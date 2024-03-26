/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactEnsemble.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef COMPACTENSEMBLE_H
#define COMPACTENSEMBLE_H

/* Include Files */
#include "INCLASS_iterative_test_single_internal_types.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void CompactEnsemble_CompactEnsemble(gc_classreg_learning_classif_Co *obj);

void CompactEnsemble_ensemblePredict(const emxArray_real32_T *X,
                                     emxArray_real32_T *score);

void b_CompactEnsemble_ensemblePredi(const boolean_T obj_IsCached[15],
                                     const emxArray_real32_T *X,
                                     emxArray_real32_T *score);

void c_CompactEnsemble_ensemblePredi(const boolean_T obj_IsCached[15],
                                     const emxArray_real32_T *X,
                                     emxArray_real32_T *score);

void d_CompactEnsemble_ensemblePredi(const boolean_T obj_IsCached[15],
                                     const emxArray_real32_T *X,
                                     emxArray_real32_T *score);

void e_CompactEnsemble_ensemblePredi(const emxArray_real32_T *X,
                                     emxArray_real32_T *score);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CompactEnsemble.h
 *
 * [EOF]
 */
