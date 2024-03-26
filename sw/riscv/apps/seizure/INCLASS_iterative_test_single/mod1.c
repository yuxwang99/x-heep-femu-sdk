/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mod1.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "mod1.h"
#include "isinf.h"
#include "isnan.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static float floatmod(float x, float y);

/* Function Definitions */
/*
 * Arguments    : float x
 *                float y
 * Return Type  : float
 */
static float floatmod(float x, float y)
{
  float r;
  r = x;
  if (y == 0.0F) {
    if (x == 0.0F) {
      r = 0.0F;
    }
  } else if (c_isnan(x) || c_isnan(y) || b_isinf(x)) {
    r = rtNaNF;
  } else if (x == 0.0F) {
    r = 0.0F;
  } else if (b_isinf(y)) {
    if (x < 0.0F) {
      r = y;
    }
  } else {
    r = fmodf(x, y);
    if (r == 0.0F) {
      r = y * 0.0F;
    } else if (x < 0.0F) {
      r += y;
    }
  }
  return r;
}

/*
 * Arguments    : float x
 *                float y
 * Return Type  : float
 */
float c_mod(float x, float y)
{
  return floatmod(x, y);
}

/*
 * File trailer for mod1.c
 *
 * [EOF]
 */
