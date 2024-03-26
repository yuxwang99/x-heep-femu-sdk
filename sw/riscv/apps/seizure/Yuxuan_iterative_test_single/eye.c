/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eye.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "eye.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float b_I[4]
 * Return Type  : void
 */
void eye(float b_I[4])
{
  b_I[1] = 0.0F;
  b_I[2] = 0.0F;
  b_I[0] = 1.0F;
  b_I[3] = 1.0F;
}

/*
 * File trailer for eye.c
 *
 * [EOF]
 */
