/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: lusolve.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef LUSOLVE_H
#define LUSOLVE_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
float b_lusolve(const float A_data[], float B);

void lusolve(const float A_data[], const emxArray_real_T *B,
             emxArray_real32_T *X);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for lusolve.h
 *
 * [EOF]
 */
