/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: unique.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef UNIQUE_H
#define UNIQUE_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_unique_vector(const emxArray_real_T *a, emxArray_real_T *b);

void c_unique_vector(const emxArray_real32_T *a, emxArray_real32_T *b,
                     emxArray_int32_T *ndx);

void unique_vector(const emxArray_real32_T *a, emxArray_real32_T *b);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for unique.h
 *
 * [EOF]
 */
