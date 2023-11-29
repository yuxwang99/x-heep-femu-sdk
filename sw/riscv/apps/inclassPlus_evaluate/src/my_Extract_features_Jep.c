/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * my_Extract_features_Jep.c
 *
 * Code generation for function 'my_Extract_features_Jep'
 *
 */

/* Include files */
#include "my_Extract_features_Jep.h"
#include "Lorenz_features.h"
#include "abs.h"
#include "denoise_rwd.h"
#include "diff.h"
#include "features_Freq_calculator.h"
#include "find.h"
#include "mean.h"
#include "movmedian.h"
#include "nonzeros.h"
#include "pan_tompkin_algorithm_segmented.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_rtwutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "randn.h"
#include "randperm.h"
#include "rt_nonfinite.h"
#include "unique.h"
#include "vvarstd.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void my_Extract_features_Jep(const double ECG_Sig[30720], const double Spo2_sig
  [30720], double Fs, int Nbr_RR, const int feature_selector_struct[17],
  emxArray_real_T *Features, boolean_T ignore_file, emxArray_real_T
  *Features_out)
{
  static double unusedExpr[30720];
  static double HRV[400];
  static double HRV_data[400];
  static double RR_Interv[400];
  static double RR_Interv_filtr[400];
  static double locs_data[400];
  static double a_data[399];
  static double y_data[399];
  static double dv[153];
  static int tmp_data[399];
  static boolean_T b_a_data[399];
  emxArray_real_T b_locs_data;
  emxArray_real_T c_locs_data;
  emxArray_real_T d_locs_data;
  emxArray_real_T e_locs_data;
  emxArray_real_T *CSI;
  emxArray_real_T *HR_diff_orig;
  emxArray_real_T *Mod_CSI;
  emxArray_real_T *Mod_CSI_filt;
  emxArray_real_T *Rlocs;
  emxArray_real_T *a;
  emxArray_real_T *b_Spo2_sig;
  emxArray_real_T *b_locs;
  emxArray_real_T *locs;
  emxArray_real_T *r;
  emxArray_real_T *unusedU0;
  double Tot_pow_data[1];
  double HF;
  double LF_HF;
  double idx1;
  double idx10;
  double idx11;
  double idx12;
  double idx13;
  double idx14;
  double idx15;
  double idx16;
  double idx17;
  double idx2;
  double idx3;
  double idx4;
  double idx5;
  double idx6;
  double idx7;
  double idx8;
  double idx9;
  double pNN50;
  double unusedU1;
  int HRV_size[2];
  int Tot_pow_size[2];
  int a_size[2];
  int b_locs_size[2];
  int locs_size[2];
  int y_size[2];
  int iv[1];
  int b_i;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int loop_ub;
  int nx;
  int stop;
  int x0;
  boolean_T exitg1;

  /*  Feature selector mask is used to select which feature extract, it has the */
  /*  following format: */
  /*  idx 1 : extract_HRV_features_time */
  /*  idx 2 : extract_HRV_features_freq  */
  /*  idx 3 : extract_HR_dif */
  /*  idx 4 : extract_Lorenz  */
  /*  idx 5 : extract_Mean_SPO2 */
  /*  idx 6 : extract_STD_SPO2 */
  emxInit_real_T(&a, 2);
  if (!ignore_file) {
    /*  ---test for runtime only-- */
    /*  use the cache data */
    randn(unusedExpr);

    /*  ---test for runtime only-- */
    /*  ---test for runtime only-- */
    /*  use the cache data */
    randperm(dv);
    i = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = 153;
    emxEnsureCapacity_real_T(a, i);
    for (i = 0; i < 153; i++) {
      a->data[i] = dv[i];
    }

    /*  ---test for runtime only-- */
  } else {
    emxInit_real_T(&unusedU0, 2);
    denoise_rwd(ECG_Sig, ceil(Fs / 5.0), unusedExpr);
    pan_tompkin_algorithm_segmented(unusedExpr, Fs, unusedU0, a);
    emxFree_real_T(&unusedU0);
  }

  emxInit_real_T(&Rlocs, 2);
  emxInit_real_T(&locs, 2);
  unique_vector(a, Rlocs);
  i = locs->size[0] * locs->size[1];
  locs->size[0] = 1;
  locs->size[1] = Rlocs->size[1];
  emxEnsureCapacity_real_T(locs, i);
  loop_ub = Rlocs->size[0] * Rlocs->size[1];
  for (i = 0; i < loop_ub; i++) {
    locs->data[i] = Rlocs->data[i] / Fs;
  }

  for (i = 0; i < 400; i++) {
    RR_Interv[i] = rtNaN;
  }

  c_diff(locs, a);
  loop_ub = a->size[1];
  for (i = 0; i < loop_ub; i++) {
    RR_Interv[i] = a->data[i];
  }

  /* RR_Interv_filtr_2=medfilt1(RR_Interv); %changed to movmedian to for C generation */
  movmedian(RR_Interv, RR_Interv_filtr);
  if (2 > locs->size[1]) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = locs->size[1];
  }

  for (i2 = 0; i2 < 400; i2++) {
    HRV[i2] = 1.0 / RR_Interv[i2];
  }

  if (Nbr_RR > 2147483646) {
    nx = MAX_int32_T;
  } else {
    nx = Nbr_RR + 1;
  }

  if (nx > 400) {
    x0 = 400;
  } else {
    x0 = nx;
  }

  /*  Features = NaN(400, 17); */
  /*  feature_idx = 0; */
  /*  feature_size = 0; */
  /*  idx_features = 0; */
  unusedU1 = 0.0;
  idx1 = -1.0;
  idx2 = -1.0;
  idx3 = -1.0;
  idx4 = -1.0;
  idx5 = -1.0;
  idx6 = -1.0;
  idx7 = -1.0;
  idx8 = -1.0;
  idx9 = -1.0;
  idx10 = -1.0;
  idx11 = -1.0;
  idx12 = -1.0;
  idx13 = -1.0;
  idx14 = -1.0;
  idx15 = -1.0;
  idx16 = -1.0;
  idx17 = -1.0;
  for (b_i = 0; b_i < 17; b_i++) {
    if (feature_selector_struct[b_i] == 1) {
      unusedU1++;
      switch (b_i + 1) {
       case 1:
        idx1 = unusedU1;
        break;

       case 2:
        idx2 = unusedU1;
        break;

       case 3:
        idx3 = unusedU1;
        break;

       case 4:
        idx4 = unusedU1;
        break;

       case 5:
        idx5 = unusedU1;
        break;

       case 6:
        idx6 = unusedU1;
        break;

       case 7:
        idx7 = unusedU1;
        break;

       case 8:
        idx8 = unusedU1;
        break;

       case 9:
        idx9 = unusedU1;
        break;

       case 10:
        idx10 = unusedU1;
        break;

       case 11:
        idx11 = unusedU1;
        break;

       case 12:
        idx12 = unusedU1;
        break;

       case 13:
        idx13 = unusedU1;
        break;

       case 14:
        idx14 = unusedU1;
        break;

       case 15:
        idx15 = unusedU1;
        break;

       case 16:
        idx16 = unusedU1;
        break;

       default:
        idx17 = unusedU1;
        break;
      }
    } else {
      switch (b_i + 1) {
       case 1:
        idx1 = -1.0;
        break;

       case 2:
        idx2 = -1.0;
        break;

       case 3:
        idx3 = -1.0;
        break;

       case 4:
        idx4 = -1.0;
        break;

       case 5:
        idx5 = -1.0;
        break;

       case 6:
        idx6 = -1.0;
        break;

       case 7:
        idx7 = -1.0;
        break;

       case 8:
        idx8 = -1.0;
        break;

       case 9:
        idx9 = -1.0;
        break;

       case 10:
        idx10 = -1.0;
        break;

       case 11:
        idx11 = -1.0;
        break;

       case 12:
        idx12 = -1.0;
        break;

       case 13:
        idx13 = -1.0;
        break;

       case 14:
        idx14 = -1.0;
        break;

       case 15:
        idx15 = -1.0;
        break;

       case 16:
        idx16 = -1.0;
        break;

       default:
        idx17 = -1.0;
        break;
      }
    }
  }

  /*  if feature_selector_struct.mask(1)  */
  /*  %     feature_size = feature_size + 4; */
  /*      idx_time = 0; */
  /*  else */
  /*  %     idx_features = idx_features + 4; */
  /*      idx_time = feature_selector_struct.feature_sizes(1); */
  /*  end */
  /*  if feature_selector_struct.mask(2)  */
  /*  %     feature_size = feature_size + 4; */
  /*      idx_freq = 0; */
  /*  else */
  /*  %     idx_features = idx_features + 4; */
  /*      idx_freq = feature_selector_struct.feature_sizes(2); */
  /*  end */
  /*  if feature_selector_struct.mask(3)  */
  /*  %     feature_size = feature_size + 1; */
  /*      idx_diff = 0; */
  /*  else */
  /*  %     idx_features = idx_features + 1; */
  /*      idx_diff = feature_selector_struct.feature_sizes(3); */
  /*  end */
  /*  if feature_selector_struct.mask(4)  */
  /*  %     feature_size = feature_size + 6; */
  /*      idx_lorenz = 0; */
  /*  else */
  /*  %     idx_features = idx_features + 6; */
  /*      idx_lorenz = feature_selector_struct.feature_sizes(4); */
  /*  end */
  /*  if feature_selector_struct.mask(5)  */
  /*  %     feature_size = feature_size + 1; */
  /*      idx_mean = 0; */
  /*  else */
  /*  %     idx_features = idx_features + 1; */
  /*      idx_mean = feature_selector_struct.feature_sizes(5); */
  /*  end */
  /*  if feature_selector_struct.mask(6)  */
  /*      idx_std = 0; */
  /*  %     feature_size = feature_size + 1; */
  /*  else */
  /*  %     idx_features = idx_features + 1; */
  /*      idx_std = feature_selector_struct.feature_sizes(6) ; */
  /*  end */
  /*  Features = NaN(400, feature_size); */
  /*  Features = NaN(400, 8); */
  /*  HR_diff = []; */
  /*  Mean_SPO2 = []; */
  /*  STD_SPO2 = []; */
  stop = 0;
  b_i = x0;
  emxInit_real_T(&Mod_CSI_filt, 2);
  emxInit_real_T(&CSI, 2);
  emxInit_real_T(&Mod_CSI, 2);
  emxInit_real_T(&HR_diff_orig, 2);
  emxInit_real_T(&b_locs, 2);
  emxInit_real_T(&b_Spo2_sig, 1);
  emxInit_real_T(&r, 1);
  exitg1 = false;
  while ((!exitg1) && (b_i < 401)) {
    if (rtIsNaN(RR_Interv[b_i - 1])) {
      stop = b_i;
      exitg1 = true;
    } else {
      /* Lorenz features */
      /*      if feature_selector_struct.mask(3) || feature_selector_struct.mask(4) */
      if ((idx9 != -1.0) || (idx10 != -1.0) || (idx11 != -1.0) || (idx12 != -1.0)
          || (idx13 != -1.0) || (idx14 != -1.0) || (idx15 != -1.0)) {
        /*          [CSI_filt,Mod_CSI_filt, CSI, Mod_CSI,HR_diff_orig, Slope] = Lorenz_features(RR_Interv_filtr, i, x0, Nbr_RR, tHRV, feature_selector_struct, Features, idx_time, idx_freq, idx_diff, idx9, idx10, idx11, idx12, idx13, idx14, idx15); */
        i2 = b_locs->size[0] * b_locs->size[1];
        b_locs->size[0] = 1;
        loop_ub = i1 - i;
        b_locs->size[1] = loop_ub;
        emxEnsureCapacity_real_T(b_locs, i2);
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_locs->data[i2] = locs->data[i + i2];
        }

        Lorenz_features(RR_Interv_filtr, RR_Interv, b_i, x0, x0 - 1, b_locs,
                        idx9, idx10, idx11, idx12, idx13, idx14, idx15, a,
                        Mod_CSI_filt, CSI, Mod_CSI, HR_diff_orig, &unusedU1);

        /*          [CSI_filt,Mod_CSI_filt,~,  ~]            = Lorenz_plot(RR_Interv_filtr(i-x0+1:i),(Nbr_RR)); */
        /*          [CSI,     Mod_CSI,     ~,HR_diff_orig] = Lorenz_plot(RR_Interv(i-x0+1:i),      (Nbr_RR)); */
        /*          Slope=abs(my_slope(tHRV(i-x0+1:i),RR_Interv_filtr(i-x0+1:i))); */
        /*  if feature_selector_struct.mask(4)  */
        /*  % Lorenz_seg = [CSI_filt*Slope, ... */
        /*  %     Mod_CSI_filt*Slope,     ... */
        /*  %     CSI*Slope,      ... */
        /*  %     Mod_CSI*Slope,  ... */
        /*  %     CSI,    ... */
        /*  %     Mod_CSI]; */
        /*  %             Features(i-x0+1,10-idx_time-idx_freq-idx_diff) = CSI_filt(1)*Slope; %f10 */
        /*  %             Features(i-x0+1,11-idx_time-idx_freq-idx_diff) = Mod_CSI_filt(1)*Slope; %f11 */
        /*  %             Features(i-x0+1,12-idx_time-idx_freq-idx_diff) = CSI(1)*Slope; %f12 */
        /*  %             Features(i-x0+1,13-idx_time-idx_freq-idx_diff) = Mod_CSI(1)*Slope; %f13 */
        /*  %             Features(i-x0+1,14-idx_time-idx_freq-idx_diff) = CSI(1); %f14 */
        /*  %             Features(i-x0+1,15-idx_time-idx_freq-idx_diff) = Mod_CSI(1); %f15 */
        if (idx10 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx10 - 1)) - 1] = a->data[0] *
            unusedU1;

          /* f10 */
        }

        if (idx11 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx11 - 1)) - 1] = Mod_CSI_filt->
            data[0] * unusedU1;

          /* f11 */
        }

        if (idx12 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx12 - 1)) - 1] = CSI->data[0] *
            unusedU1;

          /* f12 */
        }

        if (idx13 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx13 - 1)) - 1] = Mod_CSI->data[0] *
            unusedU1;

          /* f13 */
        }

        if (idx14 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx14 - 1)) - 1] = CSI->data[0];

          /* f14 */
        }

        if (idx15 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx15 - 1)) - 1] = Mod_CSI->data[0];

          /* f15 */
        }

        /*               */
        /*          end */
        if (idx9 != -1.0) {
          /*              HR_diff = [HR_diff;HR_diff_orig]; */
          /*              Features(i-x0+1,9-idx_time-idx_freq) = HR_diff_orig(1); %f9 */
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx9 - 1)) - 1] = HR_diff_orig->data
            [0];

          /* f9 */
        }
      }

      /* HRV features (time and freq) */
      /*      if feature_selector_struct.mask(2) */
      if ((idx5 != -1.0) || (idx6 != -1.0) || (idx7 != -1.0) || (idx8 != -1.0))
      {
        if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
          nx = MAX_int32_T;
        } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
          nx = MIN_int32_T;
        } else {
          nx = b_i - x0;
        }

        if (nx > 2147483646) {
          nx = MAX_int32_T;
        } else {
          nx++;
        }

        if (nx > b_i) {
          i2 = 0;
          i3 = 0;
        } else {
          i2 = nx - 1;
          i3 = b_i;
        }

        if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
          nx = MAX_int32_T;
        } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
          nx = MIN_int32_T;
        } else {
          nx = b_i - x0;
        }

        if (nx > 2147483646) {
          nx = MAX_int32_T;
        } else {
          nx++;
        }

        if (nx > b_i) {
          i4 = 0;
          nx = 0;
        } else {
          i4 = nx - 1;
          nx = b_i;
        }

        locs_size[0] = 1;
        loop_ub = i3 - i2;
        locs_size[1] = loop_ub;
        for (i3 = 0; i3 < loop_ub; i3++) {
          locs_data[i3] = locs->data[(i + i2) + i3];
        }

        HRV_size[0] = 1;
        loop_ub = nx - i4;
        HRV_size[1] = loop_ub;
        for (i2 = 0; i2 < loop_ub; i2++) {
          HRV_data[i2] = HRV[i4 + i2];
        }

        b_locs_size[0] = locs_size[0];
        b_locs_size[1] = locs_size[1];
        features_Freq_calculator(locs_data, b_locs_size, HRV_data, HRV_size,
          idx5, idx6, idx7, idx8, Tot_pow_data, Tot_pow_size, &unusedU1, &HF,
          &LF_HF);

        /*          HRV_seg_freq = [Tot_pow,LF,HF,LF_HF]; */
        /*          Features(i-x0+1,5-idx_time) = Tot_pow(1); %f5 */
        /*          Features(i-x0+1,6-idx_time) = LF; %f6 */
        /*          Features(i-x0+1,7-idx_time) = HF; %f7 */
        /*          Features(i-x0+1,8-idx_time) = LF_HF; %f8 */
        if (idx5 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx5 - 1)) - 1] = Tot_pow_data[0];

          /* f5 */
        }

        if (idx6 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx6 - 1)) - 1] = unusedU1;

          /* f6   */
        }

        if (idx7 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx7 - 1)) - 1] = HF;

          /* f7   */
        }

        if (idx8 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx8 - 1)) - 1] = LF_HF;

          /* f8   */
        }
      }

      if ((idx1 != -1.0) || (idx2 != -1.0) || (idx3 != -1.0) || (idx4 != -1.0))
      {
        if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
          nx = MAX_int32_T;
        } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
          nx = MIN_int32_T;
        } else {
          nx = b_i - x0;
        }

        if (nx > 2147483646) {
          nx = MAX_int32_T;
        } else {
          nx++;
        }

        if (nx > b_i) {
          i2 = 0;
          i3 = 0;
        } else {
          i2 = nx - 1;
          i3 = b_i;
        }

        /*  Mean_RR=mean(RR_Interv); */
        if (idx1 != -1.0) {
          locs_size[0] = 1;
          loop_ub = i3 - i2;
          locs_size[1] = loop_ub;
          for (i4 = 0; i4 < loop_ub; i4++) {
            locs_data[i4] = RR_Interv_filtr[i2 + i4];
          }

          unusedU1 = c_mean(locs_data, locs_size);
        } else {
          unusedU1 = rtNaN;
        }

        /*  Std_RR=std(RR_Interv); */
        if (idx2 != -1.0) {
          locs_size[0] = 1;
          loop_ub = i3 - i2;
          locs_size[1] = loop_ub;
          for (i4 = 0; i4 < loop_ub; i4++) {
            locs_data[i4] = RR_Interv_filtr[i2 + i4];
          }

          iv[0] = loop_ub;
          b_locs_data.data = &locs_data[0];
          b_locs_data.size = &iv[0];
          b_locs_data.allocatedSize = 400;
          b_locs_data.numDimensions = 1;
          b_locs_data.canFreeData = false;
          HF = vvarstd(&b_locs_data, loop_ub);
        } else {
          HF = rtNaN;
        }

        /*  RMSSD=sqrt(mean(diff(RR_Interv).^2)); */
        if (idx3 != -1.0) {
          locs_size[0] = 1;
          loop_ub = i3 - i2;
          locs_size[1] = loop_ub;
          for (i4 = 0; i4 < loop_ub; i4++) {
            locs_data[i4] = RR_Interv_filtr[i2 + i4];
          }

          c_locs_data.data = &locs_data[0];
          c_locs_data.size = &locs_size[0];
          c_locs_data.allocatedSize = 400;
          c_locs_data.numDimensions = 2;
          c_locs_data.canFreeData = false;
          c_diff(&c_locs_data, a);
          nx = a->size[1];
          loop_ub = a->size[0] * a->size[1];
          for (i4 = 0; i4 < loop_ub; i4++) {
            a_data[i4] = a->data[i4];
          }

          y_size[0] = 1;
          y_size[1] = (short)nx;
          nx = (short)nx;
          for (loop_ub = 0; loop_ub < nx; loop_ub++) {
            y_data[loop_ub] = rt_powd_snf(a_data[loop_ub], 2.0);
          }

          LF_HF = sqrt(c_mean(y_data, y_size));
        } else {
          LF_HF = rtNaN;
        }

        /*  pNN50=length(find(diff(RR_Interv) > 0.05))./length(diff(RR_Interv)); */
        if (idx4 != -1.0) {
          locs_size[0] = 1;
          loop_ub = i3 - i2;
          locs_size[1] = loop_ub;
          for (i3 = 0; i3 < loop_ub; i3++) {
            locs_data[i3] = RR_Interv_filtr[i2 + i3];
          }

          d_locs_data.data = &locs_data[0];
          d_locs_data.size = &locs_size[0];
          d_locs_data.allocatedSize = 400;
          d_locs_data.numDimensions = 2;
          d_locs_data.canFreeData = false;
          c_diff(&d_locs_data, a);
          a_size[0] = 1;
          a_size[1] = a->size[1];
          nx = a->size[0] * a->size[1];
          for (i3 = 0; i3 < nx; i3++) {
            b_a_data[i3] = (a->data[i3] > 0.05);
          }

          locs_size[0] = 1;
          locs_size[1] = loop_ub;
          for (i3 = 0; i3 < loop_ub; i3++) {
            locs_data[i3] = RR_Interv_filtr[i2 + i3];
          }

          d_eml_find(b_a_data, a_size, tmp_data, Tot_pow_size);
          e_locs_data.data = &locs_data[0];
          e_locs_data.size = &locs_size[0];
          e_locs_data.allocatedSize = 400;
          e_locs_data.numDimensions = 2;
          e_locs_data.canFreeData = false;
          c_diff(&e_locs_data, a);
          pNN50 = (double)Tot_pow_size[1] / (double)a->size[1];
        } else {
          pNN50 = rtNaN;
        }

        if (idx1 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx1 - 1)) - 1] = unusedU1;

          /* f1 */
        }

        if (idx2 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx2 - 1)) - 1] = HF;

          /* f1 */
        }

        if (idx3 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx3 - 1)) - 1] = LF_HF;

          /* f3 */
        }

        if (idx4 != -1.0) {
          if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
            nx = MAX_int32_T;
          } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = b_i - x0;
          }

          if (nx > 2147483646) {
            nx = MAX_int32_T;
          } else {
            nx++;
          }

          Features->data[(nx + 400 * ((int)idx4 - 1)) - 1] = pNN50;

          /* f4 */
        }
      }

      /*      if feature_selector_struct.mask(1) */
      /*          [Mean_RR,Std_RR,RMSSD,pNN50]=features_time_calculator(RR_Interv_filtr(i-x0+1:i)); */
      /*  %         HRV_seg_time = [Mean_RR,Std_RR,RMSSD,pNN50]; */
      /*          Features(i-x0+1,1) = Mean_RR; %f1 */
      /*          Features(i-x0+1,2) = Std_RR; %f2 */
      /*          Features(i-x0+1,3) = RMSSD; %f3 */
      /*          Features(i-x0+1,4) = pNN50; %f4 */
      /*      end  */
      /*      if feature_selector_mask(1) || feature_selector_mask(2) */
      /*          HRV_seg = [HRV_seg_time,HRV_seg_freq]; */
      /*          HRV_features = [HRV_features;HRV_seg];   */
      /*      end    */
      /* SPO2 features */
      /*      if feature_selector_struct.mask(5) */
      if (idx16 != -1.0) {
        /*          Mean_SPO2  = [Mean_SPO2,mean(nonzeros(abs(Spo2_sig(Rlocs(i-x0+1):Rlocs(i)))))]; */
        /*          Features(i-x0+1,16-idx_time-idx_freq-idx_lorenz-idx_diff) = ... */
        /*              Feature16(Spo2_sig,Rlocs, i, x0); */
        if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
          nx = MAX_int32_T;
        } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
          nx = MIN_int32_T;
        } else {
          nx = b_i - x0;
        }

        if (nx > 2147483646) {
          nx = MAX_int32_T;
        } else {
          nx++;
        }

        unusedU1 = Rlocs->data[nx - 1];
        if (unusedU1 > Rlocs->data[b_i - 1]) {
          i2 = 0;
          i3 = 0;
        } else {
          i2 = (int)unusedU1 - 1;
          i3 = (int)Rlocs->data[b_i - 1];
        }

        loop_ub = i3 - i2;
        i3 = b_Spo2_sig->size[0];
        b_Spo2_sig->size[0] = loop_ub;
        emxEnsureCapacity_real_T(b_Spo2_sig, i3);
        for (i3 = 0; i3 < loop_ub; i3++) {
          b_Spo2_sig->data[i3] = Spo2_sig[i2 + i3];
        }

        if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
          nx = MAX_int32_T;
        } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
          nx = MIN_int32_T;
        } else {
          nx = b_i - x0;
        }

        if (nx > 2147483646) {
          nx = MAX_int32_T;
        } else {
          nx++;
        }

        b_abs(b_Spo2_sig, r);
        nonzeros(r, b_Spo2_sig);
        Features->data[(nx + 400 * ((int)idx16 - 1)) - 1] = b_mean(b_Spo2_sig);

        /*              mean(nonzeros(abs(Spo2_sig(Rlocs(i-x0+1):Rlocs(i))))); %f16 */
      }

      /*      if feature_selector_struct.mask(6) */
      if (idx17 != -1.0) {
        /*          STD_SPO2   = [STD_SPO2,std(nonzeros(abs(Spo2_sig(Rlocs(i-x0+1):Rlocs(i)))))]; */
        /*          Features(i-x0+1,17-idx_time-idx_freq-idx_lorenz-idx_diff-idx_mean) = ... */
        /*              Feature17(Spo2_sig,Rlocs, i, x0); */
        if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
          nx = MAX_int32_T;
        } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
          nx = MIN_int32_T;
        } else {
          nx = b_i - x0;
        }

        if (nx > 2147483646) {
          nx = MAX_int32_T;
        } else {
          nx++;
        }

        unusedU1 = Rlocs->data[nx - 1];
        if (unusedU1 > Rlocs->data[b_i - 1]) {
          i2 = 0;
          i3 = 0;
        } else {
          i2 = (int)unusedU1 - 1;
          i3 = (int)Rlocs->data[b_i - 1];
        }

        loop_ub = i3 - i2;
        i3 = b_Spo2_sig->size[0];
        b_Spo2_sig->size[0] = loop_ub;
        emxEnsureCapacity_real_T(b_Spo2_sig, i3);
        for (i3 = 0; i3 < loop_ub; i3++) {
          b_Spo2_sig->data[i3] = Spo2_sig[i2 + i3];
        }

        b_abs(b_Spo2_sig, r);
        nonzeros(r, b_Spo2_sig);
        if ((b_i >= 0) && (x0 < b_i - MAX_int32_T)) {
          nx = MAX_int32_T;
        } else if ((b_i < 0) && (x0 > b_i - MIN_int32_T)) {
          nx = MIN_int32_T;
        } else {
          nx = b_i - x0;
        }

        if (nx > 2147483646) {
          nx = MAX_int32_T;
        } else {
          nx++;
        }

        Features->data[(nx + 400 * ((int)idx17 - 1)) - 1] = vvarstd(b_Spo2_sig,
          b_Spo2_sig->size[0]);

        /*              std(nonzeros(abs(Spo2_sig(Rlocs(i-x0+1):Rlocs(i))))); %f17 */
        /* Sometimes this is NaN */
      }

      /*      Features(i,:) = [HRV_seg, HR_diff_orig, Lorenz_seg, ... */
      /*                      mean(nonzeros(abs(Spo2_sig(Rlocs(i-x0+1):Rlocs(i))))), ... */
      /*                      std(nonzeros(abs(Spo2_sig(Rlocs(i-x0+1):Rlocs(i)))))]; */
      b_i++;
    }
  }

  emxFree_real_T(&r);
  emxFree_real_T(&b_Spo2_sig);
  emxFree_real_T(&b_locs);
  emxFree_real_T(&a);
  emxFree_real_T(&HR_diff_orig);
  emxFree_real_T(&Mod_CSI);
  emxFree_real_T(&CSI);
  emxFree_real_T(&Mod_CSI_filt);
  emxFree_real_T(&locs);
  emxFree_real_T(&Rlocs);
  if ((stop >= 0) && (x0 < stop - MAX_int32_T)) {
    nx = MAX_int32_T;
  } else if ((stop < 0) && (x0 > stop - MIN_int32_T)) {
    nx = MIN_int32_T;
  } else {
    nx = stop - x0;
  }

  if (1 > nx) {
    loop_ub = 0;
  } else {
    loop_ub = nx;
  }

  nx = Features->size[1];
  i = Features_out->size[0] * Features_out->size[1];
  Features_out->size[0] = loop_ub;
  Features_out->size[1] = Features->size[1];
  emxEnsureCapacity_real_T(Features_out, i);
  for (i = 0; i < nx; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      Features_out->data[i1 + Features_out->size[0] * i] = Features->data[i1 +
        400 * i];
    }
  }

  /*  Features_out = Features(Nbr_RR+1:size(Rlocs,2)-1,:); */
  /*  Removed for C generation */
  /* if isempty(Features) */
  /* disp(strcat(File_info,'Bad signal, please remove the file from list file..')) */
  /* fprintf(Warning_file_selection_Id,[cell2mat(File_info) '|' 'no features', '\n']); */
  /* error('Bad signal, please remove the file from list file..') */
  /* end */
}

/* End of code generation (my_Extract_features_Jep.c) */
