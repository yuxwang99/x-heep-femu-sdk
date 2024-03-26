/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: divide.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "divide.h"
#include "addToLoAndAdjust.h"
#include "rt_nonfinite.h"
#include "two_diff.h"
#include "two_prod.h"

/* Function Definitions */
/*
 * Arguments    : const creal_T a
 * Return Type  : creal_T
 */
creal_T b_divide(const creal_T a)
{
  creal_T c;
  creal_T s;
  creal_T t;
  c.re = a.re / 1000.0;
  c.im = 0.0;
  t = b_two_prod(c.re);
  s.re = 0.0;
  s.im = 0.0;
  if (a.re != t.re) {
    s = two_diff(a.re, t.re);
  }
  s.re = (s.re + 0.0 * a.im) - 0.0 * t.im;
  s.im = (s.im + a.im) - t.im;
  addToLoAndAdjust(&c, (s.re + s.im) / 1000.0);
  return c;
}

/*
 * Arguments    : const creal_T a
 * Return Type  : creal_T
 */
creal_T divide(const creal_T a)
{
  creal_T c;
  creal_T s;
  creal_T t;
  c.re = a.re / 8.64E+7;
  c.im = 0.0;
  t = two_prod(c.re);
  s.re = 0.0;
  s.im = 0.0;
  if (a.re != t.re) {
    s = two_diff(a.re, t.re);
  }
  s.re = (s.re + 0.0 * a.im) - 0.0 * t.im;
  s.im = (s.im + a.im) - t.im;
  addToLoAndAdjust(&c, (s.re + s.im) / 8.64E+7);
  return c;
}

/*
 * File trailer for divide.c
 *
 * [EOF]
 */
