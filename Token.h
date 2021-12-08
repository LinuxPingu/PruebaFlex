#include <string>

enum token_types {
	DIGIT, 
	IDENTIFIER, 
	INTEGER, 
	FLOAT, 
	RSVWORD, 
	OPERATOR, 
	EMPTYSPC, 
	STXSymbl, 
	FUNTC, 
	DTTYPE, 
	TESTTKN, 
	REAL, 
	ENTERO,
	LINEBRK,
	OPERATION,
	STRING,
	UsrOperations,
	Usr_WHILE 
}; typedef token_types Token_type;

struct token{
	int lnum;
	std::string* value;
	Token_type type;
}; typedef struct token* Token;