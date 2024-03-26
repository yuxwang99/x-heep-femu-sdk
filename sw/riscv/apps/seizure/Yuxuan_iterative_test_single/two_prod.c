/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: two_prod.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "two_prod.h"
#include "isnan.h"
#include "rt_nonfinite.h"
#include "split.h"

/* Function Definitions */
/*
 * Arguments    : double a
 * Return Type  : creal_T
 */
creal_T b_two_prod(double a)
{
  creal_T c;
  creal_T da;
  double shi;
  double slo;
  da = split(a);
  shi = a * 1000.0;
  slo = da.im * 1000.0 + (da.re * 1000.0 - shi);
  if (b_isnan(slo)) {
    slo = 0.0;
  }
  c.re = shi;
  c.im = slo;
  return c;
}

/*
 * Arguments    : double a
 * Return Type  : creal_T
 */
creal_T two_prod(double a)
{
  creal_T c;
  creal_T da;
  double shi;
  double slo;
  da = split(a);
  shi = a * 8.64E+7;
  slo = da.im * 8.64E+7 + (da.re * 8.64E+7 - shi);
  if (b_isnan(slo)) {
    slo = 0.0;
  }
  c.re = shi;
  c.im = slo;
  return c;
}

/*
 * File trailer for two_prod.c
 *
 * [EOF]
 */
