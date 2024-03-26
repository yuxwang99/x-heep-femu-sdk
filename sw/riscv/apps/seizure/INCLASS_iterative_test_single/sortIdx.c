/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "sortIdx.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "mergesort.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void b_sortIdx(const emxArray_real_T *x, emxArray_int32_T *idx)
{
  int i;
  int loop_ub;
  int *idx_data;
  i = idx->size[0];
  idx->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(idx, i);
  idx_data = idx->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    idx_data[i] = 0;
  }
  if (x->size[0] != 0) {
    d_mergesort(idx, x, x->size[0]);
  }
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void c_sortIdx(const emxArray_real32_T *x, emxArray_int32_T *idx)
{
  int i;
  int loop_ub;
  int *idx_data;
  i = idx->size[0];
  idx->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(idx, i);
  idx_data = idx->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    idx_data[i] = 0;
  }
  if (x->size[0] != 0) {
    e_mergesort(idx, x, x->size[0]);
  }
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void sortIdx(const emxArray_real32_T *x, emxArray_int32_T *idx)
{
  int i;
  int loop_ub;
  int *idx_data;
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(idx, i);
  idx_data = idx->data;
  loop_ub = x->size[1];
  for (i = 0; i < loop_ub; i++) {
    idx_data[i] = 0;
  }
  if (x->size[1] != 0) {
    c_mergesort(idx, x, x->size[1]);
  }
}

/*
 * File trailer for sortIdx.c
 *
 * [EOF]
 */
