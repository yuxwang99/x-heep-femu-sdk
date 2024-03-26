/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: plomb.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "plomb.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "abs.h"
#include "any.h"
#include "atan2.h"
#include "colon.h"
#include "convertStringsToChars.h"
#include "cos1.h"
#include "cospi.h"
#include "div.h"
#include "eml_mtimes_helper.h"
#include "fft.h"
#include "find.h"
#include "fix.h"
#include "floor.h"
#include "isinf.h"
#include "isnan.h"
#include "isrow.h"
#include "length.h"
#include "mean.h"
#include "minOrMax.h"
#include "mod.h"
#include "mpower.h"
#include "mrdivide_helper.h"
#include "nextpow2.h"
#include "nullAssignment.h"
#include "power.h"
#include "prod.h"
#include "round.h"
#include "rt_nonfinite.h"
#include "sign.h"
#include "sin.h"
#include "sinpi.h"
#include "sqrt1.h"
#include "strcmp.h"
#include "unique.h"
#include "var.h"
#include <math.h>
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real32_T_1x400
#define struct_emxArray_real32_T_1x400
struct emxArray_real32_T_1x400 {
  float data[400];
  int size[2];
};
#endif /* struct_emxArray_real32_T_1x400 */
#ifndef typedef_emxArray_real32_T_1x400
#define typedef_emxArray_real32_T_1x400
typedef struct emxArray_real32_T_1x400 emxArray_real32_T_1x400;
#endif /* typedef_emxArray_real32_T_1x400 */

#ifndef typedef_cell_wrap_78
#define typedef_cell_wrap_78
typedef struct {
  emxArray_real32_T_1x400 f1;
} cell_wrap_78;
#endif /* typedef_cell_wrap_78 */

/* Function Declarations */
static boolean_T
MarkMissingData(const float x_data[], int x_size, const emxArray_real32_T *t,
                double f_data[], int f_size[2], const double ofac_data[],
                const int ofac_size[2], const char freqtype_data[],
                const int freqtype_size[2], float Fs,
                double Ch_SigAndTNanPos_data[], int Ch_SigAndTNanPos_size[2],
                double *Ch_SigMean, double *Ch_SigVar, double *Ch_Alpha,
                double *Ch_n);

static double b_lombscargle(const emxArray_real32_T *x, float f,
                            const emxArray_real32_T *t);

static void b_spread(emxArray_real_T *yy, float n, float x);

static void b_times(emxArray_real_T *in1, const emxArray_real_T *in2);

static void binary_expand_op_10(emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3,
                                const emxArray_real_T *in4,
                                const emxArray_real_T *in5);

static void binary_expand_op_11(emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3,
                                const emxArray_real_T *in4,
                                const emxArray_real_T *in5);

static void binary_expand_op_12(emxArray_real_T *in1,
                                const emxArray_real32_T *in2,
                                const emxArray_real_T *in3,
                                const emxArray_real_T *in4,
                                const emxArray_real_T *in5);

static void binary_expand_op_15(emxArray_real32_T *in1, float in2,
                                const emxArray_real32_T *in3, float in4);

static void binary_expand_op_16(emxArray_real32_T *in1,
                                const emxArray_real32_T *in2, float in3,
                                const emxArray_real32_T *in4, float in5);

static void binary_expand_op_9(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const emxArray_real_T *in3,
                               const emxArray_real32_T *in4);

static void fasper(const emxArray_real32_T *x, const emxArray_real32_T *t,
                   const double f_data[], const int f_size[2],
                   emxArray_real_T *wk2, emxArray_real32_T *f);

static double getChAlpha(const char freqtype_data[], const int freqtype_size[2],
                         float Fs, double SigVar);

static boolean_T getProbDensity(int pd_size[2]);

static void lombscargle(const emxArray_real32_T *x, const emxArray_real32_T *f,
                        const emxArray_real32_T *t, emxArray_real_T *P);

static boolean_T parseAndCacheFrequencyVector(int f_size[2],
                                              boolean_T *ignoreArgsIdx);

static boolean_T parseAndCacheTimeVector(const cell_wrap_78 *arglist,
                                         float t_data[], int t_size[2],
                                         float Fs_data[], int Fs_size[2],
                                         boolean_T *ignoreArgsIdx);

static int parseAndValidateInputs(const float x_data[], const int x_size[2],
                                  const cell_wrap_78 *arglist, float x1_data[],
                                  emxArray_real32_T *t, double ofac_data[],
                                  int ofac_size[2], char freqtype_data[],
                                  int freqtype_size[2], int f_size[2],
                                  boolean_T *tflag, int ProbDet_size[2],
                                  float *Fs, boolean_T *fvecSpecified);

static void spread(float y, emxArray_real_T *yy, float n, float x);

/* Function Definitions */
/*
 * Arguments    : const float x_data[]
 *                int x_size
 *                const emxArray_real32_T *t
 *                double f_data[]
 *                int f_size[2]
 *                const double ofac_data[]
 *                const int ofac_size[2]
 *                const char freqtype_data[]
 *                const int freqtype_size[2]
 *                float Fs
 *                double Ch_SigAndTNanPos_data[]
 *                int Ch_SigAndTNanPos_size[2]
 *                double *Ch_SigMean
 *                double *Ch_SigVar
 *                double *Ch_Alpha
 *                double *Ch_n
 * Return Type  : boolean_T
 */
static boolean_T
MarkMissingData(const float x_data[], int x_size, const emxArray_real32_T *t,
                double f_data[], int f_size[2], const double ofac_data[],
                const int ofac_size[2], const char freqtype_data[],
                const int freqtype_size[2], float Fs,
                double Ch_SigAndTNanPos_data[], int Ch_SigAndTNanPos_size[2],
                double *Ch_SigMean, double *Ch_SigVar, double *Ch_Alpha,
                double *Ch_n)
{
  emxArray_boolean_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r4;
  emxArray_real32_T c_t;
  emxArray_real32_T *r;
  emxArray_real32_T *r8;
  emxArray_real32_T *temp;
  emxArray_real_T *a_tmp;
  emxArray_real_T *b_y;
  emxArray_real_T *r6;
  emxArray_real_T *r7;
  emxArray_real_T *y;
  double b_Ch_SigAndTNanPos_data[400];
  double nout_data;
  double *a_tmp_data;
  double *y_data;
  const float *t_data;
  float a;
  float *temp_data;
  int c_Ch_SigAndTNanPos_data[400];
  int a_size[2];
  int b_Ch_SigAndTNanPos_size[2];
  int c_Ch_SigAndTNanPos_size[2];
  int b_t;
  int d_t;
  int end_tmp;
  int i;
  int loop_ub;
  int t_tmp;
  int *r3;
  int *r5;
  short b_tmp_data[400];
  short c_tmp_data[400];
  boolean_T tmp_data[400];
  boolean_T Ch_NanFlag;
  t_data = t->data;
  Ch_SigAndTNanPos_size[0] = 1;
  Ch_SigAndTNanPos_size[1] = x_size;
  emxInit_real32_T(&r, 1);
  i = r->size[0];
  r->size[0] = x_size;
  emxEnsureCapacity_real32_T(r, i);
  temp_data = r->data;
  for (i = 0; i < x_size; i++) {
    temp_data[i] = x_data[i];
  }
  t_tmp = t->size[0] * t->size[1];
  c_t = *t;
  d_t = t_tmp;
  c_t.size = &d_t;
  c_t.numDimensions = 1;
  emxInit_boolean_T(&r1, 1);
  d_isnan(&c_t, r1);
  emxInit_int32_T(&r2, 1);
  eml_find(r1, r2);
  r3 = r2->data;
  d_isnan(r, r1);
  emxInit_int32_T(&r4, 1);
  eml_find(r1, r4);
  r5 = r4->data;
  emxFree_boolean_T(&r1);
  emxInit_real_T(&a_tmp, 1);
  i = a_tmp->size[0];
  a_tmp->size[0] = r2->size[0] + r4->size[0];
  emxEnsureCapacity_real_T(a_tmp, i);
  a_tmp_data = a_tmp->data;
  loop_ub = r2->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_tmp_data[i] = r3[i];
  }
  loop_ub = r4->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_tmp_data[i + r2->size[0]] = r5[i];
  }
  emxFree_int32_T(&r4);
  emxFree_int32_T(&r2);
  emxInit_real_T(&r6, 1);
  b_unique_vector(a_tmp, r6);
  b_t = r6->size[0];
  b_unique_vector(a_tmp, r6);
  a_tmp_data = r6->data;
  emxFree_real_T(&a_tmp);
  emxInit_real_T(&r7, 1);
  i = r7->size[0];
  r7->size[0] = (r6->size[0] + x_size) - b_t;
  emxEnsureCapacity_real_T(r7, i);
  y_data = r7->data;
  loop_ub = r6->size[0];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = a_tmp_data[i];
  }
  loop_ub = x_size - b_t;
  for (i = 0; i < loop_ub; i++) {
    y_data[i + r6->size[0]] = 0.0;
  }
  emxFree_real_T(&r6);
  for (i = 0; i < x_size; i++) {
    Ch_SigAndTNanPos_data[i] = y_data[i];
  }
  emxFree_real_T(&r7);
  b_Ch_SigAndTNanPos_size[0] = 1;
  b_Ch_SigAndTNanPos_size[1] = x_size;
  for (i = 0; i < x_size; i++) {
    nout_data = Ch_SigAndTNanPos_data[i];
    b_Ch_SigAndTNanPos_data[i] = nout_data;
    tmp_data[i] = (nout_data > 0.0);
  }
  Ch_NanFlag = b_any(b_Ch_SigAndTNanPos_data, b_Ch_SigAndTNanPos_size);
  end_tmp = x_size - 1;
  loop_ub = 0;
  b_t = 0;
  for (i = 0; i <= end_tmp; i++) {
    if (tmp_data[i]) {
      loop_ub++;
      b_tmp_data[b_t] = (short)i;
      b_t++;
    }
  }
  c_Ch_SigAndTNanPos_size[0] = 1;
  c_Ch_SigAndTNanPos_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    c_Ch_SigAndTNanPos_data[i] = (int)Ch_SigAndTNanPos_data[b_tmp_data[i]];
  }
  b_nullAssignment(r, c_Ch_SigAndTNanPos_data, c_Ch_SigAndTNanPos_size);
  *Ch_n = r->size[0];
  for (i = 0; i < x_size; i++) {
    tmp_data[i] = (Ch_SigAndTNanPos_data[i] > 0.0);
  }
  emxInit_real32_T(&temp, 2);
  i = temp->size[0] * temp->size[1];
  temp->size[0] = t->size[0];
  temp->size[1] = t->size[1];
  emxEnsureCapacity_real32_T(temp, i);
  temp_data = temp->data;
  for (i = 0; i < t_tmp; i++) {
    temp_data[i] = t_data[i];
  }
  loop_ub = 0;
  b_t = 0;
  for (i = 0; i <= end_tmp; i++) {
    if (tmp_data[i]) {
      loop_ub++;
      c_tmp_data[b_t] = (short)i;
      b_t++;
    }
  }
  c_Ch_SigAndTNanPos_size[0] = 1;
  c_Ch_SigAndTNanPos_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    c_Ch_SigAndTNanPos_data[i] = (int)Ch_SigAndTNanPos_data[c_tmp_data[i]];
  }
  c_nullAssignment(temp, c_Ch_SigAndTNanPos_data, c_Ch_SigAndTNanPos_size);
  temp_data = temp->data;
  b_t = temp->size[0] * temp->size[1];
  end_tmp = ofac_size[0] * ofac_size[1];
  for (i = 0; i < end_tmp; i++) {
    nout_data = 0.5 * ofac_data[0] * (double)b_t;
  }
  emxInit_real_T(&y, 2);
  a_tmp_data = y->data;
  if (b_isnan(nout_data)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    a_tmp_data = y->data;
    a_tmp_data[0] = rtNaN;
  } else if (nout_data < 1.0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)(nout_data - 1.0) + 1;
    emxEnsureCapacity_real_T(y, i);
    a_tmp_data = y->data;
    loop_ub = (int)(nout_data - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      a_tmp_data[i] = (double)i + 1.0;
    }
  }
  a = (float)b_t *
      ((temp_data[b_t - 1] - temp_data[0]) / (float)((double)b_t - 1.0));
  emxFree_real32_T(&temp);
  *Ch_SigMean = mean(r);
  *Ch_SigVar = var((float *)r->data, (*(int(*)[1])r->size)[0]);
  emxFree_real32_T(&r);
  *Ch_Alpha = getChAlpha(freqtype_data, freqtype_size, Fs, *Ch_SigVar);
  if (any(Ch_NanFlag)) {
    float a_data;
    emxInit_real_T(&b_y, 1);
    i = b_y->size[0];
    b_y->size[0] = y->size[1];
    emxEnsureCapacity_real_T(b_y, i);
    y_data = b_y->data;
    loop_ub = y->size[1];
    for (i = 0; i < loop_ub; i++) {
      y_data[i] = a_tmp_data[i];
    }
    a_size[0] = ofac_size[0];
    a_size[1] = ofac_size[1];
    for (i = 0; i < end_tmp; i++) {
      a_data = a * (float)ofac_data[0];
    }
    f_size[0] = 1;
    f_size[1] = 1;
    emxInit_real32_T(&r8, 2);
    mrdiv(b_y, (float *)&a_data, a_size, r8);
    emxFree_real_T(&b_y);
    d_maximum(r8, (float *)&a, b_Ch_SigAndTNanPos_size);
    emxFree_real32_T(&r8);
    f_data[0] = b_round(a);
  }
  emxFree_real_T(&y);
  return Ch_NanFlag;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                float f
 *                const emxArray_real32_T *t
 * Return Type  : double
 */
static double b_lombscargle(const emxArray_real32_T *x, float f,
                            const emxArray_real32_T *t)
{
  emxArray_real32_T *cwt;
  emxArray_real32_T *swt;
  emxArray_real32_T *t1;
  const float *t_data;
  const float *x_data;
  float b_x;
  float c_x;
  float swtau;
  float wtau;
  float *cwt_data;
  float *swt_data;
  float *t1_data;
  int i;
  int loop_ub;
  t_data = t->data;
  x_data = x->data;
  emxInit_real32_T(&t1, 1);
  if (isrow(t)) {
    i = t1->size[0];
    t1->size[0] = 1;
    emxEnsureCapacity_real32_T(t1, i);
    t1_data = t1->data;
    t1_data[0] = t_data[0];
  } else {
    i = t1->size[0];
    t1->size[0] = t->size[0];
    emxEnsureCapacity_real32_T(t1, i);
    t1_data = t1->data;
    loop_ub = t->size[0];
    for (i = 0; i < loop_ub; i++) {
      t1_data[i] = t_data[i];
    }
  }
  wtau = 2.0F * f;
  loop_ub = t1->size[0];
  for (i = 0; i < loop_ub; i++) {
    t1_data[i] *= wtau;
  }
  emxInit_real32_T(&swt, 1);
  sinpi(t1, swt);
  swt_data = swt->data;
  emxInit_real32_T(&cwt, 1);
  cospi(t1, cwt);
  cwt_data = cwt->data;
  if (cwt->size[0] == swt->size[0]) {
    wtau = 0.0F;
    loop_ub = cwt->size[0];
    swtau = 0.0F;
    for (i = 0; i < loop_ub; i++) {
      wtau += 2.0F * cwt_data[i] * swt_data[i];
      swtau += (cwt_data[i] - swt_data[i]) * (cwt_data[i] + swt_data[i]);
    }
    wtau = 0.5F * b_atan2(wtau, swtau);
  } else {
    wtau = binary_expand_op_17(cwt, swt);
  }
  swtau = wtau;
  b_sin(&swtau);
  c_cos(&wtau);
  if (swt->size[0] == cwt->size[0]) {
    i = t1->size[0];
    t1->size[0] = swt->size[0];
    emxEnsureCapacity_real32_T(t1, i);
    t1_data = t1->data;
    loop_ub = swt->size[0];
    for (i = 0; i < loop_ub; i++) {
      t1_data[i] = swt_data[i] * wtau - cwt_data[i] * swtau;
    }
  } else {
    binary_expand_op_16(t1, swt, wtau, cwt, swtau);
    t1_data = t1->data;
  }
  if (cwt->size[0] == swt->size[0]) {
    loop_ub = cwt->size[0];
    for (i = 0; i < loop_ub; i++) {
      cwt_data[i] = cwt_data[i] * wtau + swt_data[i] * swtau;
    }
  } else {
    binary_expand_op_15(cwt, wtau, swt, swtau);
    cwt_data = cwt->data;
  }
  emxFree_real32_T(&swt);
  wtau = 0.0F;
  loop_ub = t1->size[0];
  for (i = 0; i < loop_ub; i++) {
    wtau += t1_data[i] * t1_data[i];
  }
  swtau = 0.0F;
  loop_ub = cwt->size[0];
  for (i = 0; i < loop_ub; i++) {
    swtau += cwt_data[i] * cwt_data[i];
  }
  if (g_abs(wtau) < 2.22044605E-16F) {
    wtau += 2.22044605E-16F;
  }
  if (g_abs(swtau) < 2.22044605E-16F) {
    swtau += 2.22044605E-16F;
  }
  b_x = 0.0F;
  loop_ub = x->size[0];
  c_x = 0.0F;
  for (i = 0; i < loop_ub; i++) {
    b_x += x_data[i] * cwt_data[i];
    c_x += x_data[i] * t1_data[i];
  }
  emxFree_real32_T(&cwt);
  emxFree_real32_T(&t1);
  return b_x * b_x / swtau + c_x * c_x / wtau;
}

/*
 * Arguments    : emxArray_real_T *yy
 *                float n
 *                float x
 * Return Type  : void
 */
static void b_spread(emxArray_real_T *yy, float n, float x)
{
  emxArray_real32_T *b_x;
  emxArray_real32_T *y;
  double ndenl;
  double *yy_data;
  float *x_data;
  float *y_data;
  int ia;
  int k;
  yy_data = yy->data;
  ndenl = 6.0;
  if (x == c_round(x)) {
    yy_data[(int)x - 1]++;
  } else {
    float fv[2];
    float fac;
    float ilo;
    fv[0] = b_floor((x - 2.0F) + 1.0F);
    fv[1] = 1.0F;
    ilo = e_maximum(fv);
    fv[0] = ilo;
    fv[1] = (n - 4.0F) + 1.0F;
    ilo = c_minimum(fv);
    emxInit_real32_T(&y, 2);
    y_data = y->data;
    if (c_isnan(ilo + 1.0F) || c_isnan((ilo + 4.0F) - 1.0F)) {
      k = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real32_T(y, k);
      y_data = y->data;
      y_data[0] = rtNaNF;
    } else if ((ilo + 4.0F) - 1.0F < ilo + 1.0F) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else if ((b_isinf(ilo + 1.0F) || b_isinf((ilo + 4.0F) - 1.0F)) &&
               (ilo + 1.0F == (ilo + 4.0F) - 1.0F)) {
      k = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real32_T(y, k);
      y_data = y->data;
      y_data[0] = rtNaNF;
    } else if (b_floor(ilo + 1.0F) == ilo + 1.0F) {
      if ((g_abs(ilo + 1.0F) >= 1.07374182E+9F) ||
          (g_abs((ilo + 4.0F) - 1.0F) >= 1.07374182E+9F)) {
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        ia = (int)((double)((ilo + 4.0F) - 1.0F) - (ilo + 1.0F));
        y->size[1] = ia + 1;
        emxEnsureCapacity_real32_T(y, k);
        y_data = y->data;
        for (k = 0; k <= ia; k++) {
          y_data[k] = (float)((ilo + 1.0F) + (double)k);
        }
      } else {
        int n_tmp;
        ia = (int)floorf(ilo + 1.0F);
        n_tmp = (int)floorf(c_fix((ilo + 4.0F) - 1.0F)) - ia;
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = n_tmp + 1;
        emxEnsureCapacity_real32_T(y, k);
        y_data = y->data;
        for (k = 0; k <= n_tmp; k++) {
          y_data[k] = (float)(ia + k);
        }
      }
    } else {
      eml_float_colon(ilo + 1.0F, (ilo + 4.0F) - 1.0F, y);
      y_data = y->data;
    }
    emxInit_real32_T(&b_x, 2);
    k = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = y->size[1];
    emxEnsureCapacity_real32_T(b_x, k);
    x_data = b_x->data;
    ia = y->size[1];
    for (k = 0; k < ia; k++) {
      x_data[k] = x - y_data[k];
    }
    emxFree_real32_T(&y);
    fac = (x - ilo) * prod(b_x);
    emxFree_real32_T(&b_x);
    yy_data[(int)((ilo + 4.0F) - 1.0F) - 1] =
        (float)yy_data[(int)((ilo + 4.0F) - 1.0F) - 1] +
        fac / (6.0F * (x - ((ilo + 4.0F) - 1.0F)));
    k = (int)-(ilo + (-1.0F - (((ilo + 4.0F) - 1.0F) - 1.0F)));
    for (ia = 0; ia < k; ia++) {
      float j;
      j = (((ilo + 4.0F) - 1.0F) - 1.0F) - (float)ia;
      ndenl = (float)ndenl / ((j + 1.0F) - ilo) * (j - ((ilo + 4.0F) - 1.0F));
      yy_data[(int)j - 1] =
          (float)yy_data[(int)j - 1] + fac / ((float)ndenl * (x - j));
    }
  }
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
static void b_times(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 1);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_0] * in2_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = b_in1->size[0];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(&b_in1);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 *                const emxArray_real_T *in5
 * Return Type  : void
 */
static void binary_expand_op_10(emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3,
                                const emxArray_real_T *in4,
                                const emxArray_real_T *in5)
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  const double *in3_data;
  const double *in4_data;
  const double *in5_data;
  double *b_in2_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  in5_data = in5->data;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  emxInit_real_T(&b_in2, 1);
  if (in5->size[0] == 1) {
    i = in4->size[0];
  } else {
    i = in5->size[0];
  }
  if (i == 1) {
    if (in3->size[0] == 1) {
      loop_ub = in2->size[0];
    } else {
      loop_ub = in3->size[0];
    }
  } else {
    loop_ub = i;
  }
  i = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_2_0 = (in4->size[0] != 1);
  stride_3_0 = (in5->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] * in3_data[i * stride_1_0] -
                    in4_data[i * stride_2_0] * in5_data[i * stride_3_0];
  }
  b_power(b_in2, in1);
  emxFree_real_T(&b_in2);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 *                const emxArray_real_T *in5
 * Return Type  : void
 */
static void binary_expand_op_11(emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3,
                                const emxArray_real_T *in4,
                                const emxArray_real_T *in5)
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  const double *in3_data;
  const double *in4_data;
  const double *in5_data;
  double *b_in2_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  in5_data = in5->data;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  emxInit_real_T(&b_in2, 1);
  if (in5->size[0] == 1) {
    i = in4->size[0];
  } else {
    i = in5->size[0];
  }
  if (i == 1) {
    if (in3->size[0] == 1) {
      loop_ub = in2->size[0];
    } else {
      loop_ub = in3->size[0];
    }
  } else {
    loop_ub = i;
  }
  i = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_2_0 = (in4->size[0] != 1);
  stride_3_0 = (in5->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] * in3_data[i * stride_1_0] +
                    in4_data[i * stride_2_0] * in5_data[i * stride_3_0];
  }
  b_power(b_in2, in1);
  emxFree_real_T(&b_in2);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real32_T *in2
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 *                const emxArray_real_T *in5
 * Return Type  : void
 */
static void binary_expand_op_12(emxArray_real_T *in1,
                                const emxArray_real32_T *in2,
                                const emxArray_real_T *in3,
                                const emxArray_real_T *in4,
                                const emxArray_real_T *in5)
{
  emxArray_real_T *r;
  const double *in3_data;
  const double *in4_data;
  const double *in5_data;
  double d;
  double *in1_data;
  double *r1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  in5_data = in5->data;
  in4_data = in4->data;
  in3_data = in3->data;
  in1_data = in1->data;
  d = 0.5 * (double)in2->size[0];
  emxInit_real_T(&r, 1);
  if (in5->size[0] == 1) {
    i = in4->size[0];
  } else {
    i = in5->size[0];
  }
  if (i == 1) {
    if (in3->size[0] == 1) {
      loop_ub = in1->size[0];
    } else {
      loop_ub = in3->size[0];
    }
  } else {
    loop_ub = i;
  }
  i = r->size[0];
  r->size[0] = loop_ub;
  emxEnsureCapacity_real_T(r, i);
  r1 = r->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_2_0 = (in4->size[0] != 1);
  stride_3_0 = (in5->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = (d + in1_data[i * stride_0_0] * in3_data[i * stride_1_0]) +
            in4_data[i * stride_2_0] * in5_data[i * stride_3_0];
  }
  i = in1->size[0];
  in1->size[0] = r->size[0];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = r1[i];
  }
  emxFree_real_T(&r);
}

/*
 * Arguments    : emxArray_real32_T *in1
 *                float in2
 *                const emxArray_real32_T *in3
 *                float in4
 * Return Type  : void
 */
static void binary_expand_op_15(emxArray_real32_T *in1, float in2,
                                const emxArray_real32_T *in3, float in4)
{
  emxArray_real32_T *b_in1;
  const float *in3_data;
  float *b_in1_data;
  float *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in1, 1);
  if (in3->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] =
        in1_data[i * stride_0_0] * in2 + in3_data[i * stride_1_0] * in4;
  }
  i = in1->size[0];
  in1->size[0] = b_in1->size[0];
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real32_T(&b_in1);
}

/*
 * Arguments    : emxArray_real32_T *in1
 *                const emxArray_real32_T *in2
 *                float in3
 *                const emxArray_real32_T *in4
 *                float in5
 * Return Type  : void
 */
static void binary_expand_op_16(emxArray_real32_T *in1,
                                const emxArray_real32_T *in2, float in3,
                                const emxArray_real32_T *in4, float in5)
{
  const float *in2_data;
  const float *in4_data;
  float *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in4_data = in4->data;
  in2_data = in2->data;
  if (in4->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] =
        in2_data[i * stride_0_0] * in3 - in4_data[i * stride_1_0] * in5;
  }
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 *                const emxArray_real32_T *in4
 * Return Type  : void
 */
static void binary_expand_op_9(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const emxArray_real_T *in3,
                               const emxArray_real32_T *in4)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  const double *in3_data;
  double *b_in1_data;
  double *in1_data;
  int b_in4;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0_tmp;
  int stride_2_0;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  b_in4 = in4->size[0];
  emxInit_real_T(&b_in1, 1);
  if (in2->size[0] == 1) {
    i = in3->size[0];
  } else {
    i = in2->size[0];
  }
  if (i == 1) {
    if (in2->size[0] == 1) {
      loop_ub = in1->size[0];
    } else {
      loop_ub = in2->size[0];
    }
  } else {
    loop_ub = i;
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0_tmp = (in2->size[0] != 1);
  stride_2_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    double in1_tmp;
    in1_tmp = in2_data[i * stride_1_0_tmp];
    b_in1_data[i] = in1_data[i * stride_0_0] / in1_tmp +
                    in3_data[i * stride_2_0] / ((double)b_in4 - in1_tmp);
  }
  i = in1->size[0];
  in1->size[0] = b_in1->size[0];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(&b_in1);
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                const emxArray_real32_T *t
 *                const double f_data[]
 *                const int f_size[2]
 *                emxArray_real_T *wk2
 *                emxArray_real32_T *f
 * Return Type  : void
 */
static void fasper(const emxArray_real32_T *x, const emxArray_real32_T *t,
                   const double f_data[], const int f_size[2],
                   emxArray_real_T *wk2, emxArray_real32_T *f)
{
  emxArray_boolean_T *r2;
  emxArray_creal_T *b_wk1;
  emxArray_creal_T *c_wk1;
  emxArray_real32_T *b_y;
  emxArray_real32_T *c_y;
  emxArray_real_T *cwt;
  emxArray_real_T *hc2wt;
  emxArray_real_T *hypo;
  emxArray_real_T *iwk1;
  emxArray_real_T *iwk2;
  emxArray_real_T *r;
  emxArray_real_T *rwk1;
  emxArray_real_T *swt;
  emxArray_real_T *wk1;
  emxArray_real_T *y;
  creal_T *b_wk1_data;
  creal_T *c_wk1_data;
  double nout;
  double *cwt_data;
  double *hc2wt_data;
  double *hypo_data;
  double *iwk1_data;
  double *iwk2_data;
  double *r1;
  double *rwk1_data;
  double *swt_data;
  double *wk1_data;
  const float *t_data;
  const float *x_data;
  float Ts;
  float fac;
  float fac_tmp;
  float fndim;
  float hifac;
  float *b_f_data;
  float *y_data;
  int i;
  int i1;
  int loop_ub;
  int size_tmp_idx_1;
  boolean_T *r3;
  t_data = t->data;
  x_data = x->data;
  Ts = (t_data[t->size[0] - 1] - t_data[0]) / (float)((double)t->size[0] - 1.0);
  if (f_size[0] * f_size[1] == 1) {
    nout = b_round(2.0 * (double)t->size[0]);
    emxInit_real_T(&y, 2);
    wk1_data = y->data;
    if (b_isnan(nout)) {
      size_tmp_idx_1 = 1;
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, i);
      wk1_data = y->data;
      wk1_data[0] = rtNaN;
    } else if (nout < 1.0) {
      size_tmp_idx_1 = 0;
      y->size[0] = 1;
      y->size[1] = 0;
    } else {
      size_tmp_idx_1 = (int)(nout - 1.0) + 1;
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = (int)(nout - 1.0) + 1;
      emxEnsureCapacity_real_T(y, i);
      wk1_data = y->data;
      loop_ub = (int)(nout - 1.0);
      for (i = 0; i <= loop_ub; i++) {
        wk1_data[i] = (double)i + 1.0;
      }
    }
    fac = (float)t->size[0] * Ts * 4.0F;
    emxInit_real32_T(&b_y, 1);
    i = b_y->size[0];
    b_y->size[0] = size_tmp_idx_1;
    emxEnsureCapacity_real32_T(b_y, i);
    y_data = b_y->data;
    for (i = 0; i < size_tmp_idx_1; i++) {
      y_data[i] = (float)wk1_data[i] / fac;
    }
    emxFree_real_T(&y);
    hifac = (float)f_data[0] / maximum(b_y);
    emxFree_real32_T(&b_y);
  } else {
    hifac = 1.0F;
  }
  fndim = 2.0F * b_mpower(e_nextpow2(4.0F * hifac * (float)t->size[0] * 4.0F));
  emxInit_real_T(&wk1, 1);
  size_tmp_idx_1 = (int)fndim;
  i = wk1->size[0];
  wk1->size[0] = (int)fndim;
  emxEnsureCapacity_real_T(wk1, i);
  wk1_data = wk1->data;
  for (i = 0; i < size_tmp_idx_1; i++) {
    wk1_data[i] = 0.0;
  }
  i = wk2->size[0];
  wk2->size[0] = (int)fndim;
  emxEnsureCapacity_real_T(wk2, i);
  wk1_data = wk2->data;
  for (i = 0; i < size_tmp_idx_1; i++) {
    wk1_data[i] = 0.0;
  }
  fac_tmp = (float)t->size[0] * Ts * 4.0F;
  fac = fndim / fac_tmp;
  i = t->size[0];
  for (size_tmp_idx_1 = 0; size_tmp_idx_1 < i; size_tmp_idx_1++) {
    Ts = b_mod((t_data[size_tmp_idx_1] - t_data[0]) * fac, fndim) + 1.0F;
    spread(x_data[size_tmp_idx_1], wk1, fndim, Ts);
    b_spread(wk2, fndim, b_mod(2.0F * (Ts - 1.0F), fndim) + 1.0F);
  }
  fac = c_round(2.0F * hifac * (float)t->size[0]);
  emxInit_real32_T(&c_y, 2);
  y_data = c_y->data;
  if (c_isnan(fac)) {
    i = c_y->size[0] * c_y->size[1];
    c_y->size[0] = 1;
    c_y->size[1] = 1;
    emxEnsureCapacity_real32_T(c_y, i);
    y_data = c_y->data;
    y_data[0] = rtNaNF;
  } else if (fac < 1.0F) {
    c_y->size[0] = 1;
    c_y->size[1] = 0;
  } else {
    i = c_y->size[0] * c_y->size[1];
    c_y->size[0] = 1;
    c_y->size[1] = (int)(fac - 1.0) + 1;
    emxEnsureCapacity_real32_T(c_y, i);
    y_data = c_y->data;
    loop_ub = (int)(fac - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      y_data[i] = (float)((double)i + 1.0);
    }
  }
  i = f->size[0];
  f->size[0] = c_y->size[1];
  emxEnsureCapacity_real32_T(f, i);
  b_f_data = f->data;
  loop_ub = c_y->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_f_data[i] = y_data[i] / fac_tmp;
  }
  emxFree_real32_T(&c_y);
  emxInit_creal_T(&b_wk1);
  fft(wk1, b_wk1);
  b_wk1_data = b_wk1->data;
  if (fac + 1.0F < 2.0F) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = (int)(fac + 1.0F);
  }
  emxInit_real_T(&rwk1, 1);
  loop_ub = i1 - i;
  i1 = rwk1->size[0];
  rwk1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(rwk1, i1);
  rwk1_data = rwk1->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    rwk1_data[i1] = b_wk1_data[i + i1].re;
  }
  if (fac + 1.0F < 2.0F) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = (int)(fac + 1.0F);
  }
  emxInit_real_T(&iwk1, 1);
  loop_ub = i1 - i;
  i1 = iwk1->size[0];
  iwk1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(iwk1, i1);
  iwk1_data = iwk1->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    iwk1_data[i1] = b_wk1_data[i + i1].im;
  }
  fft(wk2, b_wk1);
  b_wk1_data = b_wk1->data;
  if (fac + 1.0F < 2.0F) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = (int)(fac + 1.0F);
  }
  loop_ub = i1 - i;
  i1 = wk1->size[0];
  wk1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(wk1, i1);
  wk1_data = wk1->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    wk1_data[i1] = b_wk1_data[i + i1].re;
  }
  if (fac + 1.0F < 2.0F) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = (int)(fac + 1.0F);
  }
  emxInit_real_T(&iwk2, 1);
  loop_ub = i1 - i;
  i1 = iwk2->size[0];
  iwk2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(iwk2, i1);
  iwk2_data = iwk2->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    iwk2_data[i1] = b_wk1_data[i + i1].im;
  }
  if (fac + 1.0F < 2.0F) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = (int)(fac + 1.0F);
  }
  emxInit_creal_T(&c_wk1);
  loop_ub = i1 - i;
  i1 = c_wk1->size[0];
  c_wk1->size[0] = loop_ub;
  emxEnsureCapacity_creal_T(c_wk1, i1);
  c_wk1_data = c_wk1->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    c_wk1_data[i1] = b_wk1_data[i + i1];
  }
  emxInit_real_T(&r, 1);
  h_abs(c_wk1, r);
  r1 = r->data;
  emxFree_creal_T(&c_wk1);
  emxInit_boolean_T(&r2, 1);
  i = r2->size[0];
  r2->size[0] = r->size[0];
  emxEnsureCapacity_boolean_T(r2, i);
  r3 = r2->data;
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    r3[i] = (r1[i] == 0.0);
  }
  if (c_any(r2)) {
    lombscargle(x, f, t, wk2);
  } else {
    if (fac + 1.0F < 2.0F) {
      i = 0;
      i1 = 0;
    } else {
      i = 1;
      i1 = (int)(fac + 1.0F);
    }
    size_tmp_idx_1 = i1 - i;
    for (i1 = 0; i1 < size_tmp_idx_1; i1++) {
      b_wk1_data[i1] = b_wk1_data[i + i1];
    }
    i = b_wk1->size[0];
    b_wk1->size[0] = size_tmp_idx_1;
    emxEnsureCapacity_creal_T(b_wk1, i);
    emxInit_real_T(&hypo, 1);
    h_abs(b_wk1, hypo);
    hypo_data = hypo->data;
    emxInit_real_T(&hc2wt, 1);
    if (wk1->size[0] == hypo->size[0]) {
      i = hc2wt->size[0];
      hc2wt->size[0] = wk1->size[0];
      emxEnsureCapacity_real_T(hc2wt, i);
      hc2wt_data = hc2wt->data;
      loop_ub = wk1->size[0];
      for (i = 0; i < loop_ub; i++) {
        hc2wt_data[i] = 0.5 * wk1_data[i] / hypo_data[i];
      }
    } else {
      binary_expand_op_14(hc2wt, wk1, hypo);
      hc2wt_data = hc2wt->data;
    }
    if (iwk2->size[0] == hypo->size[0]) {
      i = hypo->size[0];
      hypo->size[0] = iwk2->size[0];
      emxEnsureCapacity_real_T(hypo, i);
      hypo_data = hypo->data;
      loop_ub = iwk2->size[0];
      for (i = 0; i < loop_ub; i++) {
        hypo_data[i] = 0.5 * iwk2_data[i] / hypo_data[i];
      }
    } else {
      binary_expand_op_13(hypo, iwk2);
      hypo_data = hypo->data;
    }
    emxInit_real_T(&cwt, 1);
    i = cwt->size[0];
    cwt->size[0] = hc2wt->size[0];
    emxEnsureCapacity_real_T(cwt, i);
    cwt_data = cwt->data;
    loop_ub = hc2wt->size[0];
    for (i = 0; i < loop_ub; i++) {
      cwt_data[i] = hc2wt_data[i] + 0.5;
    }
    e_sqrt(cwt);
    cwt_data = cwt->data;
    emxInit_real_T(&swt, 1);
    i = swt->size[0];
    swt->size[0] = hypo->size[0];
    emxEnsureCapacity_real_T(swt, i);
    swt_data = swt->data;
    loop_ub = hypo->size[0];
    for (i = 0; i < loop_ub; i++) {
      swt_data[i] = hypo_data[i];
    }
    b_sign(swt);
    swt_data = swt->data;
    i = r->size[0];
    r->size[0] = hc2wt->size[0];
    emxEnsureCapacity_real_T(r, i);
    r1 = r->data;
    loop_ub = hc2wt->size[0];
    for (i = 0; i < loop_ub; i++) {
      r1[i] = 0.5 - hc2wt_data[i];
    }
    e_sqrt(r);
    r1 = r->data;
    if (swt->size[0] == r->size[0]) {
      loop_ub = swt->size[0];
      for (i = 0; i < loop_ub; i++) {
        swt_data[i] *= r1[i];
      }
    } else {
      b_times(swt, r);
      swt_data = swt->data;
    }
    if (hc2wt->size[0] == 1) {
      i = wk1->size[0];
    } else {
      i = hc2wt->size[0];
    }
    if (hypo->size[0] == 1) {
      i1 = iwk2->size[0];
    } else {
      i1 = hypo->size[0];
    }
    if ((hc2wt->size[0] == wk1->size[0]) && (hypo->size[0] == iwk2->size[0]) &&
        (i == i1)) {
      nout = 0.5 * (double)t->size[0];
      loop_ub = hc2wt->size[0];
      for (i = 0; i < loop_ub; i++) {
        hc2wt_data[i] =
            (nout + hc2wt_data[i] * wk1_data[i]) + hypo_data[i] * iwk2_data[i];
      }
    } else {
      binary_expand_op_12(hc2wt, t, wk1, hypo, iwk2);
      hc2wt_data = hc2wt->data;
    }
    emxFree_real_T(&hypo);
    if (cwt->size[0] == 1) {
      i = rwk1->size[0];
    } else {
      i = cwt->size[0];
    }
    if (swt->size[0] == 1) {
      i1 = iwk1->size[0];
    } else {
      i1 = swt->size[0];
    }
    if ((cwt->size[0] == rwk1->size[0]) && (swt->size[0] == iwk1->size[0]) &&
        (i == i1)) {
      i = wk1->size[0];
      wk1->size[0] = cwt->size[0];
      emxEnsureCapacity_real_T(wk1, i);
      wk1_data = wk1->data;
      loop_ub = cwt->size[0];
      for (i = 0; i < loop_ub; i++) {
        wk1_data[i] = cwt_data[i] * rwk1_data[i] + swt_data[i] * iwk1_data[i];
      }
      b_power(wk1, wk2);
      wk1_data = wk2->data;
    } else {
      binary_expand_op_11(wk2, cwt, rwk1, swt, iwk1);
      wk1_data = wk2->data;
    }
    if (cwt->size[0] == 1) {
      i = iwk1->size[0];
    } else {
      i = cwt->size[0];
    }
    if (swt->size[0] == 1) {
      i1 = rwk1->size[0];
    } else {
      i1 = swt->size[0];
    }
    if ((cwt->size[0] == iwk1->size[0]) && (swt->size[0] == rwk1->size[0]) &&
        (i == i1)) {
      loop_ub = cwt->size[0];
      for (i = 0; i < loop_ub; i++) {
        cwt_data[i] = cwt_data[i] * iwk1_data[i] - swt_data[i] * rwk1_data[i];
      }
      b_power(cwt, r);
      r1 = r->data;
    } else {
      binary_expand_op_10(r, cwt, iwk1, swt, rwk1);
      r1 = r->data;
    }
    emxFree_real_T(&swt);
    emxFree_real_T(&cwt);
    if (wk2->size[0] == 1) {
      i = hc2wt->size[0];
    } else {
      i = wk2->size[0];
    }
    if (r->size[0] == 1) {
      i1 = hc2wt->size[0];
    } else {
      i1 = r->size[0];
    }
    if ((wk2->size[0] == hc2wt->size[0]) && (r->size[0] == hc2wt->size[0]) &&
        (i == i1)) {
      loop_ub = wk2->size[0];
      for (i = 0; i < loop_ub; i++) {
        wk1_data[i] = wk1_data[i] / hc2wt_data[i] +
                      r1[i] / ((double)t->size[0] - hc2wt_data[i]);
      }
    } else {
      binary_expand_op_9(wk2, hc2wt, r, t);
    }
    emxFree_real_T(&hc2wt);
  }
  emxFree_boolean_T(&r2);
  emxFree_real_T(&r);
  emxFree_creal_T(&b_wk1);
  emxFree_real_T(&iwk2);
  emxFree_real_T(&iwk1);
  emxFree_real_T(&rwk1);
  emxFree_real_T(&wk1);
}

/*
 * Arguments    : const char freqtype_data[]
 *                const int freqtype_size[2]
 *                float Fs
 *                double SigVar
 * Return Type  : double
 */
static double getChAlpha(const char freqtype_data[], const int freqtype_size[2],
                         float Fs, double SigVar)
{
  double Alpha;
  if (d_strcmp(freqtype_data, freqtype_size)) {
    Alpha = 3.1415926535897931 / SigVar;
  } else {
    Alpha = Fs / (float)(2.0 * SigVar);
  }
  return Alpha;
}

/*
 * Arguments    : int pd_size[2]
 * Return Type  : boolean_T
 */
static boolean_T getProbDensity(int pd_size[2])
{
  boolean_T ignoreArgsIdx;
  ignoreArgsIdx = false;
  pd_size[0] = 0;
  pd_size[1] = 0;
  return ignoreArgsIdx;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                const emxArray_real32_T *f
 *                const emxArray_real32_T *t
 *                emxArray_real_T *P
 * Return Type  : void
 */
static void lombscargle(const emxArray_real32_T *x, const emxArray_real32_T *f,
                        const emxArray_real32_T *t, emxArray_real_T *P)
{
  emxArray_real32_T *cwt;
  emxArray_real32_T *swt;
  emxArray_real32_T *t1;
  emxArray_real32_T *wt;
  double *P_data;
  const float *f_data;
  const float *t_data;
  const float *x_data;
  float swtau;
  float wtau;
  float *cwt_data;
  float *swt_data;
  float *t1_data;
  float *wt_data;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  t_data = t->data;
  f_data = f->data;
  x_data = x->data;
  emxInit_real32_T(&t1, 1);
  if (isrow(t)) {
    i = t1->size[0];
    t1->size[0] = 1;
    emxEnsureCapacity_real32_T(t1, i);
    t1_data = t1->data;
    t1_data[0] = t_data[0];
  } else {
    i = t1->size[0];
    t1->size[0] = t->size[0];
    emxEnsureCapacity_real32_T(t1, i);
    t1_data = t1->data;
    loop_ub = t->size[0];
    for (i = 0; i < loop_ub; i++) {
      t1_data[i] = t_data[i];
    }
  }
  i = P->size[0];
  P->size[0] = f->size[0];
  emxEnsureCapacity_real_T(P, i);
  P_data = P->data;
  i = f->size[0];
  emxInit_real32_T(&wt, 1);
  emxInit_real32_T(&swt, 1);
  emxInit_real32_T(&cwt, 1);
  for (b_i = 0; b_i < i; b_i++) {
    float b_x;
    float c_x;
    wtau = 2.0F * f_data[b_i];
    loop_ub = t1->size[0];
    i1 = wt->size[0];
    wt->size[0] = t1->size[0];
    emxEnsureCapacity_real32_T(wt, i1);
    wt_data = wt->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      wt_data[i1] = wtau * t1_data[i1];
    }
    sinpi(wt, swt);
    swt_data = swt->data;
    cospi(wt, cwt);
    cwt_data = cwt->data;
    if (cwt->size[0] == swt->size[0]) {
      wtau = 0.0F;
      loop_ub = cwt->size[0];
      swtau = 0.0F;
      for (i1 = 0; i1 < loop_ub; i1++) {
        wtau += 2.0F * cwt_data[i1] * swt_data[i1];
        swtau += (cwt_data[i1] - swt_data[i1]) * (cwt_data[i1] + swt_data[i1]);
      }
      wtau = 0.5F * b_atan2(wtau, swtau);
    } else {
      wtau = binary_expand_op_17(cwt, swt);
    }
    swtau = wtau;
    b_sin(&swtau);
    c_cos(&wtau);
    if (swt->size[0] == cwt->size[0]) {
      i1 = wt->size[0];
      wt->size[0] = swt->size[0];
      emxEnsureCapacity_real32_T(wt, i1);
      wt_data = wt->data;
      loop_ub = swt->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        wt_data[i1] = swt_data[i1] * wtau - cwt_data[i1] * swtau;
      }
    } else {
      binary_expand_op_16(wt, swt, wtau, cwt, swtau);
      wt_data = wt->data;
    }
    if (cwt->size[0] == swt->size[0]) {
      loop_ub = cwt->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        cwt_data[i1] = cwt_data[i1] * wtau + swt_data[i1] * swtau;
      }
    } else {
      binary_expand_op_15(cwt, wtau, swt, swtau);
      cwt_data = cwt->data;
    }
    wtau = 0.0F;
    loop_ub = wt->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      wtau += wt_data[i1] * wt_data[i1];
    }
    swtau = 0.0F;
    loop_ub = cwt->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      swtau += cwt_data[i1] * cwt_data[i1];
    }
    if (g_abs(wtau) < 2.22044605E-16F) {
      wtau += 2.22044605E-16F;
    }
    if (g_abs(swtau) < 2.22044605E-16F) {
      swtau += 2.22044605E-16F;
    }
    b_x = 0.0F;
    loop_ub = x->size[0];
    c_x = 0.0F;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_x += x_data[i1] * cwt_data[i1];
      c_x += x_data[i1] * wt_data[i1];
    }
    P_data[b_i] = b_x * b_x / swtau + c_x * c_x / wtau;
  }
  emxFree_real32_T(&cwt);
  emxFree_real32_T(&swt);
  emxFree_real32_T(&wt);
  emxFree_real32_T(&t1);
}

/*
 * Arguments    : int f_size[2]
 *                boolean_T *ignoreArgsIdx
 * Return Type  : boolean_T
 */
static boolean_T parseAndCacheFrequencyVector(int f_size[2],
                                              boolean_T *ignoreArgsIdx)
{
  boolean_T fvecSpecified;
  *ignoreArgsIdx = true;
  fvecSpecified = false;
  f_size[0] = 0;
  f_size[1] = 0;
  return fvecSpecified;
}

/*
 * Arguments    : const cell_wrap_78 *arglist
 *                float t_data[]
 *                int t_size[2]
 *                float Fs_data[]
 *                int Fs_size[2]
 *                boolean_T *ignoreArgsIdx
 * Return Type  : boolean_T
 */
static boolean_T parseAndCacheTimeVector(const cell_wrap_78 *arglist,
                                         float t_data[], int t_size[2],
                                         float Fs_data[], int Fs_size[2],
                                         boolean_T *ignoreArgsIdx)
{
  boolean_T tflag;
  tflag = false;
  if (arglist->f1.size[1] == 1) {
    int loop_ub;
    Fs_size[0] = 1;
    Fs_size[1] = arglist->f1.size[1];
    loop_ub = arglist->f1.size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&Fs_data[0], &arglist->f1.data[0],
             (unsigned int)loop_ub * sizeof(float));
    }
    t_size[0] = 0;
    t_size[1] = 0;
  } else {
    int loop_ub;
    tflag = (arglist->f1.size[1] != 0);
    t_size[0] = arglist->f1.size[1];
    t_size[1] = 1;
    loop_ub = arglist->f1.size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&t_data[0], &arglist->f1.data[0],
             (unsigned int)loop_ub * sizeof(float));
    }
    Fs_size[0] = 0;
    Fs_size[1] = 0;
  }
  *ignoreArgsIdx = true;
  return tflag;
}

/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 *                const cell_wrap_78 *arglist
 *                float x1_data[]
 *                emxArray_real32_T *t
 *                double ofac_data[]
 *                int ofac_size[2]
 *                char freqtype_data[]
 *                int freqtype_size[2]
 *                int f_size[2]
 *                boolean_T *tflag
 *                int ProbDet_size[2]
 *                float *Fs
 *                boolean_T *fvecSpecified
 * Return Type  : int
 */
static int parseAndValidateInputs(const float x_data[], const int x_size[2],
                                  const cell_wrap_78 *arglist, float x1_data[],
                                  emxArray_real32_T *t, double ofac_data[],
                                  int ofac_size[2], char freqtype_data[],
                                  int freqtype_size[2], int f_size[2],
                                  boolean_T *tflag, int ProbDet_size[2],
                                  float *Fs, boolean_T *fvecSpecified)
{
  static const char b_cv[8] = {'r', 'a', 'd', '/', 's', 'a', 'm', 'p'};
  emxArray_boolean_T *r;
  emxArray_int32_T *r2;
  emxArray_real32_T b_t;
  float Fs_data[400];
  float *t_data;
  int Fs_size[2];
  int c_t;
  int i;
  int loop_ub;
  int x1_size;
  int y_size_idx_1;
  int *r3;
  boolean_T ignoreArgsIdx;
  boolean_T *r1;
  freqtype_size[0] = 1;
  freqtype_size[1] = 8;
  for (i = 0; i < 8; i++) {
    freqtype_data[i] = b_cv[i];
  }
  x1_size = x_size[1];
  loop_ub = x_size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&x1_data[0], &x_data[0], (unsigned int)loop_ub * sizeof(float));
  }
  ignoreArgsIdx = getProbDensity(ProbDet_size);
  emxReserve_real32_T(t);
  t_data = t->data;
  *tflag =
      parseAndCacheTimeVector(arglist, (float *)t->data, *(int(*)[2])t->size,
                              Fs_data, Fs_size, &ignoreArgsIdx);
  if ((*tflag) || ((Fs_size[0] != 0) && (Fs_size[1] != 0))) {
    freqtype_size[0] = 1;
    freqtype_size[1] = 2;
    freqtype_data[0] = 'H';
    freqtype_data[1] = 'z';
  }
  *fvecSpecified = parseAndCacheFrequencyVector(f_size, &ignoreArgsIdx);
  if ((t->size[0] == 0) || (t->size[1] == 0)) {
    if ((Fs_size[0] != 0) && (Fs_size[1] != 0)) {
      double y_data[400];
      float b;
      if (b_isnan((double)x_size[1] - 1.0)) {
        y_size_idx_1 = 1;
        y_data[0] = rtNaN;
      } else {
        y_size_idx_1 = x_size[1];
        loop_ub = x_size[1] - 1;
        for (i = 0; i <= loop_ub; i++) {
          y_data[i] = i;
        }
      }
      b = 1.0F / Fs_data[0];
      i = t->size[0] * t->size[1];
      t->size[0] = 1;
      t->size[1] = y_size_idx_1;
      emxEnsureCapacity_real32_T(t, i);
      t_data = t->data;
      for (i = 0; i < y_size_idx_1; i++) {
        t_data[i] = (float)y_data[i] * b;
      }
    } else {
      double y_data[400];
      if (b_isnan((double)x_size[1] - 1.0)) {
        y_size_idx_1 = 1;
        y_data[0] = rtNaN;
      } else {
        y_size_idx_1 = x_size[1];
        loop_ub = x_size[1] - 1;
        for (i = 0; i <= loop_ub; i++) {
          y_data[i] = i;
        }
      }
      i = t->size[0] * t->size[1];
      t->size[0] = 1;
      t->size[1] = y_size_idx_1;
      emxEnsureCapacity_real32_T(t, i);
      t_data = t->data;
      for (i = 0; i < y_size_idx_1; i++) {
        t_data[i] = (float)y_data[i];
      }
    }
  }
  loop_ub = t->size[0] * t->size[1];
  b_t = *t;
  c_t = loop_ub;
  b_t.size = &c_t;
  b_t.numDimensions = 1;
  emxInit_boolean_T(&r, 1);
  d_isnan(&b_t, r);
  r1 = r->data;
  y_size_idx_1 = r->size[0] - 1;
  loop_ub = 0;
  for (i = 0; i <= y_size_idx_1; i++) {
    if (!r1[i]) {
      loop_ub++;
    }
  }
  emxInit_int32_T(&r2, 1);
  i = r2->size[0];
  r2->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(r2, i);
  r3 = r2->data;
  loop_ub = 0;
  for (i = 0; i <= y_size_idx_1; i++) {
    if (!r1[i]) {
      r3[loop_ub] = i;
      loop_ub++;
    }
  }
  emxFree_boolean_T(&r);
  *Fs = (float)((double)r2->size[0] - 1.0) /
        (t_data[r3[r2->size[0] - 1]] - t_data[r3[0]]);
  emxFree_int32_T(&r2);
  ofac_size[0] = 1;
  ofac_size[1] = 1;
  ofac_data[0] = 4.0;
  *fvecSpecified = false;
  return x1_size;
}

/*
 * Arguments    : float y
 *                emxArray_real_T *yy
 *                float n
 *                float x
 * Return Type  : void
 */
static void spread(float y, emxArray_real_T *yy, float n, float x)
{
  emxArray_real32_T *b_x;
  emxArray_real32_T *b_y;
  double ndenl;
  double *yy_data;
  float *x_data;
  float *y_data;
  int ia;
  int k;
  yy_data = yy->data;
  ndenl = 6.0;
  if (x == c_round(x)) {
    yy_data[(int)x - 1] = (float)yy_data[(int)x - 1] + y;
  } else {
    float fv[2];
    float f;
    float ilo;
    fv[0] = b_floor((x - 2.0F) + 1.0F);
    fv[1] = 1.0F;
    f = e_maximum(fv);
    fv[0] = f;
    fv[1] = (n - 4.0F) + 1.0F;
    ilo = c_minimum(fv);
    emxInit_real32_T(&b_y, 2);
    y_data = b_y->data;
    if (c_isnan(ilo + 1.0F) || c_isnan((ilo + 4.0F) - 1.0F)) {
      k = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = 1;
      emxEnsureCapacity_real32_T(b_y, k);
      y_data = b_y->data;
      y_data[0] = rtNaNF;
    } else if ((ilo + 4.0F) - 1.0F < ilo + 1.0F) {
      b_y->size[0] = 1;
      b_y->size[1] = 0;
    } else if ((b_isinf(ilo + 1.0F) || b_isinf((ilo + 4.0F) - 1.0F)) &&
               (ilo + 1.0F == (ilo + 4.0F) - 1.0F)) {
      k = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = 1;
      emxEnsureCapacity_real32_T(b_y, k);
      y_data = b_y->data;
      y_data[0] = rtNaNF;
    } else if (b_floor(ilo + 1.0F) == ilo + 1.0F) {
      if ((g_abs(ilo + 1.0F) >= 1.07374182E+9F) ||
          (g_abs((ilo + 4.0F) - 1.0F) >= 1.07374182E+9F)) {
        k = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        ia = (int)((double)((ilo + 4.0F) - 1.0F) - (ilo + 1.0F));
        b_y->size[1] = ia + 1;
        emxEnsureCapacity_real32_T(b_y, k);
        y_data = b_y->data;
        for (k = 0; k <= ia; k++) {
          y_data[k] = (float)((ilo + 1.0F) + (double)k);
        }
      } else {
        int n_tmp;
        ia = (int)floorf(ilo + 1.0F);
        n_tmp = (int)floorf(c_fix((ilo + 4.0F) - 1.0F)) - ia;
        k = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = n_tmp + 1;
        emxEnsureCapacity_real32_T(b_y, k);
        y_data = b_y->data;
        for (k = 0; k <= n_tmp; k++) {
          y_data[k] = (float)(ia + k);
        }
      }
    } else {
      eml_float_colon(ilo + 1.0F, (ilo + 4.0F) - 1.0F, b_y);
      y_data = b_y->data;
    }
    emxInit_real32_T(&b_x, 2);
    k = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = b_y->size[1];
    emxEnsureCapacity_real32_T(b_x, k);
    x_data = b_x->data;
    ia = b_y->size[1];
    for (k = 0; k < ia; k++) {
      x_data[k] = x - y_data[k];
    }
    emxFree_real32_T(&b_y);
    f = y * ((x - ilo) * prod(b_x));
    emxFree_real32_T(&b_x);
    yy_data[(int)((ilo + 4.0F) - 1.0F) - 1] =
        (float)yy_data[(int)((ilo + 4.0F) - 1.0F) - 1] +
        f / (6.0F * (x - ((ilo + 4.0F) - 1.0F)));
    k = (int)-(ilo + (-1.0F - (((ilo + 4.0F) - 1.0F) - 1.0F)));
    for (ia = 0; ia < k; ia++) {
      float j;
      j = (((ilo + 4.0F) - 1.0F) - 1.0F) - (float)ia;
      ndenl = (float)ndenl / ((j + 1.0F) - ilo) * (j - ((ilo + 4.0F) - 1.0F));
      yy_data[(int)j - 1] =
          (float)yy_data[(int)j - 1] + f / ((float)ndenl * (x - j));
    }
  }
}

/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 *                const float varargin_1_data[]
 *                const int varargin_1_size[2]
 *                emxArray_real32_T *varargout_1
 *                emxArray_real32_T *varargout_2
 * Return Type  : void
 */
void plomb(const float x_data[], const int x_size[2],
           const float varargin_1_data[], const int varargin_1_size[2],
           emxArray_real32_T *varargout_1, emxArray_real32_T *varargout_2)
{
  cell_wrap_78 inputArgs;
  emxArray_int32_T *indx;
  emxArray_real32_T *Px;
  emxArray_real32_T *b;
  emxArray_real32_T *fr1;
  emxArray_real32_T *sig;
  emxArray_real32_T *t;
  emxArray_real32_T *tout;
  emxArray_real_T *Px1;
  double Ch_SigAndTNanPos_data[400];
  double Ch_SigMean;
  double PNaNPos;
  double b_expl_temp;
  double expl_temp;
  double f_data;
  double p;
  double *Px1_data;
  float xp_data[400];
  float Fs;
  float *sig_data;
  float *t_data;
  float *tout_data;
  float *varargout_1_data;
  int Ch_SigAndTNanPos_size[2];
  int ProbDet_size[2];
  int f_size[2];
  int freqtype_size[2];
  int ofac_size[2];
  int end_tmp;
  int i;
  int sizes_idx_0;
  int sizes_idx_1;
  int *indx_data;
  short b_tmp_data[400];
  short c_tmp_data[400];
  char freqtype_data[8];
  boolean_T a__1;
  boolean_T fvecSpecified;
  convertStringsToChars(varargin_1_data, varargin_1_size, inputArgs.f1.data,
                        inputArgs.f1.size);
  emxInit_real32_T(&t, 2);
  sizes_idx_0 = parseAndValidateInputs(
      x_data, x_size, &inputArgs, xp_data, t, (double *)&PNaNPos, ofac_size,
      freqtype_data, freqtype_size, f_size, &a__1, ProbDet_size, &Fs,
      &fvecSpecified);
  t_data = t->data;
  a__1 = MarkMissingData(xp_data, sizes_idx_0, t, (double *)&f_data, f_size,
                         (double *)&PNaNPos, ofac_size, freqtype_data,
                         freqtype_size, Fs, Ch_SigAndTNanPos_data, ProbDet_size,
                         &Ch_SigMean, &p, &expl_temp, &b_expl_temp);
  PNaNPos = 0.0;
  emxInit_real32_T(&sig, 1);
  i = sig->size[0];
  sig->size[0] = sizes_idx_0;
  emxEnsureCapacity_real32_T(sig, i);
  sig_data = sig->data;
  for (i = 0; i < sizes_idx_0; i++) {
    sig_data[i] = xp_data[i];
  }
  emxInit_real32_T(&tout, 1);
  if (a__1) {
    int b_Ch_SigAndTNanPos_data[400];
    boolean_T tmp_data[400];
    sizes_idx_0 = ProbDet_size[1];
    for (i = 0; i < sizes_idx_0; i++) {
      tmp_data[i] = (Ch_SigAndTNanPos_data[i] > 0.0);
    }
    end_tmp = ProbDet_size[1] - 1;
    sizes_idx_1 = 0;
    sizes_idx_0 = 0;
    for (i = 0; i <= end_tmp; i++) {
      if (tmp_data[i]) {
        sizes_idx_1++;
        b_tmp_data[sizes_idx_0] = (short)i;
        sizes_idx_0++;
      }
    }
    Ch_SigAndTNanPos_size[0] = 1;
    Ch_SigAndTNanPos_size[1] = sizes_idx_1;
    for (i = 0; i < sizes_idx_1; i++) {
      b_Ch_SigAndTNanPos_data[i] = (int)Ch_SigAndTNanPos_data[b_tmp_data[i]];
    }
    b_nullAssignment(sig, b_Ch_SigAndTNanPos_data, Ch_SigAndTNanPos_size);
    sig_data = sig->data;
    sizes_idx_0 = ProbDet_size[1];
    for (i = 0; i < sizes_idx_0; i++) {
      tmp_data[i] = (Ch_SigAndTNanPos_data[i] > 0.0);
    }
    sizes_idx_0 = t->size[0] * t->size[1];
    i = tout->size[0];
    tout->size[0] = sizes_idx_0;
    emxEnsureCapacity_real32_T(tout, i);
    tout_data = tout->data;
    for (i = 0; i < sizes_idx_0; i++) {
      tout_data[i] = t_data[i];
    }
    sizes_idx_1 = 0;
    sizes_idx_0 = 0;
    for (i = 0; i <= end_tmp; i++) {
      if (tmp_data[i]) {
        sizes_idx_1++;
        c_tmp_data[sizes_idx_0] = (short)i;
        sizes_idx_0++;
      }
    }
    Ch_SigAndTNanPos_size[0] = 1;
    Ch_SigAndTNanPos_size[1] = sizes_idx_1;
    for (i = 0; i < sizes_idx_1; i++) {
      b_Ch_SigAndTNanPos_data[i] = (int)Ch_SigAndTNanPos_data[c_tmp_data[i]];
    }
    b_nullAssignment(tout, b_Ch_SigAndTNanPos_data, Ch_SigAndTNanPos_size);
    tout_data = tout->data;
  } else {
    sizes_idx_0 = t->size[0] * t->size[1];
    i = tout->size[0];
    tout->size[0] = sizes_idx_0;
    emxEnsureCapacity_real32_T(tout, i);
    tout_data = tout->data;
    for (i = 0; i < sizes_idx_0; i++) {
      tout_data[i] = t_data[i];
    }
  }
  emxFree_real32_T(&t);
  emxInit_real32_T(&b, 1);
  emxInit_int32_T(&indx, 1);
  c_unique_vector(tout, b, indx);
  indx_data = indx->data;
  i = b->size[0];
  b->size[0] = indx->size[0];
  emxEnsureCapacity_real32_T(b, i);
  t_data = b->data;
  sizes_idx_0 = indx->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    t_data[i] = sig_data[indx_data[i] - 1];
  }
  i = sig->size[0];
  sig->size[0] = b->size[0];
  emxEnsureCapacity_real32_T(sig, i);
  sig_data = sig->data;
  sizes_idx_0 = b->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    sig_data[i] = t_data[i];
  }
  i = b->size[0];
  b->size[0] = indx->size[0];
  emxEnsureCapacity_real32_T(b, i);
  t_data = b->data;
  sizes_idx_0 = indx->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    t_data[i] = tout_data[indx_data[i] - 1];
  }
  emxFree_int32_T(&indx);
  i = tout->size[0];
  tout->size[0] = b->size[0];
  emxEnsureCapacity_real32_T(tout, i);
  tout_data = tout->data;
  sizes_idx_0 = b->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    tout_data[i] = t_data[i];
  }
  emxFree_real32_T(&b);
  p = c_nextpow2(sig->size[0]) - 1.0;
  if (sig->size[0] == mpower(p) + 1.0) {
    PNaNPos = mpower(p + 1.0);
  }
  sizes_idx_0 = sig->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    sig_data[i] -= (float)Ch_SigMean;
  }
  emxInit_real_T(&Px1, 1);
  emxInit_real32_T(&fr1, 1);
  fasper(sig, tout, (double *)&f_data, f_size, Px1, fr1);
  t_data = fr1->data;
  Px1_data = Px1->data;
  emxInit_real32_T(&Px, 1);
  i = Px->size[0];
  Px->size[0] = Px1->size[0];
  emxEnsureCapacity_real32_T(Px, i);
  sig_data = Px->data;
  sizes_idx_0 = Px1->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    sig_data[i] = (float)Px1_data[i];
  }
  emxFree_real_T(&Px1);
  i = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = fr1->size[0];
  varargout_2->size[1] = 1;
  emxEnsureCapacity_real32_T(varargout_2, i);
  tout_data = varargout_2->data;
  sizes_idx_0 = fr1->size[0];
  for (i = 0; i < sizes_idx_0; i++) {
    tout_data[i] = t_data[i];
  }
  if (PNaNPos > 0.0) {
    PNaNPos = mpower(p + 1.0);
    if (PNaNPos <= intlength(fr1->size[0])) {
      p = b_lombscargle(sig, t_data[(int)PNaNPos - 1], tout);
      sig_data[(int)PNaNPos - 1] = (float)p;
    }
  }
  emxFree_real32_T(&tout);
  emxFree_real32_T(&sig);
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
  i = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = sizes_idx_0;
  varargout_1->size[1] = sizes_idx_1;
  emxEnsureCapacity_real32_T(varargout_1, i);
  varargout_1_data = varargout_1->data;
  for (i = 0; i < sizes_idx_1; i++) {
    for (end_tmp = 0; end_tmp < sizes_idx_0; end_tmp++) {
      varargout_1_data[end_tmp] = sig_data[end_tmp];
    }
  }
  emxFree_real32_T(&Px);
  if (b_strcmp(freqtype_data, freqtype_size)) {
    sizes_idx_0 = 0;
  } else if (c_strcmp(freqtype_data, freqtype_size)) {
    sizes_idx_0 = 1;
  } else {
    sizes_idx_0 = -1;
  }
  switch (sizes_idx_0) {
  case 0:
    i = varargout_2->size[0] * varargout_2->size[1];
    varargout_2->size[0] = fr1->size[0];
    varargout_2->size[1] = 1;
    emxEnsureCapacity_real32_T(varargout_2, i);
    tout_data = varargout_2->data;
    sizes_idx_0 = fr1->size[0];
    for (i = 0; i < sizes_idx_0; i++) {
      tout_data[i] = t_data[i] * 6.28318548F / Fs;
    }
    sizes_idx_0 = varargout_1->size[0] * varargout_1->size[1];
    for (i = 0; i < sizes_idx_0; i++) {
      varargout_1_data[i] /= 6.28318548F;
    }
    break;
  case 1:
    sizes_idx_0 = varargout_1->size[0] * varargout_1->size[1];
    for (i = 0; i < sizes_idx_0; i++) {
      varargout_1_data[i] /= Fs;
    }
    break;
  }
  emxFree_real32_T(&fr1);
}

/*
 * File trailer for plomb.c
 *
 * [EOF]
 */
