/***********************************/
/* FILE NAME: Matrix_Reader_Util.c */
/***********************************/

/****************************************/
/* WARNING DISABLE: sprintf - I love it */
/****************************************/
#pragma warning (disable: 4996)

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "Matrix_Reader_Util.h"

/*****************************************************/
/* Remember Input Matrix Filename For Error Messages */
/*****************************************************/
static char *filename= "";

/*********************************/
/* Current Line Reading in Lexer */
/*********************************/
static int lineNum = 1;

/*****************************/
/* Last Token Start in Lexer */
/*****************************/
int Matrix_Reader_start_token_position=0;

/********************************/
/* FILE handle for inupt matrix */
/********************************/
extern FILE *Matrix_Reader_in;

/****************************/
/* Record All lines visited */
/****************************/
typedef struct intList {int i; struct intList *rest;} *IntList;

/***********************/
/* IntList Constructor */
/***********************/
static IntList intList(int i, IntList rest) 
{
	/************/
	/* Allocate */
	/************/
	IntList l = (IntList) malloc(sizeof *l);

	/**************/
	/* Initialize */
	/**************/
	l->i=i;
	l->rest=rest;
	
	/**********/
	/* Return */
	/**********/
	return l;
}

/***********************/
/* Lines Read By Lexer */
/***********************/
static IntList linePos=NULL;

/**********************/
/* Remember New Lines */
/**********************/
void Matrix_Reader_New_Line(void)
{
	lineNum++;
	linePos = intList(Matrix_Reader_start_token_position, linePos);
}

/*******************************/
/* Matrix Reader Error Handler */
/*******************************/
void Matrix_Reader_Error_Handler(int pos, char *message,...)
{
	va_list ap;
	int num=lineNum;
	IntList lines = linePos;

	/******************************/
	/* [0] Find the relevant line */
	/******************************/
	while (lines && lines->i >= pos) 
	{
		lines=lines->rest;
		num--;
	}

	/********************************************************/
	/* [1] Notify the user that its input matrix is illegal */
	/********************************************************/
	if (filename){fprintf(stderr,"Illegal Input Matrix in File %s:",filename);}
	
	/**********************************************************/
	/* [2] Print the line number + line position of the error */
	/**********************************************************/
	if (lines){fprintf(stderr,"%d.%d: ", num, pos-lines->i);}
	
	/***************************/
	/* [3] Print error message */
	/***************************/
	va_start(ap,message);
	vfprintf(stderr, message, ap);
	va_end(ap);
	fprintf(stderr,"\n");

	/*********************************/
	/* [4] exit at the first mistake */
	/*********************************/
	exit(0);
}

/**********************/
/* Matrix Reader Init */
/**********************/
void Matrix_Reader_Init(char *input_matrix_filename)
{
	filename = input_matrix_filename;

	/******************************************/
	/* [0] Open matrix input file for reading */
	/******************************************/
	Matrix_Reader_in = fopen(input_matrix_filename,"r");

	/***************************/
	/* [1] File does not exist */
	/***************************/
	if (!Matrix_Reader_in)
	{
		/***********************************************/
		/* [2] Notify the use that file does not exist */
		/***********************************************/
		Matrix_Reader_Error_Handler(0,"Can not open file %s",input_matrix_filename);

		/************/
		/* [3] exit */
		/************/
		exit(0);
	}
}

