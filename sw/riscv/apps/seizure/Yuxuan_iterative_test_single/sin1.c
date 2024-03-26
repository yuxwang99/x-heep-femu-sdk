/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sin1.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "sin1.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : float *x
 * Return Type  : void
 */
void c_sin(float *x)
{
  *x = sinf(*x);
}

/*
 * Arguments    : double *x
 * Return Type  : void
 */
void e_sin(double *x)
{
  *x = sin(*x);
}

/*
 * File trailer for sin1.c
 *
 * [EOF]
 */
