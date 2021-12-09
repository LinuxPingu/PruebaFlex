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

RSVW_ASM           "asm"
RSVW_BEGIN         "begin"
RSVW_CASE          "case"
RSVW_CONST         "const"
RSVW_CONSTRUCTOR   "contructor"
RSVW_DESTRUCTOR    "detructor"
RSVW_DIV           "div"
RSVW_DOWNTO        "downto"
RSVW_ELSE          "else"
RSVW_END           "end"

 

RSVW_FUNCTION         "function"
RSVW_GOTO             "goto"
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

RSVW_REINTRODUCE       "reintroduce"
RSVW_REPEAT            "repeat"
RSVW_SELF              "self"

RSVW_SHL               "shl"
RSVW_SHR               "shr"


RSVW_THEN              "then"
RSVW_TO                "to"
RSVW_TYPE              "type"
RSVW_UNIT              "unit"
RSVW_UNTIL             "util"
RSVW_USES              "uses"
RSVW_VAR               "var"
RSVW_WITH              "with"
RSVW_XOR               "xor"

/*  -- Simplificador   -- */
            /*CASO  *//*CASO (*/                          /*CASO ( */
FOR_STRUC ({BLANKSPC}|{BLANKSPC}{STXSYMBL_OP_PARENTHESES}|{BLANKSPC}{STXSYMBL_OP_PARENTHESES}{BLANKSPC})({OPERATIONS_ALL})({BLANKSPC}|{STXSYMBL_CL_PARENTHESES}{BLANKSPC}|{BLANKSPC}{STXSYMBL_CL_PARENTHESES}{BLANKSPC})({RSVW_TO}{BLANKSPC})({IDENTIFICADOR}{BLANKSPC}|{ENTERO}{BLANKSPC}|{OPRT_ALL}{BLANKSPC})

RSVW_WHILE             "while" 
RSVW_IF                "if"
RSVW_FOR               "for"
RSVW_DO                "do"
                                               
Usr_WHILE   ({BLANKSPC}{RSVW_WHILE}{BLANKSPC}|{RSVW_WHILE}{BLANKSPC})({STXSYMBL_OP_PARENTHESES}|{STXSYMBL_OP_PARENTHESES}{BLANKSPC}){OPERATIONS_ALL}({STXSYMBL_CL_PARENTHESES}|{BLANKSPC}{STXSYMBL_CL_PARENTHESES}){BLANKSPC}({RSVW_THEN}|{BLANKSPC}{RSVW_THEN}{BLANKSPC}|{BLANKSPC}{RSVW_THEN})({BLANKSPC}{LINEBRK}{RSVW_BEGIN}|{BLANKSPC}{LINEBRK}{BLANKSPC}{RSVW_BEGIN}|{LINEBRK}{BLANKSPC}{RSVW_BEGIN}{BLANKSPC}|{LINEBRK}{RSVW_BEGIN}{BLANKSPC}|{BLANKSPC}{RSVW_BEGIN}|{BLANKSPC}{LINEBRK}{RSVW_BEGIN}|{BLANKSPC}{LINEBRK}{BLANKSPC}{RSVW_BEGIN}{BLANKSPC})
Usr_IF      ({BLANKSPC}{RSVW_IF}{BLANKSPC}|{RSVW_IF}{BLANKSPC})({STXSYMBL_OP_PARENTHESES}|{STXSYMBL_OP_PARENTHESES}{BLANKSPC}){OPERATIONS_ALL}({STXSYMBL_CL_PARENTHESES}|{BLANKSPC}{STXSYMBL_CL_PARENTHESES}){BLANKSPC}({RSVW_THEN}|{BLANKSPC}{RSVW_THEN}{BLANKSPC}|{BLANKSPC}{RSVW_THEN})({BLANKSPC}{LINEBRK}{RSVW_BEGIN}|{BLANKSPC}{LINEBRK}{BLANKSPC}{RSVW_BEGIN}|{LINEBRK}{BLANKSPC}{RSVW_BEGIN}{BLANKSPC}|{LINEBRK}{RSVW_BEGIN}{BLANKSPC}|{BLANKSPC}{RSVW_BEGIN}|{BLANKSPC}{LINEBRK}{RSVW_BEGIN}|{BLANKSPC}{LINEBRK}{BLANKSPC}{RSVW_BEGIN}{BLANKSPC})
Usr_FOR     ({BLANKSPC}{RSVW_FOR}|{RSVW_FOR})({FOR_STRUC})({RSVW_DO}|{BLANKSPC}{RSVW_DO}{BLANKSPC}|{BLANKSPC}{RSVW_DO})({BLANKSPC}{LINEBRK}{RSVW_BEGIN}|{BLANKSPC}{LINEBRK}{BLANKSPC}{RSVW_BEGIN}|{LINEBRK}{BLANKSPC}{RSVW_BEGIN}{BLANKSPC}|{LINEBRK}{RSVW_BEGIN}{BLANKSPC}|{BLANKSPC}{RSVW_BEGIN}|{BLANKSPC}{LINEBRK}{RSVW_BEGIN}|{BLANKSPC}{LINEBRK}{BLANKSPC}{RSVW_BEGIN}{BLANKSPC})

/*Object Reserved Words*/

RSVW_AS                "as"
RSVW_CLASS             "class"     
RSVW_DISPINTERFACE     "dispinterface" 
RSVW_EXCEPT            "except"
RSVW_EXPORTS           "exports"

RSVW_FINALIZATION     "finalization"
RSVW_FINALY           "finaly"
RSVW_INITIALIZATION   "initialization"
RSVW_IS               "is"

RSVW_LIBRARY         "library"
RSVW_ON              "on"
RSVW_OUT             "out"
RSVW_PROPERTY        "property"

RSVW_RAISE           "raise"
RSVW_RESOURCESTRING  "resourcestring"
RSVW_THREADVAR       "threadvar"
RSVW_TRY             "try"


/*   -- END OF RSVW --    */


/*SINTAX SYMBOLS*/

STXSYMBL_OP_PARENTHESES            "(" 
STXSYMBL_CL_PARENTHESES            ")"
STXSYMBL_OP_SQR_PARENTHESES        "["
STXSYMBL_CL_SQR_PARENTHESES        "]"
STXSYMBL_SNLG_QUOTE                "'"
STXSYMBL_NXT_ARG                   ","
STXSYMBL_END_ARG                   ";"

/*  -- END OF SYNTX -- */

/* DATA TYPES  */

DTTYPE_INTEGER                    "integer"
DTTYPE_CARDINAL                   "cardinal"
DTTYPE_SHORTINT                   "shortint"
DTTYPE_SMALLINT                   "smallint"
DTTYPE_LONGINT                    "longint"
DTTYPE_INT64                      "int64"
DTTYPE_BYTE                       "byte"
DTTYPE_WORD                       "word"
DTTYPE_LONGWORD                   "longword"

DTTYPE_CHAR                       "char"
DTTYPE_REAL                       "real"
DTTYPE_BOOLEAN                    "boolean"
DTTYPE_ENUM                       "enum"

DTTYPE_STRING                     "string"
DTTYPE_ARRAY                      "array"
DTTYPE_FILE                       "file"
DTTYPE_SET                        "set"
DTTYPE_RECORD                     "record"

/* -- END OF DATA TYPES  --*/

DIGITO        [0-9]
ENTERO        [0-9]+
REAL          [0-9]+"."[0-9]+
STRING_TEXT    (\"[^\n"]*\"|\'[^\n']*\')
IDENTIFICADOR [_a-zA-Z][_a-zA-Z0-9]{0,32}
BLANKSPC      [ \t]+
BLANKSPCCUSTOM [ \t]
LINEBRK       [\n]+
LETRA  [A-Za-z0-9]
PALABRA {LETRA}+
ORACION ({PALABRA}[ ])*{PALABRA}\.

EOU_BadEnd   (['][ ]*([_A-Za-z0-9]*[ ]*[^'])*)
EOU_BadStart [^'\n]([_A-Za-z0-9]*[ ]*)*[']



/*All Arithmetic Operators*/

OPRT_ALL  ("+"|"-"|"*"|"/"|"%"|"="|"<>"|"<"|">"|">="|"<="|"+="|":="|":")

/*Arithmetic Operations*/

OPERATIONS_ALL ({ENTERO}|{REAL}|{IDENTIFICADOR}|{STRING_TEXT})([ \t]+{OPRT_ALL}[ \t]+|[ \t]+{OPRT_ALL}|{OPRT_ALL}[ \t]+|{OPRT_ALL})({ENTERO}|{REAL}|{IDENTIFICADOR}|{STRING_TEXT})

UsrOperations_wOperators ({ENTERO}|{REAL}|{IDENTIFICADOR}|{STRING_TEXT})({OPRT_ALL}|{BLANKSPC}{OPRT_ALL}|{OPRT_ALL}{BLANKSPC}|{BLANKSPC}{OPRT_ALL}{BLANKSPC})({OPERATIONS_ALL}(";"|[ \t]+";"))

/* -- END OF OPRT --*/


 
%%


{STXSYMBL_OP_PARENTHESES}       GetToken(yytext,STXSymbl,yylineno);
{STXSYMBL_CL_PARENTHESES}       GetToken(yytext,STXSymbl,yylineno);
{STXSYMBL_OP_SQR_PARENTHESES}   GetToken(yytext,STXSymbl,yylineno);
{STXSYMBL_CL_SQR_PARENTHESES}   GetToken(yytext,STXSymbl,yylineno);
{STXSYMBL_NXT_ARG}              GetToken(yytext,STXSymbl,yylineno);
{STXSYMBL_END_ARG}              GetToken(yytext,STXSymbl,yylineno);

{EOU_BadEnd}            GetToken(yytext,EOU,yylineno);
{EOU_BadStart}          GetToken(yytext,EOU,yylineno);

{RSVW_ABSOLUTE}         GetToken(yytext,RSVWORD,yylineno);
{RSVW_AND}              GetToken(yytext,RSVWORD,yylineno);     
     
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

{RSVW_REINTRODUCE}      GetToken(yytext,RSVWORD,yylineno);
{RSVW_REPEAT}           GetToken(yytext,RSVWORD,yylineno);
{RSVW_SELF}             GetToken(yytext,RSVWORD,yylineno);

{RSVW_SHL}              GetToken(yytext,RSVWORD,yylineno);
{RSVW_SHR}              GetToken(yytext,RSVWORD,yylineno);


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


{RSVW_AS}               GetToken(yytext,RSVWORD,yylineno);  
{RSVW_CLASS}            GetToken(yytext,RSVWORD,yylineno);
{RSVW_DISPINTERFACE}    GetToken(yytext,RSVWORD,yylineno);
{RSVW_EXCEPT}           GetToken(yytext,RSVWORD,yylineno);
{RSVW_EXPORTS}          GetToken(yytext,RSVWORD,yylineno);

{RSVW_FINALIZATION}     GetToken(yytext,RSVWORD,yylineno);
{RSVW_FINALY}           GetToken(yytext,RSVWORD,yylineno);
{RSVW_INITIALIZATION}   GetToken(yytext,RSVWORD,yylineno);
{RSVW_IS}               GetToken(yytext,RSVWORD,yylineno);

{RSVW_LIBRARY}          GetToken(yytext,RSVWORD,yylineno);
{RSVW_ON}               GetToken(yytext,RSVWORD,yylineno);
{RSVW_OUT}              GetToken(yytext,RSVWORD,yylineno);
{RSVW_PROPERTY}         GetToken(yytext,RSVWORD,yylineno);

{RSVW_RAISE}            GetToken(yytext,RSVWORD,yylineno);
{RSVW_RESOURCESTRING}   GetToken(yytext,RSVWORD,yylineno);
{RSVW_THREADVAR}        GetToken(yytext,RSVWORD,yylineno);
{RSVW_TRY}              GetToken(yytext,RSVWORD,yylineno);



{OPRT_ALL}              GetToken(yytext,OPERATOR,yylineno);         
{OPERATIONS_ALL}        GetToken(yytext,OPERATION,yylineno);  




{DTTYPE_INTEGER}                GetToken(yytext,DTTYPE,yylineno);   
{DTTYPE_CARDINAL}               GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_SHORTINT}               GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_SMALLINT}               GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_LONGINT}                GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_INT64}                  GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_BYTE}                   GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_WORD}                   GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_LONGWORD}               GetToken(yytext,DTTYPE,yylineno);

{DTTYPE_CHAR}                   GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_REAL}                   GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_BOOLEAN}                GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_ENUM}                   GetToken(yytext,DTTYPE,yylineno);

{DTTYPE_ARRAY}                  GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_FILE}                   GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_STRING}                 GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_SET}                    GetToken(yytext,DTTYPE,yylineno);
{DTTYPE_RECORD}                 GetToken(yytext,DTTYPE,yylineno);

{DIGITO}                        GetToken(yytext,DIGIT,yylineno);                
{ENTERO}                GetToken(yytext,INTEGER,yylineno);
{REAL}                  GetToken(yytext,REAL,yylineno);
{IDENTIFICADOR}         GetToken(yytext,IDENTIFIER,yylineno);
{BLANKSPC}              GetToken(yytext,EMPTYSPC,yylineno);
{LINEBRK}               GetToken(yytext,LINEBRK,yylineno);
{STRING_TEXT}           GetToken(yytext,STRING,yylineno);


{UsrOperations_wOperators} GetToken(yytext,UsrOperations,yylineno);
{Usr_WHILE}                GetToken(yytext,Usr_WHILE,yylineno);
{Usr_IF}                   GetToken(yytext,Usr_IF,yylineno);
{Usr_FOR}                  GetToken(yytext,Usr_FOR,yylineno);

%%

