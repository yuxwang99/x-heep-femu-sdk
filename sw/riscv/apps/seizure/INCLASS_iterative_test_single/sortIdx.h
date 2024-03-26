/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef SORTIDX_H
#define SORTIDX_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_sortIdx(const emxArray_real_T *x, emxArray_int32_T *idx);

void c_sortIdx(const emxArray_real32_T *x, emxArray_int32_T *idx);

void sortIdx(const emxArray_real32_T *x, emxArray_int32_T *idx);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for sortIdx.h
 *
 * [EOF]
 */
