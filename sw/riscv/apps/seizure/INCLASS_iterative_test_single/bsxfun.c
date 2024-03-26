/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: bsxfun.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "bsxfun.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const float a[2]
 *                float b
 *                float c[2]
 * Return Type  : void
 */
void bsxfun(const float a[2], float b, float c[2])
{
  c[0] = a[0] / b;
  c[1] = a[1] / b;
}

/*
 * File trailer for bsxfun.c
 *
 * [EOF]
 */
