/*************************/
/* FILE NAME: Fraction.c */
/*************************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "Fraction.h"

/*********/
/* TYPES */
/*********/
struct Fraction_ { int nom; int denom; };

/***************/
/* CONSTRUCTOR */
/***************/
Fraction FRACTION(int nom, int denom)
{
	Fraction p = (Fraction) malloc(sizeof(*p));

	p->nom = nom;
	p->denom = denom;

	return p;
}

/*********************/
/* GETTERS & SETTERS */
/*********************/
int NOM(Fraction f) { return f->nom; }
int DENOM(Fraction f) { return f->denom; }
