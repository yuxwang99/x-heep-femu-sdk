/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: any.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef ANY_H
#define ANY_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
boolean_T any(boolean_T x);

boolean_T b_any(const double x_data[], const int x_size[2]);

boolean_T c_any(const emxArray_boolean_T *x);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for any.h
 *
 * [EOF]
 */
