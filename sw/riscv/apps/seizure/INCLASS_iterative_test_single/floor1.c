/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: floor1.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "floor1.h"
#include "addToLoAndAdjust.h"
#include "floor.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const creal_T a
 * Return Type  : creal_T
 */
creal_T d_floor(const creal_T a)
{
  creal_T b;
  b.re = c_floor(a.re);
  b.im = 0.0;
  if (b.re == a.re) {
    addToLoAndAdjust(&b, c_floor(a.im));
  }
  return b;
}

/*
 * File trailer for floor1.c
 *
 * [EOF]
 */
