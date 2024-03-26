/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: isfinite.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "isfinite.h"
#include "isinf.h"
#include "isnan.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float x
 * Return Type  : boolean_T
 */
boolean_T b_isfinite(float x)
{
  return (!b_isinf(x)) && (!c_isnan(x));
}

/*
 * Arguments    : double x
 * Return Type  : boolean_T
 */
boolean_T c_isfinite(double x)
{
  return (!c_isinf(x)) && (!b_isnan(x));
}

/*
 * File trailer for isfinite.c
 *
 * [EOF]
 */
