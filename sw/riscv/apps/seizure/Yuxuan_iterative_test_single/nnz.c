/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: nnz.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "nnz.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *s
 * Return Type  : int
 */
int intnnz(const emxArray_real32_T *s)
{
  const float *s_data;
  int i;
  int k;
  int n;
  s_data = s->data;
  n = 0;
  i = s->size[0];
  for (k = 0; k < i; k++) {
    if (s_data[k] != 0.0F) {
      n++;
    }
  }
  return n;
}

/*
 * File trailer for nnz.c
 *
 * [EOF]
 */
