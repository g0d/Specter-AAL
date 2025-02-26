/******************************************************************************/
/*                                   Specter                                  */
/*                   		   <<Library Header>>                             */
/*                              George Delaportas                             */
/*                            Copyright © 2010-2025                           */
/******************************************************************************/



/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

/* Specter Header Tag */
#define __SPECTER_H__ 		1

/* Specter - Calculate (1 Argument) */
char *specter_calc_1(char *A, char Q);

/* Specter - Calculate (2 Arguments) */
char *specter_calc_2(char *A, char *B, char Q);

/* Specter - Addition */
char *specter_add(char *A, char *B);

/* Specter - Subtraction */
char *specter_sub(char *A, char *B);

/* Specter - Multiplication */
char *specter_mul(char *A, char *B);

/* Specter - Division */
char *specter_div(char *A, char *B);

/* Specter - Modulo */
char *specter_mod(char *A, char *B);

/* Specter - Power to B */
char *specter_pow(char *A, char *B);

/* Specter - Square Root of X */
char *specter_sqrt(char *X);

/******************************************************************************/
