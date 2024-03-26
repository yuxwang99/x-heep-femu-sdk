/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rem1.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "rem1.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static int div_s32(int numerator, int denominator);

/* Function Definitions */
/*
 * Arguments    : int numerator
 *                int denominator
 * Return Type  : int
 */
static int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int tempAbsQuotient;
    unsigned int u;
    if (numerator < 0) {
      tempAbsQuotient = ~(unsigned int)numerator + 1U;
    } else {
      tempAbsQuotient = (unsigned int)numerator;
    }
    if (denominator < 0) {
      u = ~(unsigned int)denominator + 1U;
    } else {
      u = (unsigned int)denominator;
    }
    tempAbsQuotient /= u;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }
  return quotient;
}

/*
 * Arguments    : int x
 * Return Type  : int
 */
int c_rem(int x)
{
  return x - 146097 * div_s32(x, 146097);
}

/*
 * Arguments    : int x
 * Return Type  : int
 */
int e_rem(int x)
{
  return x - 36524 * div_s32(x, 36524);
}

/*
 * Arguments    : int x
 * Return Type  : int
 */
int g_rem(int x)
{
  return x - 1461 * div_s32(x, 1461);
}

/*
 * Arguments    : int x
 * Return Type  : int
 */
int i_rem(int x)
{
  return x - 365 * div_s32(x, 365);
}

/*
 * Arguments    : int x
 * Return Type  : int
 */
int k_rem(int x)
{
  return x - 3600 * div_s32(x, 3600);
}

/*
 * Arguments    : int x
 * Return Type  : int
 */
int m_rem(int x)
{
  return x - 60 * div_s32(x, 60);
}

/*
 * File trailer for rem1.c
 *
 * [EOF]
 */
