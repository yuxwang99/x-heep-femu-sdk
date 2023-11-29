/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.c
 *
 * Code generation for function 'filter'
 *
 */

/* Include files */
#include "filter.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_filter(double b[33], const double x[30720], double y[30720])
{
  double as;
  int j;
  int k;
  int naxpy;
  int y_tmp;
  for (k = 0; k < 33; k++) {
    b[k] /= 32.0;
  }

  memset(&y[0], 0, 30720U * sizeof(double));
  for (k = 0; k < 30720; k++) {
    if (30720 - k < 33) {
      naxpy = 30719 - k;
    } else {
      naxpy = 32;
    }

    for (j = 0; j <= naxpy; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b[j];
    }

    if (30719 - k < 1) {
      naxpy = -1;
    } else {
      naxpy = 0;
    }

    as = -y[k];
    for (j = 0; j <= naxpy; j++) {
      y[k + 1] += -as;
    }
  }
}

void c_filter(const emxArray_real_T *b, const double x[30720], double y[30720])
{
  int j;
  int k;
  int nb;
  int nx_m_nb;
  int y_tmp;
  nb = b->size[1] - 1;
  memset(&y[0], 0, 30720U * sizeof(double));
  if (30720 >= (b->size[1] << 1)) {
    for (k = 0; k <= nb; k++) {
      nx_m_nb = k + 1;
      for (j = nx_m_nb; j < 30721; j++) {
        y[j - 1] += b->data[k] * x[(j - k) - 1];
      }
    }
  } else {
    if (30720 > b->size[1]) {
      nx_m_nb = 30720 - b->size[1];
    } else {
      nx_m_nb = 0;
    }

    for (k = 0; k < nx_m_nb; k++) {
      for (j = 0; j <= nb; j++) {
        y_tmp = k + j;
        y[y_tmp] += x[k] * b->data[j];
      }
    }

    nb = 30719 - nx_m_nb;
    nx_m_nb++;
    for (k = nx_m_nb; k < 30721; k++) {
      for (j = 0; j <= nb; j++) {
        y_tmp = (k + j) - 1;
        y[y_tmp] += x[k - 1] * b->data[j];
      }

      nb--;
    }
  }
}

void filter(const double b[13], const double a[3], const double x[30720], double
            y[30720])
{
  double as;
  int j;
  int k;
  int naxpy;
  int y_tmp;
  memset(&y[0], 0, 30720U * sizeof(double));
  for (k = 0; k < 30720; k++) {
    if (30720 - k < 13) {
      naxpy = 30719 - k;
    } else {
      naxpy = 12;
    }

    for (j = 0; j <= naxpy; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b[j];
    }

    if (30719 - k < 2) {
      naxpy = 30718 - k;
    } else {
      naxpy = 1;
    }

    as = -y[k];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += as * a[j + 1];
    }
  }
}

/* End of code generation (filter.c) */
