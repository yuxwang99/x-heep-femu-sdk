/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fft.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "any.h"
#include "ismember.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_creal_T *y
 * Return Type  : void
 */
void fft(const emxArray_real_T *x, emxArray_creal_T *y)
{
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  creal_T *y_data;
  int nRows;
  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  emxInit_real_T(&sintabinv, 2);
  if ((x->size[0] == 0) || any(isMember(x->size[0]))) {
    int N2blue;
    nRows = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_creal_T(y, nRows);
    y_data = y->data;
    N2blue = x->size[0];
    for (nRows = 0; nRows < N2blue; nRows++) {
      y_data[nRows].re = 0.0;
      y_data[nRows].im = 0.0;
    }
  } else {
    int N2blue;
    boolean_T useRadix2;
    useRadix2 = c_FFTImplementationCallback_get(x->size[0]);
    N2blue = d_FFTImplementationCallback_get(x->size[0], useRadix2, &nRows);
    c_FFTImplementationCallback_gen(nRows, useRadix2, costab, sintab,
                                    sintabinv);
    if (useRadix2) {
      c_FFTImplementationCallback_r2b(x, x->size[0], costab, sintab, y);
    } else {
      c_FFTImplementationCallback_dob(x, N2blue, x->size[0], costab, sintab,
                                      sintabinv, y);
    }
  }
  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
}

/*
 * File trailer for fft.c
 *
 * [EOF]
 */
