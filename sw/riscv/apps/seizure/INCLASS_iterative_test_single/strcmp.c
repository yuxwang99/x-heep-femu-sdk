/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: strcmp.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "strcmp.h"
#include "lower.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const char b_data[]
 *                const int b_size[2]
 * Return Type  : boolean_T
 */
boolean_T b_strcmp(const char b_data[], const int b_size[2])
{
  static const char b_cv[8] = {'r', 'a', 'd', '/', 's', 'a', 'm', 'p'};
  boolean_T b_bool;
  b_bool = false;
  if (b_size[1] == 8) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (b_cv[kstr] != b_data[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

/*
 * Arguments    : const char b_data[]
 *                const int b_size[2]
 * Return Type  : boolean_T
 */
boolean_T c_strcmp(const char b_data[], const int b_size[2])
{
  static const char b_cv[2] = {'H', 'z'};
  boolean_T b_bool;
  b_bool = false;
  if (b_size[1] == 2) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (b_cv[kstr] != b_data[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

/*
 * Arguments    : const char a_data[]
 *                const int a_size[2]
 * Return Type  : boolean_T
 */
boolean_T d_strcmp(const char a_data[], const int a_size[2])
{
  static const char b_cv[8] = {'r', 'a', 'd', '/', 's', 'a', 'm', 'p'};
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 8) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (lower(a_data[kstr]) != lower(b_cv[kstr])) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

/*
 * Arguments    : const char a[15]
 * Return Type  : boolean_T
 */
boolean_T e_strcmp(const char a[15])
{
  static const char b_cv[15] = {'w', 'e', 'i', 'g', 'h', 't', 'e', 'd',
                                'a', 'v', 'e', 'r', 'a', 'g', 'e'};
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  kstr = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (kstr < 15) {
      if (lower(a[kstr]) != lower(b_cv[kstr])) {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return b_bool;
}

/*
 * File trailer for strcmp.c
 *
 * [EOF]
 */
