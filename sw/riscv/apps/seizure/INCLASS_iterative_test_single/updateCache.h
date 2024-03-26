/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: updateCache.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef UPDATECACHE_H
#define UPDATECACHE_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void updateCache(const emxArray_real32_T *learnerscore,
                 emxArray_real32_T *cachedScore,
                 emxArray_real32_T *cachedWeights, boolean_T *cached,
                 const char combinerName[15],
                 const emxArray_boolean_T *obsIndices,
                 emxArray_real32_T *score);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for updateCache.h
 *
 * [EOF]
 */
