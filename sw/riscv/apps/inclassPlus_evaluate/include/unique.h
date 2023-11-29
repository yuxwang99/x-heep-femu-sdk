/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unique.h
 *
 * Code generation for function 'unique'
 *
 */

#ifndef UNIQUE_H
#define UNIQUE_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_unique_vector(const emxArray_real_T *a, emxArray_real_T *b);
  void c_unique_vector(const emxArray_real_T *a, emxArray_real_T *b,
                       emxArray_int32_T *ndx);
  void unique_vector(const emxArray_real_T *a, emxArray_real_T *b);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (unique.h) */
