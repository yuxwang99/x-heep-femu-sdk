/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_classifier.c
 *
 * Code generation for function 'test_classifier'
 *
 */

/* Include files */
#include "test_classifier.h"
#include "CompactClassificationModel.h"
#include "aggregatePredict.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_test_classifier(const double features_data[], const int features_size[2],
  const boolean_T model_IsCached[30], const double model_ClassNames[2], const
  double model_Prior[2], double thrshd, double *output, double *score_seizure,
  double *score_no_seizure)
{
  static double scoreIn_data[800];
  static double labels_data[400];
  static boolean_T tmp_data[12000];
  emxArray_real_T *b_scores_positive_window;
  emxArray_real_T *scores_negative_window;
  emxArray_real_T *scores_positive_window;
  double cont_pos;
  double d;
  double y;
  int scoreIn_size[2];
  int tmp_size[2];
  int labels_size[1];
  int i;
  int i1;
  int j;
  int k;
  int vlen;
  boolean_T bv[30];
  boolean_T exitg1;
  if (features_size[0] == 0) {
    scoreIn_size[0] = 0;
    labels_size[0] = 0;
  } else {
    scoreIn_size[0] = features_size[0];
    scoreIn_size[1] = 2;
    vlen = features_size[0] << 1;
    if (0 <= vlen - 1) {
      memset(&scoreIn_data[0], 0, vlen * sizeof(double));
    }

    for (i = 0; i < 30; i++) {
      bv[i] = true;
    }

    tmp_size[0] = features_size[0];
    tmp_size[1] = 30;
    vlen = features_size[0] * 30;
    for (i = 0; i < vlen; i++) {
      tmp_data[i] = true;
    }

    d_aggregatePredict(features_data, features_size, scoreIn_data, scoreIn_size,
                       model_IsCached, model_ClassNames, bv, tmp_data, tmp_size);
    c_CompactClassificationModel_ma(model_ClassNames, model_Prior, scoreIn_data,
      scoreIn_size, labels_data, labels_size);
  }

  cont_pos = 0.0;
  vlen = 0;
  exitg1 = false;
  while ((!exitg1) && (vlen <= labels_size[0] - 1)) {
    if (labels_data[vlen] == 1.0) {
      cont_pos++;
      if (cont_pos >= thrshd) {
        exitg1 = true;
      } else {
        vlen++;
      }
    } else {
      cont_pos = 0.0;
      vlen++;
    }
  }

  emxInit_real_T(&scores_positive_window, 2);
  emxInit_real_T(&scores_negative_window, 2);

  /*  ---- compute according to the thrshd  */
  scores_positive_window->size[0] = 0;
  scores_positive_window->size[1] = 1;
  scores_negative_window->size[0] = 0;
  scores_negative_window->size[1] = 1;
  i = (int)(((double)labels_size[0] - thrshd) + 1.0);
  emxInit_real_T(&b_scores_positive_window, 1);
  for (j = 0; j < i; j++) {
    /*  scores that it is a seizure */
    d = (((double)j + 1.0) + thrshd) - 1.0;
    if ((double)j + 1.0 > d) {
      i1 = -1;
      vlen = -1;
    } else {
      i1 = j - 1;
      vlen = (int)d - 1;
    }

    vlen -= i1;
    if (vlen == 0) {
      y = 0.0;
    } else {
      y = scoreIn_data[(i1 + scoreIn_size[0]) + 1];
      for (k = 2; k <= vlen; k++) {
        y += scoreIn_data[(i1 + k) + scoreIn_size[0]];
      }
    }

    vlen = scores_positive_window->size[0];
    i1 = b_scores_positive_window->size[0];
    b_scores_positive_window->size[0] = scores_positive_window->size[0] + 1;
    emxEnsureCapacity_real_T(b_scores_positive_window, i1);
    for (i1 = 0; i1 < vlen; i1++) {
      b_scores_positive_window->data[i1] = scores_positive_window->data[i1];
    }

    b_scores_positive_window->data[scores_positive_window->size[0]] = y / thrshd;
    i1 = scores_positive_window->size[0] * scores_positive_window->size[1];
    scores_positive_window->size[0] = b_scores_positive_window->size[0];
    scores_positive_window->size[1] = 1;
    emxEnsureCapacity_real_T(scores_positive_window, i1);
    vlen = b_scores_positive_window->size[0];
    for (i1 = 0; i1 < vlen; i1++) {
      scores_positive_window->data[i1] = b_scores_positive_window->data[i1];
    }

    /*  scores that it is not a seizure */
    if ((double)j + 1.0 > d) {
      i1 = -1;
      vlen = -1;
    } else {
      i1 = j - 1;
      vlen = (int)d - 1;
    }

    vlen -= i1;
    if (vlen == 0) {
      y = 0.0;
    } else {
      y = scoreIn_data[i1 + 1];
      for (k = 2; k <= vlen; k++) {
        y += scoreIn_data[i1 + k];
      }
    }

    vlen = scores_negative_window->size[0];
    i1 = b_scores_positive_window->size[0];
    b_scores_positive_window->size[0] = scores_negative_window->size[0] + 1;
    emxEnsureCapacity_real_T(b_scores_positive_window, i1);
    for (i1 = 0; i1 < vlen; i1++) {
      b_scores_positive_window->data[i1] = scores_negative_window->data[i1];
    }

    b_scores_positive_window->data[scores_negative_window->size[0]] = y / thrshd;
    i1 = scores_negative_window->size[0] * scores_negative_window->size[1];
    scores_negative_window->size[0] = b_scores_positive_window->size[0];
    scores_negative_window->size[1] = 1;
    emxEnsureCapacity_real_T(scores_negative_window, i1);
    vlen = b_scores_positive_window->size[0];
    for (i1 = 0; i1 < vlen; i1++) {
      scores_negative_window->data[i1] = b_scores_positive_window->data[i1];
    }
  }

  emxFree_real_T(&b_scores_positive_window);

  /*  True positive % Confidence that it is a seizure */
  vlen = scores_positive_window->size[0];
  if (scores_positive_window->size[0] == 0) {
    y = 0.0;
  } else {
    y = scores_positive_window->data[0];
    for (k = 2; k <= vlen; k++) {
      y += scores_positive_window->data[k - 1];
    }
  }

  emxFree_real_T(&scores_positive_window);
  vlen = scoreIn_size[0];
  if (vlen <= 2) {
    vlen = 2;
  }

  if (scoreIn_size[0] == 0) {
    vlen = 0;
  }

  *score_seizure = y / (((double)vlen - thrshd) + 1.0);

  /*  False negative % Confidence that it is not a seizure */
  vlen = scores_negative_window->size[0];
  if (scores_negative_window->size[0] == 0) {
    y = 0.0;
  } else {
    y = scores_negative_window->data[0];
    for (k = 2; k <= vlen; k++) {
      y += scores_negative_window->data[k - 1];
    }
  }

  emxFree_real_T(&scores_negative_window);
  vlen = scoreIn_size[0];
  if (vlen <= 2) {
    vlen = 2;
  }

  if (scoreIn_size[0] == 0) {
    vlen = 0;
  }

  *score_no_seizure = y / (((double)vlen - thrshd) + 1.0);

  /*  determine the result */
  /*  If there are no indexes of seizure in the segment then it is not a sizure, */
  /*  otherwise the predicted class for the segment is seizure */
  *output = 0.0;
  if (cont_pos == thrshd) {
    /* the predicted class for the segment is seizure */
    *output = 1.0;
  }
}

void test_classifier(const double features_data[], const int features_size[2],
                     const boolean_T model_IsCached[30], const double
                     model_ClassNames[2], const double model_Prior[2], double
                     thrshd, double *output, double *score_seizure, double
                     *score_no_seizure)
{
  static double scoreIn_data[800];
  static double labels_data[400];
  static boolean_T tmp_data[12000];
  emxArray_real_T *b_scores_positive_window;
  emxArray_real_T *scores_negative_window;
  emxArray_real_T *scores_positive_window;
  double cont_pos;
  double d;
  double y;
  int scoreIn_size[2];
  int tmp_size[2];
  int labels_size[1];
  int i;
  int i1;
  int j;
  int k;
  int vlen;
  boolean_T bv[30];
  boolean_T exitg1;
  if (features_size[0] == 0) {
    scoreIn_size[0] = 0;
    labels_size[0] = 0;
  } else {
    scoreIn_size[0] = features_size[0];
    scoreIn_size[1] = 2;
    vlen = features_size[0] << 1;
    if (0 <= vlen - 1) {
      memset(&scoreIn_data[0], 0, vlen * sizeof(double));
    }

    for (i = 0; i < 30; i++) {
      bv[i] = true;
    }

    tmp_size[0] = features_size[0];
    tmp_size[1] = 30;
    vlen = features_size[0] * 30;
    for (i = 0; i < vlen; i++) {
      tmp_data[i] = true;
    }

    c_aggregatePredict(features_data, features_size, scoreIn_data, scoreIn_size,
                       model_IsCached, model_ClassNames, bv, tmp_data, tmp_size);
    c_CompactClassificationModel_ma(model_ClassNames, model_Prior, scoreIn_data,
      scoreIn_size, labels_data, labels_size);
  }

  cont_pos = 0.0;
  vlen = 0;
  exitg1 = false;
  while ((!exitg1) && (vlen <= labels_size[0] - 1)) {
    if (labels_data[vlen] == 1.0) {
      cont_pos++;
      if (cont_pos >= thrshd) {
        exitg1 = true;
      } else {
        vlen++;
      }
    } else {
      cont_pos = 0.0;
      vlen++;
    }
  }

  emxInit_real_T(&scores_positive_window, 2);
  emxInit_real_T(&scores_negative_window, 2);

  /*  ---- compute according to the thrshd  */
  scores_positive_window->size[0] = 0;
  scores_positive_window->size[1] = 1;
  scores_negative_window->size[0] = 0;
  scores_negative_window->size[1] = 1;
  i = (int)(((double)labels_size[0] - thrshd) + 1.0);
  emxInit_real_T(&b_scores_positive_window, 1);
  for (j = 0; j < i; j++) {
    /*  scores that it is a seizure */
    d = (((double)j + 1.0) + thrshd) - 1.0;
    if ((double)j + 1.0 > d) {
      i1 = -1;
      vlen = -1;
    } else {
      i1 = j - 1;
      vlen = (int)d - 1;
    }

    vlen -= i1;
    if (vlen == 0) {
      y = 0.0;
    } else {
      y = scoreIn_data[(i1 + scoreIn_size[0]) + 1];
      for (k = 2; k <= vlen; k++) {
        y += scoreIn_data[(i1 + k) + scoreIn_size[0]];
      }
    }

    vlen = scores_positive_window->size[0];
    i1 = b_scores_positive_window->size[0];
    b_scores_positive_window->size[0] = scores_positive_window->size[0] + 1;
    emxEnsureCapacity_real_T(b_scores_positive_window, i1);
    for (i1 = 0; i1 < vlen; i1++) {
      b_scores_positive_window->data[i1] = scores_positive_window->data[i1];
    }

    b_scores_positive_window->data[scores_positive_window->size[0]] = y / thrshd;
    i1 = scores_positive_window->size[0] * scores_positive_window->size[1];
    scores_positive_window->size[0] = b_scores_positive_window->size[0];
    scores_positive_window->size[1] = 1;
    emxEnsureCapacity_real_T(scores_positive_window, i1);
    vlen = b_scores_positive_window->size[0];
    for (i1 = 0; i1 < vlen; i1++) {
      scores_positive_window->data[i1] = b_scores_positive_window->data[i1];
    }

    /*  scores that it is not a seizure */
    if ((double)j + 1.0 > d) {
      i1 = -1;
      vlen = -1;
    } else {
      i1 = j - 1;
      vlen = (int)d - 1;
    }

    vlen -= i1;
    if (vlen == 0) {
      y = 0.0;
    } else {
      y = scoreIn_data[i1 + 1];
      for (k = 2; k <= vlen; k++) {
        y += scoreIn_data[i1 + k];
      }
    }

    vlen = scores_negative_window->size[0];
    i1 = b_scores_positive_window->size[0];
    b_scores_positive_window->size[0] = scores_negative_window->size[0] + 1;
    emxEnsureCapacity_real_T(b_scores_positive_window, i1);
    for (i1 = 0; i1 < vlen; i1++) {
      b_scores_positive_window->data[i1] = scores_negative_window->data[i1];
    }

    b_scores_positive_window->data[scores_negative_window->size[0]] = y / thrshd;
    i1 = scores_negative_window->size[0] * scores_negative_window->size[1];
    scores_negative_window->size[0] = b_scores_positive_window->size[0];
    scores_negative_window->size[1] = 1;
    emxEnsureCapacity_real_T(scores_negative_window, i1);
    vlen = b_scores_positive_window->size[0];
    for (i1 = 0; i1 < vlen; i1++) {
      scores_negative_window->data[i1] = b_scores_positive_window->data[i1];
    }
  }

  emxFree_real_T(&b_scores_positive_window);

  /*  True positive % Confidence that it is a seizure */
  vlen = scores_positive_window->size[0];
  if (scores_positive_window->size[0] == 0) {
    y = 0.0;
  } else {
    y = scores_positive_window->data[0];
    for (k = 2; k <= vlen; k++) {
      y += scores_positive_window->data[k - 1];
    }
  }

  emxFree_real_T(&scores_positive_window);
  vlen = scoreIn_size[0];
  if (vlen <= 2) {
    vlen = 2;
  }

  if (scoreIn_size[0] == 0) {
    vlen = 0;
  }

  *score_seizure = y / (((double)vlen - thrshd) + 1.0);

  /*  False negative % Confidence that it is not a seizure */
  vlen = scores_negative_window->size[0];
  if (scores_negative_window->size[0] == 0) {
    y = 0.0;
  } else {
    y = scores_negative_window->data[0];
    for (k = 2; k <= vlen; k++) {
      y += scores_negative_window->data[k - 1];
    }
  }

  emxFree_real_T(&scores_negative_window);
  vlen = scoreIn_size[0];
  if (vlen <= 2) {
    vlen = 2;
  }

  if (scoreIn_size[0] == 0) {
    vlen = 0;
  }

  *score_no_seizure = y / (((double)vlen - thrshd) + 1.0);

  /*  determine the result */
  /*  If there are no indexes of seizure in the segment then it is not a sizure, */
  /*  otherwise the predicted class for the segment is seizure */
  *output = 0.0;
  if (cont_pos == thrshd) {
    /* the predicted class for the segment is seizure */
    *output = 1.0;
  }
}

/* End of code generation (test_classifier.c) */
