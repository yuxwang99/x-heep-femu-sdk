/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * my_Extract_features_Jep.h
 *
 * Code generation for function 'my_Extract_features_Jep'
 *
 */

#ifndef MY_EXTRACT_FEATURES_JEP_H
#define MY_EXTRACT_FEATURES_JEP_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void my_Extract_features_Jep(const double ECG_Sig[30720], const double
    Spo2_sig[30720], double Fs, int Nbr_RR, const int feature_selector_struct[17],
    emxArray_real_T *Features, boolean_T ignore_file, emxArray_real_T
    *Features_out);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (my_Extract_features_Jep.h) */
