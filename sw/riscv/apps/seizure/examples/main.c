/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Dec-2023 17:18:40
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
#include "INCLASS_iterative_test.h"
#include "INCLASS_iterative_test_emxAPI.h"
#include "INCLASS_iterative_test_terminate.h"
#include "INCLASS_iterative_test_types.h"
#include "rt_nonfinite.h"
#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */
static void argInit_5x17_int8_T(signed char result[85]);

static emxArray_real_T *argInit_Unboundedx1_real_T(const char *filename, int idx0);

static signed char argInit_int8_T(void);

static double argInit_real_T(void);

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
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(const char *filename, int idx0)
{
  emxArray_real_T *result;
  double *result_data;
  
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, &idx0);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  if (filename == NULL || filename[0] == '\0') {
    for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
      result_data[idx0] = argInit_real_T();
    }
  } else {
    FILE *file;
    file = fopen(filename, "r");
    for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
      /* Read a real number from the file */
      if (fscanf(file, "%lf", &result_data[idx0]) != 1) {
        fprintf(stderr, "Error reading value from file: %s %d\n", filename, idx0);
        // Handle the error as needed
        break;
      }
    }
    fclose(file);
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
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
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

  double conf_val = 0.5;
  int mask_inds[5] = {0,1,2,3,4};
  int subject = 36;
  int Fs = 256;
  int type = 0;

  if (argc > 5){
    subject = atoi(argv[1]);
    type = atoi(argv[2]);
    conf_val = strtod(argv[3], NULL);
    // mask_ind = atoi(argv[3]);
    for (int i = 4; i < argc; ++i) {
        mask_inds[i - 4] = atoi(argv[i]);
    }
  }
  printf("confidence: %f \n", conf_val);
  printf("mask_ind: [ ");
  int nModels = 0;
  for (int i = 0; i < 5; ++i) {
      printf("%d ", mask_inds[i]);
      if (mask_inds[i] >= 0)
        nModels++;
  }
  printf("]\n");
  printf("Nmodels: %d\n", nModels);
  printf("Subject: %d\n", subject);
  printf("Type: %d\n", type);
  printf("Segment: 0\n");

  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */

  // loop over all the segments
  int subjects[] = {36, 41, 45, 50, 56, 60, 62, 78, 84};
  // bool types[] = {1, 0};
  //  for (int i=0; i<9; ++i){
  //   subject = subjects[i];

  //   for (int j=0; j<2; ++j){
  //     type = j;
      char ECG_file[100]; 
      sprintf(ECG_file, "./extern_input_256/ECG_%d_%d.txt", subject, type);
      char SpO2_file[100]; 
      sprintf(SpO2_file, "./extern_input_256/Spo2_%d_%d.txt", subject, type);
      
      main_INCLASS_iterative_test(ECG_file, SpO2_file, conf_val, 256, mask_inds, type);
  //   }
  //  }
  
  /* Terminate the application.
You do not need to do this more than one time. */
  INCLASS_iterative_test_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_INCLASS_iterative_test(const char *ecgFile, 
  const char *spo2File, double conf, double Fs, const int mask_inds[5], const int type)
{
  emxArray_real_T *ECG_sig;
  emxArray_real_T *Spo2_sig;
  double final_result;
  double mask_id;
  double runtime;
  double saveup_time;
  signed char iv[85] ={
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 1, 1,
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
    
  /* Initialize function 'INCLASS_iterative_test' input arguments. */
  /* Initialize function input argument 'ECG_sig'. */
  ECG_sig = argInit_Unboundedx1_real_T(ecgFile, 30720);
  /* Initialize function input argument 'Spo2_sig'. */

  Spo2_sig = argInit_Unboundedx1_real_T(spo2File, 30720);
  /* Initialize function input argument 'masks'. */
  /* Call the entry-point 'INCLASS_iterative_test'. */
  // argInit_5x17_int8_T(iv);
  // HeapProfilerStart();
  double mask_runtime[5];
  INCLASS_iterative_test(ECG_sig, Spo2_sig, conf, Fs, iv, 
      &final_result, &mask_id, &runtime, &saveup_time,mask_runtime);

  
  printf("Pred: %d\n", (int)final_result);
  printf("True: %d\n", type);
  printf("Mask: %d\n", (int)mask_id);
  printf("total runtime: %.4lf\n", runtime);
  printf("saveup time: %.4lf\n", saveup_time);
  for (int i=0; i<5; ++i){
    printf("m%d runtime: %.4lf\n", i+1, mask_runtime[i]);
  }
  
  // HeapProfilerDump(); 
  // HeapProfilerStop();
  emxDestroyArray_real_T(Spo2_sig);
  emxDestroyArray_real_T(ECG_sig);
  
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
