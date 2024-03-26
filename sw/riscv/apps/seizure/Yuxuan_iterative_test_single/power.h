/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: power.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef POWER_H
#define POWER_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_power(const emxArray_real_T *a, emxArray_real_T *y);

void c_power(const float a_data[], const int a_size[2], float y_data[],
             int y_size[2]);

void power(const emxArray_real32_T *a, emxArray_real32_T *y);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for power.h
 *
 * [EOF]
 */
