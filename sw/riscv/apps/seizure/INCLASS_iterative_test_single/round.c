/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: round.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "round.h"
#include "round1.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x
 * Return Type  : double
 */
double b_round(double x)
{
  return x;
}

/*
 * Arguments    : float x
 * Return Type  : float
 */
float c_round(float x)
{
  float y;
  y = x;
  d_round(&y);
  return y;
}

/*
 * File trailer for round.c
 *
 * [EOF]
 */
