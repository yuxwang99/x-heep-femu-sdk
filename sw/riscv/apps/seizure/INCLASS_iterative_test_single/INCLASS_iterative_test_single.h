/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: INCLASS_iterative_test_single.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef INCLASS_ITERATIVE_TEST_SINGLE_H
#define INCLASS_ITERATIVE_TEST_SINGLE_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void INCLASS_iterative_test_single(const emxArray_real32_T *ECG_sig,
                                          const emxArray_real32_T *Spo2_sig,
                                          float conf_th, float thrshd,
                                          const signed char masks[85],
                                          float *final_result, float *ind);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for INCLASS_iterative_test_single.h
 *
 * [EOF]
 */
