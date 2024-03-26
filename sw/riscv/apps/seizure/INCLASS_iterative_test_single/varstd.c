/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: varstd.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "varstd.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include "vvarstd.h"

/* Function Definitions */
/*
 * Arguments    : const float x_data[]
 *                int x_size
 * Return Type  : float
 */
float b_varstd(const float x_data[], int x_size)
{
  return b_vvarstd(x_data, x_size, x_size);
}

/*
 * Arguments    : const emxArray_real32_T *x
 * Return Type  : float
 */
float c_varstd(const emxArray_real32_T *x)
{
  return vvarstd(x, x->size[0]);
}

/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 * Return Type  : float
 */
float varstd(const float x_data[], const int x_size[2])
{
  emxArray_real32_T b_x_data;
  int x;
  x = x_size[1];
  b_x_data.data = (float *)&x_data[0];
  b_x_data.size = &x;
  b_x_data.allocatedSize = -1;
  b_x_data.numDimensions = 1;
  b_x_data.canFreeData = false;
  return vvarstd(&b_x_data, x_size[1]);
}

/*
 * File trailer for varstd.c
 *
 * [EOF]
 */
