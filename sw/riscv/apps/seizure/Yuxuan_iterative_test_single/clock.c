/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clock.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "clock.h"
#include "datetime.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double varargout_1[6]
 * Return Type  : void
 */
void b_clock(double varargout_1[6])
{
  creal_T d_data;
  d_data = datetime_datetime();
  varargout_1[0] = datetime_ymd(d_data, &varargout_1[1], &varargout_1[2]);
  varargout_1[3] = datetime_hms(d_data, &varargout_1[4], &varargout_1[5]);
}

/*
 * File trailer for clock.c
 *
 * [EOF]
 */
