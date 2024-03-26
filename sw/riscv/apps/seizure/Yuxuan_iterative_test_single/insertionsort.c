/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: insertionsort.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "insertionsort.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_int32_T *x
 *                int xstart
 *                int xend
 * Return Type  : void
 */
void insertionsort(emxArray_int32_T *x, int xstart, int xend)
{
  int i;
  int k;
  int *x_data;
  x_data = x->data;
  i = xstart + 1;
  for (k = i; k <= xend; k++) {
    int idx;
    int xc;
    boolean_T exitg1;
    xc = x_data[k - 1];
    idx = k - 1;
    exitg1 = false;
    while ((!exitg1) && (idx >= xstart)) {
      int i1;
      i1 = x_data[idx - 1];
      if (xc < i1) {
        x_data[idx] = i1;
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x_data[idx] = xc;
  }
}

/*
 * File trailer for insertionsort.c
 *
 * [EOF]
 */
