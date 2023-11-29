/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Lorenz_plot.h
 *
 * Code generation for function 'Lorenz_plot'
 *
 */

#ifndef LORENZ_PLOT_H
#define LORENZ_PLOT_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void Lorenz_plot(const double R_R_interval_data[], const int
                   R_R_interval_size[2], int Wind_Siz, emxArray_real_T *CSI,
                   emxArray_real_T *Mod_CSI, emxArray_real_T *CVI,
                   emxArray_real_T *HR_diff);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (Lorenz_plot.h) */
