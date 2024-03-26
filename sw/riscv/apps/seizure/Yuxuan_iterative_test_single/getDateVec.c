/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: getDateVec.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "getDateVec.h"
#include "days2ymd.h"
#include "divide.h"
#include "divmod.h"
#include "floorFrac.h"
#include "rt_nonfinite.h"
#include "secs2hms.h"

/* Function Definitions */
/*
 * Arguments    : const creal_T dd
 *                double *mo
 *                double *d
 *                double *h
 *                double *m
 *                double *s
 * Return Type  : double
 */
double b_getDateVec(const creal_T dd, double *mo, double *d, double *h,
                    double *m, double *s)
{
  creal_T msOfDay;
  double fracSecs;
  double wholeDays;
  double wholeSecs;
  double y;
  wholeDays = divmod(dd, &msOfDay);
  wholeSecs = floorFrac(b_divide(msOfDay), &fracSecs);
  y = days2ymd(wholeDays, mo, d);
  *h = secs2hms(wholeSecs, m, s);
  *s += fracSecs;
  if (*s == 60.0) {
    *s = 59.999999999999993;
  }
  if ((dd.re == rtInf) && (dd.im == 0.0)) {
    y = rtInf;
  } else if ((dd.re == rtMinusInf) && (dd.im == 0.0)) {
    y = rtMinusInf;
  }
  return y;
}

/*
 * Arguments    : const creal_T dd
 *                double *mo
 *                double *d
 * Return Type  : double
 */
double getDateVec(const creal_T dd, double *mo, double *d)
{
  creal_T msOfDay;
  double wholeDays;
  double y;
  wholeDays = divmod(dd, &msOfDay);
  y = days2ymd(wholeDays, mo, d);
  if ((dd.re == rtInf) && (dd.im == 0.0)) {
    y = rtInf;
  } else if ((dd.re == rtMinusInf) && (dd.im == 0.0)) {
    y = rtMinusInf;
  }
  return y;
}

/*
 * File trailer for getDateVec.c
 *
 * [EOF]
 */
