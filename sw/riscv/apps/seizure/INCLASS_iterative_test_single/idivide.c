/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: idivide.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "idivide.h"
#include "INCLASS_iterative_test_single_rtwutil.h"
#include "fix.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static int idivide_fix(int a, double b);

/* Function Definitions */
/*
 * Arguments    : int a
 *                double b
 * Return Type  : int
 */
static int idivide_fix(int a, double b)
{
  double d;
  int c;
  d = rt_roundd_snf(b_fix((double)a / b));
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      c = (int)d;
    } else {
      c = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    c = MAX_int32_T;
  } else {
    c = 0;
  }
  return c;
}

/*
 * Arguments    : int a
 *                double b
 * Return Type  : int
 */
int idivide(int a, double b)
{
  return idivide_fix(a, b);
}

/*
 * File trailer for idivide.c
 *
 * [EOF]
 */
