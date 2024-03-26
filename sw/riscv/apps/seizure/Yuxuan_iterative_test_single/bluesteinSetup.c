/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: bluesteinSetup.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "bluesteinSetup.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int a
 *                int b
 *                int m
 * Return Type  : int
 */
int modplus(int a, int b, int m)
{
  int y;
  if (m - a <= b) {
    y = (b - m) + a;
  } else {
    y = a + b;
  }
  return y;
}

/*
 * File trailer for bluesteinSetup.c
 *
 * [EOF]
 */
