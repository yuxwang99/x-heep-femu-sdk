/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xnrm2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "xnrm2.h"
#include "INCLASS_iterative_test_single_types.h"
#include "abs.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : int n
 *                const emxArray_real32_T *x
 * Return Type  : float
 */
float xnrm2(int n, const emxArray_real32_T *x)
{
  const float *x_data;
  float scale;
  float y;
  int k;
  x_data = x->data;
  y = 0.0F;
  scale = 1.29246971E-26F;
  for (k = 0; k < n; k++) {
    float absxk;
    absxk = g_abs(x_data[k]);
    if (absxk > scale) {
      float t;
      t = scale / absxk;
      y = y * t * t + 1.0F;
      scale = absxk;
    } else {
      float t;
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrtf(y);
}

/*
 * File trailer for xnrm2.c
 *
 * [EOF]
 */
