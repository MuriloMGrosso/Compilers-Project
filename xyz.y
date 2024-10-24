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
%token <f> NUM
%token ID I64 F64 FN RETURN WS
%type <f> function

%%
function    :   function '\n'                       { printf("Resultado da funcao = %f\n", $1); exit(0); }
            ;

function    :   '{' WS RETURN WS NUM WS ';' WS '}'                     { $$ = $6; }
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
    return  yyparse();
}