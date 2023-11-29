/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * features_Freq_calculator.c
 *
 * Code generation for function 'features_Freq_calculator'
 *
 */

/* Include files */
#include "features_Freq_calculator.h"
#include "bandpower.h"
#include "diff.h"
#include "find.h"
#include "plomb.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void features_Freq_calculator(const double tHRV_data[], const int tHRV_size[2],
  double HRV_data[], const int HRV_size[2], double idx5, double idx6, double
  idx7, double idx8, double Tot_pow_data[], int Tot_pow_size[2], double *nLF,
  double *nHF, double *LF_HF)
{
  static short b_tmp_data[400];
  emxArray_boolean_T *b_f;
  emxArray_real_T c_f;
  emxArray_real_T *W_diff;
  emxArray_real_T *colPxx;
  emxArray_real_T *f;
  emxArray_real_T *pxx;
  emxArray_real_T *width;
  double freqrange[2];
  double Freq_betw_04_15_data[1];
  double Freq_betw_15_40_data_idx_0;
  double d;
  double missingWidth;
  int Freq_betw_04_15_size[2];
  int c_tmp_data[1];
  int d_f[1];
  int idx_data[1];
  int idx_size[1];
  int b_i;
  int i;
  int i1;
  int idx;
  int j;
  int k;
  int n;
  int trueCount;
  boolean_T tmp_data[400];
  boolean_T x_data[1];
  boolean_T exitg1;
  boolean_T y;
  Tot_pow_size[0] = 1;
  Tot_pow_size[1] = 1;
  Tot_pow_data[0] = 0.0;
  *nLF = 0.0;
  *nHF = 0.0;
  *LF_HF = 0.0;
  if (HRV_size[1] > 1) {
    idx = HRV_size[0] * HRV_size[1];
    for (i = 0; i < idx; i++) {
      tmp_data[i] = rtIsInf(HRV_data[i]);
    }

    idx = HRV_size[1] - 1;
    trueCount = 0;
    n = 0;
    for (b_i = 0; b_i <= idx; b_i++) {
      if (tmp_data[b_i]) {
        trueCount++;
        b_tmp_data[n] = (short)(b_i + 1);
        n++;
      }
    }

    n = HRV_size[1];
    if (HRV_size[1] <= 2) {
      if ((HRV_data[0] > HRV_data[1]) || (rtIsNaN(HRV_data[0]) && (!rtIsNaN
            (HRV_data[1])))) {
        missingWidth = HRV_data[1];
      } else {
        missingWidth = HRV_data[0];
      }
    } else {
      if (!rtIsNaN(HRV_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= HRV_size[1])) {
          if (!rtIsNaN(HRV_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        missingWidth = HRV_data[0];
      } else {
        missingWidth = HRV_data[idx - 1];
        i = idx + 1;
        for (k = i; k <= n; k++) {
          d = HRV_data[k - 1];
          if (missingWidth > d) {
            missingWidth = d;
          }
        }
      }
    }

    idx = trueCount - 1;
    for (i = 0; i <= idx; i++) {
      HRV_data[b_tmp_data[i] - 1] = missingWidth;
    }

    emxInit_real_T(&pxx, 2);
    emxInit_real_T(&f, 2);
    plomb(HRV_data, HRV_size, tHRV_data, tHRV_size, pxx, f);

    /* Tot_pow */
    /*      Tot_pow = bandpower(pxx, f, 'psd'); */
    if (idx5 != -1.0) {
      emxInit_real_T(&colPxx, 2);
      i = colPxx->size[0] * colPxx->size[1];
      colPxx->size[0] = pxx->size[0];
      colPxx->size[1] = pxx->size[1];
      emxEnsureCapacity_real_T(colPxx, i);
      idx = pxx->size[0] * pxx->size[1];
      for (i = 0; i < idx; i++) {
        colPxx->data[i] = pxx->data[i];
      }

      if (pxx->size[0] == 1) {
        i = colPxx->size[0] * colPxx->size[1];
        colPxx->size[0] = pxx->size[0] * pxx->size[1];
        colPxx->size[1] = 1;
        emxEnsureCapacity_real_T(colPxx, i);
        idx = pxx->size[0] * pxx->size[1];
        for (i = 0; i < idx; i++) {
          colPxx->data[i] = pxx->data[i];
        }
      }

      emxInit_boolean_T(&b_f, 1);
      freqrange[0] = f->data[0];
      freqrange[1] = f->data[f->size[0] - 1];
      i = b_f->size[0];
      b_f->size[0] = f->size[0];
      emxEnsureCapacity_boolean_T(b_f, i);
      idx = f->size[0];
      for (i = 0; i < idx; i++) {
        b_f->data[i] = (f->data[i] <= freqrange[0]);
      }

      b_eml_find(b_f, c_tmp_data, idx_data);
      i = b_f->size[0];
      b_f->size[0] = f->size[0];
      emxEnsureCapacity_boolean_T(b_f, i);
      idx = f->size[0];
      for (i = 0; i < idx; i++) {
        b_f->data[i] = (f->data[i] >= freqrange[1]);
      }

      emxInit_real_T(&width, 1);
      emxInit_real_T(&W_diff, 1);
      c_eml_find(b_f, idx_data, idx_size);
      idx = f->size[0];
      c_f = *f;
      d_f[0] = idx;
      c_f.size = &d_f[0];
      c_f.numDimensions = 1;
      b_diff(&c_f, W_diff);
      missingWidth = (f->data[f->size[0] - 1] - f->data[0]) / ((double)f->size[0]
        - 1.0);
      emxFree_boolean_T(&b_f);
      if (f->data[0] != 0.0) {
        i = width->size[0];
        width->size[0] = W_diff->size[0] + 1;
        emxEnsureCapacity_real_T(width, i);
        width->data[0] = missingWidth;
        idx = W_diff->size[0];
        for (i = 0; i < idx; i++) {
          width->data[i + 1] = W_diff->data[i];
        }
      } else {
        i = width->size[0];
        width->size[0] = W_diff->size[0] + 1;
        emxEnsureCapacity_real_T(width, i);
        idx = W_diff->size[0];
        for (i = 0; i < idx; i++) {
          width->data[i] = W_diff->data[i];
        }

        width->data[W_diff->size[0]] = missingWidth;
      }

      emxFree_real_T(&W_diff);
      if (c_tmp_data[0] > idx_data[0]) {
        i = 0;
        n = 0;
        b_i = 0;
        i1 = 0;
      } else {
        i = c_tmp_data[0] - 1;
        n = idx_data[0];
        b_i = c_tmp_data[0] - 1;
        i1 = idx_data[0];
      }

      idx = n - i;
      n = colPxx->size[1] - 1;
      Tot_pow_size[0] = 1;
      Tot_pow_size[1] = colPxx->size[1];
      for (j = 0; j <= n; j++) {
        Tot_pow_data[0] = 0.0;
        for (k = 0; k < idx; k++) {
          trueCount = i1 - b_i;
          Tot_pow_data[0] += width->data[i + k] * colPxx->data[(b_i + k %
            trueCount) + colPxx->size[0] * (k / trueCount)];
        }
      }

      emxFree_real_T(&width);
      emxFree_real_T(&colPxx);
    } else {
      Tot_pow_size[0] = 1;
      Tot_pow_size[1] = 1;
      Tot_pow_data[0] = rtNaN;
    }

    /* VLF */
    /* if f(1)>=0.04 */
    /*     Freq_less_04=0; */
    /* else */
    /*     Freq_less_04 = bandpower(pxx, f, [f(1) , 0.04], 'psd'); */
    /* end */
    /* nVLF  = Freq_less_04/Tot_pow; */
    /* LF */
    if ((idx6 != -1.0) || (idx7 != -1.0)) {
      /*      Freq_betw_04_15 = bandpower(pxx, f, [max(0.04,f(1)) min(0.15,f(end))], 'psd'); */
      /*      nLF = Freq_betw_04_15/Tot_pow; */
      if (idx6 != -1.0) {
        freqrange[0] = fmax(0.04, f->data[0]);
        freqrange[1] = fmin(0.15, f->data[f->size[0] - 1]);
        bandpower(pxx, f, freqrange, Freq_betw_04_15_data, Freq_betw_04_15_size);
        n = Tot_pow_size[1];
        idx = Tot_pow_size[1];
        for (i = 0; i < idx; i++) {
          x_data[i] = (Tot_pow_data[i] != 0.0);
        }

        y = (Tot_pow_size[1] != 0);
        if (y) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k <= n - 1)) {
            if (!x_data[0]) {
              y = false;
              exitg1 = true;
            } else {
              k = 1;
            }
          }
        }

        if (y) {
          *nLF = Freq_betw_04_15_data[0] / Tot_pow_data[0];
        } else {
          *nLF = rtNaN;
        }

        missingWidth = Freq_betw_04_15_data[0];
      } else {
        *nLF = rtNaN;
        missingWidth = 0.0;
      }

      /* HF */
      if (idx7 != -1.0) {
        if (f->data[f->size[0] - 1] <= 0.4) {
          Freq_betw_15_40_data_idx_0 = 0.0;
          n = Tot_pow_size[1];
          idx = Tot_pow_size[1];
          for (i = 0; i < idx; i++) {
            x_data[i] = (Tot_pow_data[i] == 0.0);
          }

          y = (Tot_pow_size[1] != 0);
          if (y) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k <= n - 1)) {
              if (!x_data[0]) {
                y = false;
                exitg1 = true;
              } else {
                k = 1;
              }
            }
          }

          if (y) {
            *nHF = rtNaN;
          } else {
            *nHF = 0.0 / Tot_pow_data[0];
          }
        } else {
          /*          Freq_betw_15_40 = bandpower(pxx, f, freq_range, 'psd'); */
          freqrange[0] = 0.15;
          freqrange[1] = fmin(0.4, f->data[f->size[0] - 1]);
          bandpower(pxx, f, freqrange, Freq_betw_04_15_data,
                    Freq_betw_04_15_size);
          idx = Freq_betw_04_15_size[0] * Freq_betw_04_15_size[1];
          for (i = 0; i < idx; i++) {
            Freq_betw_15_40_data_idx_0 = Freq_betw_04_15_data[i];
          }

          n = Tot_pow_size[1];
          idx = Tot_pow_size[1];
          for (i = 0; i < idx; i++) {
            x_data[i] = (Tot_pow_data[i] == 0.0);
          }

          y = (Tot_pow_size[1] != 0);
          if (y) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k <= n - 1)) {
              if (!x_data[0]) {
                y = false;
                exitg1 = true;
              } else {
                k = 1;
              }
            }
          }

          if (y) {
            *nHF = rtNaN;
          } else {
            *nHF = Freq_betw_15_40_data_idx_0 / Tot_pow_data[0];
          }
        }

        /*      Freq_betw_15_40 = bandpower(pxx, f, freq_range, type); */
        /*      nHF = Freq_betw_15_40/Tot_pow; */
      } else {
        *nHF = rtNaN;
        Freq_betw_15_40_data_idx_0 = 0.0;
      }

      /*      if f(end)<=0.4 */
      /*          Freq_betw_15_40=0; */
      /*          nHF = Freq_betw_15_40/Tot_pow; */
      /*      else */
      /*          freq_range = [ 0.15 min(0.4, f(end))]; */
      /*  %         Freq_betw_15_40 = bandpower(pxx, f, freq_range, 'psd'); */
      /*          [nHF, Freq_betw_15_40] = Feature7(pxx, f, freq_range, 'psd', Tot_pow); */
      /*      end */
      /*      nHF = Freq_betw_15_40/Tot_pow; */
      /*      nHF = Feature7(Freq_betw_15_40,Tot_pow); */
      /* LF_HF */
      /*      LF_HF=Freq_betw_04_15/Freq_betw_15_40; */
      if (idx8 != -1.0) {
        *LF_HF = missingWidth / Freq_betw_15_40_data_idx_0;
      } else {
        *LF_HF = rtNaN;
      }
    } else {
      *nLF = rtNaN;
      *nHF = rtNaN;
      *LF_HF = rtNaN;
    }

    emxFree_real_T(&f);
    emxFree_real_T(&pxx);
  }
}

/* End of code generation (features_Freq_calculator.c) */
