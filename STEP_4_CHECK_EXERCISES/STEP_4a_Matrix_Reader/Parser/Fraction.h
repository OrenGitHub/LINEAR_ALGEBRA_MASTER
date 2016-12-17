#ifndef __FRACTION_H__
#define __FRACTION_H__

/*************************/
/* FILE NAME: Fraction.h */
/*************************/

/*********/
/* TYPES */
/*********/
typedef struct Fraction_	*Fraction;

/***************/
/* CONSTRUCTOR */
/***************/
Fraction FRACTION(int nom, int denom);

/*********************/
/* GETTERS & SETTERS */
/*********************/
int NOM(Fraction f);
int DENOM(Fraction f);

#endif
