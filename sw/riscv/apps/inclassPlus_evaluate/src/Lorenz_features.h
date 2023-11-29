/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Lorenz_features.h
 *
 * Code generation for function 'Lorenz_features'
 *
 */

#ifndef LORENZ_FEATURES_H
#define LORENZ_FEATURES_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void Lorenz_features(const double RR_Interv_filtr[400], const double
                       RR_Interv[400], int i, int x0, int Nbr_RR, const
                       emxArray_real_T *tHRV, double idx9, double idx10, double
                       idx11, double idx12, double idx13, double idx14, double
                       idx15, emxArray_real_T *CSI_filt, emxArray_real_T
                       *Mod_CSI_filt, emxArray_real_T *CSI, emxArray_real_T
                       *Mod_CSI, emxArray_real_T *HR_diff_orig, double *Slope);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (Lorenz_features.h) */
