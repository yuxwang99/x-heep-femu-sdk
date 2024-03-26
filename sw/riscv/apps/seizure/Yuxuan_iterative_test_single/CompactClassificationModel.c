/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationModel.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "CompactClassificationModel.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_internal_types.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "all.h"
#include "eye.h"
#include "isnan.h"
#include "minOrMax.h"
#include "mtimes.h"
#include "repmat.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void
ac_CompactClassificationModel_s(q_classreg_learning_classif_Com *obj);

static void
af_CompactClassificationModel_s(qb_classreg_learning_classif_Co *obj);

static void
ag_CompactClassificationModel_s(yb_classreg_learning_classif_Co *obj);

static void
bb_CompactClassificationModel_s(i_classreg_learning_classif_Com *obj);

static void
be_CompactClassificationModel_s(ib_classreg_learning_classif_Co *obj);

static void
cd_CompactClassificationModel_s(ab_classreg_learning_classif_Co *obj);

static void
dc_CompactClassificationModel_s(r_classreg_learning_classif_Com *obj);

static void
df_CompactClassificationModel_s(rb_classreg_learning_classif_Co *obj);

static void
eb_CompactClassificationModel_s(j_classreg_learning_classif_Com *obj);

static void
ee_CompactClassificationModel_s(jb_classreg_learning_classif_Co *obj);

static void
fd_CompactClassificationModel_s(bb_classreg_learning_classif_Co *obj);

static void
fg_CompactClassificationModel_s(ac_classreg_learning_classif_Co *obj);

static void
gc_CompactClassificationModel_s(s_classreg_learning_classif_Com *obj);

static void
gf_CompactClassificationModel_s(sb_classreg_learning_classif_Co *obj);

static void
hb_CompactClassificationModel_s(k_classreg_learning_classif_Com *obj);

static void
he_CompactClassificationModel_s(kb_classreg_learning_classif_Co *obj);

static void
i_CompactClassificationModel_se(c_classreg_learning_classif_Com *obj);

static void
id_CompactClassificationModel_s(cb_classreg_learning_classif_Co *obj);

static void
ig_CompactClassificationModel_s(bc_classreg_learning_classif_Co *obj);

static void
jc_CompactClassificationModel_s(t_classreg_learning_classif_Com *obj);

static void
jf_CompactClassificationModel_s(tb_classreg_learning_classif_Co *obj);

static void
kb_CompactClassificationModel_s(l_classreg_learning_classif_Com *obj);

static void
ke_CompactClassificationModel_s(lb_classreg_learning_classif_Co *obj);

static void
l_CompactClassificationModel_se(d_classreg_learning_classif_Com *obj);

static void
ld_CompactClassificationModel_s(db_classreg_learning_classif_Co *obj);

static void
mc_CompactClassificationModel_s(u_classreg_learning_classif_Com *obj);

static void
mf_CompactClassificationModel_s(ub_classreg_learning_classif_Co *obj);

static void
nb_CompactClassificationModel_s(m_classreg_learning_classif_Com *obj);

static void
ne_CompactClassificationModel_s(mb_classreg_learning_classif_Co *obj);

static void
o_CompactClassificationModel_se(e_classreg_learning_classif_Com *obj);

static void
od_CompactClassificationModel_s(eb_classreg_learning_classif_Co *obj);

static void
og_CompactClassificationModel_s(cc_classreg_learning_classif_Co *obj);

static void
pc_CompactClassificationModel_s(v_classreg_learning_classif_Com *obj);

static void
pf_CompactClassificationModel_s(vb_classreg_learning_classif_Co *obj);

static void
qb_CompactClassificationModel_s(n_classreg_learning_classif_Com *obj);

static void
qe_CompactClassificationModel_s(nb_classreg_learning_classif_Co *obj);

static void
r_CompactClassificationModel_se(f_classreg_learning_classif_Com *obj);

static void
rd_CompactClassificationModel_s(fb_classreg_learning_classif_Co *obj);

static void
sc_CompactClassificationModel_s(w_classreg_learning_classif_Com *obj);

static void
sf_CompactClassificationModel_s(wb_classreg_learning_classif_Co *obj);

static void
sg_CompactClassificationModel_s(dc_classreg_learning_classif_Co *obj);

static void
tb_CompactClassificationModel_s(o_classreg_learning_classif_Com *obj);

static void
te_CompactClassificationModel_s(ob_classreg_learning_classif_Co *obj);

static void
u_CompactClassificationModel_se(g_classreg_learning_classif_Com *obj);

static void
ud_CompactClassificationModel_s(gb_classreg_learning_classif_Co *obj);

static void
vc_CompactClassificationModel_s(x_classreg_learning_classif_Com *obj);

static void
vg_CompactClassificationModel_s(ec_classreg_learning_classif_Co *obj);

static void
wb_CompactClassificationModel_s(p_classreg_learning_classif_Com *obj);

static void
we_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj);

static void
wf_CompactClassificationModel_s(xb_classreg_learning_classif_Co *obj);

static void
x_CompactClassificationModel_se(h_classreg_learning_classif_Com *obj);

static void
xd_CompactClassificationModel_s(hb_classreg_learning_classif_Co *obj);

static void
yc_CompactClassificationModel_s(y_classreg_learning_classif_Com *obj);

/* Function Definitions */
/*
 * Arguments    : q_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
ac_CompactClassificationModel_s(q_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : qb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
af_CompactClassificationModel_s(qb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : yb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
ag_CompactClassificationModel_s(yb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : i_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
bb_CompactClassificationModel_s(i_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : ib_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
be_CompactClassificationModel_s(ib_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : ab_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
cd_CompactClassificationModel_s(ab_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : r_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
dc_CompactClassificationModel_s(r_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : rb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
df_CompactClassificationModel_s(rb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : j_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
eb_CompactClassificationModel_s(j_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : jb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
ee_CompactClassificationModel_s(jb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : bb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
fd_CompactClassificationModel_s(bb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : ac_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
fg_CompactClassificationModel_s(ac_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : s_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
gc_CompactClassificationModel_s(s_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : sb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
gf_CompactClassificationModel_s(sb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : k_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
hb_CompactClassificationModel_s(k_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : kb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
he_CompactClassificationModel_s(kb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : c_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
i_CompactClassificationModel_se(c_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : cb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
id_CompactClassificationModel_s(cb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : bc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
ig_CompactClassificationModel_s(bc_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : t_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
jc_CompactClassificationModel_s(t_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : tb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
jf_CompactClassificationModel_s(tb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : l_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
kb_CompactClassificationModel_s(l_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : lb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
ke_CompactClassificationModel_s(lb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : d_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
l_CompactClassificationModel_se(d_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : db_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
ld_CompactClassificationModel_s(db_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : u_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
mc_CompactClassificationModel_s(u_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : ub_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
mf_CompactClassificationModel_s(ub_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : m_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
nb_CompactClassificationModel_s(m_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : mb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
ne_CompactClassificationModel_s(mb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : e_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
o_CompactClassificationModel_se(e_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : eb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
od_CompactClassificationModel_s(eb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : cc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
og_CompactClassificationModel_s(cc_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : v_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
pc_CompactClassificationModel_s(v_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : vb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
pf_CompactClassificationModel_s(vb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : n_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
qb_CompactClassificationModel_s(n_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : nb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
qe_CompactClassificationModel_s(nb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : f_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
r_CompactClassificationModel_se(f_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : fb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
rd_CompactClassificationModel_s(fb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : w_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
sc_CompactClassificationModel_s(w_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : wb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
sf_CompactClassificationModel_s(wb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : dc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
sg_CompactClassificationModel_s(dc_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : o_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
tb_CompactClassificationModel_s(o_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : ob_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
te_CompactClassificationModel_s(ob_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : g_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
u_CompactClassificationModel_se(g_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : gb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
ud_CompactClassificationModel_s(gb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : x_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
vc_CompactClassificationModel_s(x_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : ec_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
vg_CompactClassificationModel_s(ec_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : p_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
wb_CompactClassificationModel_s(p_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : pb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
we_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : xb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
wf_CompactClassificationModel_s(xb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : h_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
x_CompactClassificationModel_se(h_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : hb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
static void
xd_CompactClassificationModel_s(hb_classreg_learning_classif_Co *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : y_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
static void
yc_CompactClassificationModel_s(y_classreg_learning_classif_Com *obj)
{
  obj->ScoreTransform = Identity;
}

/*
 * Arguments    : ab_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ab_CompactClassificationModel_C(ab_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  cd_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : h_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void ab_CompactClassificationModel_s(h_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : ac_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ac_CompactClassificationModel_C(ac_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  fg_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : y_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void ad_CompactClassificationModel_s(y_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.39815259F;
  obj->Prior[1] = 0.60184741F;
}

/*
 * Arguments    : hb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ae_CompactClassificationModel_s(hb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : bb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void bb_CompactClassificationModel_C(bb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  fd_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : bc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void bc_CompactClassificationModel_C(bc_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  ig_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : q_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void bc_CompactClassificationModel_s(q_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.402744412F;
  obj->Prior[1] = 0.597255588F;
}

/*
 * Arguments    : y_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void bd_CompactClassificationModel_s(y_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : qb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void bf_CompactClassificationModel_s(qb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.401569754F;
  obj->Prior[1] = 0.598430216F;
}

/*
 * Arguments    : yb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void bg_CompactClassificationModel_s(yb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.39249292F;
  obj->Prior[1] = 0.60750705F;
}

/*
 * Arguments    : c_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void c_CompactClassificationModel_Co(c_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  i_CompactClassificationModel_se(obj);
}

/*
 * Arguments    : const float obj_Prior[2]
 *                const emxArray_real32_T *scores
 *                emxArray_real32_T *labels
 * Return Type  : void
 */
void c_CompactClassificationModel_ma(const float obj_Prior[2],
                                     const emxArray_real32_T *scores,
                                     emxArray_real32_T *labels)
{
  emxArray_boolean_T *notNaN;
  emxArray_boolean_T *r;
  emxArray_real32_T *classnum;
  const float *scores_data;
  float *classnum_data;
  float *labels_data;
  int i;
  int idx;
  int iindx;
  int loop_ub;
  boolean_T *notNaN_data;
  scores_data = scores->data;
  emxInit_boolean_T(&r, 2);
  e_isnan(scores, r);
  emxInit_boolean_T(&notNaN, 1);
  all(r, notNaN);
  notNaN_data = notNaN->data;
  emxFree_boolean_T(&r);
  loop_ub = notNaN->size[0];
  for (i = 0; i < loop_ub; i++) {
    notNaN_data[i] = !notNaN_data[i];
  }
  f_maximum(obj_Prior, &iindx);
  emxInit_real32_T(&classnum, 1);
  i = classnum->size[0];
  classnum->size[0] = scores->size[0];
  emxEnsureCapacity_real32_T(classnum, i);
  classnum_data = classnum->data;
  loop_ub = scores->size[0];
  for (i = 0; i < loop_ub; i++) {
    classnum_data[i] = rtNaNF;
  }
  i = notNaN->size[0];
  for (idx = 0; idx < i; idx++) {
    if (notNaN_data[idx]) {
      float b_scores[2];
      b_scores[0] = scores_data[idx];
      b_scores[1] = scores_data[idx + scores->size[0]];
      f_maximum(b_scores, &loop_ub);
      classnum_data[idx] = (float)loop_ub;
    }
  }
  c_repmat((signed char)(iindx - 1), scores->size[0], labels);
  labels_data = labels->data;
  i = notNaN->size[0];
  for (idx = 0; idx < i; idx++) {
    if (notNaN_data[idx]) {
      float ex;
      unsigned int u;
      ex = classnum_data[idx];
      if (ex < 4.2949673E+9F) {
        if (ex >= 0.0F) {
          u = (unsigned int)ex;
        } else {
          u = 0U;
        }
      } else {
        u = 0U;
      }
      labels_data[idx] = (signed char)((int)u - 1);
    }
  }
  emxFree_real32_T(&classnum);
  emxFree_boolean_T(&notNaN);
}

/*
 * Arguments    : const float obj_Prior[2]
 *                const float obj_Cost[4]
 *                const emxArray_real32_T *scoresIn
 *                emxArray_real32_T *labels
 *                emxArray_real32_T *classnum
 *                emxArray_real32_T *cost
 *                emxArray_real32_T *scores
 * Return Type  : void
 */
void c_CompactClassificationModel_mi(const float obj_Prior[2],
                                     const float obj_Cost[4],
                                     const emxArray_real32_T *scoresIn,
                                     emxArray_real32_T *labels,
                                     emxArray_real32_T *classnum,
                                     emxArray_real32_T *cost,
                                     emxArray_real32_T *scores)
{
  const float *scoresIn_data;
  float *classnum_data;
  float *cost_data;
  int b_iindx;
  int i;
  int idx;
  int iindx;
  scoresIn_data = scoresIn->data;
  c_mtimes(scoresIn, obj_Cost, cost);
  cost_data = cost->data;
  f_maximum(obj_Prior, &iindx);
  i = classnum->size[0];
  classnum->size[0] = scoresIn->size[0];
  emxEnsureCapacity_real32_T(classnum, i);
  classnum_data = classnum->data;
  i = scoresIn->size[0];
  for (idx = 0; idx < i; idx++) {
    float b_cost[2];
    b_cost[0] = cost_data[idx];
    b_cost[1] = cost_data[idx + cost->size[0]];
    d_minimum(b_cost, &b_iindx);
    classnum_data[idx] = (float)b_iindx;
  }
  c_repmat((signed char)(iindx - 1), scoresIn->size[0], labels);
  cost_data = labels->data;
  i = scoresIn->size[0];
  for (idx = 0; idx < i; idx++) {
    float ex;
    unsigned int u;
    ex = classnum_data[idx];
    if (ex >= 0.0F) {
      u = (unsigned int)ex;
    } else {
      u = 0U;
    }
    cost_data[idx] = (signed char)((int)u - 1);
  }
  i = scores->size[0] * scores->size[1];
  scores->size[0] = scoresIn->size[0];
  scores->size[1] = 2;
  emxEnsureCapacity_real32_T(scores, i);
  cost_data = scores->data;
  iindx = scoresIn->size[0] << 1;
  for (i = 0; i < iindx; i++) {
    cost_data[i] = scoresIn_data[i];
  }
}

/*
 * Arguments    : fc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void c_CompactClassificationModel_se(fc_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397992432F;
  obj->Prior[1] = 0.602007568F;
}

/*
 * Arguments    : cb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void cb_CompactClassificationModel_C(cb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  id_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : i_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void cb_CompactClassificationModel_s(i_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.401890129F;
  obj->Prior[1] = 0.598109901F;
}

/*
 * Arguments    : cc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void cc_CompactClassificationModel_C(cc_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  og_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : q_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void cc_CompactClassificationModel_s(q_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : ib_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ce_CompactClassificationModel_s(ib_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397405088F;
  obj->Prior[1] = 0.602594912F;
}

/*
 * Arguments    : qb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void cf_CompactClassificationModel_s(qb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : yb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void cg_CompactClassificationModel_s(yb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : d_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void d_CompactClassificationModel_Co(d_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  l_CompactClassificationModel_se(obj);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void d_CompactClassificationModel_se(void)
{
  float fv[4];
  eye(fv);
}

/*
 * Arguments    : db_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void db_CompactClassificationModel_C(db_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  ld_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : i_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void db_CompactClassificationModel_s(i_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : dc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void dc_CompactClassificationModel_C(dc_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  sg_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : ab_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void dd_CompactClassificationModel_s(ab_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397725463F;
  obj->Prior[1] = 0.602274537F;
}

/*
 * Arguments    : ib_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void de_CompactClassificationModel_s(ib_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : pb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void dg_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.404346198F;
  obj->Prior[1] = 0.595653772F;
}

/*
 * Arguments    : e_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void e_CompactClassificationModel_Co(e_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  o_CompactClassificationModel_se(obj);
}

/*
 * Arguments    : gc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void e_CompactClassificationModel_se(gc_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397992432F;
  obj->Prior[1] = 0.602007568F;
}

/*
 * Arguments    : eb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void eb_CompactClassificationModel_C(eb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  od_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : ec_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ec_CompactClassificationModel_C(ec_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  vg_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : r_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void ec_CompactClassificationModel_s(r_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.403064758F;
  obj->Prior[1] = 0.596935213F;
}

/*
 * Arguments    : ab_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ed_CompactClassificationModel_s(ab_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : rb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ef_CompactClassificationModel_s(rb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.398045808F;
  obj->Prior[1] = 0.601954162F;
}

/*
 * Arguments    : pb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void eg_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397405088F;
  obj->Prior[1] = 0.602594912F;
}

/*
 * Arguments    : f_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void f_CompactClassificationModel_Co(f_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  r_CompactClassificationModel_se(obj);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void f_CompactClassificationModel_se(void)
{
  float fv[4];
  eye(fv);
}

/*
 * Arguments    : fb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void fb_CompactClassificationModel_C(fb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  rd_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : j_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void fb_CompactClassificationModel_s(j_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.40135619F;
  obj->Prior[1] = 0.598643839F;
}

/*
 * Arguments    : r_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void fc_CompactClassificationModel_s(r_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : jb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void fe_CompactClassificationModel_s(jb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397565275F;
  obj->Prior[1] = 0.602434754F;
}

/*
 * Arguments    : rb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ff_CompactClassificationModel_s(rb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : g_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void g_CompactClassificationModel_Co(g_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  u_CompactClassificationModel_se(obj);
}

/*
 * Arguments    : fc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void g_CompactClassificationModel_se(fc_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397992432F;
  obj->Prior[1] = 0.602007568F;
}

/*
 * Arguments    : gb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void gb_CompactClassificationModel_C(gb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  ud_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : j_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void gb_CompactClassificationModel_s(j_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : bb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void gd_CompactClassificationModel_s(bb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397458494F;
  obj->Prior[1] = 0.602541506F;
}

/*
 * Arguments    : jb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ge_CompactClassificationModel_s(jb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : ac_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void gg_CompactClassificationModel_s(ac_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.39377436F;
  obj->Prior[1] = 0.60622561F;
}

/*
 * Arguments    : h_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void h_CompactClassificationModel_Co(h_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  x_CompactClassificationModel_se(obj);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void h_CompactClassificationModel_se(void)
{
  float fv[4];
  eye(fv);
}

/*
 * Arguments    : hb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void hb_CompactClassificationModel_C(hb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  xd_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : s_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void hc_CompactClassificationModel_s(s_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.394895613F;
  obj->Prior[1] = 0.605104387F;
}

/*
 * Arguments    : bb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void hd_CompactClassificationModel_s(bb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : sb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void hf_CompactClassificationModel_s(sb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.399327248F;
  obj->Prior[1] = 0.600672781F;
}

/*
 * Arguments    : ac_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void hg_CompactClassificationModel_s(ac_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : i_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void i_CompactClassificationModel_Co(i_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  bb_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : ib_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ib_CompactClassificationModel_C(ib_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  be_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : k_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void ib_CompactClassificationModel_s(k_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.399754405F;
  obj->Prior[1] = 0.600245595F;
}

/*
 * Arguments    : s_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void ic_CompactClassificationModel_s(s_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : kb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ie_CompactClassificationModel_s(kb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397885621F;
  obj->Prior[1] = 0.602114379F;
}

/*
 * Arguments    : sb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void if_CompactClassificationModel_s(sb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : j_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void j_CompactClassificationModel_Co(j_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  eb_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : c_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void j_CompactClassificationModel_se(c_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.397405088F;
  obj->Prior[1] = 0.602594912F;
}

/*
 * Arguments    : jb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void jb_CompactClassificationModel_C(jb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  ee_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : k_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void jb_CompactClassificationModel_s(k_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : cb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void jd_CompactClassificationModel_s(cb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.398312777F;
  obj->Prior[1] = 0.601687253F;
}

/*
 * Arguments    : kb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void je_CompactClassificationModel_s(kb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : bc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void jg_CompactClassificationModel_s(bc_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.401729941F;
  obj->Prior[1] = 0.598270059F;
}

/*
 * Arguments    : k_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void k_CompactClassificationModel_Co(k_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  hb_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : c_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void k_CompactClassificationModel_se(c_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : kb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void kb_CompactClassificationModel_C(kb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  he_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : t_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void kc_CompactClassificationModel_s(t_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.396230459F;
  obj->Prior[1] = 0.603769541F;
}

/*
 * Arguments    : cb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void kd_CompactClassificationModel_s(cb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : tb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void kf_CompactClassificationModel_s(tb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.392332733F;
  obj->Prior[1] = 0.607667267F;
}

/*
 * Arguments    : bc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void kg_CompactClassificationModel_s(bc_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : l_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void l_CompactClassificationModel_Co(l_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  kb_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : lb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void lb_CompactClassificationModel_C(lb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  ke_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : l_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void lb_CompactClassificationModel_s(l_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.398579746F;
  obj->Prior[1] = 0.601420283F;
}

/*
 * Arguments    : t_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void lc_CompactClassificationModel_s(t_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : lb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void le_CompactClassificationModel_s(lb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.404186F;
  obj->Prior[1] = 0.595814F;
}

/*
 * Arguments    : tb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void lf_CompactClassificationModel_s(tb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : qb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void lg_CompactClassificationModel_s(qb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.399754405F;
  obj->Prior[1] = 0.600245595F;
}

/*
 * Arguments    : m_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void m_CompactClassificationModel_Co(m_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  nb_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : d_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void m_CompactClassificationModel_se(d_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.393720955F;
  obj->Prior[1] = 0.606279F;
}

/*
 * Arguments    : mb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void mb_CompactClassificationModel_C(mb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  ne_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : l_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void mb_CompactClassificationModel_s(l_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : db_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void md_CompactClassificationModel_s(db_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.399807781F;
  obj->Prior[1] = 0.600192189F;
}

/*
 * Arguments    : lb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void me_CompactClassificationModel_s(lb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : nb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void mg_CompactClassificationModel_s(nb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.39751187F;
  obj->Prior[1] = 0.602488101F;
}

/*
 * Arguments    : n_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void n_CompactClassificationModel_Co(n_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  qb_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : d_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void n_CompactClassificationModel_se(d_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : nb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void nb_CompactClassificationModel_C(nb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  qe_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : u_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void nc_CompactClassificationModel_s(u_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.398579746F;
  obj->Prior[1] = 0.601420283F;
}

/*
 * Arguments    : db_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void nd_CompactClassificationModel_s(db_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : ub_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void nf_CompactClassificationModel_s(ub_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.39815259F;
  obj->Prior[1] = 0.60184741F;
}

/*
 * Arguments    : vb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ng_CompactClassificationModel_s(vb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.398686528F;
  obj->Prior[1] = 0.601313472F;
}

/*
 * Arguments    : o_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void o_CompactClassificationModel_Co(o_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  tb_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : ob_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ob_CompactClassificationModel_C(ob_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  te_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : m_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void ob_CompactClassificationModel_s(m_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.396016866F;
  obj->Prior[1] = 0.603983104F;
}

/*
 * Arguments    : u_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void oc_CompactClassificationModel_s(u_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : mb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void oe_CompactClassificationModel_s(mb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.399060279F;
  obj->Prior[1] = 0.600939691F;
}

/*
 * Arguments    : ub_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void of_CompactClassificationModel_s(ub_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : p_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void p_CompactClassificationModel_Co(p_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  wb_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : e_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void p_CompactClassificationModel_se(e_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.401569754F;
  obj->Prior[1] = 0.598430216F;
}

/*
 * Arguments    : pb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void pb_CompactClassificationModel_C(pb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  we_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : m_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void pb_CompactClassificationModel_s(m_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : eb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void pd_CompactClassificationModel_s(eb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.399220467F;
  obj->Prior[1] = 0.600779533F;
}

/*
 * Arguments    : mb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void pe_CompactClassificationModel_s(mb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : cc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void pg_CompactClassificationModel_s(cc_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.395429552F;
  obj->Prior[1] = 0.604570448F;
}

/*
 * Arguments    : q_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void q_CompactClassificationModel_Co(q_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  ac_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : e_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void q_CompactClassificationModel_se(e_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : qb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void qb_CompactClassificationModel_C(qb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  af_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : v_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void qc_CompactClassificationModel_s(v_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.402050287F;
  obj->Prior[1] = 0.597949684F;
}

/*
 * Arguments    : eb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void qd_CompactClassificationModel_s(eb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : vb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void qf_CompactClassificationModel_s(vb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.396123648F;
  obj->Prior[1] = 0.603876352F;
}

/*
 * Arguments    : cc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void qg_CompactClassificationModel_s(cc_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : r_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void r_CompactClassificationModel_Co(r_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  dc_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : rb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void rb_CompactClassificationModel_C(rb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  df_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : n_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void rb_CompactClassificationModel_s(n_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.403118163F;
  obj->Prior[1] = 0.596881866F;
}

/*
 * Arguments    : v_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void rc_CompactClassificationModel_s(v_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : nb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void re_CompactClassificationModel_s(nb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.394521862F;
  obj->Prior[1] = 0.605478108F;
}

/*
 * Arguments    : vb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void rf_CompactClassificationModel_s(vb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : rb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void rg_CompactClassificationModel_s(rb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.397725463F;
  obj->Prior[1] = 0.602274537F;
}

/*
 * Arguments    : s_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void s_CompactClassificationModel_Co(s_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  gc_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : f_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void s_CompactClassificationModel_se(f_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.392386138F;
  obj->Prior[1] = 0.607613862F;
}

/*
 * Arguments    : sb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void sb_CompactClassificationModel_C(sb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  gf_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : n_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void sb_CompactClassificationModel_s(n_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : fb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void sd_CompactClassificationModel_s(fb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.404559761F;
  obj->Prior[1] = 0.595440209F;
}

/*
 * Arguments    : nb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void se_CompactClassificationModel_s(nb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : t_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void t_CompactClassificationModel_Co(t_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  jc_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : f_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void t_CompactClassificationModel_se(f_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : tb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void tb_CompactClassificationModel_C(tb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  jf_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : w_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void tc_CompactClassificationModel_s(w_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.398045808F;
  obj->Prior[1] = 0.601954162F;
}

/*
 * Arguments    : fb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void td_CompactClassificationModel_s(fb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : wb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void tf_CompactClassificationModel_s(wb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.396177053F;
  obj->Prior[1] = 0.603822947F;
}

/*
 * Arguments    : dc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void tg_CompactClassificationModel_s(dc_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.395109177F;
  obj->Prior[1] = 0.604890823F;
}

/*
 * Arguments    : u_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void u_CompactClassificationModel_Co(u_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  mc_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : ub_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ub_CompactClassificationModel_C(ub_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  mf_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : o_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void ub_CompactClassificationModel_s(o_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.399967968F;
  obj->Prior[1] = 0.600032032F;
}

/*
 * Arguments    : w_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void uc_CompactClassificationModel_s(w_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : ob_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ue_CompactClassificationModel_s(ob_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.400822252F;
  obj->Prior[1] = 0.599177718F;
}

/*
 * Arguments    : wb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void uf_CompactClassificationModel_s(wb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : dc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ug_CompactClassificationModel_s(dc_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : v_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void v_CompactClassificationModel_Co(v_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  pc_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : g_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void v_CompactClassificationModel_se(g_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.397084743F;
  obj->Prior[1] = 0.602915287F;
}

/*
 * Arguments    : vb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void vb_CompactClassificationModel_C(vb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  pf_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : o_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void vb_CompactClassificationModel_s(o_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : gb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void vd_CompactClassificationModel_s(gb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.402530849F;
  obj->Prior[1] = 0.597469151F;
}

/*
 * Arguments    : ob_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ve_CompactClassificationModel_s(ob_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : ub_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void vf_CompactClassificationModel_s(ub_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.39468205F;
  obj->Prior[1] = 0.60531795F;
}

/*
 * Arguments    : w_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void w_CompactClassificationModel_Co(w_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  sc_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : g_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void w_CompactClassificationModel_se(g_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : wb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void wb_CompactClassificationModel_C(wb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  sf_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : x_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void wc_CompactClassificationModel_s(x_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.395696521F;
  obj->Prior[1] = 0.604303479F;
}

/*
 * Arguments    : gb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void wd_CompactClassificationModel_s(gb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : ec_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void wg_CompactClassificationModel_s(ec_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.399273843F;
  obj->Prior[1] = 0.600726128F;
}

/*
 * Arguments    : x_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void x_CompactClassificationModel_Co(x_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  vc_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : xb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void xb_CompactClassificationModel_C(xb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  wf_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : p_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void xb_CompactClassificationModel_s(p_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.399273843F;
  obj->Prior[1] = 0.600726128F;
}

/*
 * Arguments    : x_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void xc_CompactClassificationModel_s(x_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : pb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void xe_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.40071547F;
  obj->Prior[1] = 0.59928453F;
}

/*
 * Arguments    : xb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void xf_CompactClassificationModel_s(xb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.394788831F;
  obj->Prior[1] = 0.605211198F;
}

/*
 * Arguments    : ec_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void xg_CompactClassificationModel_s(ec_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : y_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void y_CompactClassificationModel_Co(y_classreg_learning_classif_Com *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  yc_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : h_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void y_CompactClassificationModel_se(h_classreg_learning_classif_Com *obj)
{
  obj->Prior[0] = 0.390944511F;
  obj->Prior[1] = 0.609055459F;
}

/*
 * Arguments    : yb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void yb_CompactClassificationModel_C(yb_classreg_learning_classif_Co *obj)
{
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  ag_CompactClassificationModel_s(obj);
}

/*
 * Arguments    : p_classreg_learning_classif_Com *obj
 * Return Type  : void
 */
void yb_CompactClassificationModel_s(p_classreg_learning_classif_Com *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : hb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void yd_CompactClassificationModel_s(hb_classreg_learning_classif_Co *obj)
{
  obj->Prior[0] = 0.400555283F;
  obj->Prior[1] = 0.599444687F;
}

/*
 * Arguments    : pb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void ye_CompactClassificationModel_s(pb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * Arguments    : xb_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void yf_CompactClassificationModel_s(xb_classreg_learning_classif_Co *obj)
{
  float fv[4];
  eye(fv);
  obj->Cost[0] = 1.0F - fv[0];
  obj->Cost[1] = 1.0F - fv[1];
  obj->Cost[2] = 1.0F - fv[2];
  obj->Cost[3] = 1.0F - fv[3];
}

/*
 * File trailer for CompactClassificationModel.c
 *
 * [EOF]
 */
