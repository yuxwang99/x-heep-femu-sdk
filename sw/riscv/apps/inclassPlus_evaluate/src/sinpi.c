/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sinpi.c
 *
 * Code generation for function 'sinpi'
 *
 */

/* Include files */
#include "sinpi.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void sinpi(const emxArray_real_T *x, emxArray_real_T *y)
{
  double r;
  int k;
  int nx;
  boolean_T negateSinpi;
  nx = x->size[0];
  k = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real_T(y, k);
  for (k = 0; k < nx; k++) {
    r = x->data[k];
    if (x->data[k] < 0.0) {
      r = -x->data[k];
      negateSinpi = true;
    } else {
      negateSinpi = false;
    }

    if (r < 0.25) {
      r = sin(r * 3.1415926535897931);
    } else {
      r -= 2.0 * floor(r / 2.0);
      if (r < 0.25) {
        r = sin(r * 3.1415926535897931);
      } else if (r < 0.75) {
        r = 0.5 - r;
        r = cos(r * 3.1415926535897931);
      } else if (r < 1.25) {
        r = 1.0 - r;
        r = sin(r * 3.1415926535897931);
      } else if (r < 1.75) {
        r -= 1.5;
        r = -cos(r * 3.1415926535897931);
      } else {
        r -= 2.0;
        r = sin(r * 3.1415926535897931);
      }
    }

    if (negateSinpi) {
      r = -r;
    }

    y->data[k] = r;
  }
}

/* End of code generation (sinpi.c) */
