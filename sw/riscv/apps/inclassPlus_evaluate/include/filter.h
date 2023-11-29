/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#ifndef FILTER_H
#define FILTER_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_filter(double b[33], const double x[30720], double y[30720]);
  void c_filter(const emxArray_real_T *b, const double x[30720], double y[30720]);
  void filter(const double b[13], const double a[3], const double x[30720],
              double y[30720]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (filter.h) */
