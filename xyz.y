%{
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int yydebug = 1;

extern int yylineno;

extern int yyerror (char const *msg, ...);
extern int yylex();

extern int isVarDeclared(const char* name);
extern int addVar(const char *name, float value);
extern float getVar(const char *name);
extern int setVar(const char *name, float value);

%}

%union {
    float f;
	char s[100];
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
			|   statement operations	{}
			|							{}
			;

statement   :    IF expr '{' operations '}' ELSE '{' operations '}'    { $$ = $2 ? $4 : $8; }
            |    IF expr '{' operations '}'                            { $$ = $2 ? $4 :  0; }
            ;

assign		:	ID '=' expr ';'				{ setVar($1, $3); }
			| 	ID INC ';'					{ setVar($1, getVar($1) + 1); }
			| 	ID DEC ';'					{ setVar($1, getVar($1) - 1); }
			| 	VAR ID ':' I64 '=' expr ';'	{ addVar($2, $6); }
			| 	VAR ID ':' F64 '=' expr ';'	{ addVar($2, $6); }
			;

expr		:	expr '-' expr			{ $$ = $1 - $3; }
			|	expr '+' expr			{ $$ = $1 + $3; }
			|	expr '*' expr			{ $$ = $1 * $3; }
			|	expr '/' expr			{ $$ = $1 / $3; }
			|	expr '%' expr			{ $$ = (int)$1 % (int)$3; }
			| 	'-' expr				{ $$ = -$2;}
			|	'(' expr ')'			{ $$ = $2; }
			|	NUM						{ $$ = $1; }
			|	ID						{ $$ = getVar($1); }
			| 	expr '<' expr			{ $$ = $1 <  $3 ? 1. : 0.; }
        	| 	expr '>' expr			{ $$ = $1 >  $3 ? 1. : 0.; }
        	| 	expr LE expr			{ $$ = $1 <= $3 ? 1. : 0.; }
        	| 	expr GE expr			{ $$ = $1 >= $3 ? 1. : 0.; }
        	| 	expr EQ expr			{ $$ = $1 == $3 ? 1. : 0.; }
			| 	expr NE expr			{ $$ = $1 != $3 ? 1. : 0.; }
        	| 	expr AND expr			{ $$ = $1 && $3 ? 1. : 0.; }
        	| 	expr OR expr			{ $$ = $1 || $3 ? 1. : 0.; }
        	| 	'!' expr				{ $$ = $2 == 0. ? 1. : 0.; }
        	;


%%
#include "xyz.yy.c"
#define MAX_VARIABLES 100

typedef struct {
    char name[100];
    float value;
} Variable;

int variableCount = 0;
Variable variables[MAX_VARIABLES];

int isVarDeclared(const char* name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

int addVar(const char *name, float value) {
	if(variableCount > MAX_VARIABLES - 1) {
		printf("Erro: tabela de simbolos cheia.\n");
		return -1;
	}

	if(isVarDeclared(name)) {
		printf("Erro: A variável '%s' já foi declarada.\n", name);
			return -1;
	}

	strcpy(variables[variableCount].name, name);
	variables[variableCount].value = value;
	variableCount++;
	
	return 0;
}

float getVar(const char *name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    printf("Erro: A variável '%s' não foi declarada.\n", name);
    return -1;
}

int setVar(const char *name, float value) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
			variables[i].value = value;
            return 0;
        }
    }
    printf("Erro: A variável '%s' não foi declarada.\n", name);
    return -1;
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