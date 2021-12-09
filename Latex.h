#include <string.h>
using namespace std;

const string cmdlatexmk = "latexmk";

const string cmdpdflatex = "pdflatex";

const string lmkjobnameParam = " --jobname=";

const string pdfljobnameParam = " --jobname ";

const string lmkIvokepdflParam = " -pdf";

const string latexExtension = ".tex";

const string PDFHeader = R"(\documentclass[a4paper,12pt]{article}

\usepackage[T1]{fontenc}
\usepackage[absolute]{textpos}
\usepackage[latin1]{inputenc}
\usepackage[document]{ragged2e}
\usepackage{amsmath}
\usepackage{graphicx}
\usepackage{setspace}
\usepackage{xcolor}
\usepackage{soul}
\usepackage{fancyhdr}
\usepackage{pgfplots}


\graphicspath{ {images/} }
\setlength{\TPHorizModule}{1cm}
\setlength{\TPVertModule}{1cm}

\title{\textbf{\Huge Analizador Léxico}}
\date{}

\renewcommand{\headrulewidth}{0pt}
\doublespacing

\pagestyle{fancy}
\fancyhf{}
\rfoot{\thepage}
\fancyhead[L]{\emph{\rightmark}}

\renewcommand*\contentsname{Índice}

\definecolor{MoradoChogath}{rgb}{0.42,0.08,0.78}

\sethlcolor{MoradoChogath}
)";

const string PDFCover = R"(
\begin{document}
	\begin{titlepage}
	\centering
			\begin{textblock}{5}(3.5,2)
				\includegraphics[width =14cm, height=3cm]{ulogo}
			\end{textblock}
			\maketitle
			\thispagestyle{empty}



			{\Large\text{\textbf{Profesor:}}\\}
			\begin{large}	
				\text{Ing. Sleyter Angulo}\\
			\end{large}
			{\Large\text{\textbf{Proyecto II}}\\}
			
			{\large\text{Estructura de datos II BISOFT-28}\\}
			{\large\text{\emph{Ingeniería del software}}\\}			

			{\Large\text{\textbf{Integrantes:}}\\}
			\begin{large}	
				\text{Jesé Abraham Chávez} \\
				\text{Daniel Hernandez Sanchez} \\
				\text{}\\
				\text{}\\
				\text{}\\
				\text{\textbf{III Cuatrimestre 2021}} \\
			\end{large}
	\end{titlepage}
)";
	
const string PDFContentTable = R"(
	\clearpage

	\setcounter{page}{1}

	\tableofcontents
)";

const string PDFScannerSection = R"(
	\newpage 
	\section {Scanner}
	\setlength{\parindent}{1,5cm}
	\subsection{Analizador léxico}
			\justify
			\colorbox{pink}{\textcolor{blue}{\textbf{Lorem Ipsum}}} is \textcolor{white}{\textbf{\hl{simply dummy}}} text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, 
			when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into \par
	 
			Electronic \emph{typesetting}, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, 
			and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
	\newpage 
	\subsection{Proceso de scanning}

	\newpage 
	\subsection{Flex}
)";

const string PDFSHistSection = R"(
	\newpage 
	\section {Resultados}	
	\subsection{Histograma}	

	\begin{tikzpicture}
	\begin{axis}[
		ymin=0, ymax=55,
		minor y tick num = 3,
		area style,
		]
	\addplot+[ybar interval,mark=no] plot coordinates { (0, 5) (5, 35) (10, 50) (15, 30) (20, 15) (25, 0) };
	\end{axis}
	\end{tikzpicture}	

	\newpage 
	\subsection{Diagrama circular}
)";

const string PDFEOF= R"(
\end{document})";