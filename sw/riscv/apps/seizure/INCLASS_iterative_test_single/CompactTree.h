/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactTree.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

#ifndef COMPACTTREE_H
#define COMPACTTREE_H

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
void CompactTree_CompactTree(c_classreg_learning_classif_Com *obj);

void CompactTree_findNode(const float obj_CutPredictorIndex[1581],
                          const float obj_Children[3162],
                          const float obj_CutPoint[1581],
                          const boolean_T obj_NanCutPoints[1581],
                          const emxArray_real32_T *X, emxArray_real_T *n);

void ab_CompactTree_CompactTree(cb_classreg_learning_classif_Co *obj);

void ab_CompactTree_findNode(const float obj_CutPredictorIndex[829],
                             const float obj_Children[1658],
                             const float obj_CutPoint[829],
                             const boolean_T obj_NanCutPoints[829],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void ac_CompactTree_CompactTree(pb_classreg_learning_classif_Co *obj);

void ac_CompactTree_findNode(const float obj_CutPredictorIndex[593],
                             const float obj_Children[1186],
                             const float obj_CutPoint[593],
                             const boolean_T obj_NanCutPoints[593],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void b_CompactTree_CompactTree(d_classreg_learning_classif_Com *obj);

void b_CompactTree_findNode(const float obj_CutPredictorIndex[1419],
                            const float obj_Children[2838],
                            const float obj_CutPoint[1419],
                            const boolean_T obj_NanCutPoints[1419],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void bb_CompactTree_CompactTree(db_classreg_learning_classif_Co *obj);

void bb_CompactTree_findNode(const float obj_CutPredictorIndex[651],
                             const float obj_Children[1302],
                             const float obj_CutPoint[651],
                             const boolean_T obj_NanCutPoints[651],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void bc_CompactTree_CompactTree(ac_classreg_learning_classif_Co *obj);

void bc_CompactTree_findNode(const float obj_CutPredictorIndex[463],
                             const float obj_Children[926],
                             const float obj_CutPoint[463],
                             const boolean_T obj_NanCutPoints[463],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void c_CompactTree_CompactTree(e_classreg_learning_classif_Com *obj);

void c_CompactTree_findNode(const float obj_CutPredictorIndex[1433],
                            const float obj_Children[2866],
                            const float obj_CutPoint[1433],
                            const boolean_T obj_NanCutPoints[1433],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void cb_CompactTree_CompactTree(eb_classreg_learning_classif_Co *obj);

void cb_CompactTree_findNode(const float obj_CutPredictorIndex[551],
                             const float obj_Children[1102],
                             const float obj_CutPoint[551],
                             const boolean_T obj_NanCutPoints[551],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void cc_CompactTree_CompactTree(bc_classreg_learning_classif_Co *obj);

void cc_CompactTree_findNode(const float obj_CutPredictorIndex[581],
                             const float obj_Children[1162],
                             const float obj_CutPoint[581],
                             const boolean_T obj_NanCutPoints[581],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void d_CompactTree_CompactTree(f_classreg_learning_classif_Com *obj);

void d_CompactTree_findNode(const float obj_CutPredictorIndex[1495],
                            const float obj_Children[2990],
                            const float obj_CutPoint[1495],
                            const boolean_T obj_NanCutPoints[1495],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void db_CompactTree_CompactTree(fb_classreg_learning_classif_Co *obj);

void db_CompactTree_findNode(const float obj_CutPredictorIndex[667],
                             const float obj_Children[1334],
                             const float obj_CutPoint[667],
                             const boolean_T obj_NanCutPoints[667],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void dc_CompactTree_CompactTree(qb_classreg_learning_classif_Co *obj);

void e_CompactTree_CompactTree(g_classreg_learning_classif_Com *obj);

void e_CompactTree_findNode(const float obj_CutPredictorIndex[1553],
                            const float obj_Children[3106],
                            const float obj_CutPoint[1553],
                            const boolean_T obj_NanCutPoints[1553],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void eb_CompactTree_CompactTree(gb_classreg_learning_classif_Co *obj);

void eb_CompactTree_findNode(const float obj_CutPredictorIndex[607],
                             const float obj_Children[1214],
                             const float obj_CutPoint[607],
                             const boolean_T obj_NanCutPoints[607],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void ec_CompactTree_CompactTree(nb_classreg_learning_classif_Co *obj);

void f_CompactTree_CompactTree(h_classreg_learning_classif_Com *obj);

void f_CompactTree_findNode(const float obj_CutPredictorIndex[1383],
                            const float obj_Children[2766],
                            const float obj_CutPoint[1383],
                            const boolean_T obj_NanCutPoints[1383],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void fb_CompactTree_CompactTree(hb_classreg_learning_classif_Co *obj);

void fb_CompactTree_findNode(const float obj_CutPredictorIndex[623],
                             const float obj_Children[1246],
                             const float obj_CutPoint[623],
                             const boolean_T obj_NanCutPoints[623],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void fc_CompactTree_CompactTree(vb_classreg_learning_classif_Co *obj);

void g_CompactTree_CompactTree(i_classreg_learning_classif_Com *obj);

void g_CompactTree_findNode(const float obj_CutPredictorIndex[1323],
                            const float obj_Children[2646],
                            const float obj_CutPoint[1323],
                            const boolean_T obj_NanCutPoints[1323],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void gb_CompactTree_CompactTree(ib_classreg_learning_classif_Co *obj);

void gb_CompactTree_findNode(const float obj_CutPredictorIndex[539],
                             const float obj_Children[1078],
                             const float obj_CutPoint[539],
                             const boolean_T obj_NanCutPoints[539],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void gc_CompactTree_CompactTree(cc_classreg_learning_classif_Co *obj);

void h_CompactTree_CompactTree(j_classreg_learning_classif_Com *obj);

void h_CompactTree_findNode(const float obj_CutPredictorIndex[1363],
                            const float obj_Children[2726],
                            const float obj_CutPoint[1363],
                            const boolean_T obj_NanCutPoints[1363],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void hb_CompactTree_CompactTree(jb_classreg_learning_classif_Co *obj);

void hb_CompactTree_findNode(const float obj_CutPredictorIndex[521],
                             const float obj_Children[1042],
                             const float obj_CutPoint[521],
                             const boolean_T obj_NanCutPoints[521],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void hc_CompactTree_CompactTree(rb_classreg_learning_classif_Co *obj);

void i_CompactTree_CompactTree(k_classreg_learning_classif_Com *obj);

void i_CompactTree_findNode(const float obj_CutPredictorIndex[1265],
                            const float obj_Children[2530],
                            const float obj_CutPoint[1265],
                            const boolean_T obj_NanCutPoints[1265],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void ib_CompactTree_CompactTree(kb_classreg_learning_classif_Co *obj);

void ib_CompactTree_findNode(const float obj_CutPredictorIndex[527],
                             const float obj_Children[1054],
                             const float obj_CutPoint[527],
                             const boolean_T obj_NanCutPoints[527],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void ic_CompactTree_CompactTree(dc_classreg_learning_classif_Co *obj);

void j_CompactTree_CompactTree(l_classreg_learning_classif_Com *obj);

void j_CompactTree_findNode(const float obj_CutPredictorIndex[1349],
                            const float obj_Children[2698],
                            const float obj_CutPoint[1349],
                            const boolean_T obj_NanCutPoints[1349],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void jb_CompactTree_CompactTree(lb_classreg_learning_classif_Co *obj);

void jb_CompactTree_findNode(const float obj_CutPredictorIndex[543],
                             const float obj_Children[1086],
                             const float obj_CutPoint[543],
                             const boolean_T obj_NanCutPoints[543],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void jc_CompactTree_CompactTree(ec_classreg_learning_classif_Co *obj);

void k_CompactTree_CompactTree(m_classreg_learning_classif_Com *obj);

void k_CompactTree_findNode(const float obj_CutPredictorIndex[1279],
                            const float obj_Children[2558],
                            const float obj_CutPoint[1279],
                            const boolean_T obj_NanCutPoints[1279],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void kb_CompactTree_CompactTree(mb_classreg_learning_classif_Co *obj);

void kb_CompactTree_findNode(const float obj_CutPredictorIndex[467],
                             const float obj_Children[934],
                             const float obj_CutPoint[467],
                             const boolean_T obj_NanCutPoints[467],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void l_CompactTree_CompactTree(n_classreg_learning_classif_Com *obj);

void l_CompactTree_findNode(const float obj_CutPredictorIndex[1611],
                            const float obj_Children[3222],
                            const float obj_CutPoint[1611],
                            const boolean_T obj_NanCutPoints[1611],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void lb_CompactTree_CompactTree(nb_classreg_learning_classif_Co *obj);

void lb_CompactTree_findNode(const float obj_CutPredictorIndex[611],
                             const float obj_Children[1222],
                             const float obj_CutPoint[611],
                             const boolean_T obj_NanCutPoints[611],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void m_CompactTree_CompactTree(o_classreg_learning_classif_Com *obj);

void m_CompactTree_findNode(const float obj_CutPredictorIndex[1437],
                            const float obj_Children[2874],
                            const float obj_CutPoint[1437],
                            const boolean_T obj_NanCutPoints[1437],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void mb_CompactTree_CompactTree(ob_classreg_learning_classif_Co *obj);

void mb_CompactTree_findNode(const float obj_CutPredictorIndex[457],
                             const float obj_Children[914],
                             const float obj_CutPoint[457],
                             const boolean_T obj_NanCutPoints[457],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void n_CompactTree_CompactTree(p_classreg_learning_classif_Com *obj);

void n_CompactTree_findNode(const float obj_CutPredictorIndex[1369],
                            const float obj_Children[2738],
                            const float obj_CutPoint[1369],
                            const boolean_T obj_NanCutPoints[1369],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void nb_CompactTree_CompactTree(pb_classreg_learning_classif_Co *obj);

void nb_CompactTree_findNode(const float obj_CutPredictorIndex[451],
                             const float obj_Children[902],
                             const float obj_CutPoint[451],
                             const boolean_T obj_NanCutPoints[451],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void o_CompactTree_CompactTree(q_classreg_learning_classif_Com *obj);

void o_CompactTree_findNode(const float obj_CutPredictorIndex[1367],
                            const float obj_Children[2734],
                            const float obj_CutPoint[1367],
                            const boolean_T obj_NanCutPoints[1367],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void ob_CompactTree_CompactTree(qb_classreg_learning_classif_Co *obj);

void ob_CompactTree_findNode(const float obj_CutPredictorIndex[425],
                             const float obj_Children[850],
                             const float obj_CutPoint[425],
                             const boolean_T obj_NanCutPoints[425],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void p_CompactTree_CompactTree(r_classreg_learning_classif_Com *obj);

void p_CompactTree_findNode(const float obj_CutPredictorIndex[1479],
                            const float obj_Children[2958],
                            const float obj_CutPoint[1479],
                            const boolean_T obj_NanCutPoints[1479],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void pb_CompactTree_CompactTree(rb_classreg_learning_classif_Co *obj);

void pb_CompactTree_findNode(const float obj_CutPredictorIndex[343],
                             const float obj_Children[686],
                             const float obj_CutPoint[343],
                             const boolean_T obj_NanCutPoints[343],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void q_CompactTree_CompactTree(s_classreg_learning_classif_Com *obj);

void q_CompactTree_findNode(const float obj_CutPredictorIndex[1469],
                            const float obj_Children[2938],
                            const float obj_CutPoint[1469],
                            const boolean_T obj_NanCutPoints[1469],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void qb_CompactTree_CompactTree(sb_classreg_learning_classif_Co *obj);

void qb_CompactTree_findNode(const float obj_CutPredictorIndex[537],
                             const float obj_Children[1074],
                             const float obj_CutPoint[537],
                             const boolean_T obj_NanCutPoints[537],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void r_CompactTree_CompactTree(t_classreg_learning_classif_Com *obj);

void r_CompactTree_findNode(const float obj_CutPredictorIndex[1663],
                            const float obj_Children[3326],
                            const float obj_CutPoint[1663],
                            const boolean_T obj_NanCutPoints[1663],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void rb_CompactTree_CompactTree(tb_classreg_learning_classif_Co *obj);

void rb_CompactTree_findNode(const float obj_CutPredictorIndex[529],
                             const float obj_Children[1058],
                             const float obj_CutPoint[529],
                             const boolean_T obj_NanCutPoints[529],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void s_CompactTree_CompactTree(u_classreg_learning_classif_Com *obj);

void s_CompactTree_findNode(const float obj_CutPredictorIndex[1411],
                            const float obj_Children[2822],
                            const float obj_CutPoint[1411],
                            const boolean_T obj_NanCutPoints[1411],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void sb_CompactTree_CompactTree(ub_classreg_learning_classif_Co *obj);

void sb_CompactTree_findNode(const float obj_CutPredictorIndex[427],
                             const float obj_Children[854],
                             const float obj_CutPoint[427],
                             const boolean_T obj_NanCutPoints[427],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void t_CompactTree_CompactTree(v_classreg_learning_classif_Com *obj);

void t_CompactTree_findNode(const float obj_CutPredictorIndex[1317],
                            const float obj_Children[2634],
                            const float obj_CutPoint[1317],
                            const boolean_T obj_NanCutPoints[1317],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void tb_CompactTree_CompactTree(vb_classreg_learning_classif_Co *obj);

void tb_CompactTree_findNode(const float obj_CutPredictorIndex[447],
                             const float obj_Children[894],
                             const float obj_CutPoint[447],
                             const boolean_T obj_NanCutPoints[447],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void u_CompactTree_CompactTree(w_classreg_learning_classif_Com *obj);

void u_CompactTree_findNode(const float obj_CutPredictorIndex[709],
                            const float obj_Children[1418],
                            const float obj_CutPoint[709],
                            const boolean_T obj_NanCutPoints[709],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void ub_CompactTree_CompactTree(wb_classreg_learning_classif_Co *obj);

void ub_CompactTree_findNode(const float obj_CutPredictorIndex[563],
                             const float obj_Children[1126],
                             const float obj_CutPoint[563],
                             const boolean_T obj_NanCutPoints[563],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void v_CompactTree_CompactTree(x_classreg_learning_classif_Com *obj);

void v_CompactTree_findNode(const float obj_CutPredictorIndex[783],
                            const float obj_Children[1566],
                            const float obj_CutPoint[783],
                            const boolean_T obj_NanCutPoints[783],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void vb_CompactTree_CompactTree(ub_classreg_learning_classif_Co *obj);

void vb_CompactTree_findNode(const float obj_CutPredictorIndex[469],
                             const float obj_Children[938],
                             const float obj_CutPoint[469],
                             const boolean_T obj_NanCutPoints[469],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void w_CompactTree_CompactTree(y_classreg_learning_classif_Com *obj);

void w_CompactTree_findNode(const float obj_CutPredictorIndex[649],
                            const float obj_Children[1298],
                            const float obj_CutPoint[649],
                            const boolean_T obj_NanCutPoints[649],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void wb_CompactTree_CompactTree(xb_classreg_learning_classif_Co *obj);

void wb_CompactTree_findNode(const float obj_CutPredictorIndex[471],
                             const float obj_Children[942],
                             const float obj_CutPoint[471],
                             const boolean_T obj_NanCutPoints[471],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void x_CompactTree_CompactTree(ab_classreg_learning_classif_Co *obj);

void x_CompactTree_findNode(const float obj_CutPredictorIndex[765],
                            const float obj_Children[1530],
                            const float obj_CutPoint[765],
                            const boolean_T obj_NanCutPoints[765],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void xb_CompactTree_CompactTree(yb_classreg_learning_classif_Co *obj);

void xb_CompactTree_findNode(const float obj_CutPredictorIndex[555],
                             const float obj_Children[1110],
                             const float obj_CutPoint[555],
                             const boolean_T obj_NanCutPoints[555],
                             const emxArray_real32_T *X, emxArray_real_T *n);

void y_CompactTree_CompactTree(bb_classreg_learning_classif_Co *obj);

void y_CompactTree_findNode(const float obj_CutPredictorIndex[699],
                            const float obj_Children[1398],
                            const float obj_CutPoint[699],
                            const boolean_T obj_NanCutPoints[699],
                            const emxArray_real32_T *X, emxArray_real_T *n);

void yb_CompactTree_CompactTree(pb_classreg_learning_classif_Co *obj);

void yb_CompactTree_findNode(const float obj_CutPredictorIndex[423],
                             const float obj_Children[846],
                             const float obj_CutPoint[423],
                             const boolean_T obj_NanCutPoints[423],
                             const emxArray_real32_T *X, emxArray_real_T *n);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CompactTree.h
 *
 * [EOF]
 */
