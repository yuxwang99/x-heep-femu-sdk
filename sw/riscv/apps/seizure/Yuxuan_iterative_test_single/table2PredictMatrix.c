/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: table2PredictMatrix.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "table2PredictMatrix.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *Xout
 * Return Type  : void
 */
void b_table2PredictMatrix(const emxArray_real32_T *X, emxArray_real32_T *Xout)
{
  const float *X_data;
  float *Xout_data;
  int i;
  int loop_ub;
  X_data = X->data;
  i = Xout->size[0] * Xout->size[1];
  Xout->size[0] = X->size[0];
  Xout->size[1] = 11;
  emxEnsureCapacity_real32_T(Xout, i);
  Xout_data = Xout->data;
  loop_ub = X->size[0] * 11;
  for (i = 0; i < loop_ub; i++) {
    Xout_data[i] = X_data[i];
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *Xout
 * Return Type  : void
 */
void c_table2PredictMatrix(const emxArray_real32_T *X, emxArray_real32_T *Xout)
{
  const float *X_data;
  float *Xout_data;
  int i;
  int loop_ub;
  X_data = X->data;
  i = Xout->size[0] * Xout->size[1];
  Xout->size[0] = X->size[0];
  Xout->size[1] = 12;
  emxEnsureCapacity_real32_T(Xout, i);
  Xout_data = Xout->data;
  loop_ub = X->size[0] * 12;
  for (i = 0; i < loop_ub; i++) {
    Xout_data[i] = X_data[i];
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *Xout
 * Return Type  : void
 */
void d_table2PredictMatrix(const emxArray_real32_T *X, emxArray_real32_T *Xout)
{
  const float *X_data;
  float *Xout_data;
  int i;
  int loop_ub;
  X_data = X->data;
  i = Xout->size[0] * Xout->size[1];
  Xout->size[0] = X->size[0];
  Xout->size[1] = 13;
  emxEnsureCapacity_real32_T(Xout, i);
  Xout_data = Xout->data;
  loop_ub = X->size[0] * 13;
  for (i = 0; i < loop_ub; i++) {
    Xout_data[i] = X_data[i];
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *Xout
 * Return Type  : void
 */
void e_table2PredictMatrix(const emxArray_real32_T *X, emxArray_real32_T *Xout)
{
  const float *X_data;
  float *Xout_data;
  int i;
  int loop_ub;
  X_data = X->data;
  i = Xout->size[0] * Xout->size[1];
  Xout->size[0] = X->size[0];
  Xout->size[1] = 17;
  emxEnsureCapacity_real32_T(Xout, i);
  Xout_data = Xout->data;
  loop_ub = X->size[0] * 17;
  for (i = 0; i < loop_ub; i++) {
    Xout_data[i] = X_data[i];
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *Xout
 * Return Type  : void
 */
void table2PredictMatrix(const emxArray_real32_T *X, emxArray_real32_T *Xout)
{
  const float *X_data;
  float *Xout_data;
  int i;
  int loop_ub;
  X_data = X->data;
  i = Xout->size[0] * Xout->size[1];
  Xout->size[0] = X->size[0];
  Xout->size[1] = 4;
  emxEnsureCapacity_real32_T(Xout, i);
  Xout_data = Xout->data;
  loop_ub = X->size[0] << 2;
  for (i = 0; i < loop_ub; i++) {
    Xout_data[i] = X_data[i];
  }
}

/*
 * File trailer for table2PredictMatrix.c
 *
 * [EOF]
 */
