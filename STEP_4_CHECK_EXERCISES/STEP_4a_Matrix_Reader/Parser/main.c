/*********************/
/* FILE NAME: main.c */
/*********************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "MatrixReader_ErrorMsg.h"

/********/
/* usag */
/********/
int usage(void)
{
	printf("MatrixReader <InputMatrixFilename.txt>\n\n");
	printf("Reads an input matrix with dimensions i x j\n");
	printf("where i,j in {1,2,3,4}\n\n");

	return 0;
}


int main(int argc, char **argv)
{
	/******************************/
	/* [0] Check validity of call */
	/******************************/
	if (argc == 0){return usage();}
	if (argc >= 2){return usage();}

	/*************/
	/* [1] Parse */
	/*************/
	return Parse(argv[1]);
	
	return 0;
}