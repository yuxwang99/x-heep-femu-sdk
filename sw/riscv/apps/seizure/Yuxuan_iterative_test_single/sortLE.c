/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortLE.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "sortLE.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include "sortAscendLE.h"
#include "sortDescendLE.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *v
 *                int idx1
 *                int idx2
 * Return Type  : boolean_T
 */
boolean_T b_sortLE(const emxArray_real32_T *v, int idx1, int idx2)
{
  const float *v_data;
  v_data = v->data;
  return sortAscendLE(v_data[idx1 - 1], v_data[idx2 - 1]);
}

/*
 * Arguments    : const emxArray_real_T *v
 *                int idx1
 *                int idx2
 * Return Type  : boolean_T
 */
boolean_T c_sortLE(const emxArray_real_T *v, int idx1, int idx2)
{
  const double *v_data;
  v_data = v->data;
  return b_sortAscendLE(v_data[idx1 - 1], v_data[idx2 - 1]);
}

/*
 * Arguments    : const emxArray_real32_T *v
 *                int idx1
 *                int idx2
 * Return Type  : boolean_T
 */
boolean_T sortLE(const emxArray_real32_T *v, int idx1, int idx2)
{
  const float *v_data;
  v_data = v->data;
  return sortDescendLE(v_data[idx1 - 1], v_data[idx2 - 1]);
}

/*
 * File trailer for sortLE.c
 *
 * [EOF]
 */
