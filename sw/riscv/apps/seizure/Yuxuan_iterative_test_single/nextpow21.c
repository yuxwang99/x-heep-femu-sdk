/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: nextpow21.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "nextpow21.h"
#include "abs1.h"
#include "isfinite.h"
#include "log2.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int n
 * Return Type  : int
 */
int b_nextpow2(int n)
{
  int p;
  int pmax;
  pmax = 31;
  if (n <= 1) {
    pmax = 0;
  } else {
    int pmin;
    boolean_T exitg1;
    pmin = 0;
    exitg1 = false;
    while ((!exitg1) && (pmax - pmin > 1)) {
      int pow2p;
      p = (pmin + pmax) >> 1;
      pow2p = 1 << p;
      if (pow2p == n) {
        pmax = p;
        exitg1 = true;
      } else if (pow2p > n) {
        pmax = p;
      } else {
        pmin = p;
      }
    }
  }
  return pmax;
}

/*
 * Arguments    : double n
 * Return Type  : double
 */
double d_nextpow2(double n)
{
  double b_p;
  double p;
  p = c_abs(n);
  if (c_isfinite(p)) {
    double f;
    f = b_log2(p, &b_p);
    p = b_p;
    if (f == 0.5) {
      p = b_p - 1.0;
    }
  }
  return p;
}

/*
 * Arguments    : float n
 * Return Type  : float
 */
float f_nextpow2(float n)
{
  float b_p;
  float p;
  p = f_abs(n);
  if (b_isfinite(p)) {
    float f;
    f = c_log2(p, &b_p);
    p = b_p;
    if (f == 0.5F) {
      p = b_p - 1.0F;
    }
  }
  return p;
}

/*
 * File trailer for nextpow21.c
 *
 * [EOF]
 */
