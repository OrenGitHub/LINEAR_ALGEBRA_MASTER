typedef union
{
#include "../Parser/MatrixReader_AST.h"
	union
	{
		int							ival;
		Fraction					frac;
		MatrixReaderAST_vec		vec;
		MatrixReader_AST_vecList	vecList;
	}
	gval;
} YYSTYPE;
#define	INT	258
#define	LPAREN	259
#define	RPAREN	260
#define	LBRACK	261
#define	RBRACK	262
#define	SEMICOLON	263
#define	PLUS	264
#define	MINUS	265
#define	TIMES	266
#define	DIVIDE	267


extern YYSTYPE zzlval;
