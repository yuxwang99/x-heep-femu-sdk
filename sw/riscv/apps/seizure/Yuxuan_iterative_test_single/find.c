/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: find.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "find.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_boolean_T *x
 *                int i_data[]
 * Return Type  : int
 */
int b_eml_find(const emxArray_boolean_T *x, int i_data[])
{
  int i_size;
  int idx;
  int ii;
  const boolean_T *x_data;
  boolean_T exitg1;
  x_data = x->data;
  i_size = (x->size[0] >= 1);
  ii = x->size[0];
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (ii > 0)) {
    if (x_data[ii - 1]) {
      idx = 1;
      i_data[0] = ii;
      exitg1 = true;
    } else {
      ii--;
    }
  }
  if (i_size == 1) {
    if (idx == 0) {
      i_size = 0;
    }
  } else {
    i_size = (idx >= 1);
  }
  return i_size;
}

/*
 * Arguments    : const emxArray_boolean_T *x
 *                int i_data[]
 * Return Type  : int
 */
int c_eml_find(const emxArray_boolean_T *x, int i_data[])
{
  emxArray_int32_T *i;
  int b_i;
  int i_size;
  int idx;
  int ii;
  int k;
  int *b_i_data;
  const boolean_T *x_data;
  boolean_T exitg1;
  x_data = x->data;
  k = (x->size[0] >= 1);
  idx = 0;
  emxInit_int32_T(&i, 1);
  b_i = i->size[0];
  i->size[0] = k;
  emxEnsureCapacity_int32_T(i, b_i);
  b_i_data = i->data;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x->size[0] - 1)) {
    if (x_data[ii]) {
      idx++;
      b_i_data[idx - 1] = ii + 1;
      if (idx >= k) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (k == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else {
    b_i = i->size[0];
    i->size[0] = (idx >= 1);
    emxEnsureCapacity_int32_T(i, b_i);
    b_i_data = i->data;
  }
  i_size = i->size[0];
  ii = i->size[0];
  for (b_i = 0; b_i < ii; b_i++) {
    i_data[0] = b_i_data[0];
  }
  emxFree_int32_T(&i);
  return i_size;
}

/*
 * Arguments    : const boolean_T x_data[]
 *                const int x_size[2]
 *                int i_data[]
 *                int i_size[2]
 * Return Type  : void
 */
void d_eml_find(const boolean_T x_data[], const int x_size[2], int i_data[],
                int i_size[2])
{
  int idx;
  int ii;
  int nx;
  boolean_T exitg1;
  nx = x_size[1];
  idx = 0;
  i_size[0] = 1;
  i_size[1] = x_size[1];
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x_size[1] == 1) {
    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  } else if (idx < 1) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

/*
 * Arguments    : const emxArray_boolean_T *x
 *                emxArray_int32_T *i
 * Return Type  : void
 */
void eml_find(const emxArray_boolean_T *x, emxArray_int32_T *i)
{
  int idx;
  int ii;
  int nx;
  int *i_data;
  const boolean_T *x_data;
  boolean_T exitg1;
  x_data = x->data;
  nx = x->size[0];
  idx = 0;
  ii = i->size[0];
  i->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(i, ii);
  i_data = i->data;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x->size[0] == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else {
    ii = i->size[0];
    if (idx < 1) {
      i->size[0] = 0;
    } else {
      i->size[0] = idx;
    }
    emxEnsureCapacity_int32_T(i, ii);
  }
}

/*
 * File trailer for find.c
 *
 * [EOF]
 */
