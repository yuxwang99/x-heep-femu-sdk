/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: plus.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "plus.h"
#include "addToLoAndAdjust.h"
#include "rt_nonfinite.h"
#include "two_sum.h"

/* Function Definitions */
/*
 * Arguments    : const creal_T a
 *                double b
 * Return Type  : creal_T
 */
creal_T plus(const creal_T a, double b)
{
  creal_T c;
  creal_T t;
  t = two_sum(a.im, 0.0);
  c = two_sum(a.re, b);
  addToLoAndAdjust(&c, t.re);
  addToLoAndAdjust(&c, t.im);
  return c;
}

/*
 * File trailer for plus.c
 *
 * [EOF]
 */
