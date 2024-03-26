/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: blockedSummation.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef BLOCKEDSUMMATION_H
#define BLOCKEDSUMMATION_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
float b_blockedSummation(const emxArray_real32_T *x, int vlen);

double blockedSummation(const signed char x[17]);

float c_blockedSummation(const float x[513]);

float d_blockedSummation(const float x[8]);

float e_blockedSummation(const float x_data[], const int x_size[2], int vlen);

float f_blockedSummation(const emxArray_real32_T *x, int vlen, int vstart);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for blockedSummation.h
 *
 * [EOF]
 */
