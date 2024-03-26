/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: aggregatePredict.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef AGGREGATEPREDICT_H
#define AGGREGATEPREDICT_H

/* Include Files */
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                      const boolean_T learners[5],
                      const emxArray_boolean_T *useObsForLearner);

void b_aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                        const boolean_T isCached[15],
                        const boolean_T learners[15],
                        const emxArray_boolean_T *useObsForLearner);

void c_aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                        const boolean_T isCached[15],
                        const boolean_T learners[15],
                        const emxArray_boolean_T *useObsForLearner);

void d_aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                        const boolean_T isCached[15],
                        const boolean_T learners[15],
                        const emxArray_boolean_T *useObsForLearner);

void e_aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                        const boolean_T learners[10],
                        const emxArray_boolean_T *useObsForLearner);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for aggregatePredict.h
 *
 * [EOF]
 */
