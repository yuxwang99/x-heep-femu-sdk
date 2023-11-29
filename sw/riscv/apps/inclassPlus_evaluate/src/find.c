/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_eml_find(const emxArray_boolean_T *x, int i_data[], int i_size[1])
{
  int idx;
  int ii;
  int k;
  boolean_T exitg1;
  k = (1 <= x->size[0]);
  ii = x->size[0];
  idx = 0;
  i_size[0] = k;
  exitg1 = false;
  while ((!exitg1) && (ii > 0)) {
    if (x->data[ii - 1]) {
      idx = 1;
      i_data[0] = ii;
      exitg1 = true;
    } else {
      ii--;
    }
  }

  if (k == 1) {
    if (idx == 0) {
      i_size[0] = 0;
    }
  } else {
    i_size[0] = (1 <= idx);
  }
}

void c_eml_find(const emxArray_boolean_T *x, int i_data[], int i_size[1])
{
  emxArray_int32_T *i;
  int b_i;
  int idx;
  int ii;
  int k;
  boolean_T exitg1;
  emxInit_int32_T(&i, 1);
  k = (1 <= x->size[0]);
  idx = 0;
  b_i = i->size[0];
  i->size[0] = k;
  emxEnsureCapacity_int32_T(i, b_i);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x->size[0] - 1)) {
    if (x->data[ii]) {
      idx++;
      i->data[idx - 1] = ii + 1;
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
    i->size[0] = (1 <= idx);
    emxEnsureCapacity_int32_T(i, b_i);
  }

  i_size[0] = i->size[0];
  ii = i->size[0];
  for (b_i = 0; b_i < ii; b_i++) {
    i_data[b_i] = i->data[b_i];
  }

  emxFree_int32_T(&i);
}

void d_eml_find(const boolean_T x_data[], const int x_size[2], int i_data[], int
                i_size[2])
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
  } else if (1 > idx) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

void e_eml_find(const boolean_T x[5], int i_data[], int i_size[2])
{
  int idx;
  int ii;
  boolean_T exitg1;
  idx = 0;
  i_size[0] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 5)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 5) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (1 > idx) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

void eml_find(const emxArray_boolean_T *x, emxArray_int32_T *i)
{
  int idx;
  int ii;
  int nx;
  boolean_T exitg1;
  nx = x->size[0];
  idx = 0;
  ii = i->size[0];
  i->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(i, ii);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x->data[ii]) {
      idx++;
      i->data[idx - 1] = ii + 1;
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
    if (1 > idx) {
      i->size[0] = 0;
    } else {
      i->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(i, ii);
  }
}

/* End of code generation (find.c) */
