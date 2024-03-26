/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: cospiAndSinpi.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "cospiAndSinpi.h"
#include "cos1.h"
#include "floor.h"
#include "rt_nonfinite.h"
#include "sin.h"

/* Function Definitions */
/*
 * Arguments    : float x
 * Return Type  : float
 */
float b_cospiAndSinpi(float x)
{
  float c;
  float r;
  if (x < 0.0F) {
    x = -x;
  }
  if (x < 0.25F) {
    c = x * 3.14159274F;
    c_cos(&c);
  } else {
    r = x - 2.0F * b_floor(x / 2.0F);
    if (r < 0.25F) {
      c = r * 3.14159274F;
      c_cos(&c);
    } else if (r < 0.75F) {
      c = (0.5F - r) * 3.14159274F;
      b_sin(&c);
    } else if (r < 1.25F) {
      r = (1.0F - r) * 3.14159274F;
      c_cos(&r);
      c = -r;
    } else if (r < 1.75F) {
      c = (r - 1.5F) * 3.14159274F;
      b_sin(&c);
    } else {
      c = (r - 2.0F) * 3.14159274F;
      c_cos(&c);
    }
  }
  return c;
}

/*
 * Arguments    : float x
 *                float *s
 * Return Type  : float
 */
float cospiAndSinpi(float x, float *s)
{
  float c;
  float r;
  boolean_T negateSinpi;
  if (x < 0.0F) {
    x = -x;
    negateSinpi = true;
  } else {
    negateSinpi = false;
  }
  if (x < 0.25F) {
    *s = x * 3.14159274F;
    c = *s;
    c_cos(&c);
    b_sin(s);
  } else {
    r = x - 2.0F * b_floor(x / 2.0F);
    if (r < 0.25F) {
      *s = r * 3.14159274F;
      c = *s;
      c_cos(&c);
      b_sin(s);
    } else if (r < 0.75F) {
      *s = (0.5F - r) * 3.14159274F;
      c = *s;
      b_sin(&c);
      c_cos(s);
    } else if (r < 1.25F) {
      *s = (1.0F - r) * 3.14159274F;
      r = *s;
      c_cos(&r);
      c = -r;
      b_sin(s);
    } else if (r < 1.75F) {
      *s = (r - 1.5F) * 3.14159274F;
      c = *s;
      b_sin(&c);
      c_cos(s);
      *s = -*s;
    } else {
      *s = (r - 2.0F) * 3.14159274F;
      c = *s;
      c_cos(&c);
      b_sin(s);
    }
  }
  if (negateSinpi) {
    *s = -*s;
  }
  return c;
}

/*
 * File trailer for cospiAndSinpi.c
 *
 * [EOF]
 */
