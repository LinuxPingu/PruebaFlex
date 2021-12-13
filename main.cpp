#include <FlexLexer.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>
#include <chrono>
#include <ctime> 
#include <unordered_map>
#include <sstream>
#include "Token.h"
#include "Latex.h"

using namespace chrono;



string* pStr;
string outputFileName = "";
string defaultFileName = "Scan";
Token tmpToken;
queue<Token> tokens_queue;
unordered_map<string, pair<int,int>> hist_map;

void GetToken(string lexema, token tipo, int linea);
void CreateOutputFile(string name);
string GetStringForEnum(int enum_value); 
string GetColorForEnum(int enum_value);


/*El archivo debe pasarse por parametro*/
int main(int argc, char* argvs[]) {
	/*Lectura de parametros
		-s SOURCE
		-o OUTPUT
		min args = 3
		max args = 5
	*/

	if (argc < 3 || argc > 5 || argc == 4) {
		cout << "Wrong number of arguments !" << endl;
		return 1;
	}

	//Pasada la opcion -s
	if (argc == 3) {
		if (strcmp(argvs[1], "-s") != 0) {
			cout << "Bad argument names !" << endl;
			return 1;
		}
	}
	else {
		//Pasada la opcion -o
		if (strcmp(argvs[1], "-s") != 0 || strcmp(argvs[3], "-o") != 0) {
			cout << "Bad argument names !" << endl;
			return 1;
		}
		outputFileName = *argvs[4];
	}

	try
	{
		string outFileParam(argvs[4]);

		//Lectura de archivo
		ifstream in(argvs[2]);

		/*Init Hist hash map*/
		hist_map[GetStringForEnum(IDENTIFIER)];
		hist_map[GetStringForEnum(INTEGER)];
		hist_map[GetStringForEnum(FLOAT)];
		hist_map[GetStringForEnum(RSVWORD)];
		hist_map[GetStringForEnum(OPRT)];
		hist_map[GetStringForEnum(DTTYPE)];
		hist_map[GetStringForEnum(COMPARATOR)];
		hist_map[GetStringForEnum(STRING)];
		hist_map[GetStringForEnum(CHAR)];

		//Inicializacion del scanner
		yyFlexLexer* lexer = new yyFlexLexer(&in);

		//Ejecucion del scaneo
		while (lexer->yylex() != 0) {
			/*DO NOTHING*/
		};

		//Creacion de archivo de salida
		outputFileName != "" ? CreateOutputFile(outFileParam) : CreateOutputFile(defaultFileName);


		//Analisis del output segun reglas, bloque de codigo temporal
		size_t word_counter = tokens_queue.size();

		cout << "---TOKENS--- " << endl;
		for (size_t i = 0; i < word_counter; i++)
		{
			Token popped = tokens_queue.front();
			cout << *popped->value << " -- " << GetStringForEnum(popped->type) << " ";

			tokens_queue.pop();
		}


		return 0;
	}
	catch (const std::exception&)
	{
		cout << "Unknown exception!" << endl;
	}
}

string GetStringForEnum(int enum_value) {
	string tmp(enum_str[enum_value]);
	return tmp;
}

string GetColorForEnum(int enum_value) {
	string tmp(enum_color[enum_value]);
	return tmp;
}

void GetToken(string lexema, Token_type tipo, int linea) {
	tmpToken = new token();
	tmpToken->value = new string(lexema);
	tmpToken->lnum = linea;
	tmpToken->type = tipo;
	tokens_queue.push(tmpToken);
	/*Hist Map Init*/
	try
	{	
		int acumulator = hist_map.at(GetStringForEnum(tipo)).second;
		cout << "Acumulator old value :" << acumulator << endl;
		hist_map.at(GetStringForEnum(tipo)).first = tipo;
		hist_map.at(GetStringForEnum(tipo)).second = (acumulator + 1);
		cout << "Acumulator new value :" << hist_map.at(GetStringForEnum(tipo)).second << endl;
		cout << "Added" << endl;
		
	}
	catch (const out_of_range& oor)
	{
		cerr << "Out of Range error: " << oor.what() << '\n';
	}

}

string CreateHistSection() {
	/*Add token types*/
	int map_size = hist_map.size();
	int counter = 0;
	string histsection = R"(symbolic x coords = {Identifier,Integer,Real,Keyword,Operator,Comparator,String,Char,DataType}])";
	string appendplot = "";
	string legend = R"(\legend{)";
	for (auto& plot : hist_map) {
		cout << "Token Type: " << plot.second.first << endl;
		appendplot = "\\addplot+[" + GetColorForEnum(plot.second.first) + "] coordinates{(" + plot.first + "," + to_string(plot.second.second) + ")}; \n";
		histsection.append(appendplot);
		counter++;
		counter == map_size ? legend.append(plot.first) : legend.append(plot.first + ",");
	}

	legend.append("} \n");
	histsection.append(legend);

	/*End Tikz*/
	histsection.append(R"(\end{axis} 
	\end{tikzpicture})");
	return histsection;
}

void CreateOutputFile(string name) {
	auto start_time = system_clock::now();
	time_t end_time = system_clock::to_time_t(start_time);
	stringstream  ss;
	ss << ctime(&end_time);
	string creation_time = ss.str();

	ofstream outFile((name + latexExtension));
	string textToPDFCommand = cmdlatexmk;
	textToPDFCommand.append(lmkjobnameParam + name);
	textToPDFCommand.append(lmkIvokepdflParam);
	textToPDFCommand.append(" ./" + name + latexExtension);

	char* cmd = &textToPDFCommand[0];

	/*LATEX*/
	outFile << PDFHeader;

	outFile << PDFCover;

	outFile << PDFContentTable;

	outFile << PDFScannerSection;

	outFile << PDFSHistSectionHeader;

	outFile << CreateHistSection();

	outFile << PDFSPieSectionHeader;

	outFile << PDFEOF;

	outFile.close();

	system(cmd);

	cout << CreateHistSection() << endl;
}

