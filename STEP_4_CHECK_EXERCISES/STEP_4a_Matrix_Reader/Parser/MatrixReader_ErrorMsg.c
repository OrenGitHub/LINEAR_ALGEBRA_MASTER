/**************************************/
/* FILE NAME: MatrixReader_ErrorMsg.c */
/**************************************/

/****************************************/
/* WARNING DISABLE: sprintf - I love it */
/****************************************/
#pragma warning (disable: 4996)

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*********************************************/
/* Reading Head Position for error reporting */
/*********************************************/
int MatrixReader_ErrorMsg_TokenPos = 0;

/**************************/
/* Bison Parsing Function */
/**************************/
extern int zzparse(void);

/*********************/
/* Bison FILE Handle */
/*********************/
extern FILE *zzin;

/**************************/
/* Bison Wrapper Function */
/**************************/
int Parse(char *fname)
{
	zzin = fopen(fname, "r");
	if (zzin == NULL)
	{
		fprintf(stderr, "Cannot open input file %s for reading\n", fname);
	}

	if (zzparse() == 0)
	{
		/******************/
		/* parsing worked */
		/******************/
		fprintf(stderr, "Parsing successful!\n");
		return 1;
	}
	else
	{
		fprintf(stderr, "Parsing failed\n");
		return 0;
	}
}
