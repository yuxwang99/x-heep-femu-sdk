/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.c
 *
 * Code generation for function 'nullAssignment'
 *
 */

/* Include files */
#include "nullAssignment.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_nullAssignment(emxArray_real_T *x, const int idx_data[], const int
                      idx_size[2])
{
  emxArray_boolean_T *b;
  int i;
  int k;
  int k0;
  int nxin;
  int nxout;
  emxInit_boolean_T(&b, 2);
  nxin = x->size[0];
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = x->size[0];
  emxEnsureCapacity_boolean_T(b, i);
  k0 = x->size[0];
  for (i = 0; i < k0; i++) {
    b->data[i] = false;
  }

  i = idx_size[1];
  for (k = 0; k < i; k++) {
    b->data[idx_data[k] - 1] = true;
  }

  k0 = 0;
  i = b->size[1];
  for (k = 0; k < i; k++) {
    k0 += b->data[k];
  }

  nxout = x->size[0] - k0;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b->size[1]) || (!b->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  emxFree_boolean_T(&b);
  i = x->size[0];
  if (1 > nxout) {
    x->size[0] = 0;
  } else {
    x->size[0] = nxout;
  }

  emxEnsureCapacity_real_T(x, i);
}

void c_nullAssignment(emxArray_real_T *x, const int idx_data[], const int
                      idx_size[2])
{
  static double x_data[400];
  emxArray_boolean_T *b;
  emxArray_real_T *b_x;
  int i;
  int k;
  int k0;
  int ncolx;
  int nrowx;
  int nxin;
  int nxout;
  emxInit_boolean_T(&b, 2);
  nxin = x->size[0] * x->size[1];
  nrowx = x->size[0];
  ncolx = x->size[1];
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = nxin;
  emxEnsureCapacity_boolean_T(b, i);
  for (i = 0; i < nxin; i++) {
    b->data[i] = false;
  }

  i = idx_size[1];
  for (k = 0; k < i; k++) {
    b->data[idx_data[k] - 1] = true;
  }

  k0 = 0;
  i = b->size[1];
  for (k = 0; k < i; k++) {
    k0 += b->data[k];
  }

  nxout = nxin - k0;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b->size[1]) || (!b->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  emxFree_boolean_T(&b);
  emxInit_real_T(&b_x, 2);
  if ((nrowx != 1) && (ncolx == 1)) {
    if (1 > nxout) {
      k0 = 0;
    } else {
      k0 = nxout;
    }

    for (i = 0; i < k0; i++) {
      x_data[i] = x->data[i];
    }

    i = x->size[0] * x->size[1];
    x->size[0] = k0;
    x->size[1] = 1;
    emxEnsureCapacity_real_T(x, i);
    for (i = 0; i < k0; i++) {
      x->data[i] = x_data[i];
    }
  } else {
    if (1 > nxout) {
      k0 = 0;
    } else {
      k0 = nxout;
    }

    i = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = k0;
    emxEnsureCapacity_real_T(b_x, i);
    for (i = 0; i < k0; i++) {
      b_x->data[b_x->size[0] * i] = x->data[i];
    }

    i = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, i);
    k0 = b_x->size[1];
    for (i = 0; i < k0; i++) {
      nxout = b_x->size[0];
      for (nxin = 0; nxin < nxout; nxin++) {
        x->data[nxin + x->size[0] * i] = b_x->data[nxin + b_x->size[0] * i];
      }
    }
  }

  emxFree_real_T(&b_x);
}

void nullAssignment(emxArray_real_T *x, int idx)
{
  emxArray_real_T *b_x;
  int k;
  int nxin;
  int nxout;
  nxin = x->size[0] - 2;
  nxout = x->size[0] - 1;
  for (k = idx; k <= nxout; k++) {
    x->data[k - 1] = x->data[k];
  }

  emxInit_real_T(&b_x, 1);
  if (1 > nxout) {
    nxin = -1;
  }

  nxout = b_x->size[0];
  b_x->size[0] = nxin + 1;
  emxEnsureCapacity_real_T(b_x, nxout);
  for (nxout = 0; nxout <= nxin; nxout++) {
    b_x->data[nxout] = x->data[nxout];
  }

  nxout = x->size[0];
  x->size[0] = b_x->size[0];
  emxEnsureCapacity_real_T(x, nxout);
  nxin = b_x->size[0];
  for (nxout = 0; nxout < nxin; nxout++) {
    x->data[nxout] = b_x->data[nxout];
  }

  emxFree_real_T(&b_x);
}

/* End of code generation (nullAssignment.c) */
