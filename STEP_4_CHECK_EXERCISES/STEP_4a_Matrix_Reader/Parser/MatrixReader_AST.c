/*********************************/
/* FILE NAME: MatrixReader_AST.c */
/*********************************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "MatrixReader_AST.h"
#include "Fraction.h"

/*********/
/* TYPES */
/*********/
struct MatrixReader_AST_vec_
{
	Fraction head;
	MatrixReader_AST_vec tail;
};
struct MatrixReader_AST_vecList_
{
	MatrixReader_AST_vec head;
	MatrixReader_AST_vecList tail;
};

/****************/
/* CONSTRUCTORS */
/****************/
MatrixReader_AST_vec MatrixReader_AST_VEC(Fraction head, MatrixReader_AST_vec tail)
{
	MatrixReader_AST_vec p = malloc(sizeof(*p));

	p->head = head;
	p->tail = tail;

	return p;
}
MatrixReader_AST_vec MatrixReader_AST_VEC2(Fraction num1, Fraction num2)
{
	return
		MatrixReader_AST_VEC(
			num1,
			MatrixReader_AST_VEC(
				num2,
				NULL));
}
MatrixReader_AST_vec MatrixReader_AST_VEC3(Fraction num1, Fraction num2, Fraction num3)
{
	return
		MatrixReader_AST_VEC(
			num1,
			MatrixReader_AST_VEC(
				num2,
				MatrixReader_AST_VEC(
					num3,
					NULL)));
}
MatrixReader_AST_vec MatrixReader_AST_VEC4(Fraction num1, Fraction num2, Fraction num3, Fraction num4)
{
	return
		MatrixReader_AST_VEC(
			num1,
			MatrixReader_AST_VEC(
				num2,
				MatrixReader_AST_VEC(
					num3,
					MatrixReader_AST_VEC(
						num4,
						NULL))));
}
MatrixReader_AST_vecList MatrixReader_AST_VEC_LIST(MatrixReader_AST_vec v, MatrixReader_AST_vecList l)
{
	MatrixReader_AST_vecList p = (MatrixReader_AST_vecList)malloc(sizeof(*p));

	p->head = v;
	p->tail = l;

	return p;
}