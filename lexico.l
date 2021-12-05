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

RSVW_OBJECT            "object"
RSVW_OF                "of"
RSVW_OPERATOR          "operator"
RSVW_OR                "or"
RSVW_PACKED            "packed"
RSVW_PROCEDURE         "procedure"
RSVW_PROGRAM           "program"
RSVW_RECORD            "record"
RSVW_REINTRODUCE       "reintroduce"
RSVW_REPEAT            "repeat"
RSVW_SELF              "self"
RSVW_SET               "set"
RSVW_SHL               "shl"
RSVW_SHR               "shr"

RSVW_STRING            "string"
RSVW_THEN              "then"
RSVW_TO                "to"
RSVW_TYPE              "type"
RSVW_UNIT              "unit"
RSVW_UNTIL             "util"
RSVW_USES              "uses"
RSVW_VAR               "var"
RSVW_WHILE             "while" 
RSVW_WITH              "with"
RSVW_XOR               "xor"

/*   -- END OF RSVW --    */

/*Arithmetic Operators*/

OPRT_ADD               "+"
OPRT_SUBSTR            "-"
OPRT_MULT              "*"
OPRT_DIV               "/"
OPRT_RESI              "%"

/*  -- Relational Operators -- */

OPRT_EQUAL             "="
OPRT_NOTEQUAL          "<>"
OPRT_GREATERTHAN       "<"
OPRT_SMALLERTHAN       ">"
OPRT_GREATEREQUAL      ">="
OPRT_SMALLEREQUAL      "<="

/* -- END OF OPRT --*/

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

{RSVW_FILE}             GetToken(yytext,RSVWORD,0);
{RSVW_FOR}              GetToken(yytext,RSVWORD,0);
{RSVW_FUNCTION}         GetToken(yytext,RSVWORD,0);
{RSVW_GOTO}             GetToken(yytext,RSVWORD,0);
{RSVW_IF}               GetToken(yytext,RSVWORD,0);
{RSVW_IMPLEMENTATION}   GetToken(yytext,RSVWORD,0);
{RSVW_IN}               GetToken(yytext,RSVWORD,0);
{RSVW_INHERITED}        GetToken(yytext,RSVWORD,0);
{RSVW_INLINE}           GetToken(yytext,RSVWORD,0);
{RSVW_INTERFACE}        GetToken(yytext,RSVWORD,0);
{RSVW_LABEL}            GetToken(yytext,RSVWORD,0);
{RSVW_MOD}              GetToken(yytext,RSVWORD,0);
{RSVW_NIL}              GetToken(yytext,RSVWORD,0);
{RSVW_NOT}              GetToken(yytext,RSVWORD,0);

{RSVW_OBJECT}           GetToken(yytext,RSVWORD,0);
{RSVW_OF}               GetToken(yytext,RSVWORD,0);
{RSVW_OPERATOR}         GetToken(yytext,RSVWORD,0);
{RSVW_OR}               GetToken(yytext,RSVWORD,0); 
{RSVW_PACKED}           GetToken(yytext,RSVWORD,0);
{RSVW_PROCEDURE}        GetToken(yytext,RSVWORD,0); 
{RSVW_PROGRAM}          GetToken(yytext,RSVWORD,0);
{RSVW_RECORD}           GetToken(yytext,RSVWORD,0);
{RSVW_REINTRODUCE}      GetToken(yytext,RSVWORD,0);
{RSVW_REPEAT}           GetToken(yytext,RSVWORD,0);
{RSVW_SELF}             GetToken(yytext,RSVWORD,0);
{RSVW_SET}              GetToken(yytext,RSVWORD,0);
{RSVW_SHL}              GetToken(yytext,RSVWORD,0);
{RSVW_SHR}              GetToken(yytext,RSVWORD,0);

{RSVW_STRING}           GetToken(yytext,RSVWORD,0); 
{RSVW_THEN}             GetToken(yytext,RSVWORD,0);
{RSVW_TO}               GetToken(yytext,RSVWORD,0);
{RSVW_TYPE}             GetToken(yytext,RSVWORD,0);
{RSVW_UNIT}             GetToken(yytext,RSVWORD,0);
{RSVW_UNTIL}            GetToken(yytext,RSVWORD,0);
{RSVW_USES}             GetToken(yytext,RSVWORD,0);
{RSVW_VAR}              GetToken(yytext,RSVWORD,0);
{RSVW_WHILE}            GetToken(yytext,RSVWORD,0);
{RSVW_WITH}             GetToken(yytext,RSVWORD,0);
{RSVW_XOR}              GetToken(yytext,RSVWORD,0);


{OPRT_ADD}              GetToken(yytext,OPRT,0);         
{OPRT_SUBSTR}           GetToken(yytext,OPRT,0);
{OPRT_MULT}             GetToken(yytext,OPRT,0);
{OPRT_DIV}              GetToken(yytext,OPRT,0);
{OPRT_RESI}             GetToken(yytext,OPRT,0);
{OPRT_EQUAL}            GetToken(yytext,OPRT,0);
{OPRT_NOTEQUAL}         GetToken(yytext,OPRT,0);
{OPRT_GREATERTHAN}      GetToken(yytext,OPRT,0);
{OPRT_SMALLERTHAN}      GetToken(yytext,OPRT,0);
{OPRT_GREATEREQUAL}     GetToken(yytext,OPRT,0);
{OPRT_SMALLEREQUAL}     GetToken(yytext,OPRT,0);

{ENTERO} GetToken(yytext,INTEGER,0);
{IDENTIFICADOR} GetToken(yytext,IDENTIFIER,0);
%%

