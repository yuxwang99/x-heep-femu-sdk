/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: getLocalTime.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "getLocalTime.h"
#include "CoderTimeAPI.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double *t_tm_sec
 *                double *t_tm_min
 *                double *t_tm_hour
 *                double *t_tm_mday
 *                double *t_tm_mon
 *                double *t_tm_year
 * Return Type  : double
 */
double getLocalTime(double *t_tm_sec, double *t_tm_min, double *t_tm_hour,
                    double *t_tm_mday, double *t_tm_mon, double *t_tm_year)
{
  return CoderTimeAPI_getLocalTime(t_tm_sec, t_tm_min, t_tm_hour, t_tm_mday,
                                   t_tm_mon, t_tm_year);
}

/*
 * File trailer for getLocalTime.c
 *
 * [EOF]
 */
