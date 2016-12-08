%{
/**********************/
/* BEGINING OF C PART */
/**********************/
/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "Matrix.h"
#include "Matrix_Reader_Parser.h"

/*********************/
/* ALLOCA ISSUES ... */
/*********************/
#define alloca malloc

/*******************/
/* RENAMING ISSUES */
/*******************/
#define yylex		MatrixReaderlex
#define yychar		MatrixReaderchar
#define yylval		MatrixReaderlval
#define yyparse		MatrixReaderparse
#define yyerror		MatrixReadererror
#define yydebug		MatrixReaderdebug
#define yynerrs		MatrixReadernerrs

/************/
/* AST ROOT */
/************/
Mat3 A;

/*************/
/* yylex ... */
/*************/
int  MatrixReaderlex(void);

/***************/
/* yyerror ... */
/***************/
void  MatrixReadererror(char *s){Exit(0);}

/*****************/
/* END OF C PART */
/*****************/
%}

/********************************************************************************/
/* This union is a C replacement for an abstract class representing an AST node */
/********************************************************************************/
%union
{
	union
	{
		int					ival;
		FractionType		frac;
	}
	gval;
}

/**********/
/* TOKENS */
/**********/
%token <gval> INT
%token <gval> SEMICOLON
%token <gval> LBRACK
%token <gval> RBRACK
%token <gval> PLUS
%token <gval> MINUS
%token <gval> DIVIDE

/*****************/
/* NON TERMINALS */
/*****************/
%type <gval> num
%type <gval> program

/******************/
/* START HERE ... */
/******************/
%start program

%%

program:		LBRACK num num num SEMICOLON num num num SEMICOLON num num num RBRACK		{
																								A[0][0].nominator = $2.frac.nominator;  A[0][0].denominator = $2.frac.denominator;
																								A[0][1].nominator = $3.frac.nominator;  A[0][1].denominator = $3.frac.denominator;
																								A[0][2].nominator = $4.frac.nominator;  A[0][2].denominator = $4.frac.denominator;
																								A[1][0].nominator = $6.frac.nominator;  A[1][0].denominator = $6.frac.denominator;
																								A[1][1].nominator = $7.frac.nominator;  A[1][1].denominator = $7.frac.denominator;
																								A[1][2].nominator = $8.frac.nominator;  A[1][2].denominator = $8.frac.denominator;
																								A[2][0].nominator = $10.frac.nominator; A[2][0].denominator = $10.frac.denominator;
																								A[2][1].nominator = $11.frac.nominator; A[2][1].denominator = $11.frac.denominator;
																								A[2][2].nominator = $12.frac.nominator; A[2][2].denominator = $12.frac.denominator;
																							}

num:			INT																			{$$.frac.nominator = $1.ival; $$.frac.denominator = 1;}
				| INT DIVIDE INT															{$$.frac.nominator = $1.ival; $$.frac.denominator = $3.ival;}

%%

	
