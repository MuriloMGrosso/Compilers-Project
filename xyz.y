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
}

%token <f> NUM ID
%token VAR FN RETURN MAIN I64 F64 IF ELSE WHILE EQ NE GE LE AND OR INC DEC
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

assign		:	ID '=' expr ';'				{ $1 = $3; }
			| 	VAR ID ':' I64 '=' expr ';'	{ $2 = $6; }
			| 	VAR ID ':' F64 '=' expr ';'	{ $2 = $6; }
			;

expr		:	expr '-' expr			{ $$ = $1 - $3; }
			|	expr '+' expr			{ $$ = $1 + $3; }
			|	expr '*' expr			{ $$ = $1 * $3; }
			|	expr '/' expr			{ $$ = $1 / $3; }
			| 	'-' expr				{ $$ = -$2;}
			|	'(' expr ')'			{ $$ = $2; }
			|	NUM						{ $$ = $1; }
			| 	ID INC					{ $$ = $1 + 1; }
			| 	ID DEC					{ $$ = $1 - 1; }
			|	ID						{ $$ = $1; }
			| 	expr '<' expr			{ $$ = $1 <  $3 ? 0. : 1.; }
        	| 	expr '>' expr			{ $$ = $1 >  $3 ? 0. : 1.; }
        	| 	expr LE expr			{ $$ = $1 <= $3 ? 0. : 1.; }
        	| 	expr GE expr			{ $$ = $1 >= $3 ? 0. : 1.; }
        	| 	expr EQ expr			{ $$ = $1 == $3 ? 0. : 1.; }
        	| 	expr AND expr			{ $$ = $1 && $3 ? 0. : 1.; }
        	| 	expr OR expr			{ $$ = $1 || $3 ? 0. : 1.; }
        	| 	'!' expr				{ $$ = !$2 ? 0. : 1.; 	 }
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