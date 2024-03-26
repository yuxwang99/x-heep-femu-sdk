/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sinpi1.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "sinpi1.h"
#include "cospiAndSinpi.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float x
 * Return Type  : float
 */
float b_sinpi(float x)
{
  float s;
  cospiAndSinpi(x, &s);
  return s;
}

/*
 * File trailer for sinpi1.c
 *
 * [EOF]
 */
