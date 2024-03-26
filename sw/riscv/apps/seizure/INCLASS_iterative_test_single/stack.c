/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: stack.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "stack.h"
#include "INCLASS_iterative_test_single_internal_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const struct_T eg
 *                int n
 *                struct_T this_d_data[]
 *                int *this_n
 * Return Type  : int
 */
int stack_stack(const struct_T eg, int n, struct_T this_d_data[], int *this_n)
{
  int i;
  int this_d_size;
  *this_n = 0;
  this_d_size = n;
  for (i = 0; i < n; i++) {
    this_d_data[i] = eg;
  }
  return this_d_size;
}

/*
 * File trailer for stack.c
 *
 * [EOF]
 */
