/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: minOrMax.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef MINORMAX_H
#define MINORMAX_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
float b_maximum(const float x[513]);

float b_minimum(const float x_data[], const int x_size[2]);

float c_maximum(const emxArray_real32_T *x, int *idx);

float c_minimum(const float x[2]);

void d_maximum(const emxArray_real32_T *x, float ex_data[], int ex_size[2]);

float d_minimum(const float x[2], int *idx);

float e_maximum(const float x[2]);

float f_maximum(const float x[2], int *idx);

float maximum(const emxArray_real32_T *x);

float maximum2(float x, float y);

float minimum(const emxArray_real32_T *x);

float minimum2(float x, float y);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for minOrMax.h
 *
 * [EOF]
 */
