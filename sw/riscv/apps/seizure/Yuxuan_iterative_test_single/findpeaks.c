/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: findpeaks.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "findpeaks.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "eml_setop.h"
#include "introsort.h"
#include "isinf.h"
#include "isnan.h"
#include "length.h"
#include "mergesort.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void assignOutputs(const emxArray_real32_T *y, const emxArray_real_T *x,
                          const emxArray_int32_T *iPk,
                          emxArray_real32_T *YpkOut, emxArray_real_T *XpkOut);

static void c_findPeaksSeparatedByMoreThanM(const emxArray_real32_T *y,
                                            const emxArray_real_T *x,
                                            const emxArray_int32_T *iPk,
                                            emxArray_int32_T *idx);

static void combinePeaks(const emxArray_int32_T *iPk,
                         const emxArray_int32_T *iInf,
                         emxArray_int32_T *iPkOut);

static void getAllPeaksCodegen(const emxArray_real32_T *y,
                               emxArray_int32_T *iPk, emxArray_int32_T *iInf,
                               emxArray_int32_T *iInflect);

static double parse_inputs(const emxArray_real32_T *Yin, emxArray_real_T *x);

static void removeSmallPeaks(const emxArray_real32_T *y,
                             const emxArray_int32_T *iFinite,
                             emxArray_int32_T *iPk);

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *y
 *                const emxArray_real_T *x
 *                const emxArray_int32_T *iPk
 *                emxArray_real32_T *YpkOut
 *                emxArray_real_T *XpkOut
 * Return Type  : void
 */
static void assignOutputs(const emxArray_real32_T *y, const emxArray_real_T *x,
                          const emxArray_int32_T *iPk,
                          emxArray_real32_T *YpkOut, emxArray_real_T *XpkOut)
{
  const double *x_data;
  double *XpkOut_data;
  const float *y_data;
  float *YpkOut_data;
  const int *iPk_data;
  int i;
  int loop_ub;
  iPk_data = iPk->data;
  x_data = x->data;
  y_data = y->data;
  i = YpkOut->size[0];
  YpkOut->size[0] = iPk->size[0];
  emxEnsureCapacity_real32_T(YpkOut, i);
  YpkOut_data = YpkOut->data;
  loop_ub = iPk->size[0];
  i = XpkOut->size[0];
  XpkOut->size[0] = iPk->size[0];
  emxEnsureCapacity_real_T(XpkOut, i);
  XpkOut_data = XpkOut->data;
  for (i = 0; i < loop_ub; i++) {
    YpkOut_data[i] = y_data[iPk_data[i] - 1];
    XpkOut_data[i] = x_data[iPk_data[i] - 1];
  }
}

/*
 * Arguments    : const emxArray_real32_T *y
 *                const emxArray_real_T *x
 *                const emxArray_int32_T *iPk
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
static void c_findPeaksSeparatedByMoreThanM(const emxArray_real32_T *y,
                                            const emxArray_real_T *x,
                                            const emxArray_int32_T *iPk,
                                            emxArray_int32_T *idx)
{
  emxArray_boolean_T *idelete;
  emxArray_int32_T *d_sortIdx;
  emxArray_int32_T *r;
  emxArray_real32_T *b_y;
  const double *x_data;
  const float *y_data;
  float *b_y_data;
  const int *iPk_data;
  int b_i;
  int i;
  int jj;
  int *idx_data;
  int *r1;
  int *sortIdx_data;
  boolean_T *idelete_data;
  iPk_data = iPk->data;
  x_data = x->data;
  y_data = y->data;
  emxInit_int32_T(&d_sortIdx, 1);
  emxInit_boolean_T(&idelete, 1);
  emxInit_int32_T(&r, 1);
  emxInit_real32_T(&b_y, 1);
  if (iPk->size[0] == 0) {
    idx->size[0] = 0;
  } else {
    double d;
    int loop_ub;
    i = d_sortIdx->size[0];
    d_sortIdx->size[0] = iPk->size[0];
    emxEnsureCapacity_int32_T(d_sortIdx, i);
    i = b_y->size[0];
    b_y->size[0] = iPk->size[0];
    emxEnsureCapacity_real32_T(b_y, i);
    b_y_data = b_y->data;
    loop_ub = iPk->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_y_data[i] = y_data[iPk_data[i] - 1];
    }
    b_mergesort(d_sortIdx, b_y, iPk->size[0]);
    sortIdx_data = d_sortIdx->data;
    i = idelete->size[0];
    idelete->size[0] = d_sortIdx->size[0];
    emxEnsureCapacity_boolean_T(idelete, i);
    idelete_data = idelete->data;
    loop_ub = d_sortIdx->size[0];
    for (i = 0; i < loop_ub; i++) {
      idelete_data[i] = false;
    }
    d = varargin_numel(d_sortIdx->size[0]);
    i = (int)d;
    for (b_i = 0; b_i < i; b_i++) {
      if (!idelete_data[b_i]) {
        loop_ub = (int)-((-1.0 - d) + 1.0);
        for (jj = 0; jj < loop_ub; jj++) {
          double b_jj;
          double idelete_tmp;
          float b_idelete_tmp;
          b_jj = d - (double)jj;
          idelete_tmp = x_data[iPk_data[sortIdx_data[(int)b_jj - 1] - 1] - 1];
          b_idelete_tmp = (float)x_data[iPk_data[sortIdx_data[b_i] - 1] - 1];
          idelete_data[(int)b_jj - 1] =
              (idelete_data[(int)b_jj - 1] ||
               ((idelete_tmp >= b_idelete_tmp - 77.0F) &&
                (idelete_tmp <= b_idelete_tmp + 77.0F)));
        }
        idelete_data[b_i] = false;
      }
    }
    jj = idelete->size[0] - 1;
    loop_ub = 0;
    for (b_i = 0; b_i <= jj; b_i++) {
      if (!idelete_data[b_i]) {
        loop_ub++;
      }
    }
    i = r->size[0];
    r->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r, i);
    r1 = r->data;
    loop_ub = 0;
    for (b_i = 0; b_i <= jj; b_i++) {
      if (!idelete_data[b_i]) {
        r1[loop_ub] = b_i;
        loop_ub++;
      }
    }
    i = idx->size[0];
    idx->size[0] = r->size[0];
    emxEnsureCapacity_int32_T(idx, i);
    idx_data = idx->data;
    loop_ub = r->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx_data[i] = sortIdx_data[r1[i]];
    }
    if (r->size[0] != 0) {
      introsort(idx, r->size[0]);
    }
  }
  emxFree_real32_T(&b_y);
  emxFree_int32_T(&r);
  emxFree_boolean_T(&idelete);
  emxFree_int32_T(&d_sortIdx);
}

/*
 * Arguments    : const emxArray_int32_T *iPk
 *                const emxArray_int32_T *iInf
 *                emxArray_int32_T *iPkOut
 * Return Type  : void
 */
static void combinePeaks(const emxArray_int32_T *iPk,
                         const emxArray_int32_T *iInf, emxArray_int32_T *iPkOut)
{
  emxArray_int32_T *ia;
  emxArray_int32_T *ib;
  emxInit_int32_T(&ia, 1);
  emxInit_int32_T(&ib, 1);
  do_vectors(iPk, iInf, iPkOut, ia, ib);
  emxFree_int32_T(&ib);
  emxFree_int32_T(&ia);
}

/*
 * Arguments    : const emxArray_real32_T *y
 *                emxArray_int32_T *iPk
 *                emxArray_int32_T *iInf
 *                emxArray_int32_T *iInflect
 * Return Type  : void
 */
static void getAllPeaksCodegen(const emxArray_real32_T *y,
                               emxArray_int32_T *iPk, emxArray_int32_T *iInf,
                               emxArray_int32_T *iInflect)
{
  const float *y_data;
  float ykfirst;
  int k;
  int kfirst;
  int nInf;
  int nInflect;
  int nPk;
  int ny;
  int *iInf_data;
  int *iInflect_data;
  int *iPk_data;
  char dir;
  boolean_T isinfykfirst;
  y_data = y->data;
  ny = iPk->size[0];
  iPk->size[0] = y->size[0];
  emxEnsureCapacity_int32_T(iPk, ny);
  iPk_data = iPk->data;
  ny = iInf->size[0];
  iInf->size[0] = y->size[0];
  emxEnsureCapacity_int32_T(iInf, ny);
  iInf_data = iInf->data;
  ny = iInflect->size[0];
  iInflect->size[0] = y->size[0];
  emxEnsureCapacity_int32_T(iInflect, ny);
  iInflect_data = iInflect->data;
  ny = y->size[0];
  nPk = 0;
  nInf = 0;
  nInflect = -1;
  dir = 'n';
  kfirst = 0;
  ykfirst = rtInfF;
  isinfykfirst = true;
  for (k = 1; k <= ny; k++) {
    float yk;
    boolean_T isinfyk;
    yk = y_data[k - 1];
    if (c_isnan(yk)) {
      yk = rtInfF;
      isinfyk = true;
    } else if (b_isinf(yk) && (yk > 0.0F)) {
      isinfyk = true;
      nInf++;
      iInf_data[nInf - 1] = k;
    } else {
      isinfyk = false;
    }
    if (yk != ykfirst) {
      char previousdir;
      previousdir = dir;
      if (isinfyk || isinfykfirst) {
        dir = 'n';
        if (kfirst >= 1) {
          nInflect++;
          iInflect_data[nInflect] = kfirst;
        }
      } else if (yk < ykfirst) {
        dir = 'd';
        if (previousdir != 'd') {
          nInflect++;
          iInflect_data[nInflect] = kfirst;
          if (previousdir == 'i') {
            nPk++;
            iPk_data[nPk - 1] = kfirst;
          }
        }
      } else {
        dir = 'i';
        if (previousdir != 'i') {
          nInflect++;
          iInflect_data[nInflect] = kfirst;
        }
      }
      ykfirst = yk;
      kfirst = k;
      isinfykfirst = isinfyk;
    }
  }
  if ((y->size[0] > 0) && (!isinfykfirst) &&
      ((nInflect + 1 == 0) || (iInflect_data[nInflect] < y->size[0]))) {
    nInflect++;
    iInflect_data[nInflect] = y->size[0];
  }
  ny = iPk->size[0];
  if (nPk < 1) {
    iPk->size[0] = 0;
  } else {
    iPk->size[0] = nPk;
  }
  emxEnsureCapacity_int32_T(iPk, ny);
  ny = iInf->size[0];
  if (nInf < 1) {
    iInf->size[0] = 0;
  } else {
    iInf->size[0] = nInf;
  }
  emxEnsureCapacity_int32_T(iInf, ny);
  ny = iInflect->size[0];
  if (nInflect + 1 < 1) {
    nInflect = -1;
  }
  iInflect->size[0] = nInflect + 1;
  emxEnsureCapacity_int32_T(iInflect, ny);
}

/*
 * Arguments    : const emxArray_real32_T *Yin
 *                emxArray_real_T *x
 * Return Type  : double
 */
static double parse_inputs(const emxArray_real32_T *Yin, emxArray_real_T *x)
{
  emxArray_real_T *y;
  double *x_data;
  double *y_data;
  int i;
  int loop_ub;
  emxInit_real_T(&y, 2);
  if (b_isnan(Yin->size[0])) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    y_data[0] = rtNaN;
  } else {
    i = Yin->size[0];
    loop_ub = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = i;
    emxEnsureCapacity_real_T(y, loop_ub);
    y_data = y->data;
    loop_ub = i - 1;
    for (i = 0; i <= loop_ub; i++) {
      y_data[i] = (double)i + 1.0;
    }
  }
  i = x->size[0];
  x->size[0] = y->size[1];
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  loop_ub = y->size[1];
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = y_data[i];
  }
  emxFree_real_T(&y);
  loop_ub = Yin->size[0];
  return loop_ub;
}

/*
 * Arguments    : const emxArray_real32_T *y
 *                const emxArray_int32_T *iFinite
 *                emxArray_int32_T *iPk
 * Return Type  : void
 */
static void removeSmallPeaks(const emxArray_real32_T *y,
                             const emxArray_int32_T *iFinite,
                             emxArray_int32_T *iPk)
{
  const float *y_data;
  const int *iFinite_data;
  int k;
  int n;
  int nPk;
  int *iPk_data;
  iFinite_data = iFinite->data;
  y_data = y->data;
  n = iPk->size[0];
  iPk->size[0] = iFinite->size[0];
  emxEnsureCapacity_int32_T(iPk, n);
  iPk_data = iPk->data;
  nPk = 0;
  n = iFinite->size[0];
  for (k = 0; k < n; k++) {
    float f;
    f = y_data[iFinite_data[k] - 1];
    if ((f > rtMinusInfF) &&
        (f - maximum2(y_data[iFinite_data[k] - 2], y_data[iFinite_data[k]]) >=
         0.0F)) {
      nPk++;
      iPk_data[nPk - 1] = iFinite_data[k];
    }
  }
  n = iPk->size[0];
  iPk->size[0] = nPk;
  emxEnsureCapacity_int32_T(iPk, n);
}

/*
 * Arguments    : const emxArray_real32_T *Yin
 *                emxArray_real32_T *Ypk
 *                emxArray_real_T *Xpk
 * Return Type  : void
 */
void findpeaks(const emxArray_real32_T *Yin, emxArray_real32_T *Ypk,
               emxArray_real_T *Xpk)
{
  emxArray_int32_T *b_iPk;
  emxArray_int32_T *fPk;
  emxArray_int32_T *iInfinite;
  emxArray_int32_T *iPk;
  emxArray_real_T *x;
  double maxN;
  int i;
  int loop_ub;
  int *b_iPk_data;
  int *fPk_data;
  int *iPk_data;
  emxInit_real_T(&x, 1);
  maxN = parse_inputs(Yin, x);
  emxInit_int32_T(&iPk, 1);
  emxInit_int32_T(&fPk, 1);
  emxInit_int32_T(&iInfinite, 1);
  getAllPeaksCodegen(Yin, fPk, iInfinite, iPk);
  removeSmallPeaks(Yin, fPk, iPk);
  emxInit_int32_T(&b_iPk, 1);
  combinePeaks(iPk, iInfinite, b_iPk);
  iPk_data = b_iPk->data;
  emxFree_int32_T(&iInfinite);
  c_findPeaksSeparatedByMoreThanM(Yin, x, b_iPk, iPk);
  b_iPk_data = iPk->data;
  if (iPk->size[0] > maxN) {
    i = fPk->size[0];
    fPk->size[0] = (int)maxN;
    emxEnsureCapacity_int32_T(fPk, i);
    i = iPk->size[0];
    iPk->size[0] = (int)maxN;
    emxEnsureCapacity_int32_T(iPk, i);
    b_iPk_data = iPk->data;
  } else {
    i = fPk->size[0];
    fPk->size[0] = iPk->size[0];
    emxEnsureCapacity_int32_T(fPk, i);
  }
  loop_ub = fPk->size[0];
  i = fPk->size[0];
  fPk->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(fPk, i);
  fPk_data = fPk->data;
  for (i = 0; i < loop_ub; i++) {
    fPk_data[i] = iPk_data[b_iPk_data[i] - 1];
  }
  emxFree_int32_T(&b_iPk);
  emxFree_int32_T(&iPk);
  assignOutputs(Yin, x, fPk, Ypk, Xpk);
  emxFree_real_T(&x);
  emxFree_int32_T(&fPk);
}

/*
 * File trailer for findpeaks.c
 *
 * [EOF]
 */
