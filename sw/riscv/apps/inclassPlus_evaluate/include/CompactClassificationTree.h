/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationTree.h
 *
 * Code generation for function 'CompactClassificationTree'
 *
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include files */
#include "profile_Yuxuan_iteration_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void ab_CompactClassificationTree_Co(double obj_CutPredictorIndex[5595],
    double obj_Children[11190], double obj_CutPoint[5595], boolean_T
    obj_NanCutPoints[5595], boolean_T obj_InfCutPoints[5595], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11190]);
  void ab_CompactClassificationTree_pr(const double obj_CutPredictorIndex[5653],
    const double obj_Children[11306], const double obj_CutPoint[5653], const
    boolean_T obj_NanCutPoints[5653], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11306], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ac_CompactClassificationTree_Co(double obj_CutPredictorIndex[2737],
    double obj_Children[5474], double obj_CutPoint[2737], boolean_T
    obj_NanCutPoints[2737], boolean_T obj_InfCutPoints[2737], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5474]);
  void ac_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2761],
    const double obj_Children[5522], const double obj_CutPoint[2761], const
    boolean_T obj_NanCutPoints[2761], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5522], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ad_CompactClassificationTree_Co(double obj_CutPredictorIndex[693], double
    obj_Children[1386], double obj_CutPoint[693], boolean_T obj_NanCutPoints[693],
    boolean_T obj_InfCutPoints[693], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1386]);
  void ad_CompactClassificationTree_pr(const double obj_CutPredictorIndex[747],
    const double obj_Children[1494], const double obj_CutPoint[747], const
    boolean_T obj_NanCutPoints[747], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1494], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ae_CompactClassificationTree_Co(double obj_CutPredictorIndex[733], double
    obj_Children[1466], double obj_CutPoint[733], boolean_T obj_NanCutPoints[733],
    boolean_T obj_InfCutPoints[733], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1466]);
  void ae_CompactClassificationTree_pr(const double obj_CutPredictorIndex[587],
    const double obj_Children[1174], const double obj_CutPoint[587], const
    boolean_T obj_NanCutPoints[587], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1174], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void af_CompactClassificationTree_Co(double obj_CutPredictorIndex[729], double
    obj_Children[1458], double obj_CutPoint[729], boolean_T obj_NanCutPoints[729],
    boolean_T obj_InfCutPoints[729], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1458]);
  void ag_CompactClassificationTree_Co(double obj_CutPredictorIndex[707], double
    obj_Children[1414], double obj_CutPoint[707], boolean_T obj_NanCutPoints[707],
    boolean_T obj_InfCutPoints[707], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1414]);
  void bb_CompactClassificationTree_Co(double obj_CutPredictorIndex[5875],
    double obj_Children[11750], double obj_CutPoint[5875], boolean_T
    obj_NanCutPoints[5875], boolean_T obj_InfCutPoints[5875], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11750]);
  void bb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[5745],
    const double obj_Children[11490], const double obj_CutPoint[5745], const
    boolean_T obj_NanCutPoints[5745], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11490], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void bc_CompactClassificationTree_Co(double obj_CutPredictorIndex[2851],
    double obj_Children[5702], double obj_CutPoint[2851], boolean_T
    obj_NanCutPoints[2851], boolean_T obj_InfCutPoints[2851], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5702]);
  void bc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2905],
    const double obj_Children[5810], const double obj_CutPoint[2905], const
    boolean_T obj_NanCutPoints[2905], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5810], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void bd_CompactClassificationTree_Co(double obj_CutPredictorIndex[797], double
    obj_Children[1594], double obj_CutPoint[797], boolean_T obj_NanCutPoints[797],
    boolean_T obj_InfCutPoints[797], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1594]);
  void bd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[727],
    const double obj_Children[1454], const double obj_CutPoint[727], const
    boolean_T obj_NanCutPoints[727], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1454], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void be_CompactClassificationTree_Co(double obj_CutPredictorIndex[803], double
    obj_Children[1606], double obj_CutPoint[803], boolean_T obj_NanCutPoints[803],
    boolean_T obj_InfCutPoints[803], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1606]);
  void be_CompactClassificationTree_pr(const double obj_CutPredictorIndex[729],
    const double obj_Children[1458], const double obj_CutPoint[729], const
    boolean_T obj_NanCutPoints[729], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1458], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void bf_CompactClassificationTree_Co(double obj_CutPredictorIndex[757], double
    obj_Children[1514], double obj_CutPoint[757], boolean_T obj_NanCutPoints[757],
    boolean_T obj_InfCutPoints[757], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1514]);
  void bg_CompactClassificationTree_Co(double obj_CutPredictorIndex[769], double
    obj_Children[1538], double obj_CutPoint[769], boolean_T obj_NanCutPoints[769],
    boolean_T obj_InfCutPoints[769], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1538]);
  void c_CompactClassificationTree_Com(double obj_CutPredictorIndex[5731],
    double obj_Children[11462], double obj_CutPoint[5731], boolean_T
    obj_NanCutPoints[5731], boolean_T obj_InfCutPoints[5731], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11462]);
  void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5731],
    const double obj_Children[11462], const double obj_CutPoint[5731], const
    boolean_T obj_NanCutPoints[5731], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11462], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void cb_CompactClassificationTree_Co(double obj_CutPredictorIndex[5653],
    double obj_Children[11306], double obj_CutPoint[5653], boolean_T
    obj_NanCutPoints[5653], boolean_T obj_InfCutPoints[5653], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11306]);
  void cb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[5715],
    const double obj_Children[11430], const double obj_CutPoint[5715], const
    boolean_T obj_NanCutPoints[5715], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11430], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void cc_CompactClassificationTree_Co(double obj_CutPredictorIndex[2825],
    double obj_Children[5650], double obj_CutPoint[2825], boolean_T
    obj_NanCutPoints[2825], boolean_T obj_InfCutPoints[2825], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5650]);
  void cc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2743],
    const double obj_Children[5486], const double obj_CutPoint[2743], const
    boolean_T obj_NanCutPoints[2743], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5486], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void cd_CompactClassificationTree_Co(double obj_CutPredictorIndex[813], double
    obj_Children[1626], double obj_CutPoint[813], boolean_T obj_NanCutPoints[813],
    boolean_T obj_InfCutPoints[813], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1626]);
  void cd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[745],
    const double obj_Children[1490], const double obj_CutPoint[745], const
    boolean_T obj_NanCutPoints[745], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1490], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ce_CompactClassificationTree_Co(double obj_CutPredictorIndex[847], double
    obj_Children[1694], double obj_CutPoint[847], boolean_T obj_NanCutPoints[847],
    boolean_T obj_InfCutPoints[847], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1694]);
  void ce_CompactClassificationTree_pr(const double obj_CutPredictorIndex[603],
    const double obj_Children[1206], const double obj_CutPoint[603], const
    boolean_T obj_NanCutPoints[603], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1206], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void cf_CompactClassificationTree_Co(double obj_CutPredictorIndex[603], double
    obj_Children[1206], double obj_CutPoint[603], boolean_T obj_NanCutPoints[603],
    boolean_T obj_InfCutPoints[603], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1206]);
  void d_CompactClassificationTree_Com(double obj_CutPredictorIndex[5731],
    double obj_Children[11462], double obj_CutPoint[5731], boolean_T
    obj_NanCutPoints[5731], boolean_T obj_InfCutPoints[5731], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11462]);
  void d_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5693],
    const double obj_Children[11386], const double obj_CutPoint[5693], const
    boolean_T obj_NanCutPoints[5693], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11386], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void db_CompactClassificationTree_Co(double obj_CutPredictorIndex[5745],
    double obj_Children[11490], double obj_CutPoint[5745], boolean_T
    obj_NanCutPoints[5745], boolean_T obj_InfCutPoints[5745], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11490]);
  void db_CompactClassificationTree_pr(const double obj_CutPredictorIndex[5709],
    const double obj_Children[11418], const double obj_CutPoint[5709], const
    boolean_T obj_NanCutPoints[5709], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11418], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void dc_CompactClassificationTree_Co(double obj_CutPredictorIndex[2821],
    double obj_Children[5642], double obj_CutPoint[2821], boolean_T
    obj_NanCutPoints[2821], boolean_T obj_InfCutPoints[2821], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5642]);
  void dc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[861],
    const double obj_Children[1722], const double obj_CutPoint[861], const
    boolean_T obj_NanCutPoints[861], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1722], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void dd_CompactClassificationTree_Co(double obj_CutPredictorIndex[667], double
    obj_Children[1334], double obj_CutPoint[667], boolean_T obj_NanCutPoints[667],
    boolean_T obj_InfCutPoints[667], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1334]);
  void dd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[683],
    const double obj_Children[1366], const double obj_CutPoint[683], const
    boolean_T obj_NanCutPoints[683], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1366], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void de_CompactClassificationTree_Co(double obj_CutPredictorIndex[757], double
    obj_Children[1514], double obj_CutPoint[757], boolean_T obj_NanCutPoints[757],
    boolean_T obj_InfCutPoints[757], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1514]);
  void de_CompactClassificationTree_pr(const double obj_CutPredictorIndex[609],
    const double obj_Children[1218], const double obj_CutPoint[609], const
    boolean_T obj_NanCutPoints[609], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1218], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void df_CompactClassificationTree_Co(double obj_CutPredictorIndex[609], double
    obj_Children[1218], double obj_CutPoint[609], boolean_T obj_NanCutPoints[609],
    boolean_T obj_InfCutPoints[609], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1218]);
  void e_CompactClassificationTree_Com(double obj_CutPredictorIndex[5693],
    double obj_Children[11386], double obj_CutPoint[5693], boolean_T
    obj_NanCutPoints[5693], boolean_T obj_InfCutPoints[5693], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11386]);
  void e_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5663],
    const double obj_Children[11326], const double obj_CutPoint[5663], const
    boolean_T obj_NanCutPoints[5663], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11326], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void eb_CompactClassificationTree_Co(double obj_CutPredictorIndex[5715],
    double obj_Children[11430], double obj_CutPoint[5715], boolean_T
    obj_NanCutPoints[5715], boolean_T obj_InfCutPoints[5715], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11430]);
  void eb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2801],
    const double obj_Children[5602], const double obj_CutPoint[2801], const
    boolean_T obj_NanCutPoints[2801], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5602], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ec_CompactClassificationTree_Co(double obj_CutPredictorIndex[2811],
    double obj_Children[5622], double obj_CutPoint[2811], boolean_T
    obj_NanCutPoints[2811], boolean_T obj_InfCutPoints[2811], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5622]);
  void ec_CompactClassificationTree_pr(const double obj_CutPredictorIndex[659],
    const double obj_Children[1318], const double obj_CutPoint[659], const
    boolean_T obj_NanCutPoints[659], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1318], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ed_CompactClassificationTree_Co(double obj_CutPredictorIndex[775], double
    obj_Children[1550], double obj_CutPoint[775], boolean_T obj_NanCutPoints[775],
    boolean_T obj_InfCutPoints[775], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1550]);
  void ed_CompactClassificationTree_pr(const double obj_CutPredictorIndex[803],
    const double obj_Children[1606], const double obj_CutPoint[803], const
    boolean_T obj_NanCutPoints[803], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1606], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ee_CompactClassificationTree_Co(double obj_CutPredictorIndex[801], double
    obj_Children[1602], double obj_CutPoint[801], boolean_T obj_NanCutPoints[801],
    boolean_T obj_InfCutPoints[801], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1602]);
  void ee_CompactClassificationTree_pr(const double obj_CutPredictorIndex[621],
    const double obj_Children[1242], const double obj_CutPoint[621], const
    boolean_T obj_NanCutPoints[621], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1242], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ef_CompactClassificationTree_Co(double obj_CutPredictorIndex[621], double
    obj_Children[1242], double obj_CutPoint[621], boolean_T obj_NanCutPoints[621],
    boolean_T obj_InfCutPoints[621], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1242]);
  void f_CompactClassificationTree_Com(double obj_CutPredictorIndex[5663],
    double obj_Children[11326], double obj_CutPoint[5663], boolean_T
    obj_NanCutPoints[5663], boolean_T obj_InfCutPoints[5663], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11326]);
  void f_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5645],
    const double obj_Children[11290], const double obj_CutPoint[5645], const
    boolean_T obj_NanCutPoints[5645], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11290], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void fb_CompactClassificationTree_Co(double obj_CutPredictorIndex[5689],
    double obj_Children[11378], double obj_CutPoint[5689], boolean_T
    obj_NanCutPoints[5689], boolean_T obj_InfCutPoints[5689], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11378]);
  void fb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2783],
    const double obj_Children[5566], const double obj_CutPoint[2783], const
    boolean_T obj_NanCutPoints[2783], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5566], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void fc_CompactClassificationTree_Co(double obj_CutPredictorIndex[2885],
    double obj_Children[5770], double obj_CutPoint[2885], boolean_T
    obj_NanCutPoints[2885], boolean_T obj_InfCutPoints[2885], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5770]);
  void fc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[807],
    const double obj_Children[1614], const double obj_CutPoint[807], const
    boolean_T obj_NanCutPoints[807], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1614], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void fd_CompactClassificationTree_Co(double obj_CutPredictorIndex[707], double
    obj_Children[1414], double obj_CutPoint[707], boolean_T obj_NanCutPoints[707],
    boolean_T obj_InfCutPoints[707], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1414]);
  void fd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[881],
    const double obj_Children[1762], const double obj_CutPoint[881], const
    boolean_T obj_NanCutPoints[881], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1762], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void fe_CompactClassificationTree_Co(double obj_CutPredictorIndex[763], double
    obj_Children[1526], double obj_CutPoint[763], boolean_T obj_NanCutPoints[763],
    boolean_T obj_InfCutPoints[763], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1526]);
  void fe_CompactClassificationTree_pr(const double obj_CutPredictorIndex[653],
    const double obj_Children[1306], const double obj_CutPoint[653], const
    boolean_T obj_NanCutPoints[653], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1306], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ff_CompactClassificationTree_Co(double obj_CutPredictorIndex[653], double
    obj_Children[1306], double obj_CutPoint[653], boolean_T obj_NanCutPoints[653],
    boolean_T obj_InfCutPoints[653], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1306]);
  void g_CompactClassificationTree_Com(double obj_CutPredictorIndex[5645],
    double obj_Children[11290], double obj_CutPoint[5645], boolean_T
    obj_NanCutPoints[5645], boolean_T obj_InfCutPoints[5645], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11290]);
  void g_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5755],
    const double obj_Children[11510], const double obj_CutPoint[5755], const
    boolean_T obj_NanCutPoints[5755], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11510], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void gb_CompactClassificationTree_Co(double obj_CutPredictorIndex[5709],
    double obj_Children[11418], double obj_CutPoint[5709], boolean_T
    obj_NanCutPoints[5709], boolean_T obj_InfCutPoints[5709], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11418]);
  void gb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2715],
    const double obj_Children[5430], const double obj_CutPoint[2715], const
    boolean_T obj_NanCutPoints[2715], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5430], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void gc_CompactClassificationTree_Co(double obj_CutPredictorIndex[2857],
    double obj_Children[5714], double obj_CutPoint[2857], boolean_T
    obj_NanCutPoints[2857], boolean_T obj_InfCutPoints[2857], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5714]);
  void gc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[765],
    const double obj_Children[1530], const double obj_CutPoint[765], const
    boolean_T obj_NanCutPoints[765], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1530], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void gd_CompactClassificationTree_Co(double obj_CutPredictorIndex[753], double
    obj_Children[1506], double obj_CutPoint[753], boolean_T obj_NanCutPoints[753],
    boolean_T obj_InfCutPoints[753], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1506]);
  void gd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[1005],
    const double obj_Children[2010], const double obj_CutPoint[1005], const
    boolean_T obj_NanCutPoints[1005], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[2010], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ge_CompactClassificationTree_Co(double obj_CutPredictorIndex[787], double
    obj_Children[1574], double obj_CutPoint[787], boolean_T obj_NanCutPoints[787],
    boolean_T obj_InfCutPoints[787], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1574]);
  void ge_CompactClassificationTree_pr(const double obj_CutPredictorIndex[521],
    const double obj_Children[1042], const double obj_CutPoint[521], const
    boolean_T obj_NanCutPoints[521], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1042], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void gf_CompactClassificationTree_Co(double obj_CutPredictorIndex[609], double
    obj_Children[1218], double obj_CutPoint[609], boolean_T obj_NanCutPoints[609],
    boolean_T obj_InfCutPoints[609], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1218]);
  void h_CompactClassificationTree_Com(double obj_CutPredictorIndex[5755],
    double obj_Children[11510], double obj_CutPoint[5755], boolean_T
    obj_NanCutPoints[5755], boolean_T obj_InfCutPoints[5755], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11510]);
  void h_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5667],
    const double obj_Children[11334], const double obj_CutPoint[5667], const
    boolean_T obj_NanCutPoints[5667], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11334], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void hb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2801],
    double obj_Children[5602], double obj_CutPoint[2801], boolean_T
    obj_NanCutPoints[2801], boolean_T obj_InfCutPoints[2801], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5602]);
  void hb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2709],
    const double obj_Children[5418], const double obj_CutPoint[2709], const
    boolean_T obj_NanCutPoints[2709], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5418], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void hc_CompactClassificationTree_Co(double obj_CutPredictorIndex[2821],
    double obj_Children[5642], double obj_CutPoint[2821], boolean_T
    obj_NanCutPoints[2821], boolean_T obj_InfCutPoints[2821], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5642]);
  void hc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[781],
    const double obj_Children[1562], const double obj_CutPoint[781], const
    boolean_T obj_NanCutPoints[781], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1562], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void hd_CompactClassificationTree_Co(double obj_CutPredictorIndex[667], double
    obj_Children[1334], double obj_CutPoint[667], boolean_T obj_NanCutPoints[667],
    boolean_T obj_InfCutPoints[667], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1334]);
  void hd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[713],
    const double obj_Children[1426], const double obj_CutPoint[713], const
    boolean_T obj_NanCutPoints[713], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1426], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void he_CompactClassificationTree_Co(double obj_CutPredictorIndex[897], double
    obj_Children[1794], double obj_CutPoint[897], boolean_T obj_NanCutPoints[897],
    boolean_T obj_InfCutPoints[897], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1794]);
  void he_CompactClassificationTree_pr(const double obj_CutPredictorIndex[619],
    const double obj_Children[1238], const double obj_CutPoint[619], const
    boolean_T obj_NanCutPoints[619], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1238], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void hf_CompactClassificationTree_Co(double obj_CutPredictorIndex[521], double
    obj_Children[1042], double obj_CutPoint[521], boolean_T obj_NanCutPoints[521],
    boolean_T obj_InfCutPoints[521], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1042]);
  void i_CompactClassificationTree_Com(double obj_CutPredictorIndex[5667],
    double obj_Children[11334], double obj_CutPoint[5667], boolean_T
    obj_NanCutPoints[5667], boolean_T obj_InfCutPoints[5667], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11334]);
  void i_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5779],
    const double obj_Children[11558], const double obj_CutPoint[5779], const
    boolean_T obj_NanCutPoints[5779], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11558], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ib_CompactClassificationTree_Co(double obj_CutPredictorIndex[2783],
    double obj_Children[5566], double obj_CutPoint[2783], boolean_T
    obj_NanCutPoints[2783], boolean_T obj_InfCutPoints[2783], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5566]);
  void ib_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2775],
    const double obj_Children[5550], const double obj_CutPoint[2775], const
    boolean_T obj_NanCutPoints[2775], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5550], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ic_CompactClassificationTree_Co(double obj_CutPredictorIndex[2761],
    double obj_Children[5522], double obj_CutPoint[2761], boolean_T
    obj_NanCutPoints[2761], boolean_T obj_InfCutPoints[2761], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5522]);
  void ic_CompactClassificationTree_pr(const double obj_CutPredictorIndex[681],
    const double obj_Children[1362], const double obj_CutPoint[681], const
    boolean_T obj_NanCutPoints[681], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1362], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void id_CompactClassificationTree_Co(double obj_CutPredictorIndex[791], double
    obj_Children[1582], double obj_CutPoint[791], boolean_T obj_NanCutPoints[791],
    boolean_T obj_InfCutPoints[791], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1582]);
  void id_CompactClassificationTree_pr(const double obj_CutPredictorIndex[845],
    const double obj_Children[1690], const double obj_CutPoint[845], const
    boolean_T obj_NanCutPoints[845], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1690], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ie_CompactClassificationTree_Co(double obj_CutPredictorIndex[727], double
    obj_Children[1454], double obj_CutPoint[727], boolean_T obj_NanCutPoints[727],
    boolean_T obj_InfCutPoints[727], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1454]);
  void ie_CompactClassificationTree_pr(const double obj_CutPredictorIndex[541],
    const double obj_Children[1082], const double obj_CutPoint[541], const
    boolean_T obj_NanCutPoints[541], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1082], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void if_CompactClassificationTree_Co(double obj_CutPredictorIndex[619], double
    obj_Children[1238], double obj_CutPoint[619], boolean_T obj_NanCutPoints[619],
    boolean_T obj_InfCutPoints[619], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1238]);
  void j_CompactClassificationTree_Com(double obj_CutPredictorIndex[5779],
    double obj_Children[11558], double obj_CutPoint[5779], boolean_T
    obj_NanCutPoints[5779], boolean_T obj_InfCutPoints[5779], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11558]);
  void j_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5823],
    const double obj_Children[11646], const double obj_CutPoint[5823], const
    boolean_T obj_NanCutPoints[5823], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11646], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void jb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2715],
    double obj_Children[5430], double obj_CutPoint[2715], boolean_T
    obj_NanCutPoints[2715], boolean_T obj_InfCutPoints[2715], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5430]);
  void jb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2695],
    const double obj_Children[5390], const double obj_CutPoint[2695], const
    boolean_T obj_NanCutPoints[2695], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5390], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void jc_CompactClassificationTree_Co(double obj_CutPredictorIndex[2905],
    double obj_Children[5810], double obj_CutPoint[2905], boolean_T
    obj_NanCutPoints[2905], boolean_T obj_InfCutPoints[2905], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5810]);
  void jc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[751],
    const double obj_Children[1502], const double obj_CutPoint[751], const
    boolean_T obj_NanCutPoints[751], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1502], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void jd_CompactClassificationTree_Co(double obj_CutPredictorIndex[725], double
    obj_Children[1450], double obj_CutPoint[725], boolean_T obj_NanCutPoints[725],
    boolean_T obj_InfCutPoints[725], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1450]);
  void jd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[723],
    const double obj_Children[1446], const double obj_CutPoint[723], const
    boolean_T obj_NanCutPoints[723], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1446], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void je_CompactClassificationTree_Co(double obj_CutPredictorIndex[737], double
    obj_Children[1474], double obj_CutPoint[737], boolean_T obj_NanCutPoints[737],
    boolean_T obj_InfCutPoints[737], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1474]);
  void je_CompactClassificationTree_pr(const double obj_CutPredictorIndex[641],
    const double obj_Children[1282], const double obj_CutPoint[641], const
    boolean_T obj_NanCutPoints[641], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1282], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void jf_CompactClassificationTree_Co(double obj_CutPredictorIndex[541], double
    obj_Children[1082], double obj_CutPoint[541], boolean_T obj_NanCutPoints[541],
    boolean_T obj_InfCutPoints[541], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1082]);
  void k_CompactClassificationTree_Com(double obj_CutPredictorIndex[5823],
    double obj_Children[11646], double obj_CutPoint[5823], boolean_T
    obj_NanCutPoints[5823], boolean_T obj_InfCutPoints[5823], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11646]);
  void k_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5747],
    const double obj_Children[11494], const double obj_CutPoint[5747], const
    boolean_T obj_NanCutPoints[5747], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11494], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void kb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2709],
    double obj_Children[5418], double obj_CutPoint[2709], boolean_T
    obj_NanCutPoints[2709], boolean_T obj_InfCutPoints[2709], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5418]);
  void kb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2857],
    const double obj_Children[5714], const double obj_CutPoint[2857], const
    boolean_T obj_NanCutPoints[2857], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5714], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void kc_CompactClassificationTree_Co(double obj_CutPredictorIndex[2743],
    double obj_Children[5486], double obj_CutPoint[2743], boolean_T
    obj_NanCutPoints[2743], boolean_T obj_InfCutPoints[2743], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5486]);
  void kc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[779],
    const double obj_Children[1558], const double obj_CutPoint[779], const
    boolean_T obj_NanCutPoints[779], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1558], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void kd_CompactClassificationTree_Co(double obj_CutPredictorIndex[695], double
    obj_Children[1390], double obj_CutPoint[695], boolean_T obj_NanCutPoints[695],
    boolean_T obj_InfCutPoints[695], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1390]);
  void kd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[733],
    const double obj_Children[1466], const double obj_CutPoint[733], const
    boolean_T obj_NanCutPoints[733], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1466], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ke_CompactClassificationTree_Co(double obj_CutPredictorIndex[803], double
    obj_Children[1606], double obj_CutPoint[803], boolean_T obj_NanCutPoints[803],
    boolean_T obj_InfCutPoints[803], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1606]);
  void ke_CompactClassificationTree_pr(const double obj_CutPredictorIndex[709],
    const double obj_Children[1418], const double obj_CutPoint[709], const
    boolean_T obj_NanCutPoints[709], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1418], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void kf_CompactClassificationTree_Co(double obj_CutPredictorIndex[619], double
    obj_Children[1238], double obj_CutPoint[619], boolean_T obj_NanCutPoints[619],
    boolean_T obj_InfCutPoints[619], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1238]);
  void l_CompactClassificationTree_Com(double obj_CutPredictorIndex[5747],
    double obj_Children[11494], double obj_CutPoint[5747], boolean_T
    obj_NanCutPoints[5747], boolean_T obj_InfCutPoints[5747], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11494]);
  void l_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5615],
    const double obj_Children[11230], const double obj_CutPoint[5615], const
    boolean_T obj_NanCutPoints[5615], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11230], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void lb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2775],
    double obj_Children[5550], double obj_CutPoint[2775], boolean_T
    obj_NanCutPoints[2775], boolean_T obj_InfCutPoints[2775], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5550]);
  void lb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2805],
    const double obj_Children[5610], const double obj_CutPoint[2805], const
    boolean_T obj_NanCutPoints[2805], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5610], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void lc_CompactClassificationTree_Co(double obj_CutPredictorIndex[2811],
    double obj_Children[5622], double obj_CutPoint[2811], boolean_T
    obj_NanCutPoints[2811], boolean_T obj_InfCutPoints[2811], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5622]);
  void lc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[813],
    const double obj_Children[1626], const double obj_CutPoint[813], const
    boolean_T obj_NanCutPoints[813], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1626], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ld_CompactClassificationTree_Co(double obj_CutPredictorIndex[747], double
    obj_Children[1494], double obj_CutPoint[747], boolean_T obj_NanCutPoints[747],
    boolean_T obj_InfCutPoints[747], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1494]);
  void ld_CompactClassificationTree_pr(const double obj_CutPredictorIndex[847],
    const double obj_Children[1694], const double obj_CutPoint[847], const
    boolean_T obj_NanCutPoints[847], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1694], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void le_CompactClassificationTree_Co(double obj_CutPredictorIndex[763], double
    obj_Children[1526], double obj_CutPoint[763], boolean_T obj_NanCutPoints[763],
    boolean_T obj_InfCutPoints[763], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1526]);
  void le_CompactClassificationTree_pr(const double obj_CutPredictorIndex[795],
    const double obj_Children[1590], const double obj_CutPoint[795], const
    boolean_T obj_NanCutPoints[795], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1590], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void lf_CompactClassificationTree_Co(double obj_CutPredictorIndex[641], double
    obj_Children[1282], double obj_CutPoint[641], boolean_T obj_NanCutPoints[641],
    boolean_T obj_InfCutPoints[641], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1282]);
  void m_CompactClassificationTree_Com(double obj_CutPredictorIndex[5615],
    double obj_Children[11230], double obj_CutPoint[5615], boolean_T
    obj_NanCutPoints[5615], boolean_T obj_InfCutPoints[5615], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11230]);
  void m_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5807],
    const double obj_Children[11614], const double obj_CutPoint[5807], const
    boolean_T obj_NanCutPoints[5807], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11614], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void mb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2695],
    double obj_Children[5390], double obj_CutPoint[2695], boolean_T
    obj_NanCutPoints[2695], boolean_T obj_InfCutPoints[2695], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5390]);
  void mb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2961],
    const double obj_Children[5922], const double obj_CutPoint[2961], const
    boolean_T obj_NanCutPoints[2961], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5922], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void mc_CompactClassificationTree_Co(double obj_CutPredictorIndex[861], double
    obj_Children[1722], double obj_CutPoint[861], boolean_T obj_NanCutPoints[861],
    boolean_T obj_InfCutPoints[861], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1722]);
  void mc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[769],
    const double obj_Children[1538], const double obj_CutPoint[769], const
    boolean_T obj_NanCutPoints[769], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1538], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void md_CompactClassificationTree_Co(double obj_CutPredictorIndex[727], double
    obj_Children[1454], double obj_CutPoint[727], boolean_T obj_NanCutPoints[727],
    boolean_T obj_InfCutPoints[727], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1454]);
  void md_CompactClassificationTree_pr(const double obj_CutPredictorIndex[757],
    const double obj_Children[1514], const double obj_CutPoint[757], const
    boolean_T obj_NanCutPoints[757], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1514], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void me_CompactClassificationTree_Co(double obj_CutPredictorIndex[637], double
    obj_Children[1274], double obj_CutPoint[637], boolean_T obj_NanCutPoints[637],
    boolean_T obj_InfCutPoints[637], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1274]);
  void me_CompactClassificationTree_pr(const double obj_CutPredictorIndex[615],
    const double obj_Children[1230], const double obj_CutPoint[615], const
    boolean_T obj_NanCutPoints[615], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1230], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void mf_CompactClassificationTree_Co(double obj_CutPredictorIndex[753], double
    obj_Children[1506], double obj_CutPoint[753], boolean_T obj_NanCutPoints[753],
    boolean_T obj_InfCutPoints[753], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1506]);
  void n_CompactClassificationTree_Com(double obj_CutPredictorIndex[5807],
    double obj_Children[11614], double obj_CutPoint[5807], boolean_T
    obj_NanCutPoints[5807], boolean_T obj_InfCutPoints[5807], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11614]);
  void n_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5659],
    const double obj_Children[11318], const double obj_CutPoint[5659], const
    boolean_T obj_NanCutPoints[5659], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11318], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void nb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2857],
    double obj_Children[5714], double obj_CutPoint[2857], boolean_T
    obj_NanCutPoints[2857], boolean_T obj_InfCutPoints[2857], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5714]);
  void nb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2871],
    const double obj_Children[5742], const double obj_CutPoint[2871], const
    boolean_T obj_NanCutPoints[2871], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5742], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void nc_CompactClassificationTree_Co(double obj_CutPredictorIndex[659], double
    obj_Children[1318], double obj_CutPoint[659], boolean_T obj_NanCutPoints[659],
    boolean_T obj_InfCutPoints[659], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1318]);
  void nc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[691],
    const double obj_Children[1382], const double obj_CutPoint[691], const
    boolean_T obj_NanCutPoints[691], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1382], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void nd_CompactClassificationTree_Co(double obj_CutPredictorIndex[745], double
    obj_Children[1490], double obj_CutPoint[745], boolean_T obj_NanCutPoints[745],
    boolean_T obj_InfCutPoints[745], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1490]);
  void nd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[801],
    const double obj_Children[1602], const double obj_CutPoint[801], const
    boolean_T obj_NanCutPoints[801], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1602], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ne_CompactClassificationTree_Co(double obj_CutPredictorIndex[731], double
    obj_Children[1462], double obj_CutPoint[731], boolean_T obj_NanCutPoints[731],
    boolean_T obj_InfCutPoints[731], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1462]);
  void ne_CompactClassificationTree_pr(const double obj_CutPredictorIndex[689],
    const double obj_Children[1378], const double obj_CutPoint[689], const
    boolean_T obj_NanCutPoints[689], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1378], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void nf_CompactClassificationTree_Co(double obj_CutPredictorIndex[709], double
    obj_Children[1418], double obj_CutPoint[709], boolean_T obj_NanCutPoints[709],
    boolean_T obj_InfCutPoints[709], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1418]);
  void o_CompactClassificationTree_Com(double obj_CutPredictorIndex[5659],
    double obj_Children[11318], double obj_CutPoint[5659], boolean_T
    obj_NanCutPoints[5659], boolean_T obj_InfCutPoints[5659], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11318]);
  void o_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5761],
    const double obj_Children[11522], const double obj_CutPoint[5761], const
    boolean_T obj_NanCutPoints[5761], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11522], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ob_CompactClassificationTree_Co(double obj_CutPredictorIndex[2805],
    double obj_Children[5610], double obj_CutPoint[2805], boolean_T
    obj_NanCutPoints[2805], boolean_T obj_InfCutPoints[2805], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5610]);
  void ob_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2827],
    const double obj_Children[5654], const double obj_CutPoint[2827], const
    boolean_T obj_NanCutPoints[2827], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5654], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void oc_CompactClassificationTree_Co(double obj_CutPredictorIndex[807], double
    obj_Children[1614], double obj_CutPoint[807], boolean_T obj_NanCutPoints[807],
    boolean_T obj_InfCutPoints[807], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1614]);
  void oc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[821],
    const double obj_Children[1642], const double obj_CutPoint[821], const
    boolean_T obj_NanCutPoints[821], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1642], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void od_CompactClassificationTree_Co(double obj_CutPredictorIndex[747], double
    obj_Children[1494], double obj_CutPoint[747], boolean_T obj_NanCutPoints[747],
    boolean_T obj_InfCutPoints[747], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1494]);
  void od_CompactClassificationTree_pr(const double obj_CutPredictorIndex[763],
    const double obj_Children[1526], const double obj_CutPoint[763], const
    boolean_T obj_NanCutPoints[763], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1526], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void oe_CompactClassificationTree_Co(double obj_CutPredictorIndex[903], double
    obj_Children[1806], double obj_CutPoint[903], boolean_T obj_NanCutPoints[903],
    boolean_T obj_InfCutPoints[903], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1806]);
  void oe_CompactClassificationTree_pr(const double obj_CutPredictorIndex[585],
    const double obj_Children[1170], const double obj_CutPoint[585], const
    boolean_T obj_NanCutPoints[585], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1170], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void of_CompactClassificationTree_Co(double obj_CutPredictorIndex[795], double
    obj_Children[1590], double obj_CutPoint[795], boolean_T obj_NanCutPoints[795],
    boolean_T obj_InfCutPoints[795], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1590]);
  void p_CompactClassificationTree_Com(double obj_CutPredictorIndex[5761],
    double obj_Children[11522], double obj_CutPoint[5761], boolean_T
    obj_NanCutPoints[5761], boolean_T obj_InfCutPoints[5761], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11522]);
  void p_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5785],
    const double obj_Children[11570], const double obj_CutPoint[5785], const
    boolean_T obj_NanCutPoints[5785], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11570], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void pb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2961],
    double obj_Children[5922], double obj_CutPoint[2961], boolean_T
    obj_NanCutPoints[2961], boolean_T obj_InfCutPoints[2961], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5922]);
  void pb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2811],
    const double obj_Children[5622], const double obj_CutPoint[2811], const
    boolean_T obj_NanCutPoints[2811], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5622], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void pc_CompactClassificationTree_Co(double obj_CutPredictorIndex[765], double
    obj_Children[1530], double obj_CutPoint[765], boolean_T obj_NanCutPoints[765],
    boolean_T obj_InfCutPoints[765], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1530]);
  void pc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[739],
    const double obj_Children[1478], const double obj_CutPoint[739], const
    boolean_T obj_NanCutPoints[739], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1478], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void pd_CompactClassificationTree_Co(double obj_CutPredictorIndex[861], double
    obj_Children[1722], double obj_CutPoint[861], boolean_T obj_NanCutPoints[861],
    boolean_T obj_InfCutPoints[861], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1722]);
  void pd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[787],
    const double obj_Children[1574], const double obj_CutPoint[787], const
    boolean_T obj_NanCutPoints[787], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1574], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void pe_CompactClassificationTree_Co(double obj_CutPredictorIndex[781], double
    obj_Children[1562], double obj_CutPoint[781], boolean_T obj_NanCutPoints[781],
    boolean_T obj_InfCutPoints[781], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1562]);
  void pe_CompactClassificationTree_pr(const double obj_CutPredictorIndex[805],
    const double obj_Children[1610], const double obj_CutPoint[805], const
    boolean_T obj_NanCutPoints[805], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1610], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void pf_CompactClassificationTree_Co(double obj_CutPredictorIndex[823], double
    obj_Children[1646], double obj_CutPoint[823], boolean_T obj_NanCutPoints[823],
    boolean_T obj_InfCutPoints[823], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1646]);
  void q_CompactClassificationTree_Com(double obj_CutPredictorIndex[5785],
    double obj_Children[11570], double obj_CutPoint[5785], boolean_T
    obj_NanCutPoints[5785], boolean_T obj_InfCutPoints[5785], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11570]);
  void q_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5825],
    const double obj_Children[11650], const double obj_CutPoint[5825], const
    boolean_T obj_NanCutPoints[5825], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11650], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void qb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2871],
    double obj_Children[5742], double obj_CutPoint[2871], boolean_T
    obj_NanCutPoints[2871], boolean_T obj_InfCutPoints[2871], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5742]);
  void qb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2753],
    const double obj_Children[5506], const double obj_CutPoint[2753], const
    boolean_T obj_NanCutPoints[2753], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5506], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void qc_CompactClassificationTree_Co(double obj_CutPredictorIndex[781], double
    obj_Children[1562], double obj_CutPoint[781], boolean_T obj_NanCutPoints[781],
    boolean_T obj_InfCutPoints[781], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1562]);
  void qc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[693],
    const double obj_Children[1386], const double obj_CutPoint[693], const
    boolean_T obj_NanCutPoints[693], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1386], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void qd_CompactClassificationTree_Co(double obj_CutPredictorIndex[683], double
    obj_Children[1366], double obj_CutPoint[683], boolean_T obj_NanCutPoints[683],
    boolean_T obj_InfCutPoints[683], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1366]);
  void qd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[897],
    const double obj_Children[1794], const double obj_CutPoint[897], const
    boolean_T obj_NanCutPoints[897], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1794], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void qe_CompactClassificationTree_Co(double obj_CutPredictorIndex[937], double
    obj_Children[1874], double obj_CutPoint[937], boolean_T obj_NanCutPoints[937],
    boolean_T obj_InfCutPoints[937], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1874]);
  void qe_CompactClassificationTree_pr(const double obj_CutPredictorIndex[519],
    const double obj_Children[1038], const double obj_CutPoint[519], const
    boolean_T obj_NanCutPoints[519], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1038], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void qf_CompactClassificationTree_Co(double obj_CutPredictorIndex[615], double
    obj_Children[1230], double obj_CutPoint[615], boolean_T obj_NanCutPoints[615],
    boolean_T obj_InfCutPoints[615], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1230]);
  void r_CompactClassificationTree_Com(double obj_CutPredictorIndex[5825],
    double obj_Children[11650], double obj_CutPoint[5825], boolean_T
    obj_NanCutPoints[5825], boolean_T obj_InfCutPoints[5825], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11650]);
  void r_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5701],
    const double obj_Children[11402], const double obj_CutPoint[5701], const
    boolean_T obj_NanCutPoints[5701], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11402], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void rb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2827],
    double obj_Children[5654], double obj_CutPoint[2827], boolean_T
    obj_NanCutPoints[2827], boolean_T obj_InfCutPoints[2827], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5654]);
  void rb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2755],
    const double obj_Children[5510], const double obj_CutPoint[2755], const
    boolean_T obj_NanCutPoints[2755], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5510], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void rc_CompactClassificationTree_Co(double obj_CutPredictorIndex[681], double
    obj_Children[1362], double obj_CutPoint[681], boolean_T obj_NanCutPoints[681],
    boolean_T obj_InfCutPoints[681], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1362]);
  void rc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[797],
    const double obj_Children[1594], const double obj_CutPoint[797], const
    boolean_T obj_NanCutPoints[797], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1594], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void rd_CompactClassificationTree_Co(double obj_CutPredictorIndex[803], double
    obj_Children[1606], double obj_CutPoint[803], boolean_T obj_NanCutPoints[803],
    boolean_T obj_InfCutPoints[803], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1606]);
  void rd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[737],
    const double obj_Children[1474], const double obj_CutPoint[737], const
    boolean_T obj_NanCutPoints[737], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1474], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void re_CompactClassificationTree_Co(double obj_CutPredictorIndex[775], double
    obj_Children[1550], double obj_CutPoint[775], boolean_T obj_NanCutPoints[775],
    boolean_T obj_InfCutPoints[775], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1550]);
  void re_CompactClassificationTree_pr(const double obj_CutPredictorIndex[607],
    const double obj_Children[1214], const double obj_CutPoint[607], const
    boolean_T obj_NanCutPoints[607], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1214], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void rf_CompactClassificationTree_Co(double obj_CutPredictorIndex[689], double
    obj_Children[1378], double obj_CutPoint[689], boolean_T obj_NanCutPoints[689],
    boolean_T obj_InfCutPoints[689], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1378]);
  void s_CompactClassificationTree_Com(double obj_CutPredictorIndex[5701],
    double obj_Children[11402], double obj_CutPoint[5701], boolean_T
    obj_NanCutPoints[5701], boolean_T obj_InfCutPoints[5701], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11402]);
  void s_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5727],
    const double obj_Children[11454], const double obj_CutPoint[5727], const
    boolean_T obj_NanCutPoints[5727], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11454], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void sb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2695],
    double obj_Children[5390], double obj_CutPoint[2695], boolean_T
    obj_NanCutPoints[2695], boolean_T obj_InfCutPoints[2695], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5390]);
  void sb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2843],
    const double obj_Children[5686], const double obj_CutPoint[2843], const
    boolean_T obj_NanCutPoints[2843], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5686], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void sc_CompactClassificationTree_Co(double obj_CutPredictorIndex[751], double
    obj_Children[1502], double obj_CutPoint[751], boolean_T obj_NanCutPoints[751],
    boolean_T obj_InfCutPoints[751], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1502]);
  void sc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[667],
    const double obj_Children[1334], const double obj_CutPoint[667], const
    boolean_T obj_NanCutPoints[667], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1334], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void sd_CompactClassificationTree_Co(double obj_CutPredictorIndex[881], double
    obj_Children[1762], double obj_CutPoint[881], boolean_T obj_NanCutPoints[881],
    boolean_T obj_InfCutPoints[881], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1762]);
  void sd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[637],
    const double obj_Children[1274], const double obj_CutPoint[637], const
    boolean_T obj_NanCutPoints[637], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1274], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void se_CompactClassificationTree_Co(double obj_CutPredictorIndex[741], double
    obj_Children[1482], double obj_CutPoint[741], boolean_T obj_NanCutPoints[741],
    boolean_T obj_InfCutPoints[741], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1482]);
  void sf_CompactClassificationTree_Co(double obj_CutPredictorIndex[697], double
    obj_Children[1394], double obj_CutPoint[697], boolean_T obj_NanCutPoints[697],
    boolean_T obj_InfCutPoints[697], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1394]);
  void t_CompactClassificationTree_Com(double obj_CutPredictorIndex[5727],
    double obj_Children[11454], double obj_CutPoint[5727], boolean_T
    obj_NanCutPoints[5727], boolean_T obj_InfCutPoints[5727], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11454]);
  void t_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5689],
    const double obj_Children[11378], const double obj_CutPoint[5689], const
    boolean_T obj_NanCutPoints[5689], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11378], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void tb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2857],
    double obj_Children[5714], double obj_CutPoint[2857], boolean_T
    obj_NanCutPoints[2857], boolean_T obj_InfCutPoints[2857], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5714]);
  void tb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2687],
    const double obj_Children[5374], const double obj_CutPoint[2687], const
    boolean_T obj_NanCutPoints[2687], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5374], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void tc_CompactClassificationTree_Co(double obj_CutPredictorIndex[779], double
    obj_Children[1558], double obj_CutPoint[779], boolean_T obj_NanCutPoints[779],
    boolean_T obj_InfCutPoints[779], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1558]);
  void tc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[775],
    const double obj_Children[1550], const double obj_CutPoint[775], const
    boolean_T obj_NanCutPoints[775], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1550], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void td_CompactClassificationTree_Co(double obj_CutPredictorIndex[1005],
    double obj_Children[2010], double obj_CutPoint[1005], boolean_T
    obj_NanCutPoints[1005], boolean_T obj_InfCutPoints[1005], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[2010]);
  void td_CompactClassificationTree_pr(const double obj_CutPredictorIndex[731],
    const double obj_Children[1462], const double obj_CutPoint[731], const
    boolean_T obj_NanCutPoints[731], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1462], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void te_CompactClassificationTree_Co(double obj_CutPredictorIndex[801], double
    obj_Children[1602], double obj_CutPoint[801], boolean_T obj_NanCutPoints[801],
    boolean_T obj_InfCutPoints[801], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1602]);
  void tf_CompactClassificationTree_Co(double obj_CutPredictorIndex[637], double
    obj_Children[1274], double obj_CutPoint[637], boolean_T obj_NanCutPoints[637],
    boolean_T obj_InfCutPoints[637], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1274]);
  void u_CompactClassificationTree_Com(double obj_CutPredictorIndex[5689],
    double obj_Children[11378], double obj_CutPoint[5689], boolean_T
    obj_NanCutPoints[5689], boolean_T obj_InfCutPoints[5689], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11378]);
  void u_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5691],
    const double obj_Children[11382], const double obj_CutPoint[5691], const
    boolean_T obj_NanCutPoints[5691], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11382], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ub_CompactClassificationTree_Co(double obj_CutPredictorIndex[2811],
    double obj_Children[5622], double obj_CutPoint[2811], boolean_T
    obj_NanCutPoints[2811], boolean_T obj_InfCutPoints[2811], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5622]);
  void ub_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2737],
    const double obj_Children[5474], const double obj_CutPoint[2737], const
    boolean_T obj_NanCutPoints[2737], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5474], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void uc_CompactClassificationTree_Co(double obj_CutPredictorIndex[813], double
    obj_Children[1626], double obj_CutPoint[813], boolean_T obj_NanCutPoints[813],
    boolean_T obj_InfCutPoints[813], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1626]);
  void uc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[707],
    const double obj_Children[1414], const double obj_CutPoint[707], const
    boolean_T obj_NanCutPoints[707], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1414], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ud_CompactClassificationTree_Co(double obj_CutPredictorIndex[713], double
    obj_Children[1426], double obj_CutPoint[713], boolean_T obj_NanCutPoints[713],
    boolean_T obj_InfCutPoints[713], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1426]);
  void ud_CompactClassificationTree_pr(const double obj_CutPredictorIndex[903],
    const double obj_Children[1806], const double obj_CutPoint[903], const
    boolean_T obj_NanCutPoints[903], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1806], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ue_CompactClassificationTree_Co(double obj_CutPredictorIndex[697], double
    obj_Children[1394], double obj_CutPoint[697], boolean_T obj_NanCutPoints[697],
    boolean_T obj_InfCutPoints[697], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1394]);
  void uf_CompactClassificationTree_Co(double obj_CutPredictorIndex[585], double
    obj_Children[1170], double obj_CutPoint[585], boolean_T obj_NanCutPoints[585],
    boolean_T obj_InfCutPoints[585], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1170]);
  void v_CompactClassificationTree_Com(double obj_CutPredictorIndex[5691],
    double obj_Children[11382], double obj_CutPoint[5691], boolean_T
    obj_NanCutPoints[5691], boolean_T obj_InfCutPoints[5691], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11382]);
  void v_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5623],
    const double obj_Children[11246], const double obj_CutPoint[5623], const
    boolean_T obj_NanCutPoints[5623], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11246], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void vb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2753],
    double obj_Children[5506], double obj_CutPoint[2753], boolean_T
    obj_NanCutPoints[2753], boolean_T obj_InfCutPoints[2753], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5506]);
  void vb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2851],
    const double obj_Children[5702], const double obj_CutPoint[2851], const
    boolean_T obj_NanCutPoints[2851], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5702], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void vc_CompactClassificationTree_Co(double obj_CutPredictorIndex[769], double
    obj_Children[1538], double obj_CutPoint[769], boolean_T obj_NanCutPoints[769],
    boolean_T obj_InfCutPoints[769], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1538]);
  void vc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[753],
    const double obj_Children[1506], const double obj_CutPoint[753], const
    boolean_T obj_NanCutPoints[753], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1506], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void vd_CompactClassificationTree_Co(double obj_CutPredictorIndex[845], double
    obj_Children[1690], double obj_CutPoint[845], boolean_T obj_NanCutPoints[845],
    boolean_T obj_InfCutPoints[845], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1690]);
  void vd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[937],
    const double obj_Children[1874], const double obj_CutPoint[937], const
    boolean_T obj_NanCutPoints[937], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1874], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ve_CompactClassificationTree_Co(double obj_CutPredictorIndex[823], double
    obj_Children[1646], double obj_CutPoint[823], boolean_T obj_NanCutPoints[823],
    boolean_T obj_InfCutPoints[823], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1646]);
  void vf_CompactClassificationTree_Co(double obj_CutPredictorIndex[805], double
    obj_Children[1610], double obj_CutPoint[805], boolean_T obj_NanCutPoints[805],
    boolean_T obj_InfCutPoints[805], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1610]);
  void w_CompactClassificationTree_Com(double obj_CutPredictorIndex[5785],
    double obj_Children[11570], double obj_CutPoint[5785], boolean_T
    obj_NanCutPoints[5785], boolean_T obj_InfCutPoints[5785], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11570]);
  void w_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5713],
    const double obj_Children[11426], const double obj_CutPoint[5713], const
    boolean_T obj_NanCutPoints[5713], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11426], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void wb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2755],
    double obj_Children[5510], double obj_CutPoint[2755], boolean_T
    obj_NanCutPoints[2755], boolean_T obj_InfCutPoints[2755], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5510]);
  void wb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2825],
    const double obj_Children[5650], const double obj_CutPoint[2825], const
    boolean_T obj_NanCutPoints[2825], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5650], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void wc_CompactClassificationTree_Co(double obj_CutPredictorIndex[691], double
    obj_Children[1382], double obj_CutPoint[691], boolean_T obj_NanCutPoints[691],
    boolean_T obj_InfCutPoints[691], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1382]);
  void wc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[791],
    const double obj_Children[1582], const double obj_CutPoint[791], const
    boolean_T obj_NanCutPoints[791], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1582], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void wd_CompactClassificationTree_Co(double obj_CutPredictorIndex[723], double
    obj_Children[1446], double obj_CutPoint[723], boolean_T obj_NanCutPoints[723],
    boolean_T obj_InfCutPoints[723], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1446]);
  void wd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[741],
    const double obj_Children[1482], const double obj_CutPoint[741], const
    boolean_T obj_NanCutPoints[741], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1482], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void we_CompactClassificationTree_Co(double obj_CutPredictorIndex[739], double
    obj_Children[1478], double obj_CutPoint[739], boolean_T obj_NanCutPoints[739],
    boolean_T obj_InfCutPoints[739], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1478]);
  void wf_CompactClassificationTree_Co(double obj_CutPredictorIndex[519], double
    obj_Children[1038], double obj_CutPoint[519], boolean_T obj_NanCutPoints[519],
    boolean_T obj_InfCutPoints[519], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1038]);
  void x_CompactClassificationTree_Com(double obj_CutPredictorIndex[5623],
    double obj_Children[11246], double obj_CutPoint[5623], boolean_T
    obj_NanCutPoints[5623], boolean_T obj_InfCutPoints[5623], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11246]);
  void x_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5595],
    const double obj_Children[11190], const double obj_CutPoint[5595], const
    boolean_T obj_NanCutPoints[5595], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11190], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void xb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2843],
    double obj_Children[5686], double obj_CutPoint[2843], boolean_T
    obj_NanCutPoints[2843], boolean_T obj_InfCutPoints[2843], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5686]);
  void xb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2821],
    const double obj_Children[5642], const double obj_CutPoint[2821], const
    boolean_T obj_NanCutPoints[2821], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5642], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void xc_CompactClassificationTree_Co(double obj_CutPredictorIndex[821], double
    obj_Children[1642], double obj_CutPoint[821], boolean_T obj_NanCutPoints[821],
    boolean_T obj_InfCutPoints[821], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1642]);
  void xc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[725],
    const double obj_Children[1450], const double obj_CutPoint[725], const
    boolean_T obj_NanCutPoints[725], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1450], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void xd_CompactClassificationTree_Co(double obj_CutPredictorIndex[751], double
    obj_Children[1502], double obj_CutPoint[751], boolean_T obj_NanCutPoints[751],
    boolean_T obj_InfCutPoints[751], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1502]);
  void xd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[697],
    const double obj_Children[1394], const double obj_CutPoint[697], const
    boolean_T obj_NanCutPoints[697], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1394], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void xe_CompactClassificationTree_Co(double obj_CutPredictorIndex[587], double
    obj_Children[1174], double obj_CutPoint[587], boolean_T obj_NanCutPoints[587],
    boolean_T obj_InfCutPoints[587], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1174]);
  void xf_CompactClassificationTree_Co(double obj_CutPredictorIndex[607], double
    obj_Children[1214], double obj_CutPoint[607], boolean_T obj_NanCutPoints[607],
    boolean_T obj_InfCutPoints[607], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1214]);
  void y_CompactClassificationTree_Com(double obj_CutPredictorIndex[5713],
    double obj_Children[11426], double obj_CutPoint[5713], boolean_T
    obj_NanCutPoints[5713], boolean_T obj_InfCutPoints[5713], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[11426]);
  void y_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5875],
    const double obj_Children[11750], const double obj_CutPoint[5875], const
    boolean_T obj_NanCutPoints[5875], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[11750], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void yb_CompactClassificationTree_Co(double obj_CutPredictorIndex[2687],
    double obj_Children[5374], double obj_CutPoint[2687], boolean_T
    obj_NanCutPoints[2687], boolean_T obj_InfCutPoints[2687], double
    obj_ClassNames[2], int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4], double
    obj_ClassProbability[5374]);
  void yb_CompactClassificationTree_pr(const double obj_CutPredictorIndex[2885],
    const double obj_Children[5770], const double obj_CutPoint[2885], const
    boolean_T obj_NanCutPoints[2885], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[5770], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void yc_CompactClassificationTree_Co(double obj_CutPredictorIndex[739], double
    obj_Children[1478], double obj_CutPoint[739], boolean_T obj_NanCutPoints[739],
    boolean_T obj_InfCutPoints[739], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1478]);
  void yc_CompactClassificationTree_pr(const double obj_CutPredictorIndex[695],
    const double obj_Children[1390], const double obj_CutPoint[695], const
    boolean_T obj_NanCutPoints[695], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1390], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void yd_CompactClassificationTree_Co(double obj_CutPredictorIndex[813], double
    obj_Children[1626], double obj_CutPoint[813], boolean_T obj_NanCutPoints[813],
    boolean_T obj_InfCutPoints[813], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1626]);
  void yd_CompactClassificationTree_pr(const double obj_CutPredictorIndex[823],
    const double obj_Children[1646], const double obj_CutPoint[823], const
    boolean_T obj_NanCutPoints[823], const double obj_ClassNames[2], const
    double obj_Prior[2], const double obj_Cost[4], const double
    obj_ClassProbability[1646], const double Xin_data[], const int Xin_size[2],
    double labels_data[], int labels_size[1], double scores_data[], int
    scores_size[2]);
  void ye_CompactClassificationTree_Co(double obj_CutPredictorIndex[667], double
    obj_Children[1334], double obj_CutPoint[667], boolean_T obj_NanCutPoints[667],
    boolean_T obj_InfCutPoints[667], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1334]);
  void yf_CompactClassificationTree_Co(double obj_CutPredictorIndex[621], double
    obj_Children[1242], double obj_CutPoint[621], boolean_T obj_NanCutPoints[621],
    boolean_T obj_InfCutPoints[621], double obj_ClassNames[2], int
    obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
    double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[1242]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (CompactClassificationTree.h) */
