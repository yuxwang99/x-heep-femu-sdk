/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.h
 *
 * Code generation for function 'mean'
 *
 */

#ifndef MEAN_H
#define MEAN_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  double b_mean(const emxArray_real_T *x);
  double c_mean(const double x_data[], const int x_size[2]);
  double mean(const double x[30720]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (mean.h) */
