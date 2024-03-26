/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: getDateVec.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef GETDATEVEC_H
#define GETDATEVEC_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_getDateVec(const creal_T dd, double *mo, double *d, double *h,
                    double *m, double *s);

double getDateVec(const creal_T dd, double *mo, double *d);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for getDateVec.h
 *
 * [EOF]
 */
