/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: bandpower.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "bandpower.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "convertStringsToChars.h"
#include "diff.h"
#include "find.h"
#include "isrow.h"
#include "mtimes.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void b_psdbandpower(const emxArray_real32_T *Pxx,
                           const emxArray_real32_T *W, const float freqrange[2],
                           float pwr_data[], int pwr_size[2]);

static void psdbandpower(const emxArray_real32_T *Pxx,
                         const emxArray_real32_T *W, float pwr_data[],
                         int pwr_size[2]);

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *Pxx
 *                const emxArray_real32_T *W
 *                const float freqrange[2]
 *                float pwr_data[]
 *                int pwr_size[2]
 * Return Type  : void
 */
static void b_psdbandpower(const emxArray_real32_T *Pxx,
                           const emxArray_real32_T *W, const float freqrange[2],
                           float pwr_data[], int pwr_size[2])
{
  emxArray_boolean_T *c_W;
  emxArray_real32_T d_W;
  emxArray_real32_T *colPxx1;
  emxArray_real32_T *r;
  emxArray_real32_T *width;
  const float *Pxx_data;
  const float *W_data;
  float *colPxx1_data;
  float *r1;
  float *width_data;
  int b_W;
  int e_W;
  int i;
  int i1;
  int idx_data;
  int loop_ub;
  int tmp_data;
  boolean_T *b_W_data;
  W_data = W->data;
  Pxx_data = Pxx->data;
  emxInit_real32_T(&colPxx1, 2);
  if (isrow(Pxx)) {
    loop_ub = Pxx->size[0] * Pxx->size[1];
    i = colPxx1->size[0] * colPxx1->size[1];
    colPxx1->size[0] = loop_ub;
    colPxx1->size[1] = 1;
    emxEnsureCapacity_real32_T(colPxx1, i);
    colPxx1_data = colPxx1->data;
    for (i = 0; i < loop_ub; i++) {
      colPxx1_data[i] = Pxx_data[i];
    }
  } else {
    i = colPxx1->size[0] * colPxx1->size[1];
    colPxx1->size[0] = Pxx->size[0];
    colPxx1->size[1] = Pxx->size[1];
    emxEnsureCapacity_real32_T(colPxx1, i);
    colPxx1_data = colPxx1->data;
    loop_ub = Pxx->size[0] * Pxx->size[1];
    for (i = 0; i < loop_ub; i++) {
      colPxx1_data[i] = Pxx_data[i];
    }
  }
  emxInit_boolean_T(&c_W, 1);
  i = c_W->size[0];
  c_W->size[0] = W->size[0];
  emxEnsureCapacity_boolean_T(c_W, i);
  b_W_data = c_W->data;
  loop_ub = W->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_W_data[i] = (W_data[i] <= freqrange[0]);
  }
  b_eml_find(c_W, (int *)&tmp_data);
  i = c_W->size[0];
  c_W->size[0] = W->size[0];
  emxEnsureCapacity_boolean_T(c_W, i);
  b_W_data = c_W->data;
  loop_ub = W->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_W_data[i] = (W_data[i] >= freqrange[1]);
  }
  c_eml_find(c_W, (int *)&idx_data);
  emxFree_boolean_T(&c_W);
  b_W = W->size[0];
  d_W = *W;
  e_W = b_W;
  d_W.size = &e_W;
  d_W.numDimensions = 1;
  emxInit_real32_T(&r, 1);
  b_diff(&d_W, r);
  r1 = r->data;
  emxInit_real32_T(&width, 1);
  i = width->size[0];
  width->size[0] = r->size[0] + 1;
  emxEnsureCapacity_real32_T(width, i);
  width_data = width->data;
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    width_data[i] = r1[i];
  }
  width_data[r->size[0]] = 0.0F;
  emxFree_real32_T(&r);
  if (tmp_data > idx_data) {
    i = 0;
    idx_data = 0;
    tmp_data = -1;
    i1 = -1;
  } else {
    i = tmp_data - 1;
    tmp_data -= 2;
    i1 = idx_data - 1;
  }
  b_W = idx_data - i;
  for (idx_data = 0; idx_data < b_W; idx_data++) {
    width_data[idx_data] = width_data[i + idx_data];
  }
  i = width->size[0];
  width->size[0] = b_W;
  emxEnsureCapacity_real32_T(width, i);
  b_W = colPxx1->size[1];
  for (i = 0; i < b_W; i++) {
    loop_ub = i1 - tmp_data;
    for (idx_data = 0; idx_data < loop_ub; idx_data++) {
      colPxx1_data[idx_data] = colPxx1_data[(tmp_data + idx_data) + 1];
    }
  }
  i = colPxx1->size[0] * colPxx1->size[1];
  colPxx1->size[0] = i1 - tmp_data;
  emxEnsureCapacity_real32_T(colPxx1, i);
  mtimes(width, colPxx1, pwr_data, pwr_size);
  emxFree_real32_T(&width);
  emxFree_real32_T(&colPxx1);
}

/*
 * Arguments    : const emxArray_real32_T *Pxx
 *                const emxArray_real32_T *W
 *                float pwr_data[]
 *                int pwr_size[2]
 * Return Type  : void
 */
static void psdbandpower(const emxArray_real32_T *Pxx,
                         const emxArray_real32_T *W, float pwr_data[],
                         int pwr_size[2])
{
  emxArray_boolean_T *c_W;
  emxArray_real32_T d_W;
  emxArray_real32_T *W_diff;
  emxArray_real32_T *colPxx1;
  emxArray_real32_T *width;
  const float *Pxx_data;
  const float *W_data;
  float freqrange_idx_0;
  float freqrange_idx_1_tmp;
  float *W_diff_data;
  float *colPxx1_data;
  float *width_data;
  int b_W;
  int e_W;
  int i;
  int i1;
  int idx_data;
  int loop_ub;
  int tmp_data;
  boolean_T *b_W_data;
  W_data = W->data;
  Pxx_data = Pxx->data;
  emxInit_real32_T(&colPxx1, 2);
  if (isrow(Pxx)) {
    loop_ub = Pxx->size[0] * Pxx->size[1];
    i = colPxx1->size[0] * colPxx1->size[1];
    colPxx1->size[0] = loop_ub;
    colPxx1->size[1] = 1;
    emxEnsureCapacity_real32_T(colPxx1, i);
    colPxx1_data = colPxx1->data;
    for (i = 0; i < loop_ub; i++) {
      colPxx1_data[i] = Pxx_data[i];
    }
  } else {
    i = colPxx1->size[0] * colPxx1->size[1];
    colPxx1->size[0] = Pxx->size[0];
    colPxx1->size[1] = Pxx->size[1];
    emxEnsureCapacity_real32_T(colPxx1, i);
    colPxx1_data = colPxx1->data;
    loop_ub = Pxx->size[0] * Pxx->size[1];
    for (i = 0; i < loop_ub; i++) {
      colPxx1_data[i] = Pxx_data[i];
    }
  }
  freqrange_idx_0 = W_data[0];
  freqrange_idx_1_tmp = W_data[W->size[0] - 1];
  emxInit_boolean_T(&c_W, 1);
  i = c_W->size[0];
  c_W->size[0] = W->size[0];
  emxEnsureCapacity_boolean_T(c_W, i);
  b_W_data = c_W->data;
  loop_ub = W->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_W_data[i] = (W_data[i] <= freqrange_idx_0);
  }
  b_eml_find(c_W, (int *)&tmp_data);
  i = c_W->size[0];
  c_W->size[0] = W->size[0];
  emxEnsureCapacity_boolean_T(c_W, i);
  b_W_data = c_W->data;
  loop_ub = W->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_W_data[i] = (W_data[i] >= freqrange_idx_1_tmp);
  }
  c_eml_find(c_W, (int *)&idx_data);
  emxFree_boolean_T(&c_W);
  b_W = W->size[0];
  d_W = *W;
  e_W = b_W;
  d_W.size = &e_W;
  d_W.numDimensions = 1;
  emxInit_real32_T(&W_diff, 1);
  b_diff(&d_W, W_diff);
  W_diff_data = W_diff->data;
  freqrange_idx_0 =
      (freqrange_idx_1_tmp - W_data[0]) / (float)((double)W->size[0] - 1.0);
  emxInit_real32_T(&width, 1);
  if (W_data[0] != 0.0F) {
    i = width->size[0];
    width->size[0] = W_diff->size[0] + 1;
    emxEnsureCapacity_real32_T(width, i);
    width_data = width->data;
    width_data[0] = freqrange_idx_0;
    loop_ub = W_diff->size[0];
    for (i = 0; i < loop_ub; i++) {
      width_data[i + 1] = W_diff_data[i];
    }
  } else {
    i = width->size[0];
    width->size[0] = W_diff->size[0] + 1;
    emxEnsureCapacity_real32_T(width, i);
    width_data = width->data;
    loop_ub = W_diff->size[0];
    for (i = 0; i < loop_ub; i++) {
      width_data[i] = W_diff_data[i];
    }
    width_data[W_diff->size[0]] = freqrange_idx_0;
  }
  emxFree_real32_T(&W_diff);
  if (tmp_data > idx_data) {
    i = 0;
    idx_data = 0;
    tmp_data = -1;
    i1 = -1;
  } else {
    i = tmp_data - 1;
    tmp_data -= 2;
    i1 = idx_data - 1;
  }
  b_W = idx_data - i;
  for (idx_data = 0; idx_data < b_W; idx_data++) {
    width_data[idx_data] = width_data[i + idx_data];
  }
  i = width->size[0];
  width->size[0] = b_W;
  emxEnsureCapacity_real32_T(width, i);
  b_W = colPxx1->size[1];
  for (i = 0; i < b_W; i++) {
    loop_ub = i1 - tmp_data;
    for (idx_data = 0; idx_data < loop_ub; idx_data++) {
      colPxx1_data[idx_data] = colPxx1_data[(tmp_data + idx_data) + 1];
    }
  }
  i = colPxx1->size[0] * colPxx1->size[1];
  colPxx1->size[0] = i1 - tmp_data;
  emxEnsureCapacity_real32_T(colPxx1, i);
  mtimes(width, colPxx1, pwr_data, pwr_size);
  emxFree_real32_T(&width);
  emxFree_real32_T(&colPxx1);
}

/*
 * Arguments    : const emxArray_real32_T *varargin_1
 *                const emxArray_real32_T *varargin_2
 *                const float varargin_3[2]
 *                float pwr_data[]
 *                int pwr_size[2]
 * Return Type  : void
 */
void b_bandpower(const emxArray_real32_T *varargin_1,
                 const emxArray_real32_T *varargin_2, const float varargin_3[2],
                 float pwr_data[], int pwr_size[2])
{
  emxArray_real32_T *inputArgs_f1;
  emxArray_real32_T *r;
  float inputArgs_f3[2];
  emxInit_real32_T(&inputArgs_f1, 2);
  emxInit_real32_T(&r, 2);
  c_convertStringsToChars(varargin_1, varargin_2, varargin_3, inputArgs_f1, r,
                          inputArgs_f3);
  b_psdbandpower(inputArgs_f1, r, inputArgs_f3, pwr_data, pwr_size);
  emxFree_real32_T(&r);
  emxFree_real32_T(&inputArgs_f1);
}

/*
 * Arguments    : const emxArray_real32_T *varargin_1
 *                const emxArray_real32_T *varargin_2
 *                float pwr_data[]
 *                int pwr_size[2]
 * Return Type  : void
 */
void bandpower(const emxArray_real32_T *varargin_1,
               const emxArray_real32_T *varargin_2, float pwr_data[],
               int pwr_size[2])
{
  emxArray_real32_T *inputArgs_f1;
  emxArray_real32_T *r;
  emxInit_real32_T(&inputArgs_f1, 2);
  emxInit_real32_T(&r, 2);
  b_convertStringsToChars(varargin_1, varargin_2, inputArgs_f1, r);
  psdbandpower(inputArgs_f1, r, pwr_data, pwr_size);
  emxFree_real32_T(&r);
  emxFree_real32_T(&inputArgs_f1);
}

/*
 * Arguments    : const emxArray_real32_T *varargin_1
 *                const emxArray_real32_T *varargin_2
 *                const float varargin_3[2]
 *                float pwr_data[]
 *                int pwr_size[2]
 * Return Type  : void
 */
void c_bandpower(const emxArray_real32_T *varargin_1,
                 const emxArray_real32_T *varargin_2, const float varargin_3[2],
                 float pwr_data[], int pwr_size[2])
{
  emxArray_real32_T *r;
  emxArray_real32_T *r1;
  float inputArgs_f3[2];
  float tmp_data;
  int tmp_size[2];
  emxInit_real32_T(&r, 2);
  emxInit_real32_T(&r1, 2);
  c_convertStringsToChars(varargin_1, varargin_2, varargin_3, r1, r,
                          inputArgs_f3);
  b_psdbandpower(r1, r, inputArgs_f3, (float *)&tmp_data, tmp_size);
  emxFree_real32_T(&r1);
  emxFree_real32_T(&r);
  pwr_size[0] = 1;
  pwr_size[1] = tmp_size[1];
  pwr_data[0] = tmp_data;
}

/*
 * File trailer for bandpower.c
 *
 * [EOF]
 */
