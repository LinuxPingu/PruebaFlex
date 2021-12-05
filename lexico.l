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

/*PASCAL RESEVED WORDS*/

RSVW_ABSOLUTE      "absolute"
RSVW_AND           "and"
RSVW_ARRAY         "array"
RSVW_ASM           "asm"
RSVW_BEGIN         "begin"
RSVW_CASE          "case"
RSVW_CONST         "const"
RSVW_CONSTRUCTOR   "contructor"
RSVW_DESTRUCTOR    "detructor"
RSVW_DIV           "div"
RSVW_DO            "do"
RSVW_DOWNTO        "downto"
RSVW_ELSE          "else"
RSVW_END           "end"

RSVW_FILE             "file"
RSVW_FOR              "for"
RSVW_FUNCTION         "function"
RSVW_GOTO             "goto"
RSVW_IF               "if"
RSVW_IMPLEMENTATION   "implementation"
RSVW_IN               "in"
RSVW_INHERITED        "inherited"
RSVW_INLINE           "inline"
RSVW_INTERFACE        "interface"
RSVW_LABEL            "label"
RSVW_MOD              "mod"
RSVW_NIL              "nil"
RSVW_NOT              "not"

ENTERO [0-9]+
IDENTIFICADOR [_a-zA-Z][_a-zA-Z0-9]{0,32}

%%
{RSVW_ABSOLUTE}         GetToken(yytext,RSVWORD,0);
{RSVW_AND}              GetToken(yytext,RSVWORD,0);     
{RSVW_ARRAY}            GetToken(yytext,RSVWORD,0);      
{RSVW_ASM}              GetToken(yytext,RSVWORD,0);     
{RSVW_BEGIN}            GetToken(yytext,RSVWORD,0);     
{RSVW_CASE}             GetToken(yytext,RSVWORD,0);     
{RSVW_CONST}            GetToken(yytext,RSVWORD,0);      
{RSVW_CONSTRUCTOR}      GetToken(yytext,RSVWORD,0);
{RSVW_DESTRUCTOR}       GetToken(yytext,RSVWORD,0);
{RSVW_DIV}              GetToken(yytext,RSVWORD,0);
{RSVW_DO}               GetToken(yytext,RSVWORD,0);
{RSVW_DOWNTO}           GetToken(yytext,RSVWORD,0);
{RSVW_ELSE}             GetToken(yytext,RSVWORD,0);
{RSVW_END}              GetToken(yytext,RSVWORD,0);

{ENTERO} GetToken(yytext,INTEGER,0);
{IDENTIFICADOR} GetToken(yytext,IDENTIFIER,0);
%%

