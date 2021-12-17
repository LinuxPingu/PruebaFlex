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
#include <iomanip>

using namespace chrono;



int plot_token_counter = 0;
string* pStr;
string outputFileName = "";
string defaultFileName = "Scan";
Token tmpToken;
queue<Token> tokens_queue;
unordered_map<string, pair<int,int>> plot_map;

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
		plot_map[GetStringForEnum(IDENTIFIER)];
		plot_map[GetStringForEnum(INTEGER)];
		plot_map[GetStringForEnum(FLOAT)];
		plot_map[GetStringForEnum(RSVWORD)];
		plot_map[GetStringForEnum(OPRT)];
		plot_map[GetStringForEnum(DTTYPE)];
		plot_map[GetStringForEnum(COMPARATOR)];
		plot_map[GetStringForEnum(STRING)];
		plot_map[GetStringForEnum(CHAR)];

		//Inicializacion del scanner
		yyFlexLexer* lexer = new yyFlexLexer(&in);

		//Ejecucion del scaneo
		while (lexer->yylex() != 0) {
			/*DO NOTHING*/
		};

		//Creacion de archivo de salida
		outputFileName != "" ? CreateOutputFile(outFileParam) : CreateOutputFile(defaultFileName);


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

string GetCodeColorForEnum(int enum_value) {
	string tmp(enum_code_color[enum_value]);
	return tmp;
}

string GetBoldForEnum(int enum_value) {
	string tmp(enum_nbold[enum_value]);
	return tmp;
}

string GetEmphForEnum(int enum_value) {
	string tmp(enum_emph[enum_value]);
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
		int acumulator = plot_map.at(GetStringForEnum(tipo)).second;
		plot_map.at(GetStringForEnum(tipo)).first = tipo;
		plot_map.at(GetStringForEnum(tipo)).second = (acumulator + 1);
		plot_token_counter++;
	}
	catch (const out_of_range& oor)
	{
		cerr << "Out of Range error: " << oor.what() << '\n';
	}


}

string CreateHistSection() {
	/*Add token types*/
	int map_size = plot_map.size();
	int counter = 0;
	string histsection = R"(symbolic x coords = {Identifier,Integer,Real,Keyword,Operator,Comparator,String,Char,DataType}])";
	string appendplot = "";
	string legend = R"(\legend{)";
	for (auto& plot : plot_map) {
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

string CreatePieSection() {
	string pie;
	int token_counter = plot_token_counter;
	int iterator = 0;
	float tokenperc = 0.0;
	ostringstream tokenpercstream;
	string tokenpercstring;

	tokenpercstream << fixed;
	tokenpercstream << setprecision(2);

	pie.append("\\pie[xshift=12cm,scale=2]{");
	for (auto& plot : plot_map) {
		tokenperc = ((static_cast<float>(plot.second.second)*100.00)/ static_cast<float>(token_counter));
		tokenpercstream.str("");
		tokenpercstream << tokenperc;
		tokenpercstring = tokenpercstream.str();

		iterator++;
		iterator == plot_map.size() ? pie.append(tokenpercstring + "/" + plot.first + "\n") :
				pie.append(tokenpercstring + "/" + plot.first + "," + "\n");
	}
	pie.append("}\n \\end{tikzpicture}");
	return pie;
}

void AppendBoldEmphAndColor(string& org, Token token) {
	org.append("(*@\\textcolor{" + GetCodeColorForEnum(token->type) + "}{" + "\\textbf{" + +"\\emph{"+*(token->value) + "}}" + "}@*)");
}

void AppendBoldAndColor(string& org, Token token) {
	org.append("(*@\\textcolor{" + GetCodeColorForEnum(token->type) + "}{" + "\\textbf{" + *(token->value) + "}" + "}@*)");
}

void AppendBold(string& org, Token token) {
	org.append("(*@\\textbf{" + *(token->value) + "}@*)");
}

void AppendColor(string& org, Token token) {
	org.append("(*@\\textcolor{" + GetCodeColorForEnum(token->type) + "}{" + *(token->value) + "}@*)");
}


string CreateScannedCodeSection() {
	string code = "";
	queue<Token> code_copy = tokens_queue;
	
	while (code_copy.size() != 0) {
		Token tmp = code_copy.front();
		if (GetBoldForEnum(tmp->type) != "NAN" && GetCodeColorForEnum(tmp->type) != "Black" && GetEmphForEnum(tmp->type) != "NAN"){
			AppendBoldEmphAndColor(code, tmp);
		}
		else if (GetBoldForEnum(tmp->type) != "NAN" && GetCodeColorForEnum(tmp->type) != "Black") {
			AppendBoldAndColor(code, tmp);
		}
		else if (GetBoldForEnum(tmp->type) != "NAN") {
			AppendBold(code, tmp);
		}
		else if(GetCodeColorForEnum(tmp->type) != "Black"){
			AppendColor(code, tmp);
		}
		else {
			code.append(*(tmp->value));
		}
		code_copy.pop();
	}

	return code;
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

	outFile << PDFResultSection;

	outFile << CreateScannedCodeSection();

	outFile << "\n \\end{lstlisting}";

	outFile << PDFSHistSectionHeader;

	outFile << CreateHistSection();

	outFile << PDFSPieSectionHeader;

	outFile << CreatePieSection();

	outFile << PDFEOF;

	outFile.close();

	system(cmd);
}

