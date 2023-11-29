/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pan_tompkin_algorithm_segmented.c
 *
 * Code generation for function 'pan_tompkin_algorithm_segmented'
 *
 */

/* Include files */
#include "pan_tompkin_algorithm_segmented.h"
#include "combineVectorElements.h"
#include "diff.h"
#include "filter.h"
#include "findpeaks.h"
#include "mean.h"
#include "minOrMax.h"
#include "nullAssignment.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_rtwutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void pan_tompkin_algorithm_segmented(double sig_short[30720], double fs,
  emxArray_real_T *qrs_amp_raw, emxArray_real_T *Rloc)
{
  static const double dv3[33] = { -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 32.0, -32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const double dv[13] = { 0.027777777777777776, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.055555555555555552, 0.0, 0.0, 0.0, 0.0, 0.0, 0.027777777777777776 };

  static const double b[5] = { 0.2, 0.1, 0.0, -0.1, -0.4 };

  static const double dv1[3] = { 1.0, -2.0, 1.0 };

  static double ecg_hpf[30720];
  static double ecg_lpf[30720];
  static double varargin_1[30720];
  static boolean_T qrs_i_raw_data[30720];
  emxArray_real_T *b_ecg_hpf;
  emxArray_real_T *b_varargin_1;
  emxArray_real_T *locs;
  emxArray_real_T *pks;
  emxArray_real_T *qrs_i_raw;
  emxArray_real_T *qrs_i_vec;
  emxArray_real_T *r;
  emxArray_real_T *varargin_1_tmp;
  double dv2[33];
  double diffRR_buffer[9];
  double x[8];
  double THR_NOISE;
  double THR_SIG;
  double THR_SIG1;
  double b_tmp_tmp;
  double d;
  double locs_temp;
  double m_selected_RR;
  double mean_RR;
  double pks_temp;
  double qrs_i_idx;
  double y_i;
  int qrs_i_raw_size[1];
  int b_i;
  int diffRR_counter;
  int i;
  int i1;
  int i2;
  unsigned int idx_Rloc;
  int j;
  int k;
  int qrs_c_couter;
  int ser_back;
  int x_i;
  boolean_T guard1 = false;

  /* FRAN: I changed the threshold calculation with respect to the previous */
  /* impementation. Before, the thresholds were calculated at the beginning and */
  /* updated for every new peak. This caused problems when the signal was very */
  /* noisy at some point, since the thresholds took ages to come back to a */
  /* value where the peaks following the noise could be detected. Now the */
  /* thresholds are calculated using 2 seconds of the signal every time a peak */
  /* is detected */
  d = mean(sig_short);
  for (i = 0; i < 30720; i++) {
    sig_short[i] -= d;
  }

  /*  Initialize */
  /*  qrs_c =[]; %amplitude of R */
  qrs_c_couter = -1;

  /*  qrs_i =[]; %index */
  /*  qrs_i = zeros(1, length(pks)); */
  /*  qrs_i_couter = 0; */
  /*  becomes one when a T wave is detected */
  m_selected_RR = 0.0;
  mean_RR = 0.0;

  /*  qrs_i_raw =[]; */
  /*  qrs_amp_raw=[]; */
  ser_back = 0;
  y_i = 0.0;
  x_i = 0;

  /*  Filtering - High Pass Filter & Low pass filter */
  /*  displayMessage('Filtering...'); */
  /*  Low Pass Filter  H(z) = ((1 - z^(-6))^2)/(1 - z^(-1))^2 */
  /*  sig_short -> the one from ecgprocessing */
  /* try to find an automatic was for this */
  /*  [~, w_lpf] = freqz(b_lpf, a_lpf, 2000); */
  /*  f_lpf = fs*w_lpf/(2*pi); */
  filter(dv, dv1, sig_short, ecg_lpf);
  for (k = 0; k < 30720; k++) {
    varargin_1[k] = fabs(ecg_lpf[k]);
  }

  qrs_i_idx = b_maximum(varargin_1);
  for (i = 0; i < 30720; i++) {
    ecg_lpf[i] /= qrs_i_idx;
  }

  /*  High Pass filter H(z) = (-1 + 32z^(-16)- 32z^(-17) + z^(-32))/(32 - 32z^(-1)) */
  memcpy(&dv2[0], &dv3[0], 33U * sizeof(double));
  b_filter(dv2, ecg_lpf, ecg_hpf);
  for (k = 0; k < 30720; k++) {
    varargin_1[k] = fabs(ecg_hpf[k]);
  }

  qrs_i_idx = b_maximum(varargin_1);

  /*  [h_hpf, w_hpf] = freqz(b_hpf, a_hpf, 2000); */
  /*  f_hpf = fs*w_hpf/(2*pi); */
  /*  derivative filter H(z) = 0.1(2 + z^(-1) - z^(-3) - 2z^(-4)) */
  for (b_i = 0; b_i < 30720; b_i++) {
    ecg_hpf[b_i] /= qrs_i_idx;
    ecg_lpf[b_i] = 0.0;
  }

  for (k = 0; k < 5; k++) {
    diffRR_counter = k + 1;
    for (j = diffRR_counter; j < 30721; j++) {
      ecg_lpf[j - 1] += b[k] * ecg_hpf[(j - k) - 1];
    }
  }

  qrs_i_idx = b_maximum(ecg_lpf);

  /*  Squaring nonlinearly enhance the dominant peaks */
  /*  Moving average Y(nt) = (1/N)[x(nT-(N - 1)T)+ x(nT - (N - 2)T)+...+x(nT)] */
  /*  Namely in the paper we have a sampling frequency of 200Hz for which we */
  /*  have a moving window having 30 samples i.e. 150ms... So, 200:150 = 250:x */
  /*  -> we are getting a new length of our window which is equal to 187.5 ms */
  /*  200 elementi */
  b_tmp_tmp = rt_roundd_snf(0.15 * fs);

  /*  b_test = ones(1,200)/round(length_maw*fs); */
  for (k = 0; k < 30720; k++) {
    d = ecg_lpf[k] / qrs_i_idx;
    ecg_lpf[k] = d;
    varargin_1[k] = d * d;
  }

  emxInit_real_T(&varargin_1_tmp, 2);
  i = varargin_1_tmp->size[0] * varargin_1_tmp->size[1];
  varargin_1_tmp->size[0] = 1;
  varargin_1_tmp->size[1] = (int)b_tmp_tmp;
  emxEnsureCapacity_real_T(varargin_1_tmp, i);
  k = (int)b_tmp_tmp;
  for (i = 0; i < k; i++) {
    varargin_1_tmp->data[i] = 1.0 / b_tmp_tmp;
  }

  emxInit_real_T(&pks, 1);
  emxInit_real_T(&locs, 1);
  emxInit_real_T(&qrs_i_vec, 2);
  c_filter(varargin_1_tmp, varargin_1, ecg_lpf);

  /*  ecg_m_test = filter(b_test, 1, ecg_s); */
  /*  for i=1:length(ecg_m) */
  /*     if ecg_m(i)~=ecg_m_test(i)  */
  /*          ecg_m(i) */
  /*          ecg_m_test(i)  */
  /*     end */
  /*  end */
  /*  Finding potential R peaks - no RR waves can occur in less than 200 msec distance */
  /* displayMessage('Finding candidates...'); */
  findpeaks(ecg_lpf, rt_roundd_snf(0.3 * fs), pks, locs);
  i = qrs_i_vec->size[0] * qrs_i_vec->size[1];
  qrs_i_vec->size[0] = 1;
  qrs_i_vec->size[1] = pks->size[0];
  emxEnsureCapacity_real_T(qrs_i_vec, i);
  k = pks->size[0];
  for (i = 0; i < k; i++) {
    qrs_i_vec->data[i] = 0.0;
  }

  emxInit_real_T(&qrs_i_raw, 2);
  i = qrs_i_raw->size[0] * qrs_i_raw->size[1];
  qrs_i_raw->size[0] = 1;
  qrs_i_raw->size[1] = pks->size[0];
  emxEnsureCapacity_real_T(qrs_i_raw, i);
  k = pks->size[0];
  for (i = 0; i < k; i++) {
    qrs_i_raw->data[i] = 0.0;
  }

  i = qrs_amp_raw->size[0] * qrs_amp_raw->size[1];
  qrs_amp_raw->size[0] = 1;
  qrs_amp_raw->size[1] = pks->size[0];
  emxEnsureCapacity_real_T(qrs_amp_raw, i);
  k = pks->size[0];
  for (i = 0; i < k; i++) {
    qrs_amp_raw->data[i] = 0.0;
  }

  /*  initialize the training phase (2 seconds of the signal) to determine the THR_SIG and THR_NOISE */
  /*  0.25 of the max amplitude */
  /*  0.5 of the mean signal is considered to be noise */
  /*  Initialize bandpath filter threshold(2 seconds of the bandpass signal) */
  /*  0.25 of the max amplitude */
  /*  */
  /*  Signal level in Bandpassed filter */
  /*  Noise level in Bandpassed filter */
  /*  Thresholding and online desicion rule */
  /* displayMessage('Detecting R peaks...'); */
  while (30720.0 - locs->data[locs->size[0] - 1] < 2.0 * fs) {
    nullAssignment(locs, locs->size[0]);
    nullAssignment(pks, pks->size[0]);
  }

  i = pks->size[0];
  emxInit_real_T(&b_varargin_1, 1);
  emxInit_real_T(&b_ecg_hpf, 1);
  emxInit_real_T(&r, 1);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = varargin_1_tmp->size[0] * varargin_1_tmp->size[1];
    varargin_1_tmp->size[0] = 1;
    k = (int)floor(2.0 * fs);
    varargin_1_tmp->size[1] = k + 1;
    emxEnsureCapacity_real_T(varargin_1_tmp, i1);
    for (i1 = 0; i1 <= k; i1++) {
      varargin_1_tmp->data[i1] = i1;
    }

    i1 = b_varargin_1->size[0];
    b_varargin_1->size[0] = varargin_1_tmp->size[1];
    emxEnsureCapacity_real_T(b_varargin_1, i1);
    k = varargin_1_tmp->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_varargin_1->data[i1] = ecg_lpf[(int)(locs->data[b_i] +
        varargin_1_tmp->data[i1]) - 1];
    }

    THR_SIG = maximum(b_varargin_1) / 3.0;

    /*  0.25 of the max amplitude */
    i1 = b_varargin_1->size[0];
    b_varargin_1->size[0] = varargin_1_tmp->size[1];
    emxEnsureCapacity_real_T(b_varargin_1, i1);
    k = varargin_1_tmp->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_varargin_1->data[i1] = ecg_lpf[(int)(locs->data[b_i] +
        varargin_1_tmp->data[i1]) - 1];
    }

    THR_NOISE = b_mean(b_varargin_1) / 2.0;

    /*  0.5 of the mean signal is considered to be noise */
    /*     %% Initialize bandpath filter threshold(2 seconds of the bandpass signal) */
    i1 = b_varargin_1->size[0];
    b_varargin_1->size[0] = varargin_1_tmp->size[1];
    emxEnsureCapacity_real_T(b_varargin_1, i1);
    k = varargin_1_tmp->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_varargin_1->data[i1] = ecg_hpf[(int)(locs->data[b_i] +
        varargin_1_tmp->data[i1]) - 1];
    }

    THR_SIG1 = maximum(b_varargin_1) / 3.0;

    /*  0.25 of the max amplitude */
    i1 = b_varargin_1->size[0];
    b_varargin_1->size[0] = varargin_1_tmp->size[1];
    emxEnsureCapacity_real_T(b_varargin_1, i1);
    k = varargin_1_tmp->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_varargin_1->data[i1] = ecg_hpf[(int)(locs->data[b_i] +
        varargin_1_tmp->data[i1]) - 1];
    }

    /*  */
    /*  Signal level in Bandpassed filter */
    /*  Noise level in Bandpassed filter */
    /*     %% locate the corresponding peak in the filtered signal - the output of the HPF ecg_hpf */
    d = locs->data[b_i] - b_tmp_tmp;
    if (d >= 1.0) {
      if (d > locs->data[b_i]) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (int)d - 1;
        i2 = (int)locs->data[b_i];
      }

      k = i2 - i1;
      i2 = b_ecg_hpf->size[0];
      b_ecg_hpf->size[0] = k;
      emxEnsureCapacity_real_T(b_ecg_hpf, i2);
      for (i2 = 0; i2 < k; i2++) {
        b_ecg_hpf->data[i2] = ecg_hpf[i1 + i2];
      }

      c_maximum(b_ecg_hpf, &y_i, &x_i);
    } else if (b_i + 1 == 1) {
      k = (int)locs->data[0];
      i1 = b_ecg_hpf->size[0];
      b_ecg_hpf->size[0] = (int)locs->data[0];
      emxEnsureCapacity_real_T(b_ecg_hpf, i1);
      for (i1 = 0; i1 < k; i1++) {
        b_ecg_hpf->data[i1] = ecg_hpf[i1];
      }

      c_maximum(b_ecg_hpf, &y_i, &x_i);
      ser_back = 1;
    } else {
      if (locs->data[b_i] >= 30720.0) {
        k = 30721 - (int)d;
        i1 = b_ecg_hpf->size[0];
        b_ecg_hpf->size[0] = 30721 - (int)d;
        emxEnsureCapacity_real_T(b_ecg_hpf, i1);
        for (i1 = 0; i1 < k; i1++) {
          b_ecg_hpf->data[i1] = ecg_hpf[((int)d + i1) - 1];
        }

        c_maximum(b_ecg_hpf, &y_i, &x_i);
      }
    }

    /* update the heart_rate (Two heart rate means one the most recent and the other selected) */
    /*      if length(qrs_c) >= 9 */
    if (qrs_c_couter + 1 >= 9) {
      /*          diffRR = diff(qrs_i(end-8:end)); */
      diffRR_counter = 1;
      memset(&diffRR_buffer[0], 0, 9U * sizeof(double));
      qrs_i_idx = 8.0;
      while (diffRR_counter <= 9) {
        pks_temp = qrs_i_vec->data[(int)((double)(qrs_c_couter + 1) - qrs_i_idx)
          - 1];
        if (pks_temp != 0.0) {
          diffRR_buffer[diffRR_counter - 1] = pks_temp;
          diffRR_counter++;
          qrs_i_idx--;
        }

        /*              qrs_i_idx = qrs_i_idx - 1; */
      }

      /*          if any(diffRR ~= diff(diffRR_buffer)) */
      /*              any(diffRR ~= diff(diffRR_buffer)) */
      /*          end */
      /* calculate RR interval */
      diff(diffRR_buffer, x);
      qrs_i_idx = x[0];
      for (k = 0; k < 7; k++) {
        qrs_i_idx += x[k + 1];
      }

      mean_RR = qrs_i_idx / 8.0;

      /*  calculate the mean of 8 previous R waves interval */
      /*          comp = qrs_i(end)-qrs_i(end-1); %latest RR */
      qrs_i_idx = qrs_i_vec->data[qrs_c_couter] - qrs_i_vec->data[qrs_c_couter -
        1];

      /* latest RR */
      /*          if comp ~= comp2 */
      /*             comp  */
      /*             comp2 */
      /*          end */
      if ((qrs_i_idx <= 0.92 * mean_RR) || (qrs_i_idx >= 1.16 * mean_RR)) {
        /*  lower down thresholds to detect better in MVI */
        THR_SIG *= 0.5;

        /*  lower down thresholds to detect better in Bandpass filtered */
        THR_SIG1 *= 0.5;

        /* THR_NOISE1 = 0.5*(THR_SIG1); */
      } else {
        m_selected_RR = mean_RR;

        /* the latest regular beats mean */
      }
    }

    /* calculate the mean of the last 8 R waves to make sure that QRS is not */
    /*  missing(If no R detected , trigger a search back) 1.66*mean */
    if (m_selected_RR != 0.0) {
      qrs_i_idx = m_selected_RR;

      /* if the regular RR availabe use it */
    } else if (mean_RR != 0.0) {
      qrs_i_idx = mean_RR;
    } else {
      qrs_i_idx = 0.0;
    }

    if ((qrs_i_idx != 0.0) && (locs->data[b_i] - qrs_i_vec->data[qrs_c_couter] >=
         rt_roundd_snf(1.66 * qrs_i_idx))) {
      /*          if (locs(i) - qrs_i(end)) >= round(1.66*test_m)% it shows a QRS is missed */
      /*  it shows a QRS is missed */
      /*              if (locs(i) - qrs_i(end)) ~= (locs(i) - qrs_i_vec(qrs_c_couter)) */
      /*                  (locs(i) - qrs_i(end)) - (locs(i) - qrs_i_vec(qrs_c_couter)) */
      /*              end */
      /*              [pks_temp, locs_temp] = max(ecg_m(qrs_i(end)+ round(0.200*fs):locs(i)-round(0.200*fs))); % search back and locate the max in this interval */
      pks_temp = rt_roundd_snf(0.2 * fs);
      qrs_i_idx = qrs_i_vec->data[qrs_c_couter] + pks_temp;
      pks_temp = locs->data[b_i] - pks_temp;
      if (qrs_i_idx > pks_temp) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (int)qrs_i_idx - 1;
        i2 = (int)pks_temp;
      }

      k = i2 - i1;
      i2 = b_ecg_hpf->size[0];
      b_ecg_hpf->size[0] = k;
      emxEnsureCapacity_real_T(b_ecg_hpf, i2);
      for (i2 = 0; i2 < k; i2++) {
        b_ecg_hpf->data[i2] = ecg_lpf[i1 + i2];
      }

      c_maximum(b_ecg_hpf, &pks_temp, &diffRR_counter);

      /*  search back and locate the max in this interval */
      /*              locs_temp = qrs_i(end)+ round(0.200*fs) + locs_temp -1; %location */
      locs_temp = (qrs_i_idx + (double)diffRR_counter) - 1.0;

      /* location */
      if (pks_temp > THR_NOISE) {
        /*                  qrs_c = [qrs_c pks_temp]; */
        qrs_c_couter++;

        /*                  qrs_i = [qrs_i locs_temp]; */
        qrs_i_vec->data[qrs_c_couter] = locs_temp;

        /*                  if qrs_i ~= qrs_i_vec(qrs_c_couter) */
        /*                      qrs_i */
        /*                      qrs_i_vec(qrs_c_couter) */
        /*                  end */
        /*  find the location in filtered sig */
        if (locs_temp <= 30720.0) {
          pks_temp = locs_temp - rt_roundd_snf(0.15 * fs);
          if (pks_temp > locs_temp) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = (int)pks_temp - 1;
            i2 = (int)locs_temp;
          }

          k = i2 - i1;
          i2 = b_ecg_hpf->size[0];
          b_ecg_hpf->size[0] = k;
          emxEnsureCapacity_real_T(b_ecg_hpf, i2);
          for (i2 = 0; i2 < k; i2++) {
            b_ecg_hpf->data[i2] = ecg_hpf[i1 + i2];
          }

          c_maximum(b_ecg_hpf, &qrs_i_idx, &diffRR_counter);
        } else {
          pks_temp = locs_temp - b_tmp_tmp;
          if (pks_temp > 30720.0) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = (int)pks_temp - 1;
            i2 = 30720;
          }

          k = i2 - i1;
          i2 = b_ecg_hpf->size[0];
          b_ecg_hpf->size[0] = k;
          emxEnsureCapacity_real_T(b_ecg_hpf, i2);
          for (i2 = 0; i2 < k; i2++) {
            b_ecg_hpf->data[i2] = ecg_hpf[i1 + i2];
          }

          c_maximum(b_ecg_hpf, &qrs_i_idx, &diffRR_counter);
        }

        /*  take care of bandpass signal threshold */
        if (qrs_i_idx > b_mean(b_varargin_1) / 2.0) {
          /*                      qrs_i_raw = [qrs_i_raw locs_temp-round(length_maw*fs)+ (x_i_t - 1)];% save index of bandpass */
          qrs_i_raw->data[qrs_c_couter] = (locs_temp - rt_roundd_snf(0.15 * fs))
            + ((double)diffRR_counter - 1.0);

          /*  save index of bandpass */
          /*                      qrs_amp_raw =[qrs_amp_raw y_i_t]; %save amplitude of bandpass */
          qrs_amp_raw->data[qrs_c_couter] = qrs_i_idx;

          /* save amplitude of bandpass */
          /* when found with the second thres */
        }

        /* when found with the second threshold */
      }
    }

    /* find noise and QRS peaks */
    if (pks->data[b_i] >= THR_SIG) {
      /*  if a QRS candidate occurs within 360ms of the previous QRS */
      /*  ,the algorithm determines if its T wave or QRS */
      /*          if length(qrs_c) >= 3 */
      guard1 = false;
      if ((qrs_c_couter + 1 >= 3) && (locs->data[b_i] - qrs_i_vec->
           data[qrs_c_couter] <= rt_roundd_snf(0.36 * fs))) {
        /*              if (locs(i)-qrs_i(end)) <= round(0.36*fs) */
        /*                 locs(i)-qrs_i(end) */
        /*              end */
        /*                  locs(i)-qrs_i_vec(qrs_c_couter) */
        pks_temp = rt_roundd_snf(0.075 * fs);
        qrs_i_idx = locs->data[b_i] - pks_temp;
        if (qrs_i_idx > locs->data[b_i]) {
          i1 = 0;
          i2 = 0;
        } else {
          i1 = (int)qrs_i_idx - 1;
          i2 = (int)locs->data[b_i];
        }

        /* mean slope of the waveform at that position */
        /*                  Slope2 = mean(diff(ecg_m(qrs_i(end)-round(0.075*fs):qrs_i(end)))); %mean slope of previous R wave */
        pks_temp = qrs_i_vec->data[qrs_c_couter] - pks_temp;
        if (pks_temp > qrs_i_vec->data[qrs_c_couter]) {
          diffRR_counter = 0;
          j = 0;
        } else {
          diffRR_counter = (int)pks_temp - 1;
          j = (int)qrs_i_vec->data[qrs_c_couter];
        }

        /* mean slope of previous R wave */
        /*                  if Slope2 ~= Slope2_b */
        /*                      Slope2 - Slope2_b  */
        /*                  end */
        k = i2 - i1;
        i2 = b_ecg_hpf->size[0];
        b_ecg_hpf->size[0] = k;
        emxEnsureCapacity_real_T(b_ecg_hpf, i2);
        for (i2 = 0; i2 < k; i2++) {
          b_ecg_hpf->data[i2] = ecg_lpf[i1 + i2];
        }

        b_diff(b_ecg_hpf, b_varargin_1);
        k = j - diffRR_counter;
        i1 = b_ecg_hpf->size[0];
        b_ecg_hpf->size[0] = k;
        emxEnsureCapacity_real_T(b_ecg_hpf, i1);
        for (i1 = 0; i1 < k; i1++) {
          b_ecg_hpf->data[i1] = ecg_lpf[diffRR_counter + i1];
        }

        b_diff(b_ecg_hpf, r);
        if (!(fabs(b_mean(b_varargin_1)) <= fabs(0.5 * b_mean(r)))) {
          guard1 = true;
        } else {
          /*  slope less then 0.5 of previous R */
          /*  T wave identification */
          /*  adjust noise level in both filtered and */
          /*  MVI */
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        /*  skip is 1 when a T wave is detected */
        /*              qrs_c = [qrs_c pks(i)]; */
        qrs_c_couter++;

        /*              qrs_i = [qrs_i locs(i)]; */
        qrs_i_vec->data[qrs_c_couter] = locs->data[b_i];

        /*  bandpass filter check threshold */
        if (y_i >= THR_SIG1) {
          if (ser_back != 0) {
            /*                      qrs_i_raw = [qrs_i_raw x_i];  % save index of bandpass */
            qrs_i_raw->data[qrs_c_couter] = x_i;
          } else {
            /*                      qrs_i_raw = [qrs_i_raw locs(i)-round(length_maw*fs)+ (x_i - 1)];% save index of bandpass */
            qrs_i_raw->data[qrs_c_couter] = d + ((double)x_i - 1.0);
          }

          /*                  qrs_amp_raw =[qrs_amp_raw y_i];% save amplitude of bandpass */
          qrs_amp_raw->data[qrs_c_couter] = y_i;

          /*  adjust threshold for bandpass filtered sig */
        }

        /*  adjust Signal level */
      }
    }

    /* adjust the threshold with SNR */
    /*  adjust the threshold with SNR for bandpassed signal */
    /* reset parameters */
    ser_back = 0;

    /* reset bandpass param */
  }

  emxFree_real_T(&r);
  emxFree_real_T(&varargin_1_tmp);
  emxFree_real_T(&b_varargin_1);
  emxFree_real_T(&qrs_i_vec);
  emxFree_real_T(&locs);
  emxFree_real_T(&pks);
  i = qrs_i_raw->size[0] * qrs_i_raw->size[1];
  i1 = qrs_i_raw->size[0] * qrs_i_raw->size[1];
  qrs_i_raw->size[0] = 1;
  emxEnsureCapacity_real_T(qrs_i_raw, i1);
  k = i - 1;
  for (i = 0; i <= k; i++) {
    qrs_i_raw->data[i] -= 21.0;
  }

  /*  Removing outliers  */
  /*  Rloc = []; */
  /*  Rloc_fixedSize = NaN(200,1); */
  qrs_i_raw_size[0] = qrs_i_raw->size[1];
  k = qrs_i_raw->size[1];
  for (i = 0; i < k; i++) {
    qrs_i_raw_data[i] = (qrs_i_raw->data[i] >= 1.0);
  }

  diffRR_counter = combineVectorElements(qrs_i_raw_data, qrs_i_raw_size);
  i = Rloc->size[0] * Rloc->size[1];
  Rloc->size[0] = 1;
  Rloc->size[1] = diffRR_counter;
  emxEnsureCapacity_real_T(Rloc, i);
  for (i = 0; i < diffRR_counter; i++) {
    Rloc->data[i] = 0.0;
  }

  idx_Rloc = 1U;
  i = qrs_i_raw->size[1];
  for (qrs_c_couter = 0; qrs_c_couter < i; qrs_c_couter++) {
    d = qrs_i_raw->data[qrs_c_couter];
    if (d - 20.0 >= 1.0) {
      if (d - 20.0 > d + 20.0) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (int)(d - 20.0) - 1;
        i2 = (int)(d + 20.0);
      }

      k = i2 - i1;
      i2 = b_ecg_hpf->size[0];
      b_ecg_hpf->size[0] = k;
      emxEnsureCapacity_real_T(b_ecg_hpf, i2);
      for (i2 = 0; i2 < k; i2++) {
        b_ecg_hpf->data[i2] = sig_short[i1 + i2];
      }

      c_maximum(b_ecg_hpf, &qrs_i_idx, &diffRR_counter);

      /*          Rloc = [Rloc (ind_R_1 - num - 1 + ind)]; */
      Rloc->data[(int)idx_Rloc - 1] = ((qrs_i_raw->data[qrs_c_couter] - 20.0) -
        1.0) + (double)diffRR_counter;
      idx_Rloc++;
    }
  }

  emxFree_real_T(&b_ecg_hpf);
  emxFree_real_T(&qrs_i_raw);
}

/* End of code generation (pan_tompkin_algorithm_segmented.c) */
