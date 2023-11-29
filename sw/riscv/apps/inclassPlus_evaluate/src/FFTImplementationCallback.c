/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FFTImplementationCallback.c
 *
 * Code generation for function 'FFTImplementationCallback'
 *
 */

/* Include files */
#include "FFTImplementationCallback.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void c_FFTImplementationCallback_r2b(const emxArray_creal_T *x, int
  unsigned_nRows, const emxArray_real_T *costab, const emxArray_real_T *sintab,
  emxArray_creal_T *y);
static void d_FFTImplementationCallback_doH(const emxArray_real_T *x,
  emxArray_creal_T *y, int nrowsx, int nRows, int nfft, const emxArray_creal_T
  *wwc, const emxArray_real_T *costab, const emxArray_real_T *sintab, const
  emxArray_real_T *costabinv, const emxArray_real_T *sintabinv);

/* Function Definitions */
static void c_FFTImplementationCallback_r2b(const emxArray_creal_T *x, int
  unsigned_nRows, const emxArray_real_T *costab, const emxArray_real_T *sintab,
  emxArray_creal_T *y)
{
  double temp_im;
  double temp_re;
  double twid_im;
  double twid_re;
  int i;
  int iDelta2;
  int iheight;
  int ihi;
  int ix;
  int iy;
  int ju;
  int k;
  int nRowsD2;
  int temp_re_tmp;
  boolean_T tst;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_creal_T(y, iy);
  if (unsigned_nRows > x->size[0]) {
    iy = y->size[0];
    y->size[0] = unsigned_nRows;
    emxEnsureCapacity_creal_T(y, iy);
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }

  iDelta2 = x->size[0];
  if (iDelta2 >= unsigned_nRows) {
    iDelta2 = unsigned_nRows;
  }

  iheight = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  k = nRowsD2 / 2;
  ix = 0;
  iy = 0;
  ju = 0;
  for (i = 0; i <= iDelta2 - 2; i++) {
    y->data[iy] = x->data[ix];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy] = x->data[ix];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= iheight; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      twid_re = y->data[i].re;
      twid_im = y->data[i].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      twid_re += temp_re;
      twid_im += temp_im;
      y->data[i].re = twid_re;
      y->data[i].im = twid_im;
    }
  }

  iy = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      temp_re_tmp = i + iy;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - temp_re;
      y->data[temp_re_tmp].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    ix = 1;
    for (ju = k; ju < nRowsD2; ju += k) {
      twid_re = costab->data[ju];
      twid_im = sintab->data[ju];
      i = ix;
      ihi = ix + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
          data[temp_re_tmp].im;
        temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
          data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iDelta2;
      }

      ix++;
    }

    k /= 2;
    iy = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iy;
  }
}

static void d_FFTImplementationCallback_doH(const emxArray_real_T *x,
  emxArray_creal_T *y, int nrowsx, int nRows, int nfft, const emxArray_creal_T
  *wwc, const emxArray_real_T *costab, const emxArray_real_T *sintab, const
  emxArray_real_T *costabinv, const emxArray_real_T *sintabinv)
{
  emxArray_creal_T *fv;
  emxArray_creal_T *fy;
  emxArray_creal_T *reconVar1;
  emxArray_creal_T *reconVar2;
  emxArray_creal_T *ytmp;
  emxArray_int32_T *wrapIndex;
  emxArray_real_T *b_costab;
  emxArray_real_T *b_sintab;
  emxArray_real_T *costab1q;
  emxArray_real_T *hcostabinv;
  emxArray_real_T *hsintab;
  emxArray_real_T *hsintabinv;
  double e;
  double temp_im;
  double temp_re;
  double twid_im;
  double twid_re;
  double z;
  int hnRows;
  int hszCostab;
  int i;
  int ihi;
  int ix;
  int j;
  int ju;
  int k;
  int nRowsD2;
  int nd2;
  int temp_re_tmp;
  boolean_T tst;
  emxInit_creal_T(&ytmp, 1);
  hnRows = nRows / 2;
  ju = ytmp->size[0];
  ytmp->size[0] = hnRows;
  emxEnsureCapacity_creal_T(ytmp, ju);
  if (hnRows > nrowsx) {
    ju = ytmp->size[0];
    ytmp->size[0] = hnRows;
    emxEnsureCapacity_creal_T(ytmp, ju);
    for (ju = 0; ju < hnRows; ju++) {
      ytmp->data[ju].re = 0.0;
      ytmp->data[ju].im = 0.0;
    }
  }

  if ((x->size[0] & 1) == 0) {
    tst = true;
    ix = x->size[0];
  } else if (x->size[0] >= nRows) {
    tst = true;
    ix = nRows;
  } else {
    tst = false;
    ix = x->size[0] - 1;
  }

  emxInit_real_T(&costab1q, 2);
  if (ix >= nRows) {
    ix = nRows;
  }

  nd2 = nRows << 1;
  e = 6.2831853071795862 / (double)nd2;
  ihi = nd2 / 2 / 2;
  ju = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = ihi + 1;
  emxEnsureCapacity_real_T(costab1q, ju);
  costab1q->data[0] = 1.0;
  nd2 = ihi / 2 - 1;
  for (k = 0; k <= nd2; k++) {
    costab1q->data[k + 1] = cos(e * ((double)k + 1.0));
  }

  ju = nd2 + 2;
  nd2 = ihi - 1;
  for (k = ju; k <= nd2; k++) {
    costab1q->data[k] = sin(e * (double)(ihi - k));
  }

  emxInit_real_T(&b_costab, 2);
  emxInit_real_T(&b_sintab, 2);
  costab1q->data[ihi] = 0.0;
  ihi = costab1q->size[1] - 1;
  nd2 = (costab1q->size[1] - 1) << 1;
  ju = b_costab->size[0] * b_costab->size[1];
  b_costab->size[0] = 1;
  b_costab->size[1] = nd2 + 1;
  emxEnsureCapacity_real_T(b_costab, ju);
  ju = b_sintab->size[0] * b_sintab->size[1];
  b_sintab->size[0] = 1;
  b_sintab->size[1] = nd2 + 1;
  emxEnsureCapacity_real_T(b_sintab, ju);
  b_costab->data[0] = 1.0;
  b_sintab->data[0] = 0.0;
  for (k = 0; k < ihi; k++) {
    b_costab->data[k + 1] = costab1q->data[k + 1];
    b_sintab->data[k + 1] = -costab1q->data[(ihi - k) - 1];
  }

  ju = costab1q->size[1];
  for (k = ju; k <= nd2; k++) {
    b_costab->data[k] = -costab1q->data[nd2 - k];
    b_sintab->data[k] = -costab1q->data[k - ihi];
  }

  emxInit_real_T(&hsintab, 2);
  emxInit_real_T(&hcostabinv, 2);
  emxInit_real_T(&hsintabinv, 2);
  hszCostab = costab->size[1] / 2;
  ju = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = hszCostab;
  emxEnsureCapacity_real_T(costab1q, ju);
  ju = hsintab->size[0] * hsintab->size[1];
  hsintab->size[0] = 1;
  hsintab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hsintab, ju);
  ju = hcostabinv->size[0] * hcostabinv->size[1];
  hcostabinv->size[0] = 1;
  hcostabinv->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hcostabinv, ju);
  ju = hsintabinv->size[0] * hsintabinv->size[1];
  hsintabinv->size[0] = 1;
  hsintabinv->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hsintabinv, ju);
  for (i = 0; i < hszCostab; i++) {
    nd2 = ((i + 1) << 1) - 2;
    costab1q->data[i] = costab->data[nd2];
    hsintab->data[i] = sintab->data[nd2];
    hcostabinv->data[i] = costabinv->data[nd2];
    hsintabinv->data[i] = sintabinv->data[nd2];
  }

  emxInit_int32_T(&wrapIndex, 2);
  emxInit_creal_T(&reconVar1, 1);
  emxInit_creal_T(&reconVar2, 1);
  ju = reconVar1->size[0];
  reconVar1->size[0] = hnRows;
  emxEnsureCapacity_creal_T(reconVar1, ju);
  ju = reconVar2->size[0];
  reconVar2->size[0] = hnRows;
  emxEnsureCapacity_creal_T(reconVar2, ju);
  nd2 = 0;
  ju = wrapIndex->size[0] * wrapIndex->size[1];
  wrapIndex->size[0] = 1;
  wrapIndex->size[1] = hnRows;
  emxEnsureCapacity_int32_T(wrapIndex, ju);
  for (i = 0; i < hnRows; i++) {
    reconVar1->data[i].re = b_sintab->data[nd2] + 1.0;
    reconVar1->data[i].im = -b_costab->data[nd2];
    reconVar2->data[i].re = 1.0 - b_sintab->data[nd2];
    reconVar2->data[i].im = b_costab->data[nd2];
    nd2 += 2;
    if (i + 1 != 1) {
      wrapIndex->data[i] = (hnRows - i) + 1;
    } else {
      wrapIndex->data[0] = 1;
    }
  }

  emxFree_real_T(&b_sintab);
  emxFree_real_T(&b_costab);
  nd2 = 0;
  e = (double)ix / 2.0;
  ju = (int)e;
  for (hszCostab = 0; hszCostab < ju; hszCostab++) {
    temp_re_tmp = (hnRows + hszCostab) - 1;
    temp_re = wwc->data[temp_re_tmp].re;
    temp_im = wwc->data[temp_re_tmp].im;
    twid_re = x->data[nd2];
    twid_im = x->data[nd2 + 1];
    ytmp->data[hszCostab].re = temp_re * twid_re + temp_im * twid_im;
    ytmp->data[hszCostab].im = temp_re * twid_im - temp_im * twid_re;
    nd2 += 2;
  }

  if (!tst) {
    temp_re_tmp = (hnRows + (int)e) - 1;
    temp_re = wwc->data[temp_re_tmp].re;
    temp_im = wwc->data[temp_re_tmp].im;
    twid_re = x->data[nd2];
    ju = (int)((double)ix / 2.0);
    ytmp->data[ju].re = temp_re * twid_re + temp_im * 0.0;
    ytmp->data[ju].im = temp_re * 0.0 - temp_im * twid_re;
    if ((int)e + 2 <= hnRows) {
      ju = (int)((double)ix / 2.0) + 2;
      for (i = ju; i <= hnRows; i++) {
        ytmp->data[i - 1].re = 0.0;
        ytmp->data[i - 1].im = 0.0;
      }
    }
  } else {
    if ((int)e + 1 <= hnRows) {
      ju = (int)((double)ix / 2.0) + 1;
      for (i = ju; i <= hnRows; i++) {
        ytmp->data[i - 1].re = 0.0;
        ytmp->data[i - 1].im = 0.0;
      }
    }
  }

  emxInit_creal_T(&fy, 1);
  z = (double)nfft / 2.0;
  ju = fy->size[0];
  fy->size[0] = (int)z;
  emxEnsureCapacity_creal_T(fy, ju);
  if ((int)z > ytmp->size[0]) {
    ju = fy->size[0];
    fy->size[0] = (int)z;
    emxEnsureCapacity_creal_T(fy, ju);
    nd2 = (int)z;
    for (ju = 0; ju < nd2; ju++) {
      fy->data[ju].re = 0.0;
      fy->data[ju].im = 0.0;
    }
  }

  ix = ytmp->size[0];
  j = (int)z;
  if (ix < j) {
    j = ix;
  }

  hszCostab = (int)z - 2;
  nRowsD2 = (int)z / 2;
  k = nRowsD2 / 2;
  ix = 0;
  nd2 = 0;
  ju = 0;
  for (i = 0; i <= j - 2; i++) {
    fy->data[nd2] = ytmp->data[ix];
    ihi = (int)z;
    tst = true;
    while (tst) {
      ihi >>= 1;
      ju ^= ihi;
      tst = ((ju & ihi) == 0);
    }

    nd2 = ju;
    ix++;
  }

  fy->data[nd2] = ytmp->data[ix];
  if ((int)z > 1) {
    for (i = 0; i <= hszCostab; i += 2) {
      temp_re = fy->data[i + 1].re;
      temp_im = fy->data[i + 1].im;
      e = fy->data[i].re;
      twid_re = fy->data[i].im;
      fy->data[i + 1].re = fy->data[i].re - fy->data[i + 1].re;
      fy->data[i + 1].im = fy->data[i].im - fy->data[i + 1].im;
      e += temp_re;
      twid_re += temp_im;
      fy->data[i].re = e;
      fy->data[i].im = twid_re;
    }
  }

  nd2 = 2;
  hszCostab = 4;
  ix = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < ix; i += hszCostab) {
      temp_re_tmp = i + nd2;
      temp_re = fy->data[temp_re_tmp].re;
      temp_im = fy->data[temp_re_tmp].im;
      fy->data[temp_re_tmp].re = fy->data[i].re - temp_re;
      fy->data[temp_re_tmp].im = fy->data[i].im - temp_im;
      fy->data[i].re += temp_re;
      fy->data[i].im += temp_im;
    }

    ju = 1;
    for (j = k; j < nRowsD2; j += k) {
      twid_re = costab1q->data[j];
      twid_im = hsintab->data[j];
      i = ju;
      ihi = ju + ix;
      while (i < ihi) {
        temp_re_tmp = i + nd2;
        temp_re = twid_re * fy->data[temp_re_tmp].re - twid_im * fy->
          data[temp_re_tmp].im;
        temp_im = twid_re * fy->data[temp_re_tmp].im + twid_im * fy->
          data[temp_re_tmp].re;
        fy->data[temp_re_tmp].re = fy->data[i].re - temp_re;
        fy->data[temp_re_tmp].im = fy->data[i].im - temp_im;
        fy->data[i].re += temp_re;
        fy->data[i].im += temp_im;
        i += hszCostab;
      }

      ju++;
    }

    k /= 2;
    nd2 = hszCostab;
    hszCostab += hszCostab;
    ix -= nd2;
  }

  emxInit_creal_T(&fv, 1);
  c_FFTImplementationCallback_r2b(wwc, (int)((double)nfft / 2.0), costab1q,
    hsintab, fv);
  nd2 = fy->size[0];
  emxFree_real_T(&costab1q);
  emxFree_real_T(&hsintab);
  for (ju = 0; ju < nd2; ju++) {
    twid_re = fy->data[ju].re * fv->data[ju].im + fy->data[ju].im * fv->data[ju]
      .re;
    fy->data[ju].re = fy->data[ju].re * fv->data[ju].re - fy->data[ju].im *
      fv->data[ju].im;
    fy->data[ju].im = twid_re;
  }

  c_FFTImplementationCallback_r2b(fy, (int)z, hcostabinv, hsintabinv, fv);
  emxFree_creal_T(&fy);
  emxFree_real_T(&hsintabinv);
  emxFree_real_T(&hcostabinv);
  if (fv->size[0] > 1) {
    e = 1.0 / (double)fv->size[0];
    nd2 = fv->size[0];
    for (ju = 0; ju < nd2; ju++) {
      fv->data[ju].re *= e;
      fv->data[ju].im *= e;
    }
  }

  nd2 = 0;
  ju = wwc->size[0];
  for (k = hnRows; k <= ju; k++) {
    ytmp->data[nd2].re = wwc->data[k - 1].re * fv->data[k - 1].re + wwc->data[k
      - 1].im * fv->data[k - 1].im;
    ytmp->data[nd2].im = wwc->data[k - 1].re * fv->data[k - 1].im - wwc->data[k
      - 1].im * fv->data[k - 1].re;
    nd2++;
  }

  emxFree_creal_T(&fv);
  for (i = 0; i < hnRows; i++) {
    ju = wrapIndex->data[i];
    e = ytmp->data[ju - 1].re;
    twid_re = -ytmp->data[ju - 1].im;
    y->data[i].re = 0.5 * ((ytmp->data[i].re * reconVar1->data[i].re -
      ytmp->data[i].im * reconVar1->data[i].im) + (e * reconVar2->data[i].re -
      twid_re * reconVar2->data[i].im));
    y->data[i].im = 0.5 * ((ytmp->data[i].re * reconVar1->data[i].im +
      ytmp->data[i].im * reconVar1->data[i].re) + (e * reconVar2->data[i].im +
      twid_re * reconVar2->data[i].re));
    ju = hnRows + i;
    y->data[ju].re = 0.5 * ((ytmp->data[i].re * reconVar2->data[i].re -
      ytmp->data[i].im * reconVar2->data[i].im) + (e * reconVar1->data[i].re -
      twid_re * reconVar1->data[i].im));
    y->data[ju].im = 0.5 * ((ytmp->data[i].re * reconVar2->data[i].im +
      ytmp->data[i].im * reconVar2->data[i].re) + (e * reconVar1->data[i].im +
      twid_re * reconVar1->data[i].re));
  }

  emxFree_creal_T(&reconVar2);
  emxFree_creal_T(&reconVar1);
  emxFree_int32_T(&wrapIndex);
  emxFree_creal_T(&ytmp);
}

void c_FFTImplementationCallback_doH(const emxArray_real_T *x, emxArray_creal_T *
  y, int unsigned_nRows, const emxArray_real_T *costab, const emxArray_real_T
  *sintab)
{
  emxArray_creal_T *reconVar1;
  emxArray_creal_T *reconVar2;
  emxArray_int32_T *bitrevIndex;
  emxArray_int32_T *wrapIndex;
  emxArray_real_T *hcostab;
  emxArray_real_T *hsintab;
  double temp2_im;
  double temp2_re;
  double temp_im;
  double temp_re;
  double y_im;
  double y_im_tmp;
  double z;
  int b_j1;
  int hszCostab;
  int i;
  int ihi;
  int ix;
  int j;
  int ju;
  int k;
  int nRows;
  int nRowsD2;
  boolean_T tst;
  emxInit_real_T(&hcostab, 2);
  emxInit_real_T(&hsintab, 2);
  nRows = unsigned_nRows / 2;
  j = y->size[0];
  if (j >= nRows) {
    j = nRows;
  }

  ihi = nRows - 2;
  nRowsD2 = nRows / 2;
  k = nRowsD2 / 2;
  hszCostab = costab->size[1] / 2;
  b_j1 = hcostab->size[0] * hcostab->size[1];
  hcostab->size[0] = 1;
  hcostab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hcostab, b_j1);
  b_j1 = hsintab->size[0] * hsintab->size[1];
  hsintab->size[0] = 1;
  hsintab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hsintab, b_j1);
  for (i = 0; i < hszCostab; i++) {
    ix = ((i + 1) << 1) - 2;
    hcostab->data[i] = costab->data[ix];
    hsintab->data[i] = sintab->data[ix];
  }

  emxInit_int32_T(&wrapIndex, 2);
  emxInit_creal_T(&reconVar1, 1);
  emxInit_creal_T(&reconVar2, 1);
  b_j1 = reconVar1->size[0];
  reconVar1->size[0] = nRows;
  emxEnsureCapacity_creal_T(reconVar1, b_j1);
  b_j1 = reconVar2->size[0];
  reconVar2->size[0] = nRows;
  emxEnsureCapacity_creal_T(reconVar2, b_j1);
  b_j1 = wrapIndex->size[0] * wrapIndex->size[1];
  wrapIndex->size[0] = 1;
  wrapIndex->size[1] = nRows;
  emxEnsureCapacity_int32_T(wrapIndex, b_j1);
  for (i = 0; i < nRows; i++) {
    temp2_im = sintab->data[i];
    temp2_re = costab->data[i];
    reconVar1->data[i].re = temp2_im + 1.0;
    reconVar1->data[i].im = -temp2_re;
    reconVar2->data[i].re = 1.0 - temp2_im;
    reconVar2->data[i].im = temp2_re;
    if (i + 1 != 1) {
      wrapIndex->data[i] = (nRows - i) + 1;
    } else {
      wrapIndex->data[0] = 1;
    }
  }

  emxInit_int32_T(&bitrevIndex, 1);
  z = (double)unsigned_nRows / 2.0;
  ju = 0;
  hszCostab = 1;
  b_j1 = bitrevIndex->size[0];
  bitrevIndex->size[0] = (int)z;
  emxEnsureCapacity_int32_T(bitrevIndex, b_j1);
  ix = (int)z;
  for (b_j1 = 0; b_j1 < ix; b_j1++) {
    bitrevIndex->data[b_j1] = 0;
  }

  for (b_j1 = 0; b_j1 <= j - 2; b_j1++) {
    bitrevIndex->data[b_j1] = hszCostab;
    ix = (int)z;
    tst = true;
    while (tst) {
      ix >>= 1;
      ju ^= ix;
      tst = ((ju & ix) == 0);
    }

    hszCostab = ju + 1;
  }

  bitrevIndex->data[j - 1] = hszCostab;
  if ((x->size[0] & 1) == 0) {
    tst = true;
    j = x->size[0];
  } else if (x->size[0] >= unsigned_nRows) {
    tst = true;
    j = unsigned_nRows;
  } else {
    tst = false;
    j = x->size[0] - 1;
  }

  ix = 0;
  if (j >= unsigned_nRows) {
    j = unsigned_nRows;
  }

  temp2_im = (double)j / 2.0;
  b_j1 = (int)temp2_im;
  for (i = 0; i < b_j1; i++) {
    y->data[bitrevIndex->data[i] - 1].re = x->data[ix];
    y->data[bitrevIndex->data[i] - 1].im = x->data[ix + 1];
    ix += 2;
  }

  if (!tst) {
    b_j1 = bitrevIndex->data[(int)temp2_im] - 1;
    y->data[b_j1].re = x->data[ix];
    y->data[b_j1].im = 0.0;
  }

  emxFree_int32_T(&bitrevIndex);
  if (nRows > 1) {
    for (i = 0; i <= ihi; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  ix = 2;
  hszCostab = 4;
  ju = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < ju; i += hszCostab) {
      b_j1 = i + ix;
      temp_re = y->data[b_j1].re;
      temp_im = y->data[b_j1].im;
      y->data[b_j1].re = y->data[i].re - temp_re;
      y->data[b_j1].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    nRows = 1;
    for (j = k; j < nRowsD2; j += k) {
      temp2_re = hcostab->data[j];
      temp2_im = hsintab->data[j];
      i = nRows;
      ihi = nRows + ju;
      while (i < ihi) {
        b_j1 = i + ix;
        temp_re = temp2_re * y->data[b_j1].re - temp2_im * y->data[b_j1].im;
        temp_im = temp2_re * y->data[b_j1].im + temp2_im * y->data[b_j1].re;
        y->data[b_j1].re = y->data[i].re - temp_re;
        y->data[b_j1].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += hszCostab;
      }

      nRows++;
    }

    k /= 2;
    ix = hszCostab;
    hszCostab += hszCostab;
    ju -= ix;
  }

  emxFree_real_T(&hsintab);
  emxFree_real_T(&hcostab);
  ix = (int)z / 2;
  temp_re = y->data[0].re;
  temp_im = y->data[0].im;
  y_im = y->data[0].re * reconVar1->data[0].im + y->data[0].im * reconVar1->
    data[0].re;
  temp2_re = y->data[0].re;
  temp2_im = -y->data[0].im;
  y->data[0].re = 0.5 * ((y->data[0].re * reconVar1->data[0].re - y->data[0].im *
    reconVar1->data[0].im) + (temp2_re * reconVar2->data[0].re - temp2_im *
    reconVar2->data[0].im));
  y->data[0].im = 0.5 * (y_im + (temp2_re * reconVar2->data[0].im + temp2_im *
    reconVar2->data[0].re));
  y->data[(int)z].re = 0.5 * ((temp_re * reconVar2->data[0].re - temp_im *
    reconVar2->data[0].im) + (temp_re * reconVar1->data[0].re - -temp_im *
    reconVar1->data[0].im));
  y->data[(int)z].im = 0.5 * ((temp_re * reconVar2->data[0].im + temp_im *
    reconVar2->data[0].re) + (temp_re * reconVar1->data[0].im + -temp_im *
    reconVar1->data[0].re));
  for (i = 2; i <= ix; i++) {
    temp_re = y->data[i - 1].re;
    temp_im = y->data[i - 1].im;
    b_j1 = wrapIndex->data[i - 1];
    temp2_re = y->data[b_j1 - 1].re;
    temp2_im = y->data[b_j1 - 1].im;
    y_im = y->data[i - 1].re * reconVar1->data[i - 1].im + y->data[i - 1].im *
      reconVar1->data[i - 1].re;
    y_im_tmp = -y->data[b_j1 - 1].im;
    y->data[i - 1].re = 0.5 * ((y->data[i - 1].re * reconVar1->data[i - 1].re -
      y->data[i - 1].im * reconVar1->data[i - 1].im) + (temp2_re *
      reconVar2->data[i - 1].re - y_im_tmp * reconVar2->data[i - 1].im));
    y->data[i - 1].im = 0.5 * (y_im + (temp2_re * reconVar2->data[i - 1].im +
      y_im_tmp * reconVar2->data[i - 1].re));
    hszCostab = ((int)z + i) - 1;
    y->data[hszCostab].re = 0.5 * ((temp_re * reconVar2->data[i - 1].re -
      temp_im * reconVar2->data[i - 1].im) + (temp2_re * reconVar1->data[i - 1].
      re - -temp2_im * reconVar1->data[i - 1].im));
    y->data[hszCostab].im = 0.5 * ((temp_re * reconVar2->data[i - 1].im +
      temp_im * reconVar2->data[i - 1].re) + (temp2_re * reconVar1->data[i - 1].
      im + -temp2_im * reconVar1->data[i - 1].re));
    y->data[b_j1 - 1].re = 0.5 * ((temp2_re * reconVar1->data[b_j1 - 1].re -
      temp2_im * reconVar1->data[b_j1 - 1].im) + (temp_re * reconVar2->data[b_j1
      - 1].re - -temp_im * reconVar2->data[b_j1 - 1].im));
    y->data[b_j1 - 1].im = 0.5 * ((temp2_re * reconVar1->data[b_j1 - 1].im +
      temp2_im * reconVar1->data[b_j1 - 1].re) + (temp_re * reconVar2->data[b_j1
      - 1].im + -temp_im * reconVar2->data[b_j1 - 1].re));
    hszCostab = (b_j1 + (int)z) - 1;
    y->data[hszCostab].re = 0.5 * ((temp2_re * reconVar2->data[b_j1 - 1].re -
      temp2_im * reconVar2->data[b_j1 - 1].im) + (temp_re * reconVar1->data[b_j1
      - 1].re - -temp_im * reconVar1->data[b_j1 - 1].im));
    y->data[hszCostab].im = 0.5 * ((temp2_re * reconVar2->data[b_j1 - 1].im +
      temp2_im * reconVar2->data[b_j1 - 1].re) + (temp_re * reconVar1->data[b_j1
      - 1].im + -temp_im * reconVar1->data[b_j1 - 1].re));
  }

  emxFree_int32_T(&wrapIndex);
  if (ix != 0) {
    temp2_im = y->data[ix].re;
    temp_im = y->data[ix].im;
    y_im = y->data[ix].re * reconVar1->data[ix].im + y->data[ix].im *
      reconVar1->data[ix].re;
    y_im_tmp = -y->data[ix].im;
    y->data[ix].re = 0.5 * ((y->data[ix].re * reconVar1->data[ix].re - y->
      data[ix].im * reconVar1->data[ix].im) + (temp2_im * reconVar2->data[ix].re
      - y_im_tmp * reconVar2->data[ix].im));
    y->data[ix].im = 0.5 * (y_im + (temp2_im * reconVar2->data[ix].im + y_im_tmp
      * reconVar2->data[ix].re));
    b_j1 = (int)z + ix;
    y->data[b_j1].re = 0.5 * ((temp2_im * reconVar2->data[ix].re - temp_im *
      reconVar2->data[ix].im) + (temp2_im * reconVar1->data[ix].re - -temp_im *
      reconVar1->data[ix].im));
    y->data[b_j1].im = 0.5 * ((temp2_im * reconVar2->data[ix].im + temp_im *
      reconVar2->data[ix].re) + (temp2_im * reconVar1->data[ix].im + -temp_im *
      reconVar1->data[ix].re));
  }

  emxFree_creal_T(&reconVar2);
  emxFree_creal_T(&reconVar1);
}

void c_FFTImplementationCallback_dob(const emxArray_real_T *x, int n2blue, int
  nfft, const emxArray_real_T *costab, const emxArray_real_T *sintab, const
  emxArray_real_T *sintabinv, emxArray_creal_T *y)
{
  emxArray_creal_T *fv;
  emxArray_creal_T *fy;
  emxArray_creal_T *wwc;
  double nt_im;
  double nt_re;
  double twid_im;
  double twid_re;
  int i;
  int idx;
  int iheight;
  int ihi;
  int k;
  int nInt2;
  int nInt2m1;
  int nRowsD2;
  int nt_re_tmp;
  int rt;
  boolean_T tst;
  if ((nfft != 1) && ((nfft & 1) == 0)) {
    tst = true;
  } else {
    tst = false;
  }

  emxInit_creal_T(&wwc, 1);
  if (tst) {
    ihi = nfft / 2;
    nInt2m1 = (ihi + ihi) - 1;
    nInt2 = wwc->size[0];
    wwc->size[0] = nInt2m1;
    emxEnsureCapacity_creal_T(wwc, nInt2);
    idx = ihi;
    rt = 0;
    wwc->data[ihi - 1].re = 1.0;
    wwc->data[ihi - 1].im = 0.0;
    nInt2 = ihi << 1;
    for (k = 0; k <= ihi - 2; k++) {
      iheight = ((k + 1) << 1) - 1;
      if (nInt2 - rt <= iheight) {
        rt += iheight - nInt2;
      } else {
        rt += iheight;
      }

      nt_im = -3.1415926535897931 * (double)rt / (double)ihi;
      if (nt_im == 0.0) {
        nt_re = 1.0;
        nt_im = 0.0;
      } else {
        nt_re = cos(nt_im);
        nt_im = sin(nt_im);
      }

      wwc->data[idx - 2].re = nt_re;
      wwc->data[idx - 2].im = -nt_im;
      idx--;
    }

    idx = 0;
    nInt2 = nInt2m1 - 1;
    for (k = nInt2; k >= ihi; k--) {
      wwc->data[k] = wwc->data[idx];
      idx++;
    }
  } else {
    nInt2m1 = (nfft + nfft) - 1;
    nInt2 = wwc->size[0];
    wwc->size[0] = nInt2m1;
    emxEnsureCapacity_creal_T(wwc, nInt2);
    idx = nfft;
    rt = 0;
    wwc->data[nfft - 1].re = 1.0;
    wwc->data[nfft - 1].im = 0.0;
    nInt2 = nfft << 1;
    for (k = 0; k <= nfft - 2; k++) {
      iheight = ((k + 1) << 1) - 1;
      if (nInt2 - rt <= iheight) {
        rt += iheight - nInt2;
      } else {
        rt += iheight;
      }

      nt_im = -3.1415926535897931 * (double)rt / (double)nfft;
      if (nt_im == 0.0) {
        nt_re = 1.0;
        nt_im = 0.0;
      } else {
        nt_re = cos(nt_im);
        nt_im = sin(nt_im);
      }

      wwc->data[idx - 2].re = nt_re;
      wwc->data[idx - 2].im = -nt_im;
      idx--;
    }

    idx = 0;
    nInt2 = nInt2m1 - 1;
    for (k = nInt2; k >= nfft; k--) {
      wwc->data[k] = wwc->data[idx];
      idx++;
    }
  }

  nInt2 = y->size[0];
  y->size[0] = nfft;
  emxEnsureCapacity_creal_T(y, nInt2);
  if (nfft > x->size[0]) {
    nInt2 = y->size[0];
    y->size[0] = nfft;
    emxEnsureCapacity_creal_T(y, nInt2);
    for (nInt2 = 0; nInt2 < nfft; nInt2++) {
      y->data[nInt2].re = 0.0;
      y->data[nInt2].im = 0.0;
    }
  }

  if ((n2blue != 1) && ((nfft & 1) == 0)) {
    d_FFTImplementationCallback_doH(x, y, x->size[0], nfft, n2blue, wwc, costab,
      sintab, costab, sintabinv);
  } else {
    rt = x->size[0];
    if (nfft < rt) {
      rt = nfft;
    }

    nInt2 = 0;
    for (k = 0; k < rt; k++) {
      nt_re_tmp = (nfft + k) - 1;
      y->data[k].re = wwc->data[nt_re_tmp].re * x->data[nInt2];
      y->data[k].im = wwc->data[nt_re_tmp].im * -x->data[nInt2];
      nInt2++;
    }

    nInt2 = rt + 1;
    for (k = nInt2; k <= nfft; k++) {
      y->data[k - 1].re = 0.0;
      y->data[k - 1].im = 0.0;
    }

    emxInit_creal_T(&fy, 1);
    nInt2 = fy->size[0];
    fy->size[0] = n2blue;
    emxEnsureCapacity_creal_T(fy, nInt2);
    if (n2blue > y->size[0]) {
      nInt2 = fy->size[0];
      fy->size[0] = n2blue;
      emxEnsureCapacity_creal_T(fy, nInt2);
      for (nInt2 = 0; nInt2 < n2blue; nInt2++) {
        fy->data[nInt2].re = 0.0;
        fy->data[nInt2].im = 0.0;
      }
    }

    nInt2 = y->size[0];
    if (nInt2 >= n2blue) {
      nInt2 = n2blue;
    }

    iheight = n2blue - 2;
    nRowsD2 = n2blue / 2;
    k = nRowsD2 / 2;
    nInt2m1 = 0;
    rt = 0;
    idx = 0;
    for (i = 0; i <= nInt2 - 2; i++) {
      fy->data[rt] = y->data[nInt2m1];
      rt = n2blue;
      tst = true;
      while (tst) {
        rt >>= 1;
        idx ^= rt;
        tst = ((idx & rt) == 0);
      }

      rt = idx;
      nInt2m1++;
    }

    fy->data[rt] = y->data[nInt2m1];
    if (n2blue > 1) {
      for (i = 0; i <= iheight; i += 2) {
        nt_re = fy->data[i + 1].re;
        nt_im = fy->data[i + 1].im;
        twid_re = fy->data[i].re;
        twid_im = fy->data[i].im;
        fy->data[i + 1].re = fy->data[i].re - fy->data[i + 1].re;
        fy->data[i + 1].im = fy->data[i].im - fy->data[i + 1].im;
        twid_re += nt_re;
        twid_im += nt_im;
        fy->data[i].re = twid_re;
        fy->data[i].im = twid_im;
      }
    }

    rt = 2;
    nInt2 = 4;
    iheight = ((k - 1) << 2) + 1;
    while (k > 0) {
      for (i = 0; i < iheight; i += nInt2) {
        nt_re_tmp = i + rt;
        nt_re = fy->data[nt_re_tmp].re;
        nt_im = fy->data[nt_re_tmp].im;
        fy->data[nt_re_tmp].re = fy->data[i].re - nt_re;
        fy->data[nt_re_tmp].im = fy->data[i].im - nt_im;
        fy->data[i].re += nt_re;
        fy->data[i].im += nt_im;
      }

      nInt2m1 = 1;
      for (idx = k; idx < nRowsD2; idx += k) {
        twid_re = costab->data[idx];
        twid_im = sintab->data[idx];
        i = nInt2m1;
        ihi = nInt2m1 + iheight;
        while (i < ihi) {
          nt_re_tmp = i + rt;
          nt_re = twid_re * fy->data[nt_re_tmp].re - twid_im * fy->
            data[nt_re_tmp].im;
          nt_im = twid_re * fy->data[nt_re_tmp].im + twid_im * fy->
            data[nt_re_tmp].re;
          fy->data[nt_re_tmp].re = fy->data[i].re - nt_re;
          fy->data[nt_re_tmp].im = fy->data[i].im - nt_im;
          fy->data[i].re += nt_re;
          fy->data[i].im += nt_im;
          i += nInt2;
        }

        nInt2m1++;
      }

      k /= 2;
      rt = nInt2;
      nInt2 += nInt2;
      iheight -= rt;
    }

    emxInit_creal_T(&fv, 1);
    c_FFTImplementationCallback_r2b(wwc, n2blue, costab, sintab, fv);
    rt = fy->size[0];
    for (nInt2 = 0; nInt2 < rt; nInt2++) {
      twid_im = fy->data[nInt2].re * fv->data[nInt2].im + fy->data[nInt2].im *
        fv->data[nInt2].re;
      fy->data[nInt2].re = fy->data[nInt2].re * fv->data[nInt2].re - fy->
        data[nInt2].im * fv->data[nInt2].im;
      fy->data[nInt2].im = twid_im;
    }

    c_FFTImplementationCallback_r2b(fy, n2blue, costab, sintabinv, fv);
    emxFree_creal_T(&fy);
    if (fv->size[0] > 1) {
      twid_re = 1.0 / (double)fv->size[0];
      rt = fv->size[0];
      for (nInt2 = 0; nInt2 < rt; nInt2++) {
        fv->data[nInt2].re *= twid_re;
        fv->data[nInt2].im *= twid_re;
      }
    }

    idx = 0;
    nInt2 = wwc->size[0];
    for (k = nfft; k <= nInt2; k++) {
      y->data[idx].re = wwc->data[k - 1].re * fv->data[k - 1].re + wwc->data[k -
        1].im * fv->data[k - 1].im;
      y->data[idx].im = wwc->data[k - 1].re * fv->data[k - 1].im - wwc->data[k -
        1].im * fv->data[k - 1].re;
      idx++;
    }

    emxFree_creal_T(&fv);
  }

  emxFree_creal_T(&wwc);
}

/* End of code generation (FFTImplementationCallback.c) */
