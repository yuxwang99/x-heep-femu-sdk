/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mrdivide_helper.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "mrdivide_helper.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "lusolve.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float A
 *                const float B_data[]
 * Return Type  : float
 */
float b_mrdiv(float A, const float B_data[])
{
  return b_lusolve(B_data, A);
}

/*
 * Arguments    : const float B_data[]
 * Return Type  : float
 */
float c_mrdiv(const float B_data[])
{
  return b_lusolve(B_data, 0.0F);
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const float B_data[]
 *                const int B_size[2]
 *                emxArray_real32_T *Y
 * Return Type  : void
 */
void mrdiv(const emxArray_real_T *A, const float B_data[], const int B_size[2],
           emxArray_real32_T *Y)
{
  emxArray_real32_T *b_Y;
  float *Y_data;
  float *b_Y_data;
  int i;
  emxInit_real32_T(&b_Y, 1);
  if ((A->size[0] == 0) || (B_size[0] == 0)) {
    int loop_ub;
    i = Y->size[0] * Y->size[1];
    Y->size[0] = A->size[0];
    Y->size[1] = B_size[0];
    emxEnsureCapacity_real32_T(Y, i);
    b_Y_data = Y->data;
    loop_ub = A->size[0] * B_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_Y_data[i] = 0.0F;
    }
  } else {
    int loop_ub;
    lusolve(B_data, A, b_Y);
    Y_data = b_Y->data;
    i = Y->size[0] * Y->size[1];
    Y->size[0] = b_Y->size[0];
    Y->size[1] = 1;
    emxEnsureCapacity_real32_T(Y, i);
    b_Y_data = Y->data;
    loop_ub = b_Y->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_Y_data[i] = Y_data[i];
    }
  }
  emxFree_real32_T(&b_Y);
}

/*
 * File trailer for mrdivide_helper.c
 *
 * [EOF]
 */
