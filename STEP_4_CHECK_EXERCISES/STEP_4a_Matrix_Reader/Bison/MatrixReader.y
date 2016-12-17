%{
/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "../Parser/Fraction.h"
#include "../Parser/MatrixReader_AST.h"

/*********************/
/* ALLOCA ISSUES ... */
/*********************/
#define alloca malloc

/*********************************/
/* LEXING FUNCTION PROTOTYPE ... */
/*********************************/
int zzlex(void);

/***************************/
/* PARSED INPUT MATRIX ... */
/***************************/
// Mat3 InputMatrix;

/******************************/
/* LEXING ERROR FUNCTION  ... */
/******************************/
void zzerror(char *s)
{
	/* PSEUDO_MIPS_ASM_AST_EM_error(PSEUDO_MIPS_ASM_AST_EM_tokPos, "%s", s); */
}
%}

%union
{
#include "../Parser/MatrixReader_AST.h"
	union
	{
		int							ival;
		Fraction					frac;
		MatrixReader_AST_vec		vec;
		MatrixReader_AST_vecList	vecList;
	}
	gval;
}

%token <gval> INT
%token <gval> LPAREN
%token <gval> RPAREN
%token <gval> LBRACK
%token <gval> RBRACK
%token <gval> SEMICOLON
%token <gval> PLUS
%token <gval> MINUS
%token <gval> TIMES
%token <gval> DIVIDE

%type <gval> num
%type <gval> vec2
%type <gval> vec3
%type <gval> vec4
%type <gval> vecList
%type <gval> vec2List
%type <gval> vec3List
%type <gval> vec4List
%type <gval> program

%start program

%%

program:	LBRACK vecList RBRACK			{printf("");}

vecList:	vec2List						{$$.vecList = $1.vecList;}
			| vec3List						{$$.vecList = $1.vecList;}
			| vec4List						{$$.vecList = $1.vecList;}

vec2List:	vec2 SEMICOLON vec2List			{$$.vecList = MatrixReader_AST_VEC_LIST($1.vec,$3.vecList);}
			| vec2							{$$.vecList = MatrixReader_AST_VEC_LIST($1.vec,NULL);}

vec3List:	vec3 SEMICOLON vec3List			{$$.vecList = MatrixReader_AST_VEC_LIST($1.vec,$3.vecList);}
			| vec3							{$$.vecList = MatrixReader_AST_VEC_LIST($1.vec,NULL);}

vec4List:	vec4 SEMICOLON vec4List			{$$.vecList = MatrixReader_AST_VEC_LIST($1.vec,$3.vecList);}
			| vec4							{$$.vecList = MatrixReader_AST_VEC_LIST($1.vec,NULL);}

vec2:		LPAREN num num         RPAREN	{$$.vec = MatrixReader_AST_VEC2($2.frac,$3.frac);}
vec3:		LPAREN num num num     RPAREN	{$$.vec = MatrixReader_AST_VEC3($2.frac,$3.frac,$4.frac);}
vec4:		LPAREN num num num num RPAREN	{$$.vec = MatrixReader_AST_VEC4($2.frac,$3.frac,$4.frac,$5.frac);}

num:		INT								{$$.frac = MatrixReader_AST_FRAC($1.ival,      1);}
			| INT DIVIDE INT				{$$.frac = MatrixReader_AST_FRAC($1.ival,$3.ival);}
%%

	
