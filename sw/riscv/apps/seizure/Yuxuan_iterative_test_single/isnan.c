/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: isnan.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "isnan.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x
 * Return Type  : boolean_T
 */
boolean_T b_isnan(double x)
{
  return rtIsNaN(x);
}

/*
 * Arguments    : float x
 * Return Type  : boolean_T
 */
boolean_T c_isnan(float x)
{
  return rtIsNaNF(x);
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_boolean_T *b
 * Return Type  : void
 */
void d_isnan(const emxArray_real32_T *x, emxArray_boolean_T *b)
{
  const float *x_data;
  int i;
  int loop_ub;
  boolean_T *b_data;
  x_data = x->data;
  i = b->size[0];
  b->size[0] = x->size[0];
  emxEnsureCapacity_boolean_T(b, i);
  b_data = b->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = rtIsNaNF(x_data[i]);
  }
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_boolean_T *b
 * Return Type  : void
 */
void e_isnan(const emxArray_real32_T *x, emxArray_boolean_T *b)
{
  const float *x_data;
  int i;
  int loop_ub;
  boolean_T *b_data;
  x_data = x->data;
  i = b->size[0] * b->size[1];
  b->size[0] = x->size[0];
  b->size[1] = 2;
  emxEnsureCapacity_boolean_T(b, i);
  b_data = b->data;
  loop_ub = x->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = rtIsNaNF(x_data[i]);
  }
}

/*
 * File trailer for isnan.c
 *
 * [EOF]
 */
