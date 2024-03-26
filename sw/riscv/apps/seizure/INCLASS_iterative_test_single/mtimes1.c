/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mtimes1.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "mtimes1.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *A
 *                const emxArray_real32_T *B
 *                float C_data[]
 *                int C_size[2]
 * Return Type  : void
 */
void b_mtimes(const emxArray_real32_T *A, const emxArray_real32_T *B,
              float C_data[], int C_size[2])
{
  const float *A_data;
  const float *B_data;
  int inner;
  int j;
  int k;
  int nc;
  B_data = B->data;
  A_data = A->data;
  inner = A->size[0];
  nc = B->size[1];
  C_size[0] = 1;
  C_size[1] = B->size[1];
  for (j = 0; j < nc; j++) {
    C_data[0] = 0.0F;
    for (k = 0; k < inner; k++) {
      C_data[0] += A_data[k] * B_data[k];
    }
  }
}

/*
 * Arguments    : const emxArray_real32_T *A
 *                const float B[4]
 *                emxArray_real32_T *C
 * Return Type  : void
 */
void d_mtimes(const emxArray_real32_T *A, const float B[4],
              emxArray_real32_T *C)
{
  const float *A_data;
  float *C_data;
  int coffset;
  int i;
  int j;
  int m;
  A_data = A->data;
  m = A->size[0];
  coffset = C->size[0] * C->size[1];
  C->size[0] = A->size[0];
  C->size[1] = 2;
  emxEnsureCapacity_real32_T(C, coffset);
  C_data = C->data;
  for (j = 0; j < 2; j++) {
    int boffset;
    coffset = j * m;
    boffset = j << 1;
    for (i = 0; i < m; i++) {
      C_data[coffset + i] =
          A_data[i] * B[boffset] + A_data[A->size[0] + i] * B[boffset + 1];
    }
  }
}

/*
 * File trailer for mtimes1.c
 *
 * [EOF]
 */
