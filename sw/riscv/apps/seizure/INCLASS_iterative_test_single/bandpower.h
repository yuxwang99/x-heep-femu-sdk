/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: bandpower.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef BANDPOWER_H
#define BANDPOWER_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_bandpower(const emxArray_real32_T *varargin_1,
                 const emxArray_real32_T *varargin_2, const float varargin_3[2],
                 float pwr_data[], int pwr_size[2]);

void bandpower(const emxArray_real32_T *varargin_1,
               const emxArray_real32_T *varargin_2, float pwr_data[],
               int pwr_size[2]);

void c_bandpower(const emxArray_real32_T *varargin_1,
                 const emxArray_real32_T *varargin_2, const float varargin_3[2],
                 float pwr_data[], int pwr_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for bandpower.h
 *
 * [EOF]
 */
