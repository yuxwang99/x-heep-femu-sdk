/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: any.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "any.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "isnan.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : boolean_T x
 * Return Type  : boolean_T
 */
boolean_T any(boolean_T x)
{
  return x;
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 * Return Type  : boolean_T
 */
boolean_T b_any(const double x_data[], const int x_size[2])
{
  int ix;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= x_size[1])) {
    if ((x_data[ix] == 0.0) || b_isnan(x_data[ix])) {
      ix++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  return y;
}

/*
 * Arguments    : const emxArray_boolean_T *x
 * Return Type  : boolean_T
 */
boolean_T c_any(const emxArray_boolean_T *x)
{
  int ix;
  const boolean_T *x_data;
  boolean_T exitg1;
  boolean_T y;
  x_data = x->data;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x->size[0])) {
    if (x_data[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

/*
 * File trailer for any.c
 *
 * [EOF]
 */
