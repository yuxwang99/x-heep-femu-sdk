/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortLE.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef SORTLE_H
#define SORTLE_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
boolean_T b_sortLE(const emxArray_real32_T *v, int idx1, int idx2);

boolean_T c_sortLE(const emxArray_real_T *v, int idx1, int idx2);

boolean_T sortLE(const emxArray_real32_T *v, int idx1, int idx2);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for sortLE.h
 *
 * [EOF]
 */
