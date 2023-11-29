/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationModel.h
 *
 * Code generation for function 'CompactClassificationModel'
 *
 */

#ifndef COMPACTCLASSIFICATIONMODEL_H
#define COMPACTCLASSIFICATIONMODEL_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void c_CompactClassificationModel_ma(const double obj_ClassNames[2], const
    double obj_Prior[2], const double scores_data[], const int scores_size[2],
    double labels_data[], int labels_size[1]);
  void c_CompactClassificationModel_mi(const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double scoresIn_data[],
    const int scoresIn_size[2], double labels_data[], int labels_size[1], double
    classnum_data[], int classnum_size[1], double cost_data[], int cost_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (CompactClassificationModel.h) */
