/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mergesort.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "mergesort.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include "sortLE.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_int32_T *idx
 *                const emxArray_real32_T *x
 *                int n
 * Return Type  : void
 */
void b_mergesort(emxArray_int32_T *idx, const emxArray_real32_T *x, int n)
{
  emxArray_int32_T *iwork;
  int b_i;
  int i;
  int k;
  int pEnd;
  int qEnd;
  int *idx_data;
  int *iwork_data;
  idx_data = idx->data;
  emxInit_int32_T(&iwork, 1);
  i = iwork->size[0];
  iwork->size[0] = idx->size[0];
  emxEnsureCapacity_int32_T(iwork, i);
  iwork_data = iwork->data;
  i = n - 1;
  for (k = 1; k <= i; k += 2) {
    if (sortLE(x, k, k + 1)) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }
  if ((n & 1) != 0) {
    idx_data[n - 1] = n;
  }
  b_i = 2;
  while (b_i < n) {
    int i2;
    int j;
    i2 = b_i << 1;
    j = 1;
    for (pEnd = b_i + 1; pEnd < n + 1; pEnd = qEnd + b_i) {
      int kEnd;
      int p;
      int q;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n + 1) {
        qEnd = n + 1;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int i1;
        i = idx_data[p - 1];
        i1 = idx_data[q - 1];
        if (sortLE(x, i, i1)) {
          iwork_data[k] = i;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork_data[k] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[k] = i1;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }
      j = qEnd;
    }
    b_i = i2;
  }
  emxFree_int32_T(&iwork);
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                const emxArray_real32_T *x
 *                int n
 * Return Type  : void
 */
void c_mergesort(emxArray_int32_T *idx, const emxArray_real32_T *x, int n)
{
  emxArray_int32_T *iwork;
  int b_i;
  int i;
  int k;
  int pEnd;
  int qEnd;
  int *idx_data;
  int *iwork_data;
  idx_data = idx->data;
  emxInit_int32_T(&iwork, 1);
  i = iwork->size[0];
  iwork->size[0] = idx->size[1];
  emxEnsureCapacity_int32_T(iwork, i);
  iwork_data = iwork->data;
  i = n - 1;
  for (k = 1; k <= i; k += 2) {
    if (b_sortLE(x, k, k + 1)) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }
  if ((n & 1) != 0) {
    idx_data[n - 1] = n;
  }
  b_i = 2;
  while (b_i < n) {
    int i2;
    int j;
    i2 = b_i << 1;
    j = 1;
    for (pEnd = b_i + 1; pEnd < n + 1; pEnd = qEnd + b_i) {
      int kEnd;
      int p;
      int q;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n + 1) {
        qEnd = n + 1;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int i1;
        i = idx_data[p - 1];
        i1 = idx_data[q - 1];
        if (b_sortLE(x, i, i1)) {
          iwork_data[k] = i;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork_data[k] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[k] = i1;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }
      j = qEnd;
    }
    b_i = i2;
  }
  emxFree_int32_T(&iwork);
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                const emxArray_real_T *x
 *                int n
 * Return Type  : void
 */
void d_mergesort(emxArray_int32_T *idx, const emxArray_real_T *x, int n)
{
  emxArray_int32_T *iwork;
  int b_i;
  int i;
  int k;
  int pEnd;
  int qEnd;
  int *idx_data;
  int *iwork_data;
  idx_data = idx->data;
  emxInit_int32_T(&iwork, 1);
  i = iwork->size[0];
  iwork->size[0] = idx->size[0];
  emxEnsureCapacity_int32_T(iwork, i);
  iwork_data = iwork->data;
  i = n - 1;
  for (k = 1; k <= i; k += 2) {
    if (c_sortLE(x, k, k + 1)) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }
  if ((n & 1) != 0) {
    idx_data[n - 1] = n;
  }
  b_i = 2;
  while (b_i < n) {
    int i2;
    int j;
    i2 = b_i << 1;
    j = 1;
    for (pEnd = b_i + 1; pEnd < n + 1; pEnd = qEnd + b_i) {
      int kEnd;
      int p;
      int q;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n + 1) {
        qEnd = n + 1;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int i1;
        i = idx_data[p - 1];
        i1 = idx_data[q - 1];
        if (c_sortLE(x, i, i1)) {
          iwork_data[k] = i;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork_data[k] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[k] = i1;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }
      j = qEnd;
    }
    b_i = i2;
  }
  emxFree_int32_T(&iwork);
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                const emxArray_real32_T *x
 *                int n
 * Return Type  : void
 */
void e_mergesort(emxArray_int32_T *idx, const emxArray_real32_T *x, int n)
{
  emxArray_int32_T *iwork;
  int b_i;
  int i;
  int k;
  int pEnd;
  int qEnd;
  int *idx_data;
  int *iwork_data;
  idx_data = idx->data;
  emxInit_int32_T(&iwork, 1);
  i = iwork->size[0];
  iwork->size[0] = idx->size[0];
  emxEnsureCapacity_int32_T(iwork, i);
  iwork_data = iwork->data;
  i = n - 1;
  for (k = 1; k <= i; k += 2) {
    if (b_sortLE(x, k, k + 1)) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }
  if ((n & 1) != 0) {
    idx_data[n - 1] = n;
  }
  b_i = 2;
  while (b_i < n) {
    int i2;
    int j;
    i2 = b_i << 1;
    j = 1;
    for (pEnd = b_i + 1; pEnd < n + 1; pEnd = qEnd + b_i) {
      int kEnd;
      int p;
      int q;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n + 1) {
        qEnd = n + 1;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int i1;
        i = idx_data[p - 1];
        i1 = idx_data[q - 1];
        if (b_sortLE(x, i, i1)) {
          iwork_data[k] = i;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork_data[k] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[k] = i1;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }
      j = qEnd;
    }
    b_i = i2;
  }
  emxFree_int32_T(&iwork);
}

/*
 * File trailer for mergesort.c
 *
 * [EOF]
 */
