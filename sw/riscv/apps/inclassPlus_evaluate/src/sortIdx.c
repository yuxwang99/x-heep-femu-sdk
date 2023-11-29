/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include "sortIdx.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int np,
                  int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork);
static void merge_block(emxArray_int32_T *idx, emxArray_int32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_int32_T *xwork);

/* Function Definitions */
static void merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int np,
                  int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork)
{
  int exitg1;
  int iout;
  int j;
  int n_tmp;
  int p;
  int q;
  if (nq != 0) {
    n_tmp = np + nq;
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork->data[j] = idx->data[iout];
      xwork->data[j] = x->data[iout];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[q]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[q];
        x->data[iout] = xwork->data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx->data[iout] = iwork->data[j - 1];
            x->data[iout] = xwork->data[j - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge_block(emxArray_int32_T *idx, emxArray_int32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_int32_T *xwork)
{
  int bLen;
  int nPairs;
  int nTail;
  int tailOffset;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

void b_sortIdx(const emxArray_real_T *x, emxArray_int32_T *idx)
{
  emxArray_int32_T *iwork;
  double d;
  int b_i;
  int i;
  int i2;
  int j;
  int k;
  int kEnd;
  int n;
  int p;
  int pEnd;
  int q;
  int qEnd;
  n = x->size[0] + 1;
  i = idx->size[0];
  idx->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(idx, i);
  b_i = x->size[0];
  for (i = 0; i < b_i; i++) {
    idx->data[i] = 0;
  }

  if (x->size[0] != 0) {
    emxInit_int32_T(&iwork, 1);
    i = iwork->size[0];
    iwork->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(iwork, i);
    i = x->size[0] - 1;
    for (k = 1; k <= i; k += 2) {
      if ((x->data[k - 1] <= x->data[k]) || rtIsNaN(x->data[k])) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    if ((x->size[0] & 1) != 0) {
      idx->data[x->size[0] - 1] = x->size[0];
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
          d = x->data[idx->data[q] - 1];
          i = idx->data[p - 1];
          if ((x->data[i - 1] <= d) || rtIsNaN(d)) {
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
}

void c_sortIdx(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  static int b_iwork[256];
  static int b_xwork[256];
  emxArray_int32_T *iwork;
  emxArray_int32_T *xwork;
  int idx4[4];
  int x4[4];
  int b;
  int bLen;
  int b_b;
  int b_n;
  int exitg1;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int j;
  int k;
  int n;
  int nDone;
  int nPairs;
  int nQuartets;
  unsigned short unnamed_idx_0;
  signed char perm[4];
  unnamed_idx_0 = (unsigned short)x->size[0];
  bLen = idx->size[0];
  idx->size[0] = unnamed_idx_0;
  emxEnsureCapacity_int32_T(idx, bLen);
  i3 = unnamed_idx_0;
  for (bLen = 0; bLen < i3; bLen++) {
    idx->data[bLen] = 0;
  }

  if (x->size[0] != 0) {
    emxInit_int32_T(&iwork, 1);
    n = x->size[0];
    b_n = x->size[0] - 1;
    x4[0] = 0;
    idx4[0] = 0;
    x4[1] = 0;
    idx4[1] = 0;
    x4[2] = 0;
    idx4[2] = 0;
    x4[3] = 0;
    idx4[3] = 0;
    bLen = iwork->size[0];
    iwork->size[0] = unnamed_idx_0;
    emxEnsureCapacity_int32_T(iwork, bLen);
    i3 = unnamed_idx_0;
    for (bLen = 0; bLen < i3; bLen++) {
      iwork->data[bLen] = 0;
    }

    emxInit_int32_T(&xwork, 1);
    i3 = x->size[0];
    bLen = xwork->size[0];
    xwork->size[0] = i3;
    emxEnsureCapacity_int32_T(xwork, bLen);
    for (bLen = 0; bLen < i3; bLen++) {
      xwork->data[bLen] = 0;
    }

    nQuartets = x->size[0] >> 2;
    for (j = 0; j < nQuartets; j++) {
      i = j << 2;
      idx4[0] = i + 1;
      idx4[1] = i + 2;
      idx4[2] = i + 3;
      idx4[3] = i + 4;
      x4[0] = x->data[i];
      i3 = x->data[i + 1];
      x4[1] = i3;
      i4 = x->data[i + 2];
      x4[2] = i4;
      nDone = x->data[i + 3];
      x4[3] = nDone;
      if (x->data[i] <= i3) {
        i1 = 1;
        i2 = 2;
      } else {
        i1 = 2;
        i2 = 1;
      }

      if (i4 <= nDone) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      bLen = x4[i1 - 1];
      nDone = x4[i3 - 1];
      if (bLen <= nDone) {
        bLen = x4[i2 - 1];
        if (bLen <= nDone) {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i2;
          perm[2] = (signed char)i3;
          perm[3] = (signed char)i4;
        } else if (bLen <= x4[i4 - 1]) {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i2;
          perm[3] = (signed char)i4;
        } else {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i4;
          perm[3] = (signed char)i2;
        }
      } else {
        nDone = x4[i4 - 1];
        if (bLen <= nDone) {
          if (x4[i2 - 1] <= nDone) {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i1;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i1;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          perm[0] = (signed char)i3;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)i1;
          perm[3] = (signed char)i2;
        }
      }

      idx->data[i] = idx4[perm[0] - 1];
      idx->data[i + 1] = idx4[perm[1] - 1];
      idx->data[i + 2] = idx4[perm[2] - 1];
      idx->data[i + 3] = idx4[perm[3] - 1];
      x->data[i] = x4[perm[0] - 1];
      x->data[i + 1] = x4[perm[1] - 1];
      x->data[i + 2] = x4[perm[2] - 1];
      x->data[i + 3] = x4[perm[3] - 1];
    }

    nDone = nQuartets << 2;
    i4 = b_n - nDone;
    if (i4 + 1 > 0) {
      for (k = 0; k <= i4; k++) {
        i3 = nDone + k;
        idx4[k] = i3 + 1;
        x4[k] = x->data[i3];
      }

      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (i4 + 1 == 1) {
        perm[0] = 1;
      } else if (i4 + 1 == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }

      for (k = 0; k <= i4; k++) {
        i1 = perm[k] - 1;
        i3 = nDone + k;
        idx->data[i3] = idx4[i1];
        x->data[i3] = x4[i1];
      }
    }

    i3 = 2;
    if (n > 1) {
      if (n >= 256) {
        nQuartets = n >> 8;
        for (b = 0; b < nQuartets; b++) {
          i = (b << 8) - 1;
          for (b_b = 0; b_b < 6; b_b++) {
            bLen = 1 << (b_b + 2);
            b_n = bLen << 1;
            nPairs = 256 >> (b_b + 3);
            for (k = 0; k < nPairs; k++) {
              i4 = (i + k * b_n) + 1;
              for (j = 0; j < b_n; j++) {
                nDone = i4 + j;
                b_iwork[j] = idx->data[nDone];
                b_xwork[j] = x->data[nDone];
              }

              i2 = 0;
              i3 = bLen;
              nDone = i4 - 1;
              do {
                exitg1 = 0;
                nDone++;
                if (b_xwork[i2] <= b_xwork[i3]) {
                  idx->data[nDone] = b_iwork[i2];
                  x->data[nDone] = b_xwork[i2];
                  if (i2 + 1 < bLen) {
                    i2++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx->data[nDone] = b_iwork[i3];
                  x->data[nDone] = b_xwork[i3];
                  if (i3 + 1 < b_n) {
                    i3++;
                  } else {
                    nDone -= i2;
                    for (j = i2 + 1; j <= bLen; j++) {
                      i1 = nDone + j;
                      idx->data[i1] = b_iwork[j - 1];
                      x->data[i1] = b_xwork[j - 1];
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        i3 = nQuartets << 8;
        i4 = n - i3;
        if (i4 > 0) {
          merge_block(idx, x, i3, i4, 2, iwork, xwork);
        }

        i3 = 8;
      }

      merge_block(idx, x, 0, n, i3, iwork, xwork);
    }

    emxFree_int32_T(&xwork);
    emxFree_int32_T(&iwork);
  }
}

void sortIdx(const emxArray_real_T *x, emxArray_int32_T *idx)
{
  emxArray_int32_T *iwork;
  double d;
  int b_i;
  int i;
  int i2;
  int j;
  int k;
  int kEnd;
  int n;
  int p;
  int pEnd;
  int q;
  int qEnd;
  n = x->size[0] + 1;
  i = idx->size[0];
  idx->size[0] = (unsigned short)x->size[0];
  emxEnsureCapacity_int32_T(idx, i);
  b_i = (unsigned short)x->size[0];
  for (i = 0; i < b_i; i++) {
    idx->data[i] = 0;
  }

  emxInit_int32_T(&iwork, 1);
  i = iwork->size[0];
  iwork->size[0] = (unsigned short)x->size[0];
  emxEnsureCapacity_int32_T(iwork, i);
  i = x->size[0] - 1;
  for (k = 1; k <= i; k += 2) {
    d = x->data[k - 1];
    if ((d >= x->data[k]) || rtIsNaN(d)) {
      idx->data[k - 1] = k;
      idx->data[k] = k + 1;
    } else {
      idx->data[k - 1] = k + 1;
      idx->data[k] = k;
    }
  }

  if ((x->size[0] & 1) != 0) {
    idx->data[x->size[0] - 1] = x->size[0];
  }

  b_i = 2;
  while (b_i < n - 1) {
    i2 = b_i << 1;
    j = 1;
    for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
      p = j - 1;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n) {
        qEnd = n;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        d = x->data[idx->data[p] - 1];
        i = idx->data[q - 1];
        if ((d >= x->data[i - 1]) || rtIsNaN(d)) {
          iwork->data[k] = idx->data[p];
          p++;
          if (p + 1 == pEnd) {
            while (q < qEnd) {
              k++;
              iwork->data[k] = idx->data[q - 1];
              q++;
            }
          }
        } else {
          iwork->data[k] = i;
          q++;
          if (q == qEnd) {
            while (p + 1 < pEnd) {
              k++;
              iwork->data[k] = idx->data[p];
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

/* End of code generation (sortIdx.c) */
