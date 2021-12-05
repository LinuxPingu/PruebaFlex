#include <FlexLexer.h>
#include <iostream>
#include <fstream>
#include <queue>
#include "Token.h"

using namespace std;

string* pStr;
Token tmpToken;
queue<Token> tokens_queue;

void GetToken(string lexema, token tipo, int linea);

/*El archivo debe pasarse por parametro*/
int main(){
    ifstream in("entrada.txt");
	yyFlexLexer* lexer = new yyFlexLexer(&in);
	while (lexer->yylex() != 0) {
		/*DO NOTHING*/
	};
	
	size_t word_counter = tokens_queue.size();

	cout << "---TOKENS--- " << endl;
	for (size_t i = 0; i < word_counter; i++)
	{
		Token popped = tokens_queue.front();
		cout << *popped->value <<" ";
		tokens_queue.pop();
	}

	return 0;
}


void GetToken(string lexema, Token_type tipo, int linea) {
	tmpToken = new token();
	tmpToken->value = new string(lexema);
	tmpToken->lnum = linea;
	tmpToken->type = tipo;
	tokens_queue.push(tmpToken);
}