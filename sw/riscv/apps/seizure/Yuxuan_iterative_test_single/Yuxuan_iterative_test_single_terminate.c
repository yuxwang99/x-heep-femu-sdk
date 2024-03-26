/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Yuxuan_iterative_test_single_terminate.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "Yuxuan_iterative_test_single_terminate.h"
#include "Yuxuan_iterative_test_single_data.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void Yuxuan_iterative_test_single_terminate(void)
{
  emxFree_real32_T(&ECG_segment_g);
  emxFree_real32_T(&Rlocs_g);
  isInitialized_Yuxuan_iterative_test_single = false;
}

/*
 * File trailer for Yuxuan_iterative_test_single_terminate.c
 *
 * [EOF]
 */
