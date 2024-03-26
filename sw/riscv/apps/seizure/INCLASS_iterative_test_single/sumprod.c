/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sumprod.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "sumprod.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int *a
 *                int b
 * Return Type  : void
 */
void nnzfun(int *a, int b)
{
  *a += (b != 0);
}

/*
 * File trailer for sumprod.c
 *
 * [EOF]
 */
