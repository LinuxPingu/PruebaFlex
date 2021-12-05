#include <FlexLexer.h>
#include <iostream>
#include <fstream>
#include "Token.h"

using namespace std;

string* pStr;

void GetToken(string lexema, token tipo, int linea);

/*El archivo debe pasarse por parametro*/
int main(){
    ifstream in("entrada.txt");
	yyFlexLexer* lexer = new yyFlexLexer(&in);
	while (lexer->yylex() != 0) {
		/*DO NOTHING*/
	};
	//cout << *pStr << endl;
	return 0;
}


void GetToken(string lexema, Token_type tipo, int linea) {

}