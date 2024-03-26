/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: log2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "log2.h"
#include "isfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double x
 *                double *e
 * Return Type  : double
 */
double b_log2(double x, double *e)
{
  double f;
  int eint;
  if (c_isfinite(x)) {
    f = frexp(x, &eint);
    *e = eint;
  } else {
    f = x;
    *e = 0.0;
  }
  return f;
}

/*
 * Arguments    : float x
 *                float *e
 * Return Type  : float
 */
float c_log2(float x, float *e)
{
  float f;
  int eint;
  if (b_isfinite(x)) {
    f = frexpf(x, &eint);
    *e = (float)eint;
  } else {
    f = x;
    *e = 0.0F;
  }
  return f;
}

/*
 * File trailer for log2.c
 *
 * [EOF]
 */
