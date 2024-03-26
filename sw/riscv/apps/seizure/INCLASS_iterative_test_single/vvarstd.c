/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: vvarstd.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "vvarstd.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "abs.h"
#include "combineVectorElements.h"
#include "isfinite.h"
#include "rt_nonfinite.h"
#include "sqrt1.h"
#include "xnrm2.h"

/* Function Definitions */
/*
 * Arguments    : const float v_data[]
 *                int v_size
 *                int n
 * Return Type  : float
 */
float b_vvarstd(const float v_data[], int v_size, int n)
{
  emxArray_real32_T b_v_data;
  float s;
  int k;
  if (n == 1) {
    if (b_isfinite(v_data[0])) {
      s = 0.0F;
    } else {
      s = rtNaNF;
    }
  } else {
    float xbar;
    int i;
    b_v_data.data = (float *)&v_data[0];
    b_v_data.size = &v_size;
    b_v_data.allocatedSize = -1;
    b_v_data.numDimensions = 1;
    b_v_data.canFreeData = false;
    xbar = f_combineVectorElements(&b_v_data, n) / (float)n;
    s = 0.0F;
    i = (unsigned short)n;
    for (k = 0; k < i; k++) {
      float t;
      t = v_data[k] - xbar;
      s += t * t;
    }
    s /= (float)(n - 1);
  }
  return s;
}

/*
 * Arguments    : const emxArray_real32_T *v
 *                int n
 * Return Type  : float
 */
float vvarstd(const emxArray_real32_T *v, int n)
{
  emxArray_real32_T *absdiff;
  const float *v_data;
  float s;
  float xbar;
  float *absdiff_data;
  int k;
  v_data = v->data;
  if (n == 0) {
    s = rtNaNF;
  } else if (n == 1) {
    if (b_isfinite(v_data[0])) {
      s = 0.0F;
    } else {
      s = rtNaNF;
    }
  } else {
    xbar = f_combineVectorElements(v, n) / (float)n;
    emxInit_real32_T(&absdiff, 1);
    k = absdiff->size[0];
    absdiff->size[0] = v->size[0];
    emxEnsureCapacity_real32_T(absdiff, k);
    absdiff_data = absdiff->data;
    for (k = 0; k < n; k++) {
      absdiff_data[k] = g_abs(v_data[k] - xbar);
    }
    xbar = (float)(n - 1);
    c_sqrt(&xbar);
    s = xnrm2(n, absdiff) / xbar;
    emxFree_real32_T(&absdiff);
  }
  return s;
}

/*
 * File trailer for vvarstd.c
 *
 * [EOF]
 */
