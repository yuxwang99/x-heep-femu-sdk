/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sinpi.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "sinpi.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include "sinpi1.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void sinpi(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  const float *x_data;
  float *y_data;
  int k;
  int nx;
  x_data = x->data;
  nx = x->size[0];
  k = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real32_T(y, k);
  y_data = y->data;
  for (k = 0; k < nx; k++) {
    y_data[k] = b_sinpi(x_data[k]);
  }
}

/*
 * File trailer for sinpi.c
 *
 * [EOF]
 */
