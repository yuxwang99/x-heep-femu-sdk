/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: std.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "std.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include "varstd.h"

/* Function Definitions */
/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 * Return Type  : float
 */
float b_std(const float x_data[], const int x_size[2])
{
  return varstd(x_data, x_size);
}

/*
 * Arguments    : const emxArray_real32_T *x
 * Return Type  : float
 */
float c_std(const emxArray_real32_T *x)
{
  return c_varstd(x);
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */
