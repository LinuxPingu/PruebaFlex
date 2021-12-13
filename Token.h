#include <string>

enum token_types {
	DIGIT, IDENTIFIER, INTEGER, FLOAT, RSVWORD, OPRT, EMPTYSPC, STXSymbl, FUNTC, DTTYPE,
	COMPARATOR,STRING,CHAR
}; typedef token_types Token_type;

static const char *enum_str[] =
{ "Digit", "Identifier", "Integer", "Real", "Keyword", "Operator", "BlankSpace",
	"Syntax Symbol", "Function", "DataType", "Comparator", "String", "Char"};

static const char *enum_color[] = {
	"Black", "MoradoChogath", "LBlue", "PYellow", "DBlue", "LOrange", "Black", 
	"Black", "Black", "LRed","PPGreen","PGreen","PBlue"
};

struct token{
	int lnum;
	std::string* value;
	Token_type type;
}; typedef struct token* Token;