/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fix.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "fix.h"
#include "fix1.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x
 * Return Type  : double
 */
double b_fix(double x)
{
  double y;
  y = x;
  d_fix(&y);
  return y;
}

/*
 * Arguments    : float x
 * Return Type  : float
 */
float c_fix(float x)
{
  return x;
}

/*
 * File trailer for fix.c
 *
 * [EOF]
 */
