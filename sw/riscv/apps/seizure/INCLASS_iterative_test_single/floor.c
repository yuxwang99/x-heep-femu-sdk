/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: floor.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "floor.h"
#include "floor2.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float x
 * Return Type  : float
 */
float b_floor(float x)
{
  float y;
  y = x;
  f_floor(&y);
  return y;
}

/*
 * Arguments    : double x
 * Return Type  : double
 */
double c_floor(double x)
{
  double y;
  y = x;
  e_floor(&y);
  return y;
}

/*
 * File trailer for floor.c
 *
 * [EOF]
 */
