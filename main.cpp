#include <FlexLexer.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
#include <chrono>
#include <ctime> 
#include <sstream>
#include "Token.h"

using namespace std;
using namespace chrono;

const string latexExtension = ".tex";

const string PDFHeader = R"(\documentclass[letterpaper,twoside,12pt]{article}

\usepackage[T1]{fontenc}
\usepackage{amsmath}
\usepackage{xcolor}
\usepackage[latin1]{inputenc}

\title{Analizador L�xico}
)";

const string PDFCover = R"(\author{Jes� Ch�vez CARNET \\  Daniel Hernandez CARNET \\ \\}

\begin{document}
\begin{titlepage}
\maketitle
\sffamily
\begin{align*}
\text{\textbf{Profesor:} Nombre algo largo alalal lddjlksjdk} \\ 
\end{align*}
\end{titlepage}
\end{document})";


string* pStr;
string outputFileName = "";
string defaultFileName = "Scan";
Token tmpToken;
queue<Token> tokens_queue;

void GetToken(string lexema, token tipo, int linea);
void CreateOutputFile(string name);

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
			cout << *popped->value << " -- " << popped->type << " ";

			tokens_queue.pop();
		}


		return 0;
	}
	catch (const std::exception&)
	{
		cout << "Unknown exception!" << endl;
	}
}



void GetToken(string lexema, Token_type tipo, int linea) {
	tmpToken = new token();
	tmpToken->value = new string(lexema);
	tmpToken->lnum = linea;
	tmpToken->type = tipo;
	tokens_queue.push(tmpToken);
}

void CreateOutputFile(string nombre) {
	auto start_time = system_clock::now();
	time_t end_time = system_clock::to_time_t(start_time);
	stringstream  ss;
	ss << ctime(&end_time);
	string creation_time = ss.str();

	ofstream outFile((nombre + latexExtension));
	string textToPDFCommand = "pdflatex";
	textToPDFCommand.append(" --jobname " + nombre);
	textToPDFCommand.append(" ./" + nombre);

	char* cmd = &textToPDFCommand[0];

	/*LATEX*/
	outFile << PDFHeader;

	outFile << "\\date {Generado : " + creation_time + "}";

	outFile << PDFCover;

	outFile.close();

	system(cmd);
}