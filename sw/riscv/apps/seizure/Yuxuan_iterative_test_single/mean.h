/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mean.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef MEAN_H
#define MEAN_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
float b_mean(const float x[513]);

float c_mean(const float x[8]);

float d_mean(const float x_data[], const int x_size[2]);

float mean(const emxArray_real32_T *x);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for mean.h
 *
 * [EOF]
 */
