/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationEnsemble.h
 *
 * Code generation for function 'CompactClassificationEnsemble'
 *
 */

#ifndef COMPACTCLASSIFICATIONENSEMBLE_H
#define COMPACTCLASSIFICATIONENSEMBLE_H

/* Include files */
#include "profile_Yuxuan_iteration_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void c_CompactClassificationEnsemble(boolean_T obj_IsCached[30], double
    obj_LearnerWeights[30], double obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4]);
  void d_CompactClassificationEnsemble(const boolean_T obj_IsCached[30], const
    double obj_ClassNames[2], const double obj_Prior[2], const double Xin_data[],
    const int Xin_size[2], double labels_data[], int labels_size[1], double
    score_data[], int score_size[2]);
  void e_CompactClassificationEnsemble(const boolean_T obj_IsCached[30], const
    double obj_ClassNames[2], const double obj_Prior[2], const double Xin_data[],
    const int Xin_size[2], double labels_data[], int labels_size[1], double
    score_data[], int score_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (CompactClassificationEnsemble.h) */
