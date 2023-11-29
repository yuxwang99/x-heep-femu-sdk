/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void mrdiv(const emxArray_real_T *A, const double B_data[], const int B_size[2],
           emxArray_real_T *Y)
{
  emxArray_real_T *b_Y;
  double B;
  int i;
  int loop_ub;
  emxInit_real_T(&b_Y, 1);
  if ((A->size[0] == 0) || (B_size[0] == 0)) {
    i = Y->size[0] * Y->size[1];
    Y->size[0] = A->size[0];
    Y->size[1] = B_size[0];
    emxEnsureCapacity_real_T(Y, i);
    loop_ub = A->size[0] * B_size[0];
    for (i = 0; i < loop_ub; i++) {
      Y->data[i] = 0.0;
    }
  } else {
    B = B_data[0];
    loop_ub = A->size[0];
    i = b_Y->size[0];
    b_Y->size[0] = A->size[0];
    emxEnsureCapacity_real_T(b_Y, i);
    for (i = 0; i < loop_ub; i++) {
      b_Y->data[i] = A->data[i] / B;
    }

    i = Y->size[0] * Y->size[1];
    Y->size[0] = b_Y->size[0];
    Y->size[1] = 1;
    emxEnsureCapacity_real_T(Y, i);
    loop_ub = b_Y->size[0];
    for (i = 0; i < loop_ub; i++) {
      Y->data[i] = b_Y->data[i];
    }
  }

  emxFree_real_T(&b_Y);
}

/* End of code generation (mrdivide_helper.c) */
