/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SortedBuffer.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "SortedBuffer.h"
#include "Yuxuan_iterative_test_single_internal_types.h"
#include "isinf.h"
#include "isnan.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static int SortedBuffer_locateElement(const float obj_buf[3], int obj_nbuf,
                                      float x);

/* Function Definitions */
/*
 * Arguments    : const float obj_buf[3]
 *                int obj_nbuf
 *                float x
 * Return Type  : int
 */
static int SortedBuffer_locateElement(const float obj_buf[3], int obj_nbuf,
                                      float x)
{
  int i;
  if ((obj_nbuf == 0) || (x < obj_buf[0])) {
    i = 0;
  } else if (x < obj_buf[obj_nbuf - 1]) {
    int ip1;
    int upper;
    i = 1;
    ip1 = 2;
    upper = obj_nbuf;
    while (upper > ip1) {
      int m;
      m = (i + upper) >> 1;
      if (x < obj_buf[m - 1]) {
        upper = m;
      } else {
        i = m;
        ip1 = m + 1;
      }
    }
  } else {
    i = obj_nbuf;
  }
  return i;
}

/*
 * Arguments    : float obj_buf[3]
 *                boolean_T *obj_includenans
 *                int *obj_nnans
 * Return Type  : int
 */
int SortedBuffer_SortedBuffer(float obj_buf[3], boolean_T *obj_includenans,
                              int *obj_nnans)
{
  int obj_nbuf;
  obj_buf[0] = 0.0F;
  obj_buf[1] = 0.0F;
  obj_buf[2] = 0.0F;
  obj_nbuf = 0;
  *obj_includenans = true;
  *obj_nnans = 0;
  return obj_nbuf;
}

/*
 * Arguments    : coder_internal_SortedBuffer *obj
 *                float x
 * Return Type  : void
 */
void SortedBuffer_insert(coder_internal_SortedBuffer *obj, float x)
{
  int k;
  if (obj->nbuf < 3) {
    if (c_isnan(x)) {
      obj->nnans++;
    } else if (obj->nbuf == 0) {
      obj->buf[0] = x;
      obj->nbuf = 1;
    } else {
      int i;
      i = SortedBuffer_locateElement(obj->buf, obj->nbuf, x);
      if (i == 0) {
        int b_i;
        b_i = obj->nbuf;
        for (k = b_i; k >= 1; k--) {
          obj->buf[k] = obj->buf[k - 1];
        }
        obj->buf[0] = x;
        obj->nbuf++;
      } else if (i >= obj->nbuf) {
        obj->nbuf++;
        obj->buf[obj->nbuf - 1] = x;
      } else {
        int b_i;
        int i1;
        b_i = obj->nbuf;
        i1 = i + 1;
        for (k = b_i; k >= i1; k--) {
          obj->buf[k] = obj->buf[k - 1];
        }
        obj->buf[i] = x;
        obj->nbuf++;
      }
    }
  }
}

/*
 * Arguments    : const float obj_buf[3]
 *                int obj_nbuf
 *                int obj_nnans
 * Return Type  : float
 */
float SortedBuffer_median(const float obj_buf[3], int obj_nbuf, int obj_nnans)
{
  float m;
  if (obj_nnans > 0) {
    m = rtNaNF;
  } else if (obj_nbuf == 0) {
    m = rtNaNF;
  } else {
    int mid;
    mid = obj_nbuf >> 1;
    if ((obj_nbuf & 1) == 1) {
      m = obj_buf[mid];
    } else {
      float f;
      f = obj_buf[mid - 1];
      if (((f < 0.0F) != (obj_buf[mid] < 0.0F)) || b_isinf(f)) {
        m = (f + obj_buf[mid]) / 2.0F;
      } else {
        m = f + (obj_buf[mid] - f) / 2.0F;
      }
    }
  }
  return m;
}

/*
 * Arguments    : coder_internal_SortedBuffer *obj
 *                float x
 * Return Type  : void
 */
void SortedBuffer_remove(coder_internal_SortedBuffer *obj, float x)
{
  int k;
  if (c_isnan(x)) {
    if (obj->nnans >= 1) {
      obj->nnans--;
    }
  } else if (obj->nbuf == 1) {
    if (x == obj->buf[0]) {
      obj->nbuf = 0;
    }
  } else {
    int i;
    i = SortedBuffer_locateElement(obj->buf, obj->nbuf, x);
    if ((i > 0) && (x == obj->buf[i - 1])) {
      int b_i;
      i++;
      b_i = obj->nbuf;
      for (k = i; k <= b_i; k++) {
        obj->buf[k - 2] = obj->buf[k - 1];
      }
      obj->nbuf--;
    }
  }
}

/*
 * Arguments    : coder_internal_SortedBuffer *obj
 *                float xold
 *                float xnew
 * Return Type  : void
 */
void SortedBuffer_replace(coder_internal_SortedBuffer *obj, float xold,
                          float xnew)
{
  int k;
  if (c_isnan(xold)) {
    if (obj->nnans > 0) {
      obj->nnans--;
    }
    SortedBuffer_insert(obj, xnew);
  } else if (c_isnan(xnew)) {
    SortedBuffer_remove(obj, xold);
    obj->nnans++;
  } else {
    int iold;
    iold = SortedBuffer_locateElement(obj->buf, obj->nbuf, xold);
    if ((iold > 0) && (obj->buf[iold - 1] == xold)) {
      int inew;
      inew = SortedBuffer_locateElement(obj->buf, obj->nbuf, xnew);
      if (iold <= inew) {
        int i;
        i = inew - 1;
        for (k = iold; k <= i; k++) {
          obj->buf[k - 1] = obj->buf[k];
        }
        obj->buf[inew - 1] = xnew;
      } else if (iold == inew + 1) {
        obj->buf[iold - 1] = xnew;
      } else {
        int i;
        i = inew + 2;
        for (k = iold; k >= i; k--) {
          obj->buf[k - 1] = obj->buf[k - 2];
        }
        obj->buf[inew] = xnew;
      }
    } else {
      SortedBuffer_insert(obj, xnew);
    }
  }
}

/*
 * File trailer for SortedBuffer.c
 *
 * [EOF]
 */
