/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Yuxuan_iterative_test.h
 *
 * Code generation for function 'Yuxuan_iterative_test'
 *
 */

#ifndef YUXUAN_ITERATIVE_TEST_H
#define YUXUAN_ITERATIVE_TEST_H

/* Include files */
#include "profile_Yuxuan_iteration_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void Yuxuan_iterative_test(const double ECG_sig[30720], const double Spo2_sig
    [30720], double Fs, double Nbr_RR, const boolean_T classifier1_IsCached[30],
    const double classifier1_ClassNames[2], const double classifier1_Prior[2],
    const boolean_T classifier2_IsCached[30], const double
    classifier2_ClassNames[2], const double classifier2_Prior[2], const
    c_classreg_learning_classif_Com *classifier3, const
    c_classreg_learning_classif_Com *classifier4, const
    c_classreg_learning_classif_Com *classifier5, const double norm_coef1[2],
    const double norm_coef2[3], const double norm_coef3[5], const double
    norm_coef4[13], const double norm_coef5[17], double thrshd, double conf_th,
    const double masks[85], double pred_mask[5], double pred_conf[5], double
    mask_apply_data[], int mask_apply_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (Yuxuan_iterative_test.h) */
