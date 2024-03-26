/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: power.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "power.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "ixfun.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *a
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_power(const emxArray_real_T *a, emxArray_real_T *y)
{
  const double *a_data;
  double *y_data;
  int i;
  int loop_ub;
  a_data = a->data;
  i = y->size[0];
  y->size[0] = a->size[0];
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    double varargin_1;
    varargin_1 = a_data[i];
    y_data[i] = b_sxfun_anonFcn2(varargin_1);
  }
}

/*
 * Arguments    : const float a_data[]
 *                const int a_size[2]
 *                float y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void c_power(const float a_data[], const int a_size[2], float y_data[],
             int y_size[2])
{
  int i;
  int loop_ub;
  y_size[0] = 1;
  y_size[1] = a_size[1];
  loop_ub = a_size[1];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = sxfun_anonFcn2(a_data[i]);
  }
}

/*
 * Arguments    : const emxArray_real32_T *a
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void power(const emxArray_real32_T *a, emxArray_real32_T *y)
{
  const float *a_data;
  float *y_data;
  int i;
  int loop_ub;
  a_data = a->data;
  i = y->size[0];
  y->size[0] = a->size[0];
  emxEnsureCapacity_real32_T(y, i);
  y_data = y->data;
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    float varargin_1;
    varargin_1 = a_data[i];
    y_data[i] = sxfun_anonFcn2(varargin_1);
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
