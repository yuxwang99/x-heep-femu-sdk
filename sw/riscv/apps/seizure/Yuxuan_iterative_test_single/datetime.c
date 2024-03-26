/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: datetime.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "datetime.h"
#include "createFromDateVec.h"
#include "getDateVec.h"
#include "getLocalTime.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static creal_T currentTime(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : creal_T
 */
static creal_T currentTime(void)
{
  double b_c_tm_year[7];
  double c_tm_hour;
  double c_tm_mday;
  double c_tm_min;
  double c_tm_mon;
  double c_tm_nsec;
  double c_tm_sec;
  double c_tm_year;
  c_tm_nsec = getLocalTime(&c_tm_sec, &c_tm_min, &c_tm_hour, &c_tm_mday,
                           &c_tm_mon, &c_tm_year);
  b_c_tm_year[0] = c_tm_year;
  b_c_tm_year[1] = c_tm_mon;
  b_c_tm_year[2] = c_tm_mday;
  b_c_tm_year[3] = c_tm_hour;
  b_c_tm_year[4] = c_tm_min;
  b_c_tm_year[5] = c_tm_sec;
  b_c_tm_year[6] = c_tm_nsec / 1.0E+6;
  return createFromDateVec(b_c_tm_year);
}

/*
 * Arguments    : void
 * Return Type  : creal_T
 */
creal_T datetime_datetime(void)
{
  return currentTime();
}

/*
 * Arguments    : const creal_T this_data
 *                double *m
 *                double *s
 * Return Type  : double
 */
double datetime_hms(const creal_T this_data, double *m, double *s)
{
  double a__106;
  double a__107;
  double h;
  b_getDateVec(this_data, &a__106, &a__107, &h, m, s);
  return h;
}

/*
 * Arguments    : const creal_T this_data
 *                double *m
 *                double *d
 * Return Type  : double
 */
double datetime_ymd(const creal_T this_data, double *m, double *d)
{
  return getDateVec(this_data, m, d);
}

/*
 * File trailer for datetime.c
 *
 * [EOF]
 */
