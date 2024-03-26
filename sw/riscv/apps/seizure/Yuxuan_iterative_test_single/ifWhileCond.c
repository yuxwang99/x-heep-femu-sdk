/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ifWhileCond.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "ifWhileCond.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static boolean_T b_checkNoNaNs(const boolean_T x_data[], const int x_size[2]);

static boolean_T checkNoNaNs(const boolean_T x[2]);

/* Function Definitions */
/*
 * Arguments    : const boolean_T x_data[]
 *                const int x_size[2]
 * Return Type  : boolean_T
 */
static boolean_T b_checkNoNaNs(const boolean_T x_data[], const int x_size[2])
{
  int k;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= x_size[1] - 1)) {
    if (!x_data[0]) {
      y = false;
      exitg1 = true;
    } else {
      k = 1;
    }
  }
  return y;
}

/*
 * Arguments    : const boolean_T x[2]
 * Return Type  : boolean_T
 */
static boolean_T checkNoNaNs(const boolean_T x[2])
{
  int k;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  return y;
}

/*
 * Arguments    : const boolean_T x[2]
 * Return Type  : boolean_T
 */
boolean_T b_ifWhileCond(const boolean_T x[2])
{
  return checkNoNaNs(x);
}

/*
 * Arguments    : const boolean_T x_data[]
 *                const int x_size[2]
 * Return Type  : boolean_T
 */
boolean_T ifWhileCond(const boolean_T x_data[], const int x_size[2])
{
  boolean_T y;
  y = (x_size[1] != 0);
  if (y) {
    y = b_checkNoNaNs(x_data, x_size);
  }
  return y;
}

/*
 * File trailer for ifWhileCond.c
 *
 * [EOF]
 */
