/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.h
 *
 * Code generation for function 'find'
 *
 */

#ifndef FIND_H
#define FIND_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_eml_find(const emxArray_boolean_T *x, int i_data[], int i_size[1]);
  void c_eml_find(const emxArray_boolean_T *x, int i_data[], int i_size[1]);
  void d_eml_find(const boolean_T x_data[], const int x_size[2], int i_data[],
                  int i_size[2]);
  void e_eml_find(const boolean_T x[5], int i_data[], int i_size[2]);
  void eml_find(const emxArray_boolean_T *x, emxArray_int32_T *i);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (find.h) */
