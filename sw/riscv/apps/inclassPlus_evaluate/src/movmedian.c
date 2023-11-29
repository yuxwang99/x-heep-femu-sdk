/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * movmedian.c
 *
 * Code generation for function 'movmedian'
 *
 */

/* Include files */
#include "movmedian.h"
#include "SortedBuffer.h"
#include "profile_Yuxuan_iteration_internal_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void movmedian(const double x[400], double y[400])
{
  coder_internal_SortedBuffer s;
  double d;
  double d1;
  int b_k;
  int i;
  int inew;
  int iold;
  int k;
  s.buf[0] = 0.0;
  s.buf[1] = 0.0;
  s.buf[2] = 0.0;
  s.nbuf = 0;
  s.includenans = true;
  s.nnans = 0;
  SortedBuffer_insert(&s, x[0]);
  SortedBuffer_insert(&s, x[1]);
  y[0] = SortedBuffer_median(s.buf, s.nbuf, s.nnans);
  SortedBuffer_insert(&s, x[2]);
  y[1] = SortedBuffer_median(s.buf, s.nbuf, s.nnans);
  for (k = 0; k < 397; k++) {
    d = x[k];
    if (rtIsNaN(d)) {
      if (s.nnans > 0) {
        s.nnans--;
      }

      SortedBuffer_insert(&s, x[k + 3]);
    } else {
      d1 = x[k + 3];
      if (rtIsNaN(d1)) {
        SortedBuffer_remove(&s, d);
        s.nnans++;
      } else {
        iold = SortedBuffer_locateElement(s.buf, s.nbuf, d);
        if ((iold > 0) && (s.buf[iold - 1] == d)) {
          inew = SortedBuffer_locateElement(s.buf, s.nbuf, d1);
          if (iold <= inew) {
            i = inew - 1;
            for (b_k = iold; b_k <= i; b_k++) {
              s.buf[b_k - 1] = s.buf[b_k];
            }

            s.buf[inew - 1] = d1;
          } else if (iold == inew + 1) {
            s.buf[iold - 1] = d1;
          } else {
            i = inew + 2;
            for (b_k = iold; b_k >= i; b_k--) {
              s.buf[b_k - 1] = s.buf[b_k - 2];
            }

            s.buf[inew] = d1;
          }
        } else {
          SortedBuffer_insert(&s, d1);
        }
      }
    }

    y[k + 2] = SortedBuffer_median(s.buf, s.nbuf, s.nnans);
  }

  SortedBuffer_remove(&s, x[397]);
  y[399] = SortedBuffer_median(s.buf, s.nbuf, s.nnans);
}

/* End of code generation (movmedian.c) */
