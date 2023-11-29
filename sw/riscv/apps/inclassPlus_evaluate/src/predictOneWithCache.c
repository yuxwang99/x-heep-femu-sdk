/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predictOneWithCache.c
 *
 * Code generation for function 'predictOneWithCache'
 *
 */

/* Include files */
#include "predictOneWithCache.h"
#include "CompactClassificationTree.h"
#include "ismember.h"
#include "rt_nonfinite.h"
#include "updateCache.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void ab_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5715],
  const double weak_learner_Children[11430], const double weak_learner_CutPoint
  [5715], const boolean_T weak_learner_NanCutPoints[5715], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11430],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    cb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ac_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2743],
  const double weak_learner_Children[5486], const double weak_learner_CutPoint
  [2743], const boolean_T weak_learner_NanCutPoints[2743], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5486],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    cc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ad_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[745],
  const double weak_learner_Children[1490], const double weak_learner_CutPoint
  [745], const boolean_T weak_learner_NanCutPoints[745], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1490],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    cd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ae_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[741],
  const double weak_learner_Children[1482], const double weak_learner_CutPoint
  [741], const boolean_T weak_learner_NanCutPoints[741], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1482],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    wd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void af_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[805],
  const double weak_learner_Children[1610], const double weak_learner_CutPoint
  [805], const boolean_T weak_learner_NanCutPoints[805], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1610],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    pe_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void b_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5693],
  const double weak_learner_Children[11386], const double weak_learner_CutPoint
  [5693], const boolean_T weak_learner_NanCutPoints[5693], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11386],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    d_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void bb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5709],
  const double weak_learner_Children[11418], const double weak_learner_CutPoint
  [5709], const boolean_T weak_learner_NanCutPoints[5709], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11418],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    db_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void bc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[861],
  const double weak_learner_Children[1722], const double weak_learner_CutPoint
  [861], const boolean_T weak_learner_NanCutPoints[861], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1722],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    dc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void bd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[683],
  const double weak_learner_Children[1366], const double weak_learner_CutPoint
  [683], const boolean_T weak_learner_NanCutPoints[683], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1366],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    dd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void be_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[697],
  const double weak_learner_Children[1394], const double weak_learner_CutPoint
  [697], const boolean_T weak_learner_NanCutPoints[697], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1394],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    xd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void bf_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[519],
  const double weak_learner_Children[1038], const double weak_learner_CutPoint
  [519], const boolean_T weak_learner_NanCutPoints[519], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1038],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    qe_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void c_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5663],
  const double weak_learner_Children[11326], const double weak_learner_CutPoint
  [5663], const boolean_T weak_learner_NanCutPoints[5663], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11326],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    e_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void cb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2801],
  const double weak_learner_Children[5602], const double weak_learner_CutPoint
  [2801], const boolean_T weak_learner_NanCutPoints[2801], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5602],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], double
  score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
    learnerscore_data[partialTrueCount] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (partialTrueCount = 0; partialTrueCount < 3; partialTrueCount++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * partialTrueCount] = X_data
          [(tmp_data[loop_ub] + X_size[0] * partialTrueCount) - 1];
      }
    }

    eb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
      learnerscore_data[(d_tmp_data[partialTrueCount] + learnerscore_size[0] *
                         (iloc[0] - 1)) - 1] = c_tmp_data[partialTrueCount];
    }

    for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
      learnerscore_data[(d_tmp_data[partialTrueCount] + learnerscore_size[0] *
                         (iloc[1] - 1)) - 1] = c_tmp_data[partialTrueCount +
        tmp_size[0]];
    }
  }

  loop_ub = useObsForLearner_size[0] - 1;
  trueCount = 0;
  partialTrueCount = 0;
  for (i = 0; i <= loop_ub; i++) {
    if (useObsForLearner_data[i]) {
      trueCount++;
      b_tmp_data[partialTrueCount] = (short)(i + 1);
      partialTrueCount++;
    }
  }

  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    cachedScore_data[b_tmp_data[partialTrueCount] - 1] = 0.0;
  }

  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    cachedScore_data[(b_tmp_data[partialTrueCount] + cachedScore_size[0]) - 1] =
      0.0;
  }

  *cached = false;
  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void cc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[659],
  const double weak_learner_Children[1318], const double weak_learner_CutPoint
  [659], const boolean_T weak_learner_NanCutPoints[659], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1318],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ec_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void cd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[803],
  const double weak_learner_Children[1606], const double weak_learner_CutPoint
  [803], const boolean_T weak_learner_NanCutPoints[803], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1606],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ed_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ce_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[823],
  const double weak_learner_Children[1646], const double weak_learner_CutPoint
  [823], const boolean_T weak_learner_NanCutPoints[823], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1646],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    yd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void cf_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[607],
  const double weak_learner_Children[1214], const double weak_learner_CutPoint
  [607], const boolean_T weak_learner_NanCutPoints[607], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1214],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    re_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void d_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5645],
  const double weak_learner_Children[11290], const double weak_learner_CutPoint
  [5645], const boolean_T weak_learner_NanCutPoints[5645], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11290],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    f_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void db_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2783],
  const double weak_learner_Children[5566], const double weak_learner_CutPoint
  [2783], const boolean_T weak_learner_NanCutPoints[2783], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5566],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    fb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void dc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[807],
  const double weak_learner_Children[1614], const double weak_learner_CutPoint
  [807], const boolean_T weak_learner_NanCutPoints[807], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1614],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    fc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void dd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[881],
  const double weak_learner_Children[1762], const double weak_learner_CutPoint
  [881], const boolean_T weak_learner_NanCutPoints[881], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1762],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    fd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void de_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[739],
  const double weak_learner_Children[1478], const double weak_learner_CutPoint
  [739], const boolean_T weak_learner_NanCutPoints[739], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1478],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], double
  score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
    learnerscore_data[partialTrueCount] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (partialTrueCount = 0; partialTrueCount < 17; partialTrueCount++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * partialTrueCount] = X_data
          [(tmp_data[loop_ub] + X_size[0] * partialTrueCount) - 1];
      }
    }

    pc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
      learnerscore_data[(d_tmp_data[partialTrueCount] + learnerscore_size[0] *
                         (iloc[0] - 1)) - 1] = c_tmp_data[partialTrueCount];
    }

    for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
      learnerscore_data[(d_tmp_data[partialTrueCount] + learnerscore_size[0] *
                         (iloc[1] - 1)) - 1] = c_tmp_data[partialTrueCount +
        tmp_size[0]];
    }
  }

  loop_ub = useObsForLearner_size[0] - 1;
  trueCount = 0;
  partialTrueCount = 0;
  for (i = 0; i <= loop_ub; i++) {
    if (useObsForLearner_data[i]) {
      trueCount++;
      b_tmp_data[partialTrueCount] = (short)(i + 1);
      partialTrueCount++;
    }
  }

  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    cachedScore_data[b_tmp_data[partialTrueCount] - 1] = 0.0;
  }

  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    cachedScore_data[(b_tmp_data[partialTrueCount] + cachedScore_size[0]) - 1] =
      0.0;
  }

  *cached = false;
  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void df_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[707],
  const double weak_learner_Children[1414], const double weak_learner_CutPoint
  [707], const boolean_T weak_learner_NanCutPoints[707], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1414],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    uc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void e_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5755],
  const double weak_learner_Children[11510], const double weak_learner_CutPoint
  [5755], const boolean_T weak_learner_NanCutPoints[5755], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11510],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    g_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void eb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2715],
  const double weak_learner_Children[5430], const double weak_learner_CutPoint
  [2715], const boolean_T weak_learner_NanCutPoints[2715], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5430],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    gb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ec_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[765],
  const double weak_learner_Children[1530], const double weak_learner_CutPoint
  [765], const boolean_T weak_learner_NanCutPoints[765], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1530],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    gc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ed_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[1005],
  const double weak_learner_Children[2010], const double weak_learner_CutPoint
  [1005], const boolean_T weak_learner_NanCutPoints[1005], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[2010],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    gd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ee_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[587],
  const double weak_learner_Children[1174], const double weak_learner_CutPoint
  [587], const boolean_T weak_learner_NanCutPoints[587], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1174],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ae_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ef_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[769],
  const double weak_learner_Children[1538], const double weak_learner_CutPoint
  [769], const boolean_T weak_learner_NanCutPoints[769], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1538],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    mc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void f_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5667],
  const double weak_learner_Children[11334], const double weak_learner_CutPoint
  [5667], const boolean_T weak_learner_NanCutPoints[5667], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11334],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    h_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void fb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2709],
  const double weak_learner_Children[5418], const double weak_learner_CutPoint
  [2709], const boolean_T weak_learner_NanCutPoints[2709], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5418],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    hb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void fc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[781],
  const double weak_learner_Children[1562], const double weak_learner_CutPoint
  [781], const boolean_T weak_learner_NanCutPoints[781], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1562],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    hc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void fd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[713],
  const double weak_learner_Children[1426], const double weak_learner_CutPoint
  [713], const boolean_T weak_learner_NanCutPoints[713], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1426],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    hd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void fe_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[667],
  const double weak_learner_Children[1334], const double weak_learner_CutPoint
  [667], const boolean_T weak_learner_NanCutPoints[667], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1334],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    sc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void g_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5779],
  const double weak_learner_Children[11558], const double weak_learner_CutPoint
  [5779], const boolean_T weak_learner_NanCutPoints[5779], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11558],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    i_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void gb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2775],
  const double weak_learner_Children[5550], const double weak_learner_CutPoint
  [2775], const boolean_T weak_learner_NanCutPoints[2775], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5550],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ib_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void gc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[681],
  const double weak_learner_Children[1362], const double weak_learner_CutPoint
  [681], const boolean_T weak_learner_NanCutPoints[681], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1362],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ic_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void gd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[845],
  const double weak_learner_Children[1690], const double weak_learner_CutPoint
  [845], const boolean_T weak_learner_NanCutPoints[845], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1690],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    id_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ge_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[729],
  const double weak_learner_Children[1458], const double weak_learner_CutPoint
  [729], const boolean_T weak_learner_NanCutPoints[729], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1458],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    be_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void h_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5823],
  const double weak_learner_Children[11646], const double weak_learner_CutPoint
  [5823], const boolean_T weak_learner_NanCutPoints[5823], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11646],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    j_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void hb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2695],
  const double weak_learner_Children[5390], const double weak_learner_CutPoint
  [2695], const boolean_T weak_learner_NanCutPoints[2695], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5390],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    jb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void hc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[751],
  const double weak_learner_Children[1502], const double weak_learner_CutPoint
  [751], const boolean_T weak_learner_NanCutPoints[751], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1502],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    jc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void hd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[723],
  const double weak_learner_Children[1446], const double weak_learner_CutPoint
  [723], const boolean_T weak_learner_NanCutPoints[723], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1446],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    jd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void he_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[757],
  const double weak_learner_Children[1514], const double weak_learner_CutPoint
  [757], const boolean_T weak_learner_NanCutPoints[757], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1514],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    md_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void i_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5747],
  const double weak_learner_Children[11494], const double weak_learner_CutPoint
  [5747], const boolean_T weak_learner_NanCutPoints[5747], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11494],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    k_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ib_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2857],
  const double weak_learner_Children[5714], const double weak_learner_CutPoint
  [2857], const boolean_T weak_learner_NanCutPoints[2857], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5714],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    kb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ic_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[779],
  const double weak_learner_Children[1558], const double weak_learner_CutPoint
  [779], const boolean_T weak_learner_NanCutPoints[779], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1558],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    kc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void id_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[751],
  const double weak_learner_Children[1502], const double weak_learner_CutPoint
  [751], const boolean_T weak_learner_NanCutPoints[751], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1502],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    jc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ie_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[603],
  const double weak_learner_Children[1206], const double weak_learner_CutPoint
  [603], const boolean_T weak_learner_NanCutPoints[603], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1206],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ce_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void j_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5615],
  const double weak_learner_Children[11230], const double weak_learner_CutPoint
  [5615], const boolean_T weak_learner_NanCutPoints[5615], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11230],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    l_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void jb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2805],
  const double weak_learner_Children[5610], const double weak_learner_CutPoint
  [2805], const boolean_T weak_learner_NanCutPoints[2805], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5610],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    lb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void jc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[813],
  const double weak_learner_Children[1626], const double weak_learner_CutPoint
  [813], const boolean_T weak_learner_NanCutPoints[813], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1626],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    lc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void jd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[813],
  const double weak_learner_Children[1626], const double weak_learner_CutPoint
  [813], const boolean_T weak_learner_NanCutPoints[813], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1626],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    lc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void je_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[609],
  const double weak_learner_Children[1218], const double weak_learner_CutPoint
  [609], const boolean_T weak_learner_NanCutPoints[609], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1218],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    de_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void k_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5807],
  const double weak_learner_Children[11614], const double weak_learner_CutPoint
  [5807], const boolean_T weak_learner_NanCutPoints[5807], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11614],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    m_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void kb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2961],
  const double weak_learner_Children[5922], const double weak_learner_CutPoint
  [2961], const boolean_T weak_learner_NanCutPoints[2961], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5922],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    mb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void kc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[769],
  const double weak_learner_Children[1538], const double weak_learner_CutPoint
  [769], const boolean_T weak_learner_NanCutPoints[769], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1538],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    mc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void kd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[733],
  const double weak_learner_Children[1466], const double weak_learner_CutPoint
  [733], const boolean_T weak_learner_NanCutPoints[733], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1466],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    kd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ke_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[621],
  const double weak_learner_Children[1242], const double weak_learner_CutPoint
  [621], const boolean_T weak_learner_NanCutPoints[621], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1242],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ee_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void l_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5659],
  const double weak_learner_Children[11318], const double weak_learner_CutPoint
  [5659], const boolean_T weak_learner_NanCutPoints[5659], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11318],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    n_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void lb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2871],
  const double weak_learner_Children[5742], const double weak_learner_CutPoint
  [2871], const boolean_T weak_learner_NanCutPoints[2871], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5742],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    nb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void lc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[691],
  const double weak_learner_Children[1382], const double weak_learner_CutPoint
  [691], const boolean_T weak_learner_NanCutPoints[691], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1382],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    nc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ld_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[847],
  const double weak_learner_Children[1694], const double weak_learner_CutPoint
  [847], const boolean_T weak_learner_NanCutPoints[847], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1694],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ld_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void le_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[653],
  const double weak_learner_Children[1306], const double weak_learner_CutPoint
  [653], const boolean_T weak_learner_NanCutPoints[653], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1306],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    fe_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void m_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5761],
  const double weak_learner_Children[11522], const double weak_learner_CutPoint
  [5761], const boolean_T weak_learner_NanCutPoints[5761], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11522],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    o_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void mb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2827],
  const double weak_learner_Children[5654], const double weak_learner_CutPoint
  [2827], const boolean_T weak_learner_NanCutPoints[2827], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5654],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ob_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void mc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[821],
  const double weak_learner_Children[1642], const double weak_learner_CutPoint
  [821], const boolean_T weak_learner_NanCutPoints[821], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1642],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    oc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void md_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[757],
  const double weak_learner_Children[1514], const double weak_learner_CutPoint
  [757], const boolean_T weak_learner_NanCutPoints[757], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1514],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    md_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void me_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[521],
  const double weak_learner_Children[1042], const double weak_learner_CutPoint
  [521], const boolean_T weak_learner_NanCutPoints[521], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1042],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ge_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void n_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5785],
  const double weak_learner_Children[11570], const double weak_learner_CutPoint
  [5785], const boolean_T weak_learner_NanCutPoints[5785], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11570],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    p_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void nb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2811],
  const double weak_learner_Children[5622], const double weak_learner_CutPoint
  [2811], const boolean_T weak_learner_NanCutPoints[2811], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5622],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    pb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void nc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[739],
  const double weak_learner_Children[1478], const double weak_learner_CutPoint
  [739], const boolean_T weak_learner_NanCutPoints[739], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1478],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    pc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void nd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[801],
  const double weak_learner_Children[1602], const double weak_learner_CutPoint
  [801], const boolean_T weak_learner_NanCutPoints[801], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1602],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    nd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ne_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[619],
  const double weak_learner_Children[1238], const double weak_learner_CutPoint
  [619], const boolean_T weak_learner_NanCutPoints[619], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1238],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    he_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void o_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5825],
  const double weak_learner_Children[11650], const double weak_learner_CutPoint
  [5825], const boolean_T weak_learner_NanCutPoints[5825], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11650],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    q_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ob_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2753],
  const double weak_learner_Children[5506], const double weak_learner_CutPoint
  [2753], const boolean_T weak_learner_NanCutPoints[2753], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5506],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    qb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void oc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[693],
  const double weak_learner_Children[1386], const double weak_learner_CutPoint
  [693], const boolean_T weak_learner_NanCutPoints[693], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1386],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    qc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void od_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[763],
  const double weak_learner_Children[1526], const double weak_learner_CutPoint
  [763], const boolean_T weak_learner_NanCutPoints[763], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1526],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    od_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void oe_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[541],
  const double weak_learner_Children[1082], const double weak_learner_CutPoint
  [541], const boolean_T weak_learner_NanCutPoints[541], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1082],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ie_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void p_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5701],
  const double weak_learner_Children[11402], const double weak_learner_CutPoint
  [5701], const boolean_T weak_learner_NanCutPoints[5701], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11402],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    r_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void pb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2755],
  const double weak_learner_Children[5510], const double weak_learner_CutPoint
  [2755], const boolean_T weak_learner_NanCutPoints[2755], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5510],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    rb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void pc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[797],
  const double weak_learner_Children[1594], const double weak_learner_CutPoint
  [797], const boolean_T weak_learner_NanCutPoints[797], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1594],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    rc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void pd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[787],
  const double weak_learner_Children[1574], const double weak_learner_CutPoint
  [787], const boolean_T weak_learner_NanCutPoints[787], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1574],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    pd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void pe_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[641],
  const double weak_learner_Children[1282], const double weak_learner_CutPoint
  [641], const boolean_T weak_learner_NanCutPoints[641], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1282],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    je_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5731],
  const double weak_learner_Children[11462], const double weak_learner_CutPoint
  [5731], const boolean_T weak_learner_NanCutPoints[5731], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11462],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    c_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void q_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5727],
  const double weak_learner_Children[11454], const double weak_learner_CutPoint
  [5727], const boolean_T weak_learner_NanCutPoints[5727], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11454],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    s_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void qb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2843],
  const double weak_learner_Children[5686], const double weak_learner_CutPoint
  [2843], const boolean_T weak_learner_NanCutPoints[2843], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5686],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    sb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void qc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[667],
  const double weak_learner_Children[1334], const double weak_learner_CutPoint
  [667], const boolean_T weak_learner_NanCutPoints[667], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1334],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    sc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void qd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[897],
  const double weak_learner_Children[1794], const double weak_learner_CutPoint
  [897], const boolean_T weak_learner_NanCutPoints[897], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1794],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    qd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void qe_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[753],
  const double weak_learner_Children[1506], const double weak_learner_CutPoint
  [753], const boolean_T weak_learner_NanCutPoints[753], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1506],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    vc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void r_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5689],
  const double weak_learner_Children[11378], const double weak_learner_CutPoint
  [5689], const boolean_T weak_learner_NanCutPoints[5689], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11378],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    t_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void rb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2687],
  const double weak_learner_Children[5374], const double weak_learner_CutPoint
  [2687], const boolean_T weak_learner_NanCutPoints[2687], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5374],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    tb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void rc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[775],
  const double weak_learner_Children[1550], const double weak_learner_CutPoint
  [775], const boolean_T weak_learner_NanCutPoints[775], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1550],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    tc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void rd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[727],
  const double weak_learner_Children[1454], const double weak_learner_CutPoint
  [727], const boolean_T weak_learner_NanCutPoints[727], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1454],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    bd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void re_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[709],
  const double weak_learner_Children[1418], const double weak_learner_CutPoint
  [709], const boolean_T weak_learner_NanCutPoints[709], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1418],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ke_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void s_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5691],
  const double weak_learner_Children[11382], const double weak_learner_CutPoint
  [5691], const boolean_T weak_learner_NanCutPoints[5691], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11382],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    u_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void sb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2737],
  const double weak_learner_Children[5474], const double weak_learner_CutPoint
  [2737], const boolean_T weak_learner_NanCutPoints[2737], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5474],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ub_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void sc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[707],
  const double weak_learner_Children[1414], const double weak_learner_CutPoint
  [707], const boolean_T weak_learner_NanCutPoints[707], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1414],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    uc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void sd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[737],
  const double weak_learner_Children[1474], const double weak_learner_CutPoint
  [737], const boolean_T weak_learner_NanCutPoints[737], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1474],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    rd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void se_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[795],
  const double weak_learner_Children[1590], const double weak_learner_CutPoint
  [795], const boolean_T weak_learner_NanCutPoints[795], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1590],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    le_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void t_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5623],
  const double weak_learner_Children[11246], const double weak_learner_CutPoint
  [5623], const boolean_T weak_learner_NanCutPoints[5623], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11246],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    v_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void tb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2851],
  const double weak_learner_Children[5702], const double weak_learner_CutPoint
  [2851], const boolean_T weak_learner_NanCutPoints[2851], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5702],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    vb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void tc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[753],
  const double weak_learner_Children[1506], const double weak_learner_CutPoint
  [753], const boolean_T weak_learner_NanCutPoints[753], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1506],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    vc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void td_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[637],
  const double weak_learner_Children[1274], const double weak_learner_CutPoint
  [637], const boolean_T weak_learner_NanCutPoints[637], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1274],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    sd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void te_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[823],
  const double weak_learner_Children[1646], const double weak_learner_CutPoint
  [823], const boolean_T weak_learner_NanCutPoints[823], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1646],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    yd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void u_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5713],
  const double weak_learner_Children[11426], const double weak_learner_CutPoint
  [5713], const boolean_T weak_learner_NanCutPoints[5713], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11426],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    w_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ub_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2825],
  const double weak_learner_Children[5650], const double weak_learner_CutPoint
  [2825], const boolean_T weak_learner_NanCutPoints[2825], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5650],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    wb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void uc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[791],
  const double weak_learner_Children[1582], const double weak_learner_CutPoint
  [791], const boolean_T weak_learner_NanCutPoints[791], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1582],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    wc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ud_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[731],
  const double weak_learner_Children[1462], const double weak_learner_CutPoint
  [731], const boolean_T weak_learner_NanCutPoints[731], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1462],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    td_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ue_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[615],
  const double weak_learner_Children[1230], const double weak_learner_CutPoint
  [615], const boolean_T weak_learner_NanCutPoints[615], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1230],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    me_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void v_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5595],
  const double weak_learner_Children[11190], const double weak_learner_CutPoint
  [5595], const boolean_T weak_learner_NanCutPoints[5595], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11190],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    x_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void vb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2821],
  const double weak_learner_Children[5642], const double weak_learner_CutPoint
  [2821], const boolean_T weak_learner_NanCutPoints[2821], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5642],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    xb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void vc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[725],
  const double weak_learner_Children[1450], const double weak_learner_CutPoint
  [725], const boolean_T weak_learner_NanCutPoints[725], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1450],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    xc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void vd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[903],
  const double weak_learner_Children[1806], const double weak_learner_CutPoint
  [903], const boolean_T weak_learner_NanCutPoints[903], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1806],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ud_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ve_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[689],
  const double weak_learner_Children[1378], const double weak_learner_CutPoint
  [689], const boolean_T weak_learner_NanCutPoints[689], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1378],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ne_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void w_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5875],
  const double weak_learner_Children[11750], const double weak_learner_CutPoint
  [5875], const boolean_T weak_learner_NanCutPoints[5875], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11750],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    y_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void wb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2885],
  const double weak_learner_Children[5770], const double weak_learner_CutPoint
  [2885], const boolean_T weak_learner_NanCutPoints[2885], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5770],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    yb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void wc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[695],
  const double weak_learner_Children[1390], const double weak_learner_CutPoint
  [695], const boolean_T weak_learner_NanCutPoints[695], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1390],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    yc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void wd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[781],
  const double weak_learner_Children[1562], const double weak_learner_CutPoint
  [781], const boolean_T weak_learner_NanCutPoints[781], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1562],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    hc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void we_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[697],
  const double weak_learner_Children[1394], const double weak_learner_CutPoint
  [697], const boolean_T weak_learner_NanCutPoints[697], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1394],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    xd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void x_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5653],
  const double weak_learner_Children[11306], const double weak_learner_CutPoint
  [5653], const boolean_T weak_learner_NanCutPoints[5653], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11306],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    ab_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void xb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2761],
  const double weak_learner_Children[5522], const double weak_learner_CutPoint
  [2761], const boolean_T weak_learner_NanCutPoints[2761], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5522],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ac_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void xc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[747],
  const double weak_learner_Children[1494], const double weak_learner_CutPoint
  [747], const boolean_T weak_learner_NanCutPoints[747], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1494],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    ad_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void xd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[937],
  const double weak_learner_Children[1874], const double weak_learner_CutPoint
  [937], const boolean_T weak_learner_NanCutPoints[937], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1874],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    vd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void xe_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[637],
  const double weak_learner_Children[1274], const double weak_learner_CutPoint
  [637], const boolean_T weak_learner_NanCutPoints[637], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1274],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    sd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void y_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[5745],
  const double weak_learner_Children[11490], const double weak_learner_CutPoint
  [5745], const boolean_T weak_learner_NanCutPoints[5745], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[11490],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 2;
    for (i = 0; i < trueCount; i++) {
      b_X_data[i] = X_data[tmp_data[i] - 1];
    }

    for (i = 0; i < trueCount; i++) {
      b_X_data[i + trueCount] = X_data[(tmp_data[i] + X_size[0]) - 1];
    }

    bb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void yb_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[2905],
  const double weak_learner_Children[5810], const double weak_learner_CutPoint
  [2905], const boolean_T weak_learner_NanCutPoints[2905], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[5810],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[1200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 3;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    bc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void yc_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[727],
  const double weak_learner_Children[1454], const double weak_learner_CutPoint
  [727], const boolean_T weak_learner_NanCutPoints[727], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1454],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[2000];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 5;
    for (i = 0; i < 5; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    bd_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void yd_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[775],
  const double weak_learner_Children[1550], const double weak_learner_CutPoint
  [775], const boolean_T weak_learner_NanCutPoints[775], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1550],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[5200];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 13;
    for (i = 0; i < 13; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    tc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

void ye_predictOneWithCache(const double X_data[], const int X_size[2], double
  cachedScore_data[], const int cachedScore_size[2], double cachedWeights_data[],
  const char combiner[15], const double weak_learner_CutPredictorIndex[585],
  const double weak_learner_Children[1170], const double weak_learner_CutPoint
  [585], const boolean_T weak_learner_NanCutPoints[585], const double
  weak_learner_ClassNames[2], const double weak_learner_Prior[2], const double
  weak_learner_Cost[4], const double weak_learner_ClassProbability[1170],
  boolean_T *cached, const double classnames[2], const boolean_T
  useObsForLearner_data[], const int useObsForLearner_size[1], boolean_T
  initCache, double score_data[], int score_size[2])
{
  static double b_X_data[6800];
  static double c_tmp_data[800];
  static double learnerscore_data[800];
  static double unusedU1_data[400];
  static short e_tmp_data[800];
  static short b_tmp_data[400];
  static short d_tmp_data[400];
  static short tmp_data[400];
  static boolean_T tf_data[800];
  int b_X_size[2];
  int iloc[2];
  int learnerscore_size[2];
  int tmp_size[2];
  int unusedU1_size[1];
  int exitg2;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T tf[2];
  boolean_T exitg1;
  boolean_T y;
  learnerscore_size[0] = cachedScore_size[0];
  learnerscore_size[1] = 2;
  loop_ub = cachedScore_size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  local_ismember(weak_learner_ClassNames, classnames, tf, iloc);
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner_size[0])) {
    if (!useObsForLearner_data[loop_ub - 1]) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    b_X_size[0] = trueCount;
    b_X_size[1] = 17;
    for (i = 0; i < 17; i++) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        b_X_data[loop_ub + trueCount * i] = X_data[(tmp_data[loop_ub] + X_size[0]
          * i) - 1];
      }
    }

    oe_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_ClassNames, weak_learner_Prior, weak_learner_Cost,
      weak_learner_ClassProbability, b_X_data, b_X_size, unusedU1_data,
      unusedU1_size, c_tmp_data, tmp_size);
    loop_ub = useObsForLearner_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        d_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[0] - 1)) -
        1] = c_tmp_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      learnerscore_data[(d_tmp_data[i] + learnerscore_size[0] * (iloc[1] - 1)) -
        1] = c_tmp_data[i + tmp_size[0]];
    }
  }

  if (initCache) {
    loop_ub = useObsForLearner_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[b_tmp_data[i] - 1] = 0.0;
    }

    for (i = 0; i < trueCount; i++) {
      cachedScore_data[(b_tmp_data[i] + cachedScore_size[0]) - 1] = 0.0;
    }
  } else {
    partialTrueCount = cachedScore_size[0];
    loop_ub = cachedScore_size[0] * cachedScore_size[1];
    for (i = 0; i < loop_ub; i++) {
      tf_data[i] = rtIsNaN(cachedScore_data[i]);
    }

    y = false;
    loop_ub = 1;
    do {
      exitg2 = 0;
      i = partialTrueCount << 1;
      if (loop_ub <= i) {
        if (!tf_data[loop_ub - 1]) {
          loop_ub++;
        } else {
          y = true;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (y) {
      loop_ub = i - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (tf_data[i]) {
          trueCount++;
          e_tmp_data[partialTrueCount] = (short)(i + 1);
          partialTrueCount++;
        }
      }

      for (i = 0; i < trueCount; i++) {
        cachedScore_data[e_tmp_data[i] - 1] = 0.0;
      }
    }
  }

  updateCache(learnerscore_data, learnerscore_size, cachedScore_data,
              cachedScore_size, cachedWeights_data, cached, combiner,
              useObsForLearner_data, useObsForLearner_size, score_data,
              score_size);
}

/* End of code generation (predictOneWithCache.c) */
