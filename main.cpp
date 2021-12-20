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
#include <regex>
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
	cout << *(tmpToken->value);
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
		//cerr << "Out of Range error: " << oor.what() << '\n';
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

	pie.append("\n \\def\\printonlypositive#1{\\ifdim#1pt>0pt \n #1 \n \\fi} \\pie[xshift=12cm,scale=2,before number=\\printonlypositive]{");
	for (auto& plot : plot_map) {
		tokenperc = ((static_cast<float>(plot.second.second)*100.00)/ static_cast<float>(token_counter));
		tokenpercstream.str("");
		tokenpercstream << tokenperc;
		tokenpercstring = tokenpercstream.str();

		iterator++;
		if(tokenperc != 0)
			iterator == plot_map.size() ? pie.append(tokenpercstring + "/" + plot.first + "\n") :
					pie.append(tokenpercstring + "/" + plot.first + "," + "\n");
	}
	pie.append("}\n \\end{tikzpicture}");
	return pie;
}

void LatexJumpLine(string& value) {
	value = regex_replace(value, regex("\n"), R"(\\)");
}

void LatexSpaceAndTabs(string& value) {
	cout << value;
	value = regex_replace(value, regex(" "), "\\phantom{" + latexhorizontalspace + "}");
	value = regex_replace(value, regex("\t"), "\\phantom{" + latextab + "}");
}

void AppendBoldEmphAndColor(string& org, Token token) {
	string value = *(token->value);
	LatexJumpLine(value);
	LatexSpaceAndTabs(value);
	org.append("(*@\\textcolor{" + GetCodeColorForEnum(token->type) + "}{" + "\\textbf{" + +"\\emph{"+ value + "}}" + "}@*)");
}

void AppendBoldAndColor(string& org, Token token) {
	string value = *(token->value);
	LatexJumpLine(value);
	LatexSpaceAndTabs(value);
	org.append("(*@\\textcolor{" + GetCodeColorForEnum(token->type) + "}{" + "\\textbf{" + value + "}" + "}@*)");
}

void AppendBold(string& org, Token token) {
	string value = *(token->value);
	LatexJumpLine(value);
	LatexSpaceAndTabs(value);
	org.append("(*@\\textbf{" + value + "}@*)");
}

void AppendColor(string& org, Token token) {
	string value = *(token->value);
	LatexJumpLine(value);
	LatexSpaceAndTabs(value);
	org.append("(*@\\textcolor{" + GetCodeColorForEnum(token->type) + "}{" + value + "}@*)");
}

void AppendError(string& org, Token token) {
	org.append("(*@\\phantom{"+ latexhorizontalspace +"}\\textcolor{white}{\\textbf{\\hl{"
		+ GetStringForEnum(token->type) + "}}}\\phantom{" + latexhorizontalspace + latexhorizontalspace + "}@*)");
}

string CreateScannedCodeSection() {
	string code = "";
	string errors = "";

	while (tokens_queue.size() != 0) {
		Token tmp = tokens_queue.front();
		if (GetBoldForEnum(tmp->type) != "NAN" && GetCodeColorForEnum(tmp->type) != "Black" && GetEmphForEnum(tmp->type) != "NAN"){
			AppendBoldEmphAndColor(code, tmp);
			if (tmp->type > CHAR && tmp->type < LINEBRK)
				AppendError(code, tmp), errors.append(to_string(tmp->lnum)+ " - " + GetStringForEnum(tmp->type) + "\n");
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
		tokens_queue.pop();
	}
	code.append("\n\nErrores encontrados: \n\n"+errors);
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

