%{
#include <stdlib.h>
#include "xyz.tab.h" 

extern int yyerror (char const *msg, ...);

%}

ws                          [ \t\r\n]+
letter                      [A-Za-z_]
digit                       [0-9]
id                          {letter}({letter}|{digit})*

%option noyywrap yylineno 
%%
{ws}                        { }
"//".*                      { // Isso deve ignorar o texto até o primeiro nl que aparecer. }

fn                          { return FN; }
main                        { return MAIN; }
return                      { return RETURN; }

i64                         { return I64; }
f64                         { return F64; }
{id}                        { return ID; }
{digit}+                    { yylval.i = atoll(yytext); return INT; }  
{digit}*"."{digit}+         { yylval.f = atof(yytext); return FLOAT; } 

if                          { return IF; }
else                        { return ELSE; }
while                       { return WHILE; }

"=="                        { return EQ; }
"!="                        { return NE; }
">="                        { return GE; }
"<="                        { return LE; }
"&&"                        { return AND; }
"||"                        { return OR; }

"++"                        { return INC; }
"--"                        { return DEC; }

[:+-*/%(){};,]              { return yytext[0]; }
%%