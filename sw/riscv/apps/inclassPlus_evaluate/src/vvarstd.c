/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vvarstd.c
 *
 * Code generation for function 'vvarstd'
 *
 */

/* Include files */
#include "vvarstd.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
double vvarstd(const emxArray_real_T *v, int n)
{
  double d;
  double s;
  double scale;
  double t;
  double xbar;
  int k;
  if (n == 0) {
    s = rtNaN;
  } else if (n == 1) {
    if ((!rtIsInf(v->data[0])) && (!rtIsNaN(v->data[0]))) {
      s = 0.0;
    } else {
      s = rtNaN;
    }
  } else {
    if (v->size[0] == 0) {
      xbar = 0.0;
    } else {
      xbar = v->data[0];
      for (k = 2; k <= n; k++) {
        xbar += v->data[k - 1];
      }
    }

    xbar /= (double)n;
    s = 0.0;
    scale = 3.3121686421112381E-170;
    for (k = 0; k < n; k++) {
      d = fabs(v->data[k] - xbar);
      if (d > scale) {
        t = scale / d;
        s = s * t * t + 1.0;
        scale = d;
      } else {
        t = d / scale;
        s += t * t;
      }
    }

    s = scale * sqrt(s);
    s /= sqrt(n - 1);
  }

  return s;
}

/* End of code generation (vvarstd.c) */
