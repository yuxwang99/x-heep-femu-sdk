/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortAscendLE.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "sortAscendLE.h"
#include "relop.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double a
 *                double b
 * Return Type  : boolean_T
 */
boolean_T b_sortAscendLE(double a, double b)
{
  return f_relop(a, b);
}

/*
 * Arguments    : float a
 *                float b
 * Return Type  : boolean_T
 */
boolean_T sortAscendLE(float a, float b)
{
  return d_relop(a, b);
}

/*
 * File trailer for sortAscendLE.c
 *
 * [EOF]
 */
