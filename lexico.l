%{

#include <stdio.h>
#include "Token.h"
#include <stdlib.h>

using namespace std;

extern string* pStr;
extern void GetToken(string lexema, Token_type tipo, int linea);


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
{ENTERO} GetToken(yytext,INTEGER,0);
{REAL}   {printf("Numero Real %s/n",yytext);}
{ID}     {printf("Identificador %s/n",yytext);}
{DELIMITADOR} {}
. {printf("Error LEXICO");}
%%

