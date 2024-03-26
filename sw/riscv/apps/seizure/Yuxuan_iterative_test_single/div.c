/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: div.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "div.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
void binary_expand_op_13(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *r;
  const double *in2_data;
  double *in1_data;
  double *r1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&r, 1);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = r->size[0];
  r->size[0] = loop_ub;
  emxEnsureCapacity_real_T(r, i);
  r1 = r->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = 0.5 * in2_data[i * stride_0_0] / in1_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = r->size[0];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = r1[i];
  }
  emxFree_real_T(&r);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
void binary_expand_op_14(emxArray_real_T *in1, const emxArray_real_T *in2,
                         const emxArray_real_T *in3)
{
  const double *in2_data;
  const double *in3_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = 0.5 * in2_data[i * stride_0_0] / in3_data[i * stride_1_0];
  }
}

/*
 * Arguments    : const float in1_data[]
 *                const int in1_size[2]
 *                const float in2_data[]
 *                const int in2_size[2]
 *                float in3
 * Return Type  : float
 */
float binary_expand_op_8(const float in1_data[], const int in1_size[2],
                         const float in2_data[], const int in2_size[2],
                         float in3)
{
  float b_in1_data[400];
  float c_in1_data[400];
  int b_in1_size[2];
  int c_in1_size[2];
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  b_in1_size[0] = 1;
  if (in2_size[1] == 1) {
    loop_ub = in1_size[1];
  } else {
    loop_ub = in2_size[1];
  }
  b_in1_size[1] = loop_ub;
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] * (in2_data[i * stride_1_1] - in3);
  }
  c_in1_size[0] = 1;
  c_in1_size[1] = in1_size[1];
  loop_ub = in1_size[1];
  for (i = 0; i < loop_ub; i++) {
    float f;
    f = in1_data[i];
    c_in1_data[i] = f * f;
  }
  return b_sum(b_in1_data, b_in1_size) / b_sum(c_in1_data, c_in1_size);
}

/*
 * File trailer for div.c
 *
 * [EOF]
 */
