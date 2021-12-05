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
%option yylineno

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

ENTERO        [0-9]+
IDENTIFICADOR [_a-zA-Z][_a-zA-Z0-9]{0,32}
BLANKSPC      [ \t\n]+

%%

{RSVW_ABSOLUTE}         GetToken(yytext,RSVWORD,yylineno);
{RSVW_AND}              GetToken(yytext,RSVWORD,yylineno);     
{RSVW_ARRAY}            GetToken(yytext,RSVWORD,yylineno);      
{RSVW_ASM}              GetToken(yytext,RSVWORD,yylineno);     
{RSVW_BEGIN}            GetToken(yytext,RSVWORD,yylineno);     
{RSVW_CASE}             GetToken(yytext,RSVWORD,yylineno);     
{RSVW_CONST}            GetToken(yytext,RSVWORD,yylineno);      
{RSVW_CONSTRUCTOR}      GetToken(yytext,RSVWORD,yylineno);
{RSVW_DESTRUCTOR}       GetToken(yytext,RSVWORD,yylineno);
{RSVW_DIV}              GetToken(yytext,RSVWORD,yylineno);
{RSVW_DO}               GetToken(yytext,RSVWORD,yylineno);
{RSVW_DOWNTO}           GetToken(yytext,RSVWORD,yylineno);
{RSVW_ELSE}             GetToken(yytext,RSVWORD,yylineno);
{RSVW_END}              GetToken(yytext,RSVWORD,yylineno);

{RSVW_FILE}             GetToken(yytext,RSVWORD,yylineno);
{RSVW_FOR}              GetToken(yytext,RSVWORD,yylineno);
{RSVW_FUNCTION}         GetToken(yytext,RSVWORD,yylineno);
{RSVW_GOTO}             GetToken(yytext,RSVWORD,yylineno);
{RSVW_IF}               GetToken(yytext,RSVWORD,yylineno);
{RSVW_IMPLEMENTATION}   GetToken(yytext,RSVWORD,yylineno);
{RSVW_IN}               GetToken(yytext,RSVWORD,yylineno);
{RSVW_INHERITED}        GetToken(yytext,RSVWORD,yylineno);
{RSVW_INLINE}           GetToken(yytext,RSVWORD,yylineno);
{RSVW_INTERFACE}        GetToken(yytext,RSVWORD,yylineno);
{RSVW_LABEL}            GetToken(yytext,RSVWORD,yylineno);
{RSVW_MOD}              GetToken(yytext,RSVWORD,yylineno);
{RSVW_NIL}              GetToken(yytext,RSVWORD,yylineno);
{RSVW_NOT}              GetToken(yytext,RSVWORD,yylineno);

{RSVW_OBJECT}           GetToken(yytext,RSVWORD,yylineno);
{RSVW_OF}               GetToken(yytext,RSVWORD,yylineno);
{RSVW_OPERATOR}         GetToken(yytext,RSVWORD,yylineno);
{RSVW_OR}               GetToken(yytext,RSVWORD,yylineno); 
{RSVW_PACKED}           GetToken(yytext,RSVWORD,yylineno);
{RSVW_PROCEDURE}        GetToken(yytext,RSVWORD,yylineno); 
{RSVW_PROGRAM}          GetToken(yytext,RSVWORD,yylineno);
{RSVW_RECORD}           GetToken(yytext,RSVWORD,yylineno);
{RSVW_REINTRODUCE}      GetToken(yytext,RSVWORD,yylineno);
{RSVW_REPEAT}           GetToken(yytext,RSVWORD,yylineno);
{RSVW_SELF}             GetToken(yytext,RSVWORD,yylineno);
{RSVW_SET}              GetToken(yytext,RSVWORD,yylineno);
{RSVW_SHL}              GetToken(yytext,RSVWORD,yylineno);
{RSVW_SHR}              GetToken(yytext,RSVWORD,yylineno);

{RSVW_STRING}           GetToken(yytext,RSVWORD,yylineno); 
{RSVW_THEN}             GetToken(yytext,RSVWORD,yylineno);
{RSVW_TO}               GetToken(yytext,RSVWORD,yylineno);
{RSVW_TYPE}             GetToken(yytext,RSVWORD,yylineno);
{RSVW_UNIT}             GetToken(yytext,RSVWORD,yylineno);
{RSVW_UNTIL}            GetToken(yytext,RSVWORD,yylineno);
{RSVW_USES}             GetToken(yytext,RSVWORD,yylineno);
{RSVW_VAR}              GetToken(yytext,RSVWORD,yylineno);
{RSVW_WHILE}            GetToken(yytext,RSVWORD,yylineno);
{RSVW_WITH}             GetToken(yytext,RSVWORD,yylineno);
{RSVW_XOR}              GetToken(yytext,RSVWORD,yylineno);


{OPRT_ADD}              GetToken(yytext,OPRT,yylineno);         
{OPRT_SUBSTR}           GetToken(yytext,OPRT,yylineno);
{OPRT_MULT}             GetToken(yytext,OPRT,yylineno);
{OPRT_DIV}              GetToken(yytext,OPRT,yylineno);
{OPRT_RESI}             GetToken(yytext,OPRT,yylineno);
{OPRT_EQUAL}            GetToken(yytext,OPRT,yylineno);
{OPRT_NOTEQUAL}         GetToken(yytext,OPRT,yylineno);
{OPRT_GREATERTHAN}      GetToken(yytext,OPRT,yylineno);
{OPRT_SMALLERTHAN}      GetToken(yytext,OPRT,yylineno);
{OPRT_GREATEREQUAL}     GetToken(yytext,OPRT,yylineno);
{OPRT_SMALLEREQUAL}     GetToken(yytext,OPRT,yylineno);

{ENTERO}                GetToken(yytext,INTEGER,yylineno);
{IDENTIFICADOR}         GetToken(yytext,IDENTIFIER,yylineno);
{BLANKSPC}              GetToken(yytext,EMPTYSPC,yylineno);
%%

