/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: find.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef FIND_H
#define FIND_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
int b_eml_find(const emxArray_boolean_T *x, int i_data[]);

int c_eml_find(const emxArray_boolean_T *x, int i_data[]);

void d_eml_find(const boolean_T x_data[], const int x_size[2], int i_data[],
                int i_size[2]);

void eml_find(const emxArray_boolean_T *x, emxArray_int32_T *i);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for find.h
 *
 * [EOF]
 */
