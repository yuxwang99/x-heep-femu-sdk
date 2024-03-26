/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FFTImplementationCallback.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "FFTImplementationCallback.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "bluesteinSetup.h"
#include "cos1.h"
#include "exp1.h"
#include "nextpow2.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "sizeIsPow2.h"

/* Function Declarations */
static void c_FFTImplementationCallback_cal(int nfftLen,
                                            emxArray_int32_T *wrapIndex);

static void c_FFTImplementationCallback_doH(const emxArray_real_T *x,
                                            emxArray_creal_T *y,
                                            int unsigned_nRows,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab);

static boolean_T c_FFTImplementationCallback_pad(const emxArray_real_T *x,
                                                 int n1, int *minX);

static int c_FFTImplementationCallback_rad(const emxArray_creal_T *y, int nRows,
                                           int *nRowsM2, int *nRowsD2,
                                           int *nRowsD4, double *e);

static void d_FFTImplementationCallback_doH(
    const emxArray_real_T *x, emxArray_creal_T *y, int nrowsx, int nRows,
    int nfft, const emxArray_creal_T *wwc, const emxArray_real_T *costab,
    const emxArray_real_T *sintab, const emxArray_real_T *costabinv,
    const emxArray_real_T *sintabinv);

static void d_FFTImplementationCallback_gen(int nRows, emxArray_real_T *costab,
                                            emxArray_real_T *sintab,
                                            emxArray_real_T *sintabinv);

static void d_FFTImplementationCallback_r2b(const emxArray_real_T *x,
                                            int unsigned_nRows,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y);

static int d_FFTImplementationCallback_rad(const emxArray_real_T *y,
                                           int *nRowsM2, int *nRowsD2,
                                           int *nRowsD4, double *e);

static void e_FFTImplementationCallback_get(const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_real_T *hcostab,
                                            emxArray_real_T *hsintab);

static void e_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                            int unsigned_nRows,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y);

static void f_FFTImplementationCallback_get(int hnRows,
                                            const emxArray_real_T *costable,
                                            const emxArray_real_T *sintable,
                                            emxArray_creal_T *reconVar1,
                                            emxArray_creal_T *reconVar2);

static void f_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                            int n1_unsigned,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y);

static void g_FFTImplementationCallback_get(int nRowsM1, int nfftLen,
                                            emxArray_int32_T *bitrevIndex);

static void g_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                            int n1_unsigned,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y);

static void h_FFTImplementationCallback_get(
    const emxArray_real_T *costab, const emxArray_real_T *sintab,
    const emxArray_real_T *costabinv, const emxArray_real_T *sintabinv,
    emxArray_real_T *hcostab, emxArray_real_T *hsintab,
    emxArray_real_T *hcostabinv, emxArray_real_T *hsintabinv);

static void i_FFTImplementationCallback_get(int hnRows,
                                            const emxArray_real_T *costable,
                                            const emxArray_real_T *sintable,
                                            emxArray_creal_T *reconVar1,
                                            emxArray_creal_T *reconVar2);

static void j_FFTImplementationCallback_get(emxArray_creal_T *y,
                                            const emxArray_creal_T *reconVar1,
                                            const emxArray_creal_T *reconVar2,
                                            const emxArray_int32_T *wrapIndex,
                                            int hnRows);

static void k_FFTImplementationCallback_get(emxArray_creal_T *y,
                                            const emxArray_creal_T *yk,
                                            const emxArray_creal_T *reconVar1,
                                            const emxArray_creal_T *reconVar2,
                                            const emxArray_int32_T *wrapIndex,
                                            int hnRows);

/* Function Definitions */
/*
 * Arguments    : int nfftLen
 *                emxArray_int32_T *wrapIndex
 * Return Type  : void
 */
static void c_FFTImplementationCallback_cal(int nfftLen,
                                            emxArray_int32_T *wrapIndex)
{
  int i;
  int *wrapIndex_data;
  i = wrapIndex->size[0] * wrapIndex->size[1];
  wrapIndex->size[0] = 1;
  wrapIndex->size[1] = nfftLen;
  emxEnsureCapacity_int32_T(wrapIndex, i);
  wrapIndex_data = wrapIndex->data;
  for (i = 0; i < nfftLen; i++) {
    if (i + 1 != 1) {
      wrapIndex_data[i] = (nfftLen - i) + 1;
    } else {
      wrapIndex_data[0] = 1;
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_creal_T *y
 *                int unsigned_nRows
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 * Return Type  : void
 */
static void c_FFTImplementationCallback_doH(const emxArray_real_T *x,
                                            emxArray_creal_T *y,
                                            int unsigned_nRows,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab)
{
  emxArray_creal_T *reconVar1;
  emxArray_creal_T *reconVar2;
  emxArray_int32_T *bitrevIndex;
  emxArray_int32_T *r;
  emxArray_real_T *hcostab;
  emxArray_real_T *hsintab;
  creal_T *y_data;
  const double *x_data;
  double e;
  double im;
  double temp_im;
  double temp_re;
  double twid_im;
  double twid_re;
  double z;
  double *hcostab_data;
  double *hsintab_data;
  int i;
  int iDelta;
  int iDelta2;
  int iheight;
  int ihi;
  int istart;
  int j;
  int k;
  int nRows;
  int nRowsD2;
  int *bitrevIndex_data;
  boolean_T nxeven;
  y_data = y->data;
  x_data = x->data;
  nRows = (int)((unsigned int)unsigned_nRows >> 1);
  istart = c_FFTImplementationCallback_rad(y, nRows, &ihi, &nRowsD2, &k, &e);
  emxInit_real_T(&hcostab, 2);
  emxInit_real_T(&hsintab, 2);
  e_FFTImplementationCallback_get(costab, sintab, hcostab, hsintab);
  hsintab_data = hsintab->data;
  hcostab_data = hcostab->data;
  emxInit_creal_T(&reconVar1);
  emxInit_creal_T(&reconVar2);
  f_FFTImplementationCallback_get(nRows, costab, sintab, reconVar1, reconVar2);
  z = (double)unsigned_nRows / 2.0;
  emxInit_int32_T(&bitrevIndex, 1);
  g_FFTImplementationCallback_get(istart, (int)z, bitrevIndex);
  bitrevIndex_data = bitrevIndex->data;
  nxeven = c_FFTImplementationCallback_pad(x, unsigned_nRows, &istart);
  e = (double)istart / 2.0;
  istart = (int)e;
  for (i = 0; i < istart; i++) {
    j = i << 1;
    y_data[bitrevIndex_data[i] - 1].re = x_data[j];
    y_data[bitrevIndex_data[i] - 1].im = x_data[j + 1];
  }
  if (!nxeven) {
    istart = bitrevIndex_data[(int)e] - 1;
    if ((int)e - 1 < 0) {
      j = 0;
    } else {
      j = (int)e << 1;
    }
    y_data[istart].re = x_data[j];
    y_data[istart].im = 0.0;
  }
  emxFree_int32_T(&bitrevIndex);
  if (nRows > 1) {
    for (i = 0; i <= ihi; i += 2) {
      e = y_data[i + 1].re;
      im = y_data[i + 1].im;
      temp_re = e;
      temp_im = im;
      twid_re = y_data[i].re;
      twid_im = y_data[i].im;
      e = twid_re - e;
      im = twid_im - im;
      y_data[i + 1].re = e;
      y_data[i + 1].im = im;
      twid_re += temp_re;
      twid_im += temp_im;
      y_data[i].re = twid_re;
      y_data[i].im = twid_im;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      istart = i + iDelta;
      temp_re = y_data[istart].re;
      temp_im = y_data[istart].im;
      y_data[istart].re = y_data[i].re - temp_re;
      y_data[istart].im = y_data[i].im - temp_im;
      y_data[i].re += temp_re;
      y_data[i].im += temp_im;
    }
    istart = 1;
    for (j = k; j < nRowsD2; j += k) {
      twid_re = hcostab_data[j];
      twid_im = hsintab_data[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        int temp_re_tmp_tmp;
        temp_re_tmp_tmp = i + iDelta;
        e = y_data[temp_re_tmp_tmp].im;
        im = y_data[temp_re_tmp_tmp].re;
        temp_re = twid_re * im - twid_im * e;
        temp_im = twid_re * e + twid_im * im;
        y_data[temp_re_tmp_tmp].re = y_data[i].re - temp_re;
        y_data[temp_re_tmp_tmp].im = y_data[i].im - temp_im;
        y_data[i].re += temp_re;
        y_data[i].im += temp_im;
        i += iDelta2;
      }
      istart++;
    }
    k /= 2;
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
  emxFree_real_T(&hsintab);
  emxFree_real_T(&hcostab);
  emxInit_int32_T(&r, 2);
  c_FFTImplementationCallback_cal(nRows, r);
  j_FFTImplementationCallback_get(y, reconVar1, reconVar2, r, (int)z);
  emxFree_int32_T(&r);
  emxFree_creal_T(&reconVar2);
  emxFree_creal_T(&reconVar1);
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int n1
 *                int *minX
 * Return Type  : boolean_T
 */
static boolean_T c_FFTImplementationCallback_pad(const emxArray_real_T *x,
                                                 int n1, int *minX)
{
  int sizeX;
  boolean_T nxeven;
  if ((x->size[0] & 1) == 0) {
    nxeven = true;
    sizeX = x->size[0];
  } else if (x->size[0] >= n1) {
    nxeven = true;
    sizeX = n1;
  } else {
    nxeven = false;
    sizeX = x->size[0] - 1;
  }
  if (sizeX <= n1) {
    *minX = sizeX;
  } else {
    *minX = n1;
  }
  return nxeven;
}

/*
 * Arguments    : const emxArray_creal_T *y
 *                int nRows
 *                int *nRowsM2
 *                int *nRowsD2
 *                int *nRowsD4
 *                double *e
 * Return Type  : int
 */
static int c_FFTImplementationCallback_rad(const emxArray_creal_T *y, int nRows,
                                           int *nRowsM2, int *nRowsD2,
                                           int *nRowsD4, double *e)
{
  int nRowsM1;
  int u0;
  u0 = y->size[0];
  if (u0 > nRows) {
    u0 = nRows;
  }
  nRowsM1 = u0 - 1;
  *nRowsM2 = nRows - 2;
  *nRowsD2 = (int)((unsigned int)nRows >> 1);
  *nRowsD4 = *nRowsD2 / 2;
  *e = 6.2831853071795862 / (double)nRows;
  return nRowsM1;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_creal_T *y
 *                int nrowsx
 *                int nRows
 *                int nfft
 *                const emxArray_creal_T *wwc
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                const emxArray_real_T *costabinv
 *                const emxArray_real_T *sintabinv
 * Return Type  : void
 */
static void d_FFTImplementationCallback_doH(
    const emxArray_real_T *x, emxArray_creal_T *y, int nrowsx, int nRows,
    int nfft, const emxArray_creal_T *wwc, const emxArray_real_T *costab,
    const emxArray_real_T *sintab, const emxArray_real_T *costabinv,
    const emxArray_real_T *sintabinv)
{
  emxArray_creal_T *b_fv;
  emxArray_creal_T *fv;
  emxArray_creal_T *reconVar1;
  emxArray_creal_T *reconVar2;
  emxArray_creal_T *ytmp;
  emxArray_int32_T *r;
  emxArray_real_T *a__1;
  emxArray_real_T *costable;
  emxArray_real_T *hcostabinv;
  emxArray_real_T *hsintab;
  emxArray_real_T *hsintabinv;
  emxArray_real_T *sintable;
  const creal_T *wwc_data;
  creal_T *b_fv_data;
  creal_T *fv_data;
  creal_T *ytmp_data;
  const double *x_data;
  double a_im;
  double a_re;
  double b_re;
  double z_tmp;
  int b_re_tmp;
  int hnRows;
  int i;
  int k1;
  int minHnrowsNx;
  boolean_T nxeven;
  wwc_data = wwc->data;
  x_data = x->data;
  hnRows = (int)((unsigned int)nRows >> 1);
  emxInit_creal_T(&ytmp);
  i = ytmp->size[0];
  ytmp->size[0] = hnRows;
  emxEnsureCapacity_creal_T(ytmp, i);
  ytmp_data = ytmp->data;
  if (hnRows > nrowsx) {
    i = ytmp->size[0];
    ytmp->size[0] = hnRows;
    emxEnsureCapacity_creal_T(ytmp, i);
    ytmp_data = ytmp->data;
    for (i = 0; i < hnRows; i++) {
      ytmp_data[i].re = 0.0;
      ytmp_data[i].im = 0.0;
    }
  }
  nxeven = c_FFTImplementationCallback_pad(x, nRows, &minHnrowsNx);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&costable, 2);
  emxInit_real_T(&sintable, 2);
  d_FFTImplementationCallback_gen(nRows << 1, costable, sintable, a__1);
  emxInit_real_T(&hsintab, 2);
  emxInit_real_T(&hcostabinv, 2);
  emxInit_real_T(&hsintabinv, 2);
  h_FFTImplementationCallback_get(costab, sintab, costabinv, sintabinv, a__1,
                                  hsintab, hcostabinv, hsintabinv);
  emxInit_creal_T(&reconVar1);
  emxInit_creal_T(&reconVar2);
  i_FFTImplementationCallback_get(hnRows, costable, sintable, reconVar1,
                                  reconVar2);
  emxFree_real_T(&sintable);
  emxFree_real_T(&costable);
  z_tmp = (double)minHnrowsNx / 2.0;
  i = (int)z_tmp;
  for (k1 = 0; k1 < i; k1++) {
    double b_im;
    a_re = wwc_data[(hnRows + k1) - 1].re;
    a_im = wwc_data[(hnRows + k1) - 1].im;
    b_re_tmp = k1 << 1;
    b_re = x_data[b_re_tmp];
    b_im = x_data[b_re_tmp + 1];
    ytmp_data[k1].re = a_re * b_re + a_im * b_im;
    ytmp_data[k1].im = a_re * b_im - a_im * b_re;
  }
  if (!nxeven) {
    a_re = wwc_data[(hnRows + (int)z_tmp) - 1].re;
    a_im = wwc_data[(hnRows + (int)z_tmp) - 1].im;
    if ((int)z_tmp - 1 < 0) {
      i = 0;
    } else {
      i = (int)z_tmp << 1;
    }
    b_re = x_data[i];
    ytmp_data[(int)((double)minHnrowsNx / 2.0)].re = a_re * b_re + a_im * 0.0;
    ytmp_data[(int)((double)minHnrowsNx / 2.0)].im = a_re * 0.0 - a_im * b_re;
    if ((int)z_tmp + 2 <= hnRows) {
      i = (int)z_tmp + 2;
      for (minHnrowsNx = i; minHnrowsNx <= hnRows; minHnrowsNx++) {
        ytmp_data[minHnrowsNx - 1].re = 0.0;
        ytmp_data[minHnrowsNx - 1].im = 0.0;
      }
    }
  } else if ((int)z_tmp + 1 <= hnRows) {
    i = (int)z_tmp + 1;
    for (minHnrowsNx = i; minHnrowsNx <= hnRows; minHnrowsNx++) {
      ytmp_data[minHnrowsNx - 1].re = 0.0;
      ytmp_data[minHnrowsNx - 1].im = 0.0;
    }
  }
  minHnrowsNx = (int)((double)nfft / 2.0);
  emxInit_creal_T(&fv);
  e_FFTImplementationCallback_r2b(ytmp, minHnrowsNx, a__1, hsintab, fv);
  fv_data = fv->data;
  emxInit_creal_T(&b_fv);
  f_FFTImplementationCallback_r2b(wwc, minHnrowsNx, a__1, hsintab, b_fv);
  emxFree_real_T(&hsintab);
  emxFree_real_T(&a__1);
  i = b_fv->size[0];
  b_fv->size[0] = fv->size[0];
  emxEnsureCapacity_creal_T(b_fv, i);
  b_fv_data = b_fv->data;
  b_re_tmp = fv->size[0];
  for (i = 0; i < b_re_tmp; i++) {
    z_tmp = fv_data[i].re;
    a_re = b_fv_data[i].im;
    a_im = fv_data[i].im;
    b_re = b_fv_data[i].re;
    b_fv_data[i].re = z_tmp * b_re - a_im * a_re;
    b_fv_data[i].im = z_tmp * a_re + a_im * b_re;
  }
  g_FFTImplementationCallback_r2b(b_fv, minHnrowsNx, hcostabinv, hsintabinv,
                                  fv);
  fv_data = fv->data;
  emxFree_creal_T(&b_fv);
  emxFree_real_T(&hsintabinv);
  emxFree_real_T(&hcostabinv);
  i = wwc->size[0];
  for (minHnrowsNx = hnRows; minHnrowsNx <= i; minHnrowsNx++) {
    z_tmp = wwc_data[minHnrowsNx - 1].re;
    a_re = fv_data[minHnrowsNx - 1].im;
    a_im = wwc_data[minHnrowsNx - 1].im;
    b_re = fv_data[minHnrowsNx - 1].re;
    ytmp_data[minHnrowsNx - hnRows].re = z_tmp * b_re + a_im * a_re;
    ytmp_data[minHnrowsNx - hnRows].im = z_tmp * a_re - a_im * b_re;
  }
  emxFree_creal_T(&fv);
  emxInit_int32_T(&r, 2);
  c_FFTImplementationCallback_cal(hnRows, r);
  k_FFTImplementationCallback_get(y, ytmp, reconVar1, reconVar2, r, hnRows);
  emxFree_int32_T(&r);
  emxFree_creal_T(&reconVar2);
  emxFree_creal_T(&reconVar1);
  emxFree_creal_T(&ytmp);
}

/*
 * Arguments    : int nRows
 *                emxArray_real_T *costab
 *                emxArray_real_T *sintab
 *                emxArray_real_T *sintabinv
 * Return Type  : void
 */
static void d_FFTImplementationCallback_gen(int nRows, emxArray_real_T *costab,
                                            emxArray_real_T *sintab,
                                            emxArray_real_T *sintabinv)
{
  emxArray_real_T *costab1q;
  double e;
  double *costab1q_data;
  double *costab_data;
  double *sintab_data;
  double *sintabinv_data;
  int i;
  int k;
  int n;
  int nd2;
  e = 6.2831853071795862 / (double)nRows;
  n = (int)((unsigned int)nRows >> 1) >> 1;
  emxInit_real_T(&costab1q, 2);
  i = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = n + 1;
  emxEnsureCapacity_real_T(costab1q, i);
  costab1q_data = costab1q->data;
  costab1q_data[0] = 1.0;
  nd2 = n / 2 - 1;
  for (k = 0; k <= nd2; k++) {
    costab1q_data[k + 1] = e * ((double)k + 1.0);
    e_cos(&costab1q_data[k + 1]);
  }
  i = nd2 + 2;
  nd2 = n - 1;
  for (k = i; k <= nd2; k++) {
    costab1q_data[k] = e * (double)(n - k);
    d_sin(&costab1q_data[k]);
  }
  costab1q_data[n] = 0.0;
  n = costab1q->size[1] - 1;
  nd2 = (costab1q->size[1] - 1) << 1;
  i = costab->size[0] * costab->size[1];
  costab->size[0] = 1;
  costab->size[1] = nd2 + 1;
  emxEnsureCapacity_real_T(costab, i);
  costab_data = costab->data;
  i = sintab->size[0] * sintab->size[1];
  sintab->size[0] = 1;
  sintab->size[1] = nd2 + 1;
  emxEnsureCapacity_real_T(sintab, i);
  sintab_data = sintab->data;
  costab_data[0] = 1.0;
  sintab_data[0] = 0.0;
  i = sintabinv->size[0] * sintabinv->size[1];
  sintabinv->size[0] = 1;
  sintabinv->size[1] = nd2 + 1;
  emxEnsureCapacity_real_T(sintabinv, i);
  sintabinv_data = sintabinv->data;
  for (k = 0; k < n; k++) {
    sintabinv_data[k + 1] = costab1q_data[(n - k) - 1];
  }
  i = costab1q->size[1];
  for (k = i; k <= nd2; k++) {
    sintabinv_data[k] = costab1q_data[k - n];
  }
  for (k = 0; k < n; k++) {
    costab_data[k + 1] = costab1q_data[k + 1];
    sintab_data[k + 1] = -costab1q_data[(n - k) - 1];
  }
  i = costab1q->size[1];
  for (k = i; k <= nd2; k++) {
    costab_data[k] = -costab1q_data[nd2 - k];
    sintab_data[k] = -costab1q_data[k - n];
  }
  emxFree_real_T(&costab1q);
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int unsigned_nRows
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void d_FFTImplementationCallback_r2b(const emxArray_real_T *x,
                                            int unsigned_nRows,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y)
{
  creal_T *y_data;
  const double *costab_data;
  const double *sintab_data;
  const double *x_data;
  double temp_im;
  int i;
  int istart;
  int j;
  int k;
  int nRowsD2;
  sintab_data = sintab->data;
  costab_data = costab->data;
  x_data = x->data;
  istart = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_creal_T(y, istart);
  y_data = y->data;
  if (unsigned_nRows > x->size[0]) {
    istart = y->size[0];
    y->size[0] = unsigned_nRows;
    emxEnsureCapacity_creal_T(y, istart);
    y_data = y->data;
    for (istart = 0; istart < unsigned_nRows; istart++) {
      y_data[istart].re = 0.0;
      y_data[istart].im = 0.0;
    }
  }
  if (unsigned_nRows != 1) {
    c_FFTImplementationCallback_doH(x, y, unsigned_nRows, costab, sintab);
  } else {
    int loop_ub;
    j = d_FFTImplementationCallback_rad(x, &istart, &nRowsD2, &k, &temp_im);
    loop_ub = j - 1;
    i = 0;
    int exitg1;
    do {
      if (i <= loop_ub) {
        y_data[0].re = x_data[i];
        y_data[0].im = 0.0;
        exitg1 = 1;
      } else {
        int iDelta;
        int iDelta2;
        int iheight;
        if (j - 1 < 0) {
          j = 0;
        }
        y_data[0].re = x_data[j];
        y_data[0].im = 0.0;
        iDelta = 2;
        iDelta2 = 4;
        iheight = ((k - 1) << 2) + 1;
        while (k > 0) {
          double temp_re;
          for (i = 0; i < iheight; i += iDelta2) {
            istart = i + iDelta;
            temp_re = y_data[istart].re;
            temp_im = y_data[istart].im;
            y_data[istart].re = y_data[i].re - temp_re;
            y_data[istart].im = y_data[i].im - temp_im;
            y_data[i].re += temp_re;
            y_data[i].im += temp_im;
          }
          istart = 1;
          for (j = k; j < nRowsD2; j += k) {
            double twid_im;
            double twid_re;
            int ihi;
            twid_re = costab_data[j];
            twid_im = sintab_data[j];
            i = istart;
            ihi = istart + iheight;
            while (i < ihi) {
              double temp_re_tmp;
              int temp_re_tmp_tmp;
              temp_re_tmp_tmp = i + iDelta;
              temp_im = y_data[temp_re_tmp_tmp].im;
              temp_re_tmp = y_data[temp_re_tmp_tmp].re;
              temp_re = twid_re * temp_re_tmp - twid_im * temp_im;
              temp_im = twid_re * temp_im + twid_im * temp_re_tmp;
              y_data[temp_re_tmp_tmp].re = y_data[i].re - temp_re;
              y_data[temp_re_tmp_tmp].im = y_data[i].im - temp_im;
              y_data[i].re += temp_re;
              y_data[i].im += temp_im;
              i += iDelta2;
            }
            istart++;
          }
          k /= 2;
          iDelta = iDelta2;
          iDelta2 += iDelta2;
          iheight -= iDelta;
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : const emxArray_real_T *y
 *                int *nRowsM2
 *                int *nRowsD2
 *                int *nRowsD4
 *                double *e
 * Return Type  : int
 */
static int d_FFTImplementationCallback_rad(const emxArray_real_T *y,
                                           int *nRowsM2, int *nRowsD2,
                                           int *nRowsD4, double *e)
{
  int nRowsM1;
  int u0;
  u0 = y->size[0];
  if (u0 > 1) {
    u0 = 1;
  }
  nRowsM1 = u0 - 1;
  *nRowsM2 = -1;
  *nRowsD2 = 0;
  *nRowsD4 = 0;
  *e = 6.2831853071795862;
  return nRowsM1;
}

/*
 * Arguments    : const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_real_T *hcostab
 *                emxArray_real_T *hsintab
 * Return Type  : void
 */
static void e_FFTImplementationCallback_get(const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_real_T *hcostab,
                                            emxArray_real_T *hsintab)
{
  const double *costab_data;
  const double *sintab_data;
  double *hcostab_data;
  double *hsintab_data;
  int hcostab_tmp;
  int hszCostab;
  int i;
  sintab_data = sintab->data;
  costab_data = costab->data;
  hszCostab = (int)((unsigned int)costab->size[1] >> 1);
  hcostab_tmp = hcostab->size[0] * hcostab->size[1];
  hcostab->size[0] = 1;
  hcostab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hcostab, hcostab_tmp);
  hcostab_data = hcostab->data;
  hcostab_tmp = hsintab->size[0] * hsintab->size[1];
  hsintab->size[0] = 1;
  hsintab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hsintab, hcostab_tmp);
  hsintab_data = hsintab->data;
  for (i = 0; i < hszCostab; i++) {
    hcostab_tmp = ((i + 1) << 1) - 2;
    hcostab_data[i] = costab_data[hcostab_tmp];
    hsintab_data[i] = sintab_data[hcostab_tmp];
  }
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                int unsigned_nRows
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void e_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                            int unsigned_nRows,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y)
{
  const creal_T *x_data;
  creal_T *y_data;
  const double *costab_data;
  const double *sintab_data;
  double temp_im;
  double temp_re;
  double temp_re_tmp;
  double twid_re;
  int i;
  int iDelta;
  int iDelta2;
  int iheight;
  int ihi;
  int iy;
  int j;
  int ju;
  int k;
  int nRowsD2;
  sintab_data = sintab->data;
  costab_data = costab->data;
  x_data = x->data;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_creal_T(y, iy);
  y_data = y->data;
  if (unsigned_nRows > x->size[0]) {
    iy = y->size[0];
    y->size[0] = unsigned_nRows;
    emxEnsureCapacity_creal_T(y, iy);
    y_data = y->data;
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y_data[iy].re = 0.0;
      y_data[iy].im = 0.0;
    }
  }
  j = c_FFTImplementationCallback_rad(x, unsigned_nRows, &ihi, &nRowsD2, &k,
                                      &temp_im);
  iy = 0;
  ju = 0;
  for (i = 0; i < j; i++) {
    boolean_T tst;
    y_data[iy] = x_data[i];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju;
  }
  if (j - 1 < 0) {
    j = 0;
  }
  y_data[iy] = x_data[j];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= ihi; i += 2) {
      temp_re_tmp = y_data[i + 1].re;
      temp_im = y_data[i + 1].im;
      temp_re = y_data[i].re;
      twid_re = y_data[i].im;
      y_data[i + 1].re = temp_re - temp_re_tmp;
      y_data[i + 1].im = twid_re - temp_im;
      y_data[i].re = temp_re + temp_re_tmp;
      y_data[i].im = twid_re + temp_im;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      iy = i + iDelta;
      temp_re = y_data[iy].re;
      temp_im = y_data[iy].im;
      y_data[iy].re = y_data[i].re - temp_re;
      y_data[iy].im = y_data[i].im - temp_im;
      y_data[i].re += temp_re;
      y_data[i].im += temp_im;
    }
    iy = 1;
    for (j = k; j < nRowsD2; j += k) {
      double twid_im;
      twid_re = costab_data[j];
      twid_im = sintab_data[j];
      i = iy;
      ihi = iy + iheight;
      while (i < ihi) {
        ju = i + iDelta;
        temp_re_tmp = y_data[ju].im;
        temp_im = y_data[ju].re;
        temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
        temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
        y_data[ju].re = y_data[i].re - temp_re;
        y_data[ju].im = y_data[i].im - temp_im;
        y_data[i].re += temp_re;
        y_data[i].im += temp_im;
        i += iDelta2;
      }
      iy++;
    }
    k /= 2;
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
}

/*
 * Arguments    : int hnRows
 *                const emxArray_real_T *costable
 *                const emxArray_real_T *sintable
 *                emxArray_creal_T *reconVar1
 *                emxArray_creal_T *reconVar2
 * Return Type  : void
 */
static void f_FFTImplementationCallback_get(int hnRows,
                                            const emxArray_real_T *costable,
                                            const emxArray_real_T *sintable,
                                            emxArray_creal_T *reconVar1,
                                            emxArray_creal_T *reconVar2)
{
  creal_T *reconVar1_data;
  creal_T *reconVar2_data;
  const double *costable_data;
  const double *sintable_data;
  int i;
  sintable_data = sintable->data;
  costable_data = costable->data;
  i = reconVar1->size[0];
  reconVar1->size[0] = hnRows;
  emxEnsureCapacity_creal_T(reconVar1, i);
  reconVar1_data = reconVar1->data;
  i = reconVar2->size[0];
  reconVar2->size[0] = hnRows;
  emxEnsureCapacity_creal_T(reconVar2, i);
  reconVar2_data = reconVar2->data;
  for (i = 0; i < hnRows; i++) {
    double d;
    double d1;
    d = sintable_data[i];
    d1 = costable_data[i];
    reconVar1_data[i].re = d + 1.0;
    reconVar1_data[i].im = -d1;
    reconVar2_data[i].re = 1.0 - d;
    reconVar2_data[i].im = d1;
  }
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                int n1_unsigned
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void f_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                            int n1_unsigned,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y)
{
  e_FFTImplementationCallback_r2b(x, n1_unsigned, costab, sintab, y);
}

/*
 * Arguments    : int nRowsM1
 *                int nfftLen
 *                emxArray_int32_T *bitrevIndex
 * Return Type  : void
 */
static void g_FFTImplementationCallback_get(int nRowsM1, int nfftLen,
                                            emxArray_int32_T *bitrevIndex)
{
  int b_j1;
  int iy;
  int ju;
  int *bitrevIndex_data;
  ju = 0;
  iy = 1;
  b_j1 = bitrevIndex->size[0];
  bitrevIndex->size[0] = nfftLen;
  emxEnsureCapacity_int32_T(bitrevIndex, b_j1);
  bitrevIndex_data = bitrevIndex->data;
  for (b_j1 = 0; b_j1 < nfftLen; b_j1++) {
    bitrevIndex_data[b_j1] = 0;
  }
  for (b_j1 = 0; b_j1 < nRowsM1; b_j1++) {
    boolean_T tst;
    bitrevIndex_data[b_j1] = iy;
    iy = nfftLen;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju + 1;
  }
  bitrevIndex_data[nRowsM1] = iy;
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                int n1_unsigned
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void g_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                            int n1_unsigned,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y)
{
  creal_T *y_data;
  int i;
  e_FFTImplementationCallback_r2b(x, n1_unsigned, costab, sintab, y);
  y_data = y->data;
  if (y->size[0] > 1) {
    double b;
    int loop_ub;
    b = 1.0 / (double)y->size[0];
    loop_ub = y->size[0];
    for (i = 0; i < loop_ub; i++) {
      y_data[i].re *= b;
      y_data[i].im *= b;
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                const emxArray_real_T *costabinv
 *                const emxArray_real_T *sintabinv
 *                emxArray_real_T *hcostab
 *                emxArray_real_T *hsintab
 *                emxArray_real_T *hcostabinv
 *                emxArray_real_T *hsintabinv
 * Return Type  : void
 */
static void h_FFTImplementationCallback_get(
    const emxArray_real_T *costab, const emxArray_real_T *sintab,
    const emxArray_real_T *costabinv, const emxArray_real_T *sintabinv,
    emxArray_real_T *hcostab, emxArray_real_T *hsintab,
    emxArray_real_T *hcostabinv, emxArray_real_T *hsintabinv)
{
  const double *costab_data;
  const double *costabinv_data;
  const double *sintab_data;
  const double *sintabinv_data;
  double *hcostab_data;
  double *hcostabinv_data;
  double *hsintab_data;
  double *hsintabinv_data;
  int hcostab_tmp;
  int hszCostab;
  int i;
  sintabinv_data = sintabinv->data;
  costabinv_data = costabinv->data;
  sintab_data = sintab->data;
  costab_data = costab->data;
  hszCostab = (int)((unsigned int)costab->size[1] >> 1);
  hcostab_tmp = hcostab->size[0] * hcostab->size[1];
  hcostab->size[0] = 1;
  hcostab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hcostab, hcostab_tmp);
  hcostab_data = hcostab->data;
  hcostab_tmp = hsintab->size[0] * hsintab->size[1];
  hsintab->size[0] = 1;
  hsintab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hsintab, hcostab_tmp);
  hsintab_data = hsintab->data;
  hcostab_tmp = hcostabinv->size[0] * hcostabinv->size[1];
  hcostabinv->size[0] = 1;
  hcostabinv->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hcostabinv, hcostab_tmp);
  hcostabinv_data = hcostabinv->data;
  hcostab_tmp = hsintabinv->size[0] * hsintabinv->size[1];
  hsintabinv->size[0] = 1;
  hsintabinv->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hsintabinv, hcostab_tmp);
  hsintabinv_data = hsintabinv->data;
  for (i = 0; i < hszCostab; i++) {
    hcostab_tmp = ((i + 1) << 1) - 2;
    hcostab_data[i] = costab_data[hcostab_tmp];
    hsintab_data[i] = sintab_data[hcostab_tmp];
    hcostabinv_data[i] = costabinv_data[hcostab_tmp];
    hsintabinv_data[i] = sintabinv_data[hcostab_tmp];
  }
}

/*
 * Arguments    : int hnRows
 *                const emxArray_real_T *costable
 *                const emxArray_real_T *sintable
 *                emxArray_creal_T *reconVar1
 *                emxArray_creal_T *reconVar2
 * Return Type  : void
 */
static void i_FFTImplementationCallback_get(int hnRows,
                                            const emxArray_real_T *costable,
                                            const emxArray_real_T *sintable,
                                            emxArray_creal_T *reconVar1,
                                            emxArray_creal_T *reconVar2)
{
  creal_T *reconVar1_data;
  creal_T *reconVar2_data;
  const double *costable_data;
  const double *sintable_data;
  int b_i;
  int i;
  sintable_data = sintable->data;
  costable_data = costable->data;
  i = reconVar1->size[0];
  reconVar1->size[0] = hnRows;
  emxEnsureCapacity_creal_T(reconVar1, i);
  reconVar1_data = reconVar1->data;
  i = reconVar2->size[0];
  reconVar2->size[0] = hnRows;
  emxEnsureCapacity_creal_T(reconVar2, i);
  reconVar2_data = reconVar2->data;
  for (b_i = 0; b_i < hnRows; b_i++) {
    double d;
    double d1;
    i = b_i << 1;
    d = sintable_data[i];
    d1 = costable_data[i];
    reconVar1_data[b_i].re = d + 1.0;
    reconVar1_data[b_i].im = -d1;
    reconVar2_data[b_i].re = 1.0 - d;
    reconVar2_data[b_i].im = d1;
  }
}

/*
 * Arguments    : emxArray_creal_T *y
 *                const emxArray_creal_T *reconVar1
 *                const emxArray_creal_T *reconVar2
 *                const emxArray_int32_T *wrapIndex
 *                int hnRows
 * Return Type  : void
 */
static void j_FFTImplementationCallback_get(emxArray_creal_T *y,
                                            const emxArray_creal_T *reconVar1,
                                            const emxArray_creal_T *reconVar2,
                                            const emxArray_int32_T *wrapIndex,
                                            int hnRows)
{
  const creal_T *reconVar1_data;
  const creal_T *reconVar2_data;
  creal_T *y_data;
  double b_temp1_re_tmp;
  double b_temp2_re_tmp;
  double b_y_re_tmp;
  double c_y_re_tmp;
  double d_y_re_tmp;
  double temp1_im_tmp;
  double temp1_re_tmp;
  double temp1_re_tmp_tmp;
  double y_im_tmp;
  double y_re_tmp;
  const int *wrapIndex_data;
  int i;
  int iterVar;
  wrapIndex_data = wrapIndex->data;
  reconVar2_data = reconVar2->data;
  reconVar1_data = reconVar1->data;
  y_data = y->data;
  iterVar = (int)((unsigned int)hnRows >> 1);
  temp1_re_tmp_tmp = y_data[0].re;
  temp1_im_tmp = y_data[0].im;
  y_re_tmp = temp1_re_tmp_tmp * reconVar1_data[0].re;
  y_im_tmp = temp1_re_tmp_tmp * reconVar1_data[0].im;
  b_y_re_tmp = temp1_re_tmp_tmp * reconVar2_data[0].re;
  temp1_re_tmp_tmp *= reconVar2_data[0].im;
  y_data[0].re = 0.5 * ((y_re_tmp - temp1_im_tmp * reconVar1_data[0].im) +
                        (b_y_re_tmp - -temp1_im_tmp * reconVar2_data[0].im));
  y_data[0].im =
      0.5 * ((y_im_tmp + temp1_im_tmp * reconVar1_data[0].re) +
             (temp1_re_tmp_tmp + -temp1_im_tmp * reconVar2_data[0].re));
  y_data[hnRows].re =
      0.5 * ((b_y_re_tmp - temp1_im_tmp * reconVar2_data[0].im) +
             (y_re_tmp - -temp1_im_tmp * reconVar1_data[0].im));
  y_data[hnRows].im =
      0.5 * ((temp1_re_tmp_tmp + temp1_im_tmp * reconVar2_data[0].re) +
             (y_im_tmp + -temp1_im_tmp * reconVar1_data[0].re));
  for (i = 2; i <= iterVar; i++) {
    double temp2_im_tmp;
    double temp2_re_tmp;
    int b_i;
    int i1;
    temp1_re_tmp = y_data[i - 1].re;
    temp1_im_tmp = y_data[i - 1].im;
    b_i = wrapIndex_data[i - 1];
    temp2_re_tmp = y_data[b_i - 1].re;
    temp2_im_tmp = y_data[b_i - 1].im;
    y_re_tmp = reconVar1_data[i - 1].im;
    b_y_re_tmp = reconVar1_data[i - 1].re;
    c_y_re_tmp = reconVar2_data[i - 1].im;
    d_y_re_tmp = reconVar2_data[i - 1].re;
    y_data[i - 1].re =
        0.5 * ((temp1_re_tmp * b_y_re_tmp - temp1_im_tmp * y_re_tmp) +
               (temp2_re_tmp * d_y_re_tmp - -temp2_im_tmp * c_y_re_tmp));
    y_data[i - 1].im =
        0.5 * ((temp1_re_tmp * y_re_tmp + temp1_im_tmp * b_y_re_tmp) +
               (temp2_re_tmp * c_y_re_tmp + -temp2_im_tmp * d_y_re_tmp));
    i1 = (hnRows + i) - 1;
    y_data[i1].re =
        0.5 * ((temp1_re_tmp * d_y_re_tmp - temp1_im_tmp * c_y_re_tmp) +
               (temp2_re_tmp * b_y_re_tmp - -temp2_im_tmp * y_re_tmp));
    y_data[i1].im =
        0.5 * ((temp1_re_tmp * c_y_re_tmp + temp1_im_tmp * d_y_re_tmp) +
               (temp2_re_tmp * y_re_tmp + -temp2_im_tmp * b_y_re_tmp));
    temp1_re_tmp_tmp = reconVar1_data[b_i - 1].im;
    b_temp2_re_tmp = reconVar1_data[b_i - 1].re;
    b_temp1_re_tmp = reconVar2_data[b_i - 1].im;
    y_im_tmp = reconVar2_data[b_i - 1].re;
    y_data[b_i - 1].re =
        0.5 *
        ((temp2_re_tmp * b_temp2_re_tmp - temp2_im_tmp * temp1_re_tmp_tmp) +
         (temp1_re_tmp * y_im_tmp - -temp1_im_tmp * b_temp1_re_tmp));
    y_data[b_i - 1].im =
        0.5 *
        ((temp2_re_tmp * temp1_re_tmp_tmp + temp2_im_tmp * b_temp2_re_tmp) +
         (temp1_re_tmp * b_temp1_re_tmp + -temp1_im_tmp * y_im_tmp));
    b_i = (b_i + hnRows) - 1;
    y_data[b_i].re =
        0.5 *
        ((temp2_re_tmp * y_im_tmp - temp2_im_tmp * b_temp1_re_tmp) +
         (temp1_re_tmp * b_temp2_re_tmp - -temp1_im_tmp * temp1_re_tmp_tmp));
    y_data[b_i].im =
        0.5 *
        ((temp2_re_tmp * b_temp1_re_tmp + temp2_im_tmp * y_im_tmp) +
         (temp1_re_tmp * temp1_re_tmp_tmp + -temp1_im_tmp * b_temp2_re_tmp));
  }
  if (iterVar != 0) {
    temp1_re_tmp = y_data[iterVar].re;
    temp1_im_tmp = y_data[iterVar].im;
    y_re_tmp = reconVar1_data[iterVar].im;
    b_y_re_tmp = reconVar1_data[iterVar].re;
    c_y_re_tmp = temp1_re_tmp * b_y_re_tmp;
    y_im_tmp = temp1_re_tmp * y_re_tmp;
    d_y_re_tmp = reconVar2_data[iterVar].im;
    b_temp2_re_tmp = reconVar2_data[iterVar].re;
    b_temp1_re_tmp = temp1_re_tmp * b_temp2_re_tmp;
    temp1_re_tmp_tmp = temp1_re_tmp * d_y_re_tmp;
    y_data[iterVar].re = 0.5 * ((c_y_re_tmp - temp1_im_tmp * y_re_tmp) +
                                (b_temp1_re_tmp - -temp1_im_tmp * d_y_re_tmp));
    y_data[iterVar].im =
        0.5 * ((y_im_tmp + temp1_im_tmp * b_y_re_tmp) +
               (temp1_re_tmp_tmp + -temp1_im_tmp * b_temp2_re_tmp));
    y_data[hnRows + iterVar].re =
        0.5 * ((b_temp1_re_tmp - temp1_im_tmp * d_y_re_tmp) +
               (c_y_re_tmp - -temp1_im_tmp * y_re_tmp));
    y_data[hnRows + iterVar].im =
        0.5 * ((temp1_re_tmp_tmp + temp1_im_tmp * b_temp2_re_tmp) +
               (y_im_tmp + -temp1_im_tmp * b_y_re_tmp));
  }
}

/*
 * Arguments    : emxArray_creal_T *y
 *                const emxArray_creal_T *yk
 *                const emxArray_creal_T *reconVar1
 *                const emxArray_creal_T *reconVar2
 *                const emxArray_int32_T *wrapIndex
 *                int hnRows
 * Return Type  : void
 */
static void k_FFTImplementationCallback_get(emxArray_creal_T *y,
                                            const emxArray_creal_T *yk,
                                            const emxArray_creal_T *reconVar1,
                                            const emxArray_creal_T *reconVar2,
                                            const emxArray_int32_T *wrapIndex,
                                            int hnRows)
{
  const creal_T *reconVar1_data;
  const creal_T *reconVar2_data;
  const creal_T *yk_data;
  creal_T *y_data;
  const int *wrapIndex_data;
  int i;
  wrapIndex_data = wrapIndex->data;
  reconVar2_data = reconVar2->data;
  reconVar1_data = reconVar1->data;
  yk_data = yk->data;
  y_data = y->data;
  for (i = 0; i < hnRows; i++) {
    double b_yk_re_tmp;
    double c_yk_re_tmp;
    double d_yk_re_tmp;
    double e_yk_re_tmp;
    double f_yk_re_tmp;
    double g_yk_re_tmp;
    double yk_im_tmp;
    double yk_re_tmp;
    int b_i;
    b_i = wrapIndex_data[i];
    yk_re_tmp = yk_data[i].re;
    b_yk_re_tmp = reconVar1_data[i].im;
    c_yk_re_tmp = yk_data[i].im;
    d_yk_re_tmp = reconVar1_data[i].re;
    e_yk_re_tmp = yk_data[b_i - 1].re;
    yk_im_tmp = -yk_data[b_i - 1].im;
    f_yk_re_tmp = reconVar2_data[i].im;
    g_yk_re_tmp = reconVar2_data[i].re;
    y_data[i].re =
        0.5 * ((yk_re_tmp * d_yk_re_tmp - c_yk_re_tmp * b_yk_re_tmp) +
               (e_yk_re_tmp * g_yk_re_tmp - yk_im_tmp * f_yk_re_tmp));
    y_data[i].im =
        0.5 * ((yk_re_tmp * b_yk_re_tmp + c_yk_re_tmp * d_yk_re_tmp) +
               (e_yk_re_tmp * f_yk_re_tmp + yk_im_tmp * g_yk_re_tmp));
    b_i = hnRows + i;
    y_data[b_i].re =
        0.5 * ((yk_re_tmp * g_yk_re_tmp - c_yk_re_tmp * f_yk_re_tmp) +
               (e_yk_re_tmp * d_yk_re_tmp - yk_im_tmp * b_yk_re_tmp));
    y_data[b_i].im =
        0.5 * ((yk_re_tmp * f_yk_re_tmp + c_yk_re_tmp * g_yk_re_tmp) +
               (e_yk_re_tmp * b_yk_re_tmp + yk_im_tmp * d_yk_re_tmp));
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int n2blue
 *                int nfft
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                const emxArray_real_T *sintabinv
 *                emxArray_creal_T *y
 * Return Type  : void
 */
void c_FFTImplementationCallback_dob(const emxArray_real_T *x, int n2blue,
                                     int nfft, const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab,
                                     const emxArray_real_T *sintabinv,
                                     emxArray_creal_T *y)
{
  emxArray_creal_T *b_fv;
  emxArray_creal_T *fv;
  emxArray_creal_T *wwc;
  creal_T a;
  creal_T *b_fv_data;
  creal_T *fv_data;
  creal_T *wwc_data;
  creal_T *y_data;
  const double *x_data;
  int i;
  int k;
  int nInt2m1;
  x_data = x->data;
  emxInit_creal_T(&wwc);
  if ((nfft != 1) && ((nfft & 1) == 0)) {
    int nInt2;
    int nRows;
    int rt;
    nRows = (int)((unsigned int)nfft >> 1);
    nInt2m1 = (nRows + nRows) - 1;
    i = wwc->size[0];
    wwc->size[0] = nInt2m1;
    emxEnsureCapacity_creal_T(wwc, i);
    wwc_data = wwc->data;
    rt = 0;
    wwc_data[nRows - 1].re = 1.0;
    wwc_data[nRows - 1].im = 0.0;
    nInt2 = nRows << 1;
    for (k = 0; k <= nRows - 2; k++) {
      rt = modplus(rt, ((k + 1) << 1) - 1, nInt2);
      a.re = 0.0;
      a.im = -3.1415926535897931 * (double)rt / (double)nRows;
      c_exp(&a);
      wwc_data[(nRows - k) - 2].re = a.re;
      wwc_data[(nRows - k) - 2].im = -a.im;
    }
    i = nInt2m1 - 1;
    for (k = i; k >= nRows; k--) {
      wwc_data[k] = wwc_data[(nInt2m1 - k) - 1];
    }
  } else {
    int nInt2;
    int rt;
    nInt2m1 = (nfft + nfft) - 1;
    i = wwc->size[0];
    wwc->size[0] = nInt2m1;
    emxEnsureCapacity_creal_T(wwc, i);
    wwc_data = wwc->data;
    rt = 0;
    wwc_data[nfft - 1].re = 1.0;
    wwc_data[nfft - 1].im = 0.0;
    nInt2 = nfft << 1;
    for (k = 0; k <= nfft - 2; k++) {
      rt = modplus(rt, ((k + 1) << 1) - 1, nInt2);
      a.re = 0.0;
      a.im = -3.1415926535897931 * (double)rt / (double)nfft;
      c_exp(&a);
      i = (nfft - k) - 2;
      wwc_data[i].re = a.re;
      wwc_data[i].im = -a.im;
    }
    i = nInt2m1 - 1;
    for (k = i; k >= nfft; k--) {
      wwc_data[k] = wwc_data[(nInt2m1 - k) - 1];
    }
  }
  i = y->size[0];
  y->size[0] = nfft;
  emxEnsureCapacity_creal_T(y, i);
  y_data = y->data;
  if (nfft > x->size[0]) {
    i = y->size[0];
    y->size[0] = nfft;
    emxEnsureCapacity_creal_T(y, i);
    y_data = y->data;
    for (i = 0; i < nfft; i++) {
      y_data[i].re = 0.0;
      y_data[i].im = 0.0;
    }
  }
  emxInit_creal_T(&fv);
  emxInit_creal_T(&b_fv);
  if ((n2blue != 1) && ((nfft & 1) == 0)) {
    d_FFTImplementationCallback_doH(x, y, x->size[0], nfft, n2blue, wwc, costab,
                                    sintab, costab, sintabinv);
  } else {
    double b_re_tmp;
    double c_re_tmp;
    double d_re_tmp;
    double re_tmp;
    nInt2m1 = x->size[0];
    if (nfft <= nInt2m1) {
      nInt2m1 = nfft;
    }
    nInt2m1--;
    for (k = 0; k <= nInt2m1; k++) {
      a = wwc_data[(nfft + k) - 1];
      y_data[k].re = a.re * x_data[k];
      y_data[k].im = a.im * -x_data[k];
    }
    i = nInt2m1 + 2;
    for (k = i; k <= nfft; k++) {
      y_data[k - 1].re = 0.0;
      y_data[k - 1].im = 0.0;
    }
    e_FFTImplementationCallback_r2b(y, n2blue, costab, sintab, fv);
    fv_data = fv->data;
    f_FFTImplementationCallback_r2b(wwc, n2blue, costab, sintab, b_fv);
    i = b_fv->size[0];
    b_fv->size[0] = fv->size[0];
    emxEnsureCapacity_creal_T(b_fv, i);
    b_fv_data = b_fv->data;
    nInt2m1 = fv->size[0];
    for (i = 0; i < nInt2m1; i++) {
      re_tmp = fv_data[i].re;
      b_re_tmp = b_fv_data[i].im;
      c_re_tmp = fv_data[i].im;
      d_re_tmp = b_fv_data[i].re;
      b_fv_data[i].re = re_tmp * d_re_tmp - c_re_tmp * b_re_tmp;
      b_fv_data[i].im = re_tmp * b_re_tmp + c_re_tmp * d_re_tmp;
    }
    g_FFTImplementationCallback_r2b(b_fv, n2blue, costab, sintabinv, fv);
    fv_data = fv->data;
    i = wwc->size[0];
    for (k = nfft; k <= i; k++) {
      re_tmp = wwc_data[k - 1].re;
      b_re_tmp = fv_data[k - 1].im;
      c_re_tmp = wwc_data[k - 1].im;
      d_re_tmp = fv_data[k - 1].re;
      nInt2m1 = k - nfft;
      y_data[nInt2m1].re = re_tmp * d_re_tmp + c_re_tmp * b_re_tmp;
      y_data[nInt2m1].im = re_tmp * b_re_tmp - c_re_tmp * d_re_tmp;
    }
  }
  emxFree_creal_T(&b_fv);
  emxFree_creal_T(&fv);
  emxFree_creal_T(&wwc);
}

/*
 * Arguments    : int nRows
 *                boolean_T useRadix2
 *                emxArray_real_T *costab
 *                emxArray_real_T *sintab
 *                emxArray_real_T *sintabinv
 * Return Type  : void
 */
void c_FFTImplementationCallback_gen(int nRows, boolean_T useRadix2,
                                     emxArray_real_T *costab,
                                     emxArray_real_T *sintab,
                                     emxArray_real_T *sintabinv)
{
  emxArray_real_T *costab1q;
  double e;
  double *costab1q_data;
  double *costab_data;
  double *sintab_data;
  double *sintabinv_data;
  int i;
  int k;
  int n;
  int nd2;
  e = 6.2831853071795862 / (double)nRows;
  n = (int)((unsigned int)nRows >> 1) >> 1;
  emxInit_real_T(&costab1q, 2);
  i = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = n + 1;
  emxEnsureCapacity_real_T(costab1q, i);
  costab1q_data = costab1q->data;
  costab1q_data[0] = 1.0;
  nd2 = n / 2 - 1;
  for (k = 0; k <= nd2; k++) {
    costab1q_data[k + 1] = e * ((double)k + 1.0);
    e_cos(&costab1q_data[k + 1]);
  }
  i = nd2 + 2;
  nd2 = n - 1;
  for (k = i; k <= nd2; k++) {
    costab1q_data[k] = e * (double)(n - k);
    d_sin(&costab1q_data[k]);
  }
  costab1q_data[n] = 0.0;
  if (!useRadix2) {
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i);
    costab_data = costab->data;
    i = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i);
    sintab_data = sintab->data;
    costab_data[0] = 1.0;
    sintab_data[0] = 0.0;
    i = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintabinv, i);
    sintabinv_data = sintabinv->data;
    for (k = 0; k < n; k++) {
      sintabinv_data[k + 1] = costab1q_data[(n - k) - 1];
    }
    i = costab1q->size[1];
    for (k = i; k <= nd2; k++) {
      sintabinv_data[k] = costab1q_data[k - n];
    }
    for (k = 0; k < n; k++) {
      costab_data[k + 1] = costab1q_data[k + 1];
      sintab_data[k + 1] = -costab1q_data[(n - k) - 1];
    }
    i = costab1q->size[1];
    for (k = i; k <= nd2; k++) {
      costab_data[k] = -costab1q_data[nd2 - k];
      sintab_data[k] = -costab1q_data[k - n];
    }
  } else {
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i);
    costab_data = costab->data;
    i = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i);
    sintab_data = sintab->data;
    costab_data[0] = 1.0;
    sintab_data[0] = 0.0;
    for (k = 0; k < n; k++) {
      costab_data[k + 1] = costab1q_data[k + 1];
      sintab_data[k + 1] = -costab1q_data[(n - k) - 1];
    }
    i = costab1q->size[1];
    for (k = i; k <= nd2; k++) {
      costab_data[k] = -costab1q_data[nd2 - k];
      sintab_data[k] = -costab1q_data[k - n];
    }
    sintabinv->size[0] = 1;
    sintabinv->size[1] = 0;
  }
  emxFree_real_T(&costab1q);
}

/*
 * Arguments    : int nfft
 * Return Type  : boolean_T
 */
boolean_T c_FFTImplementationCallback_get(int nfft)
{
  return sizeIsPow2(nfft);
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int n1_unsigned
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_creal_T *y
 * Return Type  : void
 */
void c_FFTImplementationCallback_r2b(const emxArray_real_T *x, int n1_unsigned,
                                     const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab,
                                     emxArray_creal_T *y)
{
  d_FFTImplementationCallback_r2b(x, n1_unsigned, costab, sintab, y);
}

/*
 * Arguments    : int nfft
 *                boolean_T useRadix2
 *                int *nRows
 * Return Type  : int
 */
int d_FFTImplementationCallback_get(int nfft, boolean_T useRadix2, int *nRows)
{
  int n2blue;
  n2blue = 1;
  if (useRadix2) {
    *nRows = nfft;
  } else {
    if (nfft > 0) {
      n2blue = 1 << nextpow2((nfft + nfft) - 1);
    }
    *nRows = n2blue;
  }
  return n2blue;
}

/*
 * File trailer for FFTImplementationCallback.c
 *
 * [EOF]
 */
