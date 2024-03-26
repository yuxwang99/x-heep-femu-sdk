/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationModel.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

#ifndef COMPACTCLASSIFICATIONMODEL_H
#define COMPACTCLASSIFICATIONMODEL_H

/* Include Files */
#include "Yuxuan_iterative_test_single_internal_types.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void ab_CompactClassificationModel_C(ab_classreg_learning_classif_Co *obj);

void ab_CompactClassificationModel_s(h_classreg_learning_classif_Com *obj);

void ac_CompactClassificationModel_C(ac_classreg_learning_classif_Co *obj);

void ad_CompactClassificationModel_s(y_classreg_learning_classif_Com *obj);

void ae_CompactClassificationModel_s(hb_classreg_learning_classif_Co *obj);

void bb_CompactClassificationModel_C(bb_classreg_learning_classif_Co *obj);

void bc_CompactClassificationModel_C(bc_classreg_learning_classif_Co *obj);

void bc_CompactClassificationModel_s(q_classreg_learning_classif_Com *obj);

void bd_CompactClassificationModel_s(y_classreg_learning_classif_Com *obj);

void bf_CompactClassificationModel_s(qb_classreg_learning_classif_Co *obj);

void bg_CompactClassificationModel_s(yb_classreg_learning_classif_Co *obj);

void c_CompactClassificationModel_Co(c_classreg_learning_classif_Com *obj);

void c_CompactClassificationModel_ma(const float obj_Prior[2],
                                     const emxArray_real32_T *scores,
                                     emxArray_real32_T *labels);

void c_CompactClassificationModel_mi(const float obj_Prior[2],
                                     const float obj_Cost[4],
                                     const emxArray_real32_T *scoresIn,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *classnum,
                                     emxArray_real32_T *cost,
                                     emxArray_real32_T *scores);

void c_CompactClassificationModel_se(fc_classreg_learning_classif_Co *obj);

void cb_CompactClassificationModel_C(cb_classreg_learning_classif_Co *obj);

void cb_CompactClassificationModel_s(i_classreg_learning_classif_Com *obj);

void cc_CompactClassificationModel_C(cc_classreg_learning_classif_Co *obj);

void cc_CompactClassificationModel_s(q_classreg_learning_classif_Com *obj);

void ce_CompactClassificationModel_s(ib_classreg_learning_classif_Co *obj);

void cf_CompactClassificationModel_s(qb_classreg_learning_classif_Co *obj);

void cg_CompactClassificationModel_s(yb_classreg_learning_classif_Co *obj);

void d_CompactClassificationModel_Co(d_classreg_learning_classif_Com *obj);

void d_CompactClassificationModel_se(void);

void db_CompactClassificationModel_C(db_classreg_learning_classif_Co *obj);

void db_CompactClassificationModel_s(i_classreg_learning_classif_Com *obj);

void dc_CompactClassificationModel_C(dc_classreg_learning_classif_Co *obj);

void dd_CompactClassificationModel_s(ab_classreg_learning_classif_Co *obj);

void de_CompactClassificationModel_s(ib_classreg_learning_classif_Co *obj);

void dg_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj);

void e_CompactClassificationModel_Co(e_classreg_learning_classif_Com *obj);

void e_CompactClassificationModel_se(gc_classreg_learning_classif_Co *obj);

void eb_CompactClassificationModel_C(eb_classreg_learning_classif_Co *obj);

void ec_CompactClassificationModel_C(ec_classreg_learning_classif_Co *obj);

void ec_CompactClassificationModel_s(r_classreg_learning_classif_Com *obj);

void ed_CompactClassificationModel_s(ab_classreg_learning_classif_Co *obj);

void ef_CompactClassificationModel_s(rb_classreg_learning_classif_Co *obj);

void eg_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj);

void f_CompactClassificationModel_Co(f_classreg_learning_classif_Com *obj);

void f_CompactClassificationModel_se(void);

void fb_CompactClassificationModel_C(fb_classreg_learning_classif_Co *obj);

void fb_CompactClassificationModel_s(j_classreg_learning_classif_Com *obj);

void fc_CompactClassificationModel_s(r_classreg_learning_classif_Com *obj);

void fe_CompactClassificationModel_s(jb_classreg_learning_classif_Co *obj);

void ff_CompactClassificationModel_s(rb_classreg_learning_classif_Co *obj);

void g_CompactClassificationModel_Co(g_classreg_learning_classif_Com *obj);

void g_CompactClassificationModel_se(fc_classreg_learning_classif_Co *obj);

void gb_CompactClassificationModel_C(gb_classreg_learning_classif_Co *obj);

void gb_CompactClassificationModel_s(j_classreg_learning_classif_Com *obj);

void gd_CompactClassificationModel_s(bb_classreg_learning_classif_Co *obj);

void ge_CompactClassificationModel_s(jb_classreg_learning_classif_Co *obj);

void gg_CompactClassificationModel_s(ac_classreg_learning_classif_Co *obj);

void h_CompactClassificationModel_Co(h_classreg_learning_classif_Com *obj);

void h_CompactClassificationModel_se(void);

void hb_CompactClassificationModel_C(hb_classreg_learning_classif_Co *obj);

void hc_CompactClassificationModel_s(s_classreg_learning_classif_Com *obj);

void hd_CompactClassificationModel_s(bb_classreg_learning_classif_Co *obj);

void hf_CompactClassificationModel_s(sb_classreg_learning_classif_Co *obj);

void hg_CompactClassificationModel_s(ac_classreg_learning_classif_Co *obj);

void i_CompactClassificationModel_Co(i_classreg_learning_classif_Com *obj);

void ib_CompactClassificationModel_C(ib_classreg_learning_classif_Co *obj);

void ib_CompactClassificationModel_s(k_classreg_learning_classif_Com *obj);

void ic_CompactClassificationModel_s(s_classreg_learning_classif_Com *obj);

void ie_CompactClassificationModel_s(kb_classreg_learning_classif_Co *obj);

void if_CompactClassificationModel_s(sb_classreg_learning_classif_Co *obj);

void j_CompactClassificationModel_Co(j_classreg_learning_classif_Com *obj);

void j_CompactClassificationModel_se(c_classreg_learning_classif_Com *obj);

void jb_CompactClassificationModel_C(jb_classreg_learning_classif_Co *obj);

void jb_CompactClassificationModel_s(k_classreg_learning_classif_Com *obj);

void jd_CompactClassificationModel_s(cb_classreg_learning_classif_Co *obj);

void je_CompactClassificationModel_s(kb_classreg_learning_classif_Co *obj);

void jg_CompactClassificationModel_s(bc_classreg_learning_classif_Co *obj);

void k_CompactClassificationModel_Co(k_classreg_learning_classif_Com *obj);

void k_CompactClassificationModel_se(c_classreg_learning_classif_Com *obj);

void kb_CompactClassificationModel_C(kb_classreg_learning_classif_Co *obj);

void kc_CompactClassificationModel_s(t_classreg_learning_classif_Com *obj);

void kd_CompactClassificationModel_s(cb_classreg_learning_classif_Co *obj);

void kf_CompactClassificationModel_s(tb_classreg_learning_classif_Co *obj);

void kg_CompactClassificationModel_s(bc_classreg_learning_classif_Co *obj);

void l_CompactClassificationModel_Co(l_classreg_learning_classif_Com *obj);

void lb_CompactClassificationModel_C(lb_classreg_learning_classif_Co *obj);

void lb_CompactClassificationModel_s(l_classreg_learning_classif_Com *obj);

void lc_CompactClassificationModel_s(t_classreg_learning_classif_Com *obj);

void le_CompactClassificationModel_s(lb_classreg_learning_classif_Co *obj);

void lf_CompactClassificationModel_s(tb_classreg_learning_classif_Co *obj);

void lg_CompactClassificationModel_s(qb_classreg_learning_classif_Co *obj);

void m_CompactClassificationModel_Co(m_classreg_learning_classif_Com *obj);

void m_CompactClassificationModel_se(d_classreg_learning_classif_Com *obj);

void mb_CompactClassificationModel_C(mb_classreg_learning_classif_Co *obj);

void mb_CompactClassificationModel_s(l_classreg_learning_classif_Com *obj);

void md_CompactClassificationModel_s(db_classreg_learning_classif_Co *obj);

void me_CompactClassificationModel_s(lb_classreg_learning_classif_Co *obj);

void mg_CompactClassificationModel_s(nb_classreg_learning_classif_Co *obj);

void n_CompactClassificationModel_Co(n_classreg_learning_classif_Com *obj);

void n_CompactClassificationModel_se(d_classreg_learning_classif_Com *obj);

void nb_CompactClassificationModel_C(nb_classreg_learning_classif_Co *obj);

void nc_CompactClassificationModel_s(u_classreg_learning_classif_Com *obj);

void nd_CompactClassificationModel_s(db_classreg_learning_classif_Co *obj);

void nf_CompactClassificationModel_s(ub_classreg_learning_classif_Co *obj);

void ng_CompactClassificationModel_s(vb_classreg_learning_classif_Co *obj);

void o_CompactClassificationModel_Co(o_classreg_learning_classif_Com *obj);

void ob_CompactClassificationModel_C(ob_classreg_learning_classif_Co *obj);

void ob_CompactClassificationModel_s(m_classreg_learning_classif_Com *obj);

void oc_CompactClassificationModel_s(u_classreg_learning_classif_Com *obj);

void oe_CompactClassificationModel_s(mb_classreg_learning_classif_Co *obj);

void of_CompactClassificationModel_s(ub_classreg_learning_classif_Co *obj);

void p_CompactClassificationModel_Co(p_classreg_learning_classif_Com *obj);

void p_CompactClassificationModel_se(e_classreg_learning_classif_Com *obj);

void pb_CompactClassificationModel_C(pb_classreg_learning_classif_Co *obj);

void pb_CompactClassificationModel_s(m_classreg_learning_classif_Com *obj);

void pd_CompactClassificationModel_s(eb_classreg_learning_classif_Co *obj);

void pe_CompactClassificationModel_s(mb_classreg_learning_classif_Co *obj);

void pg_CompactClassificationModel_s(cc_classreg_learning_classif_Co *obj);

void q_CompactClassificationModel_Co(q_classreg_learning_classif_Com *obj);

void q_CompactClassificationModel_se(e_classreg_learning_classif_Com *obj);

void qb_CompactClassificationModel_C(qb_classreg_learning_classif_Co *obj);

void qc_CompactClassificationModel_s(v_classreg_learning_classif_Com *obj);

void qd_CompactClassificationModel_s(eb_classreg_learning_classif_Co *obj);

void qf_CompactClassificationModel_s(vb_classreg_learning_classif_Co *obj);

void qg_CompactClassificationModel_s(cc_classreg_learning_classif_Co *obj);

void r_CompactClassificationModel_Co(r_classreg_learning_classif_Com *obj);

void rb_CompactClassificationModel_C(rb_classreg_learning_classif_Co *obj);

void rb_CompactClassificationModel_s(n_classreg_learning_classif_Com *obj);

void rc_CompactClassificationModel_s(v_classreg_learning_classif_Com *obj);

void re_CompactClassificationModel_s(nb_classreg_learning_classif_Co *obj);

void rf_CompactClassificationModel_s(vb_classreg_learning_classif_Co *obj);

void rg_CompactClassificationModel_s(rb_classreg_learning_classif_Co *obj);

void s_CompactClassificationModel_Co(s_classreg_learning_classif_Com *obj);

void s_CompactClassificationModel_se(f_classreg_learning_classif_Com *obj);

void sb_CompactClassificationModel_C(sb_classreg_learning_classif_Co *obj);

void sb_CompactClassificationModel_s(n_classreg_learning_classif_Com *obj);

void sd_CompactClassificationModel_s(fb_classreg_learning_classif_Co *obj);

void se_CompactClassificationModel_s(nb_classreg_learning_classif_Co *obj);

void t_CompactClassificationModel_Co(t_classreg_learning_classif_Com *obj);

void t_CompactClassificationModel_se(f_classreg_learning_classif_Com *obj);

void tb_CompactClassificationModel_C(tb_classreg_learning_classif_Co *obj);

void tc_CompactClassificationModel_s(w_classreg_learning_classif_Com *obj);

void td_CompactClassificationModel_s(fb_classreg_learning_classif_Co *obj);

void tf_CompactClassificationModel_s(wb_classreg_learning_classif_Co *obj);

void tg_CompactClassificationModel_s(dc_classreg_learning_classif_Co *obj);

void u_CompactClassificationModel_Co(u_classreg_learning_classif_Com *obj);

void ub_CompactClassificationModel_C(ub_classreg_learning_classif_Co *obj);

void ub_CompactClassificationModel_s(o_classreg_learning_classif_Com *obj);

void uc_CompactClassificationModel_s(w_classreg_learning_classif_Com *obj);

void ue_CompactClassificationModel_s(ob_classreg_learning_classif_Co *obj);

void uf_CompactClassificationModel_s(wb_classreg_learning_classif_Co *obj);

void ug_CompactClassificationModel_s(dc_classreg_learning_classif_Co *obj);

void v_CompactClassificationModel_Co(v_classreg_learning_classif_Com *obj);

void v_CompactClassificationModel_se(g_classreg_learning_classif_Com *obj);

void vb_CompactClassificationModel_C(vb_classreg_learning_classif_Co *obj);

void vb_CompactClassificationModel_s(o_classreg_learning_classif_Com *obj);

void vd_CompactClassificationModel_s(gb_classreg_learning_classif_Co *obj);

void ve_CompactClassificationModel_s(ob_classreg_learning_classif_Co *obj);

void vf_CompactClassificationModel_s(ub_classreg_learning_classif_Co *obj);

void w_CompactClassificationModel_Co(w_classreg_learning_classif_Com *obj);

void w_CompactClassificationModel_se(g_classreg_learning_classif_Com *obj);

void wb_CompactClassificationModel_C(wb_classreg_learning_classif_Co *obj);

void wc_CompactClassificationModel_s(x_classreg_learning_classif_Com *obj);

void wd_CompactClassificationModel_s(gb_classreg_learning_classif_Co *obj);

void wg_CompactClassificationModel_s(ec_classreg_learning_classif_Co *obj);

void x_CompactClassificationModel_Co(x_classreg_learning_classif_Com *obj);

void xb_CompactClassificationModel_C(xb_classreg_learning_classif_Co *obj);

void xb_CompactClassificationModel_s(p_classreg_learning_classif_Com *obj);

void xc_CompactClassificationModel_s(x_classreg_learning_classif_Com *obj);

void xe_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj);

void xf_CompactClassificationModel_s(xb_classreg_learning_classif_Co *obj);

void xg_CompactClassificationModel_s(ec_classreg_learning_classif_Co *obj);

void y_CompactClassificationModel_Co(y_classreg_learning_classif_Com *obj);

void y_CompactClassificationModel_se(h_classreg_learning_classif_Com *obj);

void yb_CompactClassificationModel_C(yb_classreg_learning_classif_Co *obj);

void yb_CompactClassificationModel_s(p_classreg_learning_classif_Com *obj);

void yd_CompactClassificationModel_s(hb_classreg_learning_classif_Co *obj);

void ye_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj);

void yf_CompactClassificationModel_s(xb_classreg_learning_classif_Co *obj);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CompactClassificationModel.h
 *
 * [EOF]
 */
