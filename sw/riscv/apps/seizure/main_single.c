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
#include "main_single.h"
#include "Yuxuan_iterative_test_single.h"
#include "Yuxuan_iterative_test_single_emxAPI.h"
#include "Yuxuan_iterative_test_single_terminate.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */

static emxArray_real32_T *argInit_Unboundedx1_real32_T(const char *filename, int idx0);

static signed char argInit_int8_T(void);

static float argInit_real32_T(void);


/*
 * Arguments    : void
 * Return Type  : emxArray_real32_T *
 */
static emxArray_real32_T *argInit_Unboundedx1_real32_T(const char *filename, int idx0)
{
  emxArray_real32_T *result;
  float *result_data;

  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_real32_T(1, &idx0);
  result_data = result->data;
  if (filename == NULL || filename[0] == '\0') {
    for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
      result_data[idx0] = argInit_real32_T();
    }
  } else {
    FILE *file;
    file = fopen(filename, "r");
    for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
      /* Read a real number from the file */
      if (fscanf(file, "%f", &result_data[idx0]) != 1) {
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

  float conf_val = 0.5;
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

    char ECG_file[100]; 
    sprintf(ECG_file, "./extern_input_256/ECG_%d_%d.txt", subject, type);
    char SpO2_file[100]; 
    sprintf(SpO2_file, "./extern_input_256/Spo2_%d_%d.txt", subject, type);
    main_Yuxuan_iterative_test_single(ECG_file, SpO2_file, conf_val, Fs, mask_inds, type);

  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Yuxuan_iterative_test_single(const char *ecgFile, 
  const char *spo2File, float conf, float Fs, const int mask_inds[5], const int type)
{
  emxArray_real32_T *ECG_sig;
  emxArray_real32_T *Spo2_sig;
  float mask_runtime[5];
  float final_result;
  float ind;
  float runtime;
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


  /* Initialize function 'Yuxuan_iterative_test_single' input arguments. */
  /* Initialize function input argument 'ECG_sig'. */
  ECG_sig = argInit_Unboundedx1_real32_T(ecgFile, 30720);
  /* Initialize function input argument 'Spo2_sig'. */

  Spo2_sig = argInit_Unboundedx1_real32_T(spo2File, 30720);

  /* Initialize function input argument 'masks'. */
  /* Call the entry-point 'Yuxuan_iterative_test_single'. */

  Yuxuan_iterative_test_single(ECG_sig, Spo2_sig, conf, 46, iv,
                               &final_result, &ind, &runtime, mask_runtime);


  printf("Pred: %d\n", (int)final_result);
  printf("True: %d\n", type);
  printf("Mask: %d\n", (int)ind);
  printf("total runtime: %.4lf\n", runtime);
  for (int i=0; i<5; ++i){
    printf("m%d runtime: %.4lf\n", i+1, mask_runtime[i]);
  }

  emxDestroyArray_real32_T(Spo2_sig);
  emxDestroyArray_real32_T(ECG_sig);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
