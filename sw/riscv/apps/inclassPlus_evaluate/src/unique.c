/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unique.c
 *
 * Code generation for function 'unique'
 *
 */

/* Include files */
#include "unique.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void count_nonfinites(const emxArray_real_T *b, int nb, int *nMInf, int
  *nFinite, int *nPInf, int *nNaN);

/* Function Definitions */
static void count_nonfinites(const emxArray_real_T *b, int nb, int *nMInf, int
  *nFinite, int *nPInf, int *nNaN)
{
  double d;
  int k;
  boolean_T exitg1;
  k = 0;
  while ((k + 1 <= nb) && rtIsInf(b->data[k]) && (b->data[k] < 0.0)) {
    k++;
  }

  *nMInf = k;
  k = nb;
  while ((k >= 1) && rtIsNaN(b->data[k - 1])) {
    k--;
  }

  *nNaN = nb - k;
  exitg1 = false;
  while ((!exitg1) && (k >= 1)) {
    d = b->data[k - 1];
    if (rtIsInf(d) && (d > 0.0)) {
      k--;
    } else {
      exitg1 = true;
    }
  }

  *nPInf = (nb - k) - *nNaN;
  *nFinite = k - *nMInf;
}

void b_unique_vector(const emxArray_real_T *a, emxArray_real_T *b)
{
  emxArray_int32_T *idx;
  double absx;
  double x;
  int exitg1;
  int exponent;
  int k;
  int nMInf;
  int nNaN;
  int na;
  int nb;
  emxInit_int32_T(&idx, 1);
  na = a->size[0];
  b_sortIdx(a, idx);
  k = b->size[0];
  b->size[0] = a->size[0];
  emxEnsureCapacity_real_T(b, k);
  for (k = 0; k < na; k++) {
    b->data[k] = a->data[idx->data[k] - 1];
  }

  emxFree_int32_T(&idx);
  count_nonfinites(b, a->size[0], &nMInf, &na, &k, &nNaN);
  nb = -1;
  if (nMInf > 0) {
    nb = 0;
  }

  na += nMInf;
  while (nMInf + 1 <= na) {
    x = b->data[nMInf];
    do {
      exitg1 = 0;
      nMInf++;
      if (nMInf + 1 > na) {
        exitg1 = 1;
      } else {
        absx = fabs(x / 2.0);
        if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &exponent);
            absx = ldexp(1.0, exponent - 53);
          }
        } else {
          absx = rtNaN;
        }

        if ((!(fabs(x - b->data[nMInf]) < absx)) && ((!rtIsInf(b->data[nMInf])) ||
             (!rtIsInf(x)) || ((b->data[nMInf] > 0.0) != (x > 0.0)))) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    nb++;
    b->data[nb] = x;
  }

  if (k > 0) {
    nb++;
    b->data[nb] = b->data[na];
  }

  nMInf = na + k;
  for (na = 0; na < nNaN; na++) {
    nb++;
    b->data[nb] = b->data[nMInf + na];
  }

  k = b->size[0];
  if (1 > nb + 1) {
    b->size[0] = 0;
  } else {
    b->size[0] = nb + 1;
  }

  emxEnsureCapacity_real_T(b, k);
}

void c_unique_vector(const emxArray_real_T *a, emxArray_real_T *b,
                     emxArray_int32_T *ndx)
{
  emxArray_int32_T *idx;
  emxArray_int32_T *r;
  double absx;
  double x;
  int exitg1;
  int exponent;
  int khi;
  int nInf;
  int nMInf;
  int nNaN;
  int na;
  int nb;
  emxInit_int32_T(&idx, 1);
  emxInit_int32_T(&r, 1);
  na = a->size[0];
  b_sortIdx(a, r);
  nInf = idx->size[0];
  idx->size[0] = r->size[0];
  emxEnsureCapacity_int32_T(idx, nInf);
  khi = r->size[0];
  for (nInf = 0; nInf < khi; nInf++) {
    idx->data[nInf] = r->data[nInf];
  }

  emxFree_int32_T(&r);
  nInf = b->size[0];
  b->size[0] = a->size[0];
  emxEnsureCapacity_real_T(b, nInf);
  for (khi = 0; khi < na; khi++) {
    b->data[khi] = a->data[idx->data[khi] - 1];
  }

  count_nonfinites(b, a->size[0], &nMInf, &khi, &nInf, &nNaN);
  nb = -1;
  if (nMInf > 0) {
    nb = 0;
  }

  khi += nMInf;
  while (nMInf + 1 <= khi) {
    x = b->data[nMInf];
    na = nMInf;
    do {
      exitg1 = 0;
      nMInf++;
      if (nMInf + 1 > khi) {
        exitg1 = 1;
      } else {
        absx = fabs(x / 2.0);
        if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &exponent);
            absx = ldexp(1.0, exponent - 53);
          }
        } else {
          absx = rtNaN;
        }

        if ((!(fabs(x - b->data[nMInf]) < absx)) && ((!rtIsInf(b->data[nMInf])) ||
             (!rtIsInf(x)) || ((b->data[nMInf] > 0.0) != (x > 0.0)))) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    nb++;
    b->data[nb] = x;
    idx->data[nb] = idx->data[na];
  }

  if (nInf > 0) {
    nb++;
    b->data[nb] = b->data[khi];
    idx->data[nb] = idx->data[khi];
  }

  nMInf = (khi + nInf) - 1;
  for (na = 0; na < nNaN; na++) {
    nb++;
    khi = (nMInf + na) + 1;
    b->data[nb] = b->data[khi];
    idx->data[nb] = idx->data[khi];
  }

  nInf = b->size[0];
  if (1 > nb + 1) {
    b->size[0] = 0;
  } else {
    b->size[0] = nb + 1;
  }

  emxEnsureCapacity_real_T(b, nInf);
  nInf = ndx->size[0];
  ndx->size[0] = nb + 1;
  emxEnsureCapacity_int32_T(ndx, nInf);
  for (khi = 0; khi <= nb; khi++) {
    ndx->data[khi] = idx->data[khi];
  }

  emxFree_int32_T(&idx);
}

void unique_vector(const emxArray_real_T *a, emxArray_real_T *b)
{
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  double absx;
  double x;
  int b_i;
  int exitg2;
  int exponent;
  int i;
  int i2;
  int j;
  int k;
  int kEnd;
  int n;
  int na;
  int p;
  int pEnd;
  int q;
  int qEnd;
  boolean_T exitg1;
  emxInit_int32_T(&idx, 2);
  na = a->size[1];
  n = a->size[1] + 1;
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = a->size[1];
  emxEnsureCapacity_int32_T(idx, i);
  b_i = a->size[1];
  for (i = 0; i < b_i; i++) {
    idx->data[i] = 0;
  }

  if (a->size[1] != 0) {
    emxInit_int32_T(&iwork, 1);
    i = iwork->size[0];
    iwork->size[0] = a->size[1];
    emxEnsureCapacity_int32_T(iwork, i);
    i = a->size[1] - 1;
    for (k = 1; k <= i; k += 2) {
      absx = a->data[k];
      if ((a->data[k - 1] <= absx) || rtIsNaN(absx)) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    if ((a->size[1] & 1) != 0) {
      idx->data[a->size[1] - 1] = a->size[1];
    }

    b_i = 2;
    while (b_i < n - 1) {
      i2 = b_i << 1;
      j = 1;
      for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
        p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          absx = a->data[idx->data[q] - 1];
          i = idx->data[p - 1];
          if ((a->data[i - 1] <= absx) || rtIsNaN(absx)) {
            iwork->data[k] = i;
            p++;
            if (p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                iwork->data[k] = idx->data[q];
                q++;
              }
            }
          } else {
            iwork->data[k] = idx->data[q];
            q++;
            if (q + 1 == qEnd) {
              while (p < pEnd) {
                k++;
                iwork->data[k] = idx->data[p - 1];
                p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k < kEnd; k++) {
          idx->data[(j + k) - 1] = iwork->data[k];
        }

        j = qEnd;
      }

      b_i = i2;
    }

    emxFree_int32_T(&iwork);
  }

  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = a->size[1];
  emxEnsureCapacity_real_T(b, i);
  for (k = 0; k < na; k++) {
    b->data[k] = a->data[idx->data[k] - 1];
  }

  emxFree_int32_T(&idx);
  k = 0;
  while ((k + 1 <= na) && rtIsInf(b->data[k]) && (b->data[k] < 0.0)) {
    k++;
  }

  i2 = k;
  k = a->size[1];
  while ((k >= 1) && rtIsNaN(b->data[k - 1])) {
    k--;
  }

  pEnd = a->size[1] - k;
  exitg1 = false;
  while ((!exitg1) && (k >= 1)) {
    absx = b->data[k - 1];
    if (rtIsInf(absx) && (absx > 0.0)) {
      k--;
    } else {
      exitg1 = true;
    }
  }

  b_i = (a->size[1] - k) - pEnd;
  p = -1;
  if (i2 > 0) {
    p = 0;
  }

  while (i2 + 1 <= k) {
    x = b->data[i2];
    do {
      exitg2 = 0;
      i2++;
      if (i2 + 1 > k) {
        exitg2 = 1;
      } else {
        absx = fabs(x / 2.0);
        if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &exponent);
            absx = ldexp(1.0, exponent - 53);
          }
        } else {
          absx = rtNaN;
        }

        if ((!(fabs(x - b->data[i2]) < absx)) && ((!rtIsInf(b->data[i2])) ||
             (!rtIsInf(x)) || ((b->data[i2] > 0.0) != (x > 0.0)))) {
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);

    p++;
    b->data[p] = x;
  }

  if (b_i > 0) {
    p++;
    b->data[p] = b->data[k];
  }

  i2 = k + b_i;
  for (j = 0; j < pEnd; j++) {
    p++;
    b->data[p] = b->data[i2 + j];
  }

  i = b->size[0] * b->size[1];
  if (1 > p + 1) {
    b->size[1] = 0;
  } else {
    b->size[1] = p + 1;
  }

  emxEnsureCapacity_real_T(b, i);
}

/* End of code generation (unique.c) */
