/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_classifier.h
 *
 * Code generation for function 'test_classifier'
 *
 */

#ifndef TEST_CLASSIFIER_H
#define TEST_CLASSIFIER_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_test_classifier(const double features_data[], const int features_size[2],
    const boolean_T model_IsCached[30], const double model_ClassNames[2], const
    double model_Prior[2], double thrshd, double *output, double *score_seizure,
    double *score_no_seizure);
  void test_classifier(const double features_data[], const int features_size[2],
                       const boolean_T model_IsCached[30], const double
                       model_ClassNames[2], const double model_Prior[2], double
                       thrshd, double *output, double *score_seizure, double
                       *score_no_seizure);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (test_classifier.h) */
