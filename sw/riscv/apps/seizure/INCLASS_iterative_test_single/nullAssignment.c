/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: nullAssignment.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "nullAssignment.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void b_onearg_null_assignment(emxArray_real32_T *x, const int idx_data[],
                                     const int idx_size[2]);

static void c_onearg_null_assignment(emxArray_real32_T *x, const int idx_data[],
                                     const int idx_size[2]);

static void make_bitarray(int n, const int idx_data[], const int idx_size[2],
                          emxArray_boolean_T *b);

static int num_true(const emxArray_boolean_T *b);

static void onearg_null_assignment(emxArray_real32_T *x, int idx);

/* Function Definitions */
/*
 * Arguments    : emxArray_real32_T *x
 *                const int idx_data[]
 *                const int idx_size[2]
 * Return Type  : void
 */
static void b_onearg_null_assignment(emxArray_real32_T *x, const int idx_data[],
                                     const int idx_size[2])
{
  emxArray_boolean_T *b;
  float *x_data;
  int k;
  int k0;
  int nxin;
  int nxout;
  boolean_T *b_data;
  x_data = x->data;
  nxin = x->size[0];
  emxInit_boolean_T(&b, 2);
  make_bitarray(x->size[0], idx_data, idx_size, b);
  b_data = b->data;
  nxout = x->size[0] - num_true(b);
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b->size[1]) || (!b_data[k])) {
      k0++;
      x_data[k0] = x_data[k];
    }
  }
  emxFree_boolean_T(&b);
  nxin = x->size[0];
  if (nxout < 1) {
    x->size[0] = 0;
  } else {
    x->size[0] = nxout;
  }
  emxEnsureCapacity_real32_T(x, nxin);
}

/*
 * Arguments    : emxArray_real32_T *x
 *                const int idx_data[]
 *                const int idx_size[2]
 * Return Type  : void
 */
static void c_onearg_null_assignment(emxArray_real32_T *x, const int idx_data[],
                                     const int idx_size[2])
{
  emxArray_boolean_T *b;
  float *x_data;
  int k;
  int k0;
  int nxin_tmp;
  int nxout;
  boolean_T *b_data;
  x_data = x->data;
  nxin_tmp = x->size[0] * x->size[1];
  emxInit_boolean_T(&b, 2);
  make_bitarray(nxin_tmp, idx_data, idx_size, b);
  b_data = b->data;
  nxout = nxin_tmp - num_true(b);
  k0 = -1;
  for (k = 0; k < nxin_tmp; k++) {
    if ((k + 1 > b->size[1]) || (!b_data[k])) {
      k0++;
      x_data[k0] = x_data[k];
    }
  }
  emxFree_boolean_T(&b);
  if ((x->size[0] != 1) && (x->size[1] == 1)) {
    float b_x_data[400];
    if (nxout < 1) {
      nxin_tmp = 0;
    } else {
      nxin_tmp = nxout;
    }
    for (k0 = 0; k0 < nxin_tmp; k0++) {
      b_x_data[k0] = x_data[k0];
    }
    k0 = x->size[0] * x->size[1];
    x->size[0] = nxin_tmp;
    x->size[1] = 1;
    emxEnsureCapacity_real32_T(x, k0);
    x_data = x->data;
    for (k0 = 0; k0 < nxin_tmp; k0++) {
      x_data[k0] = b_x_data[k0];
    }
  } else {
    k0 = x->size[0] * x->size[1];
    x->size[0] = 1;
    if (nxout < 1) {
      x->size[1] = 0;
    } else {
      x->size[1] = nxout;
    }
    emxEnsureCapacity_real32_T(x, k0);
  }
}

/*
 * Arguments    : int n
 *                const int idx_data[]
 *                const int idx_size[2]
 *                emxArray_boolean_T *b
 * Return Type  : void
 */
static void make_bitarray(int n, const int idx_data[], const int idx_size[2],
                          emxArray_boolean_T *b)
{
  int i;
  int k;
  boolean_T *b_data;
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = n;
  emxEnsureCapacity_boolean_T(b, i);
  b_data = b->data;
  for (i = 0; i < n; i++) {
    b_data[i] = false;
  }
  i = idx_size[1];
  for (k = 0; k < i; k++) {
    b_data[idx_data[k] - 1] = true;
  }
}

/*
 * Arguments    : const emxArray_boolean_T *b
 * Return Type  : int
 */
static int num_true(const emxArray_boolean_T *b)
{
  int i;
  int k;
  int n;
  const boolean_T *b_data;
  b_data = b->data;
  n = 0;
  i = b->size[1];
  for (k = 0; k < i; k++) {
    n += b_data[k];
  }
  return n;
}

/*
 * Arguments    : emxArray_real32_T *x
 *                int idx
 * Return Type  : void
 */
static void onearg_null_assignment(emxArray_real32_T *x, int idx)
{
  float *x_data;
  int k;
  int nxout;
  x_data = x->data;
  nxout = x->size[0] - 1;
  for (k = idx; k <= nxout; k++) {
    x_data[k - 1] = x_data[k];
  }
  nxout = x->size[0];
  if (x->size[0] - 1 < 1) {
    x->size[0] = 0;
  } else {
    x->size[0]--;
  }
  emxEnsureCapacity_real32_T(x, nxout);
}

/*
 * Arguments    : emxArray_real32_T *x
 *                const int idx_data[]
 *                const int idx_size[2]
 * Return Type  : void
 */
void b_nullAssignment(emxArray_real32_T *x, const int idx_data[],
                      const int idx_size[2])
{
  b_onearg_null_assignment(x, idx_data, idx_size);
}

/*
 * Arguments    : emxArray_real32_T *x
 *                const int idx_data[]
 *                const int idx_size[2]
 * Return Type  : void
 */
void c_nullAssignment(emxArray_real32_T *x, const int idx_data[],
                      const int idx_size[2])
{
  c_onearg_null_assignment(x, idx_data, idx_size);
}

/*
 * Arguments    : emxArray_real32_T *x
 *                int idx
 * Return Type  : void
 */
void nullAssignment(emxArray_real32_T *x, int idx)
{
  onearg_null_assignment(x, idx);
}

/*
 * File trailer for nullAssignment.c
 *
 * [EOF]
 */
