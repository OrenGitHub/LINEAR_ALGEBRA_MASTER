#ifndef __MATRIX_READER_AST_H__
#define __MATRIX_READER_AST_H__

/*********************************/
/* FILE NAME: MatrixReader_AST.h */
/*********************************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "Fraction.h"

/*********/
/* TYPES */
/*********/
typedef struct MatrixReader_AST_vec_		*MatrixReader_AST_vec;
typedef struct MatrixReader_AST_vecList_	*MatrixReader_AST_vecList;

/****************/
/* CONSTRUCTORS */
/****************/
MatrixReader_AST_vecList MatrixReader_AST_VEC_LIST(MatrixReader_AST_vec v, MatrixReader_AST_vecList l);
MatrixReader_AST_vec     MatrixReader_AST_VEC2(Fraction num1, Fraction num2);
MatrixReader_AST_vec     MatrixReader_AST_VEC3(Fraction num1, Fraction num2, Fraction num3);
MatrixReader_AST_vec     MatrixReader_AST_VEC4(Fraction num1, Fraction num2, Fraction num3, Fraction num4);
MatrixReader_AST_vecList MatrixReader_AST_VEC_LIST(MatrixReader_AST_vec v, MatrixReader_AST_vecList l);

#endif
