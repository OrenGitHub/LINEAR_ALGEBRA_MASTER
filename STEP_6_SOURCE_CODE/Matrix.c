/***********************/
/* FILE NAME: Matrix.c */
/***********************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "Matrix.h"

/*****************/
/* START OF CODE */
/*****************/
int gcd(int a, int b)
{
	int i=0;
	int alpha=1;

	if (a==0) return 1;

	if (a<0) a=-a;
	if (b<0) b=-b;

	for (i=2;i<a+b;i++)
	{
		if ((i*(a/i) == a) &&
			(i*(b/i) == b))
		{
			alpha = i;
		}
	}

	return alpha;
}
void ReduceToLowestTerms(FractionType *x)
{
	int alpha = gcd(x->nominator,x->denominator);

	x->nominator   /= alpha;
	x->denominator /= alpha;
}
void MUL_FRACS(FractionType *x,FractionType *y,FractionType *xy)
{
	xy->nominator   = (x->nominator  ) * (y->nominator  );
	xy->denominator = (x->denominator) * (y->denominator);

	ReduceToLowestTerms(xy);
}
void ADD_FRACS(FractionType *x,FractionType *y,FractionType *x_plus_y)
{
	x_plus_y->nominator
	=
	(x->nominator) * (y->denominator) +
	(y->nominator) * (x->denominator);
	
	x_plus_y->denominator
	=
	(x->denominator) * (y->denominator);

	ReduceToLowestTerms(x_plus_y);
}
void MUL_MAT3(Mat3 A,Mat3 B, Mat3 AB)
{
	int i=0;
	int j=0;
	int k=0;

	FractionType SUM1={0,0};
	FractionType SUM2={0,0};

	FractionType TEMP1={0,0};
	FractionType TEMP2={0,0};
	FractionType TEMP3={0,0};

	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			MUL_FRACS(&(A[i][0]),&(B[0][j]),&TEMP1);
			MUL_FRACS(&(A[i][1]),&(B[1][j]),&TEMP2);
			MUL_FRACS(&(A[i][2]),&(B[2][j]),&TEMP3);

			ADD_FRACS(&TEMP1,&TEMP2,&SUM1);
			ADD_FRACS(&SUM1, &TEMP3,&SUM2);

			AB[i][j].nominator  =SUM2.nominator;
			AB[i][j].denominator=SUM2.denominator;

			ReduceToLowestTerms(&(AB[i][j]));
		}
	}
}
