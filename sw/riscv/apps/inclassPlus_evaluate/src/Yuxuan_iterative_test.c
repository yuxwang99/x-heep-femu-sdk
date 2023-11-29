/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Yuxuan_iterative_test.c
 *
 * Code generation for function 'Yuxuan_iterative_test'
 *
 */

/* Include files */
#include "Yuxuan_iterative_test.h"
#include "CompactClassificationEnsemble.h"
#include "CompactClassificationModel.h"
#include "aggregatePredict.h"
#include "find.h"
#include "minOrMax.h"
#include "my_Extract_features_Jep.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_internal_types.h"
#include "profile_Yuxuan_iteration_rtwutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "test_classifier.h"
#include <string.h>

/* Function Definitions */
void Yuxuan_iterative_test(const double ECG_sig[30720], const double Spo2_sig
  [30720], double Fs, double Nbr_RR, const boolean_T classifier1_IsCached[30],
  const double classifier1_ClassNames[2], const double classifier1_Prior[2],
  const boolean_T classifier2_IsCached[30], const double classifier2_ClassNames
  [2], const double classifier2_Prior[2], const c_classreg_learning_classif_Com *
  classifier3, const c_classreg_learning_classif_Com *classifier4, const
  c_classreg_learning_classif_Com *classifier5, const double norm_coef1[2],
  const double norm_coef2[3], const double norm_coef3[5], const double
  norm_coef4[13], const double norm_coef5[17], double thrshd, double conf_th,
  const double masks[85], double pred_mask[5], double pred_conf[5], double
  mask_apply_data[], int mask_apply_size[2])
{
  static double extract_feature_data[6800];
  static double tmp_data[6800];
  static double c_tmp_data[5200];
  static double d_extract_feature_data[5200];
  static double b_tmp_data[2000];
  static double c_extract_feature_data[2000];
  static double features_data[1200];
  static double b_extract_feature_data[800];
  static double scoreIn_data[800];
  static double predicted_cls_data[400];
  static boolean_T d_tmp_data[12000];
  emxArray_real_T *b_scores_positive_window;
  emxArray_real_T *extract_feature;
  emxArray_real_T *r;
  emxArray_real_T *scores_negative_window;
  emxArray_real_T *scores_positive_window;
  double conf_gray;
  double conf_seiz;
  double cont_pos;
  double predict_res;
  int b_masks[17];
  int e_tmp_data[5];
  int b_extract_feature_size[2];
  int b_tmp_size[2];
  int c_extract_feature_size[2];
  int d_extract_feature_size[2];
  int extract_feature_size[2];
  int scoreIn_size[2];
  int tmp_size[2];
  int predicted_cls_size[1];
  int i;
  int i1;
  int ind;
  int j;
  int k;
  int vlen;
  boolean_T bv[30];
  boolean_T b_pred_conf[5];
  boolean_T exitg1;
  boolean_T exitg2;
  mask_apply_size[0] = 1;
  mask_apply_size[1] = 1;
  mask_apply_data[0] = rtNaN;
  for (i = 0; i < 5; i++) {
    pred_mask[i] = rtNaN;
    pred_conf[i] = rtNaN;
  }

  ind = 0;
  emxInit_real_T(&extract_feature, 2);
  emxInit_real_T(&scores_positive_window, 2);
  emxInit_real_T(&scores_negative_window, 2);
  emxInit_real_T(&b_scores_positive_window, 1);
  emxInit_real_T(&r, 2);
  exitg1 = false;
  while ((!exitg1) && (ind < 5)) {
    /*  skip all zeros mask */
    conf_gray = masks[ind];
    for (k = 0; k < 16; k++) {
      conf_gray += masks[ind + 5 * (k + 1)];
    }

    if (conf_gray == 0.0) {
      ind++;
    } else {
      /*  ------------------ compute mask ------------------ */
      conf_gray = 0.0;

      /*  --------- extract features based on mask --------- */
      for (vlen = 0; vlen < 17; vlen++) {
        predict_res = masks[ind + 5 * vlen];
        if (predict_res == 1.0) {
          conf_gray++;
        }

        predict_res = rt_roundd_snf(predict_res);
        if (predict_res < 2.147483648E+9) {
          if (predict_res >= -2.147483648E+9) {
            i = (int)predict_res;
          } else {
            i = MIN_int32_T;
          }
        } else if (predict_res >= 2.147483648E+9) {
          i = MAX_int32_T;
        } else {
          i = 0;
        }

        b_masks[vlen] = i;
      }

      i = r->size[0] * r->size[1];
      r->size[0] = 400;
      r->size[1] = (int)conf_gray;
      emxEnsureCapacity_real_T(r, i);
      vlen = 400 * (int)conf_gray;
      for (i = 0; i < vlen; i++) {
        r->data[i] = rtNaN;
      }

      predict_res = rt_roundd_snf(Nbr_RR);
      if (predict_res < 2.147483648E+9) {
        if (predict_res >= -2.147483648E+9) {
          i = (int)predict_res;
        } else {
          i = MIN_int32_T;
        }
      } else if (predict_res >= 2.147483648E+9) {
        i = MAX_int32_T;
      } else {
        i = 0;
      }

      my_Extract_features_Jep(ECG_sig, Spo2_sig, Fs, i, b_masks, r, ind + 1 == 1,
        extract_feature);

      /*  ----------- test with training models ------------ */
      switch (ind + 1) {
       case 1:
        repmat(norm_coef1, extract_feature->size[0], scoreIn_data, scoreIn_size);
        b_extract_feature_size[0] = extract_feature->size[0];
        b_extract_feature_size[1] = extract_feature->size[1];
        vlen = extract_feature->size[0] * extract_feature->size[1];
        for (i = 0; i < vlen; i++) {
          b_extract_feature_data[i] = extract_feature->data[i] / scoreIn_data[i];
        }

        d_CompactClassificationEnsemble(classifier1_IsCached,
          classifier1_ClassNames, classifier1_Prior, b_extract_feature_data,
          b_extract_feature_size, predicted_cls_data, predicted_cls_size,
          scoreIn_data, scoreIn_size);
        cont_pos = 0.0;
        vlen = 0;
        exitg2 = false;
        while ((!exitg2) && (vlen <= predicted_cls_size[0] - 1)) {
          if (predicted_cls_data[vlen] == 1.0) {
            cont_pos++;
            if (cont_pos >= thrshd) {
              exitg2 = true;
            } else {
              vlen++;
            }
          } else {
            cont_pos = 0.0;
            vlen++;
          }
        }

        /*  ---- compute according to the thrshd  */
        scores_positive_window->size[0] = 0;
        scores_positive_window->size[1] = 1;
        scores_negative_window->size[0] = 0;
        scores_negative_window->size[1] = 1;
        i = (int)(((double)predicted_cls_size[0] - thrshd) + 1.0);
        for (j = 0; j < i; j++) {
          /*  scores that it is a seizure */
          predict_res = (((double)j + 1.0) + thrshd) - 1.0;
          if ((double)j + 1.0 > predict_res) {
            i1 = -1;
            vlen = -1;
          } else {
            i1 = j - 1;
            vlen = (int)predict_res - 1;
          }

          vlen -= i1;
          if (vlen == 0) {
            conf_gray = 0.0;
          } else {
            conf_gray = scoreIn_data[(i1 + scoreIn_size[0]) + 1];
            for (k = 2; k <= vlen; k++) {
              conf_gray += scoreIn_data[(i1 + k) + scoreIn_size[0]];
            }
          }

          vlen = scores_positive_window->size[0];
          i1 = b_scores_positive_window->size[0];
          b_scores_positive_window->size[0] = scores_positive_window->size[0] +
            1;
          emxEnsureCapacity_real_T(b_scores_positive_window, i1);
          for (i1 = 0; i1 < vlen; i1++) {
            b_scores_positive_window->data[i1] = scores_positive_window->data[i1];
          }

          b_scores_positive_window->data[scores_positive_window->size[0]] =
            conf_gray / thrshd;
          i1 = scores_positive_window->size[0] * scores_positive_window->size[1];
          scores_positive_window->size[0] = b_scores_positive_window->size[0];
          scores_positive_window->size[1] = 1;
          emxEnsureCapacity_real_T(scores_positive_window, i1);
          vlen = b_scores_positive_window->size[0];
          for (i1 = 0; i1 < vlen; i1++) {
            scores_positive_window->data[i1] = b_scores_positive_window->data[i1];
          }

          /*  scores that it is not a seizure */
          if ((double)j + 1.0 > predict_res) {
            i1 = -1;
            vlen = -1;
          } else {
            i1 = j - 1;
            vlen = (int)predict_res - 1;
          }

          vlen -= i1;
          if (vlen == 0) {
            conf_gray = 0.0;
          } else {
            conf_gray = scoreIn_data[i1 + 1];
            for (k = 2; k <= vlen; k++) {
              conf_gray += scoreIn_data[i1 + k];
            }
          }

          vlen = scores_negative_window->size[0];
          i1 = b_scores_positive_window->size[0];
          b_scores_positive_window->size[0] = scores_negative_window->size[0] +
            1;
          emxEnsureCapacity_real_T(b_scores_positive_window, i1);
          for (i1 = 0; i1 < vlen; i1++) {
            b_scores_positive_window->data[i1] = scores_negative_window->data[i1];
          }

          b_scores_positive_window->data[scores_negative_window->size[0]] =
            conf_gray / thrshd;
          i1 = scores_negative_window->size[0] * scores_negative_window->size[1];
          scores_negative_window->size[0] = b_scores_positive_window->size[0];
          scores_negative_window->size[1] = 1;
          emxEnsureCapacity_real_T(scores_negative_window, i1);
          vlen = b_scores_positive_window->size[0];
          for (i1 = 0; i1 < vlen; i1++) {
            scores_negative_window->data[i1] = b_scores_positive_window->data[i1];
          }
        }

        /*  True positive % Confidence that it is a seizure */
        vlen = scores_positive_window->size[0];
        if (scores_positive_window->size[0] == 0) {
          conf_gray = 0.0;
        } else {
          conf_gray = scores_positive_window->data[0];
          for (k = 2; k <= vlen; k++) {
            conf_gray += scores_positive_window->data[k - 1];
          }
        }

        vlen = scoreIn_size[0];
        if (vlen <= 2) {
          vlen = 2;
        }

        if (scoreIn_size[0] == 0) {
          vlen = 0;
        }

        conf_seiz = conf_gray / (((double)vlen - thrshd) + 1.0);

        /*  False negative % Confidence that it is not a seizure */
        vlen = scores_negative_window->size[0];
        if (scores_negative_window->size[0] == 0) {
          conf_gray = 0.0;
        } else {
          conf_gray = scores_negative_window->data[0];
          for (k = 2; k <= vlen; k++) {
            conf_gray += scores_negative_window->data[k - 1];
          }
        }

        vlen = scoreIn_size[0];
        if (vlen <= 2) {
          vlen = 2;
        }

        if (scoreIn_size[0] == 0) {
          vlen = 0;
        }

        conf_gray /= ((double)vlen - thrshd) + 1.0;

        /*  determine the result */
        /*  If there are no indexes of seizure in the segment then it is not a sizure, */
        /*  otherwise the predicted class for the segment is seizure */
        predict_res = 0.0;
        if (cont_pos == thrshd) {
          /* the predicted class for the segment is seizure */
          predict_res = 1.0;
        }
        break;

       case 2:
        b_repmat(norm_coef2, extract_feature->size[0], features_data, tmp_size);
        vlen = extract_feature->size[0] * extract_feature->size[1];
        tmp_size[0] = extract_feature->size[0];
        tmp_size[1] = extract_feature->size[1];
        for (i = 0; i < vlen; i++) {
          features_data[i] = extract_feature->data[i] / features_data[i];
        }

        if (tmp_size[0] == 0) {
          scoreIn_size[0] = 0;
          predicted_cls_size[0] = 0;
        } else {
          scoreIn_size[0] = tmp_size[0];
          scoreIn_size[1] = 2;
          vlen = tmp_size[0] << 1;
          if (0 <= vlen - 1) {
            memset(&scoreIn_data[0], 0, vlen * sizeof(double));
          }

          for (i = 0; i < 30; i++) {
            bv[i] = true;
          }

          b_tmp_size[0] = tmp_size[0];
          b_tmp_size[1] = 30;
          vlen = tmp_size[0] * 30;
          for (i = 0; i < vlen; i++) {
            d_tmp_data[i] = true;
          }

          b_aggregatePredict(features_data, tmp_size, scoreIn_data, scoreIn_size,
                             classifier2_IsCached, classifier2_ClassNames, bv,
                             d_tmp_data, b_tmp_size);
          c_CompactClassificationModel_ma(classifier2_ClassNames,
            classifier2_Prior, scoreIn_data, scoreIn_size, predicted_cls_data,
            predicted_cls_size);
        }

        cont_pos = 0.0;
        vlen = 0;
        exitg2 = false;
        while ((!exitg2) && (vlen <= predicted_cls_size[0] - 1)) {
          if (predicted_cls_data[vlen] == 1.0) {
            cont_pos++;
            if (cont_pos >= thrshd) {
              exitg2 = true;
            } else {
              vlen++;
            }
          } else {
            cont_pos = 0.0;
            vlen++;
          }
        }

        /*  ---- compute according to the thrshd  */
        scores_positive_window->size[0] = 0;
        scores_positive_window->size[1] = 1;
        scores_negative_window->size[0] = 0;
        scores_negative_window->size[1] = 1;
        i = (int)(((double)predicted_cls_size[0] - thrshd) + 1.0);
        for (j = 0; j < i; j++) {
          /*  scores that it is a seizure */
          predict_res = (((double)j + 1.0) + thrshd) - 1.0;
          if ((double)j + 1.0 > predict_res) {
            i1 = -1;
            vlen = -1;
          } else {
            i1 = j - 1;
            vlen = (int)predict_res - 1;
          }

          vlen -= i1;
          if (vlen == 0) {
            conf_gray = 0.0;
          } else {
            conf_gray = scoreIn_data[(i1 + scoreIn_size[0]) + 1];
            for (k = 2; k <= vlen; k++) {
              conf_gray += scoreIn_data[(i1 + k) + scoreIn_size[0]];
            }
          }

          vlen = scores_positive_window->size[0];
          i1 = b_scores_positive_window->size[0];
          b_scores_positive_window->size[0] = scores_positive_window->size[0] +
            1;
          emxEnsureCapacity_real_T(b_scores_positive_window, i1);
          for (i1 = 0; i1 < vlen; i1++) {
            b_scores_positive_window->data[i1] = scores_positive_window->data[i1];
          }

          b_scores_positive_window->data[scores_positive_window->size[0]] =
            conf_gray / thrshd;
          i1 = scores_positive_window->size[0] * scores_positive_window->size[1];
          scores_positive_window->size[0] = b_scores_positive_window->size[0];
          scores_positive_window->size[1] = 1;
          emxEnsureCapacity_real_T(scores_positive_window, i1);
          vlen = b_scores_positive_window->size[0];
          for (i1 = 0; i1 < vlen; i1++) {
            scores_positive_window->data[i1] = b_scores_positive_window->data[i1];
          }

          /*  scores that it is not a seizure */
          if ((double)j + 1.0 > predict_res) {
            i1 = -1;
            vlen = -1;
          } else {
            i1 = j - 1;
            vlen = (int)predict_res - 1;
          }

          vlen -= i1;
          if (vlen == 0) {
            conf_gray = 0.0;
          } else {
            conf_gray = scoreIn_data[i1 + 1];
            for (k = 2; k <= vlen; k++) {
              conf_gray += scoreIn_data[i1 + k];
            }
          }

          vlen = scores_negative_window->size[0];
          i1 = b_scores_positive_window->size[0];
          b_scores_positive_window->size[0] = scores_negative_window->size[0] +
            1;
          emxEnsureCapacity_real_T(b_scores_positive_window, i1);
          for (i1 = 0; i1 < vlen; i1++) {
            b_scores_positive_window->data[i1] = scores_negative_window->data[i1];
          }

          b_scores_positive_window->data[scores_negative_window->size[0]] =
            conf_gray / thrshd;
          i1 = scores_negative_window->size[0] * scores_negative_window->size[1];
          scores_negative_window->size[0] = b_scores_positive_window->size[0];
          scores_negative_window->size[1] = 1;
          emxEnsureCapacity_real_T(scores_negative_window, i1);
          vlen = b_scores_positive_window->size[0];
          for (i1 = 0; i1 < vlen; i1++) {
            scores_negative_window->data[i1] = b_scores_positive_window->data[i1];
          }
        }

        /*  True positive % Confidence that it is a seizure */
        vlen = scores_positive_window->size[0];
        if (scores_positive_window->size[0] == 0) {
          conf_gray = 0.0;
        } else {
          conf_gray = scores_positive_window->data[0];
          for (k = 2; k <= vlen; k++) {
            conf_gray += scores_positive_window->data[k - 1];
          }
        }

        vlen = scoreIn_size[0];
        if (vlen <= 2) {
          vlen = 2;
        }

        if (scoreIn_size[0] == 0) {
          vlen = 0;
        }

        conf_seiz = conf_gray / (((double)vlen - thrshd) + 1.0);

        /*  False negative % Confidence that it is not a seizure */
        vlen = scores_negative_window->size[0];
        if (scores_negative_window->size[0] == 0) {
          conf_gray = 0.0;
        } else {
          conf_gray = scores_negative_window->data[0];
          for (k = 2; k <= vlen; k++) {
            conf_gray += scores_negative_window->data[k - 1];
          }
        }

        vlen = scoreIn_size[0];
        if (vlen <= 2) {
          vlen = 2;
        }

        if (scoreIn_size[0] == 0) {
          vlen = 0;
        }

        conf_gray /= ((double)vlen - thrshd) + 1.0;

        /*  determine the result */
        /*  If there are no indexes of seizure in the segment then it is not a sizure, */
        /*  otherwise the predicted class for the segment is seizure */
        predict_res = 0.0;
        if (cont_pos == thrshd) {
          /* the predicted class for the segment is seizure */
          predict_res = 1.0;
        }
        break;

       case 3:
        c_repmat(norm_coef3, extract_feature->size[0], b_tmp_data, tmp_size);
        c_extract_feature_size[0] = extract_feature->size[0];
        c_extract_feature_size[1] = extract_feature->size[1];
        vlen = extract_feature->size[0] * extract_feature->size[1];
        for (i = 0; i < vlen; i++) {
          c_extract_feature_data[i] = extract_feature->data[i] / b_tmp_data[i];
        }

        test_classifier(c_extract_feature_data, c_extract_feature_size,
                        classifier3->IsCached, classifier3->ClassNames,
                        classifier3->Prior, thrshd, &predict_res, &conf_seiz,
                        &conf_gray);
        break;

       case 4:
        d_repmat(norm_coef4, extract_feature->size[0], c_tmp_data, tmp_size);
        d_extract_feature_size[0] = extract_feature->size[0];
        d_extract_feature_size[1] = extract_feature->size[1];
        vlen = extract_feature->size[0] * extract_feature->size[1];
        for (i = 0; i < vlen; i++) {
          d_extract_feature_data[i] = extract_feature->data[i] / c_tmp_data[i];
        }

        b_test_classifier(d_extract_feature_data, d_extract_feature_size,
                          classifier4->IsCached, classifier4->ClassNames,
                          classifier4->Prior, thrshd, &predict_res, &conf_seiz,
                          &conf_gray);
        break;

       default:
        e_repmat(norm_coef5, extract_feature->size[0], tmp_data, tmp_size);
        extract_feature_size[0] = extract_feature->size[0];
        extract_feature_size[1] = extract_feature->size[1];
        vlen = extract_feature->size[0] * extract_feature->size[1];
        for (i = 0; i < vlen; i++) {
          extract_feature_data[i] = extract_feature->data[i] / tmp_data[i];
        }

        e_CompactClassificationEnsemble(classifier5->IsCached,
          classifier5->ClassNames, classifier5->Prior, extract_feature_data,
          extract_feature_size, predicted_cls_data, predicted_cls_size,
          scoreIn_data, scoreIn_size);
        cont_pos = 0.0;
        vlen = 0;
        exitg2 = false;
        while ((!exitg2) && (vlen <= predicted_cls_size[0] - 1)) {
          if (predicted_cls_data[vlen] == 1.0) {
            cont_pos++;
            if (cont_pos >= thrshd) {
              exitg2 = true;
            } else {
              vlen++;
            }
          } else {
            cont_pos = 0.0;
            vlen++;
          }
        }

        /*  ---- compute according to the thrshd  */
        scores_positive_window->size[0] = 0;
        scores_positive_window->size[1] = 1;
        scores_negative_window->size[0] = 0;
        scores_negative_window->size[1] = 1;
        i = (int)(((double)predicted_cls_size[0] - thrshd) + 1.0);
        for (j = 0; j < i; j++) {
          /*  scores that it is a seizure */
          predict_res = (((double)j + 1.0) + thrshd) - 1.0;
          if ((double)j + 1.0 > predict_res) {
            i1 = -1;
            vlen = -1;
          } else {
            i1 = j - 1;
            vlen = (int)predict_res - 1;
          }

          vlen -= i1;
          if (vlen == 0) {
            conf_gray = 0.0;
          } else {
            conf_gray = scoreIn_data[(i1 + scoreIn_size[0]) + 1];
            for (k = 2; k <= vlen; k++) {
              conf_gray += scoreIn_data[(i1 + k) + scoreIn_size[0]];
            }
          }

          vlen = scores_positive_window->size[0];
          i1 = b_scores_positive_window->size[0];
          b_scores_positive_window->size[0] = scores_positive_window->size[0] +
            1;
          emxEnsureCapacity_real_T(b_scores_positive_window, i1);
          for (i1 = 0; i1 < vlen; i1++) {
            b_scores_positive_window->data[i1] = scores_positive_window->data[i1];
          }

          b_scores_positive_window->data[scores_positive_window->size[0]] =
            conf_gray / thrshd;
          i1 = scores_positive_window->size[0] * scores_positive_window->size[1];
          scores_positive_window->size[0] = b_scores_positive_window->size[0];
          scores_positive_window->size[1] = 1;
          emxEnsureCapacity_real_T(scores_positive_window, i1);
          vlen = b_scores_positive_window->size[0];
          for (i1 = 0; i1 < vlen; i1++) {
            scores_positive_window->data[i1] = b_scores_positive_window->data[i1];
          }

          /*  scores that it is not a seizure */
          if ((double)j + 1.0 > predict_res) {
            i1 = -1;
            vlen = -1;
          } else {
            i1 = j - 1;
            vlen = (int)predict_res - 1;
          }

          vlen -= i1;
          if (vlen == 0) {
            conf_gray = 0.0;
          } else {
            conf_gray = scoreIn_data[i1 + 1];
            for (k = 2; k <= vlen; k++) {
              conf_gray += scoreIn_data[i1 + k];
            }
          }

          vlen = scores_negative_window->size[0];
          i1 = b_scores_positive_window->size[0];
          b_scores_positive_window->size[0] = scores_negative_window->size[0] +
            1;
          emxEnsureCapacity_real_T(b_scores_positive_window, i1);
          for (i1 = 0; i1 < vlen; i1++) {
            b_scores_positive_window->data[i1] = scores_negative_window->data[i1];
          }

          b_scores_positive_window->data[scores_negative_window->size[0]] =
            conf_gray / thrshd;
          i1 = scores_negative_window->size[0] * scores_negative_window->size[1];
          scores_negative_window->size[0] = b_scores_positive_window->size[0];
          scores_negative_window->size[1] = 1;
          emxEnsureCapacity_real_T(scores_negative_window, i1);
          vlen = b_scores_positive_window->size[0];
          for (i1 = 0; i1 < vlen; i1++) {
            scores_negative_window->data[i1] = b_scores_positive_window->data[i1];
          }
        }

        /*  True positive % Confidence that it is a seizure */
        vlen = scores_positive_window->size[0];
        if (scores_positive_window->size[0] == 0) {
          conf_gray = 0.0;
        } else {
          conf_gray = scores_positive_window->data[0];
          for (k = 2; k <= vlen; k++) {
            conf_gray += scores_positive_window->data[k - 1];
          }
        }

        vlen = scoreIn_size[0];
        if (vlen <= 2) {
          vlen = 2;
        }

        if (scoreIn_size[0] == 0) {
          vlen = 0;
        }

        conf_seiz = conf_gray / (((double)vlen - thrshd) + 1.0);

        /*  False negative % Confidence that it is not a seizure */
        vlen = scores_negative_window->size[0];
        if (scores_negative_window->size[0] == 0) {
          conf_gray = 0.0;
        } else {
          conf_gray = scores_negative_window->data[0];
          for (k = 2; k <= vlen; k++) {
            conf_gray += scores_negative_window->data[k - 1];
          }
        }

        vlen = scoreIn_size[0];
        if (vlen <= 2) {
          vlen = 2;
        }

        if (scoreIn_size[0] == 0) {
          vlen = 0;
        }

        conf_gray /= ((double)vlen - thrshd) + 1.0;

        /*  determine the result */
        /*  If there are no indexes of seizure in the segment then it is not a sizure, */
        /*  otherwise the predicted class for the segment is seizure */
        predict_res = 0.0;
        if (cont_pos == thrshd) {
          /* the predicted class for the segment is seizure */
          predict_res = 1.0;
        }
        break;
      }

      if (predict_res == 1.0) {
        pred_conf[ind] = conf_seiz;
      } else {
        pred_conf[ind] = conf_gray;
      }

      pred_mask[ind] = predict_res;

      /*  if the test result matches the threshold, clear cache and break */
      if (((predict_res == 1.0) && (conf_seiz >= conf_th)) || ((predict_res ==
            0.0) && (conf_gray >= conf_th))) {
        mask_apply_size[0] = 1;
        mask_apply_size[1] = 1;
        mask_apply_data[0] = (double)ind + 1.0;
        exitg1 = true;
      } else {
        if (ind + 1 == 5) {
          /*  save the most confidence result */
          /*  final_res = pred_mask(pred_conf == max(pred_conf)); */
          /*  mask_apply = ind; */
          conf_gray = e_maximum(pred_conf);
          for (i = 0; i < 5; i++) {
            b_pred_conf[i] = (pred_conf[i] == conf_gray);
          }

          e_eml_find(b_pred_conf, e_tmp_data, tmp_size);
          mask_apply_size[0] = 1;
          mask_apply_size[1] = tmp_size[1];
          vlen = tmp_size[0] * tmp_size[1];
          for (i = 0; i < vlen; i++) {
            mask_apply_data[i] = e_tmp_data[i];
          }
        }

        ind++;
      }
    }
  }

  emxFree_real_T(&r);
  emxFree_real_T(&b_scores_positive_window);
  emxFree_real_T(&scores_negative_window);
  emxFree_real_T(&scores_positive_window);
  emxFree_real_T(&extract_feature);
}

/* End of code generation (Yuxuan_iterative_test.c) */
