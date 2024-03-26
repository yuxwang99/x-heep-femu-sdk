/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortpartition.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "sortpartition.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_int32_T *x
 *                int xstart
 *                int xend
 * Return Type  : int
 */
int sortpartition(emxArray_int32_T *x, int xstart, int xend)
{
  int i;
  int j;
  int p;
  int pivot;
  int t;
  int xmid;
  int *x_data;
  x_data = x->data;
  xmid = (xstart + (xend - xstart) / 2) - 1;
  i = x_data[xstart - 1];
  if (x_data[xmid] < i) {
    x_data[xstart - 1] = x_data[xmid];
    x_data[xmid] = i;
  }
  i = x_data[xstart - 1];
  j = x_data[xend - 1];
  if (j < i) {
    x_data[xstart - 1] = j;
    x_data[xend - 1] = i;
  }
  i = x_data[xend - 1];
  if (i < x_data[xmid]) {
    t = x_data[xmid];
    x_data[xmid] = i;
    x_data[xend - 1] = t;
  }
  pivot = x_data[xmid];
  x_data[xmid] = x_data[xend - 2];
  x_data[xend - 2] = pivot;
  i = xstart - 1;
  j = xend - 2;
  int exitg1;
  do {
    exitg1 = 0;
    for (i++; x_data[i] < pivot; i++) {
    }
    for (j--; pivot < x_data[j]; j--) {
    }
    if (i + 1 >= j + 1) {
      exitg1 = 1;
    } else {
      t = x_data[i];
      x_data[i] = x_data[j];
      x_data[j] = t;
    }
  } while (exitg1 == 0);
  p = i + 1;
  x_data[xend - 2] = x_data[i];
  x_data[i] = pivot;
  return p;
}

/*
 * File trailer for sortpartition.c
 *
 * [EOF]
 */
