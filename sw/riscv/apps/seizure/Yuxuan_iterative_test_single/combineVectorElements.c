/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: combineVectorElements.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "combineVectorElements.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "sumprod.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 * Return Type  : float
 */
float b_combineVectorElements(const emxArray_real32_T *x)
{
  return b_blockedSummation(x, x->size[0]);
}

/*
 * Arguments    : const float x[513]
 * Return Type  : float
 */
float c_combineVectorElements(const float x[513])
{
  return c_blockedSummation(x);
}

/*
 * Arguments    : const signed char x[17]
 * Return Type  : double
 */
double combineVectorElements(const signed char x[17])
{
  return blockedSummation(x);
}

/*
 * Arguments    : const float x[8]
 * Return Type  : float
 */
float d_combineVectorElements(const float x[8])
{
  return d_blockedSummation(x);
}

/*
 * Arguments    : const emxArray_boolean_T *x
 * Return Type  : int
 */
int e_combineVectorElements(const emxArray_boolean_T *x)
{
  int k;
  int vlen;
  int y;
  const boolean_T *x_data;
  x_data = x->data;
  vlen = x->size[0];
  if (x->size[0] == 0) {
    y = 0;
  } else {
    y = x_data[0];
    for (k = 2; k <= vlen; k++) {
      nnzfun(&y, x_data[k - 1]);
    }
  }
  return y;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                int vlen
 * Return Type  : float
 */
float f_combineVectorElements(const emxArray_real32_T *x, int vlen)
{
  return b_blockedSummation(x, vlen);
}

/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 * Return Type  : float
 */
float g_combineVectorElements(const float x_data[], const int x_size[2])
{
  return e_blockedSummation(x_data, x_size, x_size[1]);
}

/*
 * Arguments    : const emxArray_real32_T *x
 * Return Type  : float
 */
float h_combineVectorElements(const emxArray_real32_T *x)
{
  const float *x_data;
  float y;
  int k;
  int vlen;
  x_data = x->data;
  vlen = x->size[1];
  if (x->size[1] == 0) {
    y = 1.0F;
  } else {
    y = x_data[0];
    for (k = 2; k <= vlen; k++) {
      y *= x_data[k - 1];
    }
  }
  return y;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                int vlen
 *                int vstart
 * Return Type  : float
 */
float i_combineVectorElements(const emxArray_real32_T *x, int vlen, int vstart)
{
  return f_blockedSummation(x, vlen, vstart);
}

/*
 * File trailer for combineVectorElements.c
 *
 * [EOF]
 */
