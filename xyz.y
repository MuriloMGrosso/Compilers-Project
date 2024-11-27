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
    int i;
    float f;
}

%token FN RETURN VAR MAIN I64 F64 IF ELSE WHILE EQ NE GE LE AND OR INC DEC

%token <i> INT ID
%token <f> FLOAT

%left '+' '-'
%left '*' '/'
%right UMINUS

%type <i> assign operations params

%type <f> function main expr boolexp

%%
function    :   function ';'            									{ printf("Resultado da funcao = %f\n", $1); exit(0); }
            |   FN ID '(' params ')' '{' operations RETURN expr ';' '}'   	{ $$ = $9; }
            ;

main 		: FN MAIN '(' ')' '{' operations RETURN expr ';' '}' 			{ $$ = $8; }
			;



params		: param_list						{}
			;

param_list	:	param 							{}
			|   param_list ',' param 			{}
			;
			
param		:	ID ':' I64						{}	
			|	ID ':' F64						{}		
			|									{}							
			;



operations 	: operation operations				{}
           	| operation							{}
           	;

operation  	: assign												{}
           	| IF boolexp '{' operations '}'							{}
           	| IF boolexp '{' operations '}' ELSE '{' operations '}'	{}
           	| WHILE boolexp '{' operations '}'						{}
			;



assign		: 	VAR ID ':' I64 '=' expr ';'							{}
       		| 	VAR ID ':' F64 '=' expr ';'							{}
			| 	ID INC												{}
			| 	ID DEC												{}
			;



expr		:	expr '-' expr			{ $$ = $1 - $3; }
			|	expr '+' expr			{ $$ = $1 + $3; }
			|	expr '*' expr			{ $$ = $1 * $3; }
			|	expr '/' expr			{ $$ = $1 / $3; }
			|	expr '%' expr			{ $$ = (int)$1 % (int)$3; }
			|	'(' expr ')'			{ $$ = $2; 	}
			|	'-' expr 				{ $$ = -$2; }
			|	INT						{ $$ = $1; 	}
			|	FLOAT					{ $$ = $1; 	}
			|	ID						{ $$ = $1; 	}
			;

boolexp 	: expr '<' expr				{ $$ = $1 <  $3 ? 0 : 1; }
        	| expr '>' expr				{ $$ = $1 >  $3 ? 0 : 1; }
        	| expr LE expr				{ $$ = $1 <= $3 ? 0 : 1; }
        	| expr GE expr				{ $$ = $1 >= $3 ? 0 : 1; }
        	| expr EQ expr				{ $$ = $1 == $3 ? 0 : 1; }
        	| boolexp AND boolexp		{ $$ = $1 && $3 ? 0 : 1; }
        	| boolexp OR boolexp		{ $$ = $1 || $3 ? 0 : 1; }
        	| '!' boolexp				{ $$ = !$2 ? 0 : 1; 	 }
        	| '(' boolexp ')'			{ $$ = $2; 				 }
        	| expr						{ $$ = $1 ? 0 : 1; 		 }
        	;

%%
#include "xyz.yy.c"

int yyerror(const char *msg, ...) 
{
	va_list args;

	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);

	exit(EXIT_FAILURE);
}

int main (int argc, char **argv) 
{
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }

    return  yyparse();
}