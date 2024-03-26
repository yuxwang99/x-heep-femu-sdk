/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: abs1.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "abs1.h"
#include "rt_nonfinite.h"
#include "xdlapy2.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double x
 * Return Type  : double
 */
double c_abs(double x)
{
  return fabs(x);
}

/*
 * Arguments    : const creal_T x
 * Return Type  : double
 */
double d_abs(const creal_T x)
{
  return xdlapy2(x.re, x.im);
}

/*
 * Arguments    : float x
 * Return Type  : float
 */
float f_abs(float x)
{
  return fabsf(x);
}

/*
 * File trailer for abs1.c
 *
 * [EOF]
 */
