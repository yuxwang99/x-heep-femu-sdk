/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * findpeaks.c
 *
 * Code generation for function 'findpeaks'
 *
 */

/* Include files */
#include "findpeaks.h"
#include "eml_setop.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sortIdx.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void c_findPeaksSeparatedByMoreThanM(const double y[30720], const
  emxArray_int32_T *iPk, double Pd, emxArray_int32_T *idx);

/* Function Definitions */
static void c_findPeaksSeparatedByMoreThanM(const double y[30720], const
  emxArray_int32_T *iPk, double Pd, emxArray_int32_T *idx)
{
  static boolean_T idelete_data[61440];
  static boolean_T tmp_data[61440];
  emxArray_int16_T *locs_temp;
  emxArray_int32_T *b_y;
  emxArray_int32_T *d_sortIdx;
  emxArray_real_T *c_y;
  emxArray_uint16_T *r;
  double d;
  double d1;
  int b_i;
  int i;
  int i1;
  int k;
  int n;
  int yk;
  emxInit_int32_T(&d_sortIdx, 1);
  emxInit_int16_T(&locs_temp, 1);
  emxInit_uint16_T(&r, 1);
  emxInit_int32_T(&b_y, 2);
  emxInit_real_T(&c_y, 1);
  if ((iPk->size[0] == 0) || (Pd == 0.0)) {
    if (iPk->size[0] < 1) {
      n = 0;
    } else {
      n = iPk->size[0];
    }

    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = n;
    emxEnsureCapacity_int32_T(b_y, i);
    if (n > 0) {
      b_y->data[0] = 1;
      yk = 1;
      for (k = 2; k <= n; k++) {
        yk++;
        b_y->data[k - 1] = yk;
      }
    }

    i = idx->size[0];
    idx->size[0] = b_y->size[1];
    emxEnsureCapacity_int32_T(idx, i);
    yk = b_y->size[1];
    for (i = 0; i < yk; i++) {
      idx->data[i] = b_y->data[i];
    }
  } else {
    i = c_y->size[0];
    c_y->size[0] = iPk->size[0];
    emxEnsureCapacity_real_T(c_y, i);
    yk = iPk->size[0];
    for (i = 0; i < yk; i++) {
      c_y->data[i] = y[iPk->data[i] - 1];
    }

    sortIdx(c_y, d_sortIdx);
    i = locs_temp->size[0];
    locs_temp->size[0] = d_sortIdx->size[0];
    emxEnsureCapacity_int16_T(locs_temp, i);
    yk = d_sortIdx->size[0];
    for (i = 0; i < yk; i++) {
      locs_temp->data[i] = (short)((short)(iPk->data[d_sortIdx->data[i] - 1] - 1)
        + 1);
    }

    n = (unsigned short)d_sortIdx->size[0];
    yk = (unsigned short)d_sortIdx->size[0];
    if (0 <= yk - 1) {
      memset(&idelete_data[0], 0, yk * sizeof(boolean_T));
    }

    i = d_sortIdx->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      if (!idelete_data[b_i]) {
        i1 = (short)((short)(iPk->data[d_sortIdx->data[b_i] - 1] - 1) + 1);
        d = (double)i1 - Pd;
        d1 = (double)i1 + Pd;
        yk = locs_temp->size[0];
        for (i1 = 0; i1 < yk; i1++) {
          k = locs_temp->data[i1];
          tmp_data[i1] = ((k >= d) && (k <= d1));
        }

        for (i1 = 0; i1 < n; i1++) {
          idelete_data[i1] = (idelete_data[i1] || tmp_data[i1]);
        }

        idelete_data[b_i] = false;
      }
    }

    n--;
    yk = 0;
    for (b_i = 0; b_i <= n; b_i++) {
      if (!idelete_data[b_i]) {
        yk++;
      }
    }

    i = r->size[0];
    r->size[0] = yk;
    emxEnsureCapacity_uint16_T(r, i);
    yk = 0;
    for (b_i = 0; b_i <= n; b_i++) {
      if (!idelete_data[b_i]) {
        r->data[yk] = (unsigned short)(b_i + 1);
        yk++;
      }
    }

    i = idx->size[0];
    idx->size[0] = r->size[0];
    emxEnsureCapacity_int32_T(idx, i);
    yk = r->size[0];
    for (i = 0; i < yk; i++) {
      idx->data[i] = d_sortIdx->data[r->data[i] - 1];
    }

    sort(idx);
  }

  emxFree_real_T(&c_y);
  emxFree_int32_T(&b_y);
  emxFree_uint16_T(&r);
  emxFree_int16_T(&locs_temp);
  emxFree_int32_T(&d_sortIdx);
}

void findpeaks(const double Yin[30720], double varargin_2, emxArray_real_T *Ypk,
               emxArray_real_T *Xpk)
{
  emxArray_int32_T *b_iPk;
  emxArray_int32_T *c;
  emxArray_int32_T *iFinite;
  emxArray_int32_T *iInfinite;
  emxArray_int32_T *iInflect;
  emxArray_int32_T *iPk;
  emxArray_int32_T *idx;
  double yk;
  double ykfirst;
  int k;
  int kfirst;
  int nInf;
  int nPk;
  char dir;
  char previousdir;
  boolean_T isinfyk;
  boolean_T isinfykfirst;
  emxInit_int32_T(&iInflect, 1);
  emxInit_int32_T(&iFinite, 1);
  emxInit_int32_T(&iInfinite, 1);
  k = iFinite->size[0];
  iFinite->size[0] = 30720;
  emxEnsureCapacity_int32_T(iFinite, k);
  k = iInfinite->size[0];
  iInfinite->size[0] = 30720;
  emxEnsureCapacity_int32_T(iInfinite, k);
  nPk = -1;
  nInf = -1;
  dir = 'n';
  kfirst = -1;
  ykfirst = rtInf;
  isinfykfirst = true;
  for (k = 0; k < 30720; k++) {
    yk = Yin[k];
    if (rtIsNaN(yk)) {
      yk = rtInf;
      isinfyk = true;
    } else if (rtIsInf(yk) && (yk > 0.0)) {
      isinfyk = true;
      nInf++;
      iInfinite->data[nInf] = k + 1;
    } else {
      isinfyk = false;
    }

    if (yk != ykfirst) {
      previousdir = dir;
      if (isinfyk || isinfykfirst) {
        dir = 'n';
      } else if (yk < ykfirst) {
        dir = 'd';
        if (('d' != previousdir) && (previousdir == 'i')) {
          nPk++;
          iFinite->data[nPk] = kfirst + 1;
        }
      } else {
        dir = 'i';
      }

      ykfirst = yk;
      kfirst = k;
      isinfykfirst = isinfyk;
    }
  }

  if (1 > nPk + 1) {
    kfirst = -1;
  } else {
    kfirst = nPk;
  }

  k = iInflect->size[0];
  iInflect->size[0] = kfirst + 1;
  emxEnsureCapacity_int32_T(iInflect, k);
  for (k = 0; k <= kfirst; k++) {
    iInflect->data[k] = (short)iFinite->data[k];
  }

  k = iFinite->size[0];
  iFinite->size[0] = iInflect->size[0];
  emxEnsureCapacity_int32_T(iFinite, k);
  kfirst = iInflect->size[0];
  for (k = 0; k < kfirst; k++) {
    iFinite->data[k] = iInflect->data[k];
  }

  if (1 > nInf + 1) {
    kfirst = -1;
  } else {
    kfirst = nInf;
  }

  k = iInflect->size[0];
  iInflect->size[0] = kfirst + 1;
  emxEnsureCapacity_int32_T(iInflect, k);
  for (k = 0; k <= kfirst; k++) {
    iInflect->data[k] = (short)iInfinite->data[k];
  }

  k = iInfinite->size[0];
  iInfinite->size[0] = iInflect->size[0];
  emxEnsureCapacity_int32_T(iInfinite, k);
  kfirst = iInflect->size[0];
  for (k = 0; k < kfirst; k++) {
    iInfinite->data[k] = iInflect->data[k];
  }

  emxInit_int32_T(&iPk, 1);
  k = iPk->size[0];
  iPk->size[0] = iFinite->size[0];
  emxEnsureCapacity_int32_T(iPk, k);
  nPk = 0;
  kfirst = iFinite->size[0];
  for (k = 0; k < kfirst; k++) {
    ykfirst = Yin[iFinite->data[k] - 1];
    if ((ykfirst > rtMinusInf) && (ykfirst - fmax(Yin[iFinite->data[k] - 2],
          Yin[iFinite->data[k]]) >= 0.0)) {
      nPk++;
      iPk->data[nPk - 1] = iFinite->data[k];
    }
  }

  emxInit_int32_T(&idx, 1);
  emxInit_int32_T(&c, 1);
  k = iPk->size[0];
  if (1 > nPk) {
    iPk->size[0] = 0;
  } else {
    iPk->size[0] = nPk;
  }

  emxEnsureCapacity_int32_T(iPk, k);
  do_vectors(iPk, iInfinite, c, iInflect, iFinite);
  c_findPeaksSeparatedByMoreThanM(Yin, c, varargin_2, idx);
  emxFree_int32_T(&iInfinite);
  emxFree_int32_T(&iFinite);
  emxFree_int32_T(&iPk);
  emxFree_int32_T(&iInflect);
  emxInit_int32_T(&b_iPk, 1);
  if (idx->size[0] > 30720) {
    k = b_iPk->size[0];
    b_iPk->size[0] = 30720;
    emxEnsureCapacity_int32_T(b_iPk, k);
    for (k = 0; k < 30720; k++) {
      b_iPk->data[k] = idx->data[k];
    }

    k = idx->size[0];
    idx->size[0] = b_iPk->size[0];
    emxEnsureCapacity_int32_T(idx, k);
    kfirst = b_iPk->size[0];
    for (k = 0; k < kfirst; k++) {
      idx->data[k] = b_iPk->data[k];
    }
  }

  k = b_iPk->size[0];
  b_iPk->size[0] = idx->size[0];
  emxEnsureCapacity_int32_T(b_iPk, k);
  kfirst = idx->size[0];
  for (k = 0; k < kfirst; k++) {
    b_iPk->data[k] = c->data[idx->data[k] - 1];
  }

  emxFree_int32_T(&c);
  emxFree_int32_T(&idx);
  k = Ypk->size[0];
  Ypk->size[0] = b_iPk->size[0];
  emxEnsureCapacity_real_T(Ypk, k);
  kfirst = b_iPk->size[0];
  for (k = 0; k < kfirst; k++) {
    Ypk->data[k] = Yin[b_iPk->data[k] - 1];
  }

  k = Xpk->size[0];
  Xpk->size[0] = b_iPk->size[0];
  emxEnsureCapacity_real_T(Xpk, k);
  kfirst = b_iPk->size[0];
  for (k = 0; k < kfirst; k++) {
    Xpk->data[k] = (short)((short)(b_iPk->data[k] - 1) + 1);
  }

  emxFree_int32_T(&b_iPk);
}

/* End of code generation (findpeaks.c) */
