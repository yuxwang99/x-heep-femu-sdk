/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void fft(const emxArray_real_T *x, emxArray_creal_T *y)
{
  emxArray_real_T *costab;
  emxArray_real_T *costab1q;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  double temp_im;
  double temp_re;
  double twid_im;
  double twid_re;
  int i;
  int ihi;
  int ix;
  int ju;
  int k;
  int nRowsD2;
  int pmax;
  int pmin;
  int pow2p;
  int temp_re_tmp;
  boolean_T exitg1;
  boolean_T useRadix2;
  if (x->size[0] == 0) {
    pow2p = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_creal_T(y, pow2p);
    pmax = x->size[0];
    for (pow2p = 0; pow2p < pmax; pow2p++) {
      y->data[pow2p].re = 0.0;
      y->data[pow2p].im = 0.0;
    }
  } else {
    useRadix2 = ((x->size[0] & (x->size[0] - 1)) == 0);
    pmin = 1;
    if (useRadix2) {
      pmax = x->size[0];
    } else {
      ihi = (x->size[0] + x->size[0]) - 1;
      pmax = 31;
      if (ihi <= 1) {
        pmax = 0;
      } else {
        pmin = 0;
        exitg1 = false;
        while ((!exitg1) && (pmax - pmin > 1)) {
          k = (pmin + pmax) >> 1;
          pow2p = 1 << k;
          if (pow2p == ihi) {
            pmax = k;
            exitg1 = true;
          } else if (pow2p > ihi) {
            pmax = k;
          } else {
            pmin = k;
          }
        }
      }

      pmin = 1 << pmax;
      pmax = pmin;
    }

    emxInit_real_T(&costab1q, 2);
    twid_re = 6.2831853071795862 / (double)pmax;
    ihi = pmax / 2 / 2;
    pow2p = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = ihi + 1;
    emxEnsureCapacity_real_T(costab1q, pow2p);
    costab1q->data[0] = 1.0;
    pmax = ihi / 2 - 1;
    for (k = 0; k <= pmax; k++) {
      costab1q->data[k + 1] = cos(twid_re * ((double)k + 1.0));
    }

    pow2p = pmax + 2;
    pmax = ihi - 1;
    for (k = pow2p; k <= pmax; k++) {
      costab1q->data[k] = sin(twid_re * (double)(ihi - k));
    }

    costab1q->data[ihi] = 0.0;
    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    emxInit_real_T(&sintabinv, 2);
    if (!useRadix2) {
      ihi = costab1q->size[1] - 1;
      pmax = (costab1q->size[1] - 1) << 1;
      pow2p = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(costab, pow2p);
      pow2p = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintab, pow2p);
      costab->data[0] = 1.0;
      sintab->data[0] = 0.0;
      pow2p = sintabinv->size[0] * sintabinv->size[1];
      sintabinv->size[0] = 1;
      sintabinv->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintabinv, pow2p);
      for (k = 0; k < ihi; k++) {
        sintabinv->data[k + 1] = costab1q->data[(ihi - k) - 1];
      }

      pow2p = costab1q->size[1];
      for (k = pow2p; k <= pmax; k++) {
        sintabinv->data[k] = costab1q->data[k - ihi];
      }

      for (k = 0; k < ihi; k++) {
        costab->data[k + 1] = costab1q->data[k + 1];
        sintab->data[k + 1] = -costab1q->data[(ihi - k) - 1];
      }

      pow2p = costab1q->size[1];
      for (k = pow2p; k <= pmax; k++) {
        costab->data[k] = -costab1q->data[pmax - k];
        sintab->data[k] = -costab1q->data[k - ihi];
      }
    } else {
      ihi = costab1q->size[1] - 1;
      pmax = (costab1q->size[1] - 1) << 1;
      pow2p = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(costab, pow2p);
      pow2p = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintab, pow2p);
      costab->data[0] = 1.0;
      sintab->data[0] = 0.0;
      for (k = 0; k < ihi; k++) {
        costab->data[k + 1] = costab1q->data[k + 1];
        sintab->data[k + 1] = -costab1q->data[(ihi - k) - 1];
      }

      pow2p = costab1q->size[1];
      for (k = pow2p; k <= pmax; k++) {
        costab->data[k] = -costab1q->data[pmax - k];
        sintab->data[k] = -costab1q->data[k - ihi];
      }

      sintabinv->size[0] = 1;
      sintabinv->size[1] = 0;
    }

    emxFree_real_T(&costab1q);
    if (useRadix2) {
      pow2p = y->size[0];
      y->size[0] = x->size[0];
      emxEnsureCapacity_creal_T(y, pow2p);
      if (x->size[0] != 1) {
        c_FFTImplementationCallback_doH(x, y, x->size[0], costab, sintab);
      } else {
        pmin = x->size[0];
        pow2p = x->size[0] - 2;
        nRowsD2 = x->size[0] / 2;
        k = nRowsD2 / 2;
        ix = 0;
        pmax = 0;
        ju = 0;
        for (i = 0; i <= pmin - 2; i++) {
          y->data[pmax].re = x->data[ix];
          y->data[pmax].im = 0.0;
          ihi = x->size[0];
          useRadix2 = true;
          while (useRadix2) {
            ihi >>= 1;
            ju ^= ihi;
            useRadix2 = ((ju & ihi) == 0);
          }

          pmax = ju;
          ix++;
        }

        y->data[pmax].re = x->data[ix];
        y->data[pmax].im = 0.0;
        if (x->size[0] > 1) {
          for (i = 0; i <= pow2p; i += 2) {
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

        pmax = 2;
        pmin = 4;
        pow2p = ((k - 1) << 2) + 1;
        while (k > 0) {
          for (i = 0; i < pow2p; i += pmin) {
            temp_re_tmp = i + pmax;
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
            ihi = ix + pow2p;
            while (i < ihi) {
              temp_re_tmp = i + pmax;
              temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
                data[temp_re_tmp].im;
              temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
                data[temp_re_tmp].re;
              y->data[temp_re_tmp].re = y->data[i].re - temp_re;
              y->data[temp_re_tmp].im = y->data[i].im - temp_im;
              y->data[i].re += temp_re;
              y->data[i].im += temp_im;
              i += pmin;
            }

            ix++;
          }

          k /= 2;
          pmax = pmin;
          pmin += pmin;
          pow2p -= pmax;
        }
      }
    } else {
      c_FFTImplementationCallback_dob(x, pmin, x->size[0], costab, sintab,
        sintabinv, y);
    }

    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }
}

/* End of code generation (fft.c) */
