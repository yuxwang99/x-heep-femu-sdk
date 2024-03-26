/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Yuxuan_iterative_test_single.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef YUXUAN_ITERATIVE_TEST_SINGLE_H
#define YUXUAN_ITERATIVE_TEST_SINGLE_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Yuxuan_iterative_test_single(const emxArray_real32_T *ECG_sig,
                                         const emxArray_real32_T *Spo2_sig,
                                         float conf_th, float thrshd,
                                         const signed char masks[85],
                                         float *final_result, float *ind,
                                         float *runtime, float mask_runtime[5]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Yuxuan_iterative_test_single.h
 *
 * [EOF]
 */
