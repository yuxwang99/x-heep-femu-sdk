/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * denoise_rwd.h
 *
 * Code generation for function 'denoise_rwd'
 *
 */

#ifndef DENOISE_RWD_H
#define DENOISE_RWD_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void denoise_rwd(const double ECG[30720], double BWwindow, double filteredECG
                   [30720]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (denoise_rwd.h) */
