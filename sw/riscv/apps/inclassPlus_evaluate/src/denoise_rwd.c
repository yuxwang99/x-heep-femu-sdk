/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * denoise_rwd.c
 *
 * Code generation for function 'denoise_rwd'
 *
 */

/* Include files */
#include "denoise_rwd.h"
#include "minOrMax.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void dilation(const double inputECG[30720], double windowSize, double
                     outputECG[30720]);
static void erosion(const double inputECG[30720], double windowSize, double
                    outputECG[30720]);

/* Function Definitions */
static void dilation(const double inputECG[30720], double windowSize, double
                     outputECG[30720])
{
  emxArray_real_T *b_inputECG;
  double after;
  double before_tmp;
  double c_i;
  double d;
  double d1;
  int b_i;
  int i;
  int i1;
  int i2;
  int loop_ub;
  memset(&outputECG[0], 0, 30720U * sizeof(double));
  before_tmp = floor(windowSize / 2.0);
  after = windowSize - before_tmp;
  i = (int)((30720.0 - after) + (1.0 - (before_tmp + 1.0)));
  emxInit_real_T(&b_inputECG, 1);
  for (b_i = 0; b_i < i; b_i++) {
    c_i = (before_tmp + 1.0) + (double)b_i;
    d = c_i - before_tmp;
    d1 = c_i + after;
    if (d > d1) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = (int)d - 1;
      i2 = (int)d1;
    }

    loop_ub = i2 - i1;
    i2 = b_inputECG->size[0];
    b_inputECG->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_inputECG, i2);
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_inputECG->data[i2] = inputECG[i1 + i2];
    }

    outputECG[(int)c_i - 1] = maximum(b_inputECG);
  }

  emxFree_real_T(&b_inputECG);
}

static void erosion(const double inputECG[30720], double windowSize, double
                    outputECG[30720])
{
  double after;
  double before_tmp;
  double c_i;
  double d;
  double ex;
  int b_i;
  int i;
  int i1;
  int idx;
  int k;
  int n_tmp;
  boolean_T exitg1;
  memset(&outputECG[0], 0, 30720U * sizeof(double));
  before_tmp = floor(windowSize / 2.0);
  after = windowSize - before_tmp;
  i = (int)((30720.0 - after) + (1.0 - (before_tmp + 1.0)));
  for (b_i = 0; b_i < i; b_i++) {
    c_i = (before_tmp + 1.0) + (double)b_i;
    d = c_i - before_tmp;
    ex = c_i + after;
    if (d > ex) {
      i1 = 0;
      idx = 0;
    } else {
      i1 = (int)d - 1;
      idx = (int)ex;
    }

    n_tmp = idx - i1;
    if (n_tmp <= 2) {
      if (n_tmp == 1) {
        outputECG[(int)c_i - 1] = inputECG[i1];
      } else {
        d = inputECG[i1 + 1];
        if ((inputECG[i1] > d) || (rtIsNaN(inputECG[i1]) && (!rtIsNaN(d)))) {
          outputECG[(int)c_i - 1] = d;
        } else {
          outputECG[(int)c_i - 1] = inputECG[i1];
        }
      }
    } else {
      if (!rtIsNaN(inputECG[i1])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= n_tmp)) {
          if (!rtIsNaN(inputECG[(i1 + k) - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        outputECG[(int)c_i - 1] = inputECG[i1];
      } else {
        ex = inputECG[(i1 + idx) - 1];
        idx++;
        for (k = idx; k <= n_tmp; k++) {
          d = inputECG[(i1 + k) - 1];
          if (ex > d) {
            ex = d;
          }
        }

        outputECG[(int)c_i - 1] = ex;
      }
    }
  }
}

void denoise_rwd(const double ECG[30720], double BWwindow, double filteredECG
                 [30720])
{
  static double dv[30720];
  static double dv1[30720];
  double before;
  double before_tmp_tmp;
  int i;
  int loop_ub;

  /* denoise_RWD(ECG,fs,BWremoval,BWwindow,HFNremoval,LF,HF), where: */
  /*    ECG = input ECG signal at 500Hz */
  /*    fs = output sampling frequency */
  /*    BWremoval = baseline wander removal (1: enabled, 0: disabled) */
  /*    BWwindow = size of the structuring element for baseline wander removal */
  /*    - usually fs/5. */
  /*    HFNremoval = high-frequency noise removal (1: enabled, 0: disabled) */
  /*    LF = lower cutoff frequency of the band-pass filter */
  /*    HF = upper cutoff frequency of the band-pass filter */
  /*     */
  /* This function processes the input ECG signal, applying a morphological */
  /* filter to remove baseline wander and a band-pass filter to remove high */
  /* frequency noise */
  /* tamaÃ±o de la ventana del filtro de mediana de la BWcancell (sg) */
  /* Orden del filtro paso bajo */
  /*  Eliminamos la linea de base */
  before_tmp_tmp = floor(BWwindow * 1.5);
  before = floor(BWwindow / 2.0) * 2.0 + floor(before_tmp_tmp / 2.0) * 2.0;
  erosion(ECG, BWwindow, dv);
  dilation(dv, BWwindow, dv1);
  dilation(dv1, before_tmp_tmp, dv);
  erosion(dv, before_tmp_tmp, filteredECG);
  for (i = 0; i < 30720; i++) {
    filteredECG[i] = ECG[i] - filteredECG[i];
  }

  if (1.0 > before) {
    loop_ub = 0;
  } else {
    loop_ub = (int)before;
  }

  if (0 <= loop_ub - 1) {
    memset(&filteredECG[0], 0, loop_ub * sizeof(double));
  }

  before_tmp_tmp = 30720.0 - ((BWwindow * 2.0 + before_tmp_tmp * 2.0) - before);
  if (before_tmp_tmp > 30720.0) {
    i = -1;
    loop_ub = -1;
  } else {
    i = (int)before_tmp_tmp - 2;
    loop_ub = 30719;
  }

  loop_ub -= i;
  if (0 <= loop_ub - 1) {
    memset(&filteredECG[i + 1], 0, ((loop_ub + i) - i) * sizeof(double));
  }

  /*  Filter */
  /* FPB orden 32 y fc = 25 Hz para eliminar el ruido de alta frec. */
  /* La frecuencia de corte del filtro hay que pasarsela normalizada. */
  /* Toma valores entre 0 y 1 donde 1 corresponde a Fnyquist = fs/2. */
  /* aux = filtfilt(B,1,aux); removed for C coder */
}

/* End of code generation (denoise_rwd.c) */
