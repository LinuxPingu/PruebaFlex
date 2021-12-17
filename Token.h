#include <string>

enum token_types {
	DIGIT, IDENTIFIER, INTEGER, FLOAT, RSVWORD, OPRT, EMPTYSPC, STXSymbl, FUNTC, DTTYPE,
	COMPARATOR,STRING,CHAR,BADIDENTIFIER,BADIDENTIFIERSIZE,BADSTRSTART,BADSTREND,LINEBRK
}; typedef token_types Token_type;

static const char *enum_str[] =
{ "Digit", "Identifier", "Integer", "Real", "Keyword", "Operator", "BlankSpace","Syntax Symbol", "Function", "DataType",
   "Comparator", "String", "Char","Bad identifier", "Bad identifier size","EOU STR START","EOU STR END","Line Break"};

static const char *enum_color[] = {
	"Black", "MoradoChogath", "LBlue", "PYellow", "DBlue", "LOrange", "Black", "Black", "Black", "LRed",
	"PPGreen","PGreen","PBlue","Black","Black","Red","Red","Black"
};

static const char *enum_nbold[]{
	"NAN","BOLD","NAN","NAN","BOLD","BOLD","NAN","BOLD","NAN","BOLD",
	"BOLD","NAN","NAN","BOLD","BOLD","BOLD","BOLD","NAN"
};

static const char *enum_emph[]{
	"NAN","NAN","NAN","NAN","NAN","NAN","NAN","NAN","NAN","NAN",
	"NAN","NAN","NAN","EMPH","EMPH","EMPH","EMPH","NAN"
};

static const char *enum_code_color[] = {
	"Black","PPGreen","LOrange","LOrange","DBlue","Black","Black","DGray","Black","MoradoChogath",
	"Black","DPumpkin", "DPumpkin","LRed","LRed","LRed","LRed","Black"
};

struct token{
	int lnum;
	std::string* value;
	Token_type type;
}; typedef struct token* Token;