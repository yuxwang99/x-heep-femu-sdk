/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: split.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "split.h"
#include "abs.h"
#include "isfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double a
 * Return Type  : creal_T
 */
creal_T split(double a)
{
  creal_T aout;
  if (b_abs(a) <= 6.69692879491417E+299) {
    double temp;
    temp = 1.34217729E+8 * a;
    temp -= temp - a;
    aout.re = temp;
    aout.im = a - temp;
  } else if (c_isfinite(a)) {
    double slo;
    double temp;
    a *= 3.7252902984619141E-9;
    temp = 1.34217729E+8 * a;
    temp -= temp - a;
    slo = a - temp;
    temp *= 2.68435456E+8;
    slo *= 2.68435456E+8;
    aout.re = temp;
    aout.im = slo;
  } else {
    aout.re = a;
    aout.im = 0.0;
  }
  return aout;
}

/*
 * File trailer for split.c
 *
 * [EOF]
 */
