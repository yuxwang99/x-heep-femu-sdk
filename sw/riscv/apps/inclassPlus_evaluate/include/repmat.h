/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.h
 *
 * Code generation for function 'repmat'
 *
 */

#ifndef REPMAT_H
#define REPMAT_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_repmat(const double a[3], double varargin_1, double b_data[], int
                b_size[2]);
  void c_repmat(const double a[5], double varargin_1, double b_data[], int
                b_size[2]);
  void d_repmat(const double a[13], double varargin_1, double b_data[], int
                b_size[2]);
  void e_repmat(const double a[17], double varargin_1, double b_data[], int
                b_size[2]);
  void repmat(const double a[2], double varargin_1, double b_data[], int b_size
              [2]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (repmat.h) */
