/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SortedBuffer.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef SORTEDBUFFER_H
#define SORTEDBUFFER_H

/* Include Files */
#include "INCLASS_iterative_test_single_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
int SortedBuffer_SortedBuffer(float obj_buf[3], boolean_T *obj_includenans,
                              int *obj_nnans);

void SortedBuffer_insert(coder_internal_SortedBuffer *obj, float x);

float SortedBuffer_median(const float obj_buf[3], int obj_nbuf, int obj_nnans);

void SortedBuffer_remove(coder_internal_SortedBuffer *obj, float x);

void SortedBuffer_replace(coder_internal_SortedBuffer *obj, float xold,
                          float xnew);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for SortedBuffer.h
 *
 * [EOF]
 */
