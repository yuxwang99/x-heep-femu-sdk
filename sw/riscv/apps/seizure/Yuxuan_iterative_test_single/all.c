/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: all.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "all.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_boolean_T *x
 *                emxArray_boolean_T *y
 * Return Type  : void
 */
void all(const emxArray_boolean_T *x, emxArray_boolean_T *y)
{
  int i1;
  int i2;
  int j;
  int vstride;
  const boolean_T *x_data;
  boolean_T *y_data;
  x_data = x->data;
  i2 = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_boolean_T(y, i2);
  y_data = y->data;
  vstride = x->size[0];
  for (i2 = 0; i2 < vstride; i2++) {
    y_data[i2] = true;
  }
  vstride = x->size[0];
  i2 = x->size[0];
  i1 = 0;
  for (j = 0; j < vstride; j++) {
    int ix;
    boolean_T exitg1;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && ((vstride > 0) && (ix <= i2))) {
      if (!x_data[ix - 1]) {
        y_data[j] = false;
        exitg1 = true;
      } else {
        ix += vstride;
      }
    }
  }
}

/*
 * File trailer for all.c
 *
 * [EOF]
 */
