/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: datetime.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef DATETIME_H
#define DATETIME_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
creal_T datetime_datetime(void);

double datetime_hms(const creal_T this_data, double *m, double *s);

double datetime_ymd(const creal_T this_data, double *m, double *d);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for datetime.h
 *
 * [EOF]
 */
