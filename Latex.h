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
\usepackage{pgf-pie}   
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
\definecolor{Black}{rgb}{0,0,0}
\definecolor{LBlue}{rgb}{0.14,0.43,0.89}
\definecolor{LRed}{rgb}{0.89,0.14,0.30}
\definecolor{LOrange}{rgb}{0.90,0.38,0.15}

\definecolor{PGreen}{rgb}{0.19,0.86,0.45}
\definecolor{DBlue}{rgb}{0.16,0.19,0.76}
\definecolor{PYellow}{rgb}{1,0.81,0.33}
\definecolor{PBlue}{rgb}{0.29,0.55,0.70}
\definecolor{PPGreen}{rgb}{0.31,0.79,0.55}


%Color de resaltado%
\sethlcolor{MoradoChogath}

\pgfplotsset{width=14cm,compat=1.9}
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

const string PDFSHistSectionHeader = R"(
	\newpage 
	\section {Resultados}	
	\subsection{Histograma}	

	\begin{tikzpicture}
	\begin{axis}[
			legend pos=outer north east,  %-- Colocacion de la leyenda en la parte superior derecha del grafico%
			%legend style={draw=none,at={(0.5,-0.15)}, text width=2.5cm,%
			%anchor=north,legend columns=-1},	 Colocacion de la leyenda en la parte inferior del grafico%		
			axis on top,
			bar width = 0.7cm,
			xticklabel=\empty,
		    ytick distance=1,
		    xtick distance=1,
			xticklabel style={rotate=90},
			every axis plot/.append style={
			  ybar,
			  bar shift=0pt,
			  fill
			},
)";

const string PDFSPieSectionHeader = R"(	\newpage 
										\subsection{Diagrama circular}
										\begin{tikzpicture}
											\pie{22.97/Los Angeles Lakers,
											22.97/Boston Celtics,
											8.11/Golden State Warriors,
											8.11/Chicago Bulls,
											6.76/San Antonio Spurs,
											31.07/Other Teams}
										\end{tikzpicture})";

const string PDFEOF= R"(
\end{document})";