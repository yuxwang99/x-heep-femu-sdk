/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "filter.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void b_filter(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  static const signed char iv[33] = {-1, 0, 0, 0, 0, 0,  0,   0, 0, 0, 0,
                                     0,  0, 0, 0, 0, 32, -32, 0, 0, 0, 0,
                                     0,  0, 0, 0, 0, 0,  0,   0, 0, 0, 1};
  float b[33];
  const float *x_data;
  float *y_data;
  int j;
  int k;
  int naxpy;
  int nx;
  int y_tmp;
  x_data = x->data;
  for (k = 0; k < 33; k++) {
    b[k] = (float)iv[k] / 32.0F;
  }
  nx = x->size[0] - 1;
  y_tmp = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real32_T(y, y_tmp);
  y_data = y->data;
  naxpy = x->size[0];
  for (y_tmp = 0; y_tmp < naxpy; y_tmp++) {
    y_data[y_tmp] = 0.0F;
  }
  for (k = 0; k <= nx; k++) {
    float as;
    int a_tmp;
    a_tmp = nx - k;
    naxpy = a_tmp + 1;
    if (naxpy > 33) {
      naxpy = 33;
    }
    for (j = 0; j < naxpy; j++) {
      y_tmp = k + j;
      y_data[y_tmp] += x_data[k] * b[j];
    }
    if (a_tmp <= 1) {
      naxpy = a_tmp;
    } else {
      naxpy = 1;
    }
    as = -y_data[k];
    for (j = 0; j < naxpy; j++) {
      y_data[k + 1] -= as;
    }
  }
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void c_filter(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  static const float fv[5] = {0.2F, 0.1F, 0.0F, -0.1F, -0.4F};
  const float *x_data;
  float *y_data;
  int i;
  int j;
  int k;
  int nx;
  int nx_m_nb;
  x_data = x->data;
  nx = x->size[0];
  i = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real32_T(y, i);
  y_data = y->data;
  nx_m_nb = x->size[0];
  for (i = 0; i < nx_m_nb; i++) {
    y_data[i] = 0.0F;
  }
  if (x->size[0] >= 10) {
    for (k = 0; k < 5; k++) {
      nx_m_nb = k + 1;
      for (j = nx_m_nb; j <= nx; j++) {
        y_data[j - 1] += fv[k] * x_data[(j - k) - 1];
      }
    }
  } else {
    int naxpy;
    int y_tmp;
    if (x->size[0] > 5) {
      nx_m_nb = x->size[0] - 6;
    } else {
      nx_m_nb = -1;
    }
    for (k = 0; k <= nx_m_nb; k++) {
      for (j = 0; j < 5; j++) {
        y_tmp = k + j;
        y_data[y_tmp] += x_data[k] * fv[j];
      }
    }
    naxpy = x->size[0] - nx_m_nb;
    i = nx_m_nb + 2;
    for (k = i; k <= nx; k++) {
      for (j = 0; j <= naxpy - 2; j++) {
        y_tmp = (k + j) - 1;
        y_data[y_tmp] += x_data[k - 1] * fv[j];
      }
      naxpy--;
    }
  }
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void d_filter(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  const float *x_data;
  float *y_data;
  int i;
  int j;
  int k;
  int nx;
  int nx_m_nb;
  x_data = x->data;
  nx = x->size[0];
  i = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real32_T(y, i);
  y_data = y->data;
  nx_m_nb = x->size[0];
  for (i = 0; i < nx_m_nb; i++) {
    y_data[i] = 0.0F;
  }
  if (x->size[0] >= 76) {
    for (k = 0; k < 38; k++) {
      nx_m_nb = k + 1;
      for (j = nx_m_nb; j <= nx; j++) {
        y_data[j - 1] += 0.0263157897F * x_data[(j - k) - 1];
      }
    }
  } else {
    int naxpy;
    int y_tmp;
    if (x->size[0] > 38) {
      nx_m_nb = x->size[0] - 39;
    } else {
      nx_m_nb = -1;
    }
    for (k = 0; k <= nx_m_nb; k++) {
      for (j = 0; j < 38; j++) {
        y_tmp = k + j;
        y_data[y_tmp] += x_data[k] * 0.0263157897F;
      }
    }
    naxpy = x->size[0] - nx_m_nb;
    i = nx_m_nb + 2;
    for (k = i; k <= nx; k++) {
      for (j = 0; j <= naxpy - 2; j++) {
        y_tmp = (k + j) - 1;
        y_data[y_tmp] += x_data[k - 1] * 0.0263157897F;
      }
      naxpy--;
    }
  }
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void filter(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  static const float fv[13] = {0.027777778F,  0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                               -0.055555556F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                               0.027777778F};
  static const signed char iv[3] = {1, -2, 1};
  const float *x_data;
  float *y_data;
  int j;
  int k;
  int naxpy;
  int nx;
  int y_tmp;
  x_data = x->data;
  nx = x->size[0] - 1;
  y_tmp = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real32_T(y, y_tmp);
  y_data = y->data;
  naxpy = x->size[0];
  for (y_tmp = 0; y_tmp < naxpy; y_tmp++) {
    y_data[y_tmp] = 0.0F;
  }
  for (k = 0; k <= nx; k++) {
    float as;
    int a_tmp;
    a_tmp = nx - k;
    naxpy = a_tmp + 1;
    if (naxpy > 13) {
      naxpy = 13;
    }
    for (j = 0; j < naxpy; j++) {
      y_tmp = k + j;
      y_data[y_tmp] += x_data[k] * fv[j];
    }
    if (a_tmp <= 2) {
      naxpy = a_tmp;
    } else {
      naxpy = 2;
    }
    as = -y_data[k];
    for (j = 0; j < naxpy; j++) {
      y_tmp = (k + j) + 1;
      y_data[y_tmp] += as * (float)iv[j + 1];
    }
  }
}

/*
 * File trailer for filter.c
 *
 * [EOF]
 */
