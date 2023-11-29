/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cospi.c
 *
 * Code generation for function 'cospi'
 *
 */

/* Include files */
#include "cospi.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void cospi(const emxArray_real_T *x, emxArray_real_T *y)
{
  double r;
  int k;
  int nx;
  nx = x->size[0];
  k = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real_T(y, k);
  for (k = 0; k < nx; k++) {
    r = x->data[k];
    if (x->data[k] < 0.0) {
      r = -x->data[k];
    }

    if (r < 0.25) {
      y->data[k] = cos(r * 3.1415926535897931);
    } else {
      r -= 2.0 * floor(r / 2.0);
      if (r < 0.25) {
        y->data[k] = cos(r * 3.1415926535897931);
      } else if (r < 0.75) {
        r = 0.5 - r;
        y->data[k] = sin(r * 3.1415926535897931);
      } else if (r < 1.25) {
        r = 1.0 - r;
        y->data[k] = -cos(r * 3.1415926535897931);
      } else if (r < 1.75) {
        r -= 1.5;
        y->data[k] = sin(r * 3.1415926535897931);
      } else {
        r -= 2.0;
        y->data[k] = cos(r * 3.1415926535897931);
      }
    }
  }
}

/* End of code generation (cospi.c) */
