/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Feb-2024 09:56:27
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
#include "data.h"
#include "INCLASS_iterative_test_single.h"
#include "INCLASS_iterative_test_single_emxAPI.h"
#include "INCLASS_iterative_test_single_terminate.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */

static emxArray_real32_T *argInit_Unboundedx1_real32_T(int idx0, float *data);

static signed char argInit_int8_T(void);

static float argInit_real32_T(void);


/*
 * Arguments    : void
 * Return Type  : emxArray_real32_T *
 */
static emxArray_real32_T *argInit_Unboundedx1_real32_T(int idx0, float *data)
{
  emxArray_real32_T *result;
  float *result_data;

  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_real32_T(1, &idx0);
  result_data = result->data;
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    result_data[idx0] = data[idx0];
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
int main()
{

  float conf_val = 0;
  int mask_inds[5] = {0,1,2,3,4};
  int Fs = 256;
  
  printf("confidence: 0.%d \n", (int)(conf_val*10));
  printf("mask_ind: [ ");
  for (int i = 0; i < 5; ++i) {
      printf("%d ", mask_inds[i]);
  }
  printf("]\n");

  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
    main_INCLASS_iterative_test_single(conf_val, Fs, mask_inds);

  return EXIT_SUCCESS;
}

/*
 * Arguments    : void
 * Return Type  : void
 */

void init_data(emxArray_real32_T **pEmxArray) {
 *pEmxArray = (emxArray_real32_T *)malloc(sizeof(emxArray_real32_T));
 emxArray_real32_T *exmArray = *pEmxArray;
 exmArray->data = (float *)malloc(2*30720 * sizeof(float));
}

void main_INCLASS_iterative_test_single(float conf, float Fs, const int mask_inds[5])
{
  emxArray_real32_T *ECG_sig;
  emxArray_real32_T *Spo2_sig;
  float mask_runtime[5];
  float final_result;
  float ind;
  float runtime;
  float saveup_time;
  signed char iv[85] ={
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 1,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1,
    0, 0, 1, 1, 1,
    0, 0, 0, 1, 1};

  int i = 0;
  for (i = 0; i < 85; i++) {
      bool found = false;
      for (size_t j = 0; j < 5; ++j) {
          if (i % 5 == mask_inds[j]) {
              found = true;
              break;
          }
      }
      if (!found) {
        iv[i] = 0;
      }
  }


  /* Initialize function 'INCLASS_iterative_test_single' input arguments. */
  /* Initialize function input argument 'ECG_sig'. */
  ECG_sig = argInit_Unboundedx1_real32_T(3072, ECG_MATRIX);
  //emxArray_real32_T *emxArray = (emxArray_real32_T *)malloc(sizeof(emxArray_real32_T));
 //emxArray->data = (float *)malloc(2*30720 * sizeof(float)); 

 // emxArray_real32_T *emx;
 // init_data(&emx);
//  float *Spo2 = (float *)malloc(2*30720 * sizeof(float));
/* Initialize function input argument 'Spo2_sig'. */

//  Spo2_sig = argInit_Unboundedx1_real32_T(30720, SPO2_MATRIX);

  /* Initialize function input argument 'masks'. */
  /* Call the entry-point 'INCLASS_iterative_test_single'. */

//  INCLASS_iterative_test_single(ECG_sig, Spo2_sig, conf, 46, iv,
//                               &final_result, &ind);


  printf("Pred: %d\n", (int)final_result);
  printf("Mask: %d\n", (int)(ind-1));
  // printf("total runtime: %.4lf\n", runtime);
  // printf("saveup time: %.4lf\n", saveup_time);
  // for (int i=0; i<5; ++i){
  //   printf("m%d runtime: %.4lf\n", i+1, mask_runtime[i]);
  // }

//  emxDestroyArray_real32_T(Spo2_sig);
  emxDestroyArray_real32_T(ECG_sig);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
