/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationEnsemble.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "CompactClassificationEnsemble.h"
#include "CompactClassificationModel.h"
#include "CompactEnsemble.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_internal_types.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"
#include "table2PredictMatrix.h"

/* Function Definitions */
/*
 * Arguments    : fc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void c_CompactClassificationEnsemble(fc_classreg_learning_classif_Co *obj)
{
  c_CompactClassificationModel_se(obj);
  d_CompactClassificationModel_se();
}

/*
 * Arguments    : gc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void d_CompactClassificationEnsemble(gc_classreg_learning_classif_Co *obj)
{
  CompactEnsemble_CompactEnsemble(obj);
  e_CompactClassificationModel_se(obj);
  f_CompactClassificationModel_se();
}

/*
 * Arguments    : fc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void e_CompactClassificationEnsemble(fc_classreg_learning_classif_Co *obj)
{
  g_CompactClassificationModel_se(obj);
  h_CompactClassificationModel_se();
}

/*
 * Arguments    : const float obj_Prior[2]
 *                const emxArray_real32_T *Xin
 *                emxArray_real32_T *labels
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void f_CompactClassificationEnsemble(const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score)
{
  emxArray_real32_T *X;
  float *score_data;
  int i;
  if (Xin->size[0] == 0) {
    score->size[0] = 0;
    score->size[1] = 2;
    labels->size[0] = 0;
  } else {
    int loop_ub;
    emxInit_real32_T(&X, 2);
    table2PredictMatrix(Xin, X);
    i = score->size[0] * score->size[1];
    score->size[0] = X->size[0];
    score->size[1] = 2;
    emxEnsureCapacity_real32_T(score, i);
    score_data = score->data;
    loop_ub = X->size[0] << 1;
    for (i = 0; i < loop_ub; i++) {
      score_data[i] = 0.0F;
    }
    CompactEnsemble_ensemblePredict(X, score);
    emxFree_real32_T(&X);
    c_CompactClassificationModel_ma(obj_Prior, score, labels);
  }
}

/*
 * Arguments    : const boolean_T obj_IsCached[15]
 *                const float obj_Prior[2]
 *                const emxArray_real32_T *Xin
 *                emxArray_real32_T *labels
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void g_CompactClassificationEnsemble(const boolean_T obj_IsCached[15],
                                     const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score)
{
  emxArray_real32_T *X;
  float *score_data;
  int i;
  if (Xin->size[0] == 0) {
    score->size[0] = 0;
    score->size[1] = 2;
    labels->size[0] = 0;
  } else {
    int loop_ub;
    emxInit_real32_T(&X, 2);
    b_table2PredictMatrix(Xin, X);
    i = score->size[0] * score->size[1];
    score->size[0] = X->size[0];
    score->size[1] = 2;
    emxEnsureCapacity_real32_T(score, i);
    score_data = score->data;
    loop_ub = X->size[0] << 1;
    for (i = 0; i < loop_ub; i++) {
      score_data[i] = 0.0F;
    }
    b_CompactEnsemble_ensemblePredi(obj_IsCached, X, score);
    emxFree_real32_T(&X);
    c_CompactClassificationModel_ma(obj_Prior, score, labels);
  }
}

/*
 * Arguments    : const boolean_T obj_IsCached[15]
 *                const float obj_Prior[2]
 *                const emxArray_real32_T *Xin
 *                emxArray_real32_T *labels
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void h_CompactClassificationEnsemble(const boolean_T obj_IsCached[15],
                                     const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score)
{
  emxArray_real32_T *X;
  float *score_data;
  int i;
  if (Xin->size[0] == 0) {
    score->size[0] = 0;
    score->size[1] = 2;
    labels->size[0] = 0;
  } else {
    int loop_ub;
    emxInit_real32_T(&X, 2);
    c_table2PredictMatrix(Xin, X);
    i = score->size[0] * score->size[1];
    score->size[0] = X->size[0];
    score->size[1] = 2;
    emxEnsureCapacity_real32_T(score, i);
    score_data = score->data;
    loop_ub = X->size[0] << 1;
    for (i = 0; i < loop_ub; i++) {
      score_data[i] = 0.0F;
    }
    c_CompactEnsemble_ensemblePredi(obj_IsCached, X, score);
    emxFree_real32_T(&X);
    c_CompactClassificationModel_ma(obj_Prior, score, labels);
  }
}

/*
 * Arguments    : const boolean_T obj_IsCached[15]
 *                const float obj_Prior[2]
 *                const emxArray_real32_T *Xin
 *                emxArray_real32_T *labels
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void i_CompactClassificationEnsemble(const boolean_T obj_IsCached[15],
                                     const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score)
{
  emxArray_real32_T *X;
  float *score_data;
  int i;
  if (Xin->size[0] == 0) {
    score->size[0] = 0;
    score->size[1] = 2;
    labels->size[0] = 0;
  } else {
    int loop_ub;
    emxInit_real32_T(&X, 2);
    d_table2PredictMatrix(Xin, X);
    i = score->size[0] * score->size[1];
    score->size[0] = X->size[0];
    score->size[1] = 2;
    emxEnsureCapacity_real32_T(score, i);
    score_data = score->data;
    loop_ub = X->size[0] << 1;
    for (i = 0; i < loop_ub; i++) {
      score_data[i] = 0.0F;
    }
    d_CompactEnsemble_ensemblePredi(obj_IsCached, X, score);
    emxFree_real32_T(&X);
    c_CompactClassificationModel_ma(obj_Prior, score, labels);
  }
}

/*
 * Arguments    : const float obj_Prior[2]
 *                const emxArray_real32_T *Xin
 *                emxArray_real32_T *labels
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void j_CompactClassificationEnsemble(const float obj_Prior[2],
                                     const emxArray_real32_T *Xin,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *score)
{
  emxArray_real32_T *X;
  float *score_data;
  int i;
  if (Xin->size[0] == 0) {
    score->size[0] = 0;
    score->size[1] = 2;
    labels->size[0] = 0;
  } else {
    int loop_ub;
    emxInit_real32_T(&X, 2);
    e_table2PredictMatrix(Xin, X);
    i = score->size[0] * score->size[1];
    score->size[0] = X->size[0];
    score->size[1] = 2;
    emxEnsureCapacity_real32_T(score, i);
    score_data = score->data;
    loop_ub = X->size[0] << 1;
    for (i = 0; i < loop_ub; i++) {
      score_data[i] = 0.0F;
    }
    e_CompactEnsemble_ensemblePredi(X, score);
    emxFree_real32_T(&X);
    c_CompactClassificationModel_ma(obj_Prior, score, labels);
  }
}

/*
 * File trailer for CompactClassificationEnsemble.c
 *
 * [EOF]
 */
