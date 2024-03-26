/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: blockedSummation.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "blockedSummation.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static float b_colMajorFlatIter(const emxArray_real32_T *x, int vlen);

static float c_colMajorFlatIter(const float x[513]);

static double colMajorFlatIter(const signed char x[17]);

static float d_colMajorFlatIter(const float x[8]);

static float e_colMajorFlatIter(const float x_data[], int vlen);

static float f_colMajorFlatIter(const emxArray_real32_T *x, int vlen,
                                int vstart);

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 *                int vlen
 * Return Type  : float
 */
static float b_colMajorFlatIter(const emxArray_real32_T *x, int vlen)
{
  const float *x_data;
  float y;
  int firstBlockLength;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  x_data = x->data;
  if (vlen <= 1024) {
    firstBlockLength = vlen;
    lastBlockLength = 0;
    nblocks = 1;
  } else {
    firstBlockLength = 1024;
    nblocks = vlen / 1024;
    lastBlockLength = vlen - (nblocks << 10);
    if (lastBlockLength > 0) {
      nblocks++;
    } else {
      lastBlockLength = 1024;
    }
  }
  y = x_data[0];
  for (k = 2; k <= firstBlockLength; k++) {
    y += x_data[k - 1];
  }
  for (ib = 2; ib <= nblocks; ib++) {
    float bsum;
    int hi;
    firstBlockLength = (ib - 1) << 10;
    bsum = x_data[firstBlockLength];
    if (ib == nblocks) {
      hi = lastBlockLength;
    } else {
      hi = 1024;
    }
    for (k = 2; k <= hi; k++) {
      bsum += x_data[(firstBlockLength + k) - 1];
    }
    y += bsum;
  }
  return y;
}

/*
 * Arguments    : const float x[513]
 * Return Type  : float
 */
static float c_colMajorFlatIter(const float x[513])
{
  float y;
  int k;
  y = x[0];
  for (k = 0; k < 512; k++) {
    y += x[k + 1];
  }
  return y;
}

/*
 * Arguments    : const signed char x[17]
 * Return Type  : double
 */
static double colMajorFlatIter(const signed char x[17])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 16; k++) {
    y += (double)x[k + 1];
  }
  return y;
}

/*
 * Arguments    : const float x[8]
 * Return Type  : float
 */
static float d_colMajorFlatIter(const float x[8])
{
  float y;
  int k;
  y = x[0];
  for (k = 0; k < 7; k++) {
    y += x[k + 1];
  }
  return y;
}

/*
 * Arguments    : const float x_data[]
 *                int vlen
 * Return Type  : float
 */
static float e_colMajorFlatIter(const float x_data[], int vlen)
{
  float y;
  int k;
  y = x_data[0];
  for (k = 2; k <= vlen; k++) {
    y += x_data[k - 1];
  }
  return y;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                int vlen
 *                int vstart
 * Return Type  : float
 */
static float f_colMajorFlatIter(const emxArray_real32_T *x, int vlen,
                                int vstart)
{
  const float *x_data;
  float y;
  int firstBlockLength;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  x_data = x->data;
  if (vlen <= 1024) {
    firstBlockLength = vlen;
    lastBlockLength = 0;
    nblocks = 1;
  } else {
    firstBlockLength = 1024;
    nblocks = vlen / 1024;
    lastBlockLength = vlen - (nblocks << 10);
    if (lastBlockLength > 0) {
      nblocks++;
    } else {
      lastBlockLength = 1024;
    }
  }
  y = x_data[vstart - 1];
  for (k = 2; k <= firstBlockLength; k++) {
    y += x_data[(vstart + k) - 2];
  }
  for (ib = 2; ib <= nblocks; ib++) {
    float bsum;
    int hi;
    firstBlockLength = (vstart + ((ib - 1) << 10)) - 1;
    bsum = x_data[firstBlockLength];
    if (ib == nblocks) {
      hi = lastBlockLength;
    } else {
      hi = 1024;
    }
    for (k = 2; k <= hi; k++) {
      bsum += x_data[(firstBlockLength + k) - 1];
    }
    y += bsum;
  }
  return y;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                int vlen
 * Return Type  : float
 */
float b_blockedSummation(const emxArray_real32_T *x, int vlen)
{
  float y;
  if ((x->size[0] == 0) || (vlen == 0)) {
    y = 0.0F;
  } else {
    y = b_colMajorFlatIter(x, vlen);
  }
  return y;
}

/*
 * Arguments    : const signed char x[17]
 * Return Type  : double
 */
double blockedSummation(const signed char x[17])
{
  return colMajorFlatIter(x);
}

/*
 * Arguments    : const float x[513]
 * Return Type  : float
 */
float c_blockedSummation(const float x[513])
{
  return c_colMajorFlatIter(x);
}

/*
 * Arguments    : const float x[8]
 * Return Type  : float
 */
float d_blockedSummation(const float x[8])
{
  return d_colMajorFlatIter(x);
}

/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 *                int vlen
 * Return Type  : float
 */
float e_blockedSummation(const float x_data[], const int x_size[2], int vlen)
{
  float y;
  if ((x_size[1] == 0) || (vlen == 0)) {
    y = 0.0F;
  } else {
    y = e_colMajorFlatIter(x_data, vlen);
  }
  return y;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                int vlen
 *                int vstart
 * Return Type  : float
 */
float f_blockedSummation(const emxArray_real32_T *x, int vlen, int vstart)
{
  float y;
  if ((x->size[0] == 0) || (vlen == 0)) {
    y = 0.0F;
  } else {
    y = f_colMajorFlatIter(x, vlen, vstart);
  }
  return y;
}

/*
 * File trailer for blockedSummation.c
 *
 * [EOF]
 */
