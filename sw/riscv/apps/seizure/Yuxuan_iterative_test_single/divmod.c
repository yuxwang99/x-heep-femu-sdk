/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: divmod.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "divmod.h"
#include "divide.h"
#include "floor1.h"
#include "minus.h"
#include "rt_nonfinite.h"
#include "times.h"

/* Function Definitions */
/*
 * Arguments    : const creal_T a
 *                creal_T *c
 * Return Type  : double
 */
double divmod(const creal_T a, creal_T *c)
{
  creal_T r;
  double n_rem;
  r = d_floor(divide(a));
  n_rem = r.re + r.im;
  *c = minus(a, times(r));
  return n_rem;
}

/*
 * File trailer for divmod.c
 *
 * [EOF]
 */
