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
	Usr_WHILE,
	Usr_IF,
	Usr_FOR,
	EOU
}; typedef token_types Token_type;

struct token{
	int lnum;
	std::string* value;
	Token_type type;
}; typedef struct token* Token;