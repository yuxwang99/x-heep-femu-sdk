/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: two_diff.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "two_diff.h"
#include "isnan.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double a
 *                double b
 * Return Type  : creal_T
 */
creal_T two_diff(double a, double b)
{
  creal_T c;
  double bb;
  double shi;
  shi = a - b;
  bb = shi - a;
  bb = (a - (shi - bb)) - (b + bb);
  if (b_isnan(bb)) {
    bb = 0.0;
  }
  c.re = shi;
  c.im = bb;
  return c;
}

/*
 * File trailer for two_diff.c
 *
 * [EOF]
 */
