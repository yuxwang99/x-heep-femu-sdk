/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortDescendLE.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "sortDescendLE.h"
#include "relop.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float a
 *                float b
 * Return Type  : boolean_T
 */
boolean_T sortDescendLE(float a, float b)
{
  return b_relop(a, b);
}

/*
 * File trailer for sortDescendLE.c
 *
 * [EOF]
 */
