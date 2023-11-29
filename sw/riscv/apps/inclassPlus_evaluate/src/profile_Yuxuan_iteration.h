/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * profile_Yuxuan_iteration.h
 *
 * Code generation for function 'profile_Yuxuan_iteration'
 *
 */

#ifndef PROFILE_YUXUAN_ITERATION_H
#define PROFILE_YUXUAN_ITERATION_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  extern void profile_Yuxuan_iteration(const double ECG_Seiz_Window[2764800],
    const double Spo2_Seiz_Window[2764800], const double ECG_Gray_Window[2764800],
    const double Spo2_Gray_Window[2764800], const double norm_coef1[2], const
    double norm_coef2[3], const double norm_coef3[5], const double norm_coef4[13],
    const double norm_coef5[17], double wind_len, const double masks[85], double
    profile_times, const cell_0 *File_info, double Fs, double Nbr_RR, double
    conf_seiz, const boolean_T select_ind[90], double pred_label_data[], int
    pred_label_size[2], double true_label_data[], int true_label_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (profile_Yuxuan_iteration.h) */
