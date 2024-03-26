/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: floorFrac.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "floorFrac.h"
#include "floor1.h"
#include "minus.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const creal_T a
 *                double *frac
 * Return Type  : double
 */
double floorFrac(const creal_T a, double *frac)
{
  creal_T B;
  creal_T c;
  double b;
  B = d_floor(a);
  c = minus(a, B);
  b = B.re + B.im;
  *frac = c.re + c.im;
  return b;
}

/*
 * File trailer for floorFrac.c
 *
 * [EOF]
 */
