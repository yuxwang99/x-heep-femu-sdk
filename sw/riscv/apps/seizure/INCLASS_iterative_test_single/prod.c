/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: prod.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "prod.h"
#include "INCLASS_iterative_test_single_types.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 * Return Type  : float
 */
float prod(const emxArray_real32_T *x)
{
  return h_combineVectorElements(x);
}

/*
 * File trailer for prod.c
 *
 * [EOF]
 */
