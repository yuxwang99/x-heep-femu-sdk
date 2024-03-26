/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: times.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "times.h"
#include "addToLoAndAdjust.h"
#include "rt_nonfinite.h"
#include "two_prod.h"

/* Function Definitions */
/*
 * Arguments    : const creal_T a
 * Return Type  : creal_T
 */
creal_T times(const creal_T a)
{
  creal_T c;
  c = two_prod(a.re);
  addToLoAndAdjust(&c, a.im * 8.64E+7);
  return c;
}

/*
 * File trailer for times.c
 *
 * [EOF]
 */
