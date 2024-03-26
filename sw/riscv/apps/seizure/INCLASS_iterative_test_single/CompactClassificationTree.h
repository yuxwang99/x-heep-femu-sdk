/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include Files */
#include "INCLASS_iterative_test_single_internal_types.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void ab_CompactClassificationTree_Co(ab_classreg_learning_classif_Co *obj);

void ab_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[765], const float obj_Children[1530],
    const float obj_CutPoint[765], const boolean_T obj_NanCutPoints[765],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1530], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void ac_CompactClassificationTree_Co(yb_classreg_learning_classif_Co *obj);

void ac_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[451], const float obj_Children[902],
    const float obj_CutPoint[451], const boolean_T obj_NanCutPoints[451],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[902], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void bb_CompactClassificationTree_Co(bb_classreg_learning_classif_Co *obj);

void bb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[699], const float obj_Children[1398],
    const float obj_CutPoint[699], const boolean_T obj_NanCutPoints[699],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1398], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void bc_CompactClassificationTree_Co(pb_classreg_learning_classif_Co *obj);

void bc_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[555], const float obj_Children[1110],
    const float obj_CutPoint[555], const boolean_T obj_NanCutPoints[555],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1110], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void c_CompactClassificationTree_Com(c_classreg_learning_classif_Com *obj);

void c_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1581], const float obj_Children[3162],
    const float obj_CutPoint[1581], const boolean_T obj_NanCutPoints[1581],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[3162], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void cb_CompactClassificationTree_Co(cb_classreg_learning_classif_Co *obj);

void cb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[829], const float obj_Children[1658],
    const float obj_CutPoint[829], const boolean_T obj_NanCutPoints[829],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1658], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void cc_CompactClassificationTree_Co(pb_classreg_learning_classif_Co *obj);

void cc_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[423], const float obj_Children[846],
    const float obj_CutPoint[423], const boolean_T obj_NanCutPoints[423],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[846], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void d_CompactClassificationTree_Com(d_classreg_learning_classif_Com *obj);

void d_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1419], const float obj_Children[2838],
    const float obj_CutPoint[1419], const boolean_T obj_NanCutPoints[1419],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2838], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void db_CompactClassificationTree_Co(db_classreg_learning_classif_Co *obj);

void db_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[651], const float obj_Children[1302],
    const float obj_CutPoint[651], const boolean_T obj_NanCutPoints[651],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1302], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void dc_CompactClassificationTree_Co(ac_classreg_learning_classif_Co *obj);

void dc_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[425], const float obj_Children[850],
    const float obj_CutPoint[425], const boolean_T obj_NanCutPoints[425],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[850], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void e_CompactClassificationTree_Com(e_classreg_learning_classif_Com *obj);

void e_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1433], const float obj_Children[2866],
    const float obj_CutPoint[1433], const boolean_T obj_NanCutPoints[1433],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2866], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void eb_CompactClassificationTree_Co(eb_classreg_learning_classif_Co *obj);

void eb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[551], const float obj_Children[1102],
    const float obj_CutPoint[551], const boolean_T obj_NanCutPoints[551],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1102], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void ec_CompactClassificationTree_Co(bc_classreg_learning_classif_Co *obj);

void ec_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[611], const float obj_Children[1222],
    const float obj_CutPoint[611], const boolean_T obj_NanCutPoints[611],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1222], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void f_CompactClassificationTree_Com(f_classreg_learning_classif_Com *obj);

void f_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1495], const float obj_Children[2990],
    const float obj_CutPoint[1495], const boolean_T obj_NanCutPoints[1495],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2990], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void fb_CompactClassificationTree_Co(fb_classreg_learning_classif_Co *obj);

void fb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[667], const float obj_Children[1334],
    const float obj_CutPoint[667], const boolean_T obj_NanCutPoints[667],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1334], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void fc_CompactClassificationTree_Co(qb_classreg_learning_classif_Co *obj);

void fc_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[447], const float obj_Children[894],
    const float obj_CutPoint[447], const boolean_T obj_NanCutPoints[447],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[894], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void g_CompactClassificationTree_Com(g_classreg_learning_classif_Com *obj);

void g_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1553], const float obj_Children[3106],
    const float obj_CutPoint[1553], const boolean_T obj_NanCutPoints[1553],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[3106], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void gb_CompactClassificationTree_Co(gb_classreg_learning_classif_Co *obj);

void gb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[607], const float obj_Children[1214],
    const float obj_CutPoint[607], const boolean_T obj_NanCutPoints[607],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1214], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void gc_CompactClassificationTree_Co(nb_classreg_learning_classif_Co *obj);

void gc_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[593], const float obj_Children[1186],
    const float obj_CutPoint[593], const boolean_T obj_NanCutPoints[593],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1186], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void h_CompactClassificationTree_Com(h_classreg_learning_classif_Com *obj);

void h_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1383], const float obj_Children[2766],
    const float obj_CutPoint[1383], const boolean_T obj_NanCutPoints[1383],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2766], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void hb_CompactClassificationTree_Co(hb_classreg_learning_classif_Co *obj);

void hb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[623], const float obj_Children[1246],
    const float obj_CutPoint[623], const boolean_T obj_NanCutPoints[623],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1246], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void hc_CompactClassificationTree_Co(vb_classreg_learning_classif_Co *obj);

void hc_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[343], const float obj_Children[686],
    const float obj_CutPoint[343], const boolean_T obj_NanCutPoints[343],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[686], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void i_CompactClassificationTree_Com(i_classreg_learning_classif_Com *obj);

void i_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1323], const float obj_Children[2646],
    const float obj_CutPoint[1323], const boolean_T obj_NanCutPoints[1323],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2646], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void ib_CompactClassificationTree_Co(ib_classreg_learning_classif_Co *obj);

void ib_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[539], const float obj_Children[1078],
    const float obj_CutPoint[539], const boolean_T obj_NanCutPoints[539],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1078], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void ic_CompactClassificationTree_Co(cc_classreg_learning_classif_Co *obj);

void ic_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[463], const float obj_Children[926],
    const float obj_CutPoint[463], const boolean_T obj_NanCutPoints[463],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[926], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void j_CompactClassificationTree_Com(j_classreg_learning_classif_Com *obj);

void j_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1363], const float obj_Children[2726],
    const float obj_CutPoint[1363], const boolean_T obj_NanCutPoints[1363],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2726], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void jb_CompactClassificationTree_Co(jb_classreg_learning_classif_Co *obj);

void jb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[521], const float obj_Children[1042],
    const float obj_CutPoint[521], const boolean_T obj_NanCutPoints[521],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1042], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void jc_CompactClassificationTree_Co(rb_classreg_learning_classif_Co *obj);

void jc_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[581], const float obj_Children[1162],
    const float obj_CutPoint[581], const boolean_T obj_NanCutPoints[581],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1162], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void k_CompactClassificationTree_Com(k_classreg_learning_classif_Com *obj);

void k_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1265], const float obj_Children[2530],
    const float obj_CutPoint[1265], const boolean_T obj_NanCutPoints[1265],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2530], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void kb_CompactClassificationTree_Co(kb_classreg_learning_classif_Co *obj);

void kb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[527], const float obj_Children[1054],
    const float obj_CutPoint[527], const boolean_T obj_NanCutPoints[527],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1054], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void kc_CompactClassificationTree_Co(dc_classreg_learning_classif_Co *obj);

void l_CompactClassificationTree_Com(l_classreg_learning_classif_Com *obj);

void l_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1349], const float obj_Children[2698],
    const float obj_CutPoint[1349], const boolean_T obj_NanCutPoints[1349],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2698], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void lb_CompactClassificationTree_Co(lb_classreg_learning_classif_Co *obj);

void lb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[543], const float obj_Children[1086],
    const float obj_CutPoint[543], const boolean_T obj_NanCutPoints[543],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1086], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void lc_CompactClassificationTree_Co(ec_classreg_learning_classif_Co *obj);

void m_CompactClassificationTree_Com(m_classreg_learning_classif_Com *obj);

void m_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1279], const float obj_Children[2558],
    const float obj_CutPoint[1279], const boolean_T obj_NanCutPoints[1279],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2558], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void mb_CompactClassificationTree_Co(mb_classreg_learning_classif_Co *obj);

void mb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[467], const float obj_Children[934],
    const float obj_CutPoint[467], const boolean_T obj_NanCutPoints[467],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[934], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void n_CompactClassificationTree_Com(n_classreg_learning_classif_Com *obj);

void n_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1611], const float obj_Children[3222],
    const float obj_CutPoint[1611], const boolean_T obj_NanCutPoints[1611],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[3222], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void nb_CompactClassificationTree_Co(nb_classreg_learning_classif_Co *obj);

void nb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[611], const float obj_Children[1222],
    const float obj_CutPoint[611], const boolean_T obj_NanCutPoints[611],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1222], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void o_CompactClassificationTree_Com(o_classreg_learning_classif_Com *obj);

void o_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1437], const float obj_Children[2874],
    const float obj_CutPoint[1437], const boolean_T obj_NanCutPoints[1437],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2874], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void ob_CompactClassificationTree_Co(ob_classreg_learning_classif_Co *obj);

void ob_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[457], const float obj_Children[914],
    const float obj_CutPoint[457], const boolean_T obj_NanCutPoints[457],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[914], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void p_CompactClassificationTree_Com(p_classreg_learning_classif_Com *obj);

void p_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1369], const float obj_Children[2738],
    const float obj_CutPoint[1369], const boolean_T obj_NanCutPoints[1369],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2738], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void pb_CompactClassificationTree_Co(pb_classreg_learning_classif_Co *obj);

void pb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[451], const float obj_Children[902],
    const float obj_CutPoint[451], const boolean_T obj_NanCutPoints[451],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[902], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void q_CompactClassificationTree_Com(q_classreg_learning_classif_Com *obj);

void q_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1367], const float obj_Children[2734],
    const float obj_CutPoint[1367], const boolean_T obj_NanCutPoints[1367],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2734], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void qb_CompactClassificationTree_Co(qb_classreg_learning_classif_Co *obj);

void qb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[425], const float obj_Children[850],
    const float obj_CutPoint[425], const boolean_T obj_NanCutPoints[425],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[850], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void r_CompactClassificationTree_Com(r_classreg_learning_classif_Com *obj);

void r_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1479], const float obj_Children[2958],
    const float obj_CutPoint[1479], const boolean_T obj_NanCutPoints[1479],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2958], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void rb_CompactClassificationTree_Co(rb_classreg_learning_classif_Co *obj);

void rb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[343], const float obj_Children[686],
    const float obj_CutPoint[343], const boolean_T obj_NanCutPoints[343],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[686], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void s_CompactClassificationTree_Com(s_classreg_learning_classif_Com *obj);

void s_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1469], const float obj_Children[2938],
    const float obj_CutPoint[1469], const boolean_T obj_NanCutPoints[1469],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2938], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void sb_CompactClassificationTree_Co(sb_classreg_learning_classif_Co *obj);

void sb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[537], const float obj_Children[1074],
    const float obj_CutPoint[537], const boolean_T obj_NanCutPoints[537],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1074], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void t_CompactClassificationTree_Com(t_classreg_learning_classif_Com *obj);

void t_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1663], const float obj_Children[3326],
    const float obj_CutPoint[1663], const boolean_T obj_NanCutPoints[1663],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[3326], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void tb_CompactClassificationTree_Co(tb_classreg_learning_classif_Co *obj);

void tb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[529], const float obj_Children[1058],
    const float obj_CutPoint[529], const boolean_T obj_NanCutPoints[529],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1058], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void u_CompactClassificationTree_Com(u_classreg_learning_classif_Com *obj);

void u_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1411], const float obj_Children[2822],
    const float obj_CutPoint[1411], const boolean_T obj_NanCutPoints[1411],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2822], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void ub_CompactClassificationTree_Co(ub_classreg_learning_classif_Co *obj);

void ub_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[427], const float obj_Children[854],
    const float obj_CutPoint[427], const boolean_T obj_NanCutPoints[427],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[854], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void v_CompactClassificationTree_Com(v_classreg_learning_classif_Com *obj);

void v_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[1317], const float obj_Children[2634],
    const float obj_CutPoint[1317], const boolean_T obj_NanCutPoints[1317],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[2634], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void vb_CompactClassificationTree_Co(vb_classreg_learning_classif_Co *obj);

void vb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[447], const float obj_Children[894],
    const float obj_CutPoint[447], const boolean_T obj_NanCutPoints[447],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[894], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void w_CompactClassificationTree_Com(w_classreg_learning_classif_Com *obj);

void w_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[709], const float obj_Children[1418],
    const float obj_CutPoint[709], const boolean_T obj_NanCutPoints[709],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1418], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void wb_CompactClassificationTree_Co(wb_classreg_learning_classif_Co *obj);

void wb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[563], const float obj_Children[1126],
    const float obj_CutPoint[563], const boolean_T obj_NanCutPoints[563],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1126], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void x_CompactClassificationTree_Com(x_classreg_learning_classif_Com *obj);

void x_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[783], const float obj_Children[1566],
    const float obj_CutPoint[783], const boolean_T obj_NanCutPoints[783],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1566], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void xb_CompactClassificationTree_Co(ub_classreg_learning_classif_Co *obj);

void xb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[469], const float obj_Children[938],
    const float obj_CutPoint[469], const boolean_T obj_NanCutPoints[469],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[938], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void y_CompactClassificationTree_Com(y_classreg_learning_classif_Com *obj);

void y_CompactClassificationTree_pre(
    const float obj_CutPredictorIndex[649], const float obj_Children[1298],
    const float obj_CutPoint[649], const boolean_T obj_NanCutPoints[649],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[1298], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

void yb_CompactClassificationTree_Co(xb_classreg_learning_classif_Co *obj);

void yb_CompactClassificationTree_pr(
    const float obj_CutPredictorIndex[471], const float obj_Children[942],
    const float obj_CutPoint[471], const boolean_T obj_NanCutPoints[471],
    const float obj_Prior[2], const float obj_Cost[4],
    const float obj_ClassProbability[942], const emxArray_real32_T *Xin,
    emxArray_real32_T *labels, emxArray_real32_T *scores);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
