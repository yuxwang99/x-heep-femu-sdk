/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: movfunDispatch.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef MOVFUNDISPATCH_H
#define MOVFUNDISPATCH_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_movfunDispatch(const emxArray_real32_T *x, float k,
                      emxArray_real32_T *y);

void movfunDispatch(const float x[400], float y[400]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for movfunDispatch.h
 *
 * [EOF]
 */
