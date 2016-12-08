%{
/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <string.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "Matrix_Reader_Util.h"
#include "Matrix_Reader_Parser.h"

/****************************************/
/* WARNING DISABLE: sprintf - I love it */
/****************************************/
#pragma warning (disable: 4996)

/*************************/
/* READING HEAD POSITION */
/*************************/
int reading_head_position=1;

/**********/
/* adjust */
/**********/
void adjust(void)
{
	/***************************************************************/
	/* Remember the start position of the token that was just read */
	/***************************************************************/
	Matrix_Reader_start_token_position = reading_head_position;

	/****************************/
	/* Advance the reading head */
	/****************************/
	reading_head_position += MatrixReaderleng;
}

%}

/************************/
/* SINGLE PASS ONLY ... */
/************************/
/* %option noyywrap */

/*******************************************/
/* PREFIX :: for generating several lexers */
/*******************************************/
%option prefix="MatrixReader"

/*******************************************/
/* PREFIX :: for generating several lexers */
/*******************************************/
%option outfile="../../STEP_6_SOURCE_CODE/Matrix_Reader_Lexer.c"

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

"+ "									{adjust(); printf("+"); return PLUS;     }
"- "									{adjust(); printf("-"); return MINUS;    }
"["										{adjust(); printf("["); return LBRACK;   }
"]"										{adjust(); printf("]"); return RBRACK;   }
"/"										{adjust(); printf("/"); return DIVIDE;   }
"\\"									{adjust(); printf("/"); return DIVIDE;   }
";"										{adjust(); printf(";"); return SEMICOLON;}
{ZERO}									|
("-")?{NON_ZERO_DIGIT}({DIGIT}+)		{
											adjust();
											MatrixReaderlval.gval.ival = atoi(MatrixReadertext);
											printf("INT(%d)",MatrixReaderlval.gval.ival);
											return INT;
										}
" "										{adjust(); printf(" "); continue;}
\t										{adjust(); printf(" "); continue;}
\n										{adjust(); printf("\n"); Matrix_Reader_New_Line(); continue;}
.										{
											adjust();
											Matrix_Reader_Error_Handler(
												Matrix_Reader_start_token_position,
												"illegal [***] token");
										}
