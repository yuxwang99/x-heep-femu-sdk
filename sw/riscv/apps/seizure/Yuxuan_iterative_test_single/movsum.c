/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: movsum.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "movsum.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "movfunDispatch.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 *                float k
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void movsum(const emxArray_real32_T *x, float k, emxArray_real32_T *y)
{
  b_movfunDispatch(x, k, y);
}

/*
 * File trailer for movsum.c
 *
 * [EOF]
 */
