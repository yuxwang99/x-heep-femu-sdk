/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: varstd.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef VARSTD_H
#define VARSTD_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
float b_varstd(const float x_data[], int x_size);

float c_varstd(const emxArray_real32_T *x);

float varstd(const float x_data[], const int x_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for varstd.h
 *
 * [EOF]
 */
