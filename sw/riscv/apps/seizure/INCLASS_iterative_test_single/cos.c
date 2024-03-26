/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: cos.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "cos.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double *x
 * Return Type  : void
 */
void b_cos(double *x)
{
  *x = cos(*x);
}

/*
 * Arguments    : float *x
 * Return Type  : void
 */
void d_cos(float *x)
{
  *x = cosf(*x);
}

/*
 * File trailer for cos.c
 *
 * [EOF]
 */
