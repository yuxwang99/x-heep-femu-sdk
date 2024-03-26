/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: relop.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "relop.h"
#include "isnan.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static boolean_T c_relop(float a, float b);

static boolean_T e_relop(float a, float b);

static boolean_T g_relop(double a, double b);

/* Function Definitions */
/*
 * Arguments    : float a
 *                float b
 * Return Type  : boolean_T
 */
static boolean_T c_relop(float a, float b)
{
  return a >= b;
}

/*
 * Arguments    : float a
 *                float b
 * Return Type  : boolean_T
 */
static boolean_T e_relop(float a, float b)
{
  return a <= b;
}

/*
 * Arguments    : double a
 *                double b
 * Return Type  : boolean_T
 */
static boolean_T g_relop(double a, double b)
{
  return a <= b;
}

/*
 * Arguments    : float a
 *                float b
 * Return Type  : boolean_T
 */
boolean_T b_relop(float a, float b)
{
  boolean_T p;
  if (c_relop(a, b) || c_isnan(a)) {
    p = true;
  } else {
    p = false;
  }
  return p;
}

/*
 * Arguments    : float a
 *                float b
 * Return Type  : boolean_T
 */
boolean_T d_relop(float a, float b)
{
  boolean_T p;
  if (e_relop(a, b) || c_isnan(b)) {
    p = true;
  } else {
    p = false;
  }
  return p;
}

/*
 * Arguments    : double a
 *                double b
 * Return Type  : boolean_T
 */
boolean_T f_relop(double a, double b)
{
  boolean_T p;
  if (g_relop(a, b) || b_isnan(b)) {
    p = true;
  } else {
    p = false;
  }
  return p;
}

/*
 * Arguments    : float a
 *                float b
 * Return Type  : boolean_T
 */
boolean_T h_relop(float a, float b)
{
  boolean_T p;
  if (c_isnan(b)) {
    p = false;
  } else if (c_isnan(a)) {
    p = true;
  } else {
    p = (a < b);
  }
  return p;
}

/*
 * Arguments    : int a
 *                int b
 * Return Type  : boolean_T
 */
boolean_T relop(int a, int b)
{
  return a < b;
}

/*
 * File trailer for relop.c
 *
 * [EOF]
 */
