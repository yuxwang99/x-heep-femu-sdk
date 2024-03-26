/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: floor2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "floor2.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double *x
 * Return Type  : void
 */
void e_floor(double *x)
{
  *x = floor(*x);
}

/*
 * Arguments    : float *x
 * Return Type  : void
 */
void f_floor(float *x)
{
  *x = floorf(*x);
}

/*
 * File trailer for floor2.c
 *
 * [EOF]
 */
