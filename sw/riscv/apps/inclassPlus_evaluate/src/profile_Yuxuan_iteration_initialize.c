/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * profile_Yuxuan_iteration_initialize.c
 *
 * Code generation for function 'profile_Yuxuan_iteration_initialize'
 *
 */

/* Include files */
#include "profile_Yuxuan_iteration_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "profile_Yuxuan_iteration_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void profile_Yuxuan_iteration_initialize(void)
{
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_profile_Yuxuan_iteration = true;
}

/* End of code generation (profile_Yuxuan_iteration_initialize.c) */
