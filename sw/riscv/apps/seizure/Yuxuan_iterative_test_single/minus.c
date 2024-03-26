/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: minus.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "minus.h"
#include "addToLoAndAdjust.h"
#include "rt_nonfinite.h"
#include "two_diff.h"

/* Function Definitions */
/*
 * Arguments    : const creal_T a
 *                const creal_T b
 * Return Type  : creal_T
 */
creal_T minus(const creal_T a, const creal_T b)
{
  creal_T cout;
  creal_T t;
  t = two_diff(a.im, b.im);
  cout = two_diff(a.re, b.re);
  addToLoAndAdjust(&cout, t.re);
  addToLoAndAdjust(&cout, t.im);
  return cout;
}

/*
 * File trailer for minus.c
 *
 * [EOF]
 */
