/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SortedBuffer.h
 *
 * Code generation for function 'SortedBuffer'
 *
 */

#ifndef SORTEDBUFFER_H
#define SORTEDBUFFER_H

/* Include files */
#include "profile_Yuxuan_iteration_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void SortedBuffer_insert(coder_internal_SortedBuffer *obj, double x);
  int SortedBuffer_locateElement(const double obj_buf[3], int obj_nbuf, double x);
  double SortedBuffer_median(const double obj_buf[3], int obj_nbuf, int
    obj_nnans);
  void SortedBuffer_remove(coder_internal_SortedBuffer *obj, double x);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (SortedBuffer.h) */
