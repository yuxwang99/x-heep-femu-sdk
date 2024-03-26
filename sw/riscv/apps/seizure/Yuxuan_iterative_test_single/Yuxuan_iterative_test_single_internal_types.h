/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Yuxuan_iterative_test_single_internal_types.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef YUXUAN_ITERATIVE_TEST_SINGLE_INTERNAL_TYPES_H
#define YUXUAN_ITERATIVE_TEST_SINGLE_INTERNAL_TYPES_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef enum_c_classreg_learning_coderutils_
#define enum_c_classreg_learning_coderutils_
enum c_classreg_learning_coderutils_
{
  Logit = 0, /* Default value */
  Doublelogit,
  Invlogit,
  Ismax,
  Sign,
  Symmetric,
  Symmetricismax,
  Symmetriclogit,
  Identity
};
#endif /* enum_c_classreg_learning_coderutils_ */
#ifndef typedef_c_classreg_learning_coderutils_
#define typedef_c_classreg_learning_coderutils_
typedef enum c_classreg_learning_coderutils_ c_classreg_learning_coderutils_;
#endif /* typedef_c_classreg_learning_coderutils_ */

#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  int xstart;
  int xend;
  int depth;
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_coder_internal_SortedBuffer
#define typedef_coder_internal_SortedBuffer
typedef struct {
  float buf[3];
  int nbuf;
  boolean_T includenans;
  int nnans;
} coder_internal_SortedBuffer;
#endif /* typedef_coder_internal_SortedBuffer */

#ifndef typedef_c_classreg_learning_classif_Com
#define typedef_c_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1581];
  float Children[3162];
  float CutPoint[1581];
  boolean_T NanCutPoints[1581];
  boolean_T InfCutPoints[1581];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[3162];
} c_classreg_learning_classif_Com;
#endif /* typedef_c_classreg_learning_classif_Com */

#ifndef typedef_d_classreg_learning_classif_Com
#define typedef_d_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1419];
  float Children[2838];
  float CutPoint[1419];
  boolean_T NanCutPoints[1419];
  boolean_T InfCutPoints[1419];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2838];
} d_classreg_learning_classif_Com;
#endif /* typedef_d_classreg_learning_classif_Com */

#ifndef typedef_e_classreg_learning_classif_Com
#define typedef_e_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1433];
  float Children[2866];
  float CutPoint[1433];
  boolean_T NanCutPoints[1433];
  boolean_T InfCutPoints[1433];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2866];
} e_classreg_learning_classif_Com;
#endif /* typedef_e_classreg_learning_classif_Com */

#ifndef typedef_f_classreg_learning_classif_Com
#define typedef_f_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1495];
  float Children[2990];
  float CutPoint[1495];
  boolean_T NanCutPoints[1495];
  boolean_T InfCutPoints[1495];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2990];
} f_classreg_learning_classif_Com;
#endif /* typedef_f_classreg_learning_classif_Com */

#ifndef typedef_g_classreg_learning_classif_Com
#define typedef_g_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1553];
  float Children[3106];
  float CutPoint[1553];
  boolean_T NanCutPoints[1553];
  boolean_T InfCutPoints[1553];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[3106];
} g_classreg_learning_classif_Com;
#endif /* typedef_g_classreg_learning_classif_Com */

#ifndef typedef_h_classreg_learning_classif_Com
#define typedef_h_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1383];
  float Children[2766];
  float CutPoint[1383];
  boolean_T NanCutPoints[1383];
  boolean_T InfCutPoints[1383];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2766];
} h_classreg_learning_classif_Com;
#endif /* typedef_h_classreg_learning_classif_Com */

#ifndef typedef_i_classreg_learning_classif_Com
#define typedef_i_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1323];
  float Children[2646];
  float CutPoint[1323];
  boolean_T NanCutPoints[1323];
  boolean_T InfCutPoints[1323];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2646];
} i_classreg_learning_classif_Com;
#endif /* typedef_i_classreg_learning_classif_Com */

#ifndef typedef_j_classreg_learning_classif_Com
#define typedef_j_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1363];
  float Children[2726];
  float CutPoint[1363];
  boolean_T NanCutPoints[1363];
  boolean_T InfCutPoints[1363];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2726];
} j_classreg_learning_classif_Com;
#endif /* typedef_j_classreg_learning_classif_Com */

#ifndef typedef_k_classreg_learning_classif_Com
#define typedef_k_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1265];
  float Children[2530];
  float CutPoint[1265];
  boolean_T NanCutPoints[1265];
  boolean_T InfCutPoints[1265];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2530];
} k_classreg_learning_classif_Com;
#endif /* typedef_k_classreg_learning_classif_Com */

#ifndef typedef_l_classreg_learning_classif_Com
#define typedef_l_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1349];
  float Children[2698];
  float CutPoint[1349];
  boolean_T NanCutPoints[1349];
  boolean_T InfCutPoints[1349];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2698];
} l_classreg_learning_classif_Com;
#endif /* typedef_l_classreg_learning_classif_Com */

#ifndef typedef_m_classreg_learning_classif_Com
#define typedef_m_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1279];
  float Children[2558];
  float CutPoint[1279];
  boolean_T NanCutPoints[1279];
  boolean_T InfCutPoints[1279];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2558];
} m_classreg_learning_classif_Com;
#endif /* typedef_m_classreg_learning_classif_Com */

#ifndef typedef_n_classreg_learning_classif_Com
#define typedef_n_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1611];
  float Children[3222];
  float CutPoint[1611];
  boolean_T NanCutPoints[1611];
  boolean_T InfCutPoints[1611];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[3222];
} n_classreg_learning_classif_Com;
#endif /* typedef_n_classreg_learning_classif_Com */

#ifndef typedef_o_classreg_learning_classif_Com
#define typedef_o_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1437];
  float Children[2874];
  float CutPoint[1437];
  boolean_T NanCutPoints[1437];
  boolean_T InfCutPoints[1437];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2874];
} o_classreg_learning_classif_Com;
#endif /* typedef_o_classreg_learning_classif_Com */

#ifndef typedef_p_classreg_learning_classif_Com
#define typedef_p_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1369];
  float Children[2738];
  float CutPoint[1369];
  boolean_T NanCutPoints[1369];
  boolean_T InfCutPoints[1369];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2738];
} p_classreg_learning_classif_Com;
#endif /* typedef_p_classreg_learning_classif_Com */

#ifndef typedef_q_classreg_learning_classif_Com
#define typedef_q_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1367];
  float Children[2734];
  float CutPoint[1367];
  boolean_T NanCutPoints[1367];
  boolean_T InfCutPoints[1367];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2734];
} q_classreg_learning_classif_Com;
#endif /* typedef_q_classreg_learning_classif_Com */

#ifndef typedef_r_classreg_learning_classif_Com
#define typedef_r_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1479];
  float Children[2958];
  float CutPoint[1479];
  boolean_T NanCutPoints[1479];
  boolean_T InfCutPoints[1479];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2958];
} r_classreg_learning_classif_Com;
#endif /* typedef_r_classreg_learning_classif_Com */

#ifndef typedef_s_classreg_learning_classif_Com
#define typedef_s_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1469];
  float Children[2938];
  float CutPoint[1469];
  boolean_T NanCutPoints[1469];
  boolean_T InfCutPoints[1469];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2938];
} s_classreg_learning_classif_Com;
#endif /* typedef_s_classreg_learning_classif_Com */

#ifndef typedef_t_classreg_learning_classif_Com
#define typedef_t_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1663];
  float Children[3326];
  float CutPoint[1663];
  boolean_T NanCutPoints[1663];
  boolean_T InfCutPoints[1663];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[3326];
} t_classreg_learning_classif_Com;
#endif /* typedef_t_classreg_learning_classif_Com */

#ifndef typedef_u_classreg_learning_classif_Com
#define typedef_u_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1411];
  float Children[2822];
  float CutPoint[1411];
  boolean_T NanCutPoints[1411];
  boolean_T InfCutPoints[1411];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2822];
} u_classreg_learning_classif_Com;
#endif /* typedef_u_classreg_learning_classif_Com */

#ifndef typedef_v_classreg_learning_classif_Com
#define typedef_v_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[1317];
  float Children[2634];
  float CutPoint[1317];
  boolean_T NanCutPoints[1317];
  boolean_T InfCutPoints[1317];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[2634];
} v_classreg_learning_classif_Com;
#endif /* typedef_v_classreg_learning_classif_Com */

#ifndef typedef_w_classreg_learning_classif_Com
#define typedef_w_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[709];
  float Children[1418];
  float CutPoint[709];
  boolean_T NanCutPoints[709];
  boolean_T InfCutPoints[709];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1418];
} w_classreg_learning_classif_Com;
#endif /* typedef_w_classreg_learning_classif_Com */

#ifndef typedef_x_classreg_learning_classif_Com
#define typedef_x_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[783];
  float Children[1566];
  float CutPoint[783];
  boolean_T NanCutPoints[783];
  boolean_T InfCutPoints[783];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1566];
} x_classreg_learning_classif_Com;
#endif /* typedef_x_classreg_learning_classif_Com */

#ifndef typedef_y_classreg_learning_classif_Com
#define typedef_y_classreg_learning_classif_Com
typedef struct {
  float CutPredictorIndex[649];
  float Children[1298];
  float CutPoint[649];
  boolean_T NanCutPoints[649];
  boolean_T InfCutPoints[649];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1298];
} y_classreg_learning_classif_Com;
#endif /* typedef_y_classreg_learning_classif_Com */

#ifndef typedef_ab_classreg_learning_classif_Co
#define typedef_ab_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[765];
  float Children[1530];
  float CutPoint[765];
  boolean_T NanCutPoints[765];
  boolean_T InfCutPoints[765];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1530];
} ab_classreg_learning_classif_Co;
#endif /* typedef_ab_classreg_learning_classif_Co */

#ifndef typedef_bb_classreg_learning_classif_Co
#define typedef_bb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[699];
  float Children[1398];
  float CutPoint[699];
  boolean_T NanCutPoints[699];
  boolean_T InfCutPoints[699];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1398];
} bb_classreg_learning_classif_Co;
#endif /* typedef_bb_classreg_learning_classif_Co */

#ifndef typedef_cb_classreg_learning_classif_Co
#define typedef_cb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[829];
  float Children[1658];
  float CutPoint[829];
  boolean_T NanCutPoints[829];
  boolean_T InfCutPoints[829];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1658];
} cb_classreg_learning_classif_Co;
#endif /* typedef_cb_classreg_learning_classif_Co */

#ifndef typedef_db_classreg_learning_classif_Co
#define typedef_db_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[651];
  float Children[1302];
  float CutPoint[651];
  boolean_T NanCutPoints[651];
  boolean_T InfCutPoints[651];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1302];
} db_classreg_learning_classif_Co;
#endif /* typedef_db_classreg_learning_classif_Co */

#ifndef typedef_eb_classreg_learning_classif_Co
#define typedef_eb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[551];
  float Children[1102];
  float CutPoint[551];
  boolean_T NanCutPoints[551];
  boolean_T InfCutPoints[551];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1102];
} eb_classreg_learning_classif_Co;
#endif /* typedef_eb_classreg_learning_classif_Co */

#ifndef typedef_fb_classreg_learning_classif_Co
#define typedef_fb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[667];
  float Children[1334];
  float CutPoint[667];
  boolean_T NanCutPoints[667];
  boolean_T InfCutPoints[667];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1334];
} fb_classreg_learning_classif_Co;
#endif /* typedef_fb_classreg_learning_classif_Co */

#ifndef typedef_gb_classreg_learning_classif_Co
#define typedef_gb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[607];
  float Children[1214];
  float CutPoint[607];
  boolean_T NanCutPoints[607];
  boolean_T InfCutPoints[607];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1214];
} gb_classreg_learning_classif_Co;
#endif /* typedef_gb_classreg_learning_classif_Co */

#ifndef typedef_hb_classreg_learning_classif_Co
#define typedef_hb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[623];
  float Children[1246];
  float CutPoint[623];
  boolean_T NanCutPoints[623];
  boolean_T InfCutPoints[623];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1246];
} hb_classreg_learning_classif_Co;
#endif /* typedef_hb_classreg_learning_classif_Co */

#ifndef typedef_ib_classreg_learning_classif_Co
#define typedef_ib_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[539];
  float Children[1078];
  float CutPoint[539];
  boolean_T NanCutPoints[539];
  boolean_T InfCutPoints[539];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1078];
} ib_classreg_learning_classif_Co;
#endif /* typedef_ib_classreg_learning_classif_Co */

#ifndef typedef_jb_classreg_learning_classif_Co
#define typedef_jb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[521];
  float Children[1042];
  float CutPoint[521];
  boolean_T NanCutPoints[521];
  boolean_T InfCutPoints[521];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1042];
} jb_classreg_learning_classif_Co;
#endif /* typedef_jb_classreg_learning_classif_Co */

#ifndef typedef_kb_classreg_learning_classif_Co
#define typedef_kb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[527];
  float Children[1054];
  float CutPoint[527];
  boolean_T NanCutPoints[527];
  boolean_T InfCutPoints[527];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1054];
} kb_classreg_learning_classif_Co;
#endif /* typedef_kb_classreg_learning_classif_Co */

#ifndef typedef_lb_classreg_learning_classif_Co
#define typedef_lb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[543];
  float Children[1086];
  float CutPoint[543];
  boolean_T NanCutPoints[543];
  boolean_T InfCutPoints[543];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1086];
} lb_classreg_learning_classif_Co;
#endif /* typedef_lb_classreg_learning_classif_Co */

#ifndef typedef_mb_classreg_learning_classif_Co
#define typedef_mb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[467];
  float Children[934];
  float CutPoint[467];
  boolean_T NanCutPoints[467];
  boolean_T InfCutPoints[467];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[934];
} mb_classreg_learning_classif_Co;
#endif /* typedef_mb_classreg_learning_classif_Co */

#ifndef typedef_nb_classreg_learning_classif_Co
#define typedef_nb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[611];
  float Children[1222];
  float CutPoint[611];
  boolean_T NanCutPoints[611];
  boolean_T InfCutPoints[611];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1222];
} nb_classreg_learning_classif_Co;
#endif /* typedef_nb_classreg_learning_classif_Co */

#ifndef typedef_ob_classreg_learning_classif_Co
#define typedef_ob_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[457];
  float Children[914];
  float CutPoint[457];
  boolean_T NanCutPoints[457];
  boolean_T InfCutPoints[457];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[914];
} ob_classreg_learning_classif_Co;
#endif /* typedef_ob_classreg_learning_classif_Co */

#ifndef typedef_pb_classreg_learning_classif_Co
#define typedef_pb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[451];
  float Children[902];
  float CutPoint[451];
  boolean_T NanCutPoints[451];
  boolean_T InfCutPoints[451];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[902];
} pb_classreg_learning_classif_Co;
#endif /* typedef_pb_classreg_learning_classif_Co */

#ifndef typedef_qb_classreg_learning_classif_Co
#define typedef_qb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[425];
  float Children[850];
  float CutPoint[425];
  boolean_T NanCutPoints[425];
  boolean_T InfCutPoints[425];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[850];
} qb_classreg_learning_classif_Co;
#endif /* typedef_qb_classreg_learning_classif_Co */

#ifndef typedef_rb_classreg_learning_classif_Co
#define typedef_rb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[343];
  float Children[686];
  float CutPoint[343];
  boolean_T NanCutPoints[343];
  boolean_T InfCutPoints[343];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[686];
} rb_classreg_learning_classif_Co;
#endif /* typedef_rb_classreg_learning_classif_Co */

#ifndef typedef_sb_classreg_learning_classif_Co
#define typedef_sb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[537];
  float Children[1074];
  float CutPoint[537];
  boolean_T NanCutPoints[537];
  boolean_T InfCutPoints[537];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1074];
} sb_classreg_learning_classif_Co;
#endif /* typedef_sb_classreg_learning_classif_Co */

#ifndef typedef_tb_classreg_learning_classif_Co
#define typedef_tb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[529];
  float Children[1058];
  float CutPoint[529];
  boolean_T NanCutPoints[529];
  boolean_T InfCutPoints[529];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1058];
} tb_classreg_learning_classif_Co;
#endif /* typedef_tb_classreg_learning_classif_Co */

#ifndef typedef_ub_classreg_learning_classif_Co
#define typedef_ub_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[427];
  float Children[854];
  float CutPoint[427];
  boolean_T NanCutPoints[427];
  boolean_T InfCutPoints[427];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[854];
} ub_classreg_learning_classif_Co;
#endif /* typedef_ub_classreg_learning_classif_Co */

#ifndef typedef_vb_classreg_learning_classif_Co
#define typedef_vb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[447];
  float Children[894];
  float CutPoint[447];
  boolean_T NanCutPoints[447];
  boolean_T InfCutPoints[447];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[894];
} vb_classreg_learning_classif_Co;
#endif /* typedef_vb_classreg_learning_classif_Co */

#ifndef typedef_wb_classreg_learning_classif_Co
#define typedef_wb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[563];
  float Children[1126];
  float CutPoint[563];
  boolean_T NanCutPoints[563];
  boolean_T InfCutPoints[563];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1126];
} wb_classreg_learning_classif_Co;
#endif /* typedef_wb_classreg_learning_classif_Co */

#ifndef typedef_xb_classreg_learning_classif_Co
#define typedef_xb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[469];
  float Children[938];
  float CutPoint[469];
  boolean_T NanCutPoints[469];
  boolean_T InfCutPoints[469];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[938];
} xb_classreg_learning_classif_Co;
#endif /* typedef_xb_classreg_learning_classif_Co */

#ifndef typedef_yb_classreg_learning_classif_Co
#define typedef_yb_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[471];
  float Children[942];
  float CutPoint[471];
  boolean_T NanCutPoints[471];
  boolean_T InfCutPoints[471];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[942];
} yb_classreg_learning_classif_Co;
#endif /* typedef_yb_classreg_learning_classif_Co */

#ifndef typedef_ac_classreg_learning_classif_Co
#define typedef_ac_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[555];
  float Children[1110];
  float CutPoint[555];
  boolean_T NanCutPoints[555];
  boolean_T InfCutPoints[555];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1110];
} ac_classreg_learning_classif_Co;
#endif /* typedef_ac_classreg_learning_classif_Co */

#ifndef typedef_bc_classreg_learning_classif_Co
#define typedef_bc_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[423];
  float Children[846];
  float CutPoint[423];
  boolean_T NanCutPoints[423];
  boolean_T InfCutPoints[423];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[846];
} bc_classreg_learning_classif_Co;
#endif /* typedef_bc_classreg_learning_classif_Co */

#ifndef typedef_cc_classreg_learning_classif_Co
#define typedef_cc_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[593];
  float Children[1186];
  float CutPoint[593];
  boolean_T NanCutPoints[593];
  boolean_T InfCutPoints[593];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1186];
} cc_classreg_learning_classif_Co;
#endif /* typedef_cc_classreg_learning_classif_Co */

#ifndef typedef_dc_classreg_learning_classif_Co
#define typedef_dc_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[463];
  float Children[926];
  float CutPoint[463];
  boolean_T NanCutPoints[463];
  boolean_T InfCutPoints[463];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[926];
} dc_classreg_learning_classif_Co;
#endif /* typedef_dc_classreg_learning_classif_Co */

#ifndef typedef_ec_classreg_learning_classif_Co
#define typedef_ec_classreg_learning_classif_Co
typedef struct {
  float CutPredictorIndex[581];
  float Children[1162];
  float CutPoint[581];
  boolean_T NanCutPoints[581];
  boolean_T InfCutPoints[581];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  float Prior[2];
  boolean_T ClassLogicalIndices[2];
  float Cost[4];
  float ClassProbability[1162];
} ec_classreg_learning_classif_Co;
#endif /* typedef_ec_classreg_learning_classif_Co */

#ifndef typedef_fc_classreg_learning_classif_Co
#define typedef_fc_classreg_learning_classif_Co
typedef struct {
  float Prior[2];
} fc_classreg_learning_classif_Co;
#endif /* typedef_fc_classreg_learning_classif_Co */

#ifndef typedef_gc_classreg_learning_classif_Co
#define typedef_gc_classreg_learning_classif_Co
typedef struct {
  boolean_T IsCached[15];
  float Prior[2];
} gc_classreg_learning_classif_Co;
#endif /* typedef_gc_classreg_learning_classif_Co */

#endif
/*
 * File trailer for Yuxuan_iterative_test_single_internal_types.h
 *
 * [EOF]
 */
