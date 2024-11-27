%{
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int yydebug = 1;

extern int yylineno;

extern int yyerror (char const *msg, ...);
extern int yylex();
%}

%union {
    float f;
	int i;
}
%token <f> NUM ID
%token FN RETURN MAIN I64 F64 IF ELSE WHILE EQ NE GE LE AND OR INC DEC
%type <f> function params operations assign expr 

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
			|							{}
			;

assign		:	ID '=' expr ';'			{ $1 = $3; }
			;

expr		:	expr '-' expr			{ $$ = $1 - $3; }
			|	expr '+' expr			{ $$ = $1 + $3; }
			|	expr '*' expr			{ $$ = $1 * $3; }
			|	expr '/' expr			{ $$ = $1 / $3; }
			|	'(' expr ')'			{ $$ = $2; }
			|	NUM						{ $$ = $1; }
			|	ID						{ $$ = $1; }
			;

%%
#include "xyz.yy.c"

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