/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bandpower.c
 *
 * Code generation for function 'bandpower'
 *
 */

/* Include files */
#include "bandpower.h"
#include "diff.h"
#include "find.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void bandpower(const emxArray_real_T *varargin_1, const emxArray_real_T
               *varargin_2, const double varargin_3[2], double pwr_data[], int
               pwr_size[2])
{
  emxArray_boolean_T *b_varargin_2;
  emxArray_real_T c_varargin_2;
  emxArray_real_T *colPxx;
  emxArray_real_T *r;
  emxArray_real_T *width;
  int d_varargin_2[1];
  int idx_data[1];
  int idx_size[1];
  int tmp_data[1];
  int i;
  int i1;
  int i2;
  int j;
  int k;
  int loop_ub;
  int nc;
  int pwr_tmp;
  emxInit_real_T(&colPxx, 2);
  i = colPxx->size[0] * colPxx->size[1];
  colPxx->size[0] = varargin_1->size[0];
  colPxx->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real_T(colPxx, i);
  loop_ub = varargin_1->size[0] * varargin_1->size[1];
  for (i = 0; i < loop_ub; i++) {
    colPxx->data[i] = varargin_1->data[i];
  }

  if (varargin_1->size[0] == 1) {
    i = colPxx->size[0] * colPxx->size[1];
    colPxx->size[0] = varargin_1->size[0] * varargin_1->size[1];
    colPxx->size[1] = 1;
    emxEnsureCapacity_real_T(colPxx, i);
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i = 0; i < loop_ub; i++) {
      colPxx->data[i] = varargin_1->data[i];
    }
  }

  emxInit_boolean_T(&b_varargin_2, 1);
  i = b_varargin_2->size[0];
  b_varargin_2->size[0] = varargin_2->size[0];
  emxEnsureCapacity_boolean_T(b_varargin_2, i);
  loop_ub = varargin_2->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_2->data[i] = (varargin_2->data[i] <= varargin_3[0]);
  }

  b_eml_find(b_varargin_2, tmp_data, idx_data);
  i = b_varargin_2->size[0];
  b_varargin_2->size[0] = varargin_2->size[0];
  emxEnsureCapacity_boolean_T(b_varargin_2, i);
  loop_ub = varargin_2->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_2->data[i] = (varargin_2->data[i] >= varargin_3[1]);
  }

  emxInit_real_T(&width, 1);
  emxInit_real_T(&r, 1);
  c_eml_find(b_varargin_2, idx_data, idx_size);
  loop_ub = varargin_2->size[0];
  c_varargin_2 = *varargin_2;
  d_varargin_2[0] = loop_ub;
  c_varargin_2.size = &d_varargin_2[0];
  c_varargin_2.numDimensions = 1;
  b_diff(&c_varargin_2, r);
  i = width->size[0];
  width->size[0] = r->size[0] + 1;
  emxEnsureCapacity_real_T(width, i);
  loop_ub = r->size[0];
  emxFree_boolean_T(&b_varargin_2);
  for (i = 0; i < loop_ub; i++) {
    width->data[i] = r->data[i];
  }

  width->data[r->size[0]] = 0.0;
  emxFree_real_T(&r);
  if (tmp_data[0] > idx_data[0]) {
    i = 0;
    loop_ub = 0;
    i1 = 0;
    i2 = 0;
  } else {
    i = tmp_data[0] - 1;
    loop_ub = idx_data[0];
    i1 = tmp_data[0] - 1;
    i2 = idx_data[0];
  }

  loop_ub -= i;
  nc = colPxx->size[1] - 1;
  pwr_size[0] = 1;
  pwr_size[1] = colPxx->size[1];
  for (j = 0; j <= nc; j++) {
    pwr_data[0] = 0.0;
    for (k = 0; k < loop_ub; k++) {
      pwr_tmp = i2 - i1;
      pwr_data[0] += width->data[i + k] * colPxx->data[(i1 + k % pwr_tmp) +
        colPxx->size[0] * (k / pwr_tmp)];
    }
  }

  emxFree_real_T(&width);
  emxFree_real_T(&colPxx);
}

/* End of code generation (bandpower.c) */
