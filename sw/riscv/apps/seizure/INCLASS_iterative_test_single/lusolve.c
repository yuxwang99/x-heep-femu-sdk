/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: lusolve.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "lusolve.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const float A_data[]
 *                float B
 * Return Type  : float
 */
float b_lusolve(const float A_data[], float B)
{
  return B / A_data[0];
}

/*
 * Arguments    : const float A_data[]
 *                const emxArray_real_T *B
 *                emxArray_real32_T *X
 * Return Type  : void
 */
void lusolve(const float A_data[], const emxArray_real_T *B,
             emxArray_real32_T *X)
{
  const double *B_data;
  float A;
  float *X_data;
  int i;
  int loop_ub;
  B_data = B->data;
  A = A_data[0];
  i = X->size[0];
  X->size[0] = B->size[0];
  emxEnsureCapacity_real32_T(X, i);
  X_data = X->data;
  loop_ub = B->size[0];
  for (i = 0; i < loop_ub; i++) {
    X_data[i] = (float)B_data[i] / A;
  }
}

/*
 * File trailer for lusolve.c
 *
 * [EOF]
 */
