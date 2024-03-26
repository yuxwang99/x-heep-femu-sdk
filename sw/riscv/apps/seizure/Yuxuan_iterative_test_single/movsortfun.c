/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: movsortfun.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "movsortfun.h"
#include "SortedBuffer.h"
#include "Yuxuan_iterative_test_single_internal_types.h"
#include "applyVectorFunctionNoCopy.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void b_vmovfun(const float x[400], float y[400]);

static void movsortfun_anonFcn1(const float x[400], const float y[400],
                                float varargout_1[400]);

/* Function Definitions */
/*
 * Arguments    : const float x[400]
 *                float y[400]
 * Return Type  : void
 */
static void b_vmovfun(const float x[400], float y[400])
{
  coder_internal_SortedBuffer s;
  int k;
  s.nbuf = SortedBuffer_SortedBuffer(s.buf, &s.includenans, &s.nnans);
  SortedBuffer_insert(&s, x[looper1D_anonFcn1(1) - 1]);
  SortedBuffer_insert(&s, x[looper1D_anonFcn1(2) - 1]);
  y[0] = SortedBuffer_median(s.buf, s.nbuf, s.nnans);
  SortedBuffer_insert(&s, x[2]);
  y[1] = SortedBuffer_median(s.buf, s.nbuf, s.nnans);
  for (k = 0; k < 397; k++) {
    SortedBuffer_replace(&s, x[looper1D_anonFcn1(k + 1) - 1],
                         x[looper1D_anonFcn1(k + 4) - 1]);
    y[looper1D_anonFcn1(k + 3) - 1] =
        SortedBuffer_median(s.buf, s.nbuf, s.nnans);
  }
  SortedBuffer_remove(&s, x[397]);
  y[399] = SortedBuffer_median(s.buf, s.nbuf, s.nnans);
}

/*
 * Arguments    : const float x[400]
 *                const float y[400]
 *                float varargout_1[400]
 * Return Type  : void
 */
static void movsortfun_anonFcn1(const float x[400], const float y[400],
                                float varargout_1[400])
{
  memcpy(&varargout_1[0], &y[0], 400U * sizeof(float));
  b_vmovfun(x, varargout_1);
}

/*
 * Arguments    : const float x[400]
 *                float y[400]
 * Return Type  : void
 */
void movsortfun(const float x[400], float y[400])
{
  float fv[400];
  memset(&fv[0], 0, 400U * sizeof(float));
  movsortfun_anonFcn1(x, fv, y);
}

/*
 * File trailer for movsortfun.c
 *
 * [EOF]
 */
