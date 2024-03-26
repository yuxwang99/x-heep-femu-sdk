/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mean.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "mean.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const float x[513]
 * Return Type  : float
 */
float b_mean(const float x[513])
{
  return c_combineVectorElements(x) / 513.0F;
}

/*
 * Arguments    : const float x[8]
 * Return Type  : float
 */
float c_mean(const float x[8])
{
  return d_combineVectorElements(x) / 8.0F;
}

/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 * Return Type  : float
 */
float d_mean(const float x_data[], const int x_size[2])
{
  return g_combineVectorElements(x_data, x_size) / (float)x_size[1];
}

/*
 * Arguments    : const emxArray_real32_T *x
 * Return Type  : float
 */
float mean(const emxArray_real32_T *x)
{
  return b_combineVectorElements(x) / (float)x->size[0];
}

/*
 * File trailer for mean.c
 *
 * [EOF]
 */
