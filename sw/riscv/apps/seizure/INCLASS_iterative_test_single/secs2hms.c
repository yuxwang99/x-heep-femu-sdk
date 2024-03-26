/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: secs2hms.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "secs2hms.h"
#include "INCLASS_iterative_test_single_rtwutil.h"
#include "floor.h"
#include "idivide.h"
#include "rem.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double secs
 *                double *m
 *                double *s
 * Return Type  : double
 */
double secs2hms(double secs, double *m, double *s)
{
  double h;
  if ((secs >= 0.0) && (secs <= 2.147483647E+9)) {
    int ih_rem;
    int isecs;
    isecs = (int)rt_roundd_snf(secs);
    ih_rem = j_rem(isecs);
    h = idivide(isecs, 3600.0);
    *m = idivide(ih_rem, 60.0);
    *s = l_rem(ih_rem);
  } else {
    h = c_floor(secs / 3600.0);
    *m = c_floor((secs - 3600.0 * h) / 60.0);
    *s = secs - 60.0 * *m;
  }
  return h;
}

/*
 * File trailer for secs2hms.c
 *
 * [EOF]
 */
