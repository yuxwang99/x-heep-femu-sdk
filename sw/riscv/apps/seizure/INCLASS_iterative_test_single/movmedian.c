/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: movmedian.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "movmedian.h"
#include "movfunDispatch.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const float x[400]
 *                float y[400]
 * Return Type  : void
 */
void movmedian(const float x[400], float y[400])
{
  movfunDispatch(x, y);
}

/*
 * File trailer for movmedian.c
 *
 * [EOF]
 */
