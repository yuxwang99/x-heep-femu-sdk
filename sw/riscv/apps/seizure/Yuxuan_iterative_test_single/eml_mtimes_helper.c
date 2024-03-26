/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_mtimes_helper.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "eml_mtimes_helper.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "atan2.h"
#include "rt_nonfinite.h"
#include "std.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *in1
 *                const emxArray_real32_T *in2
 * Return Type  : float
 */
float binary_expand_op_17(const emxArray_real32_T *in1,
                          const emxArray_real32_T *in2)
{
  emxArray_real32_T *b_in1;
  emxArray_real32_T *c_in1;
  const float *in1_data;
  const float *in2_data;
  float d_in1;
  float f;
  float *b_in1_data;
  float *c_in1_data;
  int i;
  int loop_ub;
  int stride_0_1_tmp;
  int stride_1_1_tmp;
  in2_data = in2->data;
  in1_data = in1->data;
  f = 0.0F;
  loop_ub = in1->size[0];
  for (i = 0; i < loop_ub; i++) {
    f += 2.0F * in1_data[i] * in2_data[i];
  }
  emxInit_real32_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real32_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1_tmp = (in1->size[0] != 1);
  stride_1_1_tmp = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1_tmp] - in2_data[i * stride_1_1_tmp];
  }
  emxInit_real32_T(&c_in1, 1);
  i = c_in1->size[0];
  c_in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(c_in1, i);
  c_in1_data = c_in1->data;
  for (i = 0; i < loop_ub; i++) {
    c_in1_data[i] = in1_data[i * stride_0_1_tmp] + in2_data[i * stride_1_1_tmp];
  }
  d_in1 = 0.0F;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    d_in1 += b_in1_data[i] * c_in1_data[i];
  }
  emxFree_real32_T(&c_in1);
  emxFree_real32_T(&b_in1);
  return 0.5F * b_atan2(f, d_in1);
}

/*
 * Arguments    : float in1_data[]
 *                int in2
 *                const float in3_data[]
 *                int in4
 *                int in6
 *                int in7
 *                int in8
 * Return Type  : void
 */
void binary_expand_op_6(float in1_data[], int in2, const float in3_data[],
                        int in4, int in6, int in7, int in8)
{
  float tmp_data[400];
  int tmp_size[2];
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  tmp_size[0] = 1;
  i = (in8 - in7) + 1;
  if (i == 1) {
    loop_ub = in6 + 1;
  } else {
    loop_ub = i;
  }
  tmp_size[1] = loop_ub;
  stride_0_1 = (in6 + 1 != 1);
  stride_1_1 = (i != 1);
  for (i = 0; i < loop_ub; i++) {
    tmp_data[i] = 0.707106769F * (in3_data[in4 + i * stride_0_1] +
                                  in3_data[(in4 + in7) + i * stride_1_1]);
  }
  in1_data[(int)((float)in2 + 1.0F) - 1] = 1000.0F * b_std(tmp_data, tmp_size);
}

/*
 * Arguments    : float in1_data[]
 *                int in2
 *                const float in3_data[]
 *                int in4
 *                int in6
 *                int in7
 *                int in8
 * Return Type  : void
 */
void binary_expand_op_7(float in1_data[], int in2, const float in3_data[],
                        int in4, int in6, int in7, int in8)
{
  float tmp_data[400];
  int tmp_size[2];
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  tmp_size[0] = 1;
  i = (in8 - in7) + 1;
  if (i == 1) {
    loop_ub = in6 + 1;
  } else {
    loop_ub = i;
  }
  tmp_size[1] = loop_ub;
  stride_0_1 = (in6 + 1 != 1);
  stride_1_1 = (i != 1);
  for (i = 0; i < loop_ub; i++) {
    tmp_data[i] = 0.707106769F * (in3_data[in4 + i * stride_0_1] -
                                  in3_data[(in4 + in7) + i * stride_1_1]);
  }
  in1_data[(int)((float)in2 + 1.0F) - 1] = 1000.0F * b_std(tmp_data, tmp_size);
}

/*
 * File trailer for eml_mtimes_helper.c
 *
 * [EOF]
 */
