/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sign1.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "sign1.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void realScalarSign(double *x);

/* Function Definitions */
/*
 * Arguments    : double *x
 * Return Type  : void
 */
static void realScalarSign(double *x)
{
  double u;
  u = *x;
  if (rtIsNaN(u)) {
    *x = rtNaN;
  } else if (u < 0.0) {
    *x = -1.0;
  } else {
    *x = (u > 0.0);
  }
}

/*
 * Arguments    : double *x
 * Return Type  : void
 */
void c_sign(double *x)
{
  realScalarSign(x);
}

/*
 * File trailer for sign1.c
 *
 * [EOF]
 */
