/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * aggregatePredict.h
 *
 * Code generation for function 'aggregatePredict'
 *
 */

#ifndef AGGREGATEPREDICT_H
#define AGGREGATEPREDICT_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void aggregatePredict(const double X_data[], const int X_size[2], double
                        score_data[], int score_size[2], const boolean_T
                        isCached[30], const double classNames[2], const
                        boolean_T learners[30], const boolean_T
                        useObsForLearner_data[], const int
                        useObsForLearner_size[2]);
  void b_aggregatePredict(const double X_data[], const int X_size[2], double
    score_data[], int score_size[2], const boolean_T isCached[30], const double
    classNames[2], const boolean_T learners[30], const boolean_T
    useObsForLearner_data[], const int useObsForLearner_size[2]);
  void c_aggregatePredict(const double X_data[], const int X_size[2], double
    score_data[], int score_size[2], const boolean_T isCached[30], const double
    classNames[2], const boolean_T learners[30], const boolean_T
    useObsForLearner_data[], const int useObsForLearner_size[2]);
  void d_aggregatePredict(const double X_data[], const int X_size[2], double
    score_data[], int score_size[2], const boolean_T isCached[30], const double
    classNames[2], const boolean_T learners[30], const boolean_T
    useObsForLearner_data[], const int useObsForLearner_size[2]);
  void e_aggregatePredict(const double X_data[], const int X_size[2], double
    score_data[], int score_size[2], const boolean_T isCached[30], const double
    classNames[2], const boolean_T learners[30], const boolean_T
    useObsForLearner_data[], const int useObsForLearner_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (aggregatePredict.h) */
