%{
/****************************************/
/* WARNING DISABLE: sprintf - I love it */
/****************************************/
#pragma warning (disable: 4996)

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "../Bison/MatrixReader.tab.h"
#include "../Parser/MatrixReader_ErrorMsg.h"

/*************************/
/* READING HEAD POSITION */
/*************************/
static int ReadingHeadPos=1;

/******************/
/* WRAP IT UP !!! */
/******************/
int zzwrap(void)
{
	ReadingHeadPos=1;
	return 1;
}

/***************************************************/
/* UPDATE READING HEADS FOR POSSIBLE FUTURE ERRORS */
/***************************************************/
static void adjust(void)
{
	MatrixReader_ErrorMsg_TokenPos=ReadingHeadPos;
	ReadingHeadPos+=zzleng;
}

%}

/*********************************/
/* RENAMING FOR MULTIPLE PARSERS */
/*********************************/
%option prefix="zz"

%%
" "										{adjust(); continue;}
\t										{adjust(); continue;}
"+"										{adjust(); printf("+"); return PLUS;     }
"-"										{adjust(); printf("-"); return MINUS;    }
"*"										{adjust(); printf("*"); return TIMES;    }
"/"										{adjust(); printf("/"); return DIVIDE;   }
"("										{adjust(); printf("("); return LPAREN;   }
")"										{adjust(); printf(")"); return RPAREN;   }
"["										{adjust(); printf("["); return LBRACK;   }
"]"										{adjust(); printf("]"); return RBRACK;   }
";"										{adjust(); printf(";"); return SEMICOLON;}
[1-9][0-9]*								{
											adjust();
											zzlval.gval.ival=atoi(zztext);
											printf("INT( %d ) ",zzlval.gval.ival);
											return INT;
										}
.										{
											adjust();
											/* PSEUDO_MIPS_ASM_AST_EM_error(PSEUDO_MIPS_ASM_AST_EM_tokPos,"illegal token"); */
										}
