/********************/
/* FILENAME: main.c */
/********************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <string.h>

/*****************/
/* START OF CODE */
/*****************/
int usage(void)
{
	/********************************************************************************************/
	/* LinearAlgebraSolver --check   <INPUT--MATRIX-FILENAME.txt> <ROW-OPERATIONS-FILENAME.txt> */
	/********************************************************************************************/
	printf("LinearAlgebraSolver --check <INPUT-MATRIX-FILENAME.txt> <ROW-OPERATIONS-FILENAME.txt>\n");

	/**************************************************************/
	/* LinearAlgebraSolver --compose <RANDOM-MATRIX-FILENAME.txt> */
	/**************************************************************/
	printf("LinearAlgebraSolver --compose <RANDOM-MATRIX-FILENAME.txt>\n");

	return 0;
}

int Check(char **argv)
{
	/*************************/
	/* [1] Read Input Matrix */
	/*************************/

	/***************************/
	/* [2] Read Row Operations */
	/***************************/

	/**************************************/
	/* [3] Apply Row Operations on Matrix */
	/**************************************/

	/******************************/
	/* [4] Check Resulting Matrix */
	/******************************/
	return 0;
}

int Compose(char **argv)
{
	return 0;
}

int main(int argc, char **argv)
{
	/*************/
	/* [0] usage */
	/*************/
	if (argc == 0) return usage();

	/**********************************************************************************************/
	/* [1] LinearAlgebraSolver --check <INPUT--MATRIX-FILENAME.txt> <ROW-OPERATIONS-FILENAME.txt> */
	/**********************************************************************************************/
	if (strcmp(argv[1],"--check") == 0) return Check(argv);

	/******************************************************************/
	/* [2] LinearAlgebraSolver --compose <RADNOM-MATRIX-FILENAME.txt> */
	/******************************************************************/
	if (strcmp(argv[1],"--compose") == 0) return Compose(argv);
}
