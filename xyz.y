%{
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_TYPE 0
#define FLOAT_TYPE 1
#define MAX_VAR_NAME 100

int yydebug = 1;

extern int yylineno;

extern int yyerror(const char *msg, ...);
extern int yylex();

extern float getVar(const char *name);
extern void setVar(const char *name, float value);
extern void addVar(const char *name, int type);
extern void setScope(const char *scope);
extern void printVarTable();
extern void incReturnCount();
extern void checkFuncReturn();

%}

%union {
	int i;
    float f;
	char s[MAX_VAR_NAME];
}

%token <f> NUM
%token <s> ID MAIN
%token VAR FN RETURN I64 F64 IF ELSE WHILE EQ NE GE LE AND OR INC DEC
%type <f> main function params statement declare assign return func_call branch loop expr call_params

%left '+' '-'
%left '*' '/'
%right UMINUS

%%
main		: 	FN MAIN '(' ')' '{' statement '}'				{ $$ = $6; setScope($2); checkFuncReturn(); printVarTable(); exit(0); }
			|	function main									{ $$ = $2; }

function    :   FN ID '(' params ')' '{' statement '}'   { $$ = $7; setScope($2); checkFuncReturn(); }
            ;

params		:	ID I64						{ addVar($1, INT_TYPE  ); }
			|	ID F64						{ addVar($1, FLOAT_TYPE); }
			|	params ',' params			{}
			|								{}
			;

statement	: 	VAR declare statement 		{}
			|	assign statement			{}
			|	func_call ';' statement		{}
			|	branch statement			{}
			|	loop statement				{}
			|	return statement			{ $$ = $1; incReturnCount(); }
			|								{}
			;

declare		: 	ID ':' I64 '=' expr ',' declare		{ addVar($1, INT_TYPE  ); setVar($1, $5); }
			| 	ID ':' F64 '=' expr ',' declare		{ addVar($1, FLOAT_TYPE); setVar($1, $5); }
			| 	ID ':' I64 '=' expr ';'				{ addVar($1, INT_TYPE  ); setVar($1, $5); }
			| 	ID ':' F64 '=' expr ';'				{ addVar($1, FLOAT_TYPE); setVar($1, $5); }
			;

assign		:	ID '=' expr ';'				{ setVar($1, $3); 			  }
			| 	ID INC ';'					{ setVar($1, getVar($1) + 1); }
			| 	ID DEC ';'					{ setVar($1, getVar($1) - 1); }
			;

return		:	RETURN expr ';'				{ $$ = $2; }
			;

func_call	:	ID '(' call_params ')'		{}
			;

call_params	:	expr								{ $$ = $1; }
			|	call_params ',' call_params			{}
			;

branch   	:   IF expr '{' statement '}' ELSE '{' statement '}'  {}
            |   IF expr '{' statement '}'                         {}
            ;

loop		:	WHILE expr '{' statement '}'					  {}
			;

expr		:	expr '-' expr			{ $$ = $1 - $3; 		   }
			|	expr '+' expr			{ $$ = $1 + $3; 		   }
			|	expr '*' expr			{ $$ = $1 * $3; 		   }
			|	expr '/' expr			{ $$ = $1 / $3; 		   }
			|	expr '%' expr			{ $$ = (int)$1 % (int)$3;  }
			| 	'-' expr				{ $$ = -$2;				   }
			|	'(' expr ')'			{ $$ = $2; 				   }
			| 	expr '<' expr			{ $$ = $1 <  $3 ? 1. : 0.; }
        	| 	expr '>' expr			{ $$ = $1 >  $3 ? 1. : 0.; }
        	| 	expr LE expr			{ $$ = $1 <= $3 ? 1. : 0.; }
        	| 	expr GE expr			{ $$ = $1 >= $3 ? 1. : 0.; }
        	| 	expr EQ expr			{ $$ = $1 == $3 ? 1. : 0.; }
			| 	expr NE expr			{ $$ = $1 != $3 ? 1. : 0.; }
        	| 	expr AND expr			{ $$ = $1 && $3 ? 1. : 0.; }
        	| 	expr OR expr			{ $$ = $1 || $3 ? 1. : 0.; }
        	| 	'!' expr				{ $$ = $2 == 0. ? 1. : 0.; }
			|	NUM						{ $$ = $1; 				   }
			|	ID						{ $$ = getVar($1); 		   }
			|	func_call				{ $$ = $1;				   }
        	;


%%

#include "xyz.yy.c"
#include <stdbool.h>

#define INT_TYPE 0
#define FLOAT_TYPE 1
#define MAX_VARIABLES 100
#define MAX_VAR_NAME 100

typedef struct {
	int type;
    float value;
    char name[MAX_VAR_NAME];
} Variable;

int variableCount = 0;
int lastScopeDefined = -1;
int returnCount = 0;
Variable variables[MAX_VARIABLES];

int yyerror (char const *msg, ...);
int yylex();

float getVar(const char *name);
bool isVarDeclared(const char* name);
void setVar(const char *name, float value);
void addVar(const char *name, int type);
void setScope(const char *scope);
void incReturnCount();
void checkFuncReturn();

void addVar(const char *name, int type) {
	char fullName[MAX_VAR_NAME];

	if(variableCount > MAX_VARIABLES - 1) {
		yyerror("Erro: tabela de variaveis cheia.\n");
		return;
	}

	if(isVarDeclared(name)) {
		yyerror("Erro: mais de uma declaração para a mesma variável.\n");
		return;
	}

	strcpy(variables[variableCount].name, name);
	variables[variableCount].type = type;
	variableCount++;
}

void setVar(const char *name, float value) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
			variables[i].value = value;
			return;
        }
    }
	yyerror("Erro: variável não declarada.\n");
}

bool isVarDeclared(const char* name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0)
            return true;
    }
    return false;
}

float getVar(const char *name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0)
			return variables[i].value;
    }
	yyerror("Erro: variável não declarada.\n");
    return 0;
}

void setScope(const char *scope) {
	char fullName[MAX_VAR_NAME];

    for (int i = lastScopeDefined + 1; i < variableCount; i++) {
		strcpy(fullName, scope);
		strcat(fullName, ".");
		strcat(fullName, variables[i].name);
		strcpy(variables[i].name, fullName);
		lastScopeDefined = i;
    }
}

void printVarTable() {
	printf("\nTabela de símbolos:\n\n");
	for(int i = 0; i < variableCount; i++) {
		printf("%s [%s]\n", variables[i].name, variables[i].type == INT_TYPE ? "i64" : "f64");
	}
	printf("\n");
}

void incReturnCount() {
	returnCount++;
}

void checkFuncReturn() {
	if(returnCount < 1) {
		yyerror("Erro: função sem retorno.\n");
		return;
	}

	returnCount = 0;
}

int yyerror(const char *msg, ...) {
	va_list args;

	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);

	exit(EXIT_FAILURE);
}

int main (int argc, char **argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }

    return yyparse();
}