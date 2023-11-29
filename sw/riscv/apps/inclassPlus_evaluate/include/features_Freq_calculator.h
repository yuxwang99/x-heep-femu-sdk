/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * features_Freq_calculator.h
 *
 * Code generation for function 'features_Freq_calculator'
 *
 */

#ifndef FEATURES_FREQ_CALCULATOR_H
#define FEATURES_FREQ_CALCULATOR_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void features_Freq_calculator(const double tHRV_data[], const int tHRV_size[2],
    double HRV_data[], const int HRV_size[2], double idx5, double idx6, double
    idx7, double idx8, double Tot_pow_data[], int Tot_pow_size[2], double *nLF,
    double *nHF, double *LF_HF);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (features_Freq_calculator.h) */
