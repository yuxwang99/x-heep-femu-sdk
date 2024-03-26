/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: addToLoAndAdjust.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "addToLoAndAdjust.h"
#include "isnan.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : creal_T *a
 *                double b
 * Return Type  : void
 */
void addToLoAndAdjust(creal_T *a, double b)
{
  double ahi;
  double alo;
  alo = a->im;
  ahi = a->re;
  if (b != 0.0) {
    double tmp;
    alo += b;
    tmp = ahi;
    ahi += alo;
    alo -= ahi - tmp;
  }
  if (b_isnan(alo)) {
    alo = 0.0;
  }
  a->re = ahi;
  a->im = alo;
}

/*
 * File trailer for addToLoAndAdjust.c
 *
 * [EOF]
 */
