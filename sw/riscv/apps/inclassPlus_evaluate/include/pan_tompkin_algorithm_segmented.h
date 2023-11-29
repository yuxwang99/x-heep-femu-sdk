/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pan_tompkin_algorithm_segmented.h
 *
 * Code generation for function 'pan_tompkin_algorithm_segmented'
 *
 */

#ifndef PAN_TOMPKIN_ALGORITHM_SEGMENTED_H
#define PAN_TOMPKIN_ALGORITHM_SEGMENTED_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void pan_tompkin_algorithm_segmented(double sig_short[30720], double fs,
    emxArray_real_T *qrs_amp_raw, emxArray_real_T *Rloc);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (pan_tompkin_algorithm_segmented.h) */
