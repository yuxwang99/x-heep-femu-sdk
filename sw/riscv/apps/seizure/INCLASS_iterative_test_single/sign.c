/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sign.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "sign.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include "sign1.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
void b_sign(emxArray_real_T *x)
{
  double *x_data;
  int k;
  int nx;
  x_data = x->data;
  nx = x->size[0];
  for (k = 0; k < nx; k++) {
    c_sign(&x_data[k]);
  }
}

/*
 * File trailer for sign.c
 *
 * [EOF]
 */
