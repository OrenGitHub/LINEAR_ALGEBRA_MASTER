%{
/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <string.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "util.h"
#include "MatrixReader_AST.h"
#include "MatrixReader_Parser.h"
#include "MatrixReader_ErrorMsg.h"

/****************************************/
/* WARNING DISABLE: sprintf - I love it */
/****************************************/
#pragma warning (disable: 4996)

/************/
/* CHAR POS */
/************/
int charPos=1;

/**********/
/* zzwrap */
/**********/
int zzwrap(void)
{
	charPos=1;
	return 1;
}

/**********/
/* adjust */
/**********/
void adjust(void)
{
	EM_tokPos=charPos;
	charPos+=zzleng;
}

/****************/
/* LOG function */
/****************/
extern void EM_MATRIX_READER_LEX_LOG(char *message, ...);

%}

/*******************************************/
/* PREFIX :: for generating several lexers */
/*******************************************/
%option prefix="zz"

/*******************************************/
/* PREFIX :: for generating several lexers */
/*******************************************/
%option outfile="MatrixReaderLexer.c"

/********************/
/* COMMON REGEXP(s) */
/********************/
ZERO									"0"
DIGIT									[0-9]
NON_ZERO_DIGIT							[1-9]

/*********/
/* RULES */
/*********/
%%

"+"										{adjust(); EM_MATRIX_READER_LEX_LOG("+"); return PLUS;     }
"-"										{adjust(); EM_MATRIX_READER_LEX_LOG("-"); return MINUS;    }
"["										{adjust(); EM_MATRIX_READER_LEX_LOG("["); return LBRACK;   }
"]"										{adjust(); EM_MATRIX_READER_LEX_LOG("]"); return RBRACK;   }
"/"										{adjust(); EM_MATRIX_READER_LEX_LOG("/"); return DIVIDE;   }
"\\"									{adjust(); EM_MATRIX_READER_LEX_LOG("/"); return DIVIDE;   }
";"										{adjust(); EM_MATRIX_READER_LEX_LOG(";"); return SEMICOLON;}
{ZERO}									|
{NON_ZERO_DIGIT}({DIGIT}+)				{
											adjust();
											zzlval.gval.ival = atoi(zztext);
											EM_MATRIX_READER_LEX_LOG("INT(%d)",zzlval.gval.ival);
											return INT;
										}
" "										{adjust(); EM_MATRIX_READER_LEX_LOG(" ");                continue;}
\t										{adjust(); EM_MATRIX_READER_LEX_LOG(" ");                continue;}
\n										{adjust(); EM_MATRIX_READER_LEX_LOG("\n"); EM_newline(); continue;}
.										{adjust(); EM_error(EM_tokPos,"illegal [***] token");}
