/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: indexIntRelop.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "indexIntRelop.h"
#include "floor.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int idx
 *                float flt
 * Return Type  : boolean_T
 */
boolean_T idx_eq_flt(int idx, float flt)
{
  boolean_T p;
  if ((flt >= -2.14748365E+9F) && (flt < 2.14748365E+9F) &&
      (b_floor(flt) == flt) && (idx == (int)flt)) {
    p = true;
  } else {
    p = false;
  }
  return p;
}

/*
 * Arguments    : float flt
 * Return Type  : boolean_T
 */
boolean_T idx_le_flt(float flt)
{
  boolean_T p;
  if ((flt >= 2.14748365E+9F) ||
      ((flt >= -2.14748365E+9F) && ((int)b_floor(flt) >= MAX_int32_T))) {
    p = true;
  } else {
    p = false;
  }
  return p;
}

/*
 * File trailer for indexIntRelop.c
 *
 * [EOF]
 */
