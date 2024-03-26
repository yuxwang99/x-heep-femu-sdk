/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mtimes.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "mtimes.h"
#include "INCLASS_iterative_test_single_types.h"
#include "mtimes1.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *A
 *                const float B[4]
 *                emxArray_real32_T *C
 * Return Type  : void
 */
void c_mtimes(const emxArray_real32_T *A, const float B[4],
              emxArray_real32_T *C)
{
  d_mtimes(A, B, C);
}

/*
 * Arguments    : const emxArray_real32_T *A
 *                const emxArray_real32_T *B
 *                float C_data[]
 *                int C_size[2]
 * Return Type  : void
 */
void mtimes(const emxArray_real32_T *A, const emxArray_real32_T *B,
            float C_data[], int C_size[2])
{
  b_mtimes(A, B, C_data, C_size);
}

/*
 * File trailer for mtimes.c
 *
 * [EOF]
 */
