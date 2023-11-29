/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Lorenz_features.c
 *
 * Code generation for function 'Lorenz_features'
 *
 */

/* Include files */
#include "Lorenz_features.h"
#include "Lorenz_plot.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void Lorenz_features(const double RR_Interv_filtr[400], const double RR_Interv
                     [400], int i, int x0, int Nbr_RR, const emxArray_real_T
                     *tHRV, double idx9, double idx10, double idx11, double
                     idx12, double idx13, double idx14, double idx15,
                     emxArray_real_T *CSI_filt, emxArray_real_T *Mod_CSI_filt,
                     emxArray_real_T *CSI, emxArray_real_T *Mod_CSI,
                     emxArray_real_T *HR_diff_orig, double *Slope)
{
  static double RR_Interv_filtr_data[400];
  static double x_data[400];
  emxArray_real_T *unusedU0;
  emxArray_real_T *unusedU1;
  double mean_X;
  double mean_y;
  double y;
  int RR_Interv_filtr_size[2];
  int b_i;
  int i1;
  int k;
  int qY;
  int vlen;

  /*  function [CSI_filt,Mod_CSI_filt, CSI, Mod_CSI, HR_diff_orig, Slope] = Lorenz_features(RR_Interv_filtr, i, x0, Nbr_RR, tHRV, feature_selector_struct, Features, idx_time, idx_freq, idx_diff, idx9, idx10, idx11, idx12, idx13, idx14, idx15) */
  /*  %         [CSI_filt,Mod_CSI_filt,~,  ~]            = Lorenz_plot(RR_Interv_filtr(i-x0+1:i),(Nbr_RR)); */
  /*      [CSI_filt,Mod_CSI_filt] = Lorenz_plot_f10f11(RR_Interv_filtr, i, x0, Nbr_RR); */
  /*  %         [CSI,     Mod_CSI,     ~,HR_diff_orig] = Lorenz_plot(RR_Interv(i-x0+1:i),      (Nbr_RR)); */
  /*      [CSI, Mod_CSI, HR_diff_orig] = Lorenz_plot_f9f12f13f14f15(RR_Interv_filtr, i, x0, Nbr_RR); */
  /*      Slope=abs(my_slope(tHRV(i-x0+1:i),RR_Interv_filtr(i-x0+1:i))); */
  /*   */
  /*      if feature_selector_struct.mask(4)  */
  /*          Features(i-x0+1,10-idx_time-idx_freq-idx_diff) = Feature10(CSI_filt, Slope); %f10 */
  /*          Features(i-x0+1,11-idx_time-idx_freq-idx_diff) = Feature11(Mod_CSI_filt,Slope); %f11 */
  /*          Features(i-x0+1,12-idx_time-idx_freq-idx_diff) = Feature12(CSI,Slope); %f12 */
  /*          Features(i-x0+1,13-idx_time-idx_freq-idx_diff) = Feature13(Mod_CSI,Slope); %f13 */
  /*          Features(i-x0+1,14-idx_time-idx_freq-idx_diff) = Feature14(CSI); %f14 */
  /*          Features(i-x0+1,15-idx_time-idx_freq-idx_diff) = Feature15(Mod_CSI); %f15 */
  /*   */
  /*      end */
  /*      if feature_selector_struct.mask(3) */
  /*          Features(i-x0+1,9-idx_time-idx_freq) = Feature9(HR_diff_orig); %f9 */
  /*      end */
  /*  end */
  /*          [CSI_filt,Mod_CSI_filt,~,  ~]            = Lorenz_plot(RR_Interv_filtr(i-x0+1:i),(Nbr_RR)); */
  b_i = CSI_filt->size[0] * CSI_filt->size[1];
  CSI_filt->size[0] = 1;
  CSI_filt->size[1] = 1;
  emxEnsureCapacity_real_T(CSI_filt, b_i);
  CSI_filt->data[0] = rtNaN;
  b_i = Mod_CSI_filt->size[0] * Mod_CSI_filt->size[1];
  Mod_CSI_filt->size[0] = 1;
  Mod_CSI_filt->size[1] = 1;
  emxEnsureCapacity_real_T(Mod_CSI_filt, b_i);
  Mod_CSI_filt->data[0] = rtNaN;
  emxInit_real_T(&unusedU0, 2);
  emxInit_real_T(&unusedU1, 2);
  if ((idx10 != -1.0) || (idx11 != -1.0)) {
    if ((i >= 0) && (x0 < i - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((i < 0) && (x0 > i - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = i - x0;
    }

    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }

    if (qY > i) {
      b_i = 0;
      k = 0;
    } else {
      b_i = qY - 1;
      k = i;
    }

    RR_Interv_filtr_size[0] = 1;
    qY = k - b_i;
    RR_Interv_filtr_size[1] = qY;
    for (k = 0; k < qY; k++) {
      RR_Interv_filtr_data[k] = RR_Interv_filtr[b_i + k];
    }

    Lorenz_plot(RR_Interv_filtr_data, RR_Interv_filtr_size, Nbr_RR, CSI_filt,
                Mod_CSI_filt, unusedU0, unusedU1);
  }

  emxFree_real_T(&unusedU1);

  /*          [CSI,     Mod_CSI,     ~,HR_diff_orig] = Lorenz_plot(RR_Interv(i-x0+1:i),      (Nbr_RR)); */
  b_i = CSI->size[0] * CSI->size[1];
  CSI->size[0] = 1;
  CSI->size[1] = 1;
  emxEnsureCapacity_real_T(CSI, b_i);
  CSI->data[0] = rtNaN;
  b_i = Mod_CSI->size[0] * Mod_CSI->size[1];
  Mod_CSI->size[0] = 1;
  Mod_CSI->size[1] = 1;
  emxEnsureCapacity_real_T(Mod_CSI, b_i);
  Mod_CSI->data[0] = rtNaN;
  b_i = HR_diff_orig->size[0] * HR_diff_orig->size[1];
  HR_diff_orig->size[0] = 1;
  HR_diff_orig->size[1] = 1;
  emxEnsureCapacity_real_T(HR_diff_orig, b_i);
  HR_diff_orig->data[0] = rtNaN;
  *Slope = rtNaN;
  if ((idx9 != -1.0) || (idx10 != -1.0) || (idx11 != -1.0) || (idx12 != -1.0) ||
      (idx13 != -1.0) || (idx14 != -1.0) || (idx15 != -1.0)) {
    /*      [CSI_filt,Mod_CSI_filt,~,  ~] = Lorenz_plot(RR_Interv_filtr(i-x0+1:i),(Nbr_RR)); */
    if ((i >= 0) && (x0 < i - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((i < 0) && (x0 > i - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = i - x0;
    }

    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }

    if (qY > i) {
      b_i = 0;
      k = 0;
    } else {
      b_i = qY - 1;
      k = i;
    }

    RR_Interv_filtr_size[0] = 1;
    qY = k - b_i;
    RR_Interv_filtr_size[1] = qY;
    for (k = 0; k < qY; k++) {
      RR_Interv_filtr_data[k] = RR_Interv[b_i + k];
    }

    Lorenz_plot(RR_Interv_filtr_data, RR_Interv_filtr_size, Nbr_RR, CSI, Mod_CSI,
                unusedU0, HR_diff_orig);

    /*       Slope=abs(my_slope(tHRV(i-x0+1:i),RR_Interv_filtr(i-x0+1:i))); */
    if ((i >= 0) && (x0 < i - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((i < 0) && (x0 > i - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = i - x0;
    }

    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }

    if (qY > i) {
      b_i = -1;
      k = -1;
    } else {
      b_i = qY - 2;
      k = i - 1;
    }

    if ((i >= 0) && (x0 < i - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((i < 0) && (x0 > i - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = i - x0;
    }

    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }

    if (qY > i) {
      i1 = -1;
      qY = -1;
    } else {
      i1 = qY - 2;
      qY = i - 1;
    }

    vlen = k - b_i;
    if (vlen == 0) {
      y = 0.0;
    } else {
      y = tHRV->data[b_i + 1];
      for (k = 2; k <= vlen; k++) {
        y += tHRV->data[b_i + k];
      }
    }

    mean_X = y / (double)vlen;
    qY -= i1;
    if (qY == 0) {
      y = 0.0;
    } else {
      y = RR_Interv[i1 + 1];
      for (k = 2; k <= qY; k++) {
        y += RR_Interv[i1 + k];
      }
    }

    mean_y = y / (double)qY;
    for (k = 0; k < vlen; k++) {
      RR_Interv_filtr_data[k] = tHRV->data[(b_i + k) + 1] - mean_X;
    }

    for (b_i = 0; b_i < vlen; b_i++) {
      x_data[b_i] = RR_Interv_filtr_data[b_i] * (RR_Interv[(i1 + b_i) + 1] -
        mean_y);
    }

    if (vlen == 0) {
      y = 0.0;
    } else {
      y = x_data[0];
      for (k = 2; k <= vlen; k++) {
        y += x_data[k - 1];
      }
    }

    qY = vlen - 1;
    for (b_i = 0; b_i <= qY; b_i++) {
      mean_y = RR_Interv_filtr_data[b_i];
      mean_y *= mean_y;
      RR_Interv_filtr_data[b_i] = mean_y;
    }

    if (vlen == 0) {
      mean_y = 0.0;
    } else {
      mean_y = RR_Interv_filtr_data[0];
      for (k = 2; k <= vlen; k++) {
        mean_y += RR_Interv_filtr_data[k - 1];
      }
    }

    *Slope = fabs(y / mean_y);

    /*      if feature_selector_struct.mask(4)  */
    /*          if idx10 ~= -1 */
    /*              Features(i-x0+1,idx10) = Feature10(CSI_filt, Slope); %f10 */
    /*          end */
    /*          if idx11 ~= -1 */
    /*              Features(i-x0+1,idx11) = Feature11(Mod_CSI_filt,Slope); %f11 */
    /*          end */
    /*          if idx12 ~= -1 */
    /*              Features(i-x0+1,idx12) = Feature12(CSI,Slope); %f12 */
    /*          end */
    /*          if idx13 ~= -1 */
    /*              Features(i-x0+1,idx13) = Feature13(Mod_CSI,Slope); %f13 */
    /*          end */
    /*          if idx14 ~= -1 */
    /*              Features(i-x0+1,idx14) = Feature14(CSI); %f14 */
    /*          end */
    /*          if idx15 ~= -1 */
    /*              Features(i-x0+1,idx15) = Feature15(Mod_CSI); %f15 */
    /*          end */
    /*   */
    /*      %     end */
    /*          if idx9 ~= -1 */
    /*              Features(i-x0+1,idx9) = Feature9(HR_diff_orig); %f9 */
    /*          end */
  }

  emxFree_real_T(&unusedU0);
}

/* End of code generation (Lorenz_features.c) */
