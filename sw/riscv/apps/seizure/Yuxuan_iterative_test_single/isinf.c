/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: isinf.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "isinf.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float x
 * Return Type  : boolean_T
 */
boolean_T b_isinf(float x)
{
  return rtIsInfF(x);
}

/*
 * Arguments    : double x
 * Return Type  : boolean_T
 */
boolean_T c_isinf(double x)
{
  return rtIsInf(x);
}

/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 *                boolean_T b_data[]
 *                int b_size[2]
 * Return Type  : void
 */
void d_isinf(const float x_data[], const int x_size[2], boolean_T b_data[],
             int b_size[2])
{
  int i;
  int loop_ub;
  b_size[0] = 1;
  b_size[1] = x_size[1];
  loop_ub = x_size[1];
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = rtIsInfF(x_data[i]);
  }
}

/*
 * File trailer for isinf.c
 *
 * [EOF]
 */
