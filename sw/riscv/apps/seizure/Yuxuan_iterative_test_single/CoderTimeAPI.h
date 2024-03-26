/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CoderTimeAPI.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef CODERTIMEAPI_H
#define CODERTIMEAPI_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double CoderTimeAPI_getLocalTime(double *t_tm_sec, double *t_tm_min,
                                 double *t_tm_hour, double *t_tm_mday,
                                 double *t_tm_mon, double *t_tm_year);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CoderTimeAPI.h
 *
 * [EOF]
 */
