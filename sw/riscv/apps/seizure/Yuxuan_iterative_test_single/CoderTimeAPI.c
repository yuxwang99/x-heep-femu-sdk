/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CoderTimeAPI.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "CoderTimeAPI.h"
#include "rt_nonfinite.h"
#include "coder_posix_time.h"

/* Function Declarations */
static double tmToMATLABTimespec(
    long origStructTm_tm_nsec, int origStructTm_tm_sec, int origStructTm_tm_min,
    int origStructTm_tm_hour, int origStructTm_tm_mday, int origStructTm_tm_mon,
    int origStructTm_tm_year, int origStructTm_tm_isdst,
    double *structTm_tm_sec, double *structTm_tm_min, double *structTm_tm_hour,
    double *structTm_tm_mday, double *structTm_tm_mon, double *structTm_tm_year,
    boolean_T *structTm_tm_isdst);

/* Function Definitions */
/*
 * Arguments    : long origStructTm_tm_nsec
 *                int origStructTm_tm_sec
 *                int origStructTm_tm_min
 *                int origStructTm_tm_hour
 *                int origStructTm_tm_mday
 *                int origStructTm_tm_mon
 *                int origStructTm_tm_year
 *                int origStructTm_tm_isdst
 *                double *structTm_tm_sec
 *                double *structTm_tm_min
 *                double *structTm_tm_hour
 *                double *structTm_tm_mday
 *                double *structTm_tm_mon
 *                double *structTm_tm_year
 *                boolean_T *structTm_tm_isdst
 * Return Type  : double
 */
static double tmToMATLABTimespec(
    long origStructTm_tm_nsec, int origStructTm_tm_sec, int origStructTm_tm_min,
    int origStructTm_tm_hour, int origStructTm_tm_mday, int origStructTm_tm_mon,
    int origStructTm_tm_year, int origStructTm_tm_isdst,
    double *structTm_tm_sec, double *structTm_tm_min, double *structTm_tm_hour,
    double *structTm_tm_mday, double *structTm_tm_mon, double *structTm_tm_year,
    boolean_T *structTm_tm_isdst)
{
  double structTm_tm_nsec;
  structTm_tm_nsec = (double)origStructTm_tm_nsec;
  *structTm_tm_sec = origStructTm_tm_sec;
  *structTm_tm_min = origStructTm_tm_min;
  *structTm_tm_hour = origStructTm_tm_hour;
  *structTm_tm_mday = origStructTm_tm_mday;
  *structTm_tm_mon = origStructTm_tm_mon;
  *structTm_tm_year = origStructTm_tm_year;
  *structTm_tm_isdst = (origStructTm_tm_isdst != 0);
  return structTm_tm_nsec;
}

/*
 * Arguments    : double *t_tm_sec
 *                double *t_tm_min
 *                double *t_tm_hour
 *                double *t_tm_mday
 *                double *t_tm_mon
 *                double *t_tm_year
 * Return Type  : double
 */
double CoderTimeAPI_getLocalTime(double *t_tm_sec, double *t_tm_min,
                                 double *t_tm_hour, double *t_tm_mday,
                                 double *t_tm_mon, double *t_tm_year)
{
  coderTm structTm;
  boolean_T expl_temp;
  coderLocalTime(&structTm);
  return tmToMATLABTimespec(structTm.tm_nsec, structTm.tm_sec, structTm.tm_min,
                            structTm.tm_hour, structTm.tm_mday, structTm.tm_mon,
                            structTm.tm_year, structTm.tm_isdst, t_tm_sec,
                            t_tm_min, t_tm_hour, t_tm_mday, t_tm_mon, t_tm_year,
                            &expl_temp);
}

/*
 * File trailer for CoderTimeAPI.c
 *
 * [EOF]
 */
