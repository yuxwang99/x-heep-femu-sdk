/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_INCLASS_iterative_test_single_api.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef _CODER_INCLASS_ITERATIVE_TEST_SINGLE_API_H
#define _CODER_INCLASS_ITERATIVE_TEST_SINGLE_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T
struct emxArray_real32_T {
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real32_T */
#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T
typedef struct emxArray_real32_T emxArray_real32_T;
#endif /* typedef_emxArray_real32_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void INCLASS_iterative_test_single(
    emxArray_real32_T *ECG_sig, emxArray_real32_T *Spo2_sig, real32_T conf_th,
    real32_T thrshd, int8_T masks[85], real32_T *final_result, real32_T *ind,
    real32_T *runtime, real32_T *saveup_time, real32_T mask_runtime[5]);

void INCLASS_iterative_test_single_atexit(void);

void INCLASS_iterative_test_single_initialize(void);

void INCLASS_iterative_test_single_terminate(void);

void INCLASS_iterative_test_single_xil_shutdown(void);

void INCLASS_iterative_test_single_xil_terminate(void);

void c_INCLASS_iterative_test_single(const mxArray *const prhs[5], int32_T nlhs,
                                     const mxArray *plhs[5]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_INCLASS_iterative_test_single_api.h
 *
 * [EOF]
 */
