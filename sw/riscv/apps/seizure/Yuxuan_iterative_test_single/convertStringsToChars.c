/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: convertStringsToChars.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "convertStringsToChars.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *varargin_1
 *                const emxArray_real32_T *varargin_2
 *                emxArray_real32_T *varargout_1
 *                emxArray_real32_T *varargout_2
 * Return Type  : void
 */
void b_convertStringsToChars(const emxArray_real32_T *varargin_1,
                             const emxArray_real32_T *varargin_2,
                             emxArray_real32_T *varargout_1,
                             emxArray_real32_T *varargout_2)
{
  emxArray_real32_T *r;
  const float *varargin_1_data;
  const float *varargin_2_data;
  float *r1;
  float *varargout_1_data;
  int i;
  int loop_ub;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  i = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = varargin_1->size[0];
  varargout_1->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real32_T(varargout_1, i);
  varargout_1_data = varargout_1->data;
  loop_ub = varargin_1->size[0] * varargin_1->size[1];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = varargin_1_data[i];
  }
  emxInit_real32_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = varargin_2->size[0];
  r->size[1] = 1;
  emxEnsureCapacity_real32_T(r, i);
  r1 = r->data;
  loop_ub = varargin_2->size[0];
  for (i = 0; i < loop_ub; i++) {
    r1[i] = varargin_2_data[i];
  }
  i = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = r->size[0];
  varargout_2->size[1] = 1;
  emxEnsureCapacity_real32_T(varargout_2, i);
  varargout_1_data = varargout_2->data;
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = r1[i];
  }
  emxFree_real32_T(&r);
}

/*
 * Arguments    : const emxArray_real32_T *varargin_1
 *                const emxArray_real32_T *varargin_2
 *                const float varargin_3[2]
 *                emxArray_real32_T *varargout_1
 *                emxArray_real32_T *varargout_2
 *                float varargout_3[2]
 * Return Type  : void
 */
void c_convertStringsToChars(const emxArray_real32_T *varargin_1,
                             const emxArray_real32_T *varargin_2,
                             const float varargin_3[2],
                             emxArray_real32_T *varargout_1,
                             emxArray_real32_T *varargout_2,
                             float varargout_3[2])
{
  emxArray_real32_T *r;
  const float *varargin_1_data;
  const float *varargin_2_data;
  float *r1;
  float *varargout_1_data;
  int i;
  int loop_ub;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  i = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = varargin_1->size[0];
  varargout_1->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real32_T(varargout_1, i);
  varargout_1_data = varargout_1->data;
  loop_ub = varargin_1->size[0] * varargin_1->size[1];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = varargin_1_data[i];
  }
  emxInit_real32_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = varargin_2->size[0];
  r->size[1] = 1;
  emxEnsureCapacity_real32_T(r, i);
  r1 = r->data;
  loop_ub = varargin_2->size[0];
  for (i = 0; i < loop_ub; i++) {
    r1[i] = varargin_2_data[i];
  }
  i = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = r->size[0];
  varargout_2->size[1] = 1;
  emxEnsureCapacity_real32_T(varargout_2, i);
  varargout_1_data = varargout_2->data;
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = r1[i];
  }
  emxFree_real32_T(&r);
  varargout_3[0] = varargin_3[0];
  varargout_3[1] = varargin_3[1];
}

/*
 * Arguments    : const float varargin_1_data[]
 *                const int varargin_1_size[2]
 *                float varargout_1_data[]
 *                int varargout_1_size[2]
 * Return Type  : void
 */
void convertStringsToChars(const float varargin_1_data[],
                           const int varargin_1_size[2],
                           float varargout_1_data[], int varargout_1_size[2])
{
  int loop_ub;
  varargout_1_size[0] = 1;
  varargout_1_size[1] = varargin_1_size[1];
  loop_ub = varargin_1_size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&varargout_1_data[0], &varargin_1_data[0],
           (unsigned int)loop_ub * sizeof(float));
  }
}

/*
 * File trailer for convertStringsToChars.c
 *
 * [EOF]
 */
