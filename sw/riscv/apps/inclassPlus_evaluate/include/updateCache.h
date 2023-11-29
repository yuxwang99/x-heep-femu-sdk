/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateCache.h
 *
 * Code generation for function 'updateCache'
 *
 */

#ifndef UPDATECACHE_H
#define UPDATECACHE_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void updateCache(const double learnerscore_data[], const int
                   learnerscore_size[2], double cachedScore_data[], const int
                   cachedScore_size[2], double cachedWeights_data[], boolean_T
                   *cached, const char combinerName[15], const boolean_T
                   obsIndices_data[], const int obsIndices_size[1], double
                   score_data[], int score_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (updateCache.h) */
