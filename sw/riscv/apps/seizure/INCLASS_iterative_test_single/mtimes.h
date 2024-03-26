/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mtimes.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef MTIMES_H
#define MTIMES_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_mtimes(const emxArray_real32_T *A, const float B[4],
              emxArray_real32_T *C);

void mtimes(const emxArray_real32_T *A, const emxArray_real32_T *B,
            float C_data[], int C_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for mtimes.h
 *
 * [EOF]
 */
