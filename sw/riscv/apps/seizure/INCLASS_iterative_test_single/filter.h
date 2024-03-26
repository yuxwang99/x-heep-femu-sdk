/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef FILTER_H
#define FILTER_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_filter(const emxArray_real32_T *x, emxArray_real32_T *y);

void c_filter(const emxArray_real32_T *x, emxArray_real32_T *y);

void d_filter(const emxArray_real32_T *x, emxArray_real32_T *y);

void filter(const emxArray_real32_T *x, emxArray_real32_T *y);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for filter.h
 *
 * [EOF]
 */
