/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: colon.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "colon.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "abs.h"
#include "floor.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static int float_colon_length(float a, float b, float *anew, float *bnew,
                              boolean_T *n_too_large);

static double maxabs(double a, double b);

/* Function Definitions */
/*
 * Arguments    : float a
 *                float b
 *                float *anew
 *                float *bnew
 *                boolean_T *n_too_large
 * Return Type  : int
 */
static int float_colon_length(float a, float b, float *anew, float *bnew,
                              boolean_T *n_too_large)
{
  double apnd;
  double cdiff;
  double ndbl;
  int n;
  *anew = a;
  ndbl = c_floor(((double)b - a) + 0.5);
  apnd = a + ndbl;
  cdiff = apnd - b;
  if (b_abs(cdiff) < 2.384185791015625E-7 * maxabs(a, b)) {
    ndbl++;
    *bnew = b;
  } else if (cdiff > 0.0) {
    *bnew = (float)(a + (ndbl - 1.0));
  } else {
    ndbl++;
    *bnew = (float)apnd;
  }
  *n_too_large = (ndbl > 2.147483647E+9);
  if (ndbl >= 0.0) {
    n = (int)floor(ndbl);
  } else {
    n = 0;
  }
  return n;
}

/*
 * Arguments    : double a
 *                double b
 * Return Type  : double
 */
static double maxabs(double a, double b)
{
  return fmax(b_abs(a), b_abs(b));
}

/*
 * Arguments    : float a
 *                float b
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void eml_float_colon(float a, float b, emxArray_real32_T *y)
{
  float a1;
  float b1;
  float *y_data;
  int k;
  int n;
  int nm1d2;
  boolean_T n_too_large;
  n = float_colon_length(a, b, &a1, &b1, &n_too_large);
  nm1d2 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_real32_T(y, nm1d2);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = a1;
    if (n > 1) {
      y_data[n - 1] = b1;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        y_data[k + 1] = a1 + (float)(k + 1);
        y_data[(n - k) - 2] = b1 - (float)(k + 1);
      }
      if (nm1d2 << 1 == n - 1) {
        y_data[nm1d2] = (a1 + b1) / 2.0F;
      } else {
        y_data[nm1d2] = a1 + (float)nm1d2;
        y_data[nm1d2 + 1] = b1 - (float)nm1d2;
      }
    }
  }
}

/*
 * File trailer for colon.c
 *
 * [EOF]
 */
