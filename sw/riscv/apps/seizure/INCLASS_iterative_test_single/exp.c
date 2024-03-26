/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: exp.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "exp.h"
#include "isinf.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : creal_T *x
 * Return Type  : void
 */
void b_exp(creal_T *x)
{
  if (x->re == 0.0) {
    double d;
    d = x->im;
    x->re = cos(d);
    x->im = sin(d);
  } else if (x->im == 0.0) {
    x->re = exp(x->re);
    x->im = 0.0;
  } else if (c_isinf(x->im) && c_isinf(x->re) && (x->re < 0.0)) {
    x->re = 0.0;
    x->im = 0.0;
  } else {
    double d;
    double r;
    r = exp(x->re / 2.0);
    d = x->im;
    x->re = r * (r * cos(d));
    x->im = r * (r * sin(d));
  }
}

/*
 * File trailer for exp.c
 *
 * [EOF]
 */
