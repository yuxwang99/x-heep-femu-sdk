/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationEnsemble.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef COMPACTCLASSIFICATIONENSEMBLE_H
#define COMPACTCLASSIFICATIONENSEMBLE_H

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
void c_CompactClassificationEnsemble(fc_classreg_learning_classif_Co *obj);

void d_CompactClassificationEnsemble(gc_classreg_learning_classif_Co *obj);

void e_CompactClassificationEnsemble(fc_classreg_learning_classif_Co *obj);

void f_CompactClassificationEnsemble(const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score);

void g_CompactClassificationEnsemble(const boolean_T obj_IsCached[15],
                                     const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score);

void h_CompactClassificationEnsemble(const boolean_T obj_IsCached[15],
                                     const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score);

void i_CompactClassificationEnsemble(const boolean_T obj_IsCached[15],
                                     const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score);

void j_CompactClassificationEnsemble(const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CompactClassificationEnsemble.h
 *
 * [EOF]
 */
