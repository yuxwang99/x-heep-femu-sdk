/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mtimes1.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef MTIMES1_H
#define MTIMES1_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_mtimes(const emxArray_real32_T *A, const emxArray_real32_T *B,
              float C_data[], int C_size[2]);

void d_mtimes(const emxArray_real32_T *A, const float B[4],
              emxArray_real32_T *C);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for mtimes1.h
 *
 * [EOF]
 */
