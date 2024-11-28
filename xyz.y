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

%}

%union {
	int i;
    float f;
	char s[MAX_VAR_NAME];
}

%token <f> NUM
%token <s> ID
%token VAR FN RETURN MAIN I64 F64 IF ELSE WHILE EQ NE GE LE AND OR INC DEC
%type <f> function params operations assign expr statement

%left '+' '-'
%left '*' '/'
%right UMINUS

%%
function    :   function ';'            { printf("Resultado da funcao = %f\n", $1); exit(0); }
            ;

function    :   FN ID '(' params ')' '{' operations RETURN expr ';' '}'   { $$ = $9; }
            ;

params		:	ID I64					{}
			|	ID F64					{}
			|   params ',' params		{}
			;

operations	:	assign operations		{}
			|	VAR declare operations		{}
			|   statement operations	{}
			|							{}
			;

statement   :    IF expr '{' operations '}' ELSE '{' operations '}'    { $$ = $2 ? $4 : $8; }
            |    IF expr '{' operations '}'                            { $$ = $2 ? $4 :  0; }
            ;

declare		:	ID ':' I64 ',' declare				{ addVar($1, INT_TYPE); }
			|	ID ':' F64 ',' declare				{ addVar($1, FLOAT_TYPE); }
			| 	ID ':' I64 '=' expr ',' declare		{ addVar($1, INT_TYPE); setVar($1, $5); }
			| 	ID ':' F64 '=' expr ',' declare		{ addVar($1, FLOAT_TYPE); setVar($1, $5); }
			|	ID ':' I64 ';'						{ addVar($1, INT_TYPE); }
			|	ID ':' F64 ';'						{ addVar($1, FLOAT_TYPE); }
			| 	ID ':' I64 '=' expr ';'				{ addVar($1, INT_TYPE); setVar($1, $5); }
			| 	ID ':' F64 '=' expr ';'				{ addVar($1, FLOAT_TYPE); setVar($1, $5); }
			;

assign		:	ID '=' expr ';'				{ setVar($1, $3); }
			| 	ID INC ';'					{ setVar($1, getVar($1) + 1); }
			| 	ID DEC ';'					{ setVar($1, getVar($1) - 1); }
			;

expr		:	expr '-' expr			{ $$ = $1 - $3; }
			|	expr '+' expr			{ $$ = $1 + $3; }
			|	expr '*' expr			{ $$ = $1 * $3; }
			|	expr '/' expr			{ $$ = $1 / $3; }
			|	expr '%' expr			{ $$ = (int)$1 % (int)$3; }
			| 	'-' expr				{ $$ = -$2;}
			|	'(' expr ')'			{ $$ = $2; }
			| 	expr '<' expr			{ $$ = $1 <  $3 ? 1. : 0.; }
        	| 	expr '>' expr			{ $$ = $1 >  $3 ? 1. : 0.; }
        	| 	expr LE expr			{ $$ = $1 <= $3 ? 1. : 0.; }
        	| 	expr GE expr			{ $$ = $1 >= $3 ? 1. : 0.; }
        	| 	expr EQ expr			{ $$ = $1 == $3 ? 1. : 0.; }
			| 	expr NE expr			{ $$ = $1 != $3 ? 1. : 0.; }
        	| 	expr AND expr			{ $$ = $1 && $3 ? 1. : 0.; }
        	| 	expr OR expr			{ $$ = $1 || $3 ? 1. : 0.; }
        	| 	'!' expr				{ $$ = $2 == 0. ? 1. : 0.; }
			|	NUM						{ $$ = $1; }
			|	ID						{ $$ = getVar($1); }
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
Variable variables[MAX_VARIABLES];

int yyerror (char const *msg, ...);
int yylex();

float getVar(const char *name);
bool isVarDeclared(const char* name);
void setVar(const char *name, float value);
void addVar(const char *name, int type);

void addVar(const char *name, int type) {
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

    return  yyparse();
}