/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: bitsra.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "bitsra.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static float b_ldexp(float u);

/* Function Definitions */
/*
 * Arguments    : float u
 * Return Type  : float
 */
static float b_ldexp(float u)
{
  return ldexpf(u, -1);
}

/*
 * Arguments    : float u
 * Return Type  : float
 */
float bitsra(float u)
{
  return b_ldexp(u);
}

/*
 * File trailer for bitsra.c
 *
 * [EOF]
 */
