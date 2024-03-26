/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: heapsort.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "heapsort.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void heapify(emxArray_int32_T *x, int idx, int xstart, int xend);

static void makeHeap(emxArray_int32_T *x, int xstart, int xend, int n);

/* Function Definitions */
/*
 * Arguments    : emxArray_int32_T *x
 *                int idx
 *                int xstart
 *                int xend
 * Return Type  : void
 */
static void heapify(emxArray_int32_T *x, int idx, int xstart, int xend)
{
  int cmpIdx;
  int extremum;
  int extremumIdx;
  int leftIdx;
  int *x_data;
  boolean_T changed;
  boolean_T exitg1;
  x_data = x->data;
  changed = true;
  extremumIdx = (idx + xstart) - 2;
  leftIdx = ((idx << 1) + xstart) - 1;
  exitg1 = false;
  while ((!exitg1) && (leftIdx < xend)) {
    int xcmp;
    changed = false;
    extremum = x_data[extremumIdx];
    cmpIdx = leftIdx - 1;
    xcmp = x_data[leftIdx - 1];
    if (xcmp < x_data[leftIdx]) {
      cmpIdx = leftIdx;
      xcmp = x_data[leftIdx];
    }
    if (x_data[extremumIdx] < xcmp) {
      x_data[extremumIdx] = xcmp;
      x_data[cmpIdx] = extremum;
      extremumIdx = cmpIdx;
      leftIdx = ((((cmpIdx - xstart) + 2) << 1) + xstart) - 1;
      changed = true;
    } else {
      exitg1 = true;
    }
  }
  if (changed && (leftIdx <= xend)) {
    extremum = x_data[extremumIdx];
    cmpIdx = x_data[leftIdx - 1];
    if (x_data[extremumIdx] < cmpIdx) {
      x_data[extremumIdx] = cmpIdx;
      x_data[leftIdx - 1] = extremum;
    }
  }
}

/*
 * Arguments    : emxArray_int32_T *x
 *                int xstart
 *                int xend
 *                int n
 * Return Type  : void
 */
static void makeHeap(emxArray_int32_T *x, int xstart, int xend, int n)
{
  int idx;
  for (idx = n; idx >= 1; idx--) {
    heapify(x, idx, xstart, xend);
  }
}

/*
 * Arguments    : emxArray_int32_T *x
 *                int xstart
 *                int xend
 * Return Type  : void
 */
void b_heapsort(emxArray_int32_T *x, int xstart, int xend)
{
  int k;
  int n;
  int *x_data;
  n = (xend - xstart) - 1;
  makeHeap(x, xstart, xend, n + 2);
  x_data = x->data;
  for (k = 0; k <= n; k++) {
    int t;
    int t_tmp;
    t_tmp = (xend - k) - 1;
    t = x_data[t_tmp];
    x_data[t_tmp] = x_data[xstart - 1];
    x_data[xstart - 1] = t;
    heapify(x, 1, xstart, t_tmp);
    x_data = x->data;
  }
}

/*
 * File trailer for heapsort.c
 *
 * [EOF]
 */
