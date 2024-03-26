/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: isnan.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef ISNAN_H
#define ISNAN_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
boolean_T b_isnan(double x);

boolean_T c_isnan(float x);

void d_isnan(const emxArray_real32_T *x, emxArray_boolean_T *b);

void e_isnan(const emxArray_real32_T *x, emxArray_boolean_T *b);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for isnan.h
 *
 * [EOF]
 */
