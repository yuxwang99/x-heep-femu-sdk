/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * profile_Yuxuan_iteration.c
 *
 * Code generation for function 'profile_Yuxuan_iteration'
 *
 */

/* Include files */
#include "profile_Yuxuan_iteration.h"
#include "CompactClassificationEnsemble.h"
#include "Yuxuan_iterative_test.h"
#include "profile_Yuxuan_iteration_data.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_initialize.h"
#include "profile_Yuxuan_iteration_internal_types.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void profile_Yuxuan_iteration(const double ECG_Seiz_Window[2764800], const
  double Spo2_Seiz_Window[2764800], const double ECG_Gray_Window[2764800], const
  double Spo2_Gray_Window[2764800], const double norm_coef1[2], const double
  norm_coef2[3], const double norm_coef3[5], const double norm_coef4[13], const
  double norm_coef5[17], double wind_len, const double masks[85], double
  profile_times, const cell_0 *File_info, double Fs, double Nbr_RR, double
  conf_seiz, const boolean_T select_ind[90], double pred_label_data[], int
  pred_label_size[2], double true_label_data[], int true_label_size[2])
{
  static double varargin_1_data[895];
  c_classreg_learning_classif_Com ab_expl_temp;
  c_classreg_learning_classif_Com ac_expl_temp;
  c_classreg_learning_classif_Com ad_expl_temp;
  c_classreg_learning_classif_Com ae_expl_temp;
  c_classreg_learning_classif_Com af_expl_temp;
  c_classreg_learning_classif_Com ag_expl_temp;
  c_classreg_learning_classif_Com ah_expl_temp;
  c_classreg_learning_classif_Com ai_expl_temp;
  c_classreg_learning_classif_Com aj_expl_temp;
  c_classreg_learning_classif_Com ak_expl_temp;
  c_classreg_learning_classif_Com al_expl_temp;
  c_classreg_learning_classif_Com am_expl_temp;
  c_classreg_learning_classif_Com an_expl_temp;
  c_classreg_learning_classif_Com ao_expl_temp;
  c_classreg_learning_classif_Com ap_expl_temp;
  c_classreg_learning_classif_Com aq_expl_temp;
  c_classreg_learning_classif_Com ar_expl_temp;
  c_classreg_learning_classif_Com as_expl_temp;
  c_classreg_learning_classif_Com at_expl_temp;
  c_classreg_learning_classif_Com au_expl_temp;
  c_classreg_learning_classif_Com av_expl_temp;
  c_classreg_learning_classif_Com bb_expl_temp;
  c_classreg_learning_classif_Com bc_expl_temp;
  c_classreg_learning_classif_Com bd_expl_temp;
  c_classreg_learning_classif_Com be_expl_temp;
  c_classreg_learning_classif_Com bf_expl_temp;
  c_classreg_learning_classif_Com bg_expl_temp;
  c_classreg_learning_classif_Com bh_expl_temp;
  c_classreg_learning_classif_Com bi_expl_temp;
  c_classreg_learning_classif_Com bj_expl_temp;
  c_classreg_learning_classif_Com bk_expl_temp;
  c_classreg_learning_classif_Com bl_expl_temp;
  c_classreg_learning_classif_Com bm_expl_temp;
  c_classreg_learning_classif_Com bn_expl_temp;
  c_classreg_learning_classif_Com bo_expl_temp;
  c_classreg_learning_classif_Com bp_expl_temp;
  c_classreg_learning_classif_Com bq_expl_temp;
  c_classreg_learning_classif_Com br_expl_temp;
  c_classreg_learning_classif_Com bs_expl_temp;
  c_classreg_learning_classif_Com bt_expl_temp;
  c_classreg_learning_classif_Com bu_expl_temp;
  c_classreg_learning_classif_Com bv_expl_temp;
  c_classreg_learning_classif_Com c_expl_temp;
  c_classreg_learning_classif_Com cb_expl_temp;
  c_classreg_learning_classif_Com cc_expl_temp;
  c_classreg_learning_classif_Com cd_expl_temp;
  c_classreg_learning_classif_Com ce_expl_temp;
  c_classreg_learning_classif_Com cf_expl_temp;
  c_classreg_learning_classif_Com cg_expl_temp;
  c_classreg_learning_classif_Com ch_expl_temp;
  c_classreg_learning_classif_Com ci_expl_temp;
  c_classreg_learning_classif_Com cj_expl_temp;
  c_classreg_learning_classif_Com ck_expl_temp;
  c_classreg_learning_classif_Com cl_expl_temp;
  c_classreg_learning_classif_Com cm_expl_temp;
  c_classreg_learning_classif_Com cn_expl_temp;
  c_classreg_learning_classif_Com co_expl_temp;
  c_classreg_learning_classif_Com cp_expl_temp;
  c_classreg_learning_classif_Com cq_expl_temp;
  c_classreg_learning_classif_Com cr_expl_temp;
  c_classreg_learning_classif_Com cs_expl_temp;
  c_classreg_learning_classif_Com ct_expl_temp;
  c_classreg_learning_classif_Com cu_expl_temp;
  c_classreg_learning_classif_Com cv_expl_temp;
  c_classreg_learning_classif_Com d_expl_temp;
  c_classreg_learning_classif_Com db_expl_temp;
  c_classreg_learning_classif_Com dc_expl_temp;
  c_classreg_learning_classif_Com dd_expl_temp;
  c_classreg_learning_classif_Com de_expl_temp;
  c_classreg_learning_classif_Com df_expl_temp;
  c_classreg_learning_classif_Com dg_expl_temp;
  c_classreg_learning_classif_Com dh_expl_temp;
  c_classreg_learning_classif_Com di_expl_temp;
  c_classreg_learning_classif_Com dj_expl_temp;
  c_classreg_learning_classif_Com dk_expl_temp;
  c_classreg_learning_classif_Com dl_expl_temp;
  c_classreg_learning_classif_Com dm_expl_temp;
  c_classreg_learning_classif_Com dn_expl_temp;
  c_classreg_learning_classif_Com do_expl_temp;
  c_classreg_learning_classif_Com dp_expl_temp;
  c_classreg_learning_classif_Com dq_expl_temp;
  c_classreg_learning_classif_Com dr_expl_temp;
  c_classreg_learning_classif_Com ds_expl_temp;
  c_classreg_learning_classif_Com dt_expl_temp;
  c_classreg_learning_classif_Com du_expl_temp;
  c_classreg_learning_classif_Com dv_expl_temp;
  c_classreg_learning_classif_Com e_expl_temp;
  c_classreg_learning_classif_Com eb_expl_temp;
  c_classreg_learning_classif_Com ec_expl_temp;
  c_classreg_learning_classif_Com ed_expl_temp;
  c_classreg_learning_classif_Com ee_expl_temp;
  c_classreg_learning_classif_Com ef_expl_temp;
  c_classreg_learning_classif_Com eg_expl_temp;
  c_classreg_learning_classif_Com eh_expl_temp;
  c_classreg_learning_classif_Com ei_expl_temp;
  c_classreg_learning_classif_Com ej_expl_temp;
  c_classreg_learning_classif_Com ek_expl_temp;
  c_classreg_learning_classif_Com el_expl_temp;
  c_classreg_learning_classif_Com em_expl_temp;
  c_classreg_learning_classif_Com en_expl_temp;
  c_classreg_learning_classif_Com eo_expl_temp;
  c_classreg_learning_classif_Com ep_expl_temp;
  c_classreg_learning_classif_Com eq_expl_temp;
  c_classreg_learning_classif_Com er_expl_temp;
  c_classreg_learning_classif_Com es_expl_temp;
  c_classreg_learning_classif_Com et_expl_temp;
  c_classreg_learning_classif_Com eu_expl_temp;
  c_classreg_learning_classif_Com ev_expl_temp;
  c_classreg_learning_classif_Com f_expl_temp;
  c_classreg_learning_classif_Com fb_expl_temp;
  c_classreg_learning_classif_Com fc_expl_temp;
  c_classreg_learning_classif_Com fd_expl_temp;
  c_classreg_learning_classif_Com fe_expl_temp;
  c_classreg_learning_classif_Com ff_expl_temp;
  c_classreg_learning_classif_Com fg_expl_temp;
  c_classreg_learning_classif_Com fh_expl_temp;
  c_classreg_learning_classif_Com fi_expl_temp;
  c_classreg_learning_classif_Com fj_expl_temp;
  c_classreg_learning_classif_Com fk_expl_temp;
  c_classreg_learning_classif_Com fl_expl_temp;
  c_classreg_learning_classif_Com fm_expl_temp;
  c_classreg_learning_classif_Com fn_expl_temp;
  c_classreg_learning_classif_Com fo_expl_temp;
  c_classreg_learning_classif_Com fp_expl_temp;
  c_classreg_learning_classif_Com fq_expl_temp;
  c_classreg_learning_classif_Com fr_expl_temp;
  c_classreg_learning_classif_Com fs_expl_temp;
  c_classreg_learning_classif_Com ft_expl_temp;
  c_classreg_learning_classif_Com fu_expl_temp;
  c_classreg_learning_classif_Com fv_expl_temp;
  c_classreg_learning_classif_Com g_expl_temp;
  c_classreg_learning_classif_Com gb_expl_temp;
  c_classreg_learning_classif_Com gc_expl_temp;
  c_classreg_learning_classif_Com gd_expl_temp;
  c_classreg_learning_classif_Com ge_expl_temp;
  c_classreg_learning_classif_Com gf_expl_temp;
  c_classreg_learning_classif_Com gg_expl_temp;
  c_classreg_learning_classif_Com gh_expl_temp;
  c_classreg_learning_classif_Com gi_expl_temp;
  c_classreg_learning_classif_Com gj_expl_temp;
  c_classreg_learning_classif_Com gk_expl_temp;
  c_classreg_learning_classif_Com gl_expl_temp;
  c_classreg_learning_classif_Com gm_expl_temp;
  c_classreg_learning_classif_Com gn_expl_temp;
  c_classreg_learning_classif_Com go_expl_temp;
  c_classreg_learning_classif_Com gp_expl_temp;
  c_classreg_learning_classif_Com gq_expl_temp;
  c_classreg_learning_classif_Com gr_expl_temp;
  c_classreg_learning_classif_Com gs_expl_temp;
  c_classreg_learning_classif_Com gt_expl_temp;
  c_classreg_learning_classif_Com gu_expl_temp;
  c_classreg_learning_classif_Com gv_expl_temp;
  c_classreg_learning_classif_Com h_expl_temp;
  c_classreg_learning_classif_Com hb_expl_temp;
  c_classreg_learning_classif_Com hc_expl_temp;
  c_classreg_learning_classif_Com hd_expl_temp;
  c_classreg_learning_classif_Com he_expl_temp;
  c_classreg_learning_classif_Com hf_expl_temp;
  c_classreg_learning_classif_Com hg_expl_temp;
  c_classreg_learning_classif_Com hh_expl_temp;
  c_classreg_learning_classif_Com hi_expl_temp;
  c_classreg_learning_classif_Com hj_expl_temp;
  c_classreg_learning_classif_Com hk_expl_temp;
  c_classreg_learning_classif_Com hl_expl_temp;
  c_classreg_learning_classif_Com hm_expl_temp;
  c_classreg_learning_classif_Com hn_expl_temp;
  c_classreg_learning_classif_Com ho_expl_temp;
  c_classreg_learning_classif_Com hp_expl_temp;
  c_classreg_learning_classif_Com hq_expl_temp;
  c_classreg_learning_classif_Com hr_expl_temp;
  c_classreg_learning_classif_Com hs_expl_temp;
  c_classreg_learning_classif_Com ht_expl_temp;
  c_classreg_learning_classif_Com hu_expl_temp;
  c_classreg_learning_classif_Com hv_expl_temp;
  c_classreg_learning_classif_Com i_expl_temp;
  c_classreg_learning_classif_Com ib_expl_temp;
  c_classreg_learning_classif_Com ic_expl_temp;
  c_classreg_learning_classif_Com id_expl_temp;
  c_classreg_learning_classif_Com ie_expl_temp;
  c_classreg_learning_classif_Com if_expl_temp;
  c_classreg_learning_classif_Com ig_expl_temp;
  c_classreg_learning_classif_Com ih_expl_temp;
  c_classreg_learning_classif_Com ii_expl_temp;
  c_classreg_learning_classif_Com ij_expl_temp;
  c_classreg_learning_classif_Com ik_expl_temp;
  c_classreg_learning_classif_Com il_expl_temp;
  c_classreg_learning_classif_Com im_expl_temp;
  c_classreg_learning_classif_Com in_expl_temp;
  c_classreg_learning_classif_Com io_expl_temp;
  c_classreg_learning_classif_Com ip_expl_temp;
  c_classreg_learning_classif_Com iq_expl_temp;
  c_classreg_learning_classif_Com ir_expl_temp;
  c_classreg_learning_classif_Com is_expl_temp;
  c_classreg_learning_classif_Com it_expl_temp;
  c_classreg_learning_classif_Com iu_expl_temp;
  c_classreg_learning_classif_Com iv_expl_temp;
  c_classreg_learning_classif_Com j_expl_temp;
  c_classreg_learning_classif_Com jb_expl_temp;
  c_classreg_learning_classif_Com jc_expl_temp;
  c_classreg_learning_classif_Com jd_expl_temp;
  c_classreg_learning_classif_Com je_expl_temp;
  c_classreg_learning_classif_Com jf_expl_temp;
  c_classreg_learning_classif_Com jg_expl_temp;
  c_classreg_learning_classif_Com jh_expl_temp;
  c_classreg_learning_classif_Com ji_expl_temp;
  c_classreg_learning_classif_Com jj_expl_temp;
  c_classreg_learning_classif_Com jk_expl_temp;
  c_classreg_learning_classif_Com jl_expl_temp;
  c_classreg_learning_classif_Com jm_expl_temp;
  c_classreg_learning_classif_Com jn_expl_temp;
  c_classreg_learning_classif_Com jo_expl_temp;
  c_classreg_learning_classif_Com jp_expl_temp;
  c_classreg_learning_classif_Com jq_expl_temp;
  c_classreg_learning_classif_Com jr_expl_temp;
  c_classreg_learning_classif_Com js_expl_temp;
  c_classreg_learning_classif_Com jt_expl_temp;
  c_classreg_learning_classif_Com ju_expl_temp;
  c_classreg_learning_classif_Com jv_expl_temp;
  c_classreg_learning_classif_Com k_expl_temp;
  c_classreg_learning_classif_Com kb_expl_temp;
  c_classreg_learning_classif_Com kc_expl_temp;
  c_classreg_learning_classif_Com kd_expl_temp;
  c_classreg_learning_classif_Com ke_expl_temp;
  c_classreg_learning_classif_Com kf_expl_temp;
  c_classreg_learning_classif_Com kg_expl_temp;
  c_classreg_learning_classif_Com kh_expl_temp;
  c_classreg_learning_classif_Com ki_expl_temp;
  c_classreg_learning_classif_Com kj_expl_temp;
  c_classreg_learning_classif_Com kk_expl_temp;
  c_classreg_learning_classif_Com kl_expl_temp;
  c_classreg_learning_classif_Com km_expl_temp;
  c_classreg_learning_classif_Com kn_expl_temp;
  c_classreg_learning_classif_Com ko_expl_temp;
  c_classreg_learning_classif_Com kp_expl_temp;
  c_classreg_learning_classif_Com kq_expl_temp;
  c_classreg_learning_classif_Com kr_expl_temp;
  c_classreg_learning_classif_Com ks_expl_temp;
  c_classreg_learning_classif_Com kt_expl_temp;
  c_classreg_learning_classif_Com ku_expl_temp;
  c_classreg_learning_classif_Com kv_expl_temp;
  c_classreg_learning_classif_Com l_expl_temp;
  c_classreg_learning_classif_Com lb_expl_temp;
  c_classreg_learning_classif_Com lc_expl_temp;
  c_classreg_learning_classif_Com ld_expl_temp;
  c_classreg_learning_classif_Com le_expl_temp;
  c_classreg_learning_classif_Com lf_expl_temp;
  c_classreg_learning_classif_Com lg_expl_temp;
  c_classreg_learning_classif_Com lh_expl_temp;
  c_classreg_learning_classif_Com li_expl_temp;
  c_classreg_learning_classif_Com lj_expl_temp;
  c_classreg_learning_classif_Com lk_expl_temp;
  c_classreg_learning_classif_Com ll_expl_temp;
  c_classreg_learning_classif_Com lm_expl_temp;
  c_classreg_learning_classif_Com ln_expl_temp;
  c_classreg_learning_classif_Com lo_expl_temp;
  c_classreg_learning_classif_Com lp_expl_temp;
  c_classreg_learning_classif_Com lq_expl_temp;
  c_classreg_learning_classif_Com lr_expl_temp;
  c_classreg_learning_classif_Com ls_expl_temp;
  c_classreg_learning_classif_Com lt_expl_temp;
  c_classreg_learning_classif_Com lu_expl_temp;
  c_classreg_learning_classif_Com lv_expl_temp;
  c_classreg_learning_classif_Com m_expl_temp;
  c_classreg_learning_classif_Com mb_expl_temp;
  c_classreg_learning_classif_Com mc_expl_temp;
  c_classreg_learning_classif_Com md_expl_temp;
  c_classreg_learning_classif_Com me_expl_temp;
  c_classreg_learning_classif_Com mf_expl_temp;
  c_classreg_learning_classif_Com mg_expl_temp;
  c_classreg_learning_classif_Com mh_expl_temp;
  c_classreg_learning_classif_Com mi_expl_temp;
  c_classreg_learning_classif_Com mj_expl_temp;
  c_classreg_learning_classif_Com mk_expl_temp;
  c_classreg_learning_classif_Com ml_expl_temp;
  c_classreg_learning_classif_Com mm_expl_temp;
  c_classreg_learning_classif_Com mn_expl_temp;
  c_classreg_learning_classif_Com mo_expl_temp;
  c_classreg_learning_classif_Com mp_expl_temp;
  c_classreg_learning_classif_Com mq_expl_temp;
  c_classreg_learning_classif_Com mr_expl_temp;
  c_classreg_learning_classif_Com ms_expl_temp;
  c_classreg_learning_classif_Com mt_expl_temp;
  c_classreg_learning_classif_Com mu_expl_temp;
  c_classreg_learning_classif_Com mv_expl_temp;
  c_classreg_learning_classif_Com n_expl_temp;
  c_classreg_learning_classif_Com nb_expl_temp;
  c_classreg_learning_classif_Com nc_expl_temp;
  c_classreg_learning_classif_Com nd_expl_temp;
  c_classreg_learning_classif_Com ne_expl_temp;
  c_classreg_learning_classif_Com nf_expl_temp;
  c_classreg_learning_classif_Com ng_expl_temp;
  c_classreg_learning_classif_Com nh_expl_temp;
  c_classreg_learning_classif_Com ni_expl_temp;
  c_classreg_learning_classif_Com nj_expl_temp;
  c_classreg_learning_classif_Com nk_expl_temp;
  c_classreg_learning_classif_Com nl_expl_temp;
  c_classreg_learning_classif_Com nm_expl_temp;
  c_classreg_learning_classif_Com nn_expl_temp;
  c_classreg_learning_classif_Com no_expl_temp;
  c_classreg_learning_classif_Com np_expl_temp;
  c_classreg_learning_classif_Com nq_expl_temp;
  c_classreg_learning_classif_Com nr_expl_temp;
  c_classreg_learning_classif_Com ns_expl_temp;
  c_classreg_learning_classif_Com nt_expl_temp;
  c_classreg_learning_classif_Com nu_expl_temp;
  c_classreg_learning_classif_Com nv_expl_temp;
  c_classreg_learning_classif_Com o_expl_temp;
  c_classreg_learning_classif_Com ob_expl_temp;
  c_classreg_learning_classif_Com oc_expl_temp;
  c_classreg_learning_classif_Com od_expl_temp;
  c_classreg_learning_classif_Com oe_expl_temp;
  c_classreg_learning_classif_Com of_expl_temp;
  c_classreg_learning_classif_Com og_expl_temp;
  c_classreg_learning_classif_Com oh_expl_temp;
  c_classreg_learning_classif_Com oi_expl_temp;
  c_classreg_learning_classif_Com oj_expl_temp;
  c_classreg_learning_classif_Com ok_expl_temp;
  c_classreg_learning_classif_Com ol_expl_temp;
  c_classreg_learning_classif_Com om_expl_temp;
  c_classreg_learning_classif_Com on_expl_temp;
  c_classreg_learning_classif_Com oo_expl_temp;
  c_classreg_learning_classif_Com op_expl_temp;
  c_classreg_learning_classif_Com oq_expl_temp;
  c_classreg_learning_classif_Com or_expl_temp;
  c_classreg_learning_classif_Com os_expl_temp;
  c_classreg_learning_classif_Com ot_expl_temp;
  c_classreg_learning_classif_Com ou_expl_temp;
  c_classreg_learning_classif_Com ov_expl_temp;
  c_classreg_learning_classif_Com p_expl_temp;
  c_classreg_learning_classif_Com pb_expl_temp;
  c_classreg_learning_classif_Com pc_expl_temp;
  c_classreg_learning_classif_Com pd_expl_temp;
  c_classreg_learning_classif_Com pe_expl_temp;
  c_classreg_learning_classif_Com pf_expl_temp;
  c_classreg_learning_classif_Com pg_expl_temp;
  c_classreg_learning_classif_Com ph_expl_temp;
  c_classreg_learning_classif_Com pi_expl_temp;
  c_classreg_learning_classif_Com pj_expl_temp;
  c_classreg_learning_classif_Com pk_expl_temp;
  c_classreg_learning_classif_Com pl_expl_temp;
  c_classreg_learning_classif_Com pm_expl_temp;
  c_classreg_learning_classif_Com pn_expl_temp;
  c_classreg_learning_classif_Com po_expl_temp;
  c_classreg_learning_classif_Com pp_expl_temp;
  c_classreg_learning_classif_Com pq_expl_temp;
  c_classreg_learning_classif_Com pr_expl_temp;
  c_classreg_learning_classif_Com ps_expl_temp;
  c_classreg_learning_classif_Com pt_expl_temp;
  c_classreg_learning_classif_Com pu_expl_temp;
  c_classreg_learning_classif_Com pv_expl_temp;
  c_classreg_learning_classif_Com q_expl_temp;
  c_classreg_learning_classif_Com qb_expl_temp;
  c_classreg_learning_classif_Com qc_expl_temp;
  c_classreg_learning_classif_Com qd_expl_temp;
  c_classreg_learning_classif_Com qe_expl_temp;
  c_classreg_learning_classif_Com qf_expl_temp;
  c_classreg_learning_classif_Com qg_expl_temp;
  c_classreg_learning_classif_Com qh_expl_temp;
  c_classreg_learning_classif_Com qi_expl_temp;
  c_classreg_learning_classif_Com qj_expl_temp;
  c_classreg_learning_classif_Com qk_expl_temp;
  c_classreg_learning_classif_Com ql_expl_temp;
  c_classreg_learning_classif_Com qm_expl_temp;
  c_classreg_learning_classif_Com qn_expl_temp;
  c_classreg_learning_classif_Com qo_expl_temp;
  c_classreg_learning_classif_Com qp_expl_temp;
  c_classreg_learning_classif_Com qq_expl_temp;
  c_classreg_learning_classif_Com qr_expl_temp;
  c_classreg_learning_classif_Com qs_expl_temp;
  c_classreg_learning_classif_Com qt_expl_temp;
  c_classreg_learning_classif_Com qu_expl_temp;
  c_classreg_learning_classif_Com qv_expl_temp;
  c_classreg_learning_classif_Com r_expl_temp;
  c_classreg_learning_classif_Com rb_expl_temp;
  c_classreg_learning_classif_Com rc_expl_temp;
  c_classreg_learning_classif_Com rd_expl_temp;
  c_classreg_learning_classif_Com re_expl_temp;
  c_classreg_learning_classif_Com rf_expl_temp;
  c_classreg_learning_classif_Com rg_expl_temp;
  c_classreg_learning_classif_Com rh_expl_temp;
  c_classreg_learning_classif_Com ri_expl_temp;
  c_classreg_learning_classif_Com rj_expl_temp;
  c_classreg_learning_classif_Com rk_expl_temp;
  c_classreg_learning_classif_Com rl_expl_temp;
  c_classreg_learning_classif_Com rm_expl_temp;
  c_classreg_learning_classif_Com rn_expl_temp;
  c_classreg_learning_classif_Com ro_expl_temp;
  c_classreg_learning_classif_Com rp_expl_temp;
  c_classreg_learning_classif_Com rq_expl_temp;
  c_classreg_learning_classif_Com rr_expl_temp;
  c_classreg_learning_classif_Com rs_expl_temp;
  c_classreg_learning_classif_Com rt_expl_temp;
  c_classreg_learning_classif_Com ru_expl_temp;
  c_classreg_learning_classif_Com s_expl_temp;
  c_classreg_learning_classif_Com sb_expl_temp;
  c_classreg_learning_classif_Com sc_expl_temp;
  c_classreg_learning_classif_Com sd_expl_temp;
  c_classreg_learning_classif_Com se_expl_temp;
  c_classreg_learning_classif_Com sf_expl_temp;
  c_classreg_learning_classif_Com sg_expl_temp;
  c_classreg_learning_classif_Com sh_expl_temp;
  c_classreg_learning_classif_Com si_expl_temp;
  c_classreg_learning_classif_Com sj_expl_temp;
  c_classreg_learning_classif_Com sk_expl_temp;
  c_classreg_learning_classif_Com sl_expl_temp;
  c_classreg_learning_classif_Com sm_expl_temp;
  c_classreg_learning_classif_Com sn_expl_temp;
  c_classreg_learning_classif_Com so_expl_temp;
  c_classreg_learning_classif_Com sp_expl_temp;
  c_classreg_learning_classif_Com sq_expl_temp;
  c_classreg_learning_classif_Com sr_expl_temp;
  c_classreg_learning_classif_Com ss_expl_temp;
  c_classreg_learning_classif_Com st_expl_temp;
  c_classreg_learning_classif_Com su_expl_temp;
  c_classreg_learning_classif_Com t_expl_temp;
  c_classreg_learning_classif_Com tb_expl_temp;
  c_classreg_learning_classif_Com tc_expl_temp;
  c_classreg_learning_classif_Com td_expl_temp;
  c_classreg_learning_classif_Com te_expl_temp;
  c_classreg_learning_classif_Com tf_expl_temp;
  c_classreg_learning_classif_Com tg_expl_temp;
  c_classreg_learning_classif_Com th_expl_temp;
  c_classreg_learning_classif_Com ti_expl_temp;
  c_classreg_learning_classif_Com tj_expl_temp;
  c_classreg_learning_classif_Com tk_expl_temp;
  c_classreg_learning_classif_Com tl_expl_temp;
  c_classreg_learning_classif_Com tm_expl_temp;
  c_classreg_learning_classif_Com tn_expl_temp;
  c_classreg_learning_classif_Com to_expl_temp;
  c_classreg_learning_classif_Com tp_expl_temp;
  c_classreg_learning_classif_Com tq_expl_temp;
  c_classreg_learning_classif_Com tr_expl_temp;
  c_classreg_learning_classif_Com ts_expl_temp;
  c_classreg_learning_classif_Com tt_expl_temp;
  c_classreg_learning_classif_Com tu_expl_temp;
  c_classreg_learning_classif_Com u_expl_temp;
  c_classreg_learning_classif_Com ub_expl_temp;
  c_classreg_learning_classif_Com uc_expl_temp;
  c_classreg_learning_classif_Com ud_expl_temp;
  c_classreg_learning_classif_Com ue_expl_temp;
  c_classreg_learning_classif_Com uf_expl_temp;
  c_classreg_learning_classif_Com ug_expl_temp;
  c_classreg_learning_classif_Com uh_expl_temp;
  c_classreg_learning_classif_Com ui_expl_temp;
  c_classreg_learning_classif_Com uj_expl_temp;
  c_classreg_learning_classif_Com uk_expl_temp;
  c_classreg_learning_classif_Com ul_expl_temp;
  c_classreg_learning_classif_Com um_expl_temp;
  c_classreg_learning_classif_Com un_expl_temp;
  c_classreg_learning_classif_Com uo_expl_temp;
  c_classreg_learning_classif_Com up_expl_temp;
  c_classreg_learning_classif_Com uq_expl_temp;
  c_classreg_learning_classif_Com ur_expl_temp;
  c_classreg_learning_classif_Com us_expl_temp;
  c_classreg_learning_classif_Com ut_expl_temp;
  c_classreg_learning_classif_Com uu_expl_temp;
  c_classreg_learning_classif_Com v_expl_temp;
  c_classreg_learning_classif_Com vb_expl_temp;
  c_classreg_learning_classif_Com vc_expl_temp;
  c_classreg_learning_classif_Com vd_expl_temp;
  c_classreg_learning_classif_Com ve_expl_temp;
  c_classreg_learning_classif_Com vf_expl_temp;
  c_classreg_learning_classif_Com vg_expl_temp;
  c_classreg_learning_classif_Com vh_expl_temp;
  c_classreg_learning_classif_Com vi_expl_temp;
  c_classreg_learning_classif_Com vj_expl_temp;
  c_classreg_learning_classif_Com vk_expl_temp;
  c_classreg_learning_classif_Com vl_expl_temp;
  c_classreg_learning_classif_Com vm_expl_temp;
  c_classreg_learning_classif_Com vn_expl_temp;
  c_classreg_learning_classif_Com vo_expl_temp;
  c_classreg_learning_classif_Com vp_expl_temp;
  c_classreg_learning_classif_Com vq_expl_temp;
  c_classreg_learning_classif_Com vr_expl_temp;
  c_classreg_learning_classif_Com vs_expl_temp;
  c_classreg_learning_classif_Com vt_expl_temp;
  c_classreg_learning_classif_Com vu_expl_temp;
  c_classreg_learning_classif_Com w_expl_temp;
  c_classreg_learning_classif_Com wb_expl_temp;
  c_classreg_learning_classif_Com wc_expl_temp;
  c_classreg_learning_classif_Com wd_expl_temp;
  c_classreg_learning_classif_Com we_expl_temp;
  c_classreg_learning_classif_Com wf_expl_temp;
  c_classreg_learning_classif_Com wg_expl_temp;
  c_classreg_learning_classif_Com wh_expl_temp;
  c_classreg_learning_classif_Com wi_expl_temp;
  c_classreg_learning_classif_Com wj_expl_temp;
  c_classreg_learning_classif_Com wk_expl_temp;
  c_classreg_learning_classif_Com wl_expl_temp;
  c_classreg_learning_classif_Com wm_expl_temp;
  c_classreg_learning_classif_Com wn_expl_temp;
  c_classreg_learning_classif_Com wo_expl_temp;
  c_classreg_learning_classif_Com wp_expl_temp;
  c_classreg_learning_classif_Com wq_expl_temp;
  c_classreg_learning_classif_Com wr_expl_temp;
  c_classreg_learning_classif_Com ws_expl_temp;
  c_classreg_learning_classif_Com wt_expl_temp;
  c_classreg_learning_classif_Com wu_expl_temp;
  c_classreg_learning_classif_Com x_expl_temp;
  c_classreg_learning_classif_Com xb_expl_temp;
  c_classreg_learning_classif_Com xc_expl_temp;
  c_classreg_learning_classif_Com xd_expl_temp;
  c_classreg_learning_classif_Com xe_expl_temp;
  c_classreg_learning_classif_Com xf_expl_temp;
  c_classreg_learning_classif_Com xg_expl_temp;
  c_classreg_learning_classif_Com xh_expl_temp;
  c_classreg_learning_classif_Com xi_expl_temp;
  c_classreg_learning_classif_Com xj_expl_temp;
  c_classreg_learning_classif_Com xk_expl_temp;
  c_classreg_learning_classif_Com xl_expl_temp;
  c_classreg_learning_classif_Com xm_expl_temp;
  c_classreg_learning_classif_Com xn_expl_temp;
  c_classreg_learning_classif_Com xo_expl_temp;
  c_classreg_learning_classif_Com xp_expl_temp;
  c_classreg_learning_classif_Com xq_expl_temp;
  c_classreg_learning_classif_Com xr_expl_temp;
  c_classreg_learning_classif_Com xs_expl_temp;
  c_classreg_learning_classif_Com xt_expl_temp;
  c_classreg_learning_classif_Com xu_expl_temp;
  c_classreg_learning_classif_Com y_expl_temp;
  c_classreg_learning_classif_Com yb_expl_temp;
  c_classreg_learning_classif_Com yc_expl_temp;
  c_classreg_learning_classif_Com yd_expl_temp;
  c_classreg_learning_classif_Com ye_expl_temp;
  c_classreg_learning_classif_Com yf_expl_temp;
  c_classreg_learning_classif_Com yg_expl_temp;
  c_classreg_learning_classif_Com yh_expl_temp;
  c_classreg_learning_classif_Com yi_expl_temp;
  c_classreg_learning_classif_Com yj_expl_temp;
  c_classreg_learning_classif_Com yk_expl_temp;
  c_classreg_learning_classif_Com yl_expl_temp;
  c_classreg_learning_classif_Com ym_expl_temp;
  c_classreg_learning_classif_Com yn_expl_temp;
  c_classreg_learning_classif_Com yo_expl_temp;
  c_classreg_learning_classif_Com yp_expl_temp;
  c_classreg_learning_classif_Com yq_expl_temp;
  c_classreg_learning_classif_Com yr_expl_temp;
  c_classreg_learning_classif_Com ys_expl_temp;
  c_classreg_learning_classif_Com yt_expl_temp;
  c_classreg_learning_classif_Com yu_expl_temp;
  cell_wrap_66 ab_reshapes[2];
  cell_wrap_66 ac_reshapes[2];
  cell_wrap_66 ad_reshapes[2];
  cell_wrap_66 b_reshapes[2];
  cell_wrap_66 bb_reshapes[2];
  cell_wrap_66 bc_reshapes[2];
  cell_wrap_66 bd_reshapes[2];
  cell_wrap_66 c_reshapes[2];
  cell_wrap_66 cb_reshapes[2];
  cell_wrap_66 cc_reshapes[2];
  cell_wrap_66 cd_reshapes[2];
  cell_wrap_66 d_reshapes[2];
  cell_wrap_66 db_reshapes[2];
  cell_wrap_66 dc_reshapes[2];
  cell_wrap_66 dd_reshapes[2];
  cell_wrap_66 e_reshapes[2];
  cell_wrap_66 eb_reshapes[2];
  cell_wrap_66 ec_reshapes[2];
  cell_wrap_66 ed_reshapes[2];
  cell_wrap_66 f_reshapes[2];
  cell_wrap_66 fb_reshapes[2];
  cell_wrap_66 fc_reshapes[2];
  cell_wrap_66 fd_reshapes[2];
  cell_wrap_66 g_reshapes[2];
  cell_wrap_66 gb_reshapes[2];
  cell_wrap_66 gc_reshapes[2];
  cell_wrap_66 gd_reshapes[2];
  cell_wrap_66 h_reshapes[2];
  cell_wrap_66 hb_reshapes[2];
  cell_wrap_66 hc_reshapes[2];
  cell_wrap_66 hd_reshapes[2];
  cell_wrap_66 i_reshapes[2];
  cell_wrap_66 ib_reshapes[2];
  cell_wrap_66 ic_reshapes[2];
  cell_wrap_66 id_reshapes[2];
  cell_wrap_66 j_reshapes[2];
  cell_wrap_66 jb_reshapes[2];
  cell_wrap_66 jc_reshapes[2];
  cell_wrap_66 jd_reshapes[2];
  cell_wrap_66 k_reshapes[2];
  cell_wrap_66 kb_reshapes[2];
  cell_wrap_66 kc_reshapes[2];
  cell_wrap_66 kd_reshapes[2];
  cell_wrap_66 l_reshapes[2];
  cell_wrap_66 lb_reshapes[2];
  cell_wrap_66 lc_reshapes[2];
  cell_wrap_66 ld_reshapes[2];
  cell_wrap_66 m_reshapes[2];
  cell_wrap_66 mb_reshapes[2];
  cell_wrap_66 mc_reshapes[2];
  cell_wrap_66 md_reshapes[2];
  cell_wrap_66 n_reshapes[2];
  cell_wrap_66 nb_reshapes[2];
  cell_wrap_66 nc_reshapes[2];
  cell_wrap_66 nd_reshapes[2];
  cell_wrap_66 o_reshapes[2];
  cell_wrap_66 ob_reshapes[2];
  cell_wrap_66 oc_reshapes[2];
  cell_wrap_66 p_reshapes[2];
  cell_wrap_66 pb_reshapes[2];
  cell_wrap_66 pc_reshapes[2];
  cell_wrap_66 q_reshapes[2];
  cell_wrap_66 qb_reshapes[2];
  cell_wrap_66 qc_reshapes[2];
  cell_wrap_66 r_reshapes[2];
  cell_wrap_66 rb_reshapes[2];
  cell_wrap_66 rc_reshapes[2];
  cell_wrap_66 reshapes[2];
  cell_wrap_66 s_reshapes[2];
  cell_wrap_66 sb_reshapes[2];
  cell_wrap_66 sc_reshapes[2];
  cell_wrap_66 t_reshapes[2];
  cell_wrap_66 tb_reshapes[2];
  cell_wrap_66 tc_reshapes[2];
  cell_wrap_66 u_reshapes[2];
  cell_wrap_66 ub_reshapes[2];
  cell_wrap_66 uc_reshapes[2];
  cell_wrap_66 v_reshapes[2];
  cell_wrap_66 vb_reshapes[2];
  cell_wrap_66 vc_reshapes[2];
  cell_wrap_66 w_reshapes[2];
  cell_wrap_66 wb_reshapes[2];
  cell_wrap_66 wc_reshapes[2];
  cell_wrap_66 x_reshapes[2];
  cell_wrap_66 xb_reshapes[2];
  cell_wrap_66 xc_reshapes[2];
  cell_wrap_66 y_reshapes[2];
  cell_wrap_66 yb_reshapes[2];
  cell_wrap_66 yc_reshapes[2];
  double classifier1_LearnerWeights[30];
  double mask_apply_data[5];
  double pred_conf[5];
  double pred_mask[5];
  double varargin_2_data[5];
  double classifier1_Cost[4];
  double classifier1_ClassNames[2];
  double classifier1_Prior[2];
  double classifier2_ClassNames[2];
  double classifier2_Prior[2];
  int expl_temp[2];
  int b_i;
  int c_i;
  int i;
  int i1;
  int i4;
  int loop_ub;
  int result_size_idx_0;
  int varargin_1_size_idx_0;
  int varargin_1_size_idx_1;
  short i5;
  signed char b_true_label_data[180];
  signed char result_data[180];
  signed char i2;
  signed char i3;
  signed char sizes_idx_1;
  unsigned char u;
  boolean_T classifier1_IsCached[30];
  boolean_T classifier2_IsCached[30];
  boolean_T classifier1_ClassLogicalIndices[2];
  c_classreg_learning_coderutils_ b_expl_temp;
  (void)File_info;
  if (!isInitialized_profile_Yuxuan_iteration) {
    profile_Yuxuan_iteration_initialize();
  }

  /*  classifier1 = loadLearnerForCoder("../c_model/model_0_0_1_1_0_0_0_0_0_0_0_0_0_0_0_0_0_26-Oct-2023seed_0.mat"); */
  /*  classifier2 = loadLearnerForCoder("../c_model/model_1_0_1_1_0_0_0_0_0_0_0_0_0_0_0_0_0_26-Oct-2023seed_0.mat"); */
  /*  classifier3 = loadLearnerForCoder("../c_model/model_1_1_1_1_0_0_0_0_0_0_0_0_0_0_0_1_0_26-Oct-2023seed_0.mat"); */
  /*  classifier4 = loadLearnerForCoder("../c_model/model_1_1_1_1_0_0_0_0_1_1_1_1_1_1_1_1_1_26-Oct-2023seed_0.mat"); */
  /*  classifier5 = loadLearnerForCoder("../c_model/model_1_1_1_1_1_1_1_1_1_1_1_1_1_1_1_1_1_26-Oct-2023seed_0.mat"); */
  c_CompactClassificationEnsemble(classifier1_IsCached,
    classifier1_LearnerWeights, classifier1_ClassNames, expl_temp, &b_expl_temp,
    classifier1_Prior, classifier1_ClassLogicalIndices, classifier1_Cost);
  c_CompactClassificationEnsemble(classifier2_IsCached,
    classifier1_LearnerWeights, classifier2_ClassNames, expl_temp, &b_expl_temp,
    classifier2_Prior, classifier1_ClassLogicalIndices, classifier1_Cost);
  c_CompactClassificationEnsemble(c_expl_temp.IsCached,
    c_expl_temp.LearnerWeights, c_expl_temp.ClassNames, expl_temp, &b_expl_temp,
    c_expl_temp.Prior, c_expl_temp.ClassLogicalIndices, c_expl_temp.Cost);
  c_CompactClassificationEnsemble(d_expl_temp.IsCached,
    d_expl_temp.LearnerWeights, d_expl_temp.ClassNames, expl_temp, &b_expl_temp,
    d_expl_temp.Prior, d_expl_temp.ClassLogicalIndices, d_expl_temp.Cost);
  c_CompactClassificationEnsemble(e_expl_temp.IsCached,
    e_expl_temp.LearnerWeights, e_expl_temp.ClassNames, expl_temp, &b_expl_temp,
    e_expl_temp.Prior, e_expl_temp.ClassLogicalIndices, e_expl_temp.Cost);
  true_label_size[0] = 1;
  true_label_size[1] = 1;
  true_label_data[0] = rtNaN;
  pred_label_size[0] = 1;
  pred_label_size[1] = 1;
  pred_label_data[0] = rtNaN;
  i = (int)profile_times;
  emxInitMatrix_cell_wrap_66(reshapes);
  emxInitMatrix_cell_wrap_66(b_reshapes);
  emxInitMatrix_cell_wrap_66(c_reshapes);
  emxInitMatrix_cell_wrap_66(d_reshapes);
  emxInitMatrix_cell_wrap_66(e_reshapes);
  emxInitMatrix_cell_wrap_66(f_reshapes);
  emxInitMatrix_cell_wrap_66(g_reshapes);
  emxInitMatrix_cell_wrap_66(h_reshapes);
  emxInitMatrix_cell_wrap_66(i_reshapes);
  emxInitMatrix_cell_wrap_66(j_reshapes);
  emxInitMatrix_cell_wrap_66(k_reshapes);
  emxInitMatrix_cell_wrap_66(l_reshapes);
  emxInitMatrix_cell_wrap_66(m_reshapes);
  emxInitMatrix_cell_wrap_66(n_reshapes);
  emxInitMatrix_cell_wrap_66(o_reshapes);
  emxInitMatrix_cell_wrap_66(p_reshapes);
  emxInitMatrix_cell_wrap_66(q_reshapes);
  emxInitMatrix_cell_wrap_66(r_reshapes);
  emxInitMatrix_cell_wrap_66(s_reshapes);
  emxInitMatrix_cell_wrap_66(t_reshapes);
  emxInitMatrix_cell_wrap_66(u_reshapes);
  emxInitMatrix_cell_wrap_66(v_reshapes);
  emxInitMatrix_cell_wrap_66(w_reshapes);
  emxInitMatrix_cell_wrap_66(x_reshapes);
  emxInitMatrix_cell_wrap_66(y_reshapes);
  emxInitMatrix_cell_wrap_66(ab_reshapes);
  emxInitMatrix_cell_wrap_66(bb_reshapes);
  emxInitMatrix_cell_wrap_66(cb_reshapes);
  emxInitMatrix_cell_wrap_66(db_reshapes);
  emxInitMatrix_cell_wrap_66(eb_reshapes);
  emxInitMatrix_cell_wrap_66(fb_reshapes);
  emxInitMatrix_cell_wrap_66(gb_reshapes);
  emxInitMatrix_cell_wrap_66(hb_reshapes);
  emxInitMatrix_cell_wrap_66(ib_reshapes);
  emxInitMatrix_cell_wrap_66(jb_reshapes);
  emxInitMatrix_cell_wrap_66(kb_reshapes);
  emxInitMatrix_cell_wrap_66(lb_reshapes);
  emxInitMatrix_cell_wrap_66(mb_reshapes);
  emxInitMatrix_cell_wrap_66(nb_reshapes);
  emxInitMatrix_cell_wrap_66(ob_reshapes);
  emxInitMatrix_cell_wrap_66(pb_reshapes);
  emxInitMatrix_cell_wrap_66(qb_reshapes);
  emxInitMatrix_cell_wrap_66(rb_reshapes);
  emxInitMatrix_cell_wrap_66(sb_reshapes);
  emxInitMatrix_cell_wrap_66(tb_reshapes);
  emxInitMatrix_cell_wrap_66(ub_reshapes);
  emxInitMatrix_cell_wrap_66(vb_reshapes);
  emxInitMatrix_cell_wrap_66(wb_reshapes);
  emxInitMatrix_cell_wrap_66(xb_reshapes);
  emxInitMatrix_cell_wrap_66(yb_reshapes);
  emxInitMatrix_cell_wrap_66(ac_reshapes);
  emxInitMatrix_cell_wrap_66(bc_reshapes);
  emxInitMatrix_cell_wrap_66(cc_reshapes);
  emxInitMatrix_cell_wrap_66(dc_reshapes);
  emxInitMatrix_cell_wrap_66(ec_reshapes);
  emxInitMatrix_cell_wrap_66(fc_reshapes);
  emxInitMatrix_cell_wrap_66(gc_reshapes);
  emxInitMatrix_cell_wrap_66(hc_reshapes);
  emxInitMatrix_cell_wrap_66(ic_reshapes);
  emxInitMatrix_cell_wrap_66(jc_reshapes);
  emxInitMatrix_cell_wrap_66(kc_reshapes);
  emxInitMatrix_cell_wrap_66(lc_reshapes);
  emxInitMatrix_cell_wrap_66(mc_reshapes);
  emxInitMatrix_cell_wrap_66(nc_reshapes);
  emxInitMatrix_cell_wrap_66(oc_reshapes);
  emxInitMatrix_cell_wrap_66(pc_reshapes);
  emxInitMatrix_cell_wrap_66(qc_reshapes);
  emxInitMatrix_cell_wrap_66(rc_reshapes);
  emxInitMatrix_cell_wrap_66(sc_reshapes);
  emxInitMatrix_cell_wrap_66(tc_reshapes);
  emxInitMatrix_cell_wrap_66(uc_reshapes);
  emxInitMatrix_cell_wrap_66(vc_reshapes);
  emxInitMatrix_cell_wrap_66(wc_reshapes);
  emxInitMatrix_cell_wrap_66(xc_reshapes);
  emxInitMatrix_cell_wrap_66(yc_reshapes);
  emxInitMatrix_cell_wrap_66(ad_reshapes);
  emxInitMatrix_cell_wrap_66(bd_reshapes);
  emxInitMatrix_cell_wrap_66(cd_reshapes);
  emxInitMatrix_cell_wrap_66(dd_reshapes);
  emxInitMatrix_cell_wrap_66(ed_reshapes);
  emxInitMatrix_cell_wrap_66(fd_reshapes);
  emxInitMatrix_cell_wrap_66(gd_reshapes);
  emxInitMatrix_cell_wrap_66(hd_reshapes);
  emxInitMatrix_cell_wrap_66(id_reshapes);
  emxInitMatrix_cell_wrap_66(jd_reshapes);
  emxInitMatrix_cell_wrap_66(kd_reshapes);
  emxInitMatrix_cell_wrap_66(ld_reshapes);
  emxInitMatrix_cell_wrap_66(md_reshapes);
  emxInitMatrix_cell_wrap_66(nd_reshapes);
  for (b_i = 0; b_i < i; b_i++) {
    /* test 10 times */
    /*  ------------------------------------------------------------ */
    true_label_size[0] = 0;
    true_label_size[1] = 0;
    pred_label_size[0] = 0;
    pred_label_size[1] = 0;

    /*  skip the training data */
    if (select_ind[0]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[0], *(double (*)
        [30720])&Spo2_Seiz_Window[0], Fs, Nbr_RR, classifier1_IsCached,
                            classifier1_ClassNames, classifier1_Prior,
                            classifier2_IsCached, classifier2_ClassNames,
                            classifier2_Prior, &c_expl_temp, &d_expl_temp,
                            &e_expl_temp, norm_coef1, norm_coef2, norm_coef3,
                            norm_coef4, norm_coef5, wind_len, conf_seiz, masks,
                            pred_mask, pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      /*  select test data type */
      /*  -------- profiling only -------- */
      i_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      i_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      i_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      i_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      i_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      i_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      i_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      i_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      i_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      i_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      p_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      p_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      p_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      p_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      p_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      p_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      p_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      p_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      p_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      p_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ab_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ab_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ab_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ab_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ab_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ab_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ab_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ab_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ab_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ab_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&i_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&p_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&ab_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        i_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        p_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ab_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[0], *(double (*)
        [30720])&Spo2_Gray_Window[0], Fs, Nbr_RR, classifier1_IsCached,
                            classifier1_ClassNames, classifier1_Prior,
                            classifier2_IsCached, classifier2_ClassNames,
                            classifier2_Prior, &i_expl_temp, &p_expl_temp,
                            &ab_expl_temp, norm_coef1, norm_coef2, norm_coef3,
                            norm_coef4, norm_coef5, wind_len, conf_seiz, masks,
                            pred_mask, pred_conf, mask_apply_data, expl_temp);
      c_i = sizes_idx_1;
      if (0 <= c_i - 1) {
        memcpy(&varargin_1_data[0], &varargin_2_data[0], c_i * sizeof(double));
      }

      if (sizes_idx_1 != 0) {
        i2 = sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      result_data[0] = 1;
      true_label_size[0] = 2;
      true_label_size[1] = 1;
      true_label_data[0] = result_data[0];
      true_label_data[1] = 0.0;

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[1]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      f_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      f_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      f_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      f_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      f_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      f_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      f_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      f_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      f_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      f_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      k_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      k_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      k_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      k_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      k_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      k_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      k_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      k_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      k_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      k_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      s_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      s_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      s_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      s_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      s_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      s_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      s_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      s_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      s_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      s_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&f_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&k_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&s_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        f_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        k_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        s_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[30720],
                            *(double (*)[30720])&Spo2_Seiz_Window[30720], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &f_expl_temp, &k_expl_temp, &s_expl_temp, norm_coef1,
                            norm_coef2, norm_coef3, norm_coef4, norm_coef5,
                            wind_len, conf_seiz, masks, pred_mask, pred_conf,
                            mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
      reshapes[0].f1->size[0] = 1;
      reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      mc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      mc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      mc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      mc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      mc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      mc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      mc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      mc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      mc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      mc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      bd_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      bd_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      bd_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      bd_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      bd_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      bd_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      bd_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      bd_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      bd_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      bd_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      sd_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      sd_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      sd_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      sd_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      sd_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      sd_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      sd_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      sd_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      sd_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      sd_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&mc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bd_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&sd_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        mc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        bd_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        sd_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[30720],
                            *(double (*)[30720])&Spo2_Gray_Window[30720], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &mc_expl_temp, &bd_expl_temp, &sd_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = reshapes[0].f1->size[0];
      c_i = reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = reshapes[0]
            .f1->data[i4 + reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + reshapes[0].f1->size[1])] =
          varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[2]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      g_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      g_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      g_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      g_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      g_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      g_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      g_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      g_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      g_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      g_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      m_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      m_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      m_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      m_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      m_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      m_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      m_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      m_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      m_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      m_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      v_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      v_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      v_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      v_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      v_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      v_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      v_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      v_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      v_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      v_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&g_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&m_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&v_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        g_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        m_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        v_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[61440],
                            *(double (*)[30720])&Spo2_Seiz_Window[61440], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &g_expl_temp, &m_expl_temp, &v_expl_temp, norm_coef1,
                            norm_coef2, norm_coef3, norm_coef4, norm_coef5,
                            wind_len, conf_seiz, masks, pred_mask, pred_conf,
                            mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = b_reshapes[0].f1->size[0] * b_reshapes[0].f1->size[1];
      b_reshapes[0].f1->size[0] = 1;
      b_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(b_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        b_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      qc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      qc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      qc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      qc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      qc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      qc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      qc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      qc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      qc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      qc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      gd_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      gd_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      gd_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      gd_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      gd_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      gd_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      gd_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      gd_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      gd_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      gd_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      yd_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      yd_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      yd_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      yd_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      yd_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      yd_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      yd_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      yd_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      yd_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      yd_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&qc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gd_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yd_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        qc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        gd_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        yd_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[61440],
                            *(double (*)[30720])&Spo2_Gray_Window[61440], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &qc_expl_temp, &gd_expl_temp, &yd_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = b_reshapes[0].f1->size[0];
      c_i = b_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = b_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = b_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = b_reshapes[0]
            .f1->data[i4 + b_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + b_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[3]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      h_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      h_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      h_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      h_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      h_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      h_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      h_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      h_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      h_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      h_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      o_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      o_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      o_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      o_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      o_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      o_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      o_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      o_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      o_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      o_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      y_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      y_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      y_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      y_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      y_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      y_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      y_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      y_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      y_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      y_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&h_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&o_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&y_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        h_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        o_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        y_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[92160],
                            *(double (*)[30720])&Spo2_Seiz_Window[92160], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &h_expl_temp, &o_expl_temp, &y_expl_temp, norm_coef1,
                            norm_coef2, norm_coef3, norm_coef4, norm_coef5,
                            wind_len, conf_seiz, masks, pred_mask, pred_conf,
                            mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = c_reshapes[0].f1->size[0] * c_reshapes[0].f1->size[1];
      c_reshapes[0].f1->size[0] = 1;
      c_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(c_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        c_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      uc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      uc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      uc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      uc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      uc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      uc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      uc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      uc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      uc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      uc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ld_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ld_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ld_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ld_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ld_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ld_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ld_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ld_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ld_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ld_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      fe_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      fe_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      fe_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      fe_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      fe_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      fe_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      fe_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      fe_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      fe_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      fe_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&uc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ld_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fe_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        uc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ld_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        fe_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[92160],
                            *(double (*)[30720])&Spo2_Gray_Window[92160], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &uc_expl_temp, &ld_expl_temp, &fe_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = c_reshapes[0].f1->size[0];
      c_i = c_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = c_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = c_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = c_reshapes[0]
            .f1->data[i4 + c_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + c_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[4]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      j_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      j_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      j_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      j_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      j_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      j_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      j_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      j_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      j_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      j_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      r_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      r_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      r_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      r_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      r_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      r_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      r_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      r_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      r_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      r_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      db_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      db_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      db_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      db_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      db_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      db_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      db_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      db_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      db_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      db_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&j_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&r_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&db_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        j_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        r_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        db_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[122880],
                            *(double (*)[30720])&Spo2_Seiz_Window[122880], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &j_expl_temp, &r_expl_temp, &db_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = d_reshapes[0].f1->size[0] * d_reshapes[0].f1->size[1];
      d_reshapes[0].f1->size[0] = 1;
      d_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(d_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        d_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      yc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      yc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      yc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      yc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      yc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      yc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      yc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      yc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      yc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      yc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      qd_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      qd_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      qd_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      qd_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      qd_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      qd_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      qd_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      qd_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      qd_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      qd_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      le_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      le_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      le_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      le_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      le_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      le_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      le_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      le_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      le_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      le_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&yc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qd_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&le_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        yc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        qd_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        le_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[122880],
                            *(double (*)[30720])&Spo2_Gray_Window[122880], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &yc_expl_temp, &qd_expl_temp, &le_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = d_reshapes[0].f1->size[0];
      c_i = d_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = d_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = d_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = d_reshapes[0]
            .f1->data[i4 + d_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + d_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[5]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      l_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      l_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      l_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      l_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      l_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      l_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      l_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      l_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      l_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      l_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      u_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      u_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      u_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      u_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      u_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      u_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      u_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      u_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      u_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      u_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      gb_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      gb_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      gb_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      gb_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      gb_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      gb_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      gb_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      gb_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      gb_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      gb_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&l_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&u_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&gb_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        l_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        u_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        gb_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[153600],
                            *(double (*)[30720])&Spo2_Seiz_Window[153600], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &l_expl_temp, &u_expl_temp, &gb_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = e_reshapes[0].f1->size[0] * e_reshapes[0].f1->size[1];
      e_reshapes[0].f1->size[0] = 1;
      e_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(e_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        e_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ed_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ed_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ed_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ed_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ed_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ed_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ed_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ed_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ed_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ed_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      wd_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      wd_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      wd_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      wd_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      wd_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      wd_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      wd_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      wd_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      wd_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      wd_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      re_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      re_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      re_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      re_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      re_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      re_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      re_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      re_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      re_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      re_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ed_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wd_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&re_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ed_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        wd_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        re_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[153600],
                            *(double (*)[30720])&Spo2_Gray_Window[153600], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ed_expl_temp, &wd_expl_temp, &re_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = e_reshapes[0].f1->size[0];
      c_i = e_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = e_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = e_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = e_reshapes[0]
            .f1->data[i4 + e_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + e_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[6]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      n_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      n_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      n_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      n_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      n_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      n_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      n_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      n_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      n_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      n_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      x_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      x_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      x_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      x_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      x_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      x_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      x_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      x_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      x_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      x_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      jb_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      jb_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      jb_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      jb_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      jb_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      jb_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      jb_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      jb_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      jb_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      jb_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&n_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&x_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&jb_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        n_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        x_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        jb_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[184320],
                            *(double (*)[30720])&Spo2_Seiz_Window[184320], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &n_expl_temp, &x_expl_temp, &jb_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = f_reshapes[0].f1->size[0] * f_reshapes[0].f1->size[1];
      f_reshapes[0].f1->size[0] = 1;
      f_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(f_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        f_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      jd_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      jd_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      jd_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      jd_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      jd_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      jd_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      jd_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      jd_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      jd_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      jd_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      de_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      de_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      de_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      de_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      de_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      de_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      de_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      de_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      de_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      de_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      xe_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      xe_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      xe_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      xe_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      xe_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      xe_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      xe_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      xe_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      xe_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      xe_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&jd_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&de_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xe_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        jd_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        de_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        xe_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[184320],
                            *(double (*)[30720])&Spo2_Gray_Window[184320], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &jd_expl_temp, &de_expl_temp, &xe_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = f_reshapes[0].f1->size[0];
      c_i = f_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = f_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = f_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = f_reshapes[0]
            .f1->data[i4 + f_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + f_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[7]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      q_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      q_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      q_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      q_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      q_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      q_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      q_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      q_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      q_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      q_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      cb_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      cb_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      cb_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      cb_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      cb_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      cb_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      cb_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      cb_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      cb_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      cb_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      mb_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      mb_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      mb_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      mb_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      mb_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      mb_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      mb_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      mb_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      mb_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      mb_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&q_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&cb_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mb_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        q_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        cb_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        mb_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[215040],
                            *(double (*)[30720])&Spo2_Seiz_Window[215040], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &q_expl_temp, &cb_expl_temp, &mb_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = g_reshapes[0].f1->size[0] * g_reshapes[0].f1->size[1];
      g_reshapes[0].f1->size[0] = 1;
      g_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(g_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        g_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      od_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      od_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      od_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      od_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      od_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      od_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      od_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      od_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      od_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      od_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      je_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      je_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      je_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      je_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      je_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      je_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      je_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      je_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      je_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      je_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ef_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ef_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ef_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ef_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ef_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ef_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ef_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ef_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ef_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ef_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&od_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&je_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ef_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        od_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        je_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ef_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[215040],
                            *(double (*)[30720])&Spo2_Gray_Window[215040], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &od_expl_temp, &je_expl_temp, &ef_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = g_reshapes[0].f1->size[0];
      c_i = g_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = g_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = g_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = g_reshapes[0]
            .f1->data[i4 + g_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + g_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[8]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      t_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      t_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      t_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      t_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      t_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      t_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      t_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      t_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      t_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      t_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      fb_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      fb_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      fb_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      fb_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      fb_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      fb_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      fb_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      fb_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      fb_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      fb_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      pb_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      pb_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      pb_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      pb_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      pb_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      pb_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      pb_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      pb_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      pb_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      pb_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&t_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&fb_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pb_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        t_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        fb_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        pb_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[245760],
                            *(double (*)[30720])&Spo2_Seiz_Window[245760], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &t_expl_temp, &fb_expl_temp, &pb_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = h_reshapes[0].f1->size[0] * h_reshapes[0].f1->size[1];
      h_reshapes[0].f1->size[0] = 1;
      h_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(h_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        h_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ud_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ud_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ud_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ud_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ud_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ud_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ud_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ud_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ud_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ud_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      pe_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      pe_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      pe_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      pe_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      pe_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      pe_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      pe_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      pe_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      pe_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      pe_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      kf_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      kf_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      kf_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      kf_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      kf_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      kf_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      kf_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      kf_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      kf_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      kf_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ud_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pe_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kf_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ud_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        pe_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        kf_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[245760],
                            *(double (*)[30720])&Spo2_Gray_Window[245760], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ud_expl_temp, &pe_expl_temp, &kf_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = h_reshapes[0].f1->size[0];
      c_i = h_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = h_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = h_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = h_reshapes[0]
            .f1->data[i4 + h_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + h_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[9]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      w_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      w_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      w_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      w_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      w_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      w_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      w_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      w_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      w_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      w_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ib_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ib_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ib_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ib_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ib_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ib_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ib_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ib_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ib_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ib_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      sb_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      sb_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      sb_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      sb_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      sb_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      sb_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      sb_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      sb_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      sb_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      sb_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&w_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0], 30U
             * sizeof(double));
      memcpy(&ib_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&sb_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        w_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ib_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        sb_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[276480],
                            *(double (*)[30720])&Spo2_Seiz_Window[276480], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &w_expl_temp, &ib_expl_temp, &sb_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = i_reshapes[0].f1->size[0] * i_reshapes[0].f1->size[1];
      i_reshapes[0].f1->size[0] = 1;
      i_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(i_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        i_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      be_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      be_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      be_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      be_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      be_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      be_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      be_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      be_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      be_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      be_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ve_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ve_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ve_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ve_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ve_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ve_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ve_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ve_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ve_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ve_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      qf_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      qf_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      qf_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      qf_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      qf_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      qf_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      qf_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      qf_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      qf_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      qf_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&be_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ve_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qf_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        be_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ve_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        qf_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[276480],
                            *(double (*)[30720])&Spo2_Gray_Window[276480], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &be_expl_temp, &ve_expl_temp, &qf_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = i_reshapes[0].f1->size[0];
      c_i = i_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = i_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = i_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = i_reshapes[0]
            .f1->data[i4 + i_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + i_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[10]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      bb_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      bb_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      bb_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      bb_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      bb_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      bb_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      bb_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      bb_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      bb_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      bb_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      lb_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      lb_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      lb_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      lb_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      lb_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      lb_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      lb_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      lb_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      lb_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      lb_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      vb_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      vb_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      vb_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      vb_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      vb_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      vb_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      vb_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      vb_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      vb_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      vb_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&bb_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lb_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vb_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        bb_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        lb_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        vb_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[307200],
                            *(double (*)[30720])&Spo2_Seiz_Window[307200], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &bb_expl_temp, &lb_expl_temp, &vb_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = j_reshapes[0].f1->size[0] * j_reshapes[0].f1->size[1];
      j_reshapes[0].f1->size[0] = 1;
      j_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(j_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        j_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      he_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      he_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      he_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      he_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      he_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      he_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      he_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      he_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      he_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      he_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      cf_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      cf_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      cf_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      cf_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      cf_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      cf_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      cf_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      cf_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      cf_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      cf_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      wf_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      wf_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      wf_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      wf_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      wf_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      wf_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      wf_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      wf_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      wf_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      wf_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&he_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cf_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wf_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        he_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        cf_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        wf_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[307200],
                            *(double (*)[30720])&Spo2_Gray_Window[307200], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &he_expl_temp, &cf_expl_temp, &wf_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = j_reshapes[0].f1->size[0];
      c_i = j_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = j_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = j_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = j_reshapes[0]
            .f1->data[i4 + j_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + j_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[11]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      eb_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      eb_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      eb_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      eb_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      eb_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      eb_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      eb_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      eb_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      eb_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      eb_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ob_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ob_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ob_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ob_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ob_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ob_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ob_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ob_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ob_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ob_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      yb_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      yb_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      yb_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      yb_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      yb_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      yb_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      yb_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      yb_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      yb_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      yb_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&eb_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ob_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yb_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        eb_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ob_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        yb_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[337920],
                            *(double (*)[30720])&Spo2_Seiz_Window[337920], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &eb_expl_temp, &ob_expl_temp, &yb_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = k_reshapes[0].f1->size[0] * k_reshapes[0].f1->size[1];
      k_reshapes[0].f1->size[0] = 1;
      k_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(k_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        k_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ne_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ne_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ne_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ne_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ne_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ne_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ne_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ne_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ne_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ne_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      if_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      if_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      if_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      if_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      if_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      if_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      if_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      if_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      if_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      if_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      dg_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      dg_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      dg_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      dg_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      dg_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      dg_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      dg_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      dg_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      dg_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      dg_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ne_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&if_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dg_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ne_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        if_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        dg_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[337920],
                            *(double (*)[30720])&Spo2_Gray_Window[337920], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ne_expl_temp, &if_expl_temp, &dg_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = k_reshapes[0].f1->size[0];
      c_i = k_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = k_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = k_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = k_reshapes[0]
            .f1->data[i4 + k_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + k_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[12]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      hb_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      hb_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      hb_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      hb_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      hb_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      hb_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      hb_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      hb_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      hb_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      hb_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      rb_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      rb_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      rb_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      rb_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      rb_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      rb_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      rb_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      rb_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      rb_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      rb_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      cc_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      cc_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      cc_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      cc_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      cc_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      cc_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      cc_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      cc_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      cc_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      cc_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&hb_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rb_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cc_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        hb_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        rb_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        cc_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[368640],
                            *(double (*)[30720])&Spo2_Seiz_Window[368640], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &hb_expl_temp, &rb_expl_temp, &cc_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i2 = (signed char)pred_label_size[1];
      } else {
        i2 = 0;
      }

      i1 = l_reshapes[0].f1->size[0] * l_reshapes[0].f1->size[1];
      l_reshapes[0].f1->size[0] = 1;
      l_reshapes[0].f1->size[1] = i2;
      emxEnsureCapacity_real_T(l_reshapes[0].f1, i1);
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        l_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i3 = (signed char)true_label_size[0];
      } else {
        i3 = 0;
      }

      result_size_idx_0 = i3 + 1;
      c_i = i3;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i3] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      te_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      te_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      te_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      te_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      te_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      te_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      te_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      te_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      te_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      te_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      of_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      of_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      of_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      of_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      of_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      of_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      of_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      of_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      of_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      of_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      jg_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      jg_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      jg_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      jg_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      jg_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      jg_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      jg_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      jg_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      jg_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      jg_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&te_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&of_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jg_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        te_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        of_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        jg_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[368640],
                            *(double (*)[30720])&Spo2_Gray_Window[368640], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &te_expl_temp, &of_expl_temp, &jg_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = l_reshapes[0].f1->size[0];
      c_i = l_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = l_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = l_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = l_reshapes[0]
            .f1->data[i4 + l_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + l_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i2 += sizes_idx_1;
      } else {
        i2 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i2 + sizes_idx_1;
      c_i = i2;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i2] = varargin_2_data[i1];
      }

      c_i = i3 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i3 + 1] = 0;
      true_label_size[0] = i3 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[13]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      kb_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      kb_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      kb_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      kb_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      kb_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      kb_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      kb_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      kb_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      kb_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      kb_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ub_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ub_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ub_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ub_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ub_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ub_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ub_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ub_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ub_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ub_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      fc_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      fc_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      fc_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      fc_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      fc_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      fc_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      fc_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      fc_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      fc_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      fc_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&kb_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ub_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fc_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        kb_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ub_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        fc_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[399360],
                            *(double (*)[30720])&Spo2_Seiz_Window[399360], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &kb_expl_temp, &ub_expl_temp, &fc_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = m_reshapes[0].f1->size[0] * m_reshapes[0].f1->size[1];
      m_reshapes[0].f1->size[0] = 1;
      m_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(m_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        m_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      af_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      af_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      af_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      af_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      af_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      af_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      af_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      af_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      af_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      af_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      uf_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      uf_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      uf_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      uf_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      uf_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      uf_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      uf_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      uf_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      uf_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      uf_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      pg_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      pg_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      pg_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      pg_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      pg_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      pg_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      pg_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      pg_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      pg_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      pg_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&af_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&uf_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pg_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        af_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        uf_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        pg_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[399360],
                            *(double (*)[30720])&Spo2_Gray_Window[399360], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &af_expl_temp, &uf_expl_temp, &pg_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = m_reshapes[0].f1->size[0];
      c_i = m_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = m_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = m_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = m_reshapes[0]
            .f1->data[i4 + m_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + m_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[14]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      nb_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      nb_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      nb_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      nb_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      nb_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      nb_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      nb_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      nb_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      nb_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      nb_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      xb_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      xb_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      xb_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      xb_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      xb_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      xb_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      xb_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      xb_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      xb_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      xb_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ic_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ic_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ic_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ic_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ic_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ic_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ic_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ic_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ic_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ic_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&nb_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xb_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ic_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        nb_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        xb_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ic_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[430080],
                            *(double (*)[30720])&Spo2_Seiz_Window[430080], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &nb_expl_temp, &xb_expl_temp, &ic_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = n_reshapes[0].f1->size[0] * n_reshapes[0].f1->size[1];
      n_reshapes[0].f1->size[0] = 1;
      n_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(n_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        n_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      gf_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      gf_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      gf_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      gf_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      gf_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      gf_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      gf_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      gf_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      gf_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      gf_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      bg_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      bg_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      bg_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      bg_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      bg_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      bg_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      bg_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      bg_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      bg_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      bg_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      vg_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      vg_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      vg_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      vg_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      vg_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      vg_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      vg_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      vg_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      vg_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      vg_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&gf_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bg_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vg_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        gf_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        bg_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        vg_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[430080],
                            *(double (*)[30720])&Spo2_Gray_Window[430080], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &gf_expl_temp, &bg_expl_temp, &vg_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = n_reshapes[0].f1->size[0];
      c_i = n_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = n_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = n_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = n_reshapes[0]
            .f1->data[i4 + n_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + n_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[15]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      qb_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      qb_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      qb_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      qb_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      qb_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      qb_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      qb_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      qb_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      qb_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      qb_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      bc_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      bc_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      bc_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      bc_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      bc_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      bc_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      bc_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      bc_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      bc_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      bc_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      lc_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      lc_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      lc_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      lc_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      lc_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      lc_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      lc_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      lc_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      lc_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      lc_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&qb_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bc_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lc_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        qb_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        bc_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        lc_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[460800],
                            *(double (*)[30720])&Spo2_Seiz_Window[460800], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &qb_expl_temp, &bc_expl_temp, &lc_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = o_reshapes[0].f1->size[0] * o_reshapes[0].f1->size[1];
      o_reshapes[0].f1->size[0] = 1;
      o_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(o_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        o_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      mf_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      mf_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      mf_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      mf_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      mf_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      mf_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      mf_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      mf_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      mf_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      mf_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      hg_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      hg_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      hg_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      hg_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      hg_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      hg_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      hg_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      hg_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      hg_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      hg_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ch_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ch_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ch_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ch_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ch_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ch_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ch_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ch_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ch_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ch_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&mf_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hg_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ch_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        mf_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        hg_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ch_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[460800],
                            *(double (*)[30720])&Spo2_Gray_Window[460800], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &mf_expl_temp, &hg_expl_temp, &ch_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = o_reshapes[0].f1->size[0];
      c_i = o_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = o_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = o_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = o_reshapes[0]
            .f1->data[i4 + o_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + o_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[16]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      tb_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      tb_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      tb_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      tb_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      tb_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      tb_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      tb_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      tb_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      tb_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      tb_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ec_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ec_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ec_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ec_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ec_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ec_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ec_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ec_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ec_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ec_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      pc_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      pc_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      pc_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      pc_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      pc_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      pc_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      pc_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      pc_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      pc_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      pc_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&tb_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ec_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pc_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        tb_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ec_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        pc_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[491520],
                            *(double (*)[30720])&Spo2_Seiz_Window[491520], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &tb_expl_temp, &ec_expl_temp, &pc_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = p_reshapes[0].f1->size[0] * p_reshapes[0].f1->size[1];
      p_reshapes[0].f1->size[0] = 1;
      p_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(p_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        p_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      sf_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      sf_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      sf_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      sf_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      sf_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      sf_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      sf_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      sf_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      sf_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      sf_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ng_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ng_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ng_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ng_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ng_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ng_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ng_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ng_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ng_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ng_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ih_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ih_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ih_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ih_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ih_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ih_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ih_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ih_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ih_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ih_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&sf_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ng_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ih_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        sf_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ng_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ih_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[491520],
                            *(double (*)[30720])&Spo2_Gray_Window[491520], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &sf_expl_temp, &ng_expl_temp, &ih_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = p_reshapes[0].f1->size[0];
      c_i = p_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = p_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = p_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = p_reshapes[0]
            .f1->data[i4 + p_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + p_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[17]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      wb_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      wb_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      wb_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      wb_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      wb_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      wb_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      wb_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      wb_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      wb_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      wb_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      hc_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      hc_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      hc_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      hc_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      hc_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      hc_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      hc_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      hc_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      hc_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      hc_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      tc_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      tc_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      tc_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      tc_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      tc_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      tc_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      tc_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      tc_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      tc_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      tc_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&wb_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hc_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&tc_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        wb_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        hc_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        tc_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[522240],
                            *(double (*)[30720])&Spo2_Seiz_Window[522240], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &wb_expl_temp, &hc_expl_temp, &tc_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = q_reshapes[0].f1->size[0] * q_reshapes[0].f1->size[1];
      q_reshapes[0].f1->size[0] = 1;
      q_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(q_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        q_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      yf_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      yf_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      yf_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      yf_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      yf_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      yf_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      yf_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      yf_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      yf_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      yf_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      tg_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      tg_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      tg_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      tg_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      tg_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      tg_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      tg_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      tg_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      tg_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      tg_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      oh_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      oh_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      oh_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      oh_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      oh_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      oh_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      oh_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      oh_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      oh_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      oh_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&yf_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&tg_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&oh_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        yf_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        tg_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        oh_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[522240],
                            *(double (*)[30720])&Spo2_Gray_Window[522240], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &yf_expl_temp, &tg_expl_temp, &oh_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = q_reshapes[0].f1->size[0];
      c_i = q_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = q_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = q_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = q_reshapes[0]
            .f1->data[i4 + q_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + q_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[18]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ac_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ac_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ac_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ac_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ac_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ac_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ac_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ac_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ac_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ac_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      kc_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      kc_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      kc_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      kc_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      kc_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      kc_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      kc_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      kc_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      kc_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      kc_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      xc_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      xc_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      xc_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      xc_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      xc_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      xc_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      xc_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      xc_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      xc_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      xc_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ac_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kc_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xc_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ac_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        kc_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        xc_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[552960],
                            *(double (*)[30720])&Spo2_Seiz_Window[552960], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ac_expl_temp, &kc_expl_temp, &xc_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = r_reshapes[0].f1->size[0] * r_reshapes[0].f1->size[1];
      r_reshapes[0].f1->size[0] = 1;
      r_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(r_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        r_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      fg_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      fg_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      fg_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      fg_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      fg_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      fg_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      fg_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      fg_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      fg_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      fg_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ah_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ah_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ah_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ah_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ah_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ah_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ah_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ah_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ah_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ah_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      uh_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      uh_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      uh_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      uh_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      uh_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      uh_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      uh_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      uh_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      uh_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      uh_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&fg_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ah_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&uh_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        fg_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ah_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        uh_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[552960],
                            *(double (*)[30720])&Spo2_Gray_Window[552960], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &fg_expl_temp, &ah_expl_temp, &uh_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = r_reshapes[0].f1->size[0];
      c_i = r_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = r_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = r_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = r_reshapes[0]
            .f1->data[i4 + r_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + r_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[19]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      dc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      dc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      dc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      dc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      dc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      dc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      dc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      dc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      dc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      dc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      oc_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      oc_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      oc_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      oc_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      oc_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      oc_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      oc_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      oc_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      oc_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      oc_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      dd_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      dd_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      dd_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      dd_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      dd_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      dd_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      dd_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      dd_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      dd_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      dd_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&dc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&oc_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dd_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        dc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        oc_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        dd_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[583680],
                            *(double (*)[30720])&Spo2_Seiz_Window[583680], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &dc_expl_temp, &oc_expl_temp, &dd_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = s_reshapes[0].f1->size[0] * s_reshapes[0].f1->size[1];
      s_reshapes[0].f1->size[0] = 1;
      s_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(s_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        s_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      lg_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      lg_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      lg_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      lg_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      lg_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      lg_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      lg_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      lg_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      lg_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      lg_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      gh_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      gh_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      gh_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      gh_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      gh_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      gh_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      gh_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      gh_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      gh_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      gh_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      bi_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      bi_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      bi_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      bi_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      bi_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      bi_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      bi_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      bi_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      bi_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      bi_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&lg_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gh_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bi_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        lg_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        gh_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        bi_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[583680],
                            *(double (*)[30720])&Spo2_Gray_Window[583680], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &lg_expl_temp, &gh_expl_temp, &bi_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = s_reshapes[0].f1->size[0];
      c_i = s_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = s_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = s_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = s_reshapes[0]
            .f1->data[i4 + s_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + s_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[20]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      gc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      gc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      gc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      gc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      gc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      gc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      gc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      gc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      gc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      gc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      sc_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      sc_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      sc_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      sc_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      sc_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      sc_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      sc_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      sc_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      sc_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      sc_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      id_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      id_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      id_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      id_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      id_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      id_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      id_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      id_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      id_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      id_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&gc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&sc_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&id_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        gc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        sc_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        id_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[614400],
                            *(double (*)[30720])&Spo2_Seiz_Window[614400], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &gc_expl_temp, &sc_expl_temp, &id_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = t_reshapes[0].f1->size[0] * t_reshapes[0].f1->size[1];
      t_reshapes[0].f1->size[0] = 1;
      t_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(t_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        t_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      rg_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      rg_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      rg_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      rg_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      rg_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      rg_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      rg_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      rg_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      rg_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      rg_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      mh_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      mh_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      mh_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      mh_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      mh_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      mh_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      mh_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      mh_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      mh_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      mh_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      hi_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      hi_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      hi_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      hi_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      hi_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      hi_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      hi_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      hi_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      hi_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      hi_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&rg_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mh_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hi_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        rg_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        mh_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        hi_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[614400],
                            *(double (*)[30720])&Spo2_Gray_Window[614400], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &rg_expl_temp, &mh_expl_temp, &hi_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = t_reshapes[0].f1->size[0];
      c_i = t_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = t_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = t_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = t_reshapes[0]
            .f1->data[i4 + t_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + t_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[21]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      jc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      jc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      jc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      jc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      jc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      jc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      jc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      jc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      jc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      jc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      wc_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      wc_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      wc_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      wc_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      wc_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      wc_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      wc_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      wc_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      wc_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      wc_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      nd_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      nd_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      nd_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      nd_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      nd_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      nd_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      nd_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      nd_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      nd_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      nd_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&jc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wc_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&nd_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        jc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        wc_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        nd_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[645120],
                            *(double (*)[30720])&Spo2_Seiz_Window[645120], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &jc_expl_temp, &wc_expl_temp, &nd_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = u_reshapes[0].f1->size[0] * u_reshapes[0].f1->size[1];
      u_reshapes[0].f1->size[0] = 1;
      u_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(u_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        u_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      xg_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      xg_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      xg_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      xg_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      xg_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      xg_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      xg_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      xg_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      xg_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      xg_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      sh_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      sh_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      sh_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      sh_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      sh_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      sh_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      sh_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      sh_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      sh_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      sh_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ni_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ni_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ni_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ni_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ni_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ni_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ni_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ni_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ni_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ni_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&xg_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&sh_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ni_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        xg_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        sh_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ni_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[645120],
                            *(double (*)[30720])&Spo2_Gray_Window[645120], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &xg_expl_temp, &sh_expl_temp, &ni_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = u_reshapes[0].f1->size[0];
      c_i = u_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = u_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = u_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = u_reshapes[0]
            .f1->data[i4 + u_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + u_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[22]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      nc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      nc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      nc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      nc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      nc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      nc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      nc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      nc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      nc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      nc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      cd_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      cd_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      cd_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      cd_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      cd_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      cd_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      cd_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      cd_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      cd_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      cd_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      td_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      td_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      td_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      td_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      td_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      td_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      td_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      td_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      td_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      td_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&nc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cd_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&td_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        nc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        cd_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        td_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[675840],
                            *(double (*)[30720])&Spo2_Seiz_Window[675840], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &nc_expl_temp, &cd_expl_temp, &td_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = v_reshapes[0].f1->size[0] * v_reshapes[0].f1->size[1];
      v_reshapes[0].f1->size[0] = 1;
      v_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(v_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        v_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      eh_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      eh_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      eh_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      eh_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      eh_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      eh_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      eh_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      eh_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      eh_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      eh_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      yh_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      yh_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      yh_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      yh_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      yh_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      yh_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      yh_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      yh_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      yh_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      yh_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ti_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ti_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ti_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ti_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ti_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ti_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ti_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ti_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ti_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ti_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&eh_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yh_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ti_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        eh_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        yh_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ti_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[675840],
                            *(double (*)[30720])&Spo2_Gray_Window[675840], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &eh_expl_temp, &yh_expl_temp, &ti_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = v_reshapes[0].f1->size[0];
      c_i = v_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = v_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = v_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = v_reshapes[0]
            .f1->data[i4 + v_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + v_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[23]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      rc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      rc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      rc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      rc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      rc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      rc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      rc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      rc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      rc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      rc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      hd_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      hd_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      hd_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      hd_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      hd_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      hd_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      hd_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      hd_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      hd_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      hd_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ae_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ae_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ae_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ae_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ae_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ae_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ae_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ae_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ae_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ae_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&rc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hd_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ae_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        rc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        hd_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ae_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[706560],
                            *(double (*)[30720])&Spo2_Seiz_Window[706560], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &rc_expl_temp, &hd_expl_temp, &ae_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = w_reshapes[0].f1->size[0] * w_reshapes[0].f1->size[1];
      w_reshapes[0].f1->size[0] = 1;
      w_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(w_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        w_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      kh_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      kh_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      kh_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      kh_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      kh_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      kh_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      kh_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      kh_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      kh_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      kh_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      fi_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      fi_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      fi_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      fi_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      fi_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      fi_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      fi_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      fi_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      fi_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      fi_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      aj_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      aj_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      aj_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      aj_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      aj_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      aj_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      aj_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      aj_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      aj_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      aj_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&kh_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fi_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&aj_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        kh_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        fi_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        aj_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[706560],
                            *(double (*)[30720])&Spo2_Gray_Window[706560], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &kh_expl_temp, &fi_expl_temp, &aj_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = w_reshapes[0].f1->size[0];
      c_i = w_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = w_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = w_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = w_reshapes[0]
            .f1->data[i4 + w_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + w_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[24]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      vc_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      vc_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      vc_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      vc_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      vc_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      vc_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      vc_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      vc_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      vc_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      vc_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      md_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      md_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      md_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      md_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      md_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      md_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      md_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      md_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      md_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      md_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ge_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ge_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ge_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ge_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ge_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ge_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ge_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ge_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ge_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ge_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&vc_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&md_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ge_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        vc_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        md_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ge_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[737280],
                            *(double (*)[30720])&Spo2_Seiz_Window[737280], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &vc_expl_temp, &md_expl_temp, &ge_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = x_reshapes[0].f1->size[0] * x_reshapes[0].f1->size[1];
      x_reshapes[0].f1->size[0] = 1;
      x_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(x_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        x_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      qh_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      qh_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      qh_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      qh_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      qh_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      qh_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      qh_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      qh_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      qh_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      qh_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      li_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      li_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      li_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      li_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      li_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      li_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      li_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      li_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      li_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      li_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      gj_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      gj_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      gj_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      gj_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      gj_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      gj_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      gj_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      gj_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      gj_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      gj_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&qh_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&li_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gj_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        qh_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        li_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        gj_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[737280],
                            *(double (*)[30720])&Spo2_Gray_Window[737280], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &qh_expl_temp, &li_expl_temp, &gj_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = x_reshapes[0].f1->size[0];
      c_i = x_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = x_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = x_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = x_reshapes[0]
            .f1->data[i4 + x_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + x_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[25]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ad_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ad_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ad_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ad_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ad_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ad_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ad_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ad_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ad_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ad_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      rd_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      rd_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      rd_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      rd_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      rd_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      rd_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      rd_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      rd_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      rd_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      rd_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      me_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      me_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      me_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      me_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      me_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      me_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      me_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      me_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      me_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      me_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ad_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rd_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&me_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ad_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        rd_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        me_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[768000],
                            *(double (*)[30720])&Spo2_Seiz_Window[768000], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ad_expl_temp, &rd_expl_temp, &me_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        u = (unsigned char)pred_label_size[1];
      } else {
        u = 0U;
      }

      i1 = y_reshapes[0].f1->size[0] * y_reshapes[0].f1->size[1];
      y_reshapes[0].f1->size[0] = 1;
      y_reshapes[0].f1->size[1] = u;
      emxEnsureCapacity_real_T(y_reshapes[0].f1, i1);
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        y_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      wh_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      wh_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      wh_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      wh_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      wh_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      wh_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      wh_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      wh_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      wh_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      wh_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ri_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ri_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ri_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ri_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ri_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ri_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ri_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ri_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ri_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ri_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      mj_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      mj_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      mj_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      mj_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      mj_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      mj_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      mj_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      mj_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      mj_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      mj_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&wh_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ri_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mj_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        wh_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ri_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        mj_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[768000],
                            *(double (*)[30720])&Spo2_Gray_Window[768000], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &wh_expl_temp, &ri_expl_temp, &mj_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = y_reshapes[0].f1->size[0];
      c_i = y_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = y_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = y_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = y_reshapes[0]
            .f1->data[i4 + y_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + y_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        u += sizes_idx_1;
      } else {
        u = 0U;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = u + sizes_idx_1;
      c_i = u;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + u] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[26]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      fd_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      fd_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      fd_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      fd_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      fd_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      fd_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      fd_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      fd_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      fd_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      fd_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      xd_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      xd_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      xd_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      xd_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      xd_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      xd_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      xd_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      xd_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      xd_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      xd_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      se_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      se_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      se_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      se_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      se_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      se_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      se_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      se_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      se_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      se_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&fd_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xd_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&se_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        fd_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        xd_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        se_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[798720],
                            *(double (*)[30720])&Spo2_Seiz_Window[798720], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &fd_expl_temp, &xd_expl_temp, &se_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ab_reshapes[0].f1->size[0] * ab_reshapes[0].f1->size[1];
      ab_reshapes[0].f1->size[0] = 1;
      ab_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ab_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ab_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      di_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      di_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      di_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      di_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      di_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      di_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      di_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      di_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      di_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      di_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      xi_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      xi_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      xi_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      xi_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      xi_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      xi_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      xi_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      xi_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      xi_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      xi_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      sj_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      sj_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      sj_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      sj_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      sj_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      sj_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      sj_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      sj_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      sj_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      sj_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&di_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xi_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&sj_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        di_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        xi_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        sj_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[798720],
                            *(double (*)[30720])&Spo2_Gray_Window[798720], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &di_expl_temp, &xi_expl_temp, &sj_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ab_reshapes[0].f1->size[0];
      c_i = ab_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ab_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ab_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ab_reshapes[0]
            .f1->data[i4 + ab_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ab_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[27]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      kd_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      kd_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      kd_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      kd_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      kd_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      kd_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      kd_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      kd_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      kd_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      kd_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ee_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ee_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ee_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ee_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ee_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ee_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ee_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ee_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ee_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ee_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ye_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ye_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ye_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ye_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ye_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ye_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ye_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ye_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ye_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ye_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&kd_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ee_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ye_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        kd_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ee_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ye_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[829440],
                            *(double (*)[30720])&Spo2_Seiz_Window[829440], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &kd_expl_temp, &ee_expl_temp, &ye_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = bb_reshapes[0].f1->size[0] * bb_reshapes[0].f1->size[1];
      bb_reshapes[0].f1->size[0] = 1;
      bb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(bb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        bb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ji_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ji_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ji_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ji_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ji_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ji_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ji_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ji_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ji_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ji_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ej_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ej_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ej_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ej_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ej_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ej_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ej_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ej_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ej_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ej_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      yj_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      yj_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      yj_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      yj_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      yj_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      yj_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      yj_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      yj_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      yj_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      yj_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ji_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ej_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yj_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ji_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ej_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        yj_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[829440],
                            *(double (*)[30720])&Spo2_Gray_Window[829440], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ji_expl_temp, &ej_expl_temp, &yj_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = bb_reshapes[0].f1->size[0];
      c_i = bb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = bb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = bb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = bb_reshapes[0]
            .f1->data[i4 + bb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + bb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[28]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      pd_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      pd_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      pd_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      pd_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      pd_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      pd_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      pd_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      pd_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      pd_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      pd_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ke_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ke_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ke_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ke_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ke_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ke_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ke_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ke_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ke_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ke_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ff_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ff_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ff_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ff_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ff_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ff_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ff_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ff_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ff_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ff_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&pd_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ke_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ff_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        pd_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ke_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ff_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[860160],
                            *(double (*)[30720])&Spo2_Seiz_Window[860160], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &pd_expl_temp, &ke_expl_temp, &ff_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = cb_reshapes[0].f1->size[0] * cb_reshapes[0].f1->size[1];
      cb_reshapes[0].f1->size[0] = 1;
      cb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(cb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        cb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      pi_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      pi_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      pi_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      pi_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      pi_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      pi_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      pi_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      pi_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      pi_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      pi_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      kj_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      kj_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      kj_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      kj_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      kj_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      kj_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      kj_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      kj_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      kj_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      kj_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      fk_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      fk_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      fk_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      fk_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      fk_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      fk_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      fk_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      fk_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      fk_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      fk_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&pi_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kj_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fk_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        pi_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        kj_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        fk_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[860160],
                            *(double (*)[30720])&Spo2_Gray_Window[860160], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &pi_expl_temp, &kj_expl_temp, &fk_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = cb_reshapes[0].f1->size[0];
      c_i = cb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = cb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = cb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = cb_reshapes[0]
            .f1->data[i4 + cb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + cb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[29]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      vd_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      vd_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      vd_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      vd_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      vd_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      vd_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      vd_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      vd_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      vd_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      vd_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      qe_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      qe_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      qe_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      qe_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      qe_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      qe_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      qe_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      qe_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      qe_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      qe_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      lf_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      lf_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      lf_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      lf_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      lf_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      lf_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      lf_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      lf_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      lf_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      lf_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&vd_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qe_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lf_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        vd_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        qe_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        lf_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[890880],
                            *(double (*)[30720])&Spo2_Seiz_Window[890880], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &vd_expl_temp, &qe_expl_temp, &lf_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = db_reshapes[0].f1->size[0] * db_reshapes[0].f1->size[1];
      db_reshapes[0].f1->size[0] = 1;
      db_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(db_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        db_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      vi_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      vi_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      vi_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      vi_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      vi_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      vi_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      vi_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      vi_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      vi_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      vi_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      qj_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      qj_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      qj_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      qj_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      qj_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      qj_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      qj_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      qj_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      qj_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      qj_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      lk_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      lk_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      lk_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      lk_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      lk_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      lk_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      lk_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      lk_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      lk_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      lk_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&vi_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qj_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lk_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        vi_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        qj_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        lk_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[890880],
                            *(double (*)[30720])&Spo2_Gray_Window[890880], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &vi_expl_temp, &qj_expl_temp, &lk_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = db_reshapes[0].f1->size[0];
      c_i = db_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = db_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = db_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = db_reshapes[0]
            .f1->data[i4 + db_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + db_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[30]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ce_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ce_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ce_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ce_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ce_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ce_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ce_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ce_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ce_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ce_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      we_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      we_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      we_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      we_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      we_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      we_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      we_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      we_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      we_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      we_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      rf_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      rf_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      rf_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      rf_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      rf_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      rf_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      rf_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      rf_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      rf_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      rf_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ce_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&we_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rf_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ce_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        we_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        rf_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[921600],
                            *(double (*)[30720])&Spo2_Seiz_Window[921600], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ce_expl_temp, &we_expl_temp, &rf_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = eb_reshapes[0].f1->size[0] * eb_reshapes[0].f1->size[1];
      eb_reshapes[0].f1->size[0] = 1;
      eb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(eb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        eb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      cj_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      cj_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      cj_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      cj_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      cj_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      cj_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      cj_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      cj_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      cj_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      cj_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      wj_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      wj_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      wj_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      wj_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      wj_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      wj_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      wj_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      wj_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      wj_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      wj_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      rk_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      rk_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      rk_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      rk_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      rk_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      rk_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      rk_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      rk_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      rk_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      rk_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&cj_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wj_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rk_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        cj_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        wj_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        rk_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[921600],
                            *(double (*)[30720])&Spo2_Gray_Window[921600], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &cj_expl_temp, &wj_expl_temp, &rk_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = eb_reshapes[0].f1->size[0];
      c_i = eb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = eb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = eb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = eb_reshapes[0]
            .f1->data[i4 + eb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + eb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[31]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ie_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ie_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ie_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ie_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ie_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ie_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ie_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ie_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ie_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ie_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      df_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      df_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      df_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      df_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      df_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      df_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      df_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      df_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      df_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      df_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      xf_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      xf_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      xf_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      xf_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      xf_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      xf_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      xf_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      xf_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      xf_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      xf_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ie_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&df_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xf_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ie_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        df_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        xf_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[952320],
                            *(double (*)[30720])&Spo2_Seiz_Window[952320], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ie_expl_temp, &df_expl_temp, &xf_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = fb_reshapes[0].f1->size[0] * fb_reshapes[0].f1->size[1];
      fb_reshapes[0].f1->size[0] = 1;
      fb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(fb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        fb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ij_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ij_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ij_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ij_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ij_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ij_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ij_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ij_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ij_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ij_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      dk_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      dk_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      dk_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      dk_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      dk_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      dk_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      dk_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      dk_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      dk_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      dk_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      xk_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      xk_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      xk_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      xk_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      xk_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      xk_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      xk_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      xk_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      xk_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      xk_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ij_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dk_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xk_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ij_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        dk_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        xk_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[952320],
                            *(double (*)[30720])&Spo2_Gray_Window[952320], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ij_expl_temp, &dk_expl_temp, &xk_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = fb_reshapes[0].f1->size[0];
      c_i = fb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = fb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = fb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = fb_reshapes[0]
            .f1->data[i4 + fb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + fb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[32]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      oe_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      oe_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      oe_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      oe_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      oe_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      oe_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      oe_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      oe_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      oe_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      oe_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      jf_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      jf_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      jf_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      jf_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      jf_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      jf_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      jf_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      jf_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      jf_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      jf_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      eg_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      eg_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      eg_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      eg_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      eg_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      eg_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      eg_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      eg_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      eg_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      eg_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&oe_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jf_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&eg_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        oe_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        jf_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        eg_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[983040],
                            *(double (*)[30720])&Spo2_Seiz_Window[983040], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &oe_expl_temp, &jf_expl_temp, &eg_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = gb_reshapes[0].f1->size[0] * gb_reshapes[0].f1->size[1];
      gb_reshapes[0].f1->size[0] = 1;
      gb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(gb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        gb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      oj_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      oj_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      oj_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      oj_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      oj_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      oj_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      oj_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      oj_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      oj_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      oj_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      jk_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      jk_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      jk_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      jk_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      jk_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      jk_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      jk_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      jk_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      jk_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      jk_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      el_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      el_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      el_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      el_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      el_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      el_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      el_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      el_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      el_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      el_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&oj_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jk_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&el_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        oj_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        jk_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        el_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[983040],
                            *(double (*)[30720])&Spo2_Gray_Window[983040], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &oj_expl_temp, &jk_expl_temp, &el_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = gb_reshapes[0].f1->size[0];
      c_i = gb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = gb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = gb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = gb_reshapes[0]
            .f1->data[i4 + gb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + gb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[33]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ue_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ue_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ue_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ue_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ue_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ue_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ue_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ue_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ue_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ue_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      pf_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      pf_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      pf_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      pf_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      pf_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      pf_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      pf_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      pf_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      pf_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      pf_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      kg_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      kg_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      kg_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      kg_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      kg_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      kg_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      kg_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      kg_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      kg_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      kg_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ue_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pf_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kg_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ue_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        pf_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        kg_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1013760],
                            *(double (*)[30720])&Spo2_Seiz_Window[1013760], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ue_expl_temp, &pf_expl_temp, &kg_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = hb_reshapes[0].f1->size[0] * hb_reshapes[0].f1->size[1];
      hb_reshapes[0].f1->size[0] = 1;
      hb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(hb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        hb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      uj_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      uj_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      uj_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      uj_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      uj_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      uj_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      uj_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      uj_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      uj_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      uj_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      pk_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      pk_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      pk_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      pk_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      pk_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      pk_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      pk_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      pk_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      pk_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      pk_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      kl_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      kl_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      kl_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      kl_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      kl_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      kl_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      kl_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      kl_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      kl_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      kl_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&uj_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pk_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kl_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        uj_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        pk_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        kl_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1013760],
                            *(double (*)[30720])&Spo2_Gray_Window[1013760], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &uj_expl_temp, &pk_expl_temp, &kl_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = hb_reshapes[0].f1->size[0];
      c_i = hb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = hb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = hb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = hb_reshapes[0]
            .f1->data[i4 + hb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + hb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[34]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      bf_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      bf_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      bf_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      bf_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      bf_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      bf_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      bf_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      bf_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      bf_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      bf_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      vf_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      vf_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      vf_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      vf_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      vf_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      vf_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      vf_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      vf_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      vf_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      vf_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      qg_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      qg_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      qg_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      qg_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      qg_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      qg_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      qg_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      qg_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      qg_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      qg_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&bf_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vf_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qg_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        bf_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        vf_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        qg_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1044480],
                            *(double (*)[30720])&Spo2_Seiz_Window[1044480], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &bf_expl_temp, &vf_expl_temp, &qg_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ib_reshapes[0].f1->size[0] * ib_reshapes[0].f1->size[1];
      ib_reshapes[0].f1->size[0] = 1;
      ib_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ib_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ib_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      bk_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      bk_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      bk_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      bk_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      bk_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      bk_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      bk_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      bk_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      bk_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      bk_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      vk_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      vk_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      vk_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      vk_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      vk_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      vk_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      vk_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      vk_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      vk_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      vk_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ql_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ql_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ql_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ql_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ql_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ql_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ql_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ql_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ql_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ql_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&bk_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vk_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ql_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        bk_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        vk_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ql_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1044480],
                            *(double (*)[30720])&Spo2_Gray_Window[1044480], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &bk_expl_temp, &vk_expl_temp, &ql_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ib_reshapes[0].f1->size[0];
      c_i = ib_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ib_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ib_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ib_reshapes[0]
            .f1->data[i4 + ib_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ib_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[35]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      hf_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      hf_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      hf_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      hf_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      hf_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      hf_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      hf_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      hf_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      hf_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      hf_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      cg_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      cg_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      cg_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      cg_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      cg_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      cg_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      cg_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      cg_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      cg_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      cg_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      wg_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      wg_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      wg_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      wg_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      wg_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      wg_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      wg_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      wg_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      wg_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      wg_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&hf_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cg_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wg_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        hf_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        cg_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        wg_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1075200],
                            *(double (*)[30720])&Spo2_Seiz_Window[1075200], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &hf_expl_temp, &cg_expl_temp, &wg_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = jb_reshapes[0].f1->size[0] * jb_reshapes[0].f1->size[1];
      jb_reshapes[0].f1->size[0] = 1;
      jb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(jb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        jb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      hk_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      hk_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      hk_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      hk_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      hk_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      hk_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      hk_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      hk_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      hk_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      hk_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      cl_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      cl_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      cl_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      cl_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      cl_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      cl_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      cl_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      cl_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      cl_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      cl_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      wl_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      wl_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      wl_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      wl_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      wl_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      wl_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      wl_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      wl_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      wl_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      wl_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&hk_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cl_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wl_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        hk_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        cl_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        wl_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1075200],
                            *(double (*)[30720])&Spo2_Gray_Window[1075200], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &hk_expl_temp, &cl_expl_temp, &wl_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = jb_reshapes[0].f1->size[0];
      c_i = jb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = jb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = jb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = jb_reshapes[0]
            .f1->data[i4 + jb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + jb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[36]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      nf_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      nf_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      nf_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      nf_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      nf_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      nf_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      nf_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      nf_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      nf_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      nf_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ig_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ig_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ig_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ig_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ig_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ig_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ig_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ig_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ig_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ig_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      dh_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      dh_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      dh_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      dh_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      dh_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      dh_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      dh_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      dh_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      dh_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      dh_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&nf_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ig_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dh_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        nf_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ig_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        dh_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1105920],
                            *(double (*)[30720])&Spo2_Seiz_Window[1105920], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &nf_expl_temp, &ig_expl_temp, &dh_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = kb_reshapes[0].f1->size[0] * kb_reshapes[0].f1->size[1];
      kb_reshapes[0].f1->size[0] = 1;
      kb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(kb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        kb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      nk_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      nk_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      nk_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      nk_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      nk_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      nk_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      nk_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      nk_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      nk_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      nk_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      il_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      il_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      il_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      il_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      il_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      il_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      il_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      il_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      il_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      il_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      dm_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      dm_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      dm_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      dm_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      dm_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      dm_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      dm_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      dm_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      dm_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      dm_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&nk_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&il_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dm_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        nk_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        il_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        dm_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1105920],
                            *(double (*)[30720])&Spo2_Gray_Window[1105920], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &nk_expl_temp, &il_expl_temp, &dm_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = kb_reshapes[0].f1->size[0];
      c_i = kb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = kb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = kb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = kb_reshapes[0]
            .f1->data[i4 + kb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + kb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[37]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      tf_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      tf_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      tf_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      tf_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      tf_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      tf_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      tf_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      tf_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      tf_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      tf_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      og_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      og_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      og_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      og_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      og_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      og_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      og_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      og_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      og_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      og_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      jh_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      jh_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      jh_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      jh_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      jh_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      jh_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      jh_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      jh_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      jh_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      jh_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&tf_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&og_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jh_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        tf_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        og_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        jh_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1136640],
                            *(double (*)[30720])&Spo2_Seiz_Window[1136640], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &tf_expl_temp, &og_expl_temp, &jh_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = lb_reshapes[0].f1->size[0] * lb_reshapes[0].f1->size[1];
      lb_reshapes[0].f1->size[0] = 1;
      lb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(lb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        lb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      tk_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      tk_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      tk_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      tk_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      tk_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      tk_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      tk_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      tk_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      tk_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      tk_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ol_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ol_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ol_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ol_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ol_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ol_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ol_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ol_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ol_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ol_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      jm_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      jm_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      jm_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      jm_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      jm_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      jm_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      jm_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      jm_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      jm_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      jm_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&tk_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ol_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jm_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        tk_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ol_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        jm_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1136640],
                            *(double (*)[30720])&Spo2_Gray_Window[1136640], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &tk_expl_temp, &ol_expl_temp, &jm_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = lb_reshapes[0].f1->size[0];
      c_i = lb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = lb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = lb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = lb_reshapes[0]
            .f1->data[i4 + lb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + lb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[38]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ag_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ag_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ag_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ag_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ag_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ag_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ag_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ag_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ag_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ag_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ug_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ug_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ug_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ug_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ug_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ug_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ug_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ug_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ug_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ug_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ph_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ph_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ph_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ph_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ph_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ph_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ph_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ph_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ph_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ph_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ag_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ug_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ph_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ag_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ug_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ph_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1167360],
                            *(double (*)[30720])&Spo2_Seiz_Window[1167360], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ag_expl_temp, &ug_expl_temp, &ph_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = mb_reshapes[0].f1->size[0] * mb_reshapes[0].f1->size[1];
      mb_reshapes[0].f1->size[0] = 1;
      mb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(mb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        mb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      al_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      al_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      al_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      al_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      al_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      al_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      al_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      al_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      al_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      al_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ul_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ul_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ul_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ul_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ul_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ul_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ul_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ul_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ul_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ul_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      pm_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      pm_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      pm_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      pm_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      pm_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      pm_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      pm_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      pm_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      pm_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      pm_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&al_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ul_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pm_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        al_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ul_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        pm_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1167360],
                            *(double (*)[30720])&Spo2_Gray_Window[1167360], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &al_expl_temp, &ul_expl_temp, &pm_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = mb_reshapes[0].f1->size[0];
      c_i = mb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = mb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = mb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = mb_reshapes[0]
            .f1->data[i4 + mb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + mb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[39]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      gg_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      gg_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      gg_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      gg_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      gg_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      gg_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      gg_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      gg_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      gg_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      gg_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      bh_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      bh_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      bh_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      bh_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      bh_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      bh_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      bh_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      bh_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      bh_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      bh_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      vh_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      vh_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      vh_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      vh_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      vh_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      vh_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      vh_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      vh_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      vh_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      vh_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&gg_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bh_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vh_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        gg_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        bh_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        vh_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1198080],
                            *(double (*)[30720])&Spo2_Seiz_Window[1198080], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &gg_expl_temp, &bh_expl_temp, &vh_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = nb_reshapes[0].f1->size[0] * nb_reshapes[0].f1->size[1];
      nb_reshapes[0].f1->size[0] = 1;
      nb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(nb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        nb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      gl_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      gl_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      gl_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      gl_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      gl_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      gl_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      gl_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      gl_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      gl_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      gl_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      bm_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      bm_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      bm_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      bm_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      bm_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      bm_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      bm_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      bm_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      bm_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      bm_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      vm_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      vm_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      vm_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      vm_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      vm_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      vm_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      vm_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      vm_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      vm_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      vm_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&gl_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bm_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vm_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        gl_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        bm_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        vm_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1198080],
                            *(double (*)[30720])&Spo2_Gray_Window[1198080], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &gl_expl_temp, &bm_expl_temp, &vm_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = nb_reshapes[0].f1->size[0];
      c_i = nb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = nb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = nb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = nb_reshapes[0]
            .f1->data[i4 + nb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + nb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[40]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      mg_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      mg_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      mg_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      mg_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      mg_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      mg_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      mg_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      mg_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      mg_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      mg_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      hh_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      hh_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      hh_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      hh_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      hh_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      hh_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      hh_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      hh_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      hh_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      hh_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ci_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ci_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ci_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ci_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ci_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ci_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ci_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ci_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ci_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ci_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&mg_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hh_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ci_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        mg_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        hh_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ci_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1228800],
                            *(double (*)[30720])&Spo2_Seiz_Window[1228800], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &mg_expl_temp, &hh_expl_temp, &ci_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ob_reshapes[0].f1->size[0] * ob_reshapes[0].f1->size[1];
      ob_reshapes[0].f1->size[0] = 1;
      ob_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ob_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ob_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ml_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ml_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ml_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ml_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ml_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ml_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ml_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ml_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ml_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ml_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      hm_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      hm_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      hm_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      hm_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      hm_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      hm_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      hm_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      hm_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      hm_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      hm_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      cn_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      cn_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      cn_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      cn_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      cn_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      cn_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      cn_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      cn_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      cn_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      cn_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ml_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hm_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cn_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ml_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        hm_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        cn_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1228800],
                            *(double (*)[30720])&Spo2_Gray_Window[1228800], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ml_expl_temp, &hm_expl_temp, &cn_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ob_reshapes[0].f1->size[0];
      c_i = ob_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ob_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ob_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ob_reshapes[0]
            .f1->data[i4 + ob_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ob_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[41]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      sg_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      sg_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      sg_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      sg_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      sg_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      sg_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      sg_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      sg_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      sg_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      sg_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      nh_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      nh_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      nh_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      nh_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      nh_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      nh_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      nh_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      nh_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      nh_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      nh_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ii_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ii_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ii_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ii_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ii_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ii_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ii_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ii_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ii_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ii_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&sg_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&nh_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ii_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        sg_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        nh_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ii_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1259520],
                            *(double (*)[30720])&Spo2_Seiz_Window[1259520], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &sg_expl_temp, &nh_expl_temp, &ii_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = pb_reshapes[0].f1->size[0] * pb_reshapes[0].f1->size[1];
      pb_reshapes[0].f1->size[0] = 1;
      pb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(pb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        pb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      sl_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      sl_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      sl_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      sl_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      sl_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      sl_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      sl_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      sl_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      sl_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      sl_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      nm_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      nm_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      nm_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      nm_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      nm_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      nm_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      nm_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      nm_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      nm_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      nm_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      in_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      in_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      in_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      in_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      in_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      in_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      in_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      in_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      in_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      in_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&sl_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&nm_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&in_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        sl_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        nm_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        in_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1259520],
                            *(double (*)[30720])&Spo2_Gray_Window[1259520], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &sl_expl_temp, &nm_expl_temp, &in_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = pb_reshapes[0].f1->size[0];
      c_i = pb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = pb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = pb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = pb_reshapes[0]
            .f1->data[i4 + pb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + pb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[42]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      yg_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      yg_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      yg_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      yg_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      yg_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      yg_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      yg_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      yg_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      yg_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      yg_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      th_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      th_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      th_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      th_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      th_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      th_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      th_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      th_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      th_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      th_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      oi_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      oi_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      oi_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      oi_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      oi_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      oi_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      oi_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      oi_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      oi_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      oi_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&yg_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&th_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&oi_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        yg_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        th_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        oi_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1290240],
                            *(double (*)[30720])&Spo2_Seiz_Window[1290240], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &yg_expl_temp, &th_expl_temp, &oi_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = qb_reshapes[0].f1->size[0] * qb_reshapes[0].f1->size[1];
      qb_reshapes[0].f1->size[0] = 1;
      qb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(qb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        qb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      yl_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      yl_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      yl_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      yl_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      yl_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      yl_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      yl_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      yl_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      yl_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      yl_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      tm_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      tm_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      tm_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      tm_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      tm_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      tm_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      tm_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      tm_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      tm_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      tm_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      on_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      on_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      on_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      on_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      on_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      on_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      on_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      on_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      on_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      on_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&yl_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&tm_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&on_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        yl_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        tm_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        on_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1290240],
                            *(double (*)[30720])&Spo2_Gray_Window[1290240], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &yl_expl_temp, &tm_expl_temp, &on_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = qb_reshapes[0].f1->size[0];
      c_i = qb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = qb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = qb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = qb_reshapes[0]
            .f1->data[i4 + qb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + qb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[43]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      fh_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      fh_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      fh_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      fh_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      fh_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      fh_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      fh_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      fh_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      fh_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      fh_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ai_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ai_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ai_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ai_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ai_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ai_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ai_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ai_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ai_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ai_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ui_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ui_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ui_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ui_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ui_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ui_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ui_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ui_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ui_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ui_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&fh_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ai_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ui_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        fh_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ai_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ui_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1320960],
                            *(double (*)[30720])&Spo2_Seiz_Window[1320960], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &fh_expl_temp, &ai_expl_temp, &ui_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = rb_reshapes[0].f1->size[0] * rb_reshapes[0].f1->size[1];
      rb_reshapes[0].f1->size[0] = 1;
      rb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(rb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        rb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      fm_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      fm_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      fm_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      fm_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      fm_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      fm_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      fm_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      fm_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      fm_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      fm_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      an_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      an_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      an_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      an_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      an_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      an_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      an_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      an_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      an_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      an_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      un_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      un_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      un_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      un_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      un_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      un_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      un_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      un_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      un_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      un_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&fm_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&an_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&un_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        fm_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        an_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        un_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1320960],
                            *(double (*)[30720])&Spo2_Gray_Window[1320960], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &fm_expl_temp, &an_expl_temp, &un_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = rb_reshapes[0].f1->size[0];
      c_i = rb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = rb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = rb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = rb_reshapes[0]
            .f1->data[i4 + rb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + rb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[44]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      lh_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      lh_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      lh_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      lh_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      lh_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      lh_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      lh_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      lh_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      lh_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      lh_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      gi_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      gi_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      gi_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      gi_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      gi_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      gi_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      gi_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      gi_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      gi_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      gi_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      bj_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      bj_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      bj_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      bj_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      bj_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      bj_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      bj_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      bj_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      bj_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      bj_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&lh_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gi_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bj_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        lh_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        gi_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        bj_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1351680],
                            *(double (*)[30720])&Spo2_Seiz_Window[1351680], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &lh_expl_temp, &gi_expl_temp, &bj_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = sb_reshapes[0].f1->size[0] * sb_reshapes[0].f1->size[1];
      sb_reshapes[0].f1->size[0] = 1;
      sb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(sb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        sb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      lm_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      lm_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      lm_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      lm_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      lm_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      lm_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      lm_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      lm_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      lm_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      lm_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      gn_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      gn_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      gn_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      gn_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      gn_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      gn_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      gn_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      gn_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      gn_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      gn_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      bo_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      bo_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      bo_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      bo_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      bo_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      bo_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      bo_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      bo_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      bo_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      bo_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&lm_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gn_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bo_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        lm_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        gn_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        bo_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1351680],
                            *(double (*)[30720])&Spo2_Gray_Window[1351680], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &lm_expl_temp, &gn_expl_temp, &bo_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = sb_reshapes[0].f1->size[0];
      c_i = sb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = sb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = sb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = sb_reshapes[0]
            .f1->data[i4 + sb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + sb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[45]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      rh_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      rh_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      rh_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      rh_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      rh_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      rh_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      rh_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      rh_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      rh_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      rh_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      mi_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      mi_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      mi_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      mi_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      mi_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      mi_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      mi_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      mi_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      mi_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      mi_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      hj_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      hj_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      hj_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      hj_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      hj_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      hj_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      hj_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      hj_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      hj_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      hj_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&rh_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mi_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hj_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        rh_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        mi_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        hj_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1382400],
                            *(double (*)[30720])&Spo2_Seiz_Window[1382400], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &rh_expl_temp, &mi_expl_temp, &hj_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = tb_reshapes[0].f1->size[0] * tb_reshapes[0].f1->size[1];
      tb_reshapes[0].f1->size[0] = 1;
      tb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(tb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        tb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      rm_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      rm_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      rm_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      rm_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      rm_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      rm_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      rm_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      rm_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      rm_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      rm_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      mn_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      mn_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      mn_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      mn_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      mn_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      mn_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      mn_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      mn_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      mn_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      mn_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ho_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ho_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ho_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ho_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ho_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ho_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ho_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ho_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ho_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ho_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&rm_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mn_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ho_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        rm_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        mn_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ho_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1382400],
                            *(double (*)[30720])&Spo2_Gray_Window[1382400], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &rm_expl_temp, &mn_expl_temp, &ho_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = tb_reshapes[0].f1->size[0];
      c_i = tb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = tb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = tb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = tb_reshapes[0]
            .f1->data[i4 + tb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + tb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[46]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      xh_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      xh_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      xh_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      xh_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      xh_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      xh_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      xh_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      xh_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      xh_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      xh_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      si_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      si_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      si_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      si_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      si_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      si_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      si_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      si_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      si_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      si_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      nj_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      nj_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      nj_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      nj_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      nj_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      nj_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      nj_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      nj_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      nj_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      nj_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&xh_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&si_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&nj_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        xh_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        si_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        nj_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1413120],
                            *(double (*)[30720])&Spo2_Seiz_Window[1413120], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &xh_expl_temp, &si_expl_temp, &nj_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ub_reshapes[0].f1->size[0] * ub_reshapes[0].f1->size[1];
      ub_reshapes[0].f1->size[0] = 1;
      ub_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ub_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ub_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      xm_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      xm_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      xm_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      xm_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      xm_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      xm_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      xm_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      xm_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      xm_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      xm_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      sn_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      sn_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      sn_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      sn_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      sn_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      sn_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      sn_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      sn_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      sn_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      sn_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      no_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      no_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      no_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      no_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      no_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      no_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      no_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      no_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      no_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      no_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&xm_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&sn_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&no_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        xm_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        sn_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        no_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1413120],
                            *(double (*)[30720])&Spo2_Gray_Window[1413120], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &xm_expl_temp, &sn_expl_temp, &no_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ub_reshapes[0].f1->size[0];
      c_i = ub_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ub_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ub_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ub_reshapes[0]
            .f1->data[i4 + ub_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ub_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[47]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ei_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ei_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ei_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ei_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ei_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ei_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ei_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ei_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ei_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ei_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      yi_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      yi_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      yi_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      yi_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      yi_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      yi_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      yi_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      yi_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      yi_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      yi_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      tj_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      tj_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      tj_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      tj_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      tj_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      tj_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      tj_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      tj_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      tj_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      tj_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ei_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yi_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&tj_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ei_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        yi_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        tj_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1443840],
                            *(double (*)[30720])&Spo2_Seiz_Window[1443840], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ei_expl_temp, &yi_expl_temp, &tj_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = vb_reshapes[0].f1->size[0] * vb_reshapes[0].f1->size[1];
      vb_reshapes[0].f1->size[0] = 1;
      vb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(vb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        vb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      en_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      en_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      en_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      en_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      en_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      en_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      en_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      en_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      en_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      en_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      yn_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      yn_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      yn_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      yn_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      yn_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      yn_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      yn_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      yn_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      yn_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      yn_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      to_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      to_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      to_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      to_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      to_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      to_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      to_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      to_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      to_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      to_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&en_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yn_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&to_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        en_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        yn_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        to_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1443840],
                            *(double (*)[30720])&Spo2_Gray_Window[1443840], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &en_expl_temp, &yn_expl_temp, &to_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = vb_reshapes[0].f1->size[0];
      c_i = vb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = vb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = vb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = vb_reshapes[0]
            .f1->data[i4 + vb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + vb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[48]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ki_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ki_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ki_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ki_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ki_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ki_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ki_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ki_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ki_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ki_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      fj_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      fj_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      fj_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      fj_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      fj_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      fj_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      fj_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      fj_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      fj_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      fj_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ak_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ak_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ak_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ak_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ak_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ak_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ak_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ak_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ak_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ak_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ki_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fj_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ak_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ki_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        fj_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ak_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1474560],
                            *(double (*)[30720])&Spo2_Seiz_Window[1474560], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ki_expl_temp, &fj_expl_temp, &ak_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = wb_reshapes[0].f1->size[0] * wb_reshapes[0].f1->size[1];
      wb_reshapes[0].f1->size[0] = 1;
      wb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(wb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        wb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      kn_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      kn_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      kn_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      kn_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      kn_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      kn_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      kn_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      kn_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      kn_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      kn_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      fo_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      fo_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      fo_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      fo_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      fo_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      fo_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      fo_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      fo_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      fo_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      fo_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ap_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ap_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ap_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ap_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ap_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ap_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ap_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ap_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ap_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ap_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&kn_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fo_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ap_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        kn_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        fo_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ap_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1474560],
                            *(double (*)[30720])&Spo2_Gray_Window[1474560], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &kn_expl_temp, &fo_expl_temp, &ap_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = wb_reshapes[0].f1->size[0];
      c_i = wb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = wb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = wb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = wb_reshapes[0]
            .f1->data[i4 + wb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + wb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[49]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      qi_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      qi_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      qi_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      qi_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      qi_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      qi_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      qi_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      qi_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      qi_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      qi_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      lj_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      lj_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      lj_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      lj_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      lj_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      lj_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      lj_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      lj_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      lj_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      lj_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      gk_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      gk_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      gk_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      gk_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      gk_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      gk_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      gk_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      gk_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      gk_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      gk_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&qi_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lj_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gk_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        qi_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        lj_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        gk_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1505280],
                            *(double (*)[30720])&Spo2_Seiz_Window[1505280], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &qi_expl_temp, &lj_expl_temp, &gk_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = xb_reshapes[0].f1->size[0] * xb_reshapes[0].f1->size[1];
      xb_reshapes[0].f1->size[0] = 1;
      xb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(xb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        xb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      qn_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      qn_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      qn_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      qn_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      qn_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      qn_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      qn_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      qn_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      qn_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      qn_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      lo_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      lo_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      lo_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      lo_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      lo_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      lo_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      lo_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      lo_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      lo_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      lo_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      gp_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      gp_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      gp_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      gp_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      gp_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      gp_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      gp_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      gp_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      gp_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      gp_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&qn_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lo_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gp_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        qn_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        lo_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        gp_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1505280],
                            *(double (*)[30720])&Spo2_Gray_Window[1505280], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &qn_expl_temp, &lo_expl_temp, &gp_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = xb_reshapes[0].f1->size[0];
      c_i = xb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = xb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = xb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = xb_reshapes[0]
            .f1->data[i4 + xb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + xb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[50]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      wi_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      wi_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      wi_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      wi_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      wi_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      wi_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      wi_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      wi_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      wi_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      wi_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      rj_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      rj_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      rj_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      rj_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      rj_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      rj_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      rj_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      rj_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      rj_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      rj_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      mk_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      mk_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      mk_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      mk_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      mk_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      mk_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      mk_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      mk_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      mk_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      mk_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&wi_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rj_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mk_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        wi_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        rj_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        mk_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1536000],
                            *(double (*)[30720])&Spo2_Seiz_Window[1536000], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &wi_expl_temp, &rj_expl_temp, &mk_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = yb_reshapes[0].f1->size[0] * yb_reshapes[0].f1->size[1];
      yb_reshapes[0].f1->size[0] = 1;
      yb_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(yb_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        yb_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      wn_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      wn_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      wn_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      wn_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      wn_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      wn_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      wn_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      wn_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      wn_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      wn_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ro_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ro_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ro_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ro_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ro_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ro_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ro_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ro_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ro_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ro_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      mp_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      mp_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      mp_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      mp_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      mp_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      mp_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      mp_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      mp_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      mp_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      mp_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&wn_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ro_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mp_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        wn_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ro_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        mp_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1536000],
                            *(double (*)[30720])&Spo2_Gray_Window[1536000], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &wn_expl_temp, &ro_expl_temp, &mp_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = yb_reshapes[0].f1->size[0];
      c_i = yb_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = yb_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = yb_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = yb_reshapes[0]
            .f1->data[i4 + yb_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + yb_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[51]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      dj_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      dj_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      dj_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      dj_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      dj_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      dj_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      dj_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      dj_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      dj_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      dj_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      xj_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      xj_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      xj_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      xj_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      xj_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      xj_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      xj_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      xj_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      xj_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      xj_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      sk_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      sk_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      sk_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      sk_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      sk_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      sk_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      sk_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      sk_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      sk_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      sk_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&dj_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xj_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&sk_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        dj_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        xj_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        sk_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1566720],
                            *(double (*)[30720])&Spo2_Seiz_Window[1566720], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &dj_expl_temp, &xj_expl_temp, &sk_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ac_reshapes[0].f1->size[0] * ac_reshapes[0].f1->size[1];
      ac_reshapes[0].f1->size[0] = 1;
      ac_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ac_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ac_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      do_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      do_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      do_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      do_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      do_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      do_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      do_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      do_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      do_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      do_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      xo_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      xo_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      xo_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      xo_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      xo_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      xo_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      xo_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      xo_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      xo_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      xo_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      sp_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      sp_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      sp_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      sp_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      sp_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      sp_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      sp_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      sp_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      sp_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      sp_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&do_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xo_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&sp_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        do_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        xo_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        sp_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1566720],
                            *(double (*)[30720])&Spo2_Gray_Window[1566720], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &do_expl_temp, &xo_expl_temp, &sp_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ac_reshapes[0].f1->size[0];
      c_i = ac_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ac_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ac_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ac_reshapes[0]
            .f1->data[i4 + ac_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ac_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[52]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      jj_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      jj_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      jj_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      jj_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      jj_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      jj_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      jj_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      jj_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      jj_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      jj_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ek_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ek_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ek_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ek_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ek_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ek_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ek_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ek_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ek_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ek_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      yk_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      yk_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      yk_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      yk_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      yk_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      yk_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      yk_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      yk_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      yk_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      yk_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&jj_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ek_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yk_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        jj_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ek_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        yk_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1597440],
                            *(double (*)[30720])&Spo2_Seiz_Window[1597440], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &jj_expl_temp, &ek_expl_temp, &yk_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = bc_reshapes[0].f1->size[0] * bc_reshapes[0].f1->size[1];
      bc_reshapes[0].f1->size[0] = 1;
      bc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(bc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        bc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      jo_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      jo_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      jo_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      jo_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      jo_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      jo_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      jo_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      jo_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      jo_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      jo_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ep_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ep_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ep_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ep_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ep_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ep_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ep_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ep_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ep_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ep_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      yp_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      yp_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      yp_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      yp_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      yp_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      yp_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      yp_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      yp_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      yp_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      yp_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&jo_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ep_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yp_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        jo_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ep_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        yp_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1597440],
                            *(double (*)[30720])&Spo2_Gray_Window[1597440], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &jo_expl_temp, &ep_expl_temp, &yp_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = bc_reshapes[0].f1->size[0];
      c_i = bc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = bc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = bc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = bc_reshapes[0]
            .f1->data[i4 + bc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + bc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[53]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      pj_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      pj_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      pj_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      pj_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      pj_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      pj_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      pj_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      pj_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      pj_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      pj_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      kk_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      kk_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      kk_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      kk_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      kk_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      kk_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      kk_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      kk_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      kk_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      kk_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      fl_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      fl_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      fl_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      fl_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      fl_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      fl_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      fl_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      fl_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      fl_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      fl_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&pj_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kk_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fl_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        pj_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        kk_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        fl_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1628160],
                            *(double (*)[30720])&Spo2_Seiz_Window[1628160], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &pj_expl_temp, &kk_expl_temp, &fl_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = cc_reshapes[0].f1->size[0] * cc_reshapes[0].f1->size[1];
      cc_reshapes[0].f1->size[0] = 1;
      cc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(cc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        cc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      po_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      po_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      po_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      po_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      po_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      po_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      po_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      po_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      po_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      po_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      kp_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      kp_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      kp_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      kp_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      kp_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      kp_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      kp_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      kp_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      kp_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      kp_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      fq_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      fq_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      fq_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      fq_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      fq_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      fq_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      fq_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      fq_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      fq_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      fq_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&po_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kp_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fq_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        po_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        kp_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        fq_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1628160],
                            *(double (*)[30720])&Spo2_Gray_Window[1628160], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &po_expl_temp, &kp_expl_temp, &fq_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = cc_reshapes[0].f1->size[0];
      c_i = cc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = cc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = cc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = cc_reshapes[0]
            .f1->data[i4 + cc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + cc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[54]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      vj_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      vj_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      vj_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      vj_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      vj_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      vj_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      vj_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      vj_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      vj_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      vj_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      qk_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      qk_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      qk_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      qk_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      qk_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      qk_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      qk_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      qk_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      qk_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      qk_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ll_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ll_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ll_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ll_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ll_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ll_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ll_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ll_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ll_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ll_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&vj_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qk_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ll_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        vj_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        qk_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ll_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1658880],
                            *(double (*)[30720])&Spo2_Seiz_Window[1658880], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &vj_expl_temp, &qk_expl_temp, &ll_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = dc_reshapes[0].f1->size[0] * dc_reshapes[0].f1->size[1];
      dc_reshapes[0].f1->size[0] = 1;
      dc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(dc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        dc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      vo_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      vo_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      vo_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      vo_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      vo_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      vo_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      vo_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      vo_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      vo_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      vo_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      qp_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      qp_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      qp_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      qp_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      qp_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      qp_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      qp_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      qp_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      qp_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      qp_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      lq_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      lq_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      lq_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      lq_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      lq_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      lq_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      lq_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      lq_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      lq_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      lq_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&vo_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qp_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lq_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        vo_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        qp_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        lq_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1658880],
                            *(double (*)[30720])&Spo2_Gray_Window[1658880], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &vo_expl_temp, &qp_expl_temp, &lq_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = dc_reshapes[0].f1->size[0];
      c_i = dc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = dc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = dc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = dc_reshapes[0]
            .f1->data[i4 + dc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + dc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[55]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ck_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ck_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ck_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ck_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ck_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ck_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ck_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ck_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ck_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ck_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      wk_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      wk_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      wk_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      wk_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      wk_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      wk_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      wk_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      wk_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      wk_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      wk_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      rl_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      rl_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      rl_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      rl_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      rl_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      rl_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      rl_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      rl_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      rl_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      rl_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ck_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wk_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rl_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ck_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        wk_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        rl_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1689600],
                            *(double (*)[30720])&Spo2_Seiz_Window[1689600], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ck_expl_temp, &wk_expl_temp, &rl_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ec_reshapes[0].f1->size[0] * ec_reshapes[0].f1->size[1];
      ec_reshapes[0].f1->size[0] = 1;
      ec_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ec_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ec_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      cp_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      cp_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      cp_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      cp_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      cp_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      cp_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      cp_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      cp_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      cp_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      cp_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      wp_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      wp_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      wp_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      wp_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      wp_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      wp_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      wp_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      wp_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      wp_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      wp_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      rq_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      rq_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      rq_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      rq_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      rq_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      rq_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      rq_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      rq_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      rq_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      rq_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&cp_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wp_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rq_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        cp_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        wp_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        rq_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1689600],
                            *(double (*)[30720])&Spo2_Gray_Window[1689600], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &cp_expl_temp, &wp_expl_temp, &rq_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ec_reshapes[0].f1->size[0];
      c_i = ec_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ec_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ec_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ec_reshapes[0]
            .f1->data[i4 + ec_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ec_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[56]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ik_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ik_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ik_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ik_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ik_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ik_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ik_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ik_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ik_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ik_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      dl_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      dl_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      dl_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      dl_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      dl_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      dl_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      dl_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      dl_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      dl_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      dl_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      xl_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      xl_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      xl_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      xl_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      xl_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      xl_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      xl_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      xl_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      xl_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      xl_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ik_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dl_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xl_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ik_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        dl_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        xl_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1720320],
                            *(double (*)[30720])&Spo2_Seiz_Window[1720320], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ik_expl_temp, &dl_expl_temp, &xl_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = fc_reshapes[0].f1->size[0] * fc_reshapes[0].f1->size[1];
      fc_reshapes[0].f1->size[0] = 1;
      fc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(fc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        fc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ip_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ip_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ip_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ip_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ip_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ip_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ip_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ip_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ip_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ip_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      dq_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      dq_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      dq_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      dq_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      dq_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      dq_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      dq_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      dq_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      dq_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      dq_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      xq_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      xq_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      xq_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      xq_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      xq_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      xq_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      xq_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      xq_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      xq_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      xq_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ip_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dq_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xq_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ip_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        dq_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        xq_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1720320],
                            *(double (*)[30720])&Spo2_Gray_Window[1720320], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ip_expl_temp, &dq_expl_temp, &xq_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = fc_reshapes[0].f1->size[0];
      c_i = fc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = fc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = fc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = fc_reshapes[0]
            .f1->data[i4 + fc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + fc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[57]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ok_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ok_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ok_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ok_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ok_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ok_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ok_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ok_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ok_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ok_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      jl_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      jl_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      jl_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      jl_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      jl_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      jl_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      jl_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      jl_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      jl_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      jl_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      em_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      em_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      em_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      em_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      em_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      em_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      em_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      em_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      em_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      em_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ok_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jl_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&em_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ok_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        jl_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        em_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1751040],
                            *(double (*)[30720])&Spo2_Seiz_Window[1751040], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ok_expl_temp, &jl_expl_temp, &em_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = gc_reshapes[0].f1->size[0] * gc_reshapes[0].f1->size[1];
      gc_reshapes[0].f1->size[0] = 1;
      gc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(gc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        gc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      op_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      op_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      op_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      op_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      op_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      op_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      op_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      op_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      op_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      op_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      jq_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      jq_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      jq_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      jq_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      jq_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      jq_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      jq_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      jq_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      jq_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      jq_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      er_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      er_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      er_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      er_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      er_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      er_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      er_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      er_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      er_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      er_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&op_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jq_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&er_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        op_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        jq_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        er_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1751040],
                            *(double (*)[30720])&Spo2_Gray_Window[1751040], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &op_expl_temp, &jq_expl_temp, &er_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = gc_reshapes[0].f1->size[0];
      c_i = gc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = gc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = gc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = gc_reshapes[0]
            .f1->data[i4 + gc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + gc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[58]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      uk_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      uk_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      uk_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      uk_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      uk_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      uk_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      uk_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      uk_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      uk_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      uk_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      pl_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      pl_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      pl_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      pl_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      pl_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      pl_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      pl_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      pl_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      pl_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      pl_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      km_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      km_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      km_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      km_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      km_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      km_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      km_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      km_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      km_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      km_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&uk_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pl_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&km_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        uk_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        pl_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        km_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1781760],
                            *(double (*)[30720])&Spo2_Seiz_Window[1781760], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &uk_expl_temp, &pl_expl_temp, &km_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = hc_reshapes[0].f1->size[0] * hc_reshapes[0].f1->size[1];
      hc_reshapes[0].f1->size[0] = 1;
      hc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(hc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        hc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      up_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      up_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      up_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      up_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      up_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      up_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      up_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      up_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      up_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      up_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      pq_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      pq_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      pq_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      pq_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      pq_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      pq_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      pq_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      pq_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      pq_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      pq_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      kr_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      kr_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      kr_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      kr_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      kr_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      kr_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      kr_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      kr_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      kr_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      kr_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&up_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pq_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kr_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        up_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        pq_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        kr_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1781760],
                            *(double (*)[30720])&Spo2_Gray_Window[1781760], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &up_expl_temp, &pq_expl_temp, &kr_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = hc_reshapes[0].f1->size[0];
      c_i = hc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = hc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = hc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = hc_reshapes[0]
            .f1->data[i4 + hc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + hc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[59]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      bl_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      bl_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      bl_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      bl_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      bl_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      bl_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      bl_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      bl_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      bl_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      bl_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      vl_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      vl_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      vl_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      vl_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      vl_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      vl_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      vl_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      vl_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      vl_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      vl_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      qm_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      qm_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      qm_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      qm_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      qm_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      qm_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      qm_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      qm_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      qm_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      qm_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&bl_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vl_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qm_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        bl_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        vl_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        qm_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1812480],
                            *(double (*)[30720])&Spo2_Seiz_Window[1812480], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &bl_expl_temp, &vl_expl_temp, &qm_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ic_reshapes[0].f1->size[0] * ic_reshapes[0].f1->size[1];
      ic_reshapes[0].f1->size[0] = 1;
      ic_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ic_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ic_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      bq_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      bq_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      bq_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      bq_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      bq_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      bq_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      bq_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      bq_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      bq_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      bq_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      vq_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      vq_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      vq_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      vq_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      vq_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      vq_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      vq_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      vq_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      vq_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      vq_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      qr_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      qr_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      qr_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      qr_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      qr_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      qr_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      qr_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      qr_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      qr_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      qr_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&bq_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vq_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qr_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        bq_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        vq_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        qr_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1812480],
                            *(double (*)[30720])&Spo2_Gray_Window[1812480], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &bq_expl_temp, &vq_expl_temp, &qr_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ic_reshapes[0].f1->size[0];
      c_i = ic_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ic_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ic_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ic_reshapes[0]
            .f1->data[i4 + ic_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ic_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[60]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      hl_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      hl_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      hl_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      hl_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      hl_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      hl_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      hl_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      hl_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      hl_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      hl_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      cm_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      cm_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      cm_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      cm_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      cm_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      cm_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      cm_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      cm_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      cm_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      cm_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      wm_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      wm_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      wm_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      wm_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      wm_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      wm_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      wm_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      wm_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      wm_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      wm_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&hl_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cm_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wm_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        hl_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        cm_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        wm_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1843200],
                            *(double (*)[30720])&Spo2_Seiz_Window[1843200], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &hl_expl_temp, &cm_expl_temp, &wm_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = jc_reshapes[0].f1->size[0] * jc_reshapes[0].f1->size[1];
      jc_reshapes[0].f1->size[0] = 1;
      jc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(jc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        jc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      hq_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      hq_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      hq_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      hq_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      hq_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      hq_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      hq_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      hq_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      hq_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      hq_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      cr_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      cr_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      cr_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      cr_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      cr_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      cr_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      cr_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      cr_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      cr_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      cr_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      wr_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      wr_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      wr_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      wr_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      wr_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      wr_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      wr_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      wr_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      wr_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      wr_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&hq_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cr_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wr_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        hq_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        cr_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        wr_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1843200],
                            *(double (*)[30720])&Spo2_Gray_Window[1843200], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &hq_expl_temp, &cr_expl_temp, &wr_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = jc_reshapes[0].f1->size[0];
      c_i = jc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = jc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = jc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = jc_reshapes[0]
            .f1->data[i4 + jc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + jc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[61]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      nl_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      nl_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      nl_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      nl_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      nl_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      nl_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      nl_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      nl_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      nl_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      nl_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      im_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      im_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      im_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      im_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      im_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      im_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      im_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      im_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      im_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      im_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      dn_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      dn_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      dn_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      dn_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      dn_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      dn_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      dn_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      dn_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      dn_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      dn_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&nl_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&im_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dn_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        nl_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        im_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        dn_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1873920],
                            *(double (*)[30720])&Spo2_Seiz_Window[1873920], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &nl_expl_temp, &im_expl_temp, &dn_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = kc_reshapes[0].f1->size[0] * kc_reshapes[0].f1->size[1];
      kc_reshapes[0].f1->size[0] = 1;
      kc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(kc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        kc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      nq_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      nq_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      nq_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      nq_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      nq_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      nq_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      nq_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      nq_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      nq_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      nq_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ir_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ir_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ir_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ir_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ir_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ir_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ir_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ir_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ir_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ir_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ds_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ds_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ds_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ds_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ds_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ds_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ds_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ds_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ds_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ds_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&nq_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ir_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ds_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        nq_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ir_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ds_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1873920],
                            *(double (*)[30720])&Spo2_Gray_Window[1873920], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &nq_expl_temp, &ir_expl_temp, &ds_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = kc_reshapes[0].f1->size[0];
      c_i = kc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = kc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = kc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = kc_reshapes[0]
            .f1->data[i4 + kc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + kc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[62]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      tl_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      tl_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      tl_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      tl_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      tl_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      tl_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      tl_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      tl_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      tl_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      tl_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      om_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      om_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      om_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      om_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      om_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      om_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      om_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      om_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      om_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      om_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      jn_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      jn_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      jn_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      jn_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      jn_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      jn_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      jn_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      jn_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      jn_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      jn_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&tl_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&om_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jn_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        tl_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        om_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        jn_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1904640],
                            *(double (*)[30720])&Spo2_Seiz_Window[1904640], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &tl_expl_temp, &om_expl_temp, &jn_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = lc_reshapes[0].f1->size[0] * lc_reshapes[0].f1->size[1];
      lc_reshapes[0].f1->size[0] = 1;
      lc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(lc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        lc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      tq_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      tq_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      tq_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      tq_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      tq_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      tq_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      tq_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      tq_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      tq_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      tq_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      or_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      or_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      or_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      or_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      or_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      or_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      or_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      or_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      or_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      or_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      js_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      js_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      js_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      js_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      js_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      js_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      js_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      js_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      js_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      js_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&tq_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&or_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&js_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        tq_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        or_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        js_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1904640],
                            *(double (*)[30720])&Spo2_Gray_Window[1904640], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &tq_expl_temp, &or_expl_temp, &js_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = lc_reshapes[0].f1->size[0];
      c_i = lc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = lc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = lc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = lc_reshapes[0]
            .f1->data[i4 + lc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + lc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[63]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      am_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      am_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      am_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      am_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      am_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      am_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      am_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      am_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      am_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      am_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      um_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      um_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      um_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      um_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      um_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      um_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      um_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      um_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      um_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      um_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      pn_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      pn_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      pn_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      pn_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      pn_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      pn_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      pn_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      pn_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      pn_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      pn_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&am_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&um_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pn_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        am_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        um_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        pn_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1935360],
                            *(double (*)[30720])&Spo2_Seiz_Window[1935360], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &am_expl_temp, &um_expl_temp, &pn_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = mc_reshapes[0].f1->size[0] * mc_reshapes[0].f1->size[1];
      mc_reshapes[0].f1->size[0] = 1;
      mc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(mc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        mc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        i2 = (signed char)true_label_size[0];
      } else {
        i2 = 0;
      }

      result_size_idx_0 = i2 + 1;
      c_i = i2;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[i2] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ar_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ar_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ar_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ar_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ar_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ar_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ar_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ar_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ar_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ar_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ur_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ur_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ur_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ur_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ur_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ur_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ur_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ur_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ur_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ur_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      os_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      os_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      os_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      os_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      os_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      os_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      os_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      os_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      os_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      os_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ar_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ur_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&os_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ar_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ur_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        os_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1935360],
                            *(double (*)[30720])&Spo2_Gray_Window[1935360], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ar_expl_temp, &ur_expl_temp, &os_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = mc_reshapes[0].f1->size[0];
      c_i = mc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = mc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = mc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = mc_reshapes[0]
            .f1->data[i4 + mc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + mc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = i2 + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[i2 + 1] = 0;
      true_label_size[0] = i2 + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[64]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      gm_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      gm_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      gm_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      gm_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      gm_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      gm_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      gm_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      gm_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      gm_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      gm_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      bn_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      bn_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      bn_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      bn_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      bn_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      bn_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      bn_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      bn_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      bn_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      bn_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      vn_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      vn_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      vn_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      vn_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      vn_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      vn_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      vn_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      vn_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      vn_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      vn_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&gm_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bn_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vn_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        gm_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        bn_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        vn_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1966080],
                            *(double (*)[30720])&Spo2_Seiz_Window[1966080], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &gm_expl_temp, &bn_expl_temp, &vn_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = nc_reshapes[0].f1->size[0] * nc_reshapes[0].f1->size[1];
      nc_reshapes[0].f1->size[0] = 1;
      nc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(nc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        nc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      gr_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      gr_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      gr_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      gr_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      gr_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      gr_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      gr_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      gr_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      gr_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      gr_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      bs_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      bs_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      bs_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      bs_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      bs_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      bs_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      bs_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      bs_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      bs_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      bs_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ts_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ts_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ts_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ts_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ts_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ts_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ts_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ts_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ts_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ts_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&gr_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bs_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ts_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        gr_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        bs_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ts_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1966080],
                            *(double (*)[30720])&Spo2_Gray_Window[1966080], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &gr_expl_temp, &bs_expl_temp, &ts_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = nc_reshapes[0].f1->size[0];
      c_i = nc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = nc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = nc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = nc_reshapes[0]
            .f1->data[i4 + nc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + nc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[65]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      mm_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      mm_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      mm_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      mm_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      mm_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      mm_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      mm_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      mm_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      mm_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      mm_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      hn_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      hn_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      hn_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      hn_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      hn_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      hn_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      hn_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      hn_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      hn_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      hn_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      co_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      co_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      co_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      co_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      co_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      co_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      co_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      co_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      co_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      co_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&mm_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hn_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&co_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        mm_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        hn_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        co_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[1996800],
                            *(double (*)[30720])&Spo2_Seiz_Window[1996800], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &mm_expl_temp, &hn_expl_temp, &co_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = oc_reshapes[0].f1->size[0] * oc_reshapes[0].f1->size[1];
      oc_reshapes[0].f1->size[0] = 1;
      oc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(oc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        oc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      mr_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      mr_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      mr_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      mr_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      mr_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      mr_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      mr_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      mr_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      mr_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      mr_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      hs_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      hs_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      hs_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      hs_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      hs_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      hs_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      hs_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      hs_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      hs_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      hs_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ys_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ys_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ys_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ys_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ys_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ys_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ys_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ys_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ys_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ys_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&mr_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hs_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ys_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        mr_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        hs_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ys_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[1996800],
                            *(double (*)[30720])&Spo2_Gray_Window[1996800], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &mr_expl_temp, &hs_expl_temp, &ys_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = oc_reshapes[0].f1->size[0];
      c_i = oc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = oc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = oc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = oc_reshapes[0]
            .f1->data[i4 + oc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + oc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[66]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      sm_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      sm_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      sm_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      sm_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      sm_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      sm_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      sm_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      sm_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      sm_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      sm_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      nn_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      nn_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      nn_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      nn_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      nn_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      nn_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      nn_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      nn_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      nn_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      nn_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      io_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      io_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      io_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      io_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      io_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      io_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      io_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      io_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      io_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      io_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&sm_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&nn_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&io_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        sm_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        nn_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        io_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2027520],
                            *(double (*)[30720])&Spo2_Seiz_Window[2027520], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &sm_expl_temp, &nn_expl_temp, &io_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = pc_reshapes[0].f1->size[0] * pc_reshapes[0].f1->size[1];
      pc_reshapes[0].f1->size[0] = 1;
      pc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(pc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        pc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      sr_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      sr_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      sr_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      sr_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      sr_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      sr_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      sr_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      sr_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      sr_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      sr_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ms_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ms_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ms_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ms_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ms_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ms_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ms_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ms_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ms_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ms_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      dt_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      dt_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      dt_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      dt_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      dt_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      dt_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      dt_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      dt_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      dt_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      dt_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&sr_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ms_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dt_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        sr_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ms_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        dt_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2027520],
                            *(double (*)[30720])&Spo2_Gray_Window[2027520], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &sr_expl_temp, &ms_expl_temp, &dt_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = pc_reshapes[0].f1->size[0];
      c_i = pc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = pc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = pc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = pc_reshapes[0]
            .f1->data[i4 + pc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + pc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[67]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ym_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ym_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ym_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ym_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ym_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ym_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ym_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ym_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ym_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ym_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      tn_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      tn_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      tn_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      tn_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      tn_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      tn_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      tn_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      tn_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      tn_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      tn_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      oo_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      oo_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      oo_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      oo_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      oo_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      oo_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      oo_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      oo_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      oo_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      oo_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ym_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&tn_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&oo_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ym_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        tn_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        oo_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2058240],
                            *(double (*)[30720])&Spo2_Seiz_Window[2058240], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ym_expl_temp, &tn_expl_temp, &oo_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = qc_reshapes[0].f1->size[0] * qc_reshapes[0].f1->size[1];
      qc_reshapes[0].f1->size[0] = 1;
      qc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(qc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        qc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      yr_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      yr_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      yr_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      yr_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      yr_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      yr_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      yr_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      yr_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      yr_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      yr_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      rs_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      rs_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      rs_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      rs_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      rs_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      rs_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      rs_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      rs_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      rs_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      rs_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ht_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ht_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ht_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ht_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ht_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ht_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ht_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ht_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ht_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ht_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&yr_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rs_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ht_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        yr_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        rs_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ht_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2058240],
                            *(double (*)[30720])&Spo2_Gray_Window[2058240], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &yr_expl_temp, &rs_expl_temp, &ht_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = qc_reshapes[0].f1->size[0];
      c_i = qc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = qc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = qc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = qc_reshapes[0]
            .f1->data[i4 + qc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + qc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[68]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      fn_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      fn_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      fn_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      fn_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      fn_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      fn_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      fn_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      fn_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      fn_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      fn_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ao_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ao_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ao_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ao_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ao_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ao_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ao_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ao_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ao_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ao_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      uo_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      uo_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      uo_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      uo_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      uo_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      uo_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      uo_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      uo_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      uo_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      uo_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&fn_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ao_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&uo_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        fn_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ao_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        uo_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2088960],
                            *(double (*)[30720])&Spo2_Seiz_Window[2088960], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &fn_expl_temp, &ao_expl_temp, &uo_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = rc_reshapes[0].f1->size[0] * rc_reshapes[0].f1->size[1];
      rc_reshapes[0].f1->size[0] = 1;
      rc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(rc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        rc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      fs_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      fs_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      fs_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      fs_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      fs_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      fs_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      fs_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      fs_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      fs_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      fs_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ws_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ws_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ws_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ws_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ws_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ws_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ws_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ws_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ws_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ws_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      lt_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      lt_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      lt_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      lt_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      lt_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      lt_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      lt_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      lt_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      lt_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      lt_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&fs_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ws_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lt_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        fs_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ws_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        lt_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2088960],
                            *(double (*)[30720])&Spo2_Gray_Window[2088960], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &fs_expl_temp, &ws_expl_temp, &lt_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = rc_reshapes[0].f1->size[0];
      c_i = rc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = rc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = rc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = rc_reshapes[0]
            .f1->data[i4 + rc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + rc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[69]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ln_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ln_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ln_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ln_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ln_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ln_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ln_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ln_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ln_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ln_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      go_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      go_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      go_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      go_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      go_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      go_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      go_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      go_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      go_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      go_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      bp_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      bp_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      bp_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      bp_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      bp_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      bp_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      bp_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      bp_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      bp_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      bp_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ln_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&go_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bp_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ln_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        go_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        bp_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2119680],
                            *(double (*)[30720])&Spo2_Seiz_Window[2119680], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ln_expl_temp, &go_expl_temp, &bp_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = sc_reshapes[0].f1->size[0] * sc_reshapes[0].f1->size[1];
      sc_reshapes[0].f1->size[0] = 1;
      sc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(sc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        sc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ls_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ls_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ls_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ls_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ls_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ls_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ls_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ls_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ls_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ls_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ct_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ct_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ct_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ct_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ct_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ct_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ct_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ct_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ct_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ct_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      pt_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      pt_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      pt_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      pt_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      pt_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      pt_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      pt_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      pt_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      pt_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      pt_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ls_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ct_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pt_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ls_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ct_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        pt_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2119680],
                            *(double (*)[30720])&Spo2_Gray_Window[2119680], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ls_expl_temp, &ct_expl_temp, &pt_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = sc_reshapes[0].f1->size[0];
      c_i = sc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = sc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = sc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = sc_reshapes[0]
            .f1->data[i4 + sc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + sc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[70]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      rn_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      rn_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      rn_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      rn_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      rn_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      rn_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      rn_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      rn_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      rn_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      rn_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      mo_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      mo_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      mo_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      mo_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      mo_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      mo_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      mo_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      mo_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      mo_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      mo_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      hp_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      hp_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      hp_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      hp_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      hp_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      hp_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      hp_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      hp_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      hp_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      hp_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&rn_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mo_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hp_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        rn_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        mo_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        hp_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2150400],
                            *(double (*)[30720])&Spo2_Seiz_Window[2150400], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &rn_expl_temp, &mo_expl_temp, &hp_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = tc_reshapes[0].f1->size[0] * tc_reshapes[0].f1->size[1];
      tc_reshapes[0].f1->size[0] = 1;
      tc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(tc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        tc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      qs_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      qs_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      qs_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      qs_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      qs_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      qs_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      qs_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      qs_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      qs_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      qs_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      gt_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      gt_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      gt_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      gt_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      gt_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      gt_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      gt_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      gt_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      gt_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      gt_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      st_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      st_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      st_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      st_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      st_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      st_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      st_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      st_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      st_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      st_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&qs_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gt_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&st_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        qs_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        gt_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        st_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2150400],
                            *(double (*)[30720])&Spo2_Gray_Window[2150400], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &qs_expl_temp, &gt_expl_temp, &st_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = tc_reshapes[0].f1->size[0];
      c_i = tc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = tc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = tc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = tc_reshapes[0]
            .f1->data[i4 + tc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + tc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[71]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      xn_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      xn_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      xn_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      xn_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      xn_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      xn_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      xn_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      xn_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      xn_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      xn_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      so_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      so_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      so_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      so_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      so_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      so_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      so_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      so_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      so_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      so_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      np_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      np_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      np_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      np_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      np_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      np_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      np_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      np_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      np_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      np_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&xn_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&so_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&np_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        xn_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        so_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        np_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2181120],
                            *(double (*)[30720])&Spo2_Seiz_Window[2181120], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &xn_expl_temp, &so_expl_temp, &np_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = uc_reshapes[0].f1->size[0] * uc_reshapes[0].f1->size[1];
      uc_reshapes[0].f1->size[0] = 1;
      uc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(uc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        uc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      vs_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      vs_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      vs_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      vs_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      vs_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      vs_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      vs_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      vs_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      vs_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      vs_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      kt_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      kt_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      kt_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      kt_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      kt_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      kt_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      kt_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      kt_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      kt_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      kt_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      vt_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      vt_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      vt_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      vt_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      vt_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      vt_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      vt_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      vt_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      vt_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      vt_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&vs_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kt_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vt_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        vs_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        kt_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        vt_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2181120],
                            *(double (*)[30720])&Spo2_Gray_Window[2181120], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &vs_expl_temp, &kt_expl_temp, &vt_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = uc_reshapes[0].f1->size[0];
      c_i = uc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = uc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = uc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = uc_reshapes[0]
            .f1->data[i4 + uc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + uc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[72]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      eo_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      eo_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      eo_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      eo_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      eo_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      eo_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      eo_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      eo_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      eo_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      eo_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      yo_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      yo_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      yo_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      yo_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      yo_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      yo_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      yo_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      yo_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      yo_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      yo_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      tp_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      tp_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      tp_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      tp_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      tp_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      tp_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      tp_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      tp_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      tp_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      tp_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&eo_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yo_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&tp_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        eo_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        yo_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        tp_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2211840],
                            *(double (*)[30720])&Spo2_Seiz_Window[2211840], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &eo_expl_temp, &yo_expl_temp, &tp_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = vc_reshapes[0].f1->size[0] * vc_reshapes[0].f1->size[1];
      vc_reshapes[0].f1->size[0] = 1;
      vc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(vc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        vc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      bt_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      bt_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      bt_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      bt_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      bt_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      bt_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      bt_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      bt_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      bt_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      bt_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ot_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ot_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ot_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ot_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ot_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ot_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ot_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ot_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ot_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ot_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      yt_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      yt_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      yt_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      yt_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      yt_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      yt_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      yt_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      yt_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      yt_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      yt_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&bt_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ot_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yt_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        bt_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ot_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        yt_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2211840],
                            *(double (*)[30720])&Spo2_Gray_Window[2211840], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &bt_expl_temp, &ot_expl_temp, &yt_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = vc_reshapes[0].f1->size[0];
      c_i = vc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = vc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = vc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = vc_reshapes[0]
            .f1->data[i4 + vc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + vc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[73]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      ko_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ko_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ko_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ko_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ko_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ko_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ko_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ko_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ko_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ko_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      fp_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      fp_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      fp_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      fp_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      fp_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      fp_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      fp_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      fp_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      fp_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      fp_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      aq_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      aq_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      aq_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      aq_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      aq_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      aq_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      aq_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      aq_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      aq_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      aq_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ko_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fp_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&aq_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ko_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        fp_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        aq_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2242560],
                            *(double (*)[30720])&Spo2_Seiz_Window[2242560], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ko_expl_temp, &fp_expl_temp, &aq_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = wc_reshapes[0].f1->size[0] * wc_reshapes[0].f1->size[1];
      wc_reshapes[0].f1->size[0] = 1;
      wc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(wc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        wc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ft_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ft_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ft_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ft_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ft_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ft_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ft_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ft_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ft_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ft_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      rt_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      rt_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      rt_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      rt_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      rt_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      rt_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      rt_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      rt_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      rt_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      rt_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      cu_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      cu_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      cu_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      cu_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      cu_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      cu_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      cu_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      cu_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      cu_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      cu_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ft_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rt_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cu_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ft_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        rt_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        cu_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2242560],
                            *(double (*)[30720])&Spo2_Gray_Window[2242560], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ft_expl_temp, &rt_expl_temp, &cu_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = wc_reshapes[0].f1->size[0];
      c_i = wc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = wc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = wc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = wc_reshapes[0]
            .f1->data[i4 + wc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + wc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[74]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      qo_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      qo_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      qo_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      qo_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      qo_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      qo_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      qo_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      qo_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      qo_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      qo_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      lp_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      lp_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      lp_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      lp_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      lp_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      lp_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      lp_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      lp_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      lp_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      lp_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      gq_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      gq_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      gq_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      gq_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      gq_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      gq_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      gq_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      gq_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      gq_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      gq_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&qo_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lp_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gq_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        qo_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        lp_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        gq_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2273280],
                            *(double (*)[30720])&Spo2_Seiz_Window[2273280], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &qo_expl_temp, &lp_expl_temp, &gq_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = xc_reshapes[0].f1->size[0] * xc_reshapes[0].f1->size[1];
      xc_reshapes[0].f1->size[0] = 1;
      xc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(xc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        xc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      jt_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      jt_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      jt_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      jt_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      jt_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      jt_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      jt_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      jt_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      jt_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      jt_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ut_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ut_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ut_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ut_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ut_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ut_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ut_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ut_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ut_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ut_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      fu_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      fu_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      fu_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      fu_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      fu_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      fu_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      fu_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      fu_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      fu_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      fu_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&jt_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ut_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fu_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        jt_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ut_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        fu_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2273280],
                            *(double (*)[30720])&Spo2_Gray_Window[2273280], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &jt_expl_temp, &ut_expl_temp, &fu_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = xc_reshapes[0].f1->size[0];
      c_i = xc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = xc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = xc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = xc_reshapes[0]
            .f1->data[i4 + xc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + xc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[75]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      wo_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      wo_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      wo_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      wo_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      wo_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      wo_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      wo_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      wo_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      wo_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      wo_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      rp_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      rp_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      rp_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      rp_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      rp_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      rp_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      rp_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      rp_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      rp_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      rp_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      mq_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      mq_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      mq_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      mq_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      mq_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      mq_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      mq_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      mq_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      mq_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      mq_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&wo_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rp_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mq_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        wo_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        rp_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        mq_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2304000],
                            *(double (*)[30720])&Spo2_Seiz_Window[2304000], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &wo_expl_temp, &rp_expl_temp, &mq_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = yc_reshapes[0].f1->size[0] * yc_reshapes[0].f1->size[1];
      yc_reshapes[0].f1->size[0] = 1;
      yc_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(yc_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        yc_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      nt_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      nt_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      nt_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      nt_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      nt_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      nt_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      nt_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      nt_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      nt_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      nt_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      xt_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      xt_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      xt_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      xt_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      xt_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      xt_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      xt_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      xt_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      xt_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      xt_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      iu_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      iu_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      iu_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      iu_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      iu_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      iu_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      iu_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      iu_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      iu_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      iu_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&nt_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xt_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&iu_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        nt_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        xt_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        iu_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2304000],
                            *(double (*)[30720])&Spo2_Gray_Window[2304000], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &nt_expl_temp, &xt_expl_temp, &iu_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = yc_reshapes[0].f1->size[0];
      c_i = yc_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = yc_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = yc_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = yc_reshapes[0]
            .f1->data[i4 + yc_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + yc_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[76]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      dp_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      dp_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      dp_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      dp_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      dp_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      dp_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      dp_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      dp_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      dp_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      dp_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      xp_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      xp_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      xp_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      xp_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      xp_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      xp_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      xp_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      xp_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      xp_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      xp_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      sq_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      sq_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      sq_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      sq_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      sq_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      sq_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      sq_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      sq_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      sq_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      sq_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&dp_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xp_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&sq_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        dp_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        xp_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        sq_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2334720],
                            *(double (*)[30720])&Spo2_Seiz_Window[2334720], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &dp_expl_temp, &xp_expl_temp, &sq_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ad_reshapes[0].f1->size[0] * ad_reshapes[0].f1->size[1];
      ad_reshapes[0].f1->size[0] = 1;
      ad_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ad_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ad_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      qt_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      qt_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      qt_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      qt_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      qt_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      qt_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      qt_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      qt_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      qt_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      qt_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      bu_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      bu_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      bu_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      bu_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      bu_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      bu_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      bu_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      bu_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      bu_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      bu_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      lu_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      lu_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      lu_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      lu_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      lu_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      lu_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      lu_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      lu_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      lu_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      lu_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&qt_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bu_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lu_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        qt_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        bu_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        lu_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2334720],
                            *(double (*)[30720])&Spo2_Gray_Window[2334720], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &qt_expl_temp, &bu_expl_temp, &lu_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ad_reshapes[0].f1->size[0];
      c_i = ad_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ad_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ad_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ad_reshapes[0]
            .f1->data[i4 + ad_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ad_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[77]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      jp_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      jp_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      jp_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      jp_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      jp_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      jp_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      jp_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      jp_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      jp_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      jp_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      eq_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      eq_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      eq_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      eq_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      eq_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      eq_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      eq_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      eq_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      eq_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      eq_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      yq_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      yq_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      yq_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      yq_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      yq_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      yq_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      yq_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      yq_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      yq_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      yq_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&jp_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&eq_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&yq_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        jp_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        eq_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        yq_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2365440],
                            *(double (*)[30720])&Spo2_Seiz_Window[2365440], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &jp_expl_temp, &eq_expl_temp, &yq_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = bd_reshapes[0].f1->size[0] * bd_reshapes[0].f1->size[1];
      bd_reshapes[0].f1->size[0] = 1;
      bd_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(bd_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        bd_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      tt_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      tt_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      tt_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      tt_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      tt_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      tt_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      tt_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      tt_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      tt_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      tt_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      eu_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      eu_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      eu_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      eu_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      eu_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      eu_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      eu_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      eu_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      eu_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      eu_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ou_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ou_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ou_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ou_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ou_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ou_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ou_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ou_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ou_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ou_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&tt_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&eu_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ou_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        tt_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        eu_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ou_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2365440],
                            *(double (*)[30720])&Spo2_Gray_Window[2365440], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &tt_expl_temp, &eu_expl_temp, &ou_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = bd_reshapes[0].f1->size[0];
      c_i = bd_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = bd_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = bd_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = bd_reshapes[0]
            .f1->data[i4 + bd_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + bd_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[78]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      pp_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      pp_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      pp_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      pp_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      pp_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      pp_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      pp_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      pp_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      pp_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      pp_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      kq_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      kq_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      kq_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      kq_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      kq_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      kq_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      kq_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      kq_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      kq_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      kq_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      fr_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      fr_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      fr_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      fr_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      fr_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      fr_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      fr_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      fr_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      fr_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      fr_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&pp_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kq_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&fr_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        pp_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        kq_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        fr_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2396160],
                            *(double (*)[30720])&Spo2_Seiz_Window[2396160], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &pp_expl_temp, &kq_expl_temp, &fr_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = cd_reshapes[0].f1->size[0] * cd_reshapes[0].f1->size[1];
      cd_reshapes[0].f1->size[0] = 1;
      cd_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(cd_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        cd_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      wt_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      wt_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      wt_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      wt_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      wt_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      wt_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      wt_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      wt_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      wt_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      wt_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      hu_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      hu_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      hu_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      hu_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      hu_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      hu_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      hu_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      hu_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      hu_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      hu_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ru_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ru_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ru_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ru_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ru_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ru_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ru_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ru_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ru_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ru_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&wt_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hu_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ru_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        wt_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        hu_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ru_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2396160],
                            *(double (*)[30720])&Spo2_Gray_Window[2396160], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &wt_expl_temp, &hu_expl_temp, &ru_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = cd_reshapes[0].f1->size[0];
      c_i = cd_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = cd_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = cd_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = cd_reshapes[0]
            .f1->data[i4 + cd_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + cd_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[79]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      vp_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      vp_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      vp_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      vp_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      vp_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      vp_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      vp_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      vp_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      vp_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      vp_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      qq_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      qq_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      qq_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      qq_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      qq_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      qq_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      qq_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      qq_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      qq_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      qq_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      lr_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      lr_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      lr_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      lr_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      lr_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      lr_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      lr_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      lr_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      lr_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      lr_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&vp_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qq_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lr_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        vp_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        qq_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        lr_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2426880],
                            *(double (*)[30720])&Spo2_Seiz_Window[2426880], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &vp_expl_temp, &qq_expl_temp, &lr_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = dd_reshapes[0].f1->size[0] * dd_reshapes[0].f1->size[1];
      dd_reshapes[0].f1->size[0] = 1;
      dd_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(dd_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        dd_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      au_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      au_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      au_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      au_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      au_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      au_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      au_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      au_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      au_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      au_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ku_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ku_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ku_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ku_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ku_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ku_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ku_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ku_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ku_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ku_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      uu_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      uu_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      uu_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      uu_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      uu_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      uu_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      uu_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      uu_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      uu_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      uu_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&au_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ku_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&uu_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        au_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ku_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        uu_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2426880],
                            *(double (*)[30720])&Spo2_Gray_Window[2426880], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &au_expl_temp, &ku_expl_temp, &uu_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = dd_reshapes[0].f1->size[0];
      c_i = dd_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = dd_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = dd_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = dd_reshapes[0]
            .f1->data[i4 + dd_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + dd_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[80]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      cq_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      cq_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      cq_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      cq_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      cq_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      cq_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      cq_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      cq_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      cq_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      cq_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      wq_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      wq_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      wq_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      wq_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      wq_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      wq_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      wq_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      wq_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      wq_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      wq_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      rr_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      rr_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      rr_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      rr_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      rr_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      rr_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      rr_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      rr_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      rr_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      rr_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&cq_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wq_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&rr_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        cq_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        wq_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        rr_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2457600],
                            *(double (*)[30720])&Spo2_Seiz_Window[2457600], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &cq_expl_temp, &wq_expl_temp, &rr_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ed_reshapes[0].f1->size[0] * ed_reshapes[0].f1->size[1];
      ed_reshapes[0].f1->size[0] = 1;
      ed_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ed_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ed_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      du_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      du_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      du_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      du_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      du_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      du_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      du_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      du_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      du_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      du_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      nu_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      nu_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      nu_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      nu_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      nu_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      nu_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      nu_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      nu_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      nu_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      nu_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      xu_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      xu_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      xu_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      xu_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      xu_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      xu_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      xu_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      xu_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      xu_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      xu_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&du_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&nu_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xu_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        du_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        nu_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        xu_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2457600],
                            *(double (*)[30720])&Spo2_Gray_Window[2457600], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &du_expl_temp, &nu_expl_temp, &xu_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ed_reshapes[0].f1->size[0];
      c_i = ed_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ed_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ed_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ed_reshapes[0]
            .f1->data[i4 + ed_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ed_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[81]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      iq_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      iq_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      iq_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      iq_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      iq_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      iq_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      iq_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      iq_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      iq_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      iq_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      dr_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      dr_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      dr_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      dr_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      dr_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      dr_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      dr_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      dr_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      dr_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      dr_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      xr_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      xr_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      xr_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      xr_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      xr_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      xr_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      xr_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      xr_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      xr_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      xr_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&iq_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dr_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xr_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        iq_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        dr_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        xr_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2488320],
                            *(double (*)[30720])&Spo2_Seiz_Window[2488320], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &iq_expl_temp, &dr_expl_temp, &xr_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = fd_reshapes[0].f1->size[0] * fd_reshapes[0].f1->size[1];
      fd_reshapes[0].f1->size[0] = 1;
      fd_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(fd_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        fd_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      gu_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      gu_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      gu_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      gu_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      gu_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      gu_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      gu_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      gu_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      gu_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      gu_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      qu_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      qu_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      qu_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      qu_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      qu_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      qu_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      qu_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      qu_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      qu_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      qu_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      bv_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      bv_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      bv_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      bv_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      bv_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      bv_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      bv_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      bv_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      bv_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      bv_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&gu_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qu_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&bv_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        gu_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        qu_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        bv_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2488320],
                            *(double (*)[30720])&Spo2_Gray_Window[2488320], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &gu_expl_temp, &qu_expl_temp, &bv_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = fd_reshapes[0].f1->size[0];
      c_i = fd_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = fd_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = fd_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = fd_reshapes[0]
            .f1->data[i4 + fd_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + fd_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[82]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      oq_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      oq_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      oq_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      oq_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      oq_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      oq_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      oq_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      oq_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      oq_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      oq_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      jr_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      jr_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      jr_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      jr_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      jr_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      jr_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      jr_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      jr_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      jr_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      jr_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      es_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      es_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      es_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      es_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      es_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      es_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      es_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      es_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      es_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      es_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&oq_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jr_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&es_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        oq_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        jr_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        es_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2519040],
                            *(double (*)[30720])&Spo2_Seiz_Window[2519040], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &oq_expl_temp, &jr_expl_temp, &es_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = gd_reshapes[0].f1->size[0] * gd_reshapes[0].f1->size[1];
      gd_reshapes[0].f1->size[0] = 1;
      gd_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(gd_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        gd_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      ju_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      ju_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      ju_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      ju_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      ju_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      ju_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      ju_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      ju_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      ju_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      ju_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      tu_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      tu_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      tu_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      tu_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      tu_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      tu_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      tu_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      tu_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      tu_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      tu_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ev_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ev_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ev_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ev_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ev_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ev_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ev_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ev_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ev_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ev_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&ju_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&tu_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ev_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        ju_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        tu_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ev_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2519040],
                            *(double (*)[30720])&Spo2_Gray_Window[2519040], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &ju_expl_temp, &tu_expl_temp, &ev_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = gd_reshapes[0].f1->size[0];
      c_i = gd_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = gd_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = gd_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = gd_reshapes[0]
            .f1->data[i4 + gd_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + gd_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[83]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      uq_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      uq_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      uq_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      uq_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      uq_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      uq_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      uq_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      uq_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      uq_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      uq_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      pr_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      pr_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      pr_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      pr_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      pr_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      pr_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      pr_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      pr_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      pr_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      pr_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ks_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ks_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ks_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ks_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ks_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ks_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ks_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ks_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ks_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ks_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&uq_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pr_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ks_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        uq_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        pr_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ks_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2549760],
                            *(double (*)[30720])&Spo2_Seiz_Window[2549760], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &uq_expl_temp, &pr_expl_temp, &ks_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = hd_reshapes[0].f1->size[0] * hd_reshapes[0].f1->size[1];
      hd_reshapes[0].f1->size[0] = 1;
      hd_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(hd_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        hd_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      mu_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      mu_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      mu_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      mu_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      mu_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      mu_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      mu_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      mu_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      mu_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      mu_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      wu_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      wu_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      wu_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      wu_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      wu_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      wu_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      wu_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      wu_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      wu_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      wu_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      hv_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      hv_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      hv_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      hv_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      hv_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      hv_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      hv_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      hv_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      hv_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      hv_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&mu_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&wu_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&hv_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        mu_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        wu_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        hv_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2549760],
                            *(double (*)[30720])&Spo2_Gray_Window[2549760], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &mu_expl_temp, &wu_expl_temp, &hv_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = hd_reshapes[0].f1->size[0];
      c_i = hd_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = hd_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = hd_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = hd_reshapes[0]
            .f1->data[i4 + hd_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + hd_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[84]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      br_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      br_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      br_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      br_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      br_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      br_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      br_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      br_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      br_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      br_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      vr_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      vr_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      vr_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      vr_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      vr_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      vr_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      vr_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      vr_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      vr_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      vr_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ps_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ps_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ps_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ps_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ps_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ps_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ps_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ps_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ps_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ps_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&br_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&vr_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ps_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        br_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        vr_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ps_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2580480],
                            *(double (*)[30720])&Spo2_Seiz_Window[2580480], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &br_expl_temp, &vr_expl_temp, &ps_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = id_reshapes[0].f1->size[0] * id_reshapes[0].f1->size[1];
      id_reshapes[0].f1->size[0] = 1;
      id_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(id_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        id_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      pu_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      pu_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      pu_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      pu_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      pu_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      pu_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      pu_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      pu_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      pu_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      pu_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      av_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      av_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      av_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      av_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      av_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      av_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      av_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      av_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      av_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      av_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      jv_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      jv_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      jv_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      jv_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      jv_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      jv_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      jv_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      jv_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      jv_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      jv_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&pu_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&av_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&jv_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        pu_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        av_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        jv_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2580480],
                            *(double (*)[30720])&Spo2_Gray_Window[2580480], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &pu_expl_temp, &av_expl_temp, &jv_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = id_reshapes[0].f1->size[0];
      c_i = id_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = id_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = id_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = id_reshapes[0]
            .f1->data[i4 + id_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + id_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[85]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      hr_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      hr_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      hr_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      hr_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      hr_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      hr_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      hr_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      hr_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      hr_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      hr_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      cs_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      cs_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      cs_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      cs_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      cs_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      cs_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      cs_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      cs_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      cs_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      cs_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      us_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      us_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      us_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      us_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      us_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      us_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      us_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      us_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      us_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      us_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&hr_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&cs_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&us_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        hr_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        cs_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        us_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2611200],
                            *(double (*)[30720])&Spo2_Seiz_Window[2611200], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &hr_expl_temp, &cs_expl_temp, &us_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = jd_reshapes[0].f1->size[0] * jd_reshapes[0].f1->size[1];
      jd_reshapes[0].f1->size[0] = 1;
      jd_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(jd_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        jd_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      su_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      su_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      su_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      su_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      su_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      su_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      su_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      su_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      su_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      su_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      dv_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      dv_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      dv_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      dv_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      dv_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      dv_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      dv_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      dv_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      dv_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      dv_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      lv_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      lv_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      lv_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      lv_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      lv_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      lv_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      lv_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      lv_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      lv_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      lv_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&su_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&dv_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&lv_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        su_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        dv_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        lv_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2611200],
                            *(double (*)[30720])&Spo2_Gray_Window[2611200], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &su_expl_temp, &dv_expl_temp, &lv_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = jd_reshapes[0].f1->size[0];
      c_i = jd_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = jd_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = jd_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = jd_reshapes[0]
            .f1->data[i4 + jd_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + jd_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[86]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      nr_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      nr_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      nr_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      nr_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      nr_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      nr_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      nr_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      nr_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      nr_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      nr_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      is_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      is_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      is_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      is_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      is_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      is_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      is_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      is_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      is_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      is_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      at_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      at_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      at_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      at_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      at_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      at_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      at_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      at_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      at_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      at_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&nr_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&is_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&at_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        nr_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        is_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        at_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2641920],
                            *(double (*)[30720])&Spo2_Seiz_Window[2641920], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &nr_expl_temp, &is_expl_temp, &at_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = kd_reshapes[0].f1->size[0] * kd_reshapes[0].f1->size[1];
      kd_reshapes[0].f1->size[0] = 1;
      kd_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(kd_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        kd_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      vu_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      vu_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      vu_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      vu_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      vu_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      vu_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      vu_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      vu_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      vu_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      vu_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      gv_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      gv_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      gv_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      gv_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      gv_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      gv_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      gv_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      gv_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      gv_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      gv_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      nv_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      nv_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      nv_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      nv_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      nv_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      nv_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      nv_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      nv_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      nv_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      nv_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&vu_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&gv_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&nv_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        vu_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        gv_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        nv_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2641920],
                            *(double (*)[30720])&Spo2_Gray_Window[2641920], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &vu_expl_temp, &gv_expl_temp, &nv_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = kd_reshapes[0].f1->size[0];
      c_i = kd_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = kd_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = kd_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = kd_reshapes[0]
            .f1->data[i4 + kd_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + kd_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[87]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      tr_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      tr_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      tr_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      tr_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      tr_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      tr_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      tr_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      tr_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      tr_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      tr_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ns_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ns_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ns_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ns_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ns_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ns_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ns_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ns_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ns_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ns_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      et_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      et_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      et_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      et_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      et_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      et_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      et_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      et_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      et_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      et_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&tr_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ns_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&et_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        tr_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ns_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        et_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2672640],
                            *(double (*)[30720])&Spo2_Seiz_Window[2672640], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &tr_expl_temp, &ns_expl_temp, &et_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = ld_reshapes[0].f1->size[0] * ld_reshapes[0].f1->size[1];
      ld_reshapes[0].f1->size[0] = 1;
      ld_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(ld_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        ld_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      yu_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      yu_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      yu_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      yu_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      yu_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      yu_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      yu_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      yu_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      yu_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      yu_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      iv_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      iv_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      iv_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      iv_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      iv_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      iv_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      iv_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      iv_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      iv_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      iv_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      ov_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      ov_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      ov_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      ov_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      ov_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      ov_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      ov_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      ov_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      ov_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      ov_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&yu_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&iv_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ov_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        yu_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        iv_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        ov_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2672640],
                            *(double (*)[30720])&Spo2_Gray_Window[2672640], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &yu_expl_temp, &iv_expl_temp, &ov_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = ld_reshapes[0].f1->size[0];
      c_i = ld_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = ld_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = ld_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = ld_reshapes[0]
            .f1->data[i4 + ld_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + ld_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[88]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      as_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      as_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      as_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      as_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      as_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      as_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      as_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      as_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      as_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      as_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      ss_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      ss_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      ss_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      ss_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      ss_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      ss_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      ss_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      ss_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      ss_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      ss_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      it_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      it_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      it_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      it_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      it_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      it_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      it_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      it_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      it_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      it_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&as_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&ss_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&it_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        as_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        ss_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        it_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2703360],
                            *(double (*)[30720])&Spo2_Seiz_Window[2703360], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &as_expl_temp, &ss_expl_temp, &it_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = md_reshapes[0].f1->size[0] * md_reshapes[0].f1->size[1];
      md_reshapes[0].f1->size[0] = 1;
      md_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(md_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        md_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      cv_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      cv_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      cv_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      cv_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      cv_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      cv_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      cv_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      cv_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      cv_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      cv_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      kv_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      kv_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      kv_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      kv_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      kv_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      kv_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      kv_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      kv_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      kv_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      kv_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      pv_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      pv_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      pv_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      pv_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      pv_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      pv_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      pv_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      pv_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      pv_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      pv_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&cv_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&kv_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&pv_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        cv_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        kv_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        pv_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2703360],
                            *(double (*)[30720])&Spo2_Gray_Window[2703360], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &cv_expl_temp, &kv_expl_temp, &pv_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = md_reshapes[0].f1->size[0];
      c_i = md_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = md_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = md_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = md_reshapes[0]
            .f1->data[i4 + md_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + md_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  skip the training data */
    if (select_ind[89]) {
      /*  ----------------- test on seiz/grey window ----------------- */
      /*  select test data type */
      /*  -------- profiling only -------- */
      gs_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      gs_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      gs_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      gs_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      gs_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      gs_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      gs_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      gs_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      gs_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      gs_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      xs_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      xs_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      xs_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      xs_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      xs_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      xs_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      xs_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      xs_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      xs_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      xs_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      mt_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      mt_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      mt_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      mt_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      mt_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      mt_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      mt_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      mt_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      mt_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      mt_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&gs_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&xs_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mt_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        gs_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        xs_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        mt_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Seiz_Window[2734080],
                            *(double (*)[30720])&Spo2_Seiz_Window[2734080], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &gs_expl_temp, &xs_expl_temp, &mt_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      if ((pred_label_size[0] != 0) && (pred_label_size[1] != 0)) {
        i5 = (short)pred_label_size[1];
      } else {
        i5 = 0;
      }

      i1 = nd_reshapes[0].f1->size[0] * nd_reshapes[0].f1->size[1];
      nd_reshapes[0].f1->size[0] = 1;
      nd_reshapes[0].f1->size[1] = i5;
      emxEnsureCapacity_real_T(nd_reshapes[0].f1, i1);
      c_i = i5;
      for (i1 = 0; i1 < c_i; i1++) {
        nd_reshapes[0].f1->data[i1] = pred_label_data[i1];
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      if ((true_label_size[0] != 0) && (true_label_size[1] != 0)) {
        u = (unsigned char)true_label_size[0];
      } else {
        u = 0U;
      }

      result_size_idx_0 = u + 1;
      c_i = u;
      for (i1 = 0; i1 < c_i; i1++) {
        result_data[i1] = (signed char)true_label_data[i1];
      }

      result_data[u] = 1;

      /*  select test data type */
      /*  -------- profiling only -------- */
      fv_expl_temp.Cost[0] = c_expl_temp.Cost[0];
      fv_expl_temp.Cost[1] = c_expl_temp.Cost[1];
      fv_expl_temp.Cost[2] = c_expl_temp.Cost[2];
      fv_expl_temp.Cost[3] = c_expl_temp.Cost[3];
      fv_expl_temp.ClassLogicalIndices[0] = c_expl_temp.ClassLogicalIndices[0];
      fv_expl_temp.Prior[0] = c_expl_temp.Prior[0];
      fv_expl_temp.ClassNames[0] = c_expl_temp.ClassNames[0];
      fv_expl_temp.ClassLogicalIndices[1] = c_expl_temp.ClassLogicalIndices[1];
      fv_expl_temp.Prior[1] = c_expl_temp.Prior[1];
      fv_expl_temp.ClassNames[1] = c_expl_temp.ClassNames[1];
      mv_expl_temp.Cost[0] = d_expl_temp.Cost[0];
      mv_expl_temp.Cost[1] = d_expl_temp.Cost[1];
      mv_expl_temp.Cost[2] = d_expl_temp.Cost[2];
      mv_expl_temp.Cost[3] = d_expl_temp.Cost[3];
      mv_expl_temp.ClassLogicalIndices[0] = d_expl_temp.ClassLogicalIndices[0];
      mv_expl_temp.Prior[0] = d_expl_temp.Prior[0];
      mv_expl_temp.ClassNames[0] = d_expl_temp.ClassNames[0];
      mv_expl_temp.ClassLogicalIndices[1] = d_expl_temp.ClassLogicalIndices[1];
      mv_expl_temp.Prior[1] = d_expl_temp.Prior[1];
      mv_expl_temp.ClassNames[1] = d_expl_temp.ClassNames[1];
      qv_expl_temp.Cost[0] = e_expl_temp.Cost[0];
      qv_expl_temp.Cost[1] = e_expl_temp.Cost[1];
      qv_expl_temp.Cost[2] = e_expl_temp.Cost[2];
      qv_expl_temp.Cost[3] = e_expl_temp.Cost[3];
      qv_expl_temp.ClassLogicalIndices[0] = e_expl_temp.ClassLogicalIndices[0];
      qv_expl_temp.Prior[0] = e_expl_temp.Prior[0];
      qv_expl_temp.ClassNames[0] = e_expl_temp.ClassNames[0];
      qv_expl_temp.ClassLogicalIndices[1] = e_expl_temp.ClassLogicalIndices[1];
      qv_expl_temp.Prior[1] = e_expl_temp.Prior[1];
      qv_expl_temp.ClassNames[1] = e_expl_temp.ClassNames[1];
      memcpy(&fv_expl_temp.LearnerWeights[0], &c_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&mv_expl_temp.LearnerWeights[0], &d_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      memcpy(&qv_expl_temp.LearnerWeights[0], &e_expl_temp.LearnerWeights[0],
             30U * sizeof(double));
      for (c_i = 0; c_i < 30; c_i++) {
        fv_expl_temp.IsCached[c_i] = c_expl_temp.IsCached[c_i];
        mv_expl_temp.IsCached[c_i] = d_expl_temp.IsCached[c_i];
        qv_expl_temp.IsCached[c_i] = e_expl_temp.IsCached[c_i];
      }

      Yuxuan_iterative_test(*(double (*)[30720])&ECG_Gray_Window[2734080],
                            *(double (*)[30720])&Spo2_Gray_Window[2734080], Fs,
                            Nbr_RR, classifier1_IsCached, classifier1_ClassNames,
                            classifier1_Prior, classifier2_IsCached,
                            classifier2_ClassNames, classifier2_Prior,
                            &fv_expl_temp, &mv_expl_temp, &qv_expl_temp,
                            norm_coef1, norm_coef2, norm_coef3, norm_coef4,
                            norm_coef5, wind_len, conf_seiz, masks, pred_mask,
                            pred_conf, mask_apply_data, expl_temp);
      varargin_1_size_idx_0 = nd_reshapes[0].f1->size[0];
      c_i = nd_reshapes[0].f1->size[1];
      varargin_1_size_idx_1 = nd_reshapes[0].f1->size[1] + sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        loop_ub = nd_reshapes[0].f1->size[0];
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_1_data[i4 + varargin_1_size_idx_0 * i1] = nd_reshapes[0]
            .f1->data[i4 + nd_reshapes[0].f1->size[0] * i1];
        }
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_1_data[varargin_1_size_idx_0 * (i1 + nd_reshapes[0].f1->size[1])]
          = varargin_2_data[i1];
      }

      if (varargin_1_size_idx_1 != 0) {
        i5 += sizes_idx_1;
      } else {
        i5 = 0;
      }

      if (expl_temp[1] != 0) {
        sizes_idx_1 = (signed char)expl_temp[1];
      } else {
        sizes_idx_1 = 0;
      }

      c_i = expl_temp[0] * expl_temp[1];
      for (i1 = 0; i1 < c_i; i1++) {
        varargin_2_data[i1] = pred_mask[(int)mask_apply_data[i1] - 1];
      }

      pred_label_size[0] = 1;
      pred_label_size[1] = i5 + sizes_idx_1;
      c_i = i5;
      if (0 <= c_i - 1) {
        memcpy(&pred_label_data[0], &varargin_1_data[0], c_i * sizeof(double));
      }

      c_i = sizes_idx_1;
      for (i1 = 0; i1 < c_i; i1++) {
        pred_label_data[i1 + i5] = varargin_2_data[i1];
      }

      c_i = u + 2;
      if (0 <= result_size_idx_0 - 1) {
        memcpy(&b_true_label_data[0], &result_data[0], result_size_idx_0 *
               sizeof(signed char));
      }

      b_true_label_data[u + 1] = 0;
      true_label_size[0] = u + 2;
      true_label_size[1] = 1;
      for (i1 = 0; i1 < c_i; i1++) {
        true_label_data[i1] = b_true_label_data[i1];
      }

      /*  ------------------------------------------------------------ */
    }

    /*  ============================================================ */
    /*  ============================================================ */
  }

  emxFreeMatrix_cell_wrap_66(nd_reshapes);
  emxFreeMatrix_cell_wrap_66(md_reshapes);
  emxFreeMatrix_cell_wrap_66(ld_reshapes);
  emxFreeMatrix_cell_wrap_66(kd_reshapes);
  emxFreeMatrix_cell_wrap_66(jd_reshapes);
  emxFreeMatrix_cell_wrap_66(id_reshapes);
  emxFreeMatrix_cell_wrap_66(hd_reshapes);
  emxFreeMatrix_cell_wrap_66(gd_reshapes);
  emxFreeMatrix_cell_wrap_66(fd_reshapes);
  emxFreeMatrix_cell_wrap_66(ed_reshapes);
  emxFreeMatrix_cell_wrap_66(dd_reshapes);
  emxFreeMatrix_cell_wrap_66(cd_reshapes);
  emxFreeMatrix_cell_wrap_66(bd_reshapes);
  emxFreeMatrix_cell_wrap_66(ad_reshapes);
  emxFreeMatrix_cell_wrap_66(yc_reshapes);
  emxFreeMatrix_cell_wrap_66(xc_reshapes);
  emxFreeMatrix_cell_wrap_66(wc_reshapes);
  emxFreeMatrix_cell_wrap_66(vc_reshapes);
  emxFreeMatrix_cell_wrap_66(uc_reshapes);
  emxFreeMatrix_cell_wrap_66(tc_reshapes);
  emxFreeMatrix_cell_wrap_66(sc_reshapes);
  emxFreeMatrix_cell_wrap_66(rc_reshapes);
  emxFreeMatrix_cell_wrap_66(qc_reshapes);
  emxFreeMatrix_cell_wrap_66(pc_reshapes);
  emxFreeMatrix_cell_wrap_66(oc_reshapes);
  emxFreeMatrix_cell_wrap_66(nc_reshapes);
  emxFreeMatrix_cell_wrap_66(mc_reshapes);
  emxFreeMatrix_cell_wrap_66(lc_reshapes);
  emxFreeMatrix_cell_wrap_66(kc_reshapes);
  emxFreeMatrix_cell_wrap_66(jc_reshapes);
  emxFreeMatrix_cell_wrap_66(ic_reshapes);
  emxFreeMatrix_cell_wrap_66(hc_reshapes);
  emxFreeMatrix_cell_wrap_66(gc_reshapes);
  emxFreeMatrix_cell_wrap_66(fc_reshapes);
  emxFreeMatrix_cell_wrap_66(ec_reshapes);
  emxFreeMatrix_cell_wrap_66(dc_reshapes);
  emxFreeMatrix_cell_wrap_66(cc_reshapes);
  emxFreeMatrix_cell_wrap_66(bc_reshapes);
  emxFreeMatrix_cell_wrap_66(ac_reshapes);
  emxFreeMatrix_cell_wrap_66(yb_reshapes);
  emxFreeMatrix_cell_wrap_66(xb_reshapes);
  emxFreeMatrix_cell_wrap_66(wb_reshapes);
  emxFreeMatrix_cell_wrap_66(vb_reshapes);
  emxFreeMatrix_cell_wrap_66(ub_reshapes);
  emxFreeMatrix_cell_wrap_66(tb_reshapes);
  emxFreeMatrix_cell_wrap_66(sb_reshapes);
  emxFreeMatrix_cell_wrap_66(rb_reshapes);
  emxFreeMatrix_cell_wrap_66(qb_reshapes);
  emxFreeMatrix_cell_wrap_66(pb_reshapes);
  emxFreeMatrix_cell_wrap_66(ob_reshapes);
  emxFreeMatrix_cell_wrap_66(nb_reshapes);
  emxFreeMatrix_cell_wrap_66(mb_reshapes);
  emxFreeMatrix_cell_wrap_66(lb_reshapes);
  emxFreeMatrix_cell_wrap_66(kb_reshapes);
  emxFreeMatrix_cell_wrap_66(jb_reshapes);
  emxFreeMatrix_cell_wrap_66(ib_reshapes);
  emxFreeMatrix_cell_wrap_66(hb_reshapes);
  emxFreeMatrix_cell_wrap_66(gb_reshapes);
  emxFreeMatrix_cell_wrap_66(fb_reshapes);
  emxFreeMatrix_cell_wrap_66(eb_reshapes);
  emxFreeMatrix_cell_wrap_66(db_reshapes);
  emxFreeMatrix_cell_wrap_66(cb_reshapes);
  emxFreeMatrix_cell_wrap_66(bb_reshapes);
  emxFreeMatrix_cell_wrap_66(ab_reshapes);
  emxFreeMatrix_cell_wrap_66(y_reshapes);
  emxFreeMatrix_cell_wrap_66(x_reshapes);
  emxFreeMatrix_cell_wrap_66(w_reshapes);
  emxFreeMatrix_cell_wrap_66(v_reshapes);
  emxFreeMatrix_cell_wrap_66(u_reshapes);
  emxFreeMatrix_cell_wrap_66(t_reshapes);
  emxFreeMatrix_cell_wrap_66(s_reshapes);
  emxFreeMatrix_cell_wrap_66(r_reshapes);
  emxFreeMatrix_cell_wrap_66(q_reshapes);
  emxFreeMatrix_cell_wrap_66(p_reshapes);
  emxFreeMatrix_cell_wrap_66(o_reshapes);
  emxFreeMatrix_cell_wrap_66(n_reshapes);
  emxFreeMatrix_cell_wrap_66(m_reshapes);
  emxFreeMatrix_cell_wrap_66(l_reshapes);
  emxFreeMatrix_cell_wrap_66(k_reshapes);
  emxFreeMatrix_cell_wrap_66(j_reshapes);
  emxFreeMatrix_cell_wrap_66(i_reshapes);
  emxFreeMatrix_cell_wrap_66(h_reshapes);
  emxFreeMatrix_cell_wrap_66(g_reshapes);
  emxFreeMatrix_cell_wrap_66(f_reshapes);
  emxFreeMatrix_cell_wrap_66(e_reshapes);
  emxFreeMatrix_cell_wrap_66(d_reshapes);
  emxFreeMatrix_cell_wrap_66(c_reshapes);
  emxFreeMatrix_cell_wrap_66(b_reshapes);
  emxFreeMatrix_cell_wrap_66(reshapes);
}

/* End of code generation (profile_Yuxuan_iteration.c) */
