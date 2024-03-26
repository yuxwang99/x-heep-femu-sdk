/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: aggregatePredict.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "aggregatePredict.h"
#include "CompactClassificationTree.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_internal_types.h"
#include "INCLASS_iterative_test_single_types.h"
#include "predictOneWithCache.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const char cv[15] = {'W', 'e', 'i', 'g', 'h', 't', 'e', 'd',
                            'A', 'v', 'e', 'r', 'a', 'g', 'e'};

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *score
 *                const boolean_T learners[5]
 *                const emxArray_boolean_T *useObsForLearner
 * Return Type  : void
 */
void aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                      const boolean_T learners[5],
                      const emxArray_boolean_T *useObsForLearner)
{
  c_classreg_learning_classif_Com expl_temp;
  d_classreg_learning_classif_Com b_expl_temp;
  e_classreg_learning_classif_Com c_expl_temp;
  emxArray_boolean_T *b_useObsForLearner;
  emxArray_real32_T *cachedScore;
  emxArray_real32_T *cachedWeights;
  f_classreg_learning_classif_Com e_expl_temp;
  g_classreg_learning_classif_Com d_expl_temp;
  float *cachedScore_data;
  float *score_data;
  int i;
  int loop_ub;
  const boolean_T *useObsForLearner_data;
  boolean_T firstCache;
  boolean_T initCache;
  boolean_T *b_useObsForLearner_data;
  useObsForLearner_data = useObsForLearner->data;
  score_data = score->data;
  emxInit_real32_T(&cachedScore, 2);
  i = cachedScore->size[0] * cachedScore->size[1];
  cachedScore->size[0] = score->size[0];
  cachedScore->size[1] = 2;
  emxEnsureCapacity_real32_T(cachedScore, i);
  cachedScore_data = cachedScore->data;
  loop_ub = score->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    cachedScore_data[i] = score_data[i];
  }
  emxInit_real32_T(&cachedWeights, 1);
  i = cachedWeights->size[0];
  cachedWeights->size[0] = score->size[0];
  emxEnsureCapacity_real32_T(cachedWeights, i);
  score_data = cachedWeights->data;
  loop_ub = score->size[0];
  for (i = 0; i < loop_ub; i++) {
    score_data[i] = 0.0F;
  }
  firstCache = true;
  emxInit_boolean_T(&b_useObsForLearner, 1);
  if (learners[0]) {
    firstCache = false;
    c_CompactClassificationTree_Com(&expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i];
    }
    predictOneWithCache(X, cachedScore, cachedWeights, cv,
                        expl_temp.CutPredictorIndex, expl_temp.Children,
                        expl_temp.CutPoint, expl_temp.NanCutPoints,
                        expl_temp.Prior, expl_temp.Cost,
                        expl_temp.ClassProbability, b_useObsForLearner, score);
  }
  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_CompactClassificationTree_Com(&b_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0]];
    }
    b_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, b_expl_temp.CutPredictorIndex,
        b_expl_temp.Children, b_expl_temp.CutPoint, b_expl_temp.NanCutPoints,
        b_expl_temp.Prior, b_expl_temp.Cost, b_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_CompactClassificationTree_Com(&c_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 2];
    }
    c_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, c_expl_temp.CutPredictorIndex,
        c_expl_temp.Children, c_expl_temp.CutPoint, c_expl_temp.NanCutPoints,
        c_expl_temp.Prior, c_expl_temp.Cost, c_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    f_CompactClassificationTree_Com(&e_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 3];
    }
    d_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, e_expl_temp.CutPredictorIndex,
        e_expl_temp.Children, e_expl_temp.CutPoint, e_expl_temp.NanCutPoints,
        e_expl_temp.Prior, e_expl_temp.Cost, e_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[4]) {
    g_CompactClassificationTree_Com(&d_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 4];
    }
    e_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, d_expl_temp.CutPredictorIndex,
        d_expl_temp.Children, d_expl_temp.CutPoint, d_expl_temp.NanCutPoints,
        d_expl_temp.Prior, d_expl_temp.Cost, d_expl_temp.ClassProbability,
        b_useObsForLearner, firstCache, score);
  }
  emxFree_boolean_T(&b_useObsForLearner);
  emxFree_real32_T(&cachedWeights);
  emxFree_real32_T(&cachedScore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *score
 *                const boolean_T isCached[15]
 *                const boolean_T learners[15]
 *                const emxArray_boolean_T *useObsForLearner
 * Return Type  : void
 */
void b_aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                        const boolean_T isCached[15],
                        const boolean_T learners[15],
                        const emxArray_boolean_T *useObsForLearner)
{
  static h_classreg_learning_classif_Com expl_temp;
  static j_classreg_learning_classif_Com c_expl_temp;
  static n_classreg_learning_classif_Com g_expl_temp;
  static o_classreg_learning_classif_Com h_expl_temp;
  static p_classreg_learning_classif_Com i_expl_temp;
  static q_classreg_learning_classif_Com j_expl_temp;
  static r_classreg_learning_classif_Com k_expl_temp;
  static s_classreg_learning_classif_Com l_expl_temp;
  static t_classreg_learning_classif_Com m_expl_temp;
  static u_classreg_learning_classif_Com o_expl_temp;
  emxArray_boolean_T *b_useObsForLearner;
  emxArray_real32_T *cachedScore;
  emxArray_real32_T *cachedWeights;
  i_classreg_learning_classif_Com b_expl_temp;
  k_classreg_learning_classif_Com d_expl_temp;
  l_classreg_learning_classif_Com e_expl_temp;
  m_classreg_learning_classif_Com f_expl_temp;
  v_classreg_learning_classif_Com n_expl_temp;
  float *cachedScore_data;
  float *score_data;
  int i;
  int loop_ub;
  const boolean_T *useObsForLearner_data;
  boolean_T b;
  boolean_T firstCache;
  boolean_T initCache;
  boolean_T *b_useObsForLearner_data;
  useObsForLearner_data = useObsForLearner->data;
  score_data = score->data;
  emxInit_real32_T(&cachedScore, 2);
  i = cachedScore->size[0] * cachedScore->size[1];
  cachedScore->size[0] = score->size[0];
  cachedScore->size[1] = 2;
  emxEnsureCapacity_real32_T(cachedScore, i);
  cachedScore_data = cachedScore->data;
  loop_ub = score->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    cachedScore_data[i] = score_data[i];
  }
  emxInit_real32_T(&cachedWeights, 1);
  i = cachedWeights->size[0];
  cachedWeights->size[0] = score->size[0];
  emxEnsureCapacity_real32_T(cachedWeights, i);
  score_data = cachedWeights->data;
  loop_ub = score->size[0];
  for (i = 0; i < loop_ub; i++) {
    score_data[i] = 0.0F;
  }
  firstCache = true;
  emxInit_boolean_T(&b_useObsForLearner, 1);
  if (learners[0]) {
    firstCache = false;
    h_CompactClassificationTree_Com(&expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i];
    }
    f_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, expl_temp.CutPredictorIndex,
        expl_temp.Children, expl_temp.CutPoint, expl_temp.NanCutPoints,
        expl_temp.Prior, expl_temp.Cost, expl_temp.ClassProbability,
        b_useObsForLearner, score);
  }
  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    i_CompactClassificationTree_Com(&b_expl_temp);
    b = isCached[1];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0]];
    }
    g_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, b_expl_temp.CutPredictorIndex,
        b_expl_temp.Children, b_expl_temp.CutPoint, b_expl_temp.NanCutPoints,
        b_expl_temp.Prior, b_expl_temp.Cost, b_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    j_CompactClassificationTree_Com(&c_expl_temp);
    b = isCached[2];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 2];
    }
    h_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, c_expl_temp.CutPredictorIndex,
        c_expl_temp.Children, c_expl_temp.CutPoint, c_expl_temp.NanCutPoints,
        c_expl_temp.Prior, c_expl_temp.Cost, c_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    k_CompactClassificationTree_Com(&d_expl_temp);
    b = isCached[3];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 3];
    }
    i_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, d_expl_temp.CutPredictorIndex,
        d_expl_temp.Children, d_expl_temp.CutPoint, d_expl_temp.NanCutPoints,
        d_expl_temp.Prior, d_expl_temp.Cost, d_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    l_CompactClassificationTree_Com(&e_expl_temp);
    b = isCached[4];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 4];
    }
    j_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, e_expl_temp.CutPredictorIndex,
        e_expl_temp.Children, e_expl_temp.CutPoint, e_expl_temp.NanCutPoints,
        e_expl_temp.Prior, e_expl_temp.Cost, e_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    m_CompactClassificationTree_Com(&f_expl_temp);
    b = isCached[5];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 5];
    }
    k_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, f_expl_temp.CutPredictorIndex,
        f_expl_temp.Children, f_expl_temp.CutPoint, f_expl_temp.NanCutPoints,
        f_expl_temp.Prior, f_expl_temp.Cost, f_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    n_CompactClassificationTree_Com(&g_expl_temp);
    b = isCached[6];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 6];
    }
    l_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, g_expl_temp.CutPredictorIndex,
        g_expl_temp.Children, g_expl_temp.CutPoint, g_expl_temp.NanCutPoints,
        g_expl_temp.Prior, g_expl_temp.Cost, g_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    o_CompactClassificationTree_Com(&h_expl_temp);
    b = isCached[7];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 7];
    }
    m_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, h_expl_temp.CutPredictorIndex,
        h_expl_temp.Children, h_expl_temp.CutPoint, h_expl_temp.NanCutPoints,
        h_expl_temp.Prior, h_expl_temp.Cost, h_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    p_CompactClassificationTree_Com(&i_expl_temp);
    b = isCached[8];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 8];
    }
    n_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, i_expl_temp.CutPredictorIndex,
        i_expl_temp.Children, i_expl_temp.CutPoint, i_expl_temp.NanCutPoints,
        i_expl_temp.Prior, i_expl_temp.Cost, i_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    q_CompactClassificationTree_Com(&j_expl_temp);
    b = isCached[9];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 9];
    }
    o_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, j_expl_temp.CutPredictorIndex,
        j_expl_temp.Children, j_expl_temp.CutPoint, j_expl_temp.NanCutPoints,
        j_expl_temp.Prior, j_expl_temp.Cost, j_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    r_CompactClassificationTree_Com(&k_expl_temp);
    b = isCached[10];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 10];
    }
    p_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, k_expl_temp.CutPredictorIndex,
        k_expl_temp.Children, k_expl_temp.CutPoint, k_expl_temp.NanCutPoints,
        k_expl_temp.Prior, k_expl_temp.Cost, k_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    s_CompactClassificationTree_Com(&l_expl_temp);
    b = isCached[11];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 11];
    }
    q_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, l_expl_temp.CutPredictorIndex,
        l_expl_temp.Children, l_expl_temp.CutPoint, l_expl_temp.NanCutPoints,
        l_expl_temp.Prior, l_expl_temp.Cost, l_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    t_CompactClassificationTree_Com(&m_expl_temp);
    b = isCached[12];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 12];
    }
    r_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, m_expl_temp.CutPredictorIndex,
        m_expl_temp.Children, m_expl_temp.CutPoint, m_expl_temp.NanCutPoints,
        m_expl_temp.Prior, m_expl_temp.Cost, m_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    u_CompactClassificationTree_Com(&o_expl_temp);
    b = isCached[13];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 13];
    }
    s_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, o_expl_temp.CutPredictorIndex,
        o_expl_temp.Children, o_expl_temp.CutPoint, o_expl_temp.NanCutPoints,
        o_expl_temp.Prior, o_expl_temp.Cost, o_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[14]) {
    v_CompactClassificationTree_Com(&n_expl_temp);
    b = isCached[14];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 14];
    }
    t_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, n_expl_temp.CutPredictorIndex,
        n_expl_temp.Children, n_expl_temp.CutPoint, n_expl_temp.NanCutPoints,
        n_expl_temp.Prior, n_expl_temp.Cost, n_expl_temp.ClassProbability, &b,
        b_useObsForLearner, firstCache, score);
  }
  emxFree_boolean_T(&b_useObsForLearner);
  emxFree_real32_T(&cachedWeights);
  emxFree_real32_T(&cachedScore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *score
 *                const boolean_T isCached[15]
 *                const boolean_T learners[15]
 *                const emxArray_boolean_T *useObsForLearner
 * Return Type  : void
 */
void c_aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                        const boolean_T isCached[15],
                        const boolean_T learners[15],
                        const emxArray_boolean_T *useObsForLearner)
{
  static ab_classreg_learning_classif_Co d_expl_temp;
  static cb_classreg_learning_classif_Co f_expl_temp;
  static x_classreg_learning_classif_Com b_expl_temp;
  bb_classreg_learning_classif_Co e_expl_temp;
  db_classreg_learning_classif_Co g_expl_temp;
  eb_classreg_learning_classif_Co h_expl_temp;
  emxArray_boolean_T *b_useObsForLearner;
  emxArray_real32_T *cachedScore;
  emxArray_real32_T *cachedWeights;
  fb_classreg_learning_classif_Co i_expl_temp;
  gb_classreg_learning_classif_Co j_expl_temp;
  hb_classreg_learning_classif_Co k_expl_temp;
  ib_classreg_learning_classif_Co l_expl_temp;
  jb_classreg_learning_classif_Co m_expl_temp;
  kb_classreg_learning_classif_Co o_expl_temp;
  lb_classreg_learning_classif_Co n_expl_temp;
  w_classreg_learning_classif_Com expl_temp;
  y_classreg_learning_classif_Com c_expl_temp;
  float *cachedScore_data;
  float *score_data;
  int i;
  int loop_ub;
  const boolean_T *useObsForLearner_data;
  boolean_T b;
  boolean_T firstCache;
  boolean_T initCache;
  boolean_T *b_useObsForLearner_data;
  useObsForLearner_data = useObsForLearner->data;
  score_data = score->data;
  emxInit_real32_T(&cachedScore, 2);
  i = cachedScore->size[0] * cachedScore->size[1];
  cachedScore->size[0] = score->size[0];
  cachedScore->size[1] = 2;
  emxEnsureCapacity_real32_T(cachedScore, i);
  cachedScore_data = cachedScore->data;
  loop_ub = score->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    cachedScore_data[i] = score_data[i];
  }
  emxInit_real32_T(&cachedWeights, 1);
  i = cachedWeights->size[0];
  cachedWeights->size[0] = score->size[0];
  emxEnsureCapacity_real32_T(cachedWeights, i);
  score_data = cachedWeights->data;
  loop_ub = score->size[0];
  for (i = 0; i < loop_ub; i++) {
    score_data[i] = 0.0F;
  }
  firstCache = true;
  emxInit_boolean_T(&b_useObsForLearner, 1);
  if (learners[0]) {
    firstCache = false;
    w_CompactClassificationTree_Com(&expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i];
    }
    u_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, expl_temp.CutPredictorIndex,
        expl_temp.Children, expl_temp.CutPoint, expl_temp.NanCutPoints,
        expl_temp.Prior, expl_temp.Cost, expl_temp.ClassProbability,
        b_useObsForLearner, score);
  }
  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    x_CompactClassificationTree_Com(&b_expl_temp);
    b = isCached[1];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0]];
    }
    v_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, b_expl_temp.CutPredictorIndex,
        b_expl_temp.Children, b_expl_temp.CutPoint, b_expl_temp.NanCutPoints,
        b_expl_temp.Prior, b_expl_temp.Cost, b_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    y_CompactClassificationTree_Com(&c_expl_temp);
    b = isCached[2];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 2];
    }
    w_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, c_expl_temp.CutPredictorIndex,
        c_expl_temp.Children, c_expl_temp.CutPoint, c_expl_temp.NanCutPoints,
        c_expl_temp.Prior, c_expl_temp.Cost, c_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    ab_CompactClassificationTree_Co(&d_expl_temp);
    b = isCached[3];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 3];
    }
    x_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, d_expl_temp.CutPredictorIndex,
        d_expl_temp.Children, d_expl_temp.CutPoint, d_expl_temp.NanCutPoints,
        d_expl_temp.Prior, d_expl_temp.Cost, d_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    bb_CompactClassificationTree_Co(&e_expl_temp);
    b = isCached[4];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 4];
    }
    y_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, e_expl_temp.CutPredictorIndex,
        e_expl_temp.Children, e_expl_temp.CutPoint, e_expl_temp.NanCutPoints,
        e_expl_temp.Prior, e_expl_temp.Cost, e_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    cb_CompactClassificationTree_Co(&f_expl_temp);
    b = isCached[5];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 5];
    }
    ab_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, f_expl_temp.CutPredictorIndex,
        f_expl_temp.Children, f_expl_temp.CutPoint, f_expl_temp.NanCutPoints,
        f_expl_temp.Prior, f_expl_temp.Cost, f_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    db_CompactClassificationTree_Co(&g_expl_temp);
    b = isCached[6];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 6];
    }
    bb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, g_expl_temp.CutPredictorIndex,
        g_expl_temp.Children, g_expl_temp.CutPoint, g_expl_temp.NanCutPoints,
        g_expl_temp.Prior, g_expl_temp.Cost, g_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    eb_CompactClassificationTree_Co(&h_expl_temp);
    b = isCached[7];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 7];
    }
    cb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, h_expl_temp.CutPredictorIndex,
        h_expl_temp.Children, h_expl_temp.CutPoint, h_expl_temp.NanCutPoints,
        h_expl_temp.Prior, h_expl_temp.Cost, h_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    fb_CompactClassificationTree_Co(&i_expl_temp);
    b = isCached[8];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 8];
    }
    db_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, i_expl_temp.CutPredictorIndex,
        i_expl_temp.Children, i_expl_temp.CutPoint, i_expl_temp.NanCutPoints,
        i_expl_temp.Prior, i_expl_temp.Cost, i_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    gb_CompactClassificationTree_Co(&j_expl_temp);
    b = isCached[9];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 9];
    }
    eb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, j_expl_temp.CutPredictorIndex,
        j_expl_temp.Children, j_expl_temp.CutPoint, j_expl_temp.NanCutPoints,
        j_expl_temp.Prior, j_expl_temp.Cost, j_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    hb_CompactClassificationTree_Co(&k_expl_temp);
    b = isCached[10];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 10];
    }
    fb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, k_expl_temp.CutPredictorIndex,
        k_expl_temp.Children, k_expl_temp.CutPoint, k_expl_temp.NanCutPoints,
        k_expl_temp.Prior, k_expl_temp.Cost, k_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    ib_CompactClassificationTree_Co(&l_expl_temp);
    b = isCached[11];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 11];
    }
    gb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, l_expl_temp.CutPredictorIndex,
        l_expl_temp.Children, l_expl_temp.CutPoint, l_expl_temp.NanCutPoints,
        l_expl_temp.Prior, l_expl_temp.Cost, l_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    jb_CompactClassificationTree_Co(&m_expl_temp);
    b = isCached[12];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 12];
    }
    hb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, m_expl_temp.CutPredictorIndex,
        m_expl_temp.Children, m_expl_temp.CutPoint, m_expl_temp.NanCutPoints,
        m_expl_temp.Prior, m_expl_temp.Cost, m_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    kb_CompactClassificationTree_Co(&o_expl_temp);
    b = isCached[13];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 13];
    }
    ib_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, o_expl_temp.CutPredictorIndex,
        o_expl_temp.Children, o_expl_temp.CutPoint, o_expl_temp.NanCutPoints,
        o_expl_temp.Prior, o_expl_temp.Cost, o_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[14]) {
    lb_CompactClassificationTree_Co(&n_expl_temp);
    b = isCached[14];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 14];
    }
    jb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, n_expl_temp.CutPredictorIndex,
        n_expl_temp.Children, n_expl_temp.CutPoint, n_expl_temp.NanCutPoints,
        n_expl_temp.Prior, n_expl_temp.Cost, n_expl_temp.ClassProbability, &b,
        b_useObsForLearner, firstCache, score);
  }
  emxFree_boolean_T(&b_useObsForLearner);
  emxFree_real32_T(&cachedWeights);
  emxFree_real32_T(&cachedScore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *score
 *                const boolean_T isCached[15]
 *                const boolean_T learners[15]
 *                const emxArray_boolean_T *useObsForLearner
 * Return Type  : void
 */
void d_aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                        const boolean_T isCached[15],
                        const boolean_T learners[15],
                        const emxArray_boolean_T *useObsForLearner)
{
  emxArray_boolean_T *b_useObsForLearner;
  emxArray_real32_T *cachedScore;
  emxArray_real32_T *cachedWeights;
  mb_classreg_learning_classif_Co expl_temp;
  nb_classreg_learning_classif_Co b_expl_temp;
  ob_classreg_learning_classif_Co c_expl_temp;
  pb_classreg_learning_classif_Co d_expl_temp;
  qb_classreg_learning_classif_Co e_expl_temp;
  rb_classreg_learning_classif_Co f_expl_temp;
  sb_classreg_learning_classif_Co g_expl_temp;
  tb_classreg_learning_classif_Co h_expl_temp;
  ub_classreg_learning_classif_Co i_expl_temp;
  vb_classreg_learning_classif_Co j_expl_temp;
  wb_classreg_learning_classif_Co k_expl_temp;
  xb_classreg_learning_classif_Co l_expl_temp;
  yb_classreg_learning_classif_Co m_expl_temp;
  float *cachedScore_data;
  float *score_data;
  int i;
  int loop_ub;
  const boolean_T *useObsForLearner_data;
  boolean_T b;
  boolean_T firstCache;
  boolean_T initCache;
  boolean_T *b_useObsForLearner_data;
  useObsForLearner_data = useObsForLearner->data;
  score_data = score->data;
  emxInit_real32_T(&cachedScore, 2);
  i = cachedScore->size[0] * cachedScore->size[1];
  cachedScore->size[0] = score->size[0];
  cachedScore->size[1] = 2;
  emxEnsureCapacity_real32_T(cachedScore, i);
  cachedScore_data = cachedScore->data;
  loop_ub = score->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    cachedScore_data[i] = score_data[i];
  }
  emxInit_real32_T(&cachedWeights, 1);
  i = cachedWeights->size[0];
  cachedWeights->size[0] = score->size[0];
  emxEnsureCapacity_real32_T(cachedWeights, i);
  score_data = cachedWeights->data;
  loop_ub = score->size[0];
  for (i = 0; i < loop_ub; i++) {
    score_data[i] = 0.0F;
  }
  firstCache = true;
  emxInit_boolean_T(&b_useObsForLearner, 1);
  if (learners[0]) {
    firstCache = false;
    mb_CompactClassificationTree_Co(&expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i];
    }
    kb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, expl_temp.CutPredictorIndex,
        expl_temp.Children, expl_temp.CutPoint, expl_temp.NanCutPoints,
        expl_temp.Prior, expl_temp.Cost, expl_temp.ClassProbability,
        b_useObsForLearner, score);
  }
  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    nb_CompactClassificationTree_Co(&b_expl_temp);
    b = isCached[1];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0]];
    }
    lb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, b_expl_temp.CutPredictorIndex,
        b_expl_temp.Children, b_expl_temp.CutPoint, b_expl_temp.NanCutPoints,
        b_expl_temp.Prior, b_expl_temp.Cost, b_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    ob_CompactClassificationTree_Co(&c_expl_temp);
    b = isCached[2];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 2];
    }
    mb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, c_expl_temp.CutPredictorIndex,
        c_expl_temp.Children, c_expl_temp.CutPoint, c_expl_temp.NanCutPoints,
        c_expl_temp.Prior, c_expl_temp.Cost, c_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    pb_CompactClassificationTree_Co(&d_expl_temp);
    b = isCached[3];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 3];
    }
    nb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, d_expl_temp.CutPredictorIndex,
        d_expl_temp.Children, d_expl_temp.CutPoint, d_expl_temp.NanCutPoints,
        d_expl_temp.Prior, d_expl_temp.Cost, d_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    qb_CompactClassificationTree_Co(&e_expl_temp);
    b = isCached[4];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 4];
    }
    ob_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, e_expl_temp.CutPredictorIndex,
        e_expl_temp.Children, e_expl_temp.CutPoint, e_expl_temp.NanCutPoints,
        e_expl_temp.Prior, e_expl_temp.Cost, e_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    rb_CompactClassificationTree_Co(&f_expl_temp);
    b = isCached[5];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 5];
    }
    pb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, f_expl_temp.CutPredictorIndex,
        f_expl_temp.Children, f_expl_temp.CutPoint, f_expl_temp.NanCutPoints,
        f_expl_temp.Prior, f_expl_temp.Cost, f_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    sb_CompactClassificationTree_Co(&g_expl_temp);
    b = isCached[6];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 6];
    }
    qb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, g_expl_temp.CutPredictorIndex,
        g_expl_temp.Children, g_expl_temp.CutPoint, g_expl_temp.NanCutPoints,
        g_expl_temp.Prior, g_expl_temp.Cost, g_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    tb_CompactClassificationTree_Co(&h_expl_temp);
    b = isCached[7];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 7];
    }
    rb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, h_expl_temp.CutPredictorIndex,
        h_expl_temp.Children, h_expl_temp.CutPoint, h_expl_temp.NanCutPoints,
        h_expl_temp.Prior, h_expl_temp.Cost, h_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    ub_CompactClassificationTree_Co(&i_expl_temp);
    b = isCached[8];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 8];
    }
    sb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, i_expl_temp.CutPredictorIndex,
        i_expl_temp.Children, i_expl_temp.CutPoint, i_expl_temp.NanCutPoints,
        i_expl_temp.Prior, i_expl_temp.Cost, i_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    vb_CompactClassificationTree_Co(&j_expl_temp);
    b = isCached[9];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 9];
    }
    tb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, j_expl_temp.CutPredictorIndex,
        j_expl_temp.Children, j_expl_temp.CutPoint, j_expl_temp.NanCutPoints,
        j_expl_temp.Prior, j_expl_temp.Cost, j_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    wb_CompactClassificationTree_Co(&k_expl_temp);
    b = isCached[10];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 10];
    }
    ub_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, k_expl_temp.CutPredictorIndex,
        k_expl_temp.Children, k_expl_temp.CutPoint, k_expl_temp.NanCutPoints,
        k_expl_temp.Prior, k_expl_temp.Cost, k_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    xb_CompactClassificationTree_Co(&i_expl_temp);
    b = isCached[11];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 11];
    }
    sb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, i_expl_temp.CutPredictorIndex,
        i_expl_temp.Children, i_expl_temp.CutPoint, i_expl_temp.NanCutPoints,
        i_expl_temp.Prior, i_expl_temp.Cost, i_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    yb_CompactClassificationTree_Co(&l_expl_temp);
    b = isCached[12];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 12];
    }
    vb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, l_expl_temp.CutPredictorIndex,
        l_expl_temp.Children, l_expl_temp.CutPoint, l_expl_temp.NanCutPoints,
        l_expl_temp.Prior, l_expl_temp.Cost, l_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    ac_CompactClassificationTree_Co(&m_expl_temp);
    b = isCached[13];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 13];
    }
    wb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, m_expl_temp.CutPredictorIndex,
        m_expl_temp.Children, m_expl_temp.CutPoint, m_expl_temp.NanCutPoints,
        m_expl_temp.Prior, m_expl_temp.Cost, m_expl_temp.ClassProbability, &b,
        b_useObsForLearner, initCache, score);
  }
  if (learners[14]) {
    bc_CompactClassificationTree_Co(&d_expl_temp);
    b = isCached[14];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 14];
    }
    nb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, d_expl_temp.CutPredictorIndex,
        d_expl_temp.Children, d_expl_temp.CutPoint, d_expl_temp.NanCutPoints,
        d_expl_temp.Prior, d_expl_temp.Cost, d_expl_temp.ClassProbability, &b,
        b_useObsForLearner, firstCache, score);
  }
  emxFree_boolean_T(&b_useObsForLearner);
  emxFree_real32_T(&cachedWeights);
  emxFree_real32_T(&cachedScore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *score
 *                const boolean_T learners[10]
 *                const emxArray_boolean_T *useObsForLearner
 * Return Type  : void
 */
void e_aggregatePredict(const emxArray_real32_T *X, emxArray_real32_T *score,
                        const boolean_T learners[10],
                        const emxArray_boolean_T *useObsForLearner)
{
  ac_classreg_learning_classif_Co b_expl_temp;
  bc_classreg_learning_classif_Co c_expl_temp;
  cc_classreg_learning_classif_Co g_expl_temp;
  dc_classreg_learning_classif_Co j_expl_temp;
  ec_classreg_learning_classif_Co i_expl_temp;
  emxArray_boolean_T *b_useObsForLearner;
  emxArray_real32_T *cachedScore;
  emxArray_real32_T *cachedWeights;
  nb_classreg_learning_classif_Co e_expl_temp;
  pb_classreg_learning_classif_Co expl_temp;
  qb_classreg_learning_classif_Co d_expl_temp;
  rb_classreg_learning_classif_Co h_expl_temp;
  vb_classreg_learning_classif_Co f_expl_temp;
  float *cachedScore_data;
  float *score_data;
  int i;
  int loop_ub;
  const boolean_T *useObsForLearner_data;
  boolean_T firstCache;
  boolean_T initCache;
  boolean_T *b_useObsForLearner_data;
  useObsForLearner_data = useObsForLearner->data;
  score_data = score->data;
  emxInit_real32_T(&cachedScore, 2);
  i = cachedScore->size[0] * cachedScore->size[1];
  cachedScore->size[0] = score->size[0];
  cachedScore->size[1] = 2;
  emxEnsureCapacity_real32_T(cachedScore, i);
  cachedScore_data = cachedScore->data;
  loop_ub = score->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    cachedScore_data[i] = score_data[i];
  }
  emxInit_real32_T(&cachedWeights, 1);
  i = cachedWeights->size[0];
  cachedWeights->size[0] = score->size[0];
  emxEnsureCapacity_real32_T(cachedWeights, i);
  score_data = cachedWeights->data;
  loop_ub = score->size[0];
  for (i = 0; i < loop_ub; i++) {
    score_data[i] = 0.0F;
  }
  firstCache = true;
  emxInit_boolean_T(&b_useObsForLearner, 1);
  if (learners[0]) {
    firstCache = false;
    cc_CompactClassificationTree_Co(&expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i];
    }
    xb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, expl_temp.CutPredictorIndex,
        expl_temp.Children, expl_temp.CutPoint, expl_temp.NanCutPoints,
        expl_temp.Prior, expl_temp.Cost, expl_temp.ClassProbability,
        b_useObsForLearner, score);
  }
  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    dc_CompactClassificationTree_Co(&b_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0]];
    }
    yb_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, b_expl_temp.CutPredictorIndex,
        b_expl_temp.Children, b_expl_temp.CutPoint, b_expl_temp.NanCutPoints,
        b_expl_temp.Prior, b_expl_temp.Cost, b_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    ec_CompactClassificationTree_Co(&c_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 2];
    }
    ac_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, c_expl_temp.CutPredictorIndex,
        c_expl_temp.Children, c_expl_temp.CutPoint, c_expl_temp.NanCutPoints,
        c_expl_temp.Prior, c_expl_temp.Cost, c_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    fc_CompactClassificationTree_Co(&d_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 3];
    }
    bc_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, d_expl_temp.CutPredictorIndex,
        d_expl_temp.Children, d_expl_temp.CutPoint, d_expl_temp.NanCutPoints,
        d_expl_temp.Prior, d_expl_temp.Cost, d_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    gc_CompactClassificationTree_Co(&e_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 4];
    }
    cc_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, e_expl_temp.CutPredictorIndex,
        e_expl_temp.Children, e_expl_temp.CutPoint, e_expl_temp.NanCutPoints,
        e_expl_temp.Prior, e_expl_temp.Cost, e_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    hc_CompactClassificationTree_Co(&f_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 5];
    }
    dc_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, f_expl_temp.CutPredictorIndex,
        f_expl_temp.Children, f_expl_temp.CutPoint, f_expl_temp.NanCutPoints,
        f_expl_temp.Prior, f_expl_temp.Cost, f_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    ic_CompactClassificationTree_Co(&g_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 6];
    }
    ec_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, g_expl_temp.CutPredictorIndex,
        g_expl_temp.Children, g_expl_temp.CutPoint, g_expl_temp.NanCutPoints,
        g_expl_temp.Prior, g_expl_temp.Cost, g_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    jc_CompactClassificationTree_Co(&h_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 7];
    }
    fc_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, h_expl_temp.CutPredictorIndex,
        h_expl_temp.Children, h_expl_temp.CutPoint, h_expl_temp.NanCutPoints,
        h_expl_temp.Prior, h_expl_temp.Cost, h_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    kc_CompactClassificationTree_Co(&j_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 8];
    }
    gc_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, j_expl_temp.CutPredictorIndex,
        j_expl_temp.Children, j_expl_temp.CutPoint, j_expl_temp.NanCutPoints,
        j_expl_temp.Prior, j_expl_temp.Cost, j_expl_temp.ClassProbability,
        b_useObsForLearner, initCache, score);
  }
  if (learners[9]) {
    lc_CompactClassificationTree_Co(&i_expl_temp);
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    b_useObsForLearner_data = b_useObsForLearner->data;
    loop_ub = useObsForLearner->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] =
          useObsForLearner_data[i + useObsForLearner->size[0] * 9];
    }
    hc_predictOneWithCache(
        X, cachedScore, cachedWeights, cv, i_expl_temp.CutPredictorIndex,
        i_expl_temp.Children, i_expl_temp.CutPoint, i_expl_temp.NanCutPoints,
        i_expl_temp.Prior, i_expl_temp.Cost, i_expl_temp.ClassProbability,
        b_useObsForLearner, firstCache, score);
  }
  emxFree_boolean_T(&b_useObsForLearner);
  emxFree_real32_T(&cachedWeights);
  emxFree_real32_T(&cachedScore);
}

/*
 * File trailer for aggregatePredict.c
 *
 * [EOF]
 */
