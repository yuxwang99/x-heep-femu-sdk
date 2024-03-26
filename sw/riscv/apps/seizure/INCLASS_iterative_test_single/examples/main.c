/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "INCLASS_iterative_test_single.h"
#include "INCLASS_iterative_test_single_emxAPI.h"
#include "INCLASS_iterative_test_single_terminate.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_5x17_int8_T(signed char result[85]);

static emxArray_real32_T *argInit_Unboundedx1_real32_T(void);

static signed char argInit_int8_T(void);

static float argInit_real32_T(void);

/* Function Definitions */
/*
 * Arguments    : signed char result[85]
 * Return Type  : void
 */
static void argInit_5x17_int8_T(signed char result[85])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 85; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_int8_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real32_T *
 */
static emxArray_real32_T *argInit_Unboundedx1_real32_T(void)
{
  emxArray_real32_T *result;
  float *result_data;
  int idx0 = 2;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_real32_T(1, &idx0);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx0] = argInit_real32_T();
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : signed char
 */
static signed char argInit_int8_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : float
 */
static float argInit_real32_T(void)
{
  return 0.0F;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_INCLASS_iterative_test_single();
  /* Terminate the application.
You do not need to do this more than one time. */
  INCLASS_iterative_test_single_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_INCLASS_iterative_test_single(void)
{
  emxArray_real32_T *ECG_sig;
  emxArray_real32_T *Spo2_sig;
  float mask_runtime[5];
  float conf_th_tmp;
  float final_result;
  float ind;
  float runtime;
  float saveup_time;
  signed char iv[85];
  /* Initialize function 'INCLASS_iterative_test_single' input arguments. */
  /* Initialize function input argument 'ECG_sig'. */
  ECG_sig = argInit_Unboundedx1_real32_T();
  /* Initialize function input argument 'Spo2_sig'. */
  Spo2_sig = argInit_Unboundedx1_real32_T();
  conf_th_tmp = argInit_real32_T();
  /* Initialize function input argument 'masks'. */
  /* Call the entry-point 'INCLASS_iterative_test_single'. */
  argInit_5x17_int8_T(iv);
  INCLASS_iterative_test_single(ECG_sig, Spo2_sig, conf_th_tmp, conf_th_tmp, iv,
                                &final_result, &ind, &runtime, &saveup_time,
                                mask_runtime);
  emxDestroyArray_real32_T(Spo2_sig);
  emxDestroyArray_real32_T(ECG_sig);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
