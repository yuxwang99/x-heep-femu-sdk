/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plomb.c
 *
 * Code generation for function 'plomb'
 *
 */

/* Include files */
#include "plomb.h"
#include "colon.h"
#include "cospi.h"
#include "fft.h"
#include "find.h"
#include "minOrMax.h"
#include "mod.h"
#include "mrdivide_helper.h"
#include "nullAssignment.h"
#include "profile_Yuxuan_iteration_data.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_rtwutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include "sinpi.h"
#include "strcmp.h"
#include "unique.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T_1x400
#define struct_emxArray_real_T_1x400

struct emxArray_real_T_1x400
{
  double data[400];
  int size[2];
};

#endif                                 /*struct_emxArray_real_T_1x400*/

#ifndef typedef_emxArray_real_T_1x400
#define typedef_emxArray_real_T_1x400

typedef struct emxArray_real_T_1x400 emxArray_real_T_1x400;

#endif                                 /*typedef_emxArray_real_T_1x400*/

#ifndef typedef_cell_wrap_55
#define typedef_cell_wrap_55

typedef struct {
  emxArray_real_T_1x400 f1;
} cell_wrap_55;

#endif                                 /*typedef_cell_wrap_55*/

/* Function Declarations */
static void MarkMissingData(const double x_data[], const int x_size[1], const
  emxArray_real_T *t, double f_data[], int f_size[2], const double ofac_data[],
  const int ofac_size[2], const char spectrumtype[3], const char freqtype_data[],
  const int freqtype_size[2], double Fs, double Ch_SigAndTNanPos_data[], int
  Ch_SigAndTNanPos_size[2], boolean_T *Ch_NanFlag, double *Ch_SigMean, double
  *Ch_SigVar, double *Ch_Alpha, double *Ch_n);
static double b_lombscargle(const emxArray_real_T *x, double f, const
  emxArray_real_T *t);
static void fasper(const emxArray_real_T *x, const emxArray_real_T *t, const
                   double f_data[], const int f_size[2], emxArray_real_T *wk2,
                   emxArray_real_T *f);
static void lombscargle(const emxArray_real_T *x, const emxArray_real_T *f,
  const emxArray_real_T *t, emxArray_real_T *P);
static void parseAndCacheTimeVector(const cell_wrap_55 arglist[1], boolean_T
  *ignoreArgsIdx, double t_data[], int t_size[2], boolean_T *tflag, double
  Fs_data[], int Fs_size[2]);
static void parseAndValidateInputs(const double x_data[], const int x_size[2],
  const cell_wrap_55 arglist[1], double x1_data[], int x1_size[1],
  emxArray_real_T *t, int f_size[2], double ofac_data[], int ofac_size[2], char
  spectrumtype[3], char freqtype_data[], int freqtype_size[2], boolean_T *tflag,
  int ProbDet_size[2], double *Fs, boolean_T *fvecSpecified);
static double rt_atan2d_snf(double u0, double u1);
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */
static void MarkMissingData(const double x_data[], const int x_size[1], const
  emxArray_real_T *t, double f_data[], int f_size[2], const double ofac_data[],
  const int ofac_size[2], const char spectrumtype[3], const char freqtype_data[],
  const int freqtype_size[2], double Fs, double Ch_SigAndTNanPos_data[], int
  Ch_SigAndTNanPos_size[2], boolean_T *Ch_NanFlag, double *Ch_SigMean, double
  *Ch_SigVar, double *Ch_Alpha, double *Ch_n)
{
  static double sig_data[400];
  static int b_Ch_SigAndTNanPos_data[400];
  static short b_tmp_data[400];
  static short c_tmp_data[400];
  static const char b_cv1[8] = { 'r', 'a', 'd', '/', 's', 'a', 'm', 'p' };

  static const char b_cv[3] = { 'p', 's', 'd' };

  emxArray_boolean_T *r;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_real_T *a_tmp;
  emxArray_real_T *b;
  emxArray_real_T *b_y;
  emxArray_real_T *r3;
  emxArray_real_T *r4;
  emxArray_real_T *temp;
  emxArray_real_T *x;
  emxArray_real_T *y;
  double nout_data[1];
  double a;
  double b_t;
  double ex_data_idx_0;
  double xbar;
  int a_size[2];
  int b_Ch_SigAndTNanPos_size[2];
  int exitg2;
  int loop_ub;
  int n;
  int sig_size_idx_0;
  int trueCount;
  int x_size_idx_1;
  boolean_T tmp_data[400];
  boolean_T b_bool;
  boolean_T exitg1;
  emxInit_boolean_T(&r, 1);
  Ch_SigAndTNanPos_size[0] = 1;
  Ch_SigAndTNanPos_size[1] = (short)x_size[0];
  x_size_idx_1 = r->size[0];
  r->size[0] = t->size[0] * t->size[1];
  emxEnsureCapacity_boolean_T(r, x_size_idx_1);
  loop_ub = t->size[0] * t->size[1];
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    r->data[x_size_idx_1] = rtIsNaN(t->data[x_size_idx_1]);
  }

  emxInit_int32_T(&r1, 1);
  eml_find(r, r1);
  loop_ub = x_size[0];
  x_size_idx_1 = r->size[0];
  r->size[0] = x_size[0];
  emxEnsureCapacity_boolean_T(r, x_size_idx_1);
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    r->data[x_size_idx_1] = rtIsNaN(x_data[x_size_idx_1]);
  }

  emxInit_real_T(&a_tmp, 1);
  emxInit_int32_T(&r2, 1);
  eml_find(r, r2);
  x_size_idx_1 = a_tmp->size[0];
  a_tmp->size[0] = r1->size[0] + r2->size[0];
  emxEnsureCapacity_real_T(a_tmp, x_size_idx_1);
  loop_ub = r1->size[0];
  emxFree_boolean_T(&r);
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    a_tmp->data[x_size_idx_1] = r1->data[x_size_idx_1];
  }

  loop_ub = r2->size[0];
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    a_tmp->data[x_size_idx_1 + r1->size[0]] = r2->data[x_size_idx_1];
  }

  emxFree_int32_T(&r2);
  emxFree_int32_T(&r1);
  emxInit_real_T(&r3, 1);
  emxInit_real_T(&b, 1);
  b_unique_vector(a_tmp, b);
  n = b->size[0];
  b_unique_vector(a_tmp, b);
  x_size_idx_1 = r3->size[0];
  r3->size[0] = (b->size[0] + (short)x_size[0]) - n;
  emxEnsureCapacity_real_T(r3, x_size_idx_1);
  loop_ub = b->size[0];
  emxFree_real_T(&a_tmp);
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    r3->data[x_size_idx_1] = b->data[x_size_idx_1];
  }

  loop_ub = (short)x_size[0] - n;
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    r3->data[x_size_idx_1 + b->size[0]] = 0.0;
  }

  emxFree_real_T(&b);
  loop_ub = (short)x_size[0];
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    Ch_SigAndTNanPos_data[x_size_idx_1] = r3->data[x_size_idx_1];
  }

  emxFree_real_T(&r3);
  loop_ub = (short)x_size[0];
  x_size_idx_1 = (short)x_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&sig_data[0], &Ch_SigAndTNanPos_data[0], loop_ub * sizeof(double));
  }

  *Ch_NanFlag = false;
  n = 0;
  exitg1 = false;
  while ((!exitg1) && (n + 1 <= x_size_idx_1)) {
    if ((sig_data[n] == 0.0) || rtIsNaN(sig_data[n])) {
      n++;
    } else {
      *Ch_NanFlag = true;
      exitg1 = true;
    }
  }

  loop_ub = (short)x_size[0];
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    tmp_data[x_size_idx_1] = (Ch_SigAndTNanPos_data[x_size_idx_1] > 0.0);
  }

  x_size_idx_1 = (short)x_size[0] - 1;
  trueCount = 0;
  n = 0;
  for (loop_ub = 0; loop_ub <= x_size_idx_1; loop_ub++) {
    if (tmp_data[loop_ub]) {
      trueCount++;
      b_tmp_data[n] = (short)(loop_ub + 1);
      n++;
    }
  }

  emxInit_real_T(&r4, 1);
  loop_ub = x_size[0];
  x_size_idx_1 = r4->size[0];
  r4->size[0] = x_size[0];
  emxEnsureCapacity_real_T(r4, x_size_idx_1);
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    r4->data[x_size_idx_1] = x_data[x_size_idx_1];
  }

  b_Ch_SigAndTNanPos_size[0] = 1;
  b_Ch_SigAndTNanPos_size[1] = trueCount;
  for (x_size_idx_1 = 0; x_size_idx_1 < trueCount; x_size_idx_1++) {
    b_Ch_SigAndTNanPos_data[x_size_idx_1] = (int)
      Ch_SigAndTNanPos_data[b_tmp_data[x_size_idx_1] - 1];
  }

  b_nullAssignment(r4, b_Ch_SigAndTNanPos_data, b_Ch_SigAndTNanPos_size);
  sig_size_idx_0 = r4->size[0];
  loop_ub = r4->size[0];
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    sig_data[x_size_idx_1] = r4->data[x_size_idx_1];
  }

  emxFree_real_T(&r4);
  *Ch_n = sig_size_idx_0;
  loop_ub = (short)x_size[0];
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    tmp_data[x_size_idx_1] = (Ch_SigAndTNanPos_data[x_size_idx_1] > 0.0);
  }

  x_size_idx_1 = (short)x_size[0] - 1;
  trueCount = 0;
  n = 0;
  for (loop_ub = 0; loop_ub <= x_size_idx_1; loop_ub++) {
    if (tmp_data[loop_ub]) {
      trueCount++;
      c_tmp_data[n] = (short)(loop_ub + 1);
      n++;
    }
  }

  emxInit_real_T(&temp, 2);
  x_size_idx_1 = temp->size[0] * temp->size[1];
  temp->size[0] = t->size[0];
  temp->size[1] = t->size[1];
  emxEnsureCapacity_real_T(temp, x_size_idx_1);
  loop_ub = t->size[0] * t->size[1];
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    temp->data[x_size_idx_1] = t->data[x_size_idx_1];
  }

  b_Ch_SigAndTNanPos_size[0] = 1;
  b_Ch_SigAndTNanPos_size[1] = trueCount;
  for (x_size_idx_1 = 0; x_size_idx_1 < trueCount; x_size_idx_1++) {
    b_Ch_SigAndTNanPos_data[x_size_idx_1] = (int)
      Ch_SigAndTNanPos_data[c_tmp_data[x_size_idx_1] - 1];
  }

  c_nullAssignment(temp, b_Ch_SigAndTNanPos_data, b_Ch_SigAndTNanPos_size);
  n = temp->size[0] * temp->size[1];
  trueCount = ofac_size[0] * ofac_size[1];
  for (x_size_idx_1 = 0; x_size_idx_1 < trueCount; x_size_idx_1++) {
    nout_data[x_size_idx_1] = 0.5 * ofac_data[x_size_idx_1] * (double)n;
  }

  x_size_idx_1 = (signed char)ofac_size[0] * (signed char)ofac_size[1];
  for (loop_ub = 0; loop_ub < x_size_idx_1; loop_ub++) {
    nout_data[0] = rt_roundd_snf(nout_data[0]);
  }

  emxInit_real_T(&y, 2);
  if (rtIsNaN(nout_data[0])) {
    x_size_idx_1 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, x_size_idx_1);
    y->data[0] = rtNaN;
  } else if (nout_data[0] < 1.0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (rtIsInf(nout_data[0]) && (1.0 == nout_data[0])) {
    x_size_idx_1 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, x_size_idx_1);
    y->data[0] = rtNaN;
  } else {
    x_size_idx_1 = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = (int)floor(nout_data[0] - 1.0);
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(y, x_size_idx_1);
    for (x_size_idx_1 = 0; x_size_idx_1 <= loop_ub; x_size_idx_1++) {
      y->data[x_size_idx_1] = (double)x_size_idx_1 + 1.0;
    }
  }

  emxInit_real_T(&b_y, 1);
  a = (double)n * ((temp->data[temp->size[0] * temp->size[1] - 1] - temp->data[0])
                   / ((double)n - 1.0));
  x_size_idx_1 = b_y->size[0];
  b_y->size[0] = y->size[1];
  emxEnsureCapacity_real_T(b_y, x_size_idx_1);
  loop_ub = y->size[1];
  emxFree_real_T(&temp);
  for (x_size_idx_1 = 0; x_size_idx_1 < loop_ub; x_size_idx_1++) {
    b_y->data[x_size_idx_1] = y->data[x_size_idx_1];
  }

  emxFree_real_T(&y);
  a_size[0] = ofac_size[0];
  a_size[1] = ofac_size[1];
  for (x_size_idx_1 = 0; x_size_idx_1 < trueCount; x_size_idx_1++) {
    nout_data[x_size_idx_1] = a * ofac_data[x_size_idx_1];
  }

  emxInit_real_T(&x, 2);
  mrdiv(b_y, nout_data, a_size, x);
  n = x->size[0];
  emxFree_real_T(&b_y);
  if (x->size[1] >= 1) {
    ex_data_idx_0 = x->data[0];
    for (loop_ub = 2; loop_ub <= n; loop_ub++) {
      a = x->data[loop_ub - 1];
      if ((!rtIsNaN(a)) && (rtIsNaN(ex_data_idx_0) || (ex_data_idx_0 < a))) {
        ex_data_idx_0 = a;
      }
    }
  }

  emxFree_real_T(&x);
  if (sig_size_idx_0 == 0) {
    a = 0.0;
  } else {
    a = sig_data[0];
    for (loop_ub = 2; loop_ub <= sig_size_idx_0; loop_ub++) {
      a += sig_data[loop_ub - 1];
    }
  }

  *Ch_SigMean = a / (double)sig_size_idx_0;
  if (sig_size_idx_0 == 1) {
    if ((!rtIsInf(sig_data[0])) && (!rtIsNaN(sig_data[0]))) {
      *Ch_SigVar = 0.0;
    } else {
      *Ch_SigVar = rtNaN;
    }
  } else {
    if (sig_size_idx_0 == 0) {
      xbar = 0.0;
    } else {
      xbar = sig_data[0];
      for (loop_ub = 2; loop_ub <= sig_size_idx_0; loop_ub++) {
        xbar += sig_data[loop_ub - 1];
      }
    }

    xbar /= (double)sig_size_idx_0;
    a = 0.0;
    for (loop_ub = 0; loop_ub < sig_size_idx_0; loop_ub++) {
      b_t = sig_data[loop_ub] - xbar;
      a += b_t * b_t;
    }

    *Ch_SigVar = a / ((double)sig_size_idx_0 - 1.0);
  }

  *Ch_Alpha = 1.0;
  b_bool = false;
  n = 0;
  do {
    exitg2 = 0;
    if (n < 3) {
      if (cv[(unsigned char)spectrumtype[n]] != cv[(int)b_cv[n]]) {
        exitg2 = 1;
      } else {
        n++;
      }
    } else {
      b_bool = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_bool) {
    b_bool = false;
    if (freqtype_size[1] == 8) {
      n = 0;
      do {
        exitg2 = 0;
        if (n < 8) {
          if (cv[(unsigned char)freqtype_data[n]] != cv[(int)b_cv1[n]]) {
            exitg2 = 1;
          } else {
            n++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (b_bool) {
      *Ch_Alpha = 3.1415926535897931 / *Ch_SigVar;
    } else {
      *Ch_Alpha = Fs / (2.0 * *Ch_SigVar);
    }
  }

  if (*Ch_NanFlag) {
    f_size[0] = 1;
    f_size[1] = 1;
    f_data[0] = ex_data_idx_0;
  }
}

static double b_lombscargle(const emxArray_real_T *x, double f, const
  emxArray_real_T *t)
{
  emxArray_real_T *cwt;
  emxArray_real_T *swttau;
  emxArray_real_T *t1;
  emxArray_real_T *y;
  double b_x;
  double cwtau;
  double swtau;
  double wtau;
  int i;
  int loop_ub;
  emxInit_real_T(&t1, 1);
  if (t->size[0] == 1) {
    i = t1->size[0];
    t1->size[0] = 1;
    emxEnsureCapacity_real_T(t1, i);
    t1->data[0] = t->data[0];
  } else {
    i = t1->size[0];
    t1->size[0] = t->size[0];
    emxEnsureCapacity_real_T(t1, i);
    loop_ub = t->size[0];
    for (i = 0; i < loop_ub; i++) {
      t1->data[i] = t->data[i];
    }
  }

  emxInit_real_T(&y, 1);
  wtau = 2.0 * f;
  i = y->size[0];
  y->size[0] = t1->size[0];
  emxEnsureCapacity_real_T(y, i);
  loop_ub = t1->size[0];
  for (i = 0; i < loop_ub; i++) {
    y->data[i] = wtau * t1->data[i];
  }

  emxInit_real_T(&cwt, 1);
  sinpi(y, t1);
  cospi(y, cwt);
  wtau = 0.0;
  loop_ub = cwt->size[0];
  emxFree_real_T(&y);
  for (i = 0; i < loop_ub; i++) {
    wtau += 2.0 * cwt->data[i] * t1->data[i];
  }

  cwtau = 0.0;
  loop_ub = cwt->size[0];
  for (i = 0; i < loop_ub; i++) {
    cwtau += (cwt->data[i] - t1->data[i]) * (cwt->data[i] + t1->data[i]);
  }

  emxInit_real_T(&swttau, 1);
  wtau = 0.5 * rt_atan2d_snf(wtau, cwtau);
  swtau = sin(wtau);
  cwtau = cos(wtau);
  i = swttau->size[0];
  swttau->size[0] = t1->size[0];
  emxEnsureCapacity_real_T(swttau, i);
  loop_ub = t1->size[0];
  for (i = 0; i < loop_ub; i++) {
    swttau->data[i] = t1->data[i] * cwtau - cwt->data[i] * swtau;
  }

  loop_ub = cwt->size[0];
  for (i = 0; i < loop_ub; i++) {
    cwt->data[i] = cwt->data[i] * cwtau + t1->data[i] * swtau;
  }

  emxFree_real_T(&t1);
  wtau = 0.0;
  loop_ub = swttau->size[0];
  for (i = 0; i < loop_ub; i++) {
    wtau += swttau->data[i] * swttau->data[i];
  }

  cwtau = 0.0;
  loop_ub = cwt->size[0];
  for (i = 0; i < loop_ub; i++) {
    cwtau += cwt->data[i] * cwt->data[i];
  }

  if (fabs(wtau) < 2.2204460492503131E-16) {
    wtau += 2.2204460492503131E-16;
  }

  if (fabs(cwtau) < 2.2204460492503131E-16) {
    cwtau += 2.2204460492503131E-16;
  }

  swtau = 0.0;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    swtau += x->data[i] * cwt->data[i];
  }

  emxFree_real_T(&cwt);
  b_x = 0.0;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_x += x->data[i] * swttau->data[i];
  }

  emxFree_real_T(&swttau);
  return swtau * swtau / cwtau + b_x * b_x / wtau;
}

static void fasper(const emxArray_real_T *x, const emxArray_real_T *t, const
                   double f_data[], const int f_size[2], emxArray_real_T *wk2,
                   emxArray_real_T *f)
{
  emxArray_boolean_T *c_x;
  emxArray_creal_T *b_wk1;
  emxArray_real_T *b_y;
  emxArray_real_T *cwt;
  emxArray_real_T *d_x;
  emxArray_real_T *hc2wt;
  emxArray_real_T *iwk1;
  emxArray_real_T *iwk2;
  emxArray_real_T *rwk1;
  emxArray_real_T *rwk2;
  emxArray_real_T *swt;
  emxArray_real_T *wk1;
  emxArray_real_T *y;
  double dv[2];
  double Ts;
  double b_t;
  double b_x;
  double ck;
  double fac;
  double fndim;
  double hifac;
  double ilo;
  double ndenl;
  double nout;
  int eint;
  int i;
  int size_tmp_idx_1;
  int vlen;
  boolean_T c_y;
  boolean_T exitg1;
  Ts = (t->data[t->size[0] - 1] - t->data[0]) / ((double)t->size[0] - 1.0);
  emxInit_real_T(&rwk2, 1);
  emxInit_real_T(&y, 2);
  if (f_size[0] * f_size[1] == 1) {
    nout = 2.0 * (double)t->size[0];
    if (nout < 1.0) {
      size_tmp_idx_1 = 0;
      y->size[0] = 1;
      y->size[1] = 0;
    } else {
      vlen = (int)(nout - 1.0);
      size_tmp_idx_1 = (int)(nout - 1.0) + 1;
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = (int)(nout - 1.0) + 1;
      emxEnsureCapacity_real_T(y, i);
      for (i = 0; i <= vlen; i++) {
        y->data[i] = (double)i + 1.0;
      }
    }

    i = rwk2->size[0];
    rwk2->size[0] = y->size[1];
    emxEnsureCapacity_real_T(rwk2, i);
    vlen = y->size[1];
    for (i = 0; i < vlen; i++) {
      rwk2->data[i] = y->data[i];
    }

    emxInit_real_T(&b_y, 1);
    b_t = (double)t->size[0] * Ts * 4.0;
    i = b_y->size[0];
    b_y->size[0] = size_tmp_idx_1;
    emxEnsureCapacity_real_T(b_y, i);
    for (i = 0; i < size_tmp_idx_1; i++) {
      b_y->data[i] = rwk2->data[i] / b_t;
    }

    hifac = f_data[0] / maximum(b_y);
    emxFree_real_T(&b_y);
  } else {
    hifac = 1.0;
  }

  nout = fabs(4.0 * hifac * (double)t->size[0] * 4.0);
  if ((!rtIsInf(nout)) && (!rtIsNaN(nout))) {
    b_t = frexp(nout, &eint);
    nout = eint;
    if (b_t == 0.5) {
      nout = (double)eint - 1.0;
    }
  }

  emxInit_real_T(&wk1, 1);
  fndim = 2.0 * rt_powd_snf(2.0, nout);
  i = wk1->size[0];
  wk1->size[0] = (int)fndim;
  emxEnsureCapacity_real_T(wk1, i);
  vlen = (int)fndim;
  for (i = 0; i < vlen; i++) {
    wk1->data[i] = 0.0;
  }

  i = wk2->size[0];
  wk2->size[0] = (int)fndim;
  emxEnsureCapacity_real_T(wk2, i);
  vlen = (int)fndim;
  for (i = 0; i < vlen; i++) {
    wk2->data[i] = 0.0;
  }

  fac = fndim / ((double)t->size[0] * Ts * 4.0);
  i = t->size[0];
  for (size_tmp_idx_1 = 0; size_tmp_idx_1 < i; size_tmp_idx_1++) {
    ck = b_mod((t->data[size_tmp_idx_1] - t->data[0]) * fac, fndim) + 1.0;
    b_x = b_mod(2.0 * (ck - 1.0), fndim) + 1.0;
    ndenl = 6.0;
    if (ck == rt_roundd_snf(ck)) {
      wk1->data[(int)ck - 1] += x->data[size_tmp_idx_1];
    } else {
      dv[0] = floor((ck - 2.0) + 1.0);
      dv[1] = 1.0;
      nout = d_maximum(dv);
      dv[0] = nout;
      dv[1] = (fndim - 4.0) + 1.0;
      ilo = minimum(dv);
      if (rtIsNaN(ilo + 1.0) || rtIsNaN((ilo + 4.0) - 1.0)) {
        eint = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, eint);
        y->data[0] = rtNaN;
      } else if ((ilo + 4.0) - 1.0 < ilo + 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(ilo + 1.0) || rtIsInf((ilo + 4.0) - 1.0)) && (ilo +
                  1.0 == (ilo + 4.0) - 1.0)) {
        eint = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, eint);
        y->data[0] = rtNaN;
      } else if (floor(ilo + 1.0) == ilo + 1.0) {
        eint = y->size[0] * y->size[1];
        y->size[0] = 1;
        vlen = (int)floor(((ilo + 4.0) - 1.0) - (ilo + 1.0));
        y->size[1] = vlen + 1;
        emxEnsureCapacity_real_T(y, eint);
        for (eint = 0; eint <= vlen; eint++) {
          y->data[eint] = (ilo + 1.0) + (double)eint;
        }
      } else {
        eml_float_colon(ilo + 1.0, (ilo + 4.0) - 1.0, y);
      }

      eint = y->size[0] * y->size[1];
      vlen = y->size[0] * y->size[1];
      y->size[0] = 1;
      emxEnsureCapacity_real_T(y, vlen);
      vlen = eint - 1;
      for (eint = 0; eint <= vlen; eint++) {
        y->data[eint] = ck - y->data[eint];
      }

      vlen = y->size[1];
      if (y->size[1] == 0) {
        nout = 1.0;
      } else {
        nout = y->data[0];
        for (eint = 2; eint <= vlen; eint++) {
          nout *= y->data[eint - 1];
        }
      }

      nout = x->data[size_tmp_idx_1] * ((ck - ilo) * nout);
      wk1->data[(int)((ilo + 4.0) - 1.0) - 1] += nout / (6.0 * (ck - ((ilo + 4.0)
        - 1.0)));
      eint = (int)((ilo + (-1.0 - (((ilo + 4.0) - 1.0) - 1.0))) / -1.0);
      for (vlen = 0; vlen < eint; vlen++) {
        b_t = (((ilo + 4.0) - 1.0) - 1.0) + -(double)vlen;
        ndenl = ndenl / ((b_t + 1.0) - ilo) * (b_t - ((ilo + 4.0) - 1.0));
        wk1->data[(int)b_t - 1] += nout / (ndenl * (ck - b_t));
      }
    }

    ndenl = 6.0;
    if (b_x == rt_roundd_snf(b_x)) {
      wk2->data[(int)b_x - 1]++;
    } else {
      dv[0] = floor((b_x - 2.0) + 1.0);
      dv[1] = 1.0;
      nout = d_maximum(dv);
      dv[0] = nout;
      dv[1] = (fndim - 4.0) + 1.0;
      ilo = minimum(dv);
      if (rtIsNaN(ilo + 1.0) || rtIsNaN((ilo + 4.0) - 1.0)) {
        eint = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, eint);
        y->data[0] = rtNaN;
      } else if ((ilo + 4.0) - 1.0 < ilo + 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(ilo + 1.0) || rtIsInf((ilo + 4.0) - 1.0)) && (ilo +
                  1.0 == (ilo + 4.0) - 1.0)) {
        eint = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, eint);
        y->data[0] = rtNaN;
      } else if (floor(ilo + 1.0) == ilo + 1.0) {
        eint = y->size[0] * y->size[1];
        y->size[0] = 1;
        vlen = (int)floor(((ilo + 4.0) - 1.0) - (ilo + 1.0));
        y->size[1] = vlen + 1;
        emxEnsureCapacity_real_T(y, eint);
        for (eint = 0; eint <= vlen; eint++) {
          y->data[eint] = (ilo + 1.0) + (double)eint;
        }
      } else {
        eml_float_colon(ilo + 1.0, (ilo + 4.0) - 1.0, y);
      }

      eint = y->size[0] * y->size[1];
      vlen = y->size[0] * y->size[1];
      y->size[0] = 1;
      emxEnsureCapacity_real_T(y, vlen);
      vlen = eint - 1;
      for (eint = 0; eint <= vlen; eint++) {
        y->data[eint] = b_x - y->data[eint];
      }

      vlen = y->size[1];
      if (y->size[1] == 0) {
        nout = 1.0;
      } else {
        nout = y->data[0];
        for (eint = 2; eint <= vlen; eint++) {
          nout *= y->data[eint - 1];
        }
      }

      nout *= b_x - ilo;
      wk2->data[(int)((ilo + 4.0) - 1.0) - 1] += nout / (6.0 * (b_x - ((ilo +
        4.0) - 1.0)));
      eint = (int)((ilo + (-1.0 - (((ilo + 4.0) - 1.0) - 1.0))) / -1.0);
      for (vlen = 0; vlen < eint; vlen++) {
        b_t = (((ilo + 4.0) - 1.0) - 1.0) + -(double)vlen;
        ndenl = ndenl / ((b_t + 1.0) - ilo) * (b_t - ((ilo + 4.0) - 1.0));
        wk2->data[(int)b_t - 1] += nout / (ndenl * (b_x - b_t));
      }
    }
  }

  nout = rt_roundd_snf(2.0 * hifac * (double)t->size[0]);
  if (rtIsNaN(nout)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else if (nout < 1.0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (rtIsInf(nout) && (1.0 == nout)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    vlen = (int)(nout - 1.0);
    y->size[1] = (int)(nout - 1.0) + 1;
    emxEnsureCapacity_real_T(y, i);
    for (i = 0; i <= vlen; i++) {
      y->data[i] = (double)i + 1.0;
    }
  }

  b_t = (double)t->size[0] * Ts * 4.0;
  i = f->size[0];
  f->size[0] = y->size[1];
  emxEnsureCapacity_real_T(f, i);
  vlen = y->size[1];
  for (i = 0; i < vlen; i++) {
    f->data[i] = y->data[i] / b_t;
  }

  emxFree_real_T(&y);
  emxInit_creal_T(&b_wk1, 1);
  fft(wk1, b_wk1);
  if (2.0 > nout + 1.0) {
    i = 0;
    eint = 0;
  } else {
    i = 1;
    eint = (int)(nout + 1.0);
  }

  emxInit_real_T(&rwk1, 1);
  vlen = eint - i;
  eint = rwk1->size[0];
  rwk1->size[0] = vlen;
  emxEnsureCapacity_real_T(rwk1, eint);
  for (eint = 0; eint < vlen; eint++) {
    rwk1->data[eint] = b_wk1->data[i + eint].re;
  }

  if (2.0 > nout + 1.0) {
    i = 0;
    eint = 0;
  } else {
    i = 1;
    eint = (int)(nout + 1.0);
  }

  emxInit_real_T(&iwk1, 1);
  vlen = eint - i;
  eint = iwk1->size[0];
  iwk1->size[0] = vlen;
  emxEnsureCapacity_real_T(iwk1, eint);
  for (eint = 0; eint < vlen; eint++) {
    iwk1->data[eint] = b_wk1->data[i + eint].im;
  }

  fft(wk2, b_wk1);
  if (2.0 > nout + 1.0) {
    i = 0;
    eint = 0;
  } else {
    i = 1;
    eint = (int)(nout + 1.0);
  }

  vlen = eint - i;
  eint = rwk2->size[0];
  rwk2->size[0] = vlen;
  emxEnsureCapacity_real_T(rwk2, eint);
  for (eint = 0; eint < vlen; eint++) {
    rwk2->data[eint] = b_wk1->data[i + eint].re;
  }

  if (2.0 > nout + 1.0) {
    i = 0;
    eint = 0;
  } else {
    i = 1;
    eint = (int)(nout + 1.0);
  }

  emxInit_real_T(&iwk2, 1);
  vlen = eint - i;
  eint = iwk2->size[0];
  iwk2->size[0] = vlen;
  emxEnsureCapacity_real_T(iwk2, eint);
  for (eint = 0; eint < vlen; eint++) {
    iwk2->data[eint] = b_wk1->data[i + eint].im;
  }

  if (2.0 > nout + 1.0) {
    i = 0;
    eint = -1;
  } else {
    i = 1;
    eint = (int)(nout + 1.0) - 1;
  }

  size_tmp_idx_1 = eint - i;
  eint = wk1->size[0];
  wk1->size[0] = size_tmp_idx_1 + 1;
  emxEnsureCapacity_real_T(wk1, eint);
  for (eint = 0; eint <= size_tmp_idx_1; eint++) {
    vlen = i + eint;
    wk1->data[eint] = rt_hypotd_snf(b_wk1->data[vlen].re, b_wk1->data[vlen].im);
  }

  emxInit_boolean_T(&c_x, 1);
  i = c_x->size[0];
  c_x->size[0] = wk1->size[0];
  emxEnsureCapacity_boolean_T(c_x, i);
  vlen = wk1->size[0];
  for (i = 0; i < vlen; i++) {
    c_x->data[i] = (wk1->data[i] == 0.0);
  }

  c_y = false;
  vlen = 1;
  exitg1 = false;
  while ((!exitg1) && (vlen <= c_x->size[0])) {
    if (!c_x->data[vlen - 1]) {
      vlen++;
    } else {
      c_y = true;
      exitg1 = true;
    }
  }

  emxFree_boolean_T(&c_x);
  if (c_y) {
    lombscargle(x, f, t, wk2);
  } else {
    if (2.0 > nout + 1.0) {
      i = 0;
      eint = -1;
    } else {
      i = 1;
      eint = (int)(nout + 1.0) - 1;
    }

    size_tmp_idx_1 = eint - i;
    eint = wk1->size[0];
    wk1->size[0] = size_tmp_idx_1 + 1;
    emxEnsureCapacity_real_T(wk1, eint);
    for (eint = 0; eint <= size_tmp_idx_1; eint++) {
      vlen = i + eint;
      wk1->data[eint] = rt_hypotd_snf(b_wk1->data[vlen].re, b_wk1->data[vlen].im);
    }

    emxInit_real_T(&hc2wt, 1);
    i = hc2wt->size[0];
    hc2wt->size[0] = rwk2->size[0];
    emxEnsureCapacity_real_T(hc2wt, i);
    vlen = rwk2->size[0];
    for (i = 0; i < vlen; i++) {
      hc2wt->data[i] = 0.5 * rwk2->data[i] / wk1->data[i];
    }

    i = wk1->size[0];
    wk1->size[0] = iwk2->size[0];
    emxEnsureCapacity_real_T(wk1, i);
    vlen = iwk2->size[0];
    for (i = 0; i < vlen; i++) {
      wk1->data[i] = 0.5 * iwk2->data[i] / wk1->data[i];
    }

    emxInit_real_T(&cwt, 1);
    i = cwt->size[0];
    cwt->size[0] = hc2wt->size[0];
    emxEnsureCapacity_real_T(cwt, i);
    vlen = hc2wt->size[0];
    for (i = 0; i < vlen; i++) {
      cwt->data[i] = hc2wt->data[i] + 0.5;
    }

    vlen = cwt->size[0];
    for (eint = 0; eint < vlen; eint++) {
      cwt->data[eint] = sqrt(cwt->data[eint]);
    }

    emxInit_real_T(&swt, 1);
    i = swt->size[0];
    swt->size[0] = wk1->size[0];
    emxEnsureCapacity_real_T(swt, i);
    vlen = wk1->size[0];
    for (i = 0; i < vlen; i++) {
      swt->data[i] = wk1->data[i];
    }

    vlen = wk1->size[0];
    for (eint = 0; eint < vlen; eint++) {
      b_x = swt->data[eint];
      if (swt->data[eint] < 0.0) {
        b_x = -1.0;
      } else if (swt->data[eint] > 0.0) {
        b_x = 1.0;
      } else {
        if (swt->data[eint] == 0.0) {
          b_x = 0.0;
        }
      }

      swt->data[eint] = b_x;
    }

    emxInit_real_T(&d_x, 1);
    i = d_x->size[0];
    d_x->size[0] = hc2wt->size[0];
    emxEnsureCapacity_real_T(d_x, i);
    vlen = hc2wt->size[0];
    for (i = 0; i < vlen; i++) {
      d_x->data[i] = 0.5 - hc2wt->data[i];
    }

    vlen = d_x->size[0];
    for (eint = 0; eint < vlen; eint++) {
      d_x->data[eint] = sqrt(d_x->data[eint]);
    }

    vlen = swt->size[0];
    for (i = 0; i < vlen; i++) {
      swt->data[i] *= d_x->data[i];
    }

    emxFree_real_T(&d_x);
    nout = 0.5 * (double)t->size[0];
    vlen = hc2wt->size[0];
    for (i = 0; i < vlen; i++) {
      hc2wt->data[i] = (nout + hc2wt->data[i] * rwk2->data[i]) + wk1->data[i] *
        iwk2->data[i];
    }

    i = wk1->size[0];
    wk1->size[0] = cwt->size[0];
    emxEnsureCapacity_real_T(wk1, i);
    vlen = cwt->size[0];
    for (i = 0; i < vlen; i++) {
      wk1->data[i] = cwt->data[i] * rwk1->data[i] + swt->data[i] * iwk1->data[i];
    }

    i = wk2->size[0];
    wk2->size[0] = wk1->size[0];
    emxEnsureCapacity_real_T(wk2, i);
    vlen = wk1->size[0];
    for (eint = 0; eint < vlen; eint++) {
      wk2->data[eint] = rt_powd_snf(wk1->data[eint], 2.0);
    }

    vlen = cwt->size[0];
    for (i = 0; i < vlen; i++) {
      cwt->data[i] = cwt->data[i] * iwk1->data[i] - swt->data[i] * rwk1->data[i];
    }

    emxFree_real_T(&swt);
    i = wk1->size[0];
    wk1->size[0] = cwt->size[0];
    emxEnsureCapacity_real_T(wk1, i);
    vlen = cwt->size[0];
    for (eint = 0; eint < vlen; eint++) {
      wk1->data[eint] = rt_powd_snf(cwt->data[eint], 2.0);
    }

    emxFree_real_T(&cwt);
    vlen = wk2->size[0];
    for (i = 0; i < vlen; i++) {
      wk2->data[i] = wk2->data[i] / hc2wt->data[i] + wk1->data[i] / ((double)
        t->size[0] - hc2wt->data[i]);
    }

    emxFree_real_T(&hc2wt);
  }

  emxFree_creal_T(&b_wk1);
  emxFree_real_T(&iwk2);
  emxFree_real_T(&rwk2);
  emxFree_real_T(&iwk1);
  emxFree_real_T(&rwk1);
  emxFree_real_T(&wk1);
}

static void lombscargle(const emxArray_real_T *x, const emxArray_real_T *f,
  const emxArray_real_T *t, emxArray_real_T *P)
{
  emxArray_real_T *cwt;
  emxArray_real_T *swt;
  emxArray_real_T *swttau;
  emxArray_real_T *t1;
  emxArray_real_T *y;
  double b_x;
  double cwtau;
  double swtau;
  double wtau;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  emxInit_real_T(&t1, 1);
  if (t->size[0] == 1) {
    i = t1->size[0];
    t1->size[0] = 1;
    emxEnsureCapacity_real_T(t1, i);
    t1->data[0] = t->data[0];
  } else {
    i = t1->size[0];
    t1->size[0] = t->size[0];
    emxEnsureCapacity_real_T(t1, i);
    loop_ub = t->size[0];
    for (i = 0; i < loop_ub; i++) {
      t1->data[i] = t->data[i];
    }
  }

  i = P->size[0];
  P->size[0] = f->size[0];
  emxEnsureCapacity_real_T(P, i);
  i = f->size[0];
  emxInit_real_T(&swt, 1);
  emxInit_real_T(&cwt, 1);
  emxInit_real_T(&swttau, 1);
  emxInit_real_T(&y, 1);
  for (b_i = 0; b_i < i; b_i++) {
    wtau = 2.0 * f->data[b_i];
    loop_ub = t1->size[0];
    i1 = y->size[0];
    y->size[0] = t1->size[0];
    emxEnsureCapacity_real_T(y, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      y->data[i1] = wtau * t1->data[i1];
    }

    sinpi(y, swt);
    cospi(y, cwt);
    wtau = 0.0;
    loop_ub = cwt->size[0];
    cwtau = 0.0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      wtau += 2.0 * cwt->data[i1] * swt->data[i1];
      cwtau += (cwt->data[i1] - swt->data[i1]) * (cwt->data[i1] + swt->data[i1]);
    }

    wtau = 0.5 * rt_atan2d_snf(wtau, cwtau);
    swtau = sin(wtau);
    cwtau = cos(wtau);
    i1 = swttau->size[0];
    swttau->size[0] = swt->size[0];
    emxEnsureCapacity_real_T(swttau, i1);
    loop_ub = swt->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      swttau->data[i1] = swt->data[i1] * cwtau - cwt->data[i1] * swtau;
    }

    loop_ub = cwt->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      cwt->data[i1] = cwt->data[i1] * cwtau + swt->data[i1] * swtau;
    }

    wtau = 0.0;
    loop_ub = swttau->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      wtau += swttau->data[i1] * swttau->data[i1];
    }

    cwtau = 0.0;
    loop_ub = cwt->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      cwtau += cwt->data[i1] * cwt->data[i1];
    }

    if (fabs(wtau) < 2.2204460492503131E-16) {
      wtau += 2.2204460492503131E-16;
    }

    if (fabs(cwtau) < 2.2204460492503131E-16) {
      cwtau += 2.2204460492503131E-16;
    }

    swtau = 0.0;
    loop_ub = x->size[0];
    b_x = 0.0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      swtau += x->data[i1] * cwt->data[i1];
      b_x += x->data[i1] * swttau->data[i1];
    }

    P->data[b_i] = swtau * swtau / cwtau + b_x * b_x / wtau;
  }

  emxFree_real_T(&y);
  emxFree_real_T(&swttau);
  emxFree_real_T(&cwt);
  emxFree_real_T(&swt);
  emxFree_real_T(&t1);
}

static void parseAndCacheTimeVector(const cell_wrap_55 arglist[1], boolean_T
  *ignoreArgsIdx, double t_data[], int t_size[2], boolean_T *tflag, double
  Fs_data[], int Fs_size[2])
{
  int i;
  int loop_ub;
  *tflag = false;
  if (arglist[0].f1.size[1] == 1) {
    Fs_size[0] = 1;
    Fs_size[1] = arglist[0].f1.size[1];
    loop_ub = arglist[0].f1.size[0] * arglist[0].f1.size[1];
    for (i = 0; i < loop_ub; i++) {
      Fs_data[i] = arglist[0].f1.data[i];
    }

    t_size[0] = 0;
    t_size[1] = 0;
  } else {
    *tflag = (arglist[0].f1.size[1] != 0);
    t_size[0] = arglist[0].f1.size[1];
    t_size[1] = 1;
    loop_ub = arglist[0].f1.size[1];
    for (i = 0; i < loop_ub; i++) {
      t_data[i] = arglist[0].f1.data[i];
    }

    Fs_size[0] = 0;
    Fs_size[1] = 0;
  }

  *ignoreArgsIdx = true;
}

static void parseAndValidateInputs(const double x_data[], const int x_size[2],
  const cell_wrap_55 arglist[1], double x1_data[], int x1_size[1],
  emxArray_real_T *t, int f_size[2], double ofac_data[], int ofac_size[2], char
  spectrumtype[3], char freqtype_data[], int freqtype_size[2], boolean_T *tflag,
  int ProbDet_size[2], double *Fs, boolean_T *fvecSpecified)
{
  static double Fs_data[400];
  static double t_data[400];
  static short y_data[400];
  static const char b_cv[8] = { 'r', 'a', 'd', '/', 's', 'a', 'm', 'p' };

  emxArray_boolean_T *r;
  emxArray_real_T *temp;
  double b;
  int Fs_size[2];
  int t_size[2];
  int i;
  int loop_ub;
  int y_size_idx_1;
  boolean_T ignoreArgsIdx;
  spectrumtype[0] = 'p';
  spectrumtype[1] = 's';
  spectrumtype[2] = 'd';
  freqtype_size[0] = 1;
  freqtype_size[1] = 8;
  for (i = 0; i < 8; i++) {
    freqtype_data[i] = b_cv[i];
  }

  loop_ub = x_size[1];
  x1_size[0] = x_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&x1_data[0], &x_data[0], loop_ub * sizeof(double));
  }

  ProbDet_size[0] = 0;
  ProbDet_size[1] = 0;
  ignoreArgsIdx = false;
  parseAndCacheTimeVector(arglist, &ignoreArgsIdx, t_data, t_size, tflag,
    Fs_data, Fs_size);
  i = t->size[0] * t->size[1];
  t->size[0] = t_size[0];
  t->size[1] = t_size[1];
  emxEnsureCapacity_real_T(t, i);
  loop_ub = t_size[0] * t_size[1];
  for (i = 0; i < loop_ub; i++) {
    t->data[i] = t_data[i];
  }

  if ((*tflag) || ((Fs_size[0] != 0) && (Fs_size[1] != 0))) {
    freqtype_size[0] = 1;
    freqtype_size[1] = 2;
    freqtype_data[0] = 'H';
    freqtype_data[1] = 'z';
  }

  f_size[0] = 0;
  f_size[1] = 0;
  if ((t_size[0] == 0) || (t_size[1] == 0)) {
    if ((Fs_size[0] != 0) && (Fs_size[1] != 0)) {
      y_size_idx_1 = (short)(x1_size[0] - 1) + 1;
      loop_ub = (short)(x1_size[0] - 1);
      for (i = 0; i <= loop_ub; i++) {
        y_data[i] = (short)i;
      }

      b = 1.0 / Fs_data[0];
      i = t->size[0] * t->size[1];
      t->size[0] = 1;
      t->size[1] = y_size_idx_1;
      emxEnsureCapacity_real_T(t, i);
      for (i = 0; i < y_size_idx_1; i++) {
        t->data[i] = (double)y_data[i] * b;
      }
    } else {
      y_size_idx_1 = (short)(x1_size[0] - 1) + 1;
      loop_ub = (short)(x1_size[0] - 1);
      for (i = 0; i <= loop_ub; i++) {
        y_data[i] = (short)i;
      }

      i = t->size[0] * t->size[1];
      t->size[0] = 1;
      t->size[1] = y_size_idx_1;
      emxEnsureCapacity_real_T(t, i);
      for (i = 0; i < y_size_idx_1; i++) {
        t->data[i] = y_data[i];
      }
    }
  }

  emxInit_boolean_T(&r, 1);
  i = r->size[0];
  r->size[0] = t->size[0] * t->size[1];
  emxEnsureCapacity_boolean_T(r, i);
  loop_ub = t->size[0] * t->size[1];
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = rtIsNaN(t->data[i]);
  }

  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = !r->data[i];
  }

  y_size_idx_1 = r->size[0] - 1;
  loop_ub = 0;
  for (i = 0; i <= y_size_idx_1; i++) {
    if (r->data[i]) {
      loop_ub++;
    }
  }

  emxInit_real_T(&temp, 1);
  i = temp->size[0];
  temp->size[0] = loop_ub;
  emxEnsureCapacity_real_T(temp, i);
  loop_ub = 0;
  for (i = 0; i <= y_size_idx_1; i++) {
    if (r->data[i]) {
      temp->data[loop_ub] = t->data[i];
      loop_ub++;
    }
  }

  emxFree_boolean_T(&r);
  *Fs = ((double)temp->size[0] - 1.0) / (temp->data[temp->size[0] - 1] -
    temp->data[0]);
  ofac_size[0] = 1;
  ofac_size[1] = 1;
  ofac_data[0] = 4.0;
  *fvecSpecified = false;
  emxFree_real_T(&temp);
}

static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

void plomb(const double x_data[], const int x_size[2], const double
           varargin_1_data[], const int varargin_1_size[2], emxArray_real_T
           *varargout_1, emxArray_real_T *varargout_2)
{
  static cell_wrap_55 inputArgs[1];
  static double Ch_SigAndTNanPos_data[400];
  static double xp_data[400];
  static int b_Ch_SigAndTNanPos_data[400];
  static short b_tmp_data[400];
  static short c_tmp_data[400];
  static const char b_cv[8] = { 'r', 'a', 'd', '/', 's', 'a', 'm', 'p' };

  static const char b_cv1[2] = { 'H', 'z' };

  emxArray_int32_T *indx;
  emxArray_real_T *Px;
  emxArray_real_T *b;
  emxArray_real_T *b_sig;
  emxArray_real_T *fr1;
  emxArray_real_T *result;
  emxArray_real_T *sig;
  emxArray_real_T *t;
  emxArray_real_T *tout;
  double f_data[1];
  double ofac_data[1];
  double Ch_SigMean;
  double Ch_n;
  double Fs;
  double PNaNPos;
  double expl_temp;
  int Ch_SigAndTNanPos_size[2];
  int ProbDet_size[2];
  int b_f_size[2];
  int f_size[2];
  int freqtype_size[2];
  int ofac_size[2];
  int xp_size[1];
  int eint;
  int exitg1;
  int i;
  int sizes_idx_0;
  int sizes_idx_1;
  int trueCount;
  char freqtype_data[8];
  char spectrumtype[3];
  boolean_T tmp_data[400];
  boolean_T fvecSpecified;
  boolean_T unusedU0;
  inputArgs[0].f1.size[0] = 1;
  inputArgs[0].f1.size[1] = varargin_1_size[1];
  sizes_idx_0 = varargin_1_size[0] * varargin_1_size[1];
  for (i = 0; i < sizes_idx_0; i++) {
    inputArgs[0].f1.data[i] = varargin_1_data[i];
  }

  emxInit_real_T(&sig, 1);
  emxInit_real_T(&t, 2);
  parseAndValidateInputs(x_data, x_size, inputArgs, xp_data, xp_size, t, f_size,
    ofac_data, ofac_size, spectrumtype, freqtype_data, freqtype_size, &unusedU0,
    ProbDet_size, &Fs, &fvecSpecified);
  b_f_size[0] = 0;
  b_f_size[1] = 0;
  MarkMissingData(xp_data, xp_size, t, f_data, b_f_size, ofac_data, ofac_size,
                  spectrumtype, freqtype_data, freqtype_size, Fs,
                  Ch_SigAndTNanPos_data, f_size, &unusedU0, &Ch_SigMean,
                  &PNaNPos, &expl_temp, &Ch_n);
  PNaNPos = 0.0;
  sizes_idx_0 = xp_size[0];
  i = sig->size[0];
  sig->size[0] = xp_size[0];
  emxEnsureCapacity_real_T(sig, i);
  for (i = 0; i < sizes_idx_0; i++) {
    sig->data[i] = xp_data[i];
  }

  emxInit_real_T(&tout, 1);
  if (unusedU0) {
    sizes_idx_0 = f_size[1];
    for (i = 0; i < sizes_idx_0; i++) {
      tmp_data[i] = (Ch_SigAndTNanPos_data[i] > 0.0);
    }

    sizes_idx_0 = f_size[1] - 1;
    trueCount = 0;
    sizes_idx_1 = 0;
    for (i = 0; i <= sizes_idx_0; i++) {
      if (tmp_data[i]) {
        trueCount++;
        b_tmp_data[sizes_idx_1] = (short)(i + 1);
        sizes_idx_1++;
      }
    }

    Ch_SigAndTNanPos_size[0] = 1;
    Ch_SigAndTNanPos_size[1] = trueCount;
    for (i = 0; i < trueCount; i++) {
      b_Ch_SigAndTNanPos_data[i] = (int)Ch_SigAndTNanPos_data[b_tmp_data[i] - 1];
    }

    b_nullAssignment(sig, b_Ch_SigAndTNanPos_data, Ch_SigAndTNanPos_size);
    sizes_idx_0 = f_size[1];
    for (i = 0; i < sizes_idx_0; i++) {
      tmp_data[i] = (Ch_SigAndTNanPos_data[i] > 0.0);
    }

    sizes_idx_0 = f_size[1] - 1;
    trueCount = 0;
    sizes_idx_1 = 0;
    for (i = 0; i <= sizes_idx_0; i++) {
      if (tmp_data[i]) {
        trueCount++;
        c_tmp_data[sizes_idx_1] = (short)(i + 1);
        sizes_idx_1++;
      }
    }

    i = tout->size[0];
    tout->size[0] = t->size[0] * t->size[1];
    emxEnsureCapacity_real_T(tout, i);
    sizes_idx_0 = t->size[0] * t->size[1];
    for (i = 0; i < sizes_idx_0; i++) {
      tout->data[i] = t->data[i];
    }

    Ch_SigAndTNanPos_size[0] = 1;
    Ch_SigAndTNanPos_size[1] = trueCount;
    for (i = 0; i < trueCount; i++) {
      b_Ch_SigAndTNanPos_data[i] = (int)Ch_SigAndTNanPos_data[c_tmp_data[i] - 1];
    }

    b_nullAssignment(tout, b_Ch_SigAndTNanPos_data, Ch_SigAndTNanPos_size);
  } else {
    i = tout->size[0];
    tout->size[0] = t->size[0] * t->size[1];
    emxEnsureCapacity_real_T(tout, i);
    sizes_idx_0 = t->size[0] * t->size[1];
    for (i = 0; i < sizes_idx_0; i++) {
      tout->data[i] = t->data[i];
    }
  }

  emxFree_real_T(&t);
  emxInit_real_T(&b, 1);
  emxInit_int32_T(&indx, 1);
  c_unique_vector(tout, b, indx);
  i = b->size[0];
  b->size[0] = indx->size[0];
  emxEnsureCapacity_real_T(b, i);
  sizes_idx_0 = indx->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    b->data[i] = indx->data[i];
  }

  emxFree_int32_T(&indx);
  emxInit_real_T(&b_sig, 1);
  i = b_sig->size[0];
  b_sig->size[0] = b->size[0];
  emxEnsureCapacity_real_T(b_sig, i);
  sizes_idx_0 = b->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    b_sig->data[i] = sig->data[(int)b->data[i] - 1];
  }

  i = sig->size[0];
  sig->size[0] = b_sig->size[0];
  emxEnsureCapacity_real_T(sig, i);
  sizes_idx_0 = b_sig->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    sig->data[i] = b_sig->data[i];
  }

  i = b_sig->size[0];
  b_sig->size[0] = b->size[0];
  emxEnsureCapacity_real_T(b_sig, i);
  sizes_idx_0 = b->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    b_sig->data[i] = tout->data[(int)b->data[i] - 1];
  }

  emxFree_real_T(&b);
  i = tout->size[0];
  tout->size[0] = b_sig->size[0];
  emxEnsureCapacity_real_T(tout, i);
  sizes_idx_0 = b_sig->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    tout->data[i] = b_sig->data[i];
  }

  emxFree_real_T(&b_sig);
  expl_temp = frexp(sig->size[0], &eint);
  if (expl_temp == 0.5) {
    eint--;
  }

  if (sig->size[0] == rt_powd_snf(2.0, (double)eint - 1.0) + 1.0) {
    PNaNPos = rt_powd_snf(2.0, ((double)eint - 1.0) + 1.0);
  }

  sizes_idx_0 = sig->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    sig->data[i] -= Ch_SigMean;
  }

  emxInit_real_T(&Px, 1);
  emxInit_real_T(&fr1, 1);
  fasper(sig, tout, f_data, b_f_size, Px, fr1);
  i = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = fr1->size[0];
  varargout_2->size[1] = 1;
  emxEnsureCapacity_real_T(varargout_2, i);
  sizes_idx_0 = fr1->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    varargout_2->data[i] = fr1->data[i];
  }

  if (PNaNPos > 0.0) {
    PNaNPos = rt_powd_snf(2.0, ((double)eint - 1.0) + 1.0);
    sizes_idx_0 = fr1->size[0];
    if (sizes_idx_0 <= 1) {
      sizes_idx_0 = 1;
    }

    if (fr1->size[0] == 0) {
      sizes_idx_0 = 0;
    }

    if (PNaNPos <= sizes_idx_0) {
      Px->data[(int)PNaNPos - 1] = b_lombscargle(sig, fr1->data[(int)PNaNPos - 1],
        tout);
    }
  }

  emxFree_real_T(&tout);
  emxFree_real_T(&sig);
  if (Px->size[0] != 0) {
    sizes_idx_0 = Px->size[0];
  } else {
    sizes_idx_0 = 0;
  }

  if ((sizes_idx_0 == 0) || (Px->size[0] != 0)) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }

  emxInit_real_T(&result, 2);
  i = result->size[0] * result->size[1];
  result->size[0] = sizes_idx_0;
  result->size[1] = sizes_idx_1;
  emxEnsureCapacity_real_T(result, i);
  for (i = 0; i < sizes_idx_1; i++) {
    for (trueCount = 0; trueCount < sizes_idx_0; trueCount++) {
      result->data[trueCount] = Px->data[trueCount];
    }
  }

  i = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = sizes_idx_0;
  varargout_1->size[1] = sizes_idx_1;
  emxEnsureCapacity_real_T(varargout_1, i);
  for (i = 0; i < sizes_idx_1; i++) {
    for (trueCount = 0; trueCount < sizes_idx_0; trueCount++) {
      varargout_1->data[trueCount] = Px->data[trueCount];
    }
  }

  emxFree_real_T(&Px);
  if (b_strcmp(spectrumtype)) {
    sizes_idx_0 = 0;
  } else {
    sizes_idx_0 = -1;
  }

  if (sizes_idx_0 == 0) {
    unusedU0 = false;
    if (freqtype_size[1] == 8) {
      sizes_idx_0 = 0;
      do {
        exitg1 = 0;
        if (sizes_idx_0 < 8) {
          if (freqtype_data[sizes_idx_0] != b_cv[sizes_idx_0]) {
            exitg1 = 1;
          } else {
            sizes_idx_0++;
          }
        } else {
          unusedU0 = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (unusedU0) {
      sizes_idx_0 = 0;
    } else {
      unusedU0 = false;
      if (freqtype_size[1] == 2) {
        sizes_idx_0 = 0;
        do {
          exitg1 = 0;
          if (sizes_idx_0 < 2) {
            if (freqtype_data[sizes_idx_0] != b_cv1[sizes_idx_0]) {
              exitg1 = 1;
            } else {
              sizes_idx_0++;
            }
          } else {
            unusedU0 = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (unusedU0) {
        sizes_idx_0 = 1;
      } else {
        sizes_idx_0 = -1;
      }
    }

    switch (sizes_idx_0) {
     case 0:
      i = varargout_2->size[0] * varargout_2->size[1];
      varargout_2->size[0] = fr1->size[0];
      varargout_2->size[1] = 1;
      emxEnsureCapacity_real_T(varargout_2, i);
      sizes_idx_0 = fr1->size[0];
      for (i = 0; i < sizes_idx_0; i++) {
        varargout_2->data[i] = fr1->data[i] * 6.2831853071795862 / Fs;
      }

      i = varargout_1->size[0] * varargout_1->size[1];
      varargout_1->size[0] = result->size[0];
      varargout_1->size[1] = result->size[1];
      emxEnsureCapacity_real_T(varargout_1, i);
      sizes_idx_0 = result->size[0] * result->size[1];
      for (i = 0; i < sizes_idx_0; i++) {
        varargout_1->data[i] = result->data[i] / 6.2831853071795862;
      }
      break;

     case 1:
      i = varargout_1->size[0] * varargout_1->size[1];
      varargout_1->size[0] = result->size[0];
      varargout_1->size[1] = result->size[1];
      emxEnsureCapacity_real_T(varargout_1, i);
      sizes_idx_0 = result->size[0] * result->size[1];
      for (i = 0; i < sizes_idx_0; i++) {
        varargout_1->data[i] = result->data[i] / Fs;
      }
      break;
    }
  }

  emxFree_real_T(&result);
  emxFree_real_T(&fr1);
}

/* End of code generation (plomb.c) */
