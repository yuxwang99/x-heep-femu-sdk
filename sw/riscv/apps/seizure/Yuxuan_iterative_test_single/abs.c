/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: abs.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "abs.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "abs1.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x
 * Return Type  : double
 */
double b_abs(double x)
{
  return c_abs(x);
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void e_abs(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  const float *x_data;
  float *y_data;
  int k;
  int nx;
  x_data = x->data;
  nx = x->size[0];
  k = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real32_T(y, k);
  y_data = y->data;
  for (k = 0; k < nx; k++) {
    y_data[k] = f_abs(x_data[k]);
  }
}

/*
 * Arguments    : float x
 * Return Type  : float
 */
float g_abs(float x)
{
  return f_abs(x);
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void h_abs(const emxArray_creal_T *x, emxArray_real_T *y)
{
  const creal_T *x_data;
  double *y_data;
  int k;
  int nx;
  x_data = x->data;
  nx = x->size[0];
  k = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real_T(y, k);
  y_data = y->data;
  for (k = 0; k < nx; k++) {
    y_data[k] = d_abs(x_data[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
