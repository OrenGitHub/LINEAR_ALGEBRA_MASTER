#ifndef __MATRIX_H__
#define __MATRIX_H__

/***************/
/* DEFINITIONS */
/***************/
#define NOMINATOR 0
#define DENOMINATOR 1

/*********/
/* TYPES */
/*********/
typedef struct {int nominator; int denominator;} FractionType;

/*********/
/* TYPES */
/*********/
typedef FractionType Mat2[2][2];
typedef FractionType Mat3[3][3];
typedef FractionType Mat4[4][4];

#endif