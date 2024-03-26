/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictOneWithCache.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "predictOneWithCache.h"
#include "CompactClassificationTree.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "any.h"
#include "isnan.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "updateCache.h"

/* Function Declarations */
static void b_and(emxArray_boolean_T *in1, const emxArray_boolean_T *in2, const
                  emxArray_boolean_T *in3);

/* Function Definitions */
/*
 * Arguments    : emxArray_boolean_T *in1
 *                const emxArray_boolean_T *in2
 *                const emxArray_boolean_T *in3
 * Return Type  : void
 */
static void b_and(emxArray_boolean_T *in1, const emxArray_boolean_T *in2, const
                  emxArray_boolean_T *in3)
{
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  const boolean_T *in2_data;
  const boolean_T *in3_data;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }

  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = 2;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = (in2_data[i1 * stride_0_0 + in2->size[0]
        * i] && in3_data[i1 * stride_1_0 + in3->size[0] * i]);
    }
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[829]
 *                const float weak_learner_Children[1658]
 *                const float weak_learner_CutPoint[829]
 *                const boolean_T weak_learner_NanCutPoints[829]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1658]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void ab_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[829], const float weak_learner_Children
  [1658], const float weak_learner_CutPoint[829], const boolean_T
  weak_learner_NanCutPoints[829], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1658],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    cb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[423]
 *                const float weak_learner_Children[846]
 *                const float weak_learner_CutPoint[423]
 *                const boolean_T weak_learner_NanCutPoints[423]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[846]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T ac_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[423], const float weak_learner_Children
  [846], const float weak_learner_CutPoint[423], const boolean_T
  weak_learner_NanCutPoints[423], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[846], const
  emxArray_boolean_T *useObsForLearner, boolean_T initCache, emxArray_real32_T
  *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    cc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1419]
 *                const float weak_learner_Children[2838]
 *                const float weak_learner_CutPoint[1419]
 *                const boolean_T weak_learner_NanCutPoints[1419]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2838]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T b_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1419], const float weak_learner_Children
  [2838], const float weak_learner_CutPoint[1419], const boolean_T
  weak_learner_NanCutPoints[1419], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2838],
  const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
  emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 4;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 4; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    d_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[651]
 *                const float weak_learner_Children[1302]
 *                const float weak_learner_CutPoint[651]
 *                const boolean_T weak_learner_NanCutPoints[651]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1302]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void bb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[651], const float weak_learner_Children
  [1302], const float weak_learner_CutPoint[651], const boolean_T
  weak_learner_NanCutPoints[651], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1302],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    db_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[425]
 *                const float weak_learner_Children[850]
 *                const float weak_learner_CutPoint[425]
 *                const boolean_T weak_learner_NanCutPoints[425]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[850]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T bc_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[425], const float weak_learner_Children
  [850], const float weak_learner_CutPoint[425], const boolean_T
  weak_learner_NanCutPoints[425], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[850], const
  emxArray_boolean_T *useObsForLearner, boolean_T initCache, emxArray_real32_T
  *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    dc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1433]
 *                const float weak_learner_Children[2866]
 *                const float weak_learner_CutPoint[1433]
 *                const boolean_T weak_learner_NanCutPoints[1433]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2866]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T c_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1433], const float weak_learner_Children
  [2866], const float weak_learner_CutPoint[1433], const boolean_T
  weak_learner_NanCutPoints[1433], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2866],
  const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
  emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 4;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 4; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    e_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[551]
 *                const float weak_learner_Children[1102]
 *                const float weak_learner_CutPoint[551]
 *                const boolean_T weak_learner_NanCutPoints[551]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1102]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void cb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[551], const float weak_learner_Children
  [1102], const float weak_learner_CutPoint[551], const boolean_T
  weak_learner_NanCutPoints[551], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1102],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    eb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[611]
 *                const float weak_learner_Children[1222]
 *                const float weak_learner_CutPoint[611]
 *                const boolean_T weak_learner_NanCutPoints[611]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1222]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T cc_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[611], const float weak_learner_Children
  [1222], const float weak_learner_CutPoint[611], const boolean_T
  weak_learner_NanCutPoints[611], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1222], const
  emxArray_boolean_T *useObsForLearner, boolean_T initCache, emxArray_real32_T
  *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    ec_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1495]
 *                const float weak_learner_Children[2990]
 *                const float weak_learner_CutPoint[1495]
 *                const boolean_T weak_learner_NanCutPoints[1495]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2990]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T d_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1495], const float weak_learner_Children
  [2990], const float weak_learner_CutPoint[1495], const boolean_T
  weak_learner_NanCutPoints[1495], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2990],
  const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
  emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 4;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 4; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    f_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[667]
 *                const float weak_learner_Children[1334]
 *                const float weak_learner_CutPoint[667]
 *                const boolean_T weak_learner_NanCutPoints[667]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1334]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void db_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[667], const float weak_learner_Children
  [1334], const float weak_learner_CutPoint[667], const boolean_T
  weak_learner_NanCutPoints[667], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1334],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    fb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[447]
 *                const float weak_learner_Children[894]
 *                const float weak_learner_CutPoint[447]
 *                const boolean_T weak_learner_NanCutPoints[447]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[894]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T dc_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[447], const float weak_learner_Children
  [894], const float weak_learner_CutPoint[447], const boolean_T
  weak_learner_NanCutPoints[447], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[894], const
  emxArray_boolean_T *useObsForLearner, boolean_T initCache, emxArray_real32_T
  *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    fc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1553]
 *                const float weak_learner_Children[3106]
 *                const float weak_learner_CutPoint[1553]
 *                const boolean_T weak_learner_NanCutPoints[1553]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[3106]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T e_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1553], const float weak_learner_Children
  [3106], const float weak_learner_CutPoint[1553], const boolean_T
  weak_learner_NanCutPoints[1553], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[3106],
  const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
  emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 4;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 4; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    g_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[607]
 *                const float weak_learner_Children[1214]
 *                const float weak_learner_CutPoint[607]
 *                const boolean_T weak_learner_NanCutPoints[607]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1214]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void eb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[607], const float weak_learner_Children
  [1214], const float weak_learner_CutPoint[607], const boolean_T
  weak_learner_NanCutPoints[607], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1214],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    gb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[593]
 *                const float weak_learner_Children[1186]
 *                const float weak_learner_CutPoint[593]
 *                const boolean_T weak_learner_NanCutPoints[593]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1186]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T ec_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[593], const float weak_learner_Children
  [1186], const float weak_learner_CutPoint[593], const boolean_T
  weak_learner_NanCutPoints[593], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1186], const
  emxArray_boolean_T *useObsForLearner, boolean_T initCache, emxArray_real32_T
  *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    gc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1383]
 *                const float weak_learner_Children[2766]
 *                const float weak_learner_CutPoint[1383]
 *                const boolean_T weak_learner_NanCutPoints[1383]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2766]
 *                const emxArray_boolean_T *useObsForLearner
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T f_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1383], const float weak_learner_Children
  [2766], const float weak_learner_CutPoint[1383], const boolean_T
  weak_learner_NanCutPoints[1383], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2766],
  const emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score)
{
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r3;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int end;
  int i;
  int loop_ub;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub] = i;
        loop_ub++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r3, 2);
    h_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r3);
    b_X_data = r3->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub = r3->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r3->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r3);
  }

  end = useObsForLearner->size[0] - 1;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      loop_ub++;
    }
  }

  emxInit_int32_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(r1, i);
  r2 = r1->data;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      r2[loop_ub] = i;
      loop_ub++;
    }
  }

  loop_ub = r1->size[0];
  for (i = 0; i < 2; i++) {
    for (end = 0; end < loop_ub; end++) {
      cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
    }
  }

  emxFree_int32_T(&r1);
  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[623]
 *                const float weak_learner_Children[1246]
 *                const float weak_learner_CutPoint[623]
 *                const boolean_T weak_learner_NanCutPoints[623]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1246]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void fb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[623], const float weak_learner_Children
  [1246], const float weak_learner_CutPoint[623], const boolean_T
  weak_learner_NanCutPoints[623], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1246],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    hb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[343]
 *                const float weak_learner_Children[686]
 *                const float weak_learner_CutPoint[343]
 *                const boolean_T weak_learner_NanCutPoints[343]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[686]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T fc_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[343], const float weak_learner_Children
  [686], const float weak_learner_CutPoint[343], const boolean_T
  weak_learner_NanCutPoints[343], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[686], const
  emxArray_boolean_T *useObsForLearner, boolean_T initCache, emxArray_real32_T
  *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    hc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1323]
 *                const float weak_learner_Children[2646]
 *                const float weak_learner_CutPoint[1323]
 *                const boolean_T weak_learner_NanCutPoints[1323]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2646]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void g_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1323], const float weak_learner_Children
  [2646], const float weak_learner_CutPoint[1323], const boolean_T
  weak_learner_NanCutPoints[1323], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2646],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    i_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[539]
 *                const float weak_learner_Children[1078]
 *                const float weak_learner_CutPoint[539]
 *                const boolean_T weak_learner_NanCutPoints[539]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1078]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void gb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[539], const float weak_learner_Children
  [1078], const float weak_learner_CutPoint[539], const boolean_T
  weak_learner_NanCutPoints[539], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1078],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    ib_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[463]
 *                const float weak_learner_Children[926]
 *                const float weak_learner_CutPoint[463]
 *                const boolean_T weak_learner_NanCutPoints[463]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[926]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T gc_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[463], const float weak_learner_Children
  [926], const float weak_learner_CutPoint[463], const boolean_T
  weak_learner_NanCutPoints[463], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[926], const
  emxArray_boolean_T *useObsForLearner, boolean_T initCache, emxArray_real32_T
  *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    ic_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1363]
 *                const float weak_learner_Children[2726]
 *                const float weak_learner_CutPoint[1363]
 *                const boolean_T weak_learner_NanCutPoints[1363]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2726]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void h_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1363], const float weak_learner_Children
  [2726], const float weak_learner_CutPoint[1363], const boolean_T
  weak_learner_NanCutPoints[1363], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2726],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    j_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[521]
 *                const float weak_learner_Children[1042]
 *                const float weak_learner_CutPoint[521]
 *                const boolean_T weak_learner_NanCutPoints[521]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1042]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void hb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[521], const float weak_learner_Children
  [1042], const float weak_learner_CutPoint[521], const boolean_T
  weak_learner_NanCutPoints[521], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1042],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    jb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[581]
 *                const float weak_learner_Children[1162]
 *                const float weak_learner_CutPoint[581]
 *                const boolean_T weak_learner_NanCutPoints[581]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1162]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T hc_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[581], const float weak_learner_Children
  [1162], const float weak_learner_CutPoint[581], const boolean_T
  weak_learner_NanCutPoints[581], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1162], const
  emxArray_boolean_T *useObsForLearner, boolean_T initCache, emxArray_real32_T
  *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    jc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1265]
 *                const float weak_learner_Children[2530]
 *                const float weak_learner_CutPoint[1265]
 *                const boolean_T weak_learner_NanCutPoints[1265]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2530]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void i_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1265], const float weak_learner_Children
  [2530], const float weak_learner_CutPoint[1265], const boolean_T
  weak_learner_NanCutPoints[1265], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2530],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    k_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[527]
 *                const float weak_learner_Children[1054]
 *                const float weak_learner_CutPoint[527]
 *                const boolean_T weak_learner_NanCutPoints[527]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1054]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void ib_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[527], const float weak_learner_Children
  [1054], const float weak_learner_CutPoint[527], const boolean_T
  weak_learner_NanCutPoints[527], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1054],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    kb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1349]
 *                const float weak_learner_Children[2698]
 *                const float weak_learner_CutPoint[1349]
 *                const boolean_T weak_learner_NanCutPoints[1349]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2698]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void j_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1349], const float weak_learner_Children
  [2698], const float weak_learner_CutPoint[1349], const boolean_T
  weak_learner_NanCutPoints[1349], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2698],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    l_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[543]
 *                const float weak_learner_Children[1086]
 *                const float weak_learner_CutPoint[543]
 *                const boolean_T weak_learner_NanCutPoints[543]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1086]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void jb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[543], const float weak_learner_Children
  [1086], const float weak_learner_CutPoint[543], const boolean_T
  weak_learner_NanCutPoints[543], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1086],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    lb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1279]
 *                const float weak_learner_Children[2558]
 *                const float weak_learner_CutPoint[1279]
 *                const boolean_T weak_learner_NanCutPoints[1279]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2558]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void k_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1279], const float weak_learner_Children
  [2558], const float weak_learner_CutPoint[1279], const boolean_T
  weak_learner_NanCutPoints[1279], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2558],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    m_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[467]
 *                const float weak_learner_Children[934]
 *                const float weak_learner_CutPoint[467]
 *                const boolean_T weak_learner_NanCutPoints[467]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[934]
 *                const emxArray_boolean_T *useObsForLearner
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T kb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[467], const float weak_learner_Children
  [934], const float weak_learner_CutPoint[467], const boolean_T
  weak_learner_NanCutPoints[467], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[934], const
  emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score)
{
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r3;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int end;
  int i;
  int loop_ub;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub] = i;
        loop_ub++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r3, 2);
    mb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r3);
    b_X_data = r3->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub = r3->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r3->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r3);
  }

  end = useObsForLearner->size[0] - 1;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      loop_ub++;
    }
  }

  emxInit_int32_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(r1, i);
  r2 = r1->data;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      r2[loop_ub] = i;
      loop_ub++;
    }
  }

  loop_ub = r1->size[0];
  for (i = 0; i < 2; i++) {
    for (end = 0; end < loop_ub; end++) {
      cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
    }
  }

  emxFree_int32_T(&r1);
  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1611]
 *                const float weak_learner_Children[3222]
 *                const float weak_learner_CutPoint[1611]
 *                const boolean_T weak_learner_NanCutPoints[1611]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[3222]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void l_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1611], const float weak_learner_Children
  [3222], const float weak_learner_CutPoint[1611], const boolean_T
  weak_learner_NanCutPoints[1611], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[3222],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    n_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[611]
 *                const float weak_learner_Children[1222]
 *                const float weak_learner_CutPoint[611]
 *                const boolean_T weak_learner_NanCutPoints[611]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1222]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void lb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[611], const float weak_learner_Children
  [1222], const float weak_learner_CutPoint[611], const boolean_T
  weak_learner_NanCutPoints[611], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1222],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    nb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1437]
 *                const float weak_learner_Children[2874]
 *                const float weak_learner_CutPoint[1437]
 *                const boolean_T weak_learner_NanCutPoints[1437]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2874]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void m_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1437], const float weak_learner_Children
  [2874], const float weak_learner_CutPoint[1437], const boolean_T
  weak_learner_NanCutPoints[1437], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2874],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    o_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[457]
 *                const float weak_learner_Children[914]
 *                const float weak_learner_CutPoint[457]
 *                const boolean_T weak_learner_NanCutPoints[457]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[914]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void mb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[457], const float weak_learner_Children
  [914], const float weak_learner_CutPoint[457], const boolean_T
  weak_learner_NanCutPoints[457], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[914],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    ob_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1369]
 *                const float weak_learner_Children[2738]
 *                const float weak_learner_CutPoint[1369]
 *                const boolean_T weak_learner_NanCutPoints[1369]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2738]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void n_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1369], const float weak_learner_Children
  [2738], const float weak_learner_CutPoint[1369], const boolean_T
  weak_learner_NanCutPoints[1369], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2738],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    p_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[451]
 *                const float weak_learner_Children[902]
 *                const float weak_learner_CutPoint[451]
 *                const boolean_T weak_learner_NanCutPoints[451]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[902]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void nb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[451], const float weak_learner_Children
  [902], const float weak_learner_CutPoint[451], const boolean_T
  weak_learner_NanCutPoints[451], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[902],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    pb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1367]
 *                const float weak_learner_Children[2734]
 *                const float weak_learner_CutPoint[1367]
 *                const boolean_T weak_learner_NanCutPoints[1367]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2734]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void o_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1367], const float weak_learner_Children
  [2734], const float weak_learner_CutPoint[1367], const boolean_T
  weak_learner_NanCutPoints[1367], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2734],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    q_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[425]
 *                const float weak_learner_Children[850]
 *                const float weak_learner_CutPoint[425]
 *                const boolean_T weak_learner_NanCutPoints[425]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[850]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void ob_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[425], const float weak_learner_Children
  [850], const float weak_learner_CutPoint[425], const boolean_T
  weak_learner_NanCutPoints[425], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[850],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    qb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1479]
 *                const float weak_learner_Children[2958]
 *                const float weak_learner_CutPoint[1479]
 *                const boolean_T weak_learner_NanCutPoints[1479]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2958]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void p_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1479], const float weak_learner_Children
  [2958], const float weak_learner_CutPoint[1479], const boolean_T
  weak_learner_NanCutPoints[1479], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2958],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    r_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[343]
 *                const float weak_learner_Children[686]
 *                const float weak_learner_CutPoint[343]
 *                const boolean_T weak_learner_NanCutPoints[343]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[686]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void pb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[343], const float weak_learner_Children
  [686], const float weak_learner_CutPoint[343], const boolean_T
  weak_learner_NanCutPoints[343], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[686],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    rb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1581]
 *                const float weak_learner_Children[3162]
 *                const float weak_learner_CutPoint[1581]
 *                const boolean_T weak_learner_NanCutPoints[1581]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[3162]
 *                const emxArray_boolean_T *useObsForLearner
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1581], const float weak_learner_Children
  [3162], const float weak_learner_CutPoint[1581], const boolean_T
  weak_learner_NanCutPoints[1581], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[3162],
  const emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score)
{
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r3;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int end;
  int i;
  int loop_ub;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub] = i;
        loop_ub++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 4;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub = r->size[0];
    for (i = 0; i < 4; i++) {
      for (end = 0; end < loop_ub; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r3, 2);
    c_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r3);
    b_X_data = r3->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub = r3->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r3->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r3);
  }

  end = useObsForLearner->size[0] - 1;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      loop_ub++;
    }
  }

  emxInit_int32_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(r1, i);
  r2 = r1->data;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      r2[loop_ub] = i;
      loop_ub++;
    }
  }

  loop_ub = r1->size[0];
  for (i = 0; i < 2; i++) {
    for (end = 0; end < loop_ub; end++) {
      cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
    }
  }

  emxFree_int32_T(&r1);
  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1469]
 *                const float weak_learner_Children[2938]
 *                const float weak_learner_CutPoint[1469]
 *                const boolean_T weak_learner_NanCutPoints[1469]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2938]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void q_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1469], const float weak_learner_Children
  [2938], const float weak_learner_CutPoint[1469], const boolean_T
  weak_learner_NanCutPoints[1469], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2938],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    s_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[537]
 *                const float weak_learner_Children[1074]
 *                const float weak_learner_CutPoint[537]
 *                const boolean_T weak_learner_NanCutPoints[537]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1074]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void qb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[537], const float weak_learner_Children
  [1074], const float weak_learner_CutPoint[537], const boolean_T
  weak_learner_NanCutPoints[537], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1074],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    sb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1663]
 *                const float weak_learner_Children[3326]
 *                const float weak_learner_CutPoint[1663]
 *                const boolean_T weak_learner_NanCutPoints[1663]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[3326]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void r_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1663], const float weak_learner_Children
  [3326], const float weak_learner_CutPoint[1663], const boolean_T
  weak_learner_NanCutPoints[1663], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[3326],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    t_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[529]
 *                const float weak_learner_Children[1058]
 *                const float weak_learner_CutPoint[529]
 *                const boolean_T weak_learner_NanCutPoints[529]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1058]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void rb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[529], const float weak_learner_Children
  [1058], const float weak_learner_CutPoint[529], const boolean_T
  weak_learner_NanCutPoints[529], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1058],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    tb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1411]
 *                const float weak_learner_Children[2822]
 *                const float weak_learner_CutPoint[1411]
 *                const boolean_T weak_learner_NanCutPoints[1411]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2822]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void s_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1411], const float weak_learner_Children
  [2822], const float weak_learner_CutPoint[1411], const boolean_T
  weak_learner_NanCutPoints[1411], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2822],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    u_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[427]
 *                const float weak_learner_Children[854]
 *                const float weak_learner_CutPoint[427]
 *                const boolean_T weak_learner_NanCutPoints[427]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[854]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void sb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[427], const float weak_learner_Children
  [854], const float weak_learner_CutPoint[427], const boolean_T
  weak_learner_NanCutPoints[427], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[854],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    ub_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[1317]
 *                const float weak_learner_Children[2634]
 *                const float weak_learner_CutPoint[1317]
 *                const boolean_T weak_learner_NanCutPoints[1317]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[2634]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void t_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[1317], const float weak_learner_Children
  [2634], const float weak_learner_CutPoint[1317], const boolean_T
  weak_learner_NanCutPoints[1317], const float weak_learner_Prior[2], const
  float weak_learner_Cost[4], const float weak_learner_ClassProbability[2634],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 11;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 11; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    v_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[447]
 *                const float weak_learner_Children[894]
 *                const float weak_learner_CutPoint[447]
 *                const boolean_T weak_learner_NanCutPoints[447]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[894]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void tb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[447], const float weak_learner_Children
  [894], const float weak_learner_CutPoint[447], const boolean_T
  weak_learner_NanCutPoints[447], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[894],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    vb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[709]
 *                const float weak_learner_Children[1418]
 *                const float weak_learner_CutPoint[709]
 *                const boolean_T weak_learner_NanCutPoints[709]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1418]
 *                const emxArray_boolean_T *useObsForLearner
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T u_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[709], const float weak_learner_Children
  [1418], const float weak_learner_CutPoint[709], const boolean_T
  weak_learner_NanCutPoints[709], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1418], const
  emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score)
{
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r3;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int end;
  int i;
  int loop_ub;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub] = i;
        loop_ub++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r3, 2);
    w_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r3);
    b_X_data = r3->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub = r3->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r3->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r3);
  }

  end = useObsForLearner->size[0] - 1;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      loop_ub++;
    }
  }

  emxInit_int32_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(r1, i);
  r2 = r1->data;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      r2[loop_ub] = i;
      loop_ub++;
    }
  }

  loop_ub = r1->size[0];
  for (i = 0; i < 2; i++) {
    for (end = 0; end < loop_ub; end++) {
      cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
    }
  }

  emxFree_int32_T(&r1);
  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[563]
 *                const float weak_learner_Children[1126]
 *                const float weak_learner_CutPoint[563]
 *                const boolean_T weak_learner_NanCutPoints[563]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1126]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void ub_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[563], const float weak_learner_Children
  [1126], const float weak_learner_CutPoint[563], const boolean_T
  weak_learner_NanCutPoints[563], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1126],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    wb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[783]
 *                const float weak_learner_Children[1566]
 *                const float weak_learner_CutPoint[783]
 *                const boolean_T weak_learner_NanCutPoints[783]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1566]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void v_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[783], const float weak_learner_Children
  [1566], const float weak_learner_CutPoint[783], const boolean_T
  weak_learner_NanCutPoints[783], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1566],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    x_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[469]
 *                const float weak_learner_Children[938]
 *                const float weak_learner_CutPoint[469]
 *                const boolean_T weak_learner_NanCutPoints[469]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[938]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void vb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[469], const float weak_learner_Children
  [938], const float weak_learner_CutPoint[469], const boolean_T
  weak_learner_NanCutPoints[469], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[938],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    xb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[649]
 *                const float weak_learner_Children[1298]
 *                const float weak_learner_CutPoint[649]
 *                const boolean_T weak_learner_NanCutPoints[649]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1298]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void w_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[649], const float weak_learner_Children
  [1298], const float weak_learner_CutPoint[649], const boolean_T
  weak_learner_NanCutPoints[649], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1298],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    y_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[471]
 *                const float weak_learner_Children[942]
 *                const float weak_learner_CutPoint[471]
 *                const boolean_T weak_learner_NanCutPoints[471]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[942]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void wb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[471], const float weak_learner_Children
  [942], const float weak_learner_CutPoint[471], const boolean_T
  weak_learner_NanCutPoints[471], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[942],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 13;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 13; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    yb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[765]
 *                const float weak_learner_Children[1530]
 *                const float weak_learner_CutPoint[765]
 *                const boolean_T weak_learner_NanCutPoints[765]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1530]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void x_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[765], const float weak_learner_Children
  [1530], const float weak_learner_CutPoint[765], const boolean_T
  weak_learner_NanCutPoints[765], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1530],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    ab_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[451]
 *                const float weak_learner_Children[902]
 *                const float weak_learner_CutPoint[451]
 *                const boolean_T weak_learner_NanCutPoints[451]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[902]
 *                const emxArray_boolean_T *useObsForLearner
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T xb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[451], const float weak_learner_Children
  [902], const float weak_learner_CutPoint[451], const boolean_T
  weak_learner_NanCutPoints[451], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[902], const
  emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score)
{
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r3;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int end;
  int i;
  int loop_ub;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub] = i;
        loop_ub++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r3, 2);
    ac_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r3);
    b_X_data = r3->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub = r3->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r3->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r3);
  }

  end = useObsForLearner->size[0] - 1;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      loop_ub++;
    }
  }

  emxInit_int32_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(r1, i);
  r2 = r1->data;
  loop_ub = 0;
  for (i = 0; i <= end; i++) {
    if (useObsForLearner_data[i]) {
      r2[loop_ub] = i;
      loop_ub++;
    }
  }

  loop_ub = r1->size[0];
  for (i = 0; i < 2; i++) {
    for (end = 0; end < loop_ub; end++) {
      cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
    }
  }

  emxFree_int32_T(&r1);
  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[699]
 *                const float weak_learner_Children[1398]
 *                const float weak_learner_CutPoint[699]
 *                const boolean_T weak_learner_NanCutPoints[699]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1398]
 *                boolean_T *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void y_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[699], const float weak_learner_Children
  [1398], const float weak_learner_CutPoint[699], const boolean_T
  weak_learner_NanCutPoints[699], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1398],
  boolean_T *cached, const emxArray_boolean_T *useObsForLearner, boolean_T
  initCache, emxArray_real32_T *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 12;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 12; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    bb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                const char combiner[15]
 *                const float weak_learner_CutPredictorIndex[555]
 *                const float weak_learner_Children[1110]
 *                const float weak_learner_CutPoint[555]
 *                const boolean_T weak_learner_NanCutPoints[555]
 *                const float weak_learner_Prior[2]
 *                const float weak_learner_Cost[4]
 *                const float weak_learner_ClassProbability[1110]
 *                const emxArray_boolean_T *useObsForLearner
 *                boolean_T initCache
 *                emxArray_real32_T *score
 * Return Type  : boolean_T
 */
boolean_T yb_predictOneWithCache(const emxArray_real32_T *X, emxArray_real32_T
  *cachedScore, emxArray_real32_T *cachedWeights, const char combiner[15], const
  float weak_learner_CutPredictorIndex[555], const float weak_learner_Children
  [1110], const float weak_learner_CutPoint[555], const boolean_T
  weak_learner_NanCutPoints[555], const float weak_learner_Prior[2], const float
  weak_learner_Cost[4], const float weak_learner_ClassProbability[1110], const
  emxArray_boolean_T *useObsForLearner, boolean_T initCache, emxArray_real32_T
  *score)
{
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *a__2;
  emxArray_real32_T *b_X;
  emxArray_real32_T *learnerscore;
  emxArray_real32_T *r7;
  const float *X_data;
  float *b_X_data;
  float *cachedScore_data;
  float *learnerscore_data;
  int c_tf;
  int end;
  int i;
  int loop_ub_tmp;
  int *r2;
  const boolean_T *useObsForLearner_data;
  boolean_T cached;
  boolean_T *r4;
  boolean_T *r6;
  boolean_T *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real32_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real32_T(learnerscore, i);
  learnerscore_data = learnerscore->data;
  loop_ub_tmp = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    learnerscore_data[i] = rtNaNF;
  }

  if (c_any(useObsForLearner)) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r, i);
    r2 = r->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    emxInit_real32_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 17;
    emxEnsureCapacity_real32_T(b_X, i);
    b_X_data = b_X->data;
    loop_ub_tmp = r->size[0];
    for (i = 0; i < 17; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        b_X_data[end + b_X->size[0] * i] = X_data[r2[end] + X->size[0] * i];
      }
    }

    emxInit_real32_T(&a__2, 1);
    emxInit_real32_T(&r7, 2);
    bc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r7);
    b_X_data = r7->data;
    emxFree_real32_T(&b_X);
    emxFree_real32_T(&a__2);
    loop_ub_tmp = r7->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        learnerscore_data[r2[end] + learnerscore->size[0] * i] = b_X_data[end +
          r7->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real32_T(&r7);
  }

  if (initCache) {
    end = useObsForLearner->size[0] - 1;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        loop_ub_tmp++;
      }
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(r1, i);
    r2 = r1->data;
    loop_ub_tmp = 0;
    for (i = 0; i <= end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub_tmp] = i;
        loop_ub_tmp++;
      }
    }

    loop_ub_tmp = r1->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub_tmp; end++) {
        cachedScore_data[r2[end] + cachedScore->size[0] * i] = 0.0F;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    e_isnan(cachedScore, tf);
    tf_data = tf->data;
    loop_ub_tmp = tf->size[0] << 1;
    b_tf = *tf;
    c_tf = loop_ub_tmp;
    b_tf.size = &c_tf;
    b_tf.numDimensions = 1;
    if (c_any(&b_tf)) {
      emxInit_boolean_T(&r3, 2);
      d_repmat(useObsForLearner, r3);
      r4 = r3->data;
      emxInit_boolean_T(&r5, 2);
      if (tf->size[0] == r3->size[0]) {
        i = r5->size[0] * r5->size[1];
        r5->size[0] = tf->size[0];
        r5->size[1] = 2;
        emxEnsureCapacity_boolean_T(r5, i);
        r6 = r5->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          r6[i] = (tf_data[i] && r4[i]);
        }
      } else {
        b_and(r5, tf, r3);
        r6 = r5->data;
      }

      emxFree_boolean_T(&r3);
      end = (r5->size[0] << 1) - 1;
      for (i = 0; i <= end; i++) {
        if (r6[i]) {
          cachedScore_data[i] = 0.0F;
        }
      }

      emxFree_boolean_T(&r5);
    }

    emxFree_boolean_T(&tf);
  }

  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real32_T(&learnerscore);
  return cached;
}

/*
 * File trailer for predictOneWithCache.c
 *
 * [EOF]
 */
