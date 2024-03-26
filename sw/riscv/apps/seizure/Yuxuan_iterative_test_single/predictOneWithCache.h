/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictOneWithCache.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

/* Include Files */
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void ab_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[829],
    const float weak_learner_Children[1658],
    const float weak_learner_CutPoint[829],
    const boolean_T weak_learner_NanCutPoints[829],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1658], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T ac_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[423],
    const float weak_learner_Children[846],
    const float weak_learner_CutPoint[423],
    const boolean_T weak_learner_NanCutPoints[423],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[846],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T b_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1419],
    const float weak_learner_Children[2838],
    const float weak_learner_CutPoint[1419],
    const boolean_T weak_learner_NanCutPoints[1419],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2838],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void bb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[651],
    const float weak_learner_Children[1302],
    const float weak_learner_CutPoint[651],
    const boolean_T weak_learner_NanCutPoints[651],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1302], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T bc_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[425],
    const float weak_learner_Children[850],
    const float weak_learner_CutPoint[425],
    const boolean_T weak_learner_NanCutPoints[425],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[850],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T c_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1433],
    const float weak_learner_Children[2866],
    const float weak_learner_CutPoint[1433],
    const boolean_T weak_learner_NanCutPoints[1433],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2866],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void cb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[551],
    const float weak_learner_Children[1102],
    const float weak_learner_CutPoint[551],
    const boolean_T weak_learner_NanCutPoints[551],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1102], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T cc_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[611],
    const float weak_learner_Children[1222],
    const float weak_learner_CutPoint[611],
    const boolean_T weak_learner_NanCutPoints[611],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1222],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T d_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1495],
    const float weak_learner_Children[2990],
    const float weak_learner_CutPoint[1495],
    const boolean_T weak_learner_NanCutPoints[1495],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2990],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void db_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[667],
    const float weak_learner_Children[1334],
    const float weak_learner_CutPoint[667],
    const boolean_T weak_learner_NanCutPoints[667],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1334], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T dc_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[447],
    const float weak_learner_Children[894],
    const float weak_learner_CutPoint[447],
    const boolean_T weak_learner_NanCutPoints[447],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[894],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T e_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1553],
    const float weak_learner_Children[3106],
    const float weak_learner_CutPoint[1553],
    const boolean_T weak_learner_NanCutPoints[1553],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[3106],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void eb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[607],
    const float weak_learner_Children[1214],
    const float weak_learner_CutPoint[607],
    const boolean_T weak_learner_NanCutPoints[607],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1214], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T ec_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[593],
    const float weak_learner_Children[1186],
    const float weak_learner_CutPoint[593],
    const boolean_T weak_learner_NanCutPoints[593],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1186],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T f_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1383],
    const float weak_learner_Children[2766],
    const float weak_learner_CutPoint[1383],
    const boolean_T weak_learner_NanCutPoints[1383],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2766],
    const emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score);

void fb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[623],
    const float weak_learner_Children[1246],
    const float weak_learner_CutPoint[623],
    const boolean_T weak_learner_NanCutPoints[623],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1246], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T fc_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[343],
    const float weak_learner_Children[686],
    const float weak_learner_CutPoint[343],
    const boolean_T weak_learner_NanCutPoints[343],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[686],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void g_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1323],
    const float weak_learner_Children[2646],
    const float weak_learner_CutPoint[1323],
    const boolean_T weak_learner_NanCutPoints[1323],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2646], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void gb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[539],
    const float weak_learner_Children[1078],
    const float weak_learner_CutPoint[539],
    const boolean_T weak_learner_NanCutPoints[539],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1078], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T gc_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[463],
    const float weak_learner_Children[926],
    const float weak_learner_CutPoint[463],
    const boolean_T weak_learner_NanCutPoints[463],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[926],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void h_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1363],
    const float weak_learner_Children[2726],
    const float weak_learner_CutPoint[1363],
    const boolean_T weak_learner_NanCutPoints[1363],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2726], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void hb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[521],
    const float weak_learner_Children[1042],
    const float weak_learner_CutPoint[521],
    const boolean_T weak_learner_NanCutPoints[521],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1042], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T hc_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[581],
    const float weak_learner_Children[1162],
    const float weak_learner_CutPoint[581],
    const boolean_T weak_learner_NanCutPoints[581],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1162],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void i_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1265],
    const float weak_learner_Children[2530],
    const float weak_learner_CutPoint[1265],
    const boolean_T weak_learner_NanCutPoints[1265],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2530], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void ib_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[527],
    const float weak_learner_Children[1054],
    const float weak_learner_CutPoint[527],
    const boolean_T weak_learner_NanCutPoints[527],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1054], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void j_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1349],
    const float weak_learner_Children[2698],
    const float weak_learner_CutPoint[1349],
    const boolean_T weak_learner_NanCutPoints[1349],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2698], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void jb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[543],
    const float weak_learner_Children[1086],
    const float weak_learner_CutPoint[543],
    const boolean_T weak_learner_NanCutPoints[543],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1086], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void k_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1279],
    const float weak_learner_Children[2558],
    const float weak_learner_CutPoint[1279],
    const boolean_T weak_learner_NanCutPoints[1279],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2558], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T kb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[467],
    const float weak_learner_Children[934],
    const float weak_learner_CutPoint[467],
    const boolean_T weak_learner_NanCutPoints[467],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[934],
    const emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score);

void l_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1611],
    const float weak_learner_Children[3222],
    const float weak_learner_CutPoint[1611],
    const boolean_T weak_learner_NanCutPoints[1611],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[3222], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void lb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[611],
    const float weak_learner_Children[1222],
    const float weak_learner_CutPoint[611],
    const boolean_T weak_learner_NanCutPoints[611],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1222], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void m_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1437],
    const float weak_learner_Children[2874],
    const float weak_learner_CutPoint[1437],
    const boolean_T weak_learner_NanCutPoints[1437],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2874], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void mb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[457],
    const float weak_learner_Children[914],
    const float weak_learner_CutPoint[457],
    const boolean_T weak_learner_NanCutPoints[457],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[914], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void n_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1369],
    const float weak_learner_Children[2738],
    const float weak_learner_CutPoint[1369],
    const boolean_T weak_learner_NanCutPoints[1369],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2738], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void nb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[451],
    const float weak_learner_Children[902],
    const float weak_learner_CutPoint[451],
    const boolean_T weak_learner_NanCutPoints[451],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[902], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void o_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1367],
    const float weak_learner_Children[2734],
    const float weak_learner_CutPoint[1367],
    const boolean_T weak_learner_NanCutPoints[1367],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2734], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void ob_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[425],
    const float weak_learner_Children[850],
    const float weak_learner_CutPoint[425],
    const boolean_T weak_learner_NanCutPoints[425],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[850], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void p_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1479],
    const float weak_learner_Children[2958],
    const float weak_learner_CutPoint[1479],
    const boolean_T weak_learner_NanCutPoints[1479],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2958], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void pb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[343],
    const float weak_learner_Children[686],
    const float weak_learner_CutPoint[343],
    const boolean_T weak_learner_NanCutPoints[343],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[686], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1581],
    const float weak_learner_Children[3162],
    const float weak_learner_CutPoint[1581],
    const boolean_T weak_learner_NanCutPoints[1581],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[3162],
    const emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score);

void q_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1469],
    const float weak_learner_Children[2938],
    const float weak_learner_CutPoint[1469],
    const boolean_T weak_learner_NanCutPoints[1469],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2938], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void qb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[537],
    const float weak_learner_Children[1074],
    const float weak_learner_CutPoint[537],
    const boolean_T weak_learner_NanCutPoints[537],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1074], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void r_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1663],
    const float weak_learner_Children[3326],
    const float weak_learner_CutPoint[1663],
    const boolean_T weak_learner_NanCutPoints[1663],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[3326], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void rb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[529],
    const float weak_learner_Children[1058],
    const float weak_learner_CutPoint[529],
    const boolean_T weak_learner_NanCutPoints[529],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1058], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void s_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1411],
    const float weak_learner_Children[2822],
    const float weak_learner_CutPoint[1411],
    const boolean_T weak_learner_NanCutPoints[1411],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2822], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void sb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[427],
    const float weak_learner_Children[854],
    const float weak_learner_CutPoint[427],
    const boolean_T weak_learner_NanCutPoints[427],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[854], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void t_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[1317],
    const float weak_learner_Children[2634],
    const float weak_learner_CutPoint[1317],
    const boolean_T weak_learner_NanCutPoints[1317],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[2634], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void tb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[447],
    const float weak_learner_Children[894],
    const float weak_learner_CutPoint[447],
    const boolean_T weak_learner_NanCutPoints[447],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[894], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T u_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[709],
    const float weak_learner_Children[1418],
    const float weak_learner_CutPoint[709],
    const boolean_T weak_learner_NanCutPoints[709],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1418],
    const emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score);

void ub_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[563],
    const float weak_learner_Children[1126],
    const float weak_learner_CutPoint[563],
    const boolean_T weak_learner_NanCutPoints[563],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1126], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void v_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[783],
    const float weak_learner_Children[1566],
    const float weak_learner_CutPoint[783],
    const boolean_T weak_learner_NanCutPoints[783],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1566], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void vb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[469],
    const float weak_learner_Children[938],
    const float weak_learner_CutPoint[469],
    const boolean_T weak_learner_NanCutPoints[469],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[938], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void w_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[649],
    const float weak_learner_Children[1298],
    const float weak_learner_CutPoint[649],
    const boolean_T weak_learner_NanCutPoints[649],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1298], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void wb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[471],
    const float weak_learner_Children[942],
    const float weak_learner_CutPoint[471],
    const boolean_T weak_learner_NanCutPoints[471],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[942], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

void x_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[765],
    const float weak_learner_Children[1530],
    const float weak_learner_CutPoint[765],
    const boolean_T weak_learner_NanCutPoints[765],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1530], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T xb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[451],
    const float weak_learner_Children[902],
    const float weak_learner_CutPoint[451],
    const boolean_T weak_learner_NanCutPoints[451],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[902],
    const emxArray_boolean_T *useObsForLearner, emxArray_real32_T *score);

void y_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[699],
    const float weak_learner_Children[1398],
    const float weak_learner_CutPoint[699],
    const boolean_T weak_learner_NanCutPoints[699],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1398], boolean_T *cached,
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

boolean_T yb_predictOneWithCache(
    const emxArray_real32_T *X, emxArray_real32_T *cachedScore,
    emxArray_real32_T *cachedWeights, const char combiner[15],
    const float weak_learner_CutPredictorIndex[555],
    const float weak_learner_Children[1110],
    const float weak_learner_CutPoint[555],
    const boolean_T weak_learner_NanCutPoints[555],
    const float weak_learner_Prior[2], const float weak_learner_Cost[4],
    const float weak_learner_ClassProbability[1110],
    const emxArray_boolean_T *useObsForLearner, boolean_T initCache,
    emxArray_real32_T *score);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for predictOneWithCache.h
 *
 * [EOF]
 */
