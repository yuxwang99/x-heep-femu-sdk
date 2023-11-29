/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationEnsemble.c
 *
 * Code generation for function 'CompactClassificationEnsemble'
 *
 */

/* Include files */
#include "CompactClassificationEnsemble.h"
#include "CompactClassificationModel.h"
#include "aggregatePredict.h"
#include "profile_Yuxuan_iteration_data.h"
#include "profile_Yuxuan_iteration_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void c_CompactClassificationEnsemble(boolean_T obj_IsCached[30], double
  obj_LearnerWeights[30], double obj_ClassNames[2], int obj_ClassNamesLength[2],
  c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
  boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4])
{
  int i;
  obj_ClassNames[0] = 0.0;
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNames[1] = 1.0;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 30; i++) {
    obj_LearnerWeights[i] = 1.0;
    obj_IsCached[i] = false;
  }

  obj_Prior[0] = 0.40827998740686328;
  obj_Prior[1] = 0.59172001259313678;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

void d_CompactClassificationEnsemble(const boolean_T obj_IsCached[30], const
  double obj_ClassNames[2], const double obj_Prior[2], const double Xin_data[],
  const int Xin_size[2], double labels_data[], int labels_size[1], double
  score_data[], int score_size[2])
{
  static boolean_T tmp_data[12000];
  int tmp_size[2];
  int i;
  int loop_ub;
  boolean_T bv[30];
  if (Xin_size[0] == 0) {
    score_size[0] = 0;
    score_size[1] = 2;
    labels_size[0] = 0;
  } else {
    score_size[0] = Xin_size[0];
    score_size[1] = 2;
    loop_ub = Xin_size[0] << 1;
    if (0 <= loop_ub - 1) {
      memset(&score_data[0], 0, loop_ub * sizeof(double));
    }

    for (i = 0; i < 30; i++) {
      bv[i] = true;
    }

    tmp_size[0] = Xin_size[0];
    tmp_size[1] = 30;
    loop_ub = Xin_size[0] * 30;
    for (i = 0; i < loop_ub; i++) {
      tmp_data[i] = true;
    }

    aggregatePredict(Xin_data, Xin_size, score_data, score_size, obj_IsCached,
                     obj_ClassNames, bv, tmp_data, tmp_size);
    c_CompactClassificationModel_ma(obj_ClassNames, obj_Prior, score_data,
      score_size, labels_data, labels_size);
  }
}

void e_CompactClassificationEnsemble(const boolean_T obj_IsCached[30], const
  double obj_ClassNames[2], const double obj_Prior[2], const double Xin_data[],
  const int Xin_size[2], double labels_data[], int labels_size[1], double
  score_data[], int score_size[2])
{
  static boolean_T tmp_data[12000];
  int tmp_size[2];
  int i;
  int loop_ub;
  boolean_T bv[30];
  if (Xin_size[0] == 0) {
    score_size[0] = 0;
    score_size[1] = 2;
    labels_size[0] = 0;
  } else {
    score_size[0] = Xin_size[0];
    score_size[1] = 2;
    loop_ub = Xin_size[0] << 1;
    if (0 <= loop_ub - 1) {
      memset(&score_data[0], 0, loop_ub * sizeof(double));
    }

    for (i = 0; i < 30; i++) {
      bv[i] = true;
    }

    tmp_size[0] = Xin_size[0];
    tmp_size[1] = 30;
    loop_ub = Xin_size[0] * 30;
    for (i = 0; i < loop_ub; i++) {
      tmp_data[i] = true;
    }

    e_aggregatePredict(Xin_data, Xin_size, score_data, score_size, obj_IsCached,
                       obj_ClassNames, bv, tmp_data, tmp_size);
    c_CompactClassificationModel_ma(obj_ClassNames, obj_Prior, score_data,
      score_size, labels_data, labels_size);
  }
}

/* End of code generation (CompactClassificationEnsemble.c) */
