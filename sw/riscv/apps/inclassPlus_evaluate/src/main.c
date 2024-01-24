/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
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

/* Include files */
#include "main.h"
#include "profile_Yuxuan_iteration.h"
#include "profile_Yuxuan_iteration_terminate.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <sys/time.h>

/* Function Declarations */
static void argInit_1x13_real_T(double result[13]);
static void argInit_1x17_real_T(double result[17]);
static void argInit_1x2_real_T(double result[2]);
static void argInit_1x3_real_T(double result[3]);
static void argInit_1x41_char_T(char result[41]);
static void argInit_1x42_char_T(char result[42]);
static void argInit_1x43_char_T(char result[43]);
static void argInit_1x5_real_T(double result[5]);
static void argInit_30720x90_real_T(double result[2764800]);
static void argInit_5x17_real_T(double result[85]);
static void argInit_90x1_boolean_T(boolean_T result[90]);
static boolean_T argInit_boolean_T(void);
static void argInit_cell_0(cell_0 *result);
static char argInit_char_T(void);
static double argInit_real_T(void);
static rtString argInit_rtString(void);
static b_rtString b_argInit_rtString(void);
static c_rtString c_argInit_rtString(void);
static void main_profile_Yuxuan_iteration(void);

/* Function Definitions */
static void argInit_1x13_real_T(double result[13])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 13; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x17_real_T(double result[17])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 17; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x2_real_T(double result[2])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x3_real_T(double result[3])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 3; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x41_char_T(char result[41])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 41; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x42_char_T(char result[42])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 42; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x43_char_T(char result[43])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 43; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x5_real_T(double result[5])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 5; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_30720x90_real_T(double result[2764800])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 30720; idx0++) {
    for (idx1 = 0; idx1 < 90; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 30720 * idx1] = argInit_real_T();
    }
  }
}

static void argInit_5x17_real_T(double result[85])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    for (idx1 = 0; idx1 < 17; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 5 * idx1] = argInit_real_T();
    }
  }
}

static void argInit_90x1_boolean_T(boolean_T result[90])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 90; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_boolean_T();
  }
}

static boolean_T argInit_boolean_T(void)
{
  return false;
}

static void argInit_cell_0(cell_0 *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result->f2 = b_argInit_rtString();
  result->f1 = argInit_rtString();
  result->f49 = c_argInit_rtString();
  result->f3 = result->f2;
  result->f4 = result->f2;
  result->f5 = result->f2;
  result->f6 = result->f2;
  result->f7 = result->f2;
  result->f8 = result->f2;
  result->f9 = result->f2;
  result->f10 = result->f2;
  result->f11 = result->f2;
  result->f12 = result->f1;
  result->f13 = result->f2;
  result->f14 = result->f1;
  result->f15 = result->f1;
  result->f16 = result->f1;
  result->f17 = result->f1;
  result->f18 = result->f1;
  result->f19 = result->f1;
  result->f20 = result->f1;
  result->f21 = result->f2;
  result->f22 = result->f2;
  result->f23 = result->f2;
  result->f24 = result->f2;
  result->f25 = result->f2;
  result->f26 = result->f2;
  result->f27 = result->f2;
  result->f28 = result->f2;
  result->f29 = result->f2;
  result->f30 = result->f2;
  result->f31 = result->f2;
  result->f32 = result->f2;
  result->f33 = result->f2;
  result->f34 = result->f2;
  result->f35 = result->f2;
  result->f36 = result->f2;
  result->f37 = result->f2;
  result->f38 = result->f2;
  result->f39 = result->f1;
  result->f40 = result->f1;
  result->f41 = result->f2;
  result->f42 = result->f2;
  result->f43 = result->f2;
  result->f44 = result->f2;
  result->f45 = result->f2;
  result->f46 = result->f2;
  result->f47 = result->f1;
  result->f48 = result->f1;
  result->f50 = result->f49;
  result->f51 = result->f2;
  result->f52 = result->f2;
  result->f53 = result->f1;
  result->f54 = result->f1;
  result->f55 = result->f1;
  result->f56 = result->f2;
  result->f57 = result->f2;
  result->f58 = result->f2;
  result->f59 = result->f2;
  result->f60 = result->f2;
  result->f61 = result->f2;
  result->f62 = result->f2;
  result->f63 = result->f1;
  result->f64 = result->f2;
  result->f65 = result->f2;
  result->f66 = result->f2;
  result->f67 = result->f2;
  result->f68 = result->f2;
  result->f69 = result->f2;
  result->f70 = result->f1;
  result->f71 = result->f2;
  result->f72 = result->f2;
  result->f73 = result->f2;
  result->f74 = result->f2;
  result->f75 = result->f1;
  result->f76 = result->f1;
  result->f77 = result->f1;
  result->f78 = result->f1;
  result->f79 = result->f2;
  result->f80 = result->f2;
  result->f81 = result->f2;
  result->f82 = result->f1;
  result->f83 = result->f1;
  result->f84 = result->f1;
  result->f85 = result->f1;
  result->f86 = result->f1;
  result->f87 = result->f1;
  result->f88 = result->f1;
  result->f89 = result->f1;
  result->f90 = result->f1;
}

static char argInit_char_T(void)
{
  return '?';
}

static double argInit_real_T(void)
{
  return 0.0;
}

static rtString argInit_rtString(void)
{
  rtString result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x41_char_T(result.Value);
  return result;
}

static b_rtString b_argInit_rtString(void)
{
  b_rtString result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x42_char_T(result.Value);
  return result;
}

static c_rtString c_argInit_rtString(void)
{
  c_rtString result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x43_char_T(result.Value);
  return result;
}

static void main_profile_Yuxuan_iteration(void)
{
  static cell_0 r;
  static double ECG_Seiz_Window_tmp[2764800];
  static double pred_label_data[900];
  static double true_label_data[180];
  static double dv5[85];
  double dv4[17];
  double dv3[13];
  double dv2[5];
  double dv1[3];
  double dv[2];
  double wind_len_tmp;
  int pred_label_size[2];
  int true_label_size[2];
  boolean_T bv[90];

  /* Initialize function 'profile_Yuxuan_iteration' input arguments. */
  /* Initialize function input argument 'ECG_Seiz_Window'. */
  argInit_30720x90_real_T(ECG_Seiz_Window_tmp);

  /* Initialize function input argument 'Spo2_Seiz_Window'. */
  /* Initialize function input argument 'ECG_Gray_Window'. */
  /* Initialize function input argument 'Spo2_Gray_Window'. */
  /* Initialize function input argument 'norm_coef1'. */
  /* Initialize function input argument 'norm_coef2'. */
  /* Initialize function input argument 'norm_coef3'. */
  /* Initialize function input argument 'norm_coef4'. */
  /* Initialize function input argument 'norm_coef5'. */
  wind_len_tmp = argInit_real_T();

  /* Initialize function input argument 'masks'. */
  /* Initialize function input argument 'File_info'. */
  /* Initialize function input argument 'select_ind'. */
  /* Call the entry-point 'profile_Yuxuan_iteration'. */
  argInit_1x2_real_T(dv);
  argInit_1x3_real_T(dv1);
  argInit_1x5_real_T(dv2);
  argInit_1x13_real_T(dv3);
  argInit_1x17_real_T(dv4);
  argInit_5x17_real_T(dv5);
  argInit_cell_0(&r);
  argInit_90x1_boolean_T(bv);

//  struct timeval currentTime;
//   gettimeofday(&currentTime, NULL);

    // Calculate milliseconds
//    long milliseconds = currentTime.tv_sec * 1000 + currentTime.tv_usec / 1000;

//    printf("Current time in milliseconds: %ld\n", milliseconds);


  profile_Yuxuan_iteration(ECG_Seiz_Window_tmp, ECG_Seiz_Window_tmp,
    ECG_Seiz_Window_tmp, ECG_Seiz_Window_tmp, dv, dv1, dv2, dv3, dv4,
    wind_len_tmp, dv5, wind_len_tmp, &r, wind_len_tmp, wind_len_tmp,
    wind_len_tmp, bv, pred_label_data, pred_label_size, true_label_data,
    true_label_size);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_profile_Yuxuan_iteration();

  /* Terminate the application.
     You do not need to do this more than one time. */
  profile_Yuxuan_iteration_terminate();
  return 0;
}

/* End of code generation (main.c) */
