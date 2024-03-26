/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sizeIsPow2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "sizeIsPow2.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int n
 * Return Type  : boolean_T
 */
boolean_T sizeIsPow2(int n)
{
  return (n > 0) && ((n & (n - 1)) == 0);
}

/*
 * File trailer for sizeIsPow2.c
 *
 * [EOF]
 */
