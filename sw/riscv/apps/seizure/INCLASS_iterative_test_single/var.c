/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: var.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "var.h"
#include "rt_nonfinite.h"
#include "varstd.h"

/* Function Definitions */
/*
 * Arguments    : const float x_data[]
 *                int x_size
 * Return Type  : float
 */
float var(const float x_data[], int x_size)
{
  return b_varstd(x_data, x_size);
}

/*
 * File trailer for var.c
 *
 * [EOF]
 */
