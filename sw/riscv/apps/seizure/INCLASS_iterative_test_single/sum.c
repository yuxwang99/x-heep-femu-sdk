/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sum.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "sum.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 * Return Type  : float
 */
float b_sum(const float x_data[], const int x_size[2])
{
  return g_combineVectorElements(x_data, x_size);
}

/*
 * Arguments    : const signed char x[17]
 * Return Type  : double
 */
double sum(const signed char x[17])
{
  return combineVectorElements(x);
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
