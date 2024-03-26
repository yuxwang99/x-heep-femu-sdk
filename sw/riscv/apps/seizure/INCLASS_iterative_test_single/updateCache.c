/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: updateCache.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "updateCache.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "bsxfun.h"
#include "ifWhileCond.h"
#include "rt_nonfinite.h"
#include "strcmp.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *learnerscore
 *                emxArray_real32_T *cachedScore
 *                emxArray_real32_T *cachedWeights
 *                boolean_T *cached
 *                const char combinerName[15]
 *                const emxArray_boolean_T *obsIndices
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void updateCache(const emxArray_real32_T *learnerscore,
                 emxArray_real32_T *cachedScore,
                 emxArray_real32_T *cachedWeights, boolean_T *cached,
                 const char combinerName[15],
                 const emxArray_boolean_T *obsIndices, emxArray_real32_T *score)
{
  emxArray_int32_T *r;
  emxArray_real32_T *b_cachedScore;
  emxArray_real32_T *b_cachedWeights;
  const float *learnerscore_data;
  float *b_cachedScore_data;
  float *cachedScore_data;
  float *cachedWeights_data;
  float *score_data;
  int b_i;
  int end;
  int i;
  int loop_ub;
  int *r1;
  const boolean_T *obsIndices_data;
  obsIndices_data = obsIndices->data;
  cachedWeights_data = cachedWeights->data;
  cachedScore_data = cachedScore->data;
  learnerscore_data = learnerscore->data;
  i = score->size[0] * score->size[1];
  score->size[0] = cachedScore->size[0];
  score->size[1] = 2;
  emxEnsureCapacity_real32_T(score, i);
  score_data = score->data;
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    score_data[i] = cachedScore_data[i];
  }
  if (!*cached) {
    *cached = true;
    end = obsIndices->size[0] - 1;
    loop_ub = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (obsIndices_data[b_i]) {
        loop_ub++;
      }
    }
    emxInit_int32_T(&r, 1);
    i = r->size[0];
    r->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r, i);
    r1 = r->data;
    loop_ub = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (obsIndices_data[b_i]) {
        r1[loop_ub] = b_i;
        loop_ub++;
      }
    }
    emxInit_real32_T(&b_cachedScore, 2);
    i = b_cachedScore->size[0] * b_cachedScore->size[1];
    b_cachedScore->size[0] = r->size[0];
    b_cachedScore->size[1] = 2;
    emxEnsureCapacity_real32_T(b_cachedScore, i);
    b_cachedScore_data = b_cachedScore->data;
    loop_ub = r->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub; end++) {
        b_cachedScore_data[end + b_cachedScore->size[0] * i] =
            cachedScore_data[r1[end] + cachedScore->size[0] * i] +
            learnerscore_data[r1[end] + learnerscore->size[0] * i];
      }
    }
    loop_ub = b_cachedScore->size[0];
    for (i = 0; i < 2; i++) {
      for (end = 0; end < loop_ub; end++) {
        cachedScore_data[r1[end] + cachedScore->size[0] * i] =
            b_cachedScore_data[end + b_cachedScore->size[0] * i];
      }
    }
    emxFree_real32_T(&b_cachedScore);
    emxInit_real32_T(&b_cachedWeights, 1);
    i = b_cachedWeights->size[0];
    b_cachedWeights->size[0] = r->size[0];
    emxEnsureCapacity_real32_T(b_cachedWeights, i);
    b_cachedScore_data = b_cachedWeights->data;
    loop_ub = r->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_cachedScore_data[i] = cachedWeights_data[r1[i]] + 1.0F;
    }
    loop_ub = b_cachedWeights->size[0];
    for (i = 0; i < loop_ub; i++) {
      cachedWeights_data[r1[i]] = b_cachedScore_data[i];
    }
    emxFree_real32_T(&b_cachedWeights);
    emxFree_int32_T(&r);
    if (e_strcmp(combinerName)) {
      i = cachedScore->size[0];
      for (b_i = 0; b_i < i; b_i++) {
        float f;
        f = cachedWeights_data[b_i];
        if (f == 0.0F) {
          boolean_T d_cachedScore[2];
          d_cachedScore[0] = (cachedScore_data[b_i] == 0.0F);
          d_cachedScore[1] =
              (cachedScore_data[b_i + cachedScore->size[0]] == 0.0F);
          if (b_ifWhileCond(d_cachedScore)) {
            score_data[b_i] = rtNaNF;
            score_data[b_i + score->size[0]] = rtNaNF;
          } else {
            d_cachedScore[0] = (cachedScore_data[b_i] < 0.0F);
            d_cachedScore[1] =
                (cachedScore_data[b_i + cachedScore->size[0]] < 0.0F);
            if (b_ifWhileCond(d_cachedScore)) {
              score_data[b_i] = rtMinusInfF;
              score_data[b_i + score->size[0]] = rtMinusInfF;
            } else {
              score_data[b_i] = rtInfF;
              score_data[b_i + score->size[0]] = rtInfF;
            }
          }
        } else {
          float c_cachedScore[2];
          float fv[2];
          c_cachedScore[0] = cachedScore_data[b_i];
          c_cachedScore[1] = cachedScore_data[b_i + cachedScore->size[0]];
          bsxfun(c_cachedScore, f, fv);
          score_data[b_i] = fv[0];
          score_data[b_i + score->size[0]] = fv[1];
        }
      }
    } else {
      i = cachedScore->size[0];
      for (b_i = 0; b_i < i; b_i++) {
        score_data[b_i] = cachedScore_data[b_i];
        score_data[b_i + score->size[0]] =
            cachedScore_data[b_i + cachedScore->size[0]];
      }
    }
  }
}

/*
 * File trailer for updateCache.c
 *
 * [EOF]
 */
