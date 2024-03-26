/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: isinf.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef ISINF_H
#define ISINF_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
boolean_T b_isinf(float x);

boolean_T c_isinf(double x);

void d_isinf(const float x_data[], const int x_size[2], boolean_T b_data[],
             int b_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for isinf.h
 *
 * [EOF]
 */
