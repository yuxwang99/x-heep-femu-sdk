/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: length.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "length.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int varargin_1
 * Return Type  : int
 */
int intlength(int varargin_1)
{
  int n;
  if (varargin_1 == 0) {
    n = 0;
  } else if (varargin_1 >= 1) {
    n = varargin_1;
  } else {
    n = 1;
  }
  return n;
}

/*
 * Arguments    : int varargin_1
 * Return Type  : double
 */
double varargin_numel(int varargin_1)
{
  return varargin_1;
}

/*
 * File trailer for length.c
 *
 * [EOF]
 */
