/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: minOrMax.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "minOrMax.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "isnan.h"
#include "relop.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const float x[513]
 * Return Type  : float
 */
float b_maximum(const float x[513])
{
  float ex;
  int idx;
  int k;
  if (!c_isnan(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 513)) {
      if (!c_isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    idx++;
    for (k = idx; k < 514; k++) {
      float f;
      f = x[k - 1];
      if (ex < f) {
        ex = f;
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const float x_data[]
 *                const int x_size[2]
 * Return Type  : float
 */
float b_minimum(const float x_data[], const int x_size[2])
{
  float ex;
  int k;
  int last;
  last = x_size[1];
  if (x_size[1] <= 2) {
    if (x_size[1] == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[x_size[1] - 1];
      if ((!(x_data[0] > ex)) && ((!c_isnan(x_data[0])) || c_isnan(ex))) {
        ex = x_data[0];
      }
    }
  } else {
    int idx;
    if (!c_isnan(x_data[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!c_isnan(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        float f;
        f = x_data[k - 1];
        if (ex > f) {
          ex = f;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                int *idx
 * Return Type  : float
 */
float c_maximum(const emxArray_real32_T *x, int *idx)
{
  const float *x_data;
  float ex;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x->size[0] - 1];
      if ((x_data[0] < ex) || (c_isnan(x_data[0]) && (!c_isnan(ex)))) {
        *idx = x->size[0];
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    if (!c_isnan(x_data[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!c_isnan(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      ex = x_data[0];
      *idx = 1;
    } else {
      int i;
      ex = x_data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        float f;
        f = x_data[k - 1];
        if (ex < f) {
          ex = f;
          *idx = k;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const float x[2]
 * Return Type  : float
 */
float c_minimum(const float x[2])
{
  float ex;
  if ((x[0] > x[1]) || (c_isnan(x[0]) && (!c_isnan(x[1])))) {
    ex = x[1];
  } else {
    ex = x[0];
  }
  return ex;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                float ex_data[]
 *                int ex_size[2]
 * Return Type  : void
 */
void d_maximum(const emxArray_real32_T *x, float ex_data[], int ex_size[2])
{
  const float *x_data;
  int i;
  int m;
  x_data = x->data;
  m = x->size[0];
  ex_size[0] = 1;
  ex_size[1] = x->size[1];
  if (x->size[1] >= 1) {
    ex_data[0] = x_data[0];
    for (i = 2; i <= m; i++) {
      float f;
      f = x_data[i - 1];
      if (h_relop(ex_data[0], f)) {
        ex_data[0] = f;
      }
    }
  }
}

/*
 * Arguments    : const float x[2]
 *                int *idx
 * Return Type  : float
 */
float d_minimum(const float x[2], int *idx)
{
  float ex;
  if ((x[0] > x[1]) || (c_isnan(x[0]) && (!c_isnan(x[1])))) {
    ex = x[1];
    *idx = 2;
  } else {
    ex = x[0];
    *idx = 1;
  }
  return ex;
}

/*
 * Arguments    : const float x[2]
 * Return Type  : float
 */
float e_maximum(const float x[2])
{
  float ex;
  if ((x[0] < x[1]) || (c_isnan(x[0]) && (!c_isnan(x[1])))) {
    ex = x[1];
  } else {
    ex = x[0];
  }
  return ex;
}

/*
 * Arguments    : const float x[2]
 *                int *idx
 * Return Type  : float
 */
float f_maximum(const float x[2], int *idx)
{
  float ex;
  if ((x[0] < x[1]) || (c_isnan(x[0]) && (!c_isnan(x[1])))) {
    ex = x[1];
    *idx = 2;
  } else {
    ex = x[0];
    *idx = 1;
  }
  return ex;
}

/*
 * Arguments    : const emxArray_real32_T *x
 * Return Type  : float
 */
float maximum(const emxArray_real32_T *x)
{
  const float *x_data;
  float ex;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[x->size[0] - 1];
      if ((!(x_data[0] < ex)) && ((!c_isnan(x_data[0])) || c_isnan(ex))) {
        ex = x_data[0];
      }
    }
  } else {
    int idx;
    if (!c_isnan(x_data[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!c_isnan(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        float f;
        f = x_data[k - 1];
        if (ex < f) {
          ex = f;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : float x
 *                float y
 * Return Type  : float
 */
float maximum2(float x, float y)
{
  return fmaxf(x, y);
}

/*
 * Arguments    : const emxArray_real32_T *x
 * Return Type  : float
 */
float minimum(const emxArray_real32_T *x)
{
  const float *x_data;
  float ex;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[x->size[0] - 1];
      if ((!(x_data[0] > ex)) && ((!c_isnan(x_data[0])) || c_isnan(ex))) {
        ex = x_data[0];
      }
    }
  } else {
    int idx;
    if (!c_isnan(x_data[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!c_isnan(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        float f;
        f = x_data[k - 1];
        if (ex > f) {
          ex = f;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : float x
 *                float y
 * Return Type  : float
 */
float minimum2(float x, float y)
{
  return fminf(x, y);
}

/*
 * File trailer for minOrMax.c
 *
 * [EOF]
 */
