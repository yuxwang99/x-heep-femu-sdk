/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * aggregatePredict.c
 *
 * Code generation for function 'aggregatePredict'
 *
 */

/* Include files */
#include "aggregatePredict.h"
#include "CompactClassificationTree.h"
#include "predictOneWithCache.h"
#include "profile_Yuxuan_iteration_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static const char cv1[15] = { 'W', 'e', 'i', 'g', 'h', 't', 'e', 'd', 'A', 'v',
  'e', 'r', 'a', 'g', 'e' };

/* Function Definitions */
void aggregatePredict(const double X_data[], const int X_size[2], double
                      score_data[], int score_size[2], const boolean_T isCached
                      [30], const double classNames[2], const boolean_T
                      learners[30], const boolean_T useObsForLearner_data[],
                      const int useObsForLearner_size[2])
{
  static double w_weak_learner_Children[11750];
  static double w_weak_learner_ClassProbability[11750];
  static double o_weak_learner_Children[11650];
  static double o_weak_learner_ClassProbability[11650];
  static double h_weak_learner_Children[11646];
  static double h_weak_learner_ClassProbability[11646];
  static double k_weak_learner_Children[11614];
  static double k_weak_learner_ClassProbability[11614];
  static double n_weak_learner_Children[11570];
  static double n_weak_learner_ClassProbability[11570];
  static double g_weak_learner_Children[11558];
  static double g_weak_learner_ClassProbability[11558];
  static double m_weak_learner_Children[11522];
  static double m_weak_learner_ClassProbability[11522];
  static double e_weak_learner_Children[11510];
  static double e_weak_learner_ClassProbability[11510];
  static double i_weak_learner_Children[11494];
  static double i_weak_learner_ClassProbability[11494];
  static double y_weak_learner_Children[11490];
  static double y_weak_learner_ClassProbability[11490];
  static double weak_learner_Children[11462];
  static double weak_learner_ClassProbability[11462];
  static double q_weak_learner_Children[11454];
  static double q_weak_learner_ClassProbability[11454];
  static double ab_weak_learner_Children[11430];
  static double ab_weak_learner_ClassProbabilit[11430];
  static double u_weak_learner_Children[11426];
  static double u_weak_learner_ClassProbability[11426];
  static double bb_weak_learner_Children[11418];
  static double bb_weak_learner_ClassProbabilit[11418];
  static double p_weak_learner_Children[11402];
  static double p_weak_learner_ClassProbability[11402];
  static double b_weak_learner_Children[11386];
  static double b_weak_learner_ClassProbability[11386];
  static double s_weak_learner_Children[11382];
  static double s_weak_learner_ClassProbability[11382];
  static double r_weak_learner_Children[11378];
  static double r_weak_learner_ClassProbability[11378];
  static double f_weak_learner_Children[11334];
  static double f_weak_learner_ClassProbability[11334];
  static double c_weak_learner_Children[11326];
  static double c_weak_learner_ClassProbability[11326];
  static double l_weak_learner_Children[11318];
  static double l_weak_learner_ClassProbability[11318];
  static double x_weak_learner_Children[11306];
  static double x_weak_learner_ClassProbability[11306];
  static double d_weak_learner_Children[11290];
  static double d_weak_learner_ClassProbability[11290];
  static double t_weak_learner_Children[11246];
  static double t_weak_learner_ClassProbability[11246];
  static double j_weak_learner_Children[11230];
  static double j_weak_learner_ClassProbability[11230];
  static double v_weak_learner_Children[11190];
  static double v_weak_learner_ClassProbability[11190];
  static double w_weak_learner_CutPoint[5875];
  static double w_weak_learner_CutPredictorInde[5875];
  static double o_weak_learner_CutPoint[5825];
  static double o_weak_learner_CutPredictorInde[5825];
  static double h_weak_learner_CutPoint[5823];
  static double h_weak_learner_CutPredictorInde[5823];
  static double k_weak_learner_CutPoint[5807];
  static double k_weak_learner_CutPredictorInde[5807];
  static double n_weak_learner_CutPoint[5785];
  static double n_weak_learner_CutPredictorInde[5785];
  static double g_weak_learner_CutPoint[5779];
  static double g_weak_learner_CutPredictorInde[5779];
  static double m_weak_learner_CutPoint[5761];
  static double m_weak_learner_CutPredictorInde[5761];
  static double e_weak_learner_CutPoint[5755];
  static double e_weak_learner_CutPredictorInde[5755];
  static double i_weak_learner_CutPoint[5747];
  static double i_weak_learner_CutPredictorInde[5747];
  static double y_weak_learner_CutPoint[5745];
  static double y_weak_learner_CutPredictorInde[5745];
  static double weak_learner_CutPoint[5731];
  static double weak_learner_CutPredictorIndex[5731];
  static double q_weak_learner_CutPoint[5727];
  static double q_weak_learner_CutPredictorInde[5727];
  static double ab_weak_learner_CutPoint[5715];
  static double ab_weak_learner_CutPredictorInd[5715];
  static double u_weak_learner_CutPoint[5713];
  static double u_weak_learner_CutPredictorInde[5713];
  static double bb_weak_learner_CutPoint[5709];
  static double bb_weak_learner_CutPredictorInd[5709];
  static double p_weak_learner_CutPoint[5701];
  static double p_weak_learner_CutPredictorInde[5701];
  static double b_weak_learner_CutPoint[5693];
  static double b_weak_learner_CutPredictorInde[5693];
  static double s_weak_learner_CutPoint[5691];
  static double s_weak_learner_CutPredictorInde[5691];
  static double r_weak_learner_CutPoint[5689];
  static double r_weak_learner_CutPredictorInde[5689];
  static double f_weak_learner_CutPoint[5667];
  static double f_weak_learner_CutPredictorInde[5667];
  static double c_weak_learner_CutPoint[5663];
  static double c_weak_learner_CutPredictorInde[5663];
  static double l_weak_learner_CutPoint[5659];
  static double l_weak_learner_CutPredictorInde[5659];
  static double x_weak_learner_CutPoint[5653];
  static double x_weak_learner_CutPredictorInde[5653];
  static double d_weak_learner_CutPoint[5645];
  static double d_weak_learner_CutPredictorInde[5645];
  static double t_weak_learner_CutPoint[5623];
  static double t_weak_learner_CutPredictorInde[5623];
  static double j_weak_learner_CutPoint[5615];
  static double j_weak_learner_CutPredictorInde[5615];
  static double v_weak_learner_CutPoint[5595];
  static double v_weak_learner_CutPredictorInde[5595];
  static double cachedScore_data[800];
  static double cachedWeights_data[400];
  static boolean_T ab_expl_temp[5875];
  static boolean_T w_weak_learner_NanCutPoints[5875];
  static boolean_T o_weak_learner_NanCutPoints[5825];
  static boolean_T r_expl_temp[5825];
  static boolean_T h_weak_learner_NanCutPoints[5823];
  static boolean_T k_expl_temp[5823];
  static boolean_T k_weak_learner_NanCutPoints[5807];
  static boolean_T n_expl_temp[5807];
  static boolean_T n_weak_learner_NanCutPoints[5785];
  static boolean_T q_expl_temp[5785];
  static boolean_T g_weak_learner_NanCutPoints[5779];
  static boolean_T j_expl_temp[5779];
  static boolean_T m_weak_learner_NanCutPoints[5761];
  static boolean_T p_expl_temp[5761];
  static boolean_T e_weak_learner_NanCutPoints[5755];
  static boolean_T h_expl_temp[5755];
  static boolean_T i_weak_learner_NanCutPoints[5747];
  static boolean_T l_expl_temp[5747];
  static boolean_T cb_expl_temp[5745];
  static boolean_T y_weak_learner_NanCutPoints[5745];
  static boolean_T expl_temp[5731];
  static boolean_T weak_learner_NanCutPoints[5731];
  static boolean_T q_weak_learner_NanCutPoints[5727];
  static boolean_T t_expl_temp[5727];
  static boolean_T ab_weak_learner_NanCutPoints[5715];
  static boolean_T db_expl_temp[5715];
  static boolean_T u_weak_learner_NanCutPoints[5713];
  static boolean_T x_expl_temp[5713];
  static boolean_T bb_weak_learner_NanCutPoints[5709];
  static boolean_T eb_expl_temp[5709];
  static boolean_T p_weak_learner_NanCutPoints[5701];
  static boolean_T s_expl_temp[5701];
  static boolean_T b_weak_learner_NanCutPoints[5693];
  static boolean_T e_expl_temp[5693];
  static boolean_T s_weak_learner_NanCutPoints[5691];
  static boolean_T v_expl_temp[5691];
  static boolean_T r_weak_learner_NanCutPoints[5689];
  static boolean_T u_expl_temp[5689];
  static boolean_T f_weak_learner_NanCutPoints[5667];
  static boolean_T i_expl_temp[5667];
  static boolean_T c_weak_learner_NanCutPoints[5663];
  static boolean_T f_expl_temp[5663];
  static boolean_T l_weak_learner_NanCutPoints[5659];
  static boolean_T o_expl_temp[5659];
  static boolean_T bb_expl_temp[5653];
  static boolean_T x_weak_learner_NanCutPoints[5653];
  static boolean_T d_weak_learner_NanCutPoints[5645];
  static boolean_T g_expl_temp[5645];
  static boolean_T t_weak_learner_NanCutPoints[5623];
  static boolean_T w_expl_temp[5623];
  static boolean_T j_weak_learner_NanCutPoints[5615];
  static boolean_T m_expl_temp[5615];
  static boolean_T v_weak_learner_NanCutPoints[5595];
  static boolean_T y_expl_temp[5595];
  double weak_learner_Cost[4];
  double weak_learner_ClassNames[2];
  double weak_learner_Prior[2];
  int b_expl_temp[2];
  int cachedScore_size[2];
  int b_useObsForLearner_size[1];
  int i;
  int loop_ub;
  boolean_T b_useObsForLearner_data[400];
  boolean_T d_expl_temp[2];
  boolean_T b;
  boolean_T firstCache;
  boolean_T initCache;
  c_classreg_learning_coderutils_ c_expl_temp;
  cachedScore_size[0] = score_size[0];
  cachedScore_size[1] = 2;
  loop_ub = score_size[0] * score_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&cachedScore_data[0], &score_data[0], loop_ub * sizeof(double));
  }

  loop_ub = score_size[0];
  if (0 <= loop_ub - 1) {
    memset(&cachedWeights_data[0], 0, loop_ub * sizeof(double));
  }

  firstCache = true;
  if (learners[0]) {
    firstCache = false;
    c_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp,
      weak_learner_Prior, d_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    b = false;
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&b_useObsForLearner_data[0], &useObsForLearner_data[0], loop_ub *
             sizeof(boolean_T));
    }

    predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                        cachedWeights_data, cv1, weak_learner_CutPredictorIndex,
                        weak_learner_Children, weak_learner_CutPoint,
                        weak_learner_NanCutPoints, weak_learner_ClassNames,
                        weak_learner_Prior, weak_learner_Cost,
                        weak_learner_ClassProbability, &b, classNames,
                        b_useObsForLearner_data, b_useObsForLearner_size, true,
                        score_data, score_size);
  }

  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    d_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp,
      weak_learner_Prior, d_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    b = isCached[1];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0]];
    }

    predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                        cachedWeights_data, cv1, weak_learner_CutPredictorIndex,
                        weak_learner_Children, weak_learner_CutPoint,
                        weak_learner_NanCutPoints, weak_learner_ClassNames,
                        weak_learner_Prior, weak_learner_Cost,
                        weak_learner_ClassProbability, &b, classNames,
                        b_useObsForLearner_data, b_useObsForLearner_size,
                        initCache, score_data, score_size);
  }

  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    e_CompactClassificationTree_Com(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, e_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[2];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 2];
    }

    b_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          b_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    f_CompactClassificationTree_Com(c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, f_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, c_weak_learner_ClassProbability);
    b = isCached[3];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 3];
    }

    c_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          c_weak_learner_CutPredictorInde,
                          c_weak_learner_Children, c_weak_learner_CutPoint,
                          c_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          c_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    g_CompactClassificationTree_Com(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, g_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[4];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 4];
    }

    d_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          d_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    h_CompactClassificationTree_Com(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, h_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[5];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 5];
    }

    e_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          e_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    i_CompactClassificationTree_Com(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, i_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[6];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 6];
    }

    f_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          f_weak_learner_CutPredictorInde,
                          f_weak_learner_Children, f_weak_learner_CutPoint,
                          f_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          f_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    j_CompactClassificationTree_Com(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, j_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[7];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 7];
    }

    g_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          g_weak_learner_CutPredictorInde,
                          g_weak_learner_Children, g_weak_learner_CutPoint,
                          g_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          g_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    k_CompactClassificationTree_Com(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, k_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[8];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 8];
    }

    h_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          h_weak_learner_CutPredictorInde,
                          h_weak_learner_Children, h_weak_learner_CutPoint,
                          h_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          h_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    l_CompactClassificationTree_Com(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, l_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[9];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 9];
    }

    i_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          i_weak_learner_CutPredictorInde,
                          i_weak_learner_Children, i_weak_learner_CutPoint,
                          i_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          i_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    m_CompactClassificationTree_Com(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, m_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[10];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 10];
    }

    j_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          j_weak_learner_CutPredictorInde,
                          j_weak_learner_Children, j_weak_learner_CutPoint,
                          j_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          j_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    n_CompactClassificationTree_Com(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, n_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[11];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 11];
    }

    k_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          k_weak_learner_CutPredictorInde,
                          k_weak_learner_Children, k_weak_learner_CutPoint,
                          k_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          k_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    o_CompactClassificationTree_Com(l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, o_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, l_weak_learner_ClassProbability);
    b = isCached[12];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 12];
    }

    l_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          l_weak_learner_CutPredictorInde,
                          l_weak_learner_Children, l_weak_learner_CutPoint,
                          l_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          l_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    p_CompactClassificationTree_Com(m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, p_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, m_weak_learner_ClassProbability);
    b = isCached[13];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 13];
    }

    m_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          m_weak_learner_CutPredictorInde,
                          m_weak_learner_Children, m_weak_learner_CutPoint,
                          m_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          m_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[14]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    q_CompactClassificationTree_Com(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, q_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[14];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 14];
    }

    n_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          n_weak_learner_CutPredictorInde,
                          n_weak_learner_Children, n_weak_learner_CutPoint,
                          n_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          n_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[15]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    r_CompactClassificationTree_Com(o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, r_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, o_weak_learner_ClassProbability);
    b = isCached[15];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 15];
    }

    o_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          o_weak_learner_CutPredictorInde,
                          o_weak_learner_Children, o_weak_learner_CutPoint,
                          o_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          o_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[16]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    s_CompactClassificationTree_Com(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, s_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[16];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 16];
    }

    p_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          p_weak_learner_CutPredictorInde,
                          p_weak_learner_Children, p_weak_learner_CutPoint,
                          p_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          p_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[17]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    t_CompactClassificationTree_Com(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, t_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[17];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 17];
    }

    q_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          q_weak_learner_CutPredictorInde,
                          q_weak_learner_Children, q_weak_learner_CutPoint,
                          q_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          q_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[18]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    u_CompactClassificationTree_Com(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, u_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[18];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 18];
    }

    r_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          r_weak_learner_CutPredictorInde,
                          r_weak_learner_Children, r_weak_learner_CutPoint,
                          r_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          r_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[19]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    v_CompactClassificationTree_Com(s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, v_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, s_weak_learner_ClassProbability);
    b = isCached[19];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 19];
    }

    s_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          s_weak_learner_CutPredictorInde,
                          s_weak_learner_Children, s_weak_learner_CutPoint,
                          s_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          s_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[20]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    w_CompactClassificationTree_Com(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, q_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[20];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 20];
    }

    n_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          n_weak_learner_CutPredictorInde,
                          n_weak_learner_Children, n_weak_learner_CutPoint,
                          n_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          n_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[21]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    x_CompactClassificationTree_Com(t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, w_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, t_weak_learner_ClassProbability);
    b = isCached[21];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 21];
    }

    t_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          t_weak_learner_CutPredictorInde,
                          t_weak_learner_Children, t_weak_learner_CutPoint,
                          t_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          t_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[22]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    y_CompactClassificationTree_Com(u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, x_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, u_weak_learner_ClassProbability);
    b = isCached[22];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 22];
    }

    u_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          u_weak_learner_CutPredictorInde,
                          u_weak_learner_Children, u_weak_learner_CutPoint,
                          u_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          u_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[23]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ab_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, y_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[23];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 23];
    }

    v_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          v_weak_learner_CutPredictorInde,
                          v_weak_learner_Children, v_weak_learner_CutPoint,
                          v_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          v_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[24]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bb_CompactClassificationTree_Co(w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, ab_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, w_weak_learner_ClassProbability);
    b = isCached[24];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 24];
    }

    w_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          w_weak_learner_CutPredictorInde,
                          w_weak_learner_Children, w_weak_learner_CutPoint,
                          w_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          w_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[25]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    cb_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, bb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[25];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 25];
    }

    x_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          x_weak_learner_CutPredictorInde,
                          x_weak_learner_Children, x_weak_learner_CutPoint,
                          x_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          x_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[26]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    db_CompactClassificationTree_Co(y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, cb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, y_weak_learner_ClassProbability);
    b = isCached[26];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 26];
    }

    y_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          y_weak_learner_CutPredictorInde,
                          y_weak_learner_Children, y_weak_learner_CutPoint,
                          y_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          y_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[27]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    eb_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, db_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit);
    b = isCached[27];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 27];
    }

    ab_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[28]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fb_CompactClassificationTree_Co(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, u_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[28];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 28];
    }

    r_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
                          cachedWeights_data, cv1,
                          r_weak_learner_CutPredictorInde,
                          r_weak_learner_Children, r_weak_learner_CutPoint,
                          r_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_Prior, weak_learner_Cost,
                          r_weak_learner_ClassProbability, &b, classNames,
                          b_useObsForLearner_data, b_useObsForLearner_size,
                          initCache, score_data, score_size);
  }

  if (learners[29]) {
    gb_CompactClassificationTree_Co(bb_weak_learner_CutPredictorInd,
      bb_weak_learner_Children, bb_weak_learner_CutPoint,
      bb_weak_learner_NanCutPoints, eb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, bb_weak_learner_ClassProbabilit);
    b = isCached[29];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 29];
    }

    bb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, bb_weak_learner_CutPredictorInd,
      bb_weak_learner_Children, bb_weak_learner_CutPoint,
      bb_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, bb_weak_learner_ClassProbabilit, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, firstCache, score_data,
      score_size);
  }
}

void b_aggregatePredict(const double X_data[], const int X_size[2], double
  score_data[], int score_size[2], const boolean_T isCached[30], const double
  classNames[2], const boolean_T learners[30], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[2])
{
  static double i_weak_learner_Children[5922];
  static double i_weak_learner_ClassProbability[5922];
  static double w_weak_learner_Children[5810];
  static double w_weak_learner_ClassProbability[5810];
  static double u_weak_learner_Children[5770];
  static double u_weak_learner_ClassProbability[5770];
  static double j_weak_learner_Children[5742];
  static double j_weak_learner_ClassProbability[5742];
  static double g_weak_learner_Children[5714];
  static double g_weak_learner_ClassProbability[5714];
  static double r_weak_learner_Children[5702];
  static double r_weak_learner_ClassProbability[5702];
  static double o_weak_learner_Children[5686];
  static double o_weak_learner_ClassProbability[5686];
  static double k_weak_learner_Children[5654];
  static double k_weak_learner_ClassProbability[5654];
  static double s_weak_learner_Children[5650];
  static double s_weak_learner_ClassProbability[5650];
  static double t_weak_learner_Children[5642];
  static double t_weak_learner_ClassProbability[5642];
  static double l_weak_learner_Children[5622];
  static double l_weak_learner_ClassProbability[5622];
  static double h_weak_learner_Children[5610];
  static double h_weak_learner_ClassProbability[5610];
  static double weak_learner_Children[5602];
  static double weak_learner_ClassProbability[5602];
  static double b_weak_learner_Children[5566];
  static double b_weak_learner_ClassProbability[5566];
  static double e_weak_learner_Children[5550];
  static double e_weak_learner_ClassProbability[5550];
  static double v_weak_learner_Children[5522];
  static double v_weak_learner_ClassProbability[5522];
  static double n_weak_learner_Children[5510];
  static double n_weak_learner_ClassProbability[5510];
  static double m_weak_learner_Children[5506];
  static double m_weak_learner_ClassProbability[5506];
  static double x_weak_learner_Children[5486];
  static double x_weak_learner_ClassProbability[5486];
  static double q_weak_learner_Children[5474];
  static double q_weak_learner_ClassProbability[5474];
  static double c_weak_learner_Children[5430];
  static double c_weak_learner_ClassProbability[5430];
  static double d_weak_learner_Children[5418];
  static double d_weak_learner_ClassProbability[5418];
  static double f_weak_learner_Children[5390];
  static double f_weak_learner_ClassProbability[5390];
  static double p_weak_learner_Children[5374];
  static double p_weak_learner_ClassProbability[5374];
  static double i_weak_learner_CutPoint[2961];
  static double i_weak_learner_CutPredictorInde[2961];
  static double w_weak_learner_CutPoint[2905];
  static double w_weak_learner_CutPredictorInde[2905];
  static double u_weak_learner_CutPoint[2885];
  static double u_weak_learner_CutPredictorInde[2885];
  static double j_weak_learner_CutPoint[2871];
  static double j_weak_learner_CutPredictorInde[2871];
  static double g_weak_learner_CutPoint[2857];
  static double g_weak_learner_CutPredictorInde[2857];
  static double r_weak_learner_CutPoint[2851];
  static double r_weak_learner_CutPredictorInde[2851];
  static double o_weak_learner_CutPoint[2843];
  static double o_weak_learner_CutPredictorInde[2843];
  static double k_weak_learner_CutPoint[2827];
  static double k_weak_learner_CutPredictorInde[2827];
  static double s_weak_learner_CutPoint[2825];
  static double s_weak_learner_CutPredictorInde[2825];
  static double t_weak_learner_CutPoint[2821];
  static double t_weak_learner_CutPredictorInde[2821];
  static double l_weak_learner_CutPoint[2811];
  static double l_weak_learner_CutPredictorInde[2811];
  static double h_weak_learner_CutPoint[2805];
  static double h_weak_learner_CutPredictorInde[2805];
  static double weak_learner_CutPoint[2801];
  static double weak_learner_CutPredictorIndex[2801];
  static double b_weak_learner_CutPoint[2783];
  static double b_weak_learner_CutPredictorInde[2783];
  static double e_weak_learner_CutPoint[2775];
  static double e_weak_learner_CutPredictorInde[2775];
  static double v_weak_learner_CutPoint[2761];
  static double v_weak_learner_CutPredictorInde[2761];
  static double n_weak_learner_CutPoint[2755];
  static double n_weak_learner_CutPredictorInde[2755];
  static double m_weak_learner_CutPoint[2753];
  static double m_weak_learner_CutPredictorInde[2753];
  static double x_weak_learner_CutPoint[2743];
  static double x_weak_learner_CutPredictorInde[2743];
  static double q_weak_learner_CutPoint[2737];
  static double q_weak_learner_CutPredictorInde[2737];
  static double c_weak_learner_CutPoint[2715];
  static double c_weak_learner_CutPredictorInde[2715];
  static double d_weak_learner_CutPoint[2709];
  static double d_weak_learner_CutPredictorInde[2709];
  static double f_weak_learner_CutPoint[2695];
  static double f_weak_learner_CutPredictorInde[2695];
  static double p_weak_learner_CutPoint[2687];
  static double p_weak_learner_CutPredictorInde[2687];
  static double cachedScore_data[800];
  static double cachedWeights_data[400];
  static boolean_T i_weak_learner_NanCutPoints[2961];
  static boolean_T l_expl_temp[2961];
  static boolean_T ab_expl_temp[2905];
  static boolean_T w_weak_learner_NanCutPoints[2905];
  static boolean_T u_weak_learner_NanCutPoints[2885];
  static boolean_T x_expl_temp[2885];
  static boolean_T j_weak_learner_NanCutPoints[2871];
  static boolean_T m_expl_temp[2871];
  static boolean_T g_weak_learner_NanCutPoints[2857];
  static boolean_T j_expl_temp[2857];
  static boolean_T r_weak_learner_NanCutPoints[2851];
  static boolean_T u_expl_temp[2851];
  static boolean_T o_weak_learner_NanCutPoints[2843];
  static boolean_T r_expl_temp[2843];
  static boolean_T k_weak_learner_NanCutPoints[2827];
  static boolean_T n_expl_temp[2827];
  static boolean_T s_weak_learner_NanCutPoints[2825];
  static boolean_T v_expl_temp[2825];
  static boolean_T t_weak_learner_NanCutPoints[2821];
  static boolean_T w_expl_temp[2821];
  static boolean_T l_weak_learner_NanCutPoints[2811];
  static boolean_T o_expl_temp[2811];
  static boolean_T h_weak_learner_NanCutPoints[2805];
  static boolean_T k_expl_temp[2805];
  static boolean_T expl_temp[2801];
  static boolean_T weak_learner_NanCutPoints[2801];
  static boolean_T b_weak_learner_NanCutPoints[2783];
  static boolean_T e_expl_temp[2783];
  static boolean_T e_weak_learner_NanCutPoints[2775];
  static boolean_T h_expl_temp[2775];
  static boolean_T v_weak_learner_NanCutPoints[2761];
  static boolean_T y_expl_temp[2761];
  static boolean_T n_weak_learner_NanCutPoints[2755];
  static boolean_T q_expl_temp[2755];
  static boolean_T m_weak_learner_NanCutPoints[2753];
  static boolean_T p_expl_temp[2753];
  static boolean_T bb_expl_temp[2743];
  static boolean_T x_weak_learner_NanCutPoints[2743];
  static boolean_T q_weak_learner_NanCutPoints[2737];
  static boolean_T t_expl_temp[2737];
  static boolean_T c_weak_learner_NanCutPoints[2715];
  static boolean_T f_expl_temp[2715];
  static boolean_T d_weak_learner_NanCutPoints[2709];
  static boolean_T g_expl_temp[2709];
  static boolean_T f_weak_learner_NanCutPoints[2695];
  static boolean_T i_expl_temp[2695];
  static boolean_T p_weak_learner_NanCutPoints[2687];
  static boolean_T s_expl_temp[2687];
  double weak_learner_Cost[4];
  double weak_learner_ClassNames[2];
  double weak_learner_Prior[2];
  int b_expl_temp[2];
  int cachedScore_size[2];
  int b_useObsForLearner_size[1];
  int i;
  int loop_ub;
  boolean_T b_useObsForLearner_data[400];
  boolean_T d_expl_temp[2];
  boolean_T b;
  boolean_T firstCache;
  boolean_T initCache;
  c_classreg_learning_coderutils_ c_expl_temp;
  cachedScore_size[0] = score_size[0];
  cachedScore_size[1] = 2;
  loop_ub = score_size[0] * score_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&cachedScore_data[0], &score_data[0], loop_ub * sizeof(double));
  }

  loop_ub = score_size[0];
  if (0 <= loop_ub - 1) {
    memset(&cachedWeights_data[0], 0, loop_ub * sizeof(double));
  }

  firstCache = true;
  if (learners[0]) {
    firstCache = false;
    hb_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp,
      weak_learner_Prior, d_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    b = false;
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&b_useObsForLearner_data[0], &useObsForLearner_data[0], loop_ub *
             sizeof(boolean_T));
    }

    cb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, &b, classNames, b_useObsForLearner_data,
      b_useObsForLearner_size, score_data, score_size);
  }

  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ib_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, e_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[1];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0]];
    }

    db_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, b_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jb_CompactClassificationTree_Co(c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, f_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, c_weak_learner_ClassProbability);
    b = isCached[2];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 2];
    }

    eb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, c_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kb_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, g_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[3];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 3];
    }

    fb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, d_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    lb_CompactClassificationTree_Co(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, h_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[4];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 4];
    }

    gb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, e_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    mb_CompactClassificationTree_Co(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, i_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[5];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 5];
    }

    hb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, f_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    nb_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, j_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[6];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 6];
    }

    ib_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, g_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ob_CompactClassificationTree_Co(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, k_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[7];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 7];
    }

    jb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, h_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pb_CompactClassificationTree_Co(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, l_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[8];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 8];
    }

    kb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, i_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qb_CompactClassificationTree_Co(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, m_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[9];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 9];
    }

    lb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, j_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    rb_CompactClassificationTree_Co(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, n_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[10];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 10];
    }

    mb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, k_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sb_CompactClassificationTree_Co(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, i_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[11];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 11];
    }

    hb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, f_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    tb_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, j_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[12];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 12];
    }

    ib_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, g_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ub_CompactClassificationTree_Co(l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, o_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, l_weak_learner_ClassProbability);
    b = isCached[13];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 13];
    }

    nb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, l_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[14]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vb_CompactClassificationTree_Co(m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, p_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, m_weak_learner_ClassProbability);
    b = isCached[14];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 14];
    }

    ob_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, m_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[15]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wb_CompactClassificationTree_Co(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, q_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[15];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 15];
    }

    pb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, n_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[16]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xb_CompactClassificationTree_Co(o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, r_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, o_weak_learner_ClassProbability);
    b = isCached[16];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 16];
    }

    qb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, o_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[17]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yb_CompactClassificationTree_Co(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, s_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[17];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 17];
    }

    rb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, p_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[18]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ac_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, t_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[18];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 18];
    }

    sb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, q_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[19]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bc_CompactClassificationTree_Co(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, u_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[19];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 19];
    }

    tb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, r_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[20]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    cc_CompactClassificationTree_Co(s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, v_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, s_weak_learner_ClassProbability);
    b = isCached[20];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 20];
    }

    ub_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, s_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[21]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    dc_CompactClassificationTree_Co(t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, w_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, t_weak_learner_ClassProbability);
    b = isCached[21];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 21];
    }

    vb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, t_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[22]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ec_CompactClassificationTree_Co(l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, o_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, l_weak_learner_ClassProbability);
    b = isCached[22];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 22];
    }

    nb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, l_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[23]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fc_CompactClassificationTree_Co(u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, x_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, u_weak_learner_ClassProbability);
    b = isCached[23];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 23];
    }

    wb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, u_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[24]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    gc_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, j_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[24];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 24];
    }

    ib_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, g_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[25]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    hc_CompactClassificationTree_Co(t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, w_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, t_weak_learner_ClassProbability);
    b = isCached[25];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 25];
    }

    vb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, t_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[26]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ic_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, y_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[26];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 26];
    }

    xb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, v_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[27]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jc_CompactClassificationTree_Co(w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, ab_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, w_weak_learner_ClassProbability);
    b = isCached[27];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 27];
    }

    yb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, w_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[28]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kc_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, bb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[28];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 28];
    }

    ac_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, x_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[29]) {
    lc_CompactClassificationTree_Co(l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, o_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, l_weak_learner_ClassProbability);
    b = isCached[29];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 29];
    }

    nb_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, l_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, firstCache, score_data,
      score_size);
  }
}

void c_aggregatePredict(const double X_data[], const int X_size[2], double
  score_data[], int score_size[2], const boolean_T isCached[30], const double
  classNames[2], const boolean_T learners[30], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[2])
{
  static double weak_learner_Children[1722];
  static double weak_learner_ClassProbability[1722];
  static double l_weak_learner_Children[1642];
  static double l_weak_learner_ClassProbability[1642];
  static double i_weak_learner_Children[1626];
  static double i_weak_learner_ClassProbability[1626];
  static double c_weak_learner_Children[1614];
  static double c_weak_learner_ClassProbability[1614];
  static double o_weak_learner_Children[1594];
  static double o_weak_learner_ClassProbability[1594];
  static double t_weak_learner_Children[1582];
  static double t_weak_learner_ClassProbability[1582];
  static double e_weak_learner_Children[1562];
  static double e_weak_learner_ClassProbability[1562];
  static double h_weak_learner_Children[1558];
  static double h_weak_learner_ClassProbability[1558];
  static double q_weak_learner_Children[1550];
  static double q_weak_learner_ClassProbability[1550];
  static double j_weak_learner_Children[1538];
  static double j_weak_learner_ClassProbability[1538];
  static double d_weak_learner_Children[1530];
  static double d_weak_learner_ClassProbability[1530];
  static double s_weak_learner_Children[1506];
  static double s_weak_learner_ClassProbability[1506];
  static double g_weak_learner_Children[1502];
  static double g_weak_learner_ClassProbability[1502];
  static double w_weak_learner_Children[1494];
  static double w_weak_learner_ClassProbability[1494];
  static double y_weak_learner_Children[1490];
  static double y_weak_learner_ClassProbability[1490];
  static double m_weak_learner_Children[1478];
  static double m_weak_learner_ClassProbability[1478];
  static double x_weak_learner_Children[1454];
  static double x_weak_learner_ClassProbability[1454];
  static double u_weak_learner_Children[1450];
  static double u_weak_learner_ClassProbability[1450];
  static double r_weak_learner_Children[1414];
  static double r_weak_learner_ClassProbability[1414];
  static double v_weak_learner_Children[1390];
  static double v_weak_learner_ClassProbability[1390];
  static double n_weak_learner_Children[1386];
  static double n_weak_learner_ClassProbability[1386];
  static double k_weak_learner_Children[1382];
  static double k_weak_learner_ClassProbability[1382];
  static double ab_weak_learner_Children[1366];
  static double ab_weak_learner_ClassProbabilit[1366];
  static double f_weak_learner_Children[1362];
  static double f_weak_learner_ClassProbability[1362];
  static double p_weak_learner_Children[1334];
  static double p_weak_learner_ClassProbability[1334];
  static double b_weak_learner_Children[1318];
  static double b_weak_learner_ClassProbability[1318];
  static double weak_learner_CutPoint[861];
  static double weak_learner_CutPredictorIndex[861];
  static double l_weak_learner_CutPoint[821];
  static double l_weak_learner_CutPredictorInde[821];
  static double i_weak_learner_CutPoint[813];
  static double i_weak_learner_CutPredictorInde[813];
  static double c_weak_learner_CutPoint[807];
  static double c_weak_learner_CutPredictorInde[807];
  static double cachedScore_data[800];
  static double o_weak_learner_CutPoint[797];
  static double o_weak_learner_CutPredictorInde[797];
  static double t_weak_learner_CutPoint[791];
  static double t_weak_learner_CutPredictorInde[791];
  static double e_weak_learner_CutPoint[781];
  static double e_weak_learner_CutPredictorInde[781];
  static double h_weak_learner_CutPoint[779];
  static double h_weak_learner_CutPredictorInde[779];
  static double q_weak_learner_CutPoint[775];
  static double q_weak_learner_CutPredictorInde[775];
  static double j_weak_learner_CutPoint[769];
  static double j_weak_learner_CutPredictorInde[769];
  static double d_weak_learner_CutPoint[765];
  static double d_weak_learner_CutPredictorInde[765];
  static double s_weak_learner_CutPoint[753];
  static double s_weak_learner_CutPredictorInde[753];
  static double g_weak_learner_CutPoint[751];
  static double g_weak_learner_CutPredictorInde[751];
  static double w_weak_learner_CutPoint[747];
  static double w_weak_learner_CutPredictorInde[747];
  static double y_weak_learner_CutPoint[745];
  static double y_weak_learner_CutPredictorInde[745];
  static double m_weak_learner_CutPoint[739];
  static double m_weak_learner_CutPredictorInde[739];
  static double x_weak_learner_CutPoint[727];
  static double x_weak_learner_CutPredictorInde[727];
  static double u_weak_learner_CutPoint[725];
  static double u_weak_learner_CutPredictorInde[725];
  static double r_weak_learner_CutPoint[707];
  static double r_weak_learner_CutPredictorInde[707];
  static double v_weak_learner_CutPoint[695];
  static double v_weak_learner_CutPredictorInde[695];
  static double n_weak_learner_CutPoint[693];
  static double n_weak_learner_CutPredictorInde[693];
  static double k_weak_learner_CutPoint[691];
  static double k_weak_learner_CutPredictorInde[691];
  static double ab_weak_learner_CutPoint[683];
  static double ab_weak_learner_CutPredictorInd[683];
  static double f_weak_learner_CutPoint[681];
  static double f_weak_learner_CutPredictorInde[681];
  static double p_weak_learner_CutPoint[667];
  static double p_weak_learner_CutPredictorInde[667];
  static double b_weak_learner_CutPoint[659];
  static double b_weak_learner_CutPredictorInde[659];
  static double cachedWeights_data[400];
  static boolean_T expl_temp[861];
  static boolean_T weak_learner_NanCutPoints[861];
  static boolean_T l_weak_learner_NanCutPoints[821];
  static boolean_T o_expl_temp[821];
  static boolean_T i_weak_learner_NanCutPoints[813];
  static boolean_T l_expl_temp[813];
  static boolean_T c_weak_learner_NanCutPoints[807];
  static boolean_T f_expl_temp[807];
  static boolean_T o_weak_learner_NanCutPoints[797];
  static boolean_T r_expl_temp[797];
  static boolean_T t_weak_learner_NanCutPoints[791];
  static boolean_T w_expl_temp[791];
  static boolean_T e_weak_learner_NanCutPoints[781];
  static boolean_T h_expl_temp[781];
  static boolean_T h_weak_learner_NanCutPoints[779];
  static boolean_T k_expl_temp[779];
  static boolean_T q_weak_learner_NanCutPoints[775];
  static boolean_T t_expl_temp[775];
  static boolean_T j_weak_learner_NanCutPoints[769];
  static boolean_T m_expl_temp[769];
  static boolean_T d_weak_learner_NanCutPoints[765];
  static boolean_T g_expl_temp[765];
  static boolean_T s_weak_learner_NanCutPoints[753];
  static boolean_T v_expl_temp[753];
  static boolean_T g_weak_learner_NanCutPoints[751];
  static boolean_T j_expl_temp[751];
  static boolean_T ab_expl_temp[747];
  static boolean_T w_weak_learner_NanCutPoints[747];
  static boolean_T cb_expl_temp[745];
  static boolean_T y_weak_learner_NanCutPoints[745];
  static boolean_T m_weak_learner_NanCutPoints[739];
  static boolean_T p_expl_temp[739];
  static boolean_T bb_expl_temp[727];
  static boolean_T x_weak_learner_NanCutPoints[727];
  static boolean_T u_weak_learner_NanCutPoints[725];
  static boolean_T x_expl_temp[725];
  static boolean_T r_weak_learner_NanCutPoints[707];
  static boolean_T u_expl_temp[707];
  static boolean_T v_weak_learner_NanCutPoints[695];
  static boolean_T y_expl_temp[695];
  static boolean_T n_weak_learner_NanCutPoints[693];
  static boolean_T q_expl_temp[693];
  static boolean_T k_weak_learner_NanCutPoints[691];
  static boolean_T n_expl_temp[691];
  static boolean_T ab_weak_learner_NanCutPoints[683];
  static boolean_T db_expl_temp[683];
  static boolean_T f_weak_learner_NanCutPoints[681];
  static boolean_T i_expl_temp[681];
  static boolean_T p_weak_learner_NanCutPoints[667];
  static boolean_T s_expl_temp[667];
  double weak_learner_Cost[4];
  double weak_learner_ClassNames[2];
  double weak_learner_Prior[2];
  int b_expl_temp[2];
  int cachedScore_size[2];
  int b_useObsForLearner_size[1];
  int i;
  int loop_ub;
  boolean_T b_weak_learner_NanCutPoints[659];
  boolean_T e_expl_temp[659];
  boolean_T b_useObsForLearner_data[400];
  boolean_T d_expl_temp[2];
  boolean_T b;
  boolean_T firstCache;
  boolean_T initCache;
  c_classreg_learning_coderutils_ c_expl_temp;
  cachedScore_size[0] = score_size[0];
  cachedScore_size[1] = 2;
  loop_ub = score_size[0] * score_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&cachedScore_data[0], &score_data[0], loop_ub * sizeof(double));
  }

  loop_ub = score_size[0];
  if (0 <= loop_ub - 1) {
    memset(&cachedWeights_data[0], 0, loop_ub * sizeof(double));
  }

  firstCache = true;
  if (learners[0]) {
    firstCache = false;
    mc_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp,
      weak_learner_Prior, d_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    b = false;
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&b_useObsForLearner_data[0], &useObsForLearner_data[0], loop_ub *
             sizeof(boolean_T));
    }

    bc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, &b, classNames, b_useObsForLearner_data,
      b_useObsForLearner_size, true, score_data, score_size);
  }

  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    nc_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, e_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[1];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0]];
    }

    cc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, b_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    oc_CompactClassificationTree_Co(c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, f_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, c_weak_learner_ClassProbability);
    b = isCached[2];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 2];
    }

    dc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, c_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pc_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, g_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[3];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 3];
    }

    ec_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, d_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qc_CompactClassificationTree_Co(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, h_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[4];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 4];
    }

    fc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, e_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    rc_CompactClassificationTree_Co(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, i_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[5];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 5];
    }

    gc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, f_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sc_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, j_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[6];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 6];
    }

    hc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, g_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    tc_CompactClassificationTree_Co(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, k_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[7];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 7];
    }

    ic_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, h_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    uc_CompactClassificationTree_Co(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, l_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[8];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 8];
    }

    jc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, i_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vc_CompactClassificationTree_Co(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, m_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[9];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 9];
    }

    kc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, j_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wc_CompactClassificationTree_Co(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, n_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[10];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 10];
    }

    lc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, k_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xc_CompactClassificationTree_Co(l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, o_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, l_weak_learner_ClassProbability);
    b = isCached[11];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 11];
    }

    mc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, l_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yc_CompactClassificationTree_Co(m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, p_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, m_weak_learner_ClassProbability);
    b = isCached[12];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 12];
    }

    nc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, m_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ad_CompactClassificationTree_Co(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, q_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[13];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 13];
    }

    oc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, n_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[14]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bd_CompactClassificationTree_Co(o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, r_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, o_weak_learner_ClassProbability);
    b = isCached[14];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 14];
    }

    pc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, o_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[15]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    cd_CompactClassificationTree_Co(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, l_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[15];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 15];
    }

    jc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, i_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[16]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    dd_CompactClassificationTree_Co(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, s_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[16];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 16];
    }

    qc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, p_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[17]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ed_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, t_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[17];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 17];
    }

    rc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, q_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[18]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fd_CompactClassificationTree_Co(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, u_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[18];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 18];
    }

    sc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, r_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[19]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    gd_CompactClassificationTree_Co(s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, v_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, s_weak_learner_ClassProbability);
    b = isCached[19];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 19];
    }

    tc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, s_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[20]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    hd_CompactClassificationTree_Co(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, s_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[20];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 20];
    }

    qc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, p_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[21]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    id_CompactClassificationTree_Co(t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, w_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, t_weak_learner_ClassProbability);
    b = isCached[21];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 21];
    }

    uc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, t_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[22]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jd_CompactClassificationTree_Co(u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, x_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, u_weak_learner_ClassProbability);
    b = isCached[22];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 22];
    }

    vc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, u_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[23]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kd_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, y_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[23];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 23];
    }

    wc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, v_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[24]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ld_CompactClassificationTree_Co(w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, ab_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, w_weak_learner_ClassProbability);
    b = isCached[24];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 24];
    }

    xc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, w_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[25]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    md_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, bb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[25];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 25];
    }

    yc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, x_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[26]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    nd_CompactClassificationTree_Co(y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, cb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, y_weak_learner_ClassProbability);
    b = isCached[26];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 26];
    }

    ad_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, y_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[27]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    od_CompactClassificationTree_Co(w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, ab_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, w_weak_learner_ClassProbability);
    b = isCached[27];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 27];
    }

    xc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, w_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[28]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pd_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp,
      weak_learner_Prior, d_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    b = isCached[28];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 28];
    }

    bc_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, &b, classNames, b_useObsForLearner_data,
      b_useObsForLearner_size, initCache, score_data, score_size);
  }

  if (learners[29]) {
    qd_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, db_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit);
    b = isCached[29];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 29];
    }

    bd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, firstCache, score_data,
      score_size);
  }
}

void d_aggregatePredict(const double X_data[], const int X_size[2], double
  score_data[], int score_size[2], const boolean_T isCached[30], const double
  classNames[2], const boolean_T learners[30], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[2])
{
  static double c_weak_learner_Children[2010];
  static double c_weak_learner_ClassProbability[2010];
  static double v_weak_learner_Children[1874];
  static double v_weak_learner_ClassProbability[1874];
  static double t_weak_learner_Children[1806];
  static double t_weak_learner_ClassProbability[1806];
  static double o_weak_learner_Children[1794];
  static double o_weak_learner_ClassProbability[1794];
  static double b_weak_learner_Children[1762];
  static double b_weak_learner_ClassProbability[1762];
  static double j_weak_learner_Children[1694];
  static double j_weak_learner_ClassProbability[1694];
  static double e_weak_learner_Children[1690];
  static double e_weak_learner_ClassProbability[1690];
  static double y_weak_learner_Children[1646];
  static double y_weak_learner_ClassProbability[1646];
  static double h_weak_learner_Children[1626];
  static double h_weak_learner_ClassProbability[1626];
  static double weak_learner_Children[1606];
  static double weak_learner_ClassProbability[1606];
  static double l_weak_learner_Children[1602];
  static double l_weak_learner_ClassProbability[1602];
  static double n_weak_learner_Children[1574];
  static double n_weak_learner_ClassProbability[1574];
  static double u_weak_learner_Children[1562];
  static double u_weak_learner_ClassProbability[1562];
  static double w_weak_learner_Children[1550];
  static double w_weak_learner_ClassProbability[1550];
  static double m_weak_learner_Children[1526];
  static double m_weak_learner_ClassProbability[1526];
  static double k_weak_learner_Children[1514];
  static double k_weak_learner_ClassProbability[1514];
  static double g_weak_learner_Children[1502];
  static double g_weak_learner_ClassProbability[1502];
  static double x_weak_learner_Children[1482];
  static double x_weak_learner_ClassProbability[1482];
  static double q_weak_learner_Children[1474];
  static double q_weak_learner_ClassProbability[1474];
  static double i_weak_learner_Children[1466];
  static double i_weak_learner_ClassProbability[1466];
  static double s_weak_learner_Children[1462];
  static double s_weak_learner_ClassProbability[1462];
  static double p_weak_learner_Children[1454];
  static double p_weak_learner_ClassProbability[1454];
  static double f_weak_learner_Children[1446];
  static double f_weak_learner_ClassProbability[1446];
  static double d_weak_learner_Children[1426];
  static double d_weak_learner_ClassProbability[1426];
  static double ab_weak_learner_Children[1394];
  static double ab_weak_learner_ClassProbabilit[1394];
  static double r_weak_learner_Children[1274];
  static double r_weak_learner_ClassProbability[1274];
  static double c_weak_learner_CutPoint[1005];
  static double c_weak_learner_CutPredictorInde[1005];
  static double v_weak_learner_CutPoint[937];
  static double v_weak_learner_CutPredictorInde[937];
  static double t_weak_learner_CutPoint[903];
  static double t_weak_learner_CutPredictorInde[903];
  static double o_weak_learner_CutPoint[897];
  static double o_weak_learner_CutPredictorInde[897];
  static double b_weak_learner_CutPoint[881];
  static double b_weak_learner_CutPredictorInde[881];
  static double j_weak_learner_CutPoint[847];
  static double j_weak_learner_CutPredictorInde[847];
  static double e_weak_learner_CutPoint[845];
  static double e_weak_learner_CutPredictorInde[845];
  static double y_weak_learner_CutPoint[823];
  static double y_weak_learner_CutPredictorInde[823];
  static double h_weak_learner_CutPoint[813];
  static double h_weak_learner_CutPredictorInde[813];
  static double weak_learner_CutPoint[803];
  static double weak_learner_CutPredictorIndex[803];
  static double l_weak_learner_CutPoint[801];
  static double l_weak_learner_CutPredictorInde[801];
  static double cachedScore_data[800];
  static double n_weak_learner_CutPoint[787];
  static double n_weak_learner_CutPredictorInde[787];
  static double u_weak_learner_CutPoint[781];
  static double u_weak_learner_CutPredictorInde[781];
  static double w_weak_learner_CutPoint[775];
  static double w_weak_learner_CutPredictorInde[775];
  static double m_weak_learner_CutPoint[763];
  static double m_weak_learner_CutPredictorInde[763];
  static double k_weak_learner_CutPoint[757];
  static double k_weak_learner_CutPredictorInde[757];
  static double g_weak_learner_CutPoint[751];
  static double g_weak_learner_CutPredictorInde[751];
  static double x_weak_learner_CutPoint[741];
  static double x_weak_learner_CutPredictorInde[741];
  static double q_weak_learner_CutPoint[737];
  static double q_weak_learner_CutPredictorInde[737];
  static double i_weak_learner_CutPoint[733];
  static double i_weak_learner_CutPredictorInde[733];
  static double s_weak_learner_CutPoint[731];
  static double s_weak_learner_CutPredictorInde[731];
  static double p_weak_learner_CutPoint[727];
  static double p_weak_learner_CutPredictorInde[727];
  static double f_weak_learner_CutPoint[723];
  static double f_weak_learner_CutPredictorInde[723];
  static double d_weak_learner_CutPoint[713];
  static double d_weak_learner_CutPredictorInde[713];
  static double ab_weak_learner_CutPoint[697];
  static double ab_weak_learner_CutPredictorInd[697];
  static double r_weak_learner_CutPoint[637];
  static double r_weak_learner_CutPredictorInde[637];
  static double cachedWeights_data[400];
  static boolean_T c_weak_learner_NanCutPoints[1005];
  static boolean_T f_expl_temp[1005];
  static boolean_T v_weak_learner_NanCutPoints[937];
  static boolean_T y_expl_temp[937];
  static boolean_T t_weak_learner_NanCutPoints[903];
  static boolean_T w_expl_temp[903];
  static boolean_T o_weak_learner_NanCutPoints[897];
  static boolean_T r_expl_temp[897];
  static boolean_T b_weak_learner_NanCutPoints[881];
  static boolean_T e_expl_temp[881];
  static boolean_T j_weak_learner_NanCutPoints[847];
  static boolean_T m_expl_temp[847];
  static boolean_T e_weak_learner_NanCutPoints[845];
  static boolean_T h_expl_temp[845];
  static boolean_T cb_expl_temp[823];
  static boolean_T y_weak_learner_NanCutPoints[823];
  static boolean_T h_weak_learner_NanCutPoints[813];
  static boolean_T k_expl_temp[813];
  static boolean_T expl_temp[803];
  static boolean_T weak_learner_NanCutPoints[803];
  static boolean_T l_weak_learner_NanCutPoints[801];
  static boolean_T o_expl_temp[801];
  static boolean_T n_weak_learner_NanCutPoints[787];
  static boolean_T q_expl_temp[787];
  static boolean_T u_weak_learner_NanCutPoints[781];
  static boolean_T x_expl_temp[781];
  static boolean_T ab_expl_temp[775];
  static boolean_T w_weak_learner_NanCutPoints[775];
  static boolean_T m_weak_learner_NanCutPoints[763];
  static boolean_T p_expl_temp[763];
  static boolean_T k_weak_learner_NanCutPoints[757];
  static boolean_T n_expl_temp[757];
  static boolean_T g_weak_learner_NanCutPoints[751];
  static boolean_T j_expl_temp[751];
  static boolean_T bb_expl_temp[741];
  static boolean_T x_weak_learner_NanCutPoints[741];
  static boolean_T q_weak_learner_NanCutPoints[737];
  static boolean_T t_expl_temp[737];
  static boolean_T i_weak_learner_NanCutPoints[733];
  static boolean_T l_expl_temp[733];
  static boolean_T s_weak_learner_NanCutPoints[731];
  static boolean_T v_expl_temp[731];
  static boolean_T p_weak_learner_NanCutPoints[727];
  static boolean_T s_expl_temp[727];
  static boolean_T f_weak_learner_NanCutPoints[723];
  static boolean_T i_expl_temp[723];
  static boolean_T d_weak_learner_NanCutPoints[713];
  static boolean_T g_expl_temp[713];
  static boolean_T ab_weak_learner_NanCutPoints[697];
  static boolean_T db_expl_temp[697];
  double weak_learner_Cost[4];
  double weak_learner_ClassNames[2];
  double weak_learner_Prior[2];
  int b_expl_temp[2];
  int cachedScore_size[2];
  int b_useObsForLearner_size[1];
  int i;
  int loop_ub;
  boolean_T r_weak_learner_NanCutPoints[637];
  boolean_T u_expl_temp[637];
  boolean_T b_useObsForLearner_data[400];
  boolean_T d_expl_temp[2];
  boolean_T b;
  boolean_T firstCache;
  boolean_T initCache;
  c_classreg_learning_coderutils_ c_expl_temp;
  cachedScore_size[0] = score_size[0];
  cachedScore_size[1] = 2;
  loop_ub = score_size[0] * score_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&cachedScore_data[0], &score_data[0], loop_ub * sizeof(double));
  }

  loop_ub = score_size[0];
  if (0 <= loop_ub - 1) {
    memset(&cachedWeights_data[0], 0, loop_ub * sizeof(double));
  }

  firstCache = true;
  if (learners[0]) {
    firstCache = false;
    rd_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp,
      weak_learner_Prior, d_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    b = false;
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&b_useObsForLearner_data[0], &useObsForLearner_data[0], loop_ub *
             sizeof(boolean_T));
    }

    cd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, &b, classNames, b_useObsForLearner_data,
      b_useObsForLearner_size, true, score_data, score_size);
  }

  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sd_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, e_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[1];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0]];
    }

    dd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, b_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    td_CompactClassificationTree_Co(c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, f_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, c_weak_learner_ClassProbability);
    b = isCached[2];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 2];
    }

    ed_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, c_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ud_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, g_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[3];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 3];
    }

    fd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, d_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vd_CompactClassificationTree_Co(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, h_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[4];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 4];
    }

    gd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, e_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wd_CompactClassificationTree_Co(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, i_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[5];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 5];
    }

    hd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, f_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xd_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, j_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[6];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 6];
    }

    id_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, g_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yd_CompactClassificationTree_Co(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, k_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[7];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 7];
    }

    jd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, h_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ae_CompactClassificationTree_Co(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, l_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[8];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 8];
    }

    kd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, i_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    be_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp,
      weak_learner_Prior, d_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    b = isCached[9];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 9];
    }

    cd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, &b, classNames, b_useObsForLearner_data,
      b_useObsForLearner_size, initCache, score_data, score_size);
  }

  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ce_CompactClassificationTree_Co(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, m_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[10];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 10];
    }

    ld_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, j_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    de_CompactClassificationTree_Co(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, n_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[11];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 11];
    }

    md_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, k_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ee_CompactClassificationTree_Co(l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, o_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, l_weak_learner_ClassProbability);
    b = isCached[12];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 12];
    }

    nd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, l_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fe_CompactClassificationTree_Co(m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, p_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, m_weak_learner_ClassProbability);
    b = isCached[13];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 13];
    }

    od_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, m_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[14]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ge_CompactClassificationTree_Co(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, q_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[14];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 14];
    }

    pd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, n_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[15]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    he_CompactClassificationTree_Co(o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, r_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, o_weak_learner_ClassProbability);
    b = isCached[15];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 15];
    }

    qd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, o_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[16]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ie_CompactClassificationTree_Co(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, s_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[16];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 16];
    }

    rd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, p_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[17]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    je_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, t_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[17];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 17];
    }

    sd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, q_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[18]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ke_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp,
      weak_learner_Prior, d_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    b = isCached[18];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 18];
    }

    cd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, &b, classNames, b_useObsForLearner_data,
      b_useObsForLearner_size, initCache, score_data, score_size);
  }

  if (learners[19]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    le_CompactClassificationTree_Co(m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, p_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, m_weak_learner_ClassProbability);
    b = isCached[19];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 19];
    }

    od_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, m_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[20]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    me_CompactClassificationTree_Co(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, u_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[20];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 20];
    }

    td_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, r_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[21]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ne_CompactClassificationTree_Co(s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, v_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, s_weak_learner_ClassProbability);
    b = isCached[21];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 21];
    }

    ud_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, s_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[22]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    oe_CompactClassificationTree_Co(t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, w_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, t_weak_learner_ClassProbability);
    b = isCached[22];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 22];
    }

    vd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, t_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[23]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pe_CompactClassificationTree_Co(u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, x_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, u_weak_learner_ClassProbability);
    b = isCached[23];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 23];
    }

    wd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, u_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[24]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qe_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, y_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[24];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 24];
    }

    xd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, v_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[25]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    re_CompactClassificationTree_Co(w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, ab_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, w_weak_learner_ClassProbability);
    b = isCached[25];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 25];
    }

    yd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, w_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[26]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    se_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, bb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[26];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 26];
    }

    ae_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, x_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[27]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    te_CompactClassificationTree_Co(l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, o_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, l_weak_learner_ClassProbability);
    b = isCached[27];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 27];
    }

    nd_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, l_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[28]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ue_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, db_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit);
    b = isCached[28];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 28];
    }

    be_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[29]) {
    ve_CompactClassificationTree_Co(y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, cb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, y_weak_learner_ClassProbability);
    b = isCached[29];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 29];
    }

    ce_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, y_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, firstCache, score_data,
      score_size);
  }
}

void e_aggregatePredict(const double X_data[], const int X_size[2], double
  score_data[], int score_size[2], const boolean_T isCached[30], const double
  classNames[2], const boolean_T learners[30], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[2])
{
  static double q_weak_learner_Children[1646];
  static double q_weak_learner_ClassProbability[1646];
  static double w_weak_learner_Children[1610];
  static double w_weak_learner_ClassProbability[1610];
  static double p_weak_learner_Children[1590];
  static double p_weak_learner_ClassProbability[1590];
  static double ab_weak_learner_Children[1538];
  static double ab_weak_learner_ClassProbabilit[1538];
  static double e_weak_learner_Children[1514];
  static double e_weak_learner_ClassProbability[1514];
  static double n_weak_learner_Children[1506];
  static double n_weak_learner_ClassProbability[1506];
  static double weak_learner_Children[1478];
  static double weak_learner_ClassProbability[1478];
  static double d_weak_learner_Children[1458];
  static double d_weak_learner_ClassProbability[1458];
  static double o_weak_learner_Children[1418];
  static double o_weak_learner_ClassProbability[1418];
  static double bb_weak_learner_Children[1414];
  static double bb_weak_learner_ClassProbabilit[1414];
  static double t_weak_learner_Children[1394];
  static double t_weak_learner_ClassProbability[1394];
  static double s_weak_learner_Children[1378];
  static double s_weak_learner_ClassProbability[1378];
  static double c_weak_learner_Children[1334];
  static double c_weak_learner_ClassProbability[1334];
  static double i_weak_learner_Children[1306];
  static double i_weak_learner_ClassProbability[1306];
  static double m_weak_learner_Children[1282];
  static double m_weak_learner_ClassProbability[1282];
  static double u_weak_learner_Children[1274];
  static double u_weak_learner_ClassProbability[1274];
  static double h_weak_learner_Children[1242];
  static double h_weak_learner_ClassProbability[1242];
  static double k_weak_learner_Children[1238];
  static double k_weak_learner_ClassProbability[1238];
  static double r_weak_learner_Children[1230];
  static double r_weak_learner_ClassProbability[1230];
  static double g_weak_learner_Children[1218];
  static double g_weak_learner_ClassProbability[1218];
  static double y_weak_learner_Children[1214];
  static double y_weak_learner_ClassProbability[1214];
  static double f_weak_learner_Children[1206];
  static double f_weak_learner_ClassProbability[1206];
  static double b_weak_learner_Children[1174];
  static double b_weak_learner_ClassProbability[1174];
  static double v_weak_learner_Children[1170];
  static double v_weak_learner_ClassProbability[1170];
  static double l_weak_learner_Children[1082];
  static double l_weak_learner_ClassProbability[1082];
  static double j_weak_learner_Children[1042];
  static double j_weak_learner_ClassProbability[1042];
  static double x_weak_learner_Children[1038];
  static double x_weak_learner_ClassProbability[1038];
  static double q_weak_learner_CutPoint[823];
  static double q_weak_learner_CutPredictorInde[823];
  static double w_weak_learner_CutPoint[805];
  static double w_weak_learner_CutPredictorInde[805];
  static double cachedScore_data[800];
  static double p_weak_learner_CutPoint[795];
  static double p_weak_learner_CutPredictorInde[795];
  static double ab_weak_learner_CutPoint[769];
  static double ab_weak_learner_CutPredictorInd[769];
  static double e_weak_learner_CutPoint[757];
  static double e_weak_learner_CutPredictorInde[757];
  static double n_weak_learner_CutPoint[753];
  static double n_weak_learner_CutPredictorInde[753];
  static double weak_learner_CutPoint[739];
  static double weak_learner_CutPredictorIndex[739];
  static double d_weak_learner_CutPoint[729];
  static double d_weak_learner_CutPredictorInde[729];
  static double o_weak_learner_CutPoint[709];
  static double o_weak_learner_CutPredictorInde[709];
  static double bb_weak_learner_CutPoint[707];
  static double bb_weak_learner_CutPredictorInd[707];
  static double t_weak_learner_CutPoint[697];
  static double t_weak_learner_CutPredictorInde[697];
  static double s_weak_learner_CutPoint[689];
  static double s_weak_learner_CutPredictorInde[689];
  static double c_weak_learner_CutPoint[667];
  static double c_weak_learner_CutPredictorInde[667];
  static double i_weak_learner_CutPoint[653];
  static double i_weak_learner_CutPredictorInde[653];
  static double m_weak_learner_CutPoint[641];
  static double m_weak_learner_CutPredictorInde[641];
  static double u_weak_learner_CutPoint[637];
  static double u_weak_learner_CutPredictorInde[637];
  static double h_weak_learner_CutPoint[621];
  static double h_weak_learner_CutPredictorInde[621];
  static double k_weak_learner_CutPoint[619];
  static double k_weak_learner_CutPredictorInde[619];
  static double r_weak_learner_CutPoint[615];
  static double r_weak_learner_CutPredictorInde[615];
  static double g_weak_learner_CutPoint[609];
  static double g_weak_learner_CutPredictorInde[609];
  static double y_weak_learner_CutPoint[607];
  static double y_weak_learner_CutPredictorInde[607];
  static double f_weak_learner_CutPoint[603];
  static double f_weak_learner_CutPredictorInde[603];
  static double b_weak_learner_CutPoint[587];
  static double b_weak_learner_CutPredictorInde[587];
  static double v_weak_learner_CutPoint[585];
  static double v_weak_learner_CutPredictorInde[585];
  static double l_weak_learner_CutPoint[541];
  static double l_weak_learner_CutPredictorInde[541];
  static double j_weak_learner_CutPoint[521];
  static double j_weak_learner_CutPredictorInde[521];
  static double x_weak_learner_CutPoint[519];
  static double x_weak_learner_CutPredictorInde[519];
  static double cachedWeights_data[400];
  static boolean_T q_weak_learner_NanCutPoints[823];
  static boolean_T t_expl_temp[823];
  static boolean_T ab_expl_temp[805];
  static boolean_T w_weak_learner_NanCutPoints[805];
  static boolean_T p_weak_learner_NanCutPoints[795];
  static boolean_T s_expl_temp[795];
  static boolean_T ab_weak_learner_NanCutPoints[769];
  static boolean_T db_expl_temp[769];
  static boolean_T e_weak_learner_NanCutPoints[757];
  static boolean_T h_expl_temp[757];
  static boolean_T n_weak_learner_NanCutPoints[753];
  static boolean_T q_expl_temp[753];
  static boolean_T expl_temp[739];
  static boolean_T weak_learner_NanCutPoints[739];
  static boolean_T d_weak_learner_NanCutPoints[729];
  static boolean_T g_expl_temp[729];
  static boolean_T o_weak_learner_NanCutPoints[709];
  static boolean_T r_expl_temp[709];
  static boolean_T bb_weak_learner_NanCutPoints[707];
  static boolean_T eb_expl_temp[707];
  static boolean_T t_weak_learner_NanCutPoints[697];
  static boolean_T w_expl_temp[697];
  static boolean_T s_weak_learner_NanCutPoints[689];
  static boolean_T v_expl_temp[689];
  static boolean_T c_weak_learner_NanCutPoints[667];
  static boolean_T f_expl_temp[667];
  static boolean_T i_weak_learner_NanCutPoints[653];
  static boolean_T l_expl_temp[653];
  static boolean_T m_weak_learner_NanCutPoints[641];
  static boolean_T p_expl_temp[641];
  static boolean_T u_weak_learner_NanCutPoints[637];
  static boolean_T x_expl_temp[637];
  static boolean_T h_weak_learner_NanCutPoints[621];
  static boolean_T k_expl_temp[621];
  static boolean_T k_weak_learner_NanCutPoints[619];
  static boolean_T n_expl_temp[619];
  static boolean_T r_weak_learner_NanCutPoints[615];
  static boolean_T u_expl_temp[615];
  static boolean_T g_weak_learner_NanCutPoints[609];
  static boolean_T j_expl_temp[609];
  static boolean_T cb_expl_temp[607];
  static boolean_T y_weak_learner_NanCutPoints[607];
  static boolean_T f_weak_learner_NanCutPoints[603];
  static boolean_T i_expl_temp[603];
  static boolean_T b_weak_learner_NanCutPoints[587];
  static boolean_T e_expl_temp[587];
  static boolean_T v_weak_learner_NanCutPoints[585];
  static boolean_T y_expl_temp[585];
  static boolean_T l_weak_learner_NanCutPoints[541];
  static boolean_T o_expl_temp[541];
  static boolean_T j_weak_learner_NanCutPoints[521];
  static boolean_T m_expl_temp[521];
  double weak_learner_Cost[4];
  double weak_learner_ClassNames[2];
  double weak_learner_Prior[2];
  int b_expl_temp[2];
  int cachedScore_size[2];
  int b_useObsForLearner_size[1];
  int i;
  int loop_ub;
  boolean_T bb_expl_temp[519];
  boolean_T x_weak_learner_NanCutPoints[519];
  boolean_T b_useObsForLearner_data[400];
  boolean_T d_expl_temp[2];
  boolean_T b;
  boolean_T firstCache;
  boolean_T initCache;
  c_classreg_learning_coderutils_ c_expl_temp;
  cachedScore_size[0] = score_size[0];
  cachedScore_size[1] = 2;
  loop_ub = score_size[0] * score_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&cachedScore_data[0], &score_data[0], loop_ub * sizeof(double));
  }

  loop_ub = score_size[0];
  if (0 <= loop_ub - 1) {
    memset(&cachedWeights_data[0], 0, loop_ub * sizeof(double));
  }

  firstCache = true;
  if (learners[0]) {
    firstCache = false;
    we_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp,
      weak_learner_Prior, d_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    b = false;
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&b_useObsForLearner_data[0], &useObsForLearner_data[0], loop_ub *
             sizeof(boolean_T));
    }

    de_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, &b, classNames, b_useObsForLearner_data,
      b_useObsForLearner_size, score_data, score_size);
  }

  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xe_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, e_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[1];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0]];
    }

    ee_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, b_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ye_CompactClassificationTree_Co(c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, f_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, c_weak_learner_ClassProbability);
    b = isCached[2];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 2];
    }

    fe_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, c_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    af_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, g_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[3];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 3];
    }

    ge_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, d_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bf_CompactClassificationTree_Co(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, h_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[4];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 4];
    }

    he_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, e_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    cf_CompactClassificationTree_Co(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, i_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[5];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 5];
    }

    ie_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, f_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    df_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, j_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[6];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 6];
    }

    je_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, g_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ef_CompactClassificationTree_Co(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, k_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[7];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 7];
    }

    ke_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, h_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ff_CompactClassificationTree_Co(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, l_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[8];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 8];
    }

    le_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, i_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    gf_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, j_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[9];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 9];
    }

    je_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, g_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    hf_CompactClassificationTree_Co(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, m_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[10];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 10];
    }

    me_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, j_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    if_CompactClassificationTree_Co(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, n_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[11];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 11];
    }

    ne_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, k_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jf_CompactClassificationTree_Co(l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, o_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, l_weak_learner_ClassProbability);
    b = isCached[12];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 12];
    }

    oe_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, l_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kf_CompactClassificationTree_Co(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, n_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[13];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 13];
    }

    ne_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, k_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[14]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    lf_CompactClassificationTree_Co(m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, p_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, m_weak_learner_ClassProbability);
    b = isCached[14];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 14];
    }

    pe_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, m_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[15]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    mf_CompactClassificationTree_Co(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, q_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[15];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 15];
    }

    qe_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, n_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[16]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    nf_CompactClassificationTree_Co(o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, r_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, o_weak_learner_ClassProbability);
    b = isCached[16];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 16];
    }

    re_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, o_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[17]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    of_CompactClassificationTree_Co(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, s_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[17];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 17];
    }

    se_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, p_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[18]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pf_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, t_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[18];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 18];
    }

    te_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, q_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[19]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qf_CompactClassificationTree_Co(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, u_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[19];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 19];
    }

    ue_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, r_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[20]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    rf_CompactClassificationTree_Co(s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, v_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, s_weak_learner_ClassProbability);
    b = isCached[20];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 20];
    }

    ve_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, s_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[21]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sf_CompactClassificationTree_Co(t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, w_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, t_weak_learner_ClassProbability);
    b = isCached[21];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 21];
    }

    we_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, t_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[22]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    tf_CompactClassificationTree_Co(u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, x_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, u_weak_learner_ClassProbability);
    b = isCached[22];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 22];
    }

    xe_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, u_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[23]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    uf_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, y_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[23];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 23];
    }

    ye_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, v_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[24]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vf_CompactClassificationTree_Co(w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, ab_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, w_weak_learner_ClassProbability);
    b = isCached[24];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 24];
    }

    af_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, w_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[25]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wf_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, bb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[25];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 25];
    }

    bf_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, x_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[26]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xf_CompactClassificationTree_Co(y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, cb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, y_weak_learner_ClassProbability);
    b = isCached[26];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 26];
    }

    cf_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, y_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[27]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yf_CompactClassificationTree_Co(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, k_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[27];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 27];
    }

    ke_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, h_weak_learner_ClassProbability, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[28]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ag_CompactClassificationTree_Co(bb_weak_learner_CutPredictorInd,
      bb_weak_learner_Children, bb_weak_learner_CutPoint,
      bb_weak_learner_NanCutPoints, eb_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, bb_weak_learner_ClassProbabilit);
    b = isCached[28];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 28];
    }

    df_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, bb_weak_learner_CutPredictorInd,
      bb_weak_learner_Children, bb_weak_learner_CutPoint,
      bb_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, bb_weak_learner_ClassProbabilit, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, initCache, score_data,
      score_size);
  }

  if (learners[29]) {
    bg_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, db_expl_temp, weak_learner_ClassNames,
      b_expl_temp, &c_expl_temp, weak_learner_Prior, d_expl_temp,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit);
    b = isCached[29];
    loop_ub = useObsForLearner_size[0];
    b_useObsForLearner_size[0] = useObsForLearner_size[0];
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner_size[0] * 29];
    }

    ef_predictOneWithCache(X_data, X_size, cachedScore_data, cachedScore_size,
      cachedWeights_data, cv1, ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, weak_learner_ClassNames, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, classNames,
      b_useObsForLearner_data, b_useObsForLearner_size, firstCache, score_data,
      score_size);
  }
}

/* End of code generation (aggregatePredict.c) */
