%{
#include <stdlib.h>
#include "xyz.tab.h" 

extern int yyerror (char const *msg, ...);

%}

ws                          [ \t\r\n]+
letter                      [A-Za-z_]
digit                       [0-9]
id                          {letter}({letter}|{digit})*
num                         {digit}+(\.{digit}+)?

%option noyywrap yylineno 
%%

{ws}                        { }
"//".*                      { }

fn                          { return FN;    }
main                        { return MAIN;  }
return                      { return RETURN;}

i64                         { return I64;   }
f64                         { return F64;   }
{id}                        { return ID;    }
{num}                       { yylval.f = atof(yytext); return NUM; }

"if"                        { return IF;    }
"else"                      { return ELSE;  }
"while"                     { return WHILE; }

"=="                        { return EQ;    }
"!="                        { return NE;    }
">="                        { return GE;    }
"<="                        { return LE;    }
"&&"                        { return AND;   }
"||"                        { return OR;    }

"++"                        { return INC;   }
"--"                        { return DEC;   }

[:+/\-*%(){};,]             { return yytext[0]; }
%%