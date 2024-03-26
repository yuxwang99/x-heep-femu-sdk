/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mrdivide_helper.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef MRDIVIDE_HELPER_H
#define MRDIVIDE_HELPER_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
float b_mrdiv(float A, const float B_data[]);

float c_mrdiv(const float B_data[]);

void mrdiv(const emxArray_real_T *A, const float B_data[], const int B_size[2],
           emxArray_real32_T *Y);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for mrdivide_helper.h
 *
 * [EOF]
 */
