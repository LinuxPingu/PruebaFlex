%{
#include <stdio.h>
#include <stdlib.h>
%}

%option c++
%option outfile="Scanner.cpp"
%option case-insensitive
%option noyywrap

DIGITO [0-9]
LETRA [a-zA-ZñÑ]
ENTERO {DIGITO}+
REAL {DIGITO}+"."{DIGITO}+
ID {LETRA}({LETRA}|{DIGITO}|"_")*

DELIMITADOR [\t\r\f" "]

%%
{ENTERO} {printf("Numero Entero %s/n",yytext);}
{REAL}   {printf("Numero Real %s/n",yytext);}
{ID}     {printf("Identificador %s/n",yytext);}
{DELIMITADOR} {}
. {printf("Error LEXICO");}
%%
