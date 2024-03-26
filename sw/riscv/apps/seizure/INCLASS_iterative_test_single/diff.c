/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: diff.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "diff.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void b_diff(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  const float *x_data;
  float *y_data;
  int dimSize;
  int u0;
  x_data = x->data;
  dimSize = x->size[0];
  if (x->size[0] == 0) {
    y->size[0] = 0;
  } else {
    u0 = x->size[0] - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y->size[0] = 0;
    } else {
      u0 = y->size[0];
      y->size[0] = x->size[0] - 1;
      emxEnsureCapacity_real32_T(y, u0);
      y_data = y->data;
      if (x->size[0] - 1 != 0) {
        float work_data;
        work_data = x_data[0];
        for (u0 = 2; u0 <= dimSize; u0++) {
          float tmp2;
          tmp2 = work_data;
          work_data = x_data[u0 - 1];
          y_data[u0 - 2] = work_data - tmp2;
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void c_diff(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  const float *x_data;
  float *y_data;
  int dimSize;
  int u0;
  x_data = x->data;
  dimSize = x->size[1];
  if (x->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    u0 = x->size[1] - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else {
      u0 = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = x->size[1] - 1;
      emxEnsureCapacity_real32_T(y, u0);
      y_data = y->data;
      if (x->size[1] - 1 != 0) {
        float work_data;
        work_data = x_data[0];
        for (u0 = 2; u0 <= dimSize; u0++) {
          float f;
          float tmp1;
          tmp1 = x_data[u0 - 1];
          f = tmp1;
          tmp1 -= work_data;
          work_data = f;
          y_data[u0 - 2] = tmp1;
        }
      }
    }
  }
}

/*
 * Arguments    : const float x[9]
 *                float y[8]
 * Return Type  : void
 */
void diff(const float x[9], float y[8])
{
  float work;
  int m;
  work = x[0];
  for (m = 0; m < 8; m++) {
    float tmp2;
    tmp2 = work;
    work = x[m + 1];
    y[m] = work - tmp2;
  }
}

/*
 * File trailer for diff.c
 *
 * [EOF]
 */
