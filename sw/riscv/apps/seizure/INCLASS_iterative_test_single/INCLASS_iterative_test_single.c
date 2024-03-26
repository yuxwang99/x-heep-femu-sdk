/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: INCLASS_iterative_test_single.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "INCLASS_iterative_test_single.h"
#include "CompactClassificationEnsemble.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_internal_types.h"
#include "INCLASS_iterative_test_single_types.h"
#include "abs.h"
#include "bandpower.h"
#include "bitsra.h"
#include "combineVectorElements.h"
#include "diff.h"
#include "div.h"
#include "eml_mtimes_helper.h"
#include "filter.h"
#include "find.h"
#include "findpeaks.h"
#include "floor.h"
#include "ifWhileCond.h"
#include "isinf.h"
#include "isnan.h"
#include "log10.h"
#include "mean.h"
#include "minOrMax.h"
#include "movmedian.h"
#include "movsum.h"
#include "mrdivide_helper.h"
#include "nonzeros.h"
#include "nullAssignment.h"
#include "plomb.h"
#include "power.h"
#include "repmat.h"
#include "round.h"
#include "rt_nonfinite.h"
#include "sqrt1.h"
#include "std.h"
#include "sum.h"
#include "unique.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static float Feature1(const float RR_Interv_data[],
                      const int RR_Interv_size[2]);

static float Feature10(const float CSI_filt_data[], float Slope);

static float Feature14(const float CSI_data[]);

static float Feature16(const emxArray_real32_T *Spo2_sig,
                       const emxArray_real32_T *Rlocs, float i);

static float Feature17(const emxArray_real32_T *Spo2_sig,
                       const emxArray_real32_T *Rlocs, float i);

static float Feature2(const float RR_Interv_data[],
                      const int RR_Interv_size[2]);

static float Feature3(const float RR_Interv_data[],
                      const int RR_Interv_size[2]);

static float Feature4(const float RR_Interv_data[],
                      const int RR_Interv_size[2]);

static void Feature5(const emxArray_real32_T *pxx, const emxArray_real32_T *f,
                     float Tot_pow_data[], int Tot_pow_size[2]);

static float Feature6(const emxArray_real32_T *pxx, const emxArray_real32_T *f,
                      const float freq_range[2], const float Tot_pow_data[],
                      const int Tot_pow_size[2], float *Freq_betw_04_15);

static float Feature7(const emxArray_real32_T *pxx, const emxArray_real32_T *f,
                      const float Tot_pow_data[], const int Tot_pow_size[2],
                      float *Freq_betw_15_40);

static float Feature8(float Freq_betw_04_15, float Freq_betw_15_40);

static float Lorenz_features(
    const float RR_Interv_filtr[400], const float RR_Interv[400], float i,
    const emxArray_real32_T *tHRV, int idx9, int idx10, int idx11, int idx12,
    int idx13, int idx14, int idx15, float CSI_filt_data[],
    int CSI_filt_size[2], float Mod_CSI_filt_data[], int Mod_CSI_filt_size[2],
    float CSI_data[], int CSI_size[2], float Mod_CSI_data[],
    int Mod_CSI_size[2], float HR_diff_orig_data[], int HR_diff_orig_size[2]);

static void Lorenz_plot(const float R_R_interval_data[],
                        const int R_R_interval_size[2], float CSI_data[],
                        int CSI_size[2], float Mod_CSI_data[],
                        int Mod_CSI_size[2], float CVI_data[], int CVI_size[2],
                        float HR_diff_data[], int HR_diff_size[2]);

static void Lorenz_plot_f10f11(const float RR_Interv_filtr[400], float i,
                               float CSI_filt_data[], int CSI_filt_size[2],
                               float Mod_CSI_filt_data[],
                               int Mod_CSI_filt_size[2]);

static void Lorenz_plot_f9f12f13f14f15(const float RR_Interv[400], float i,
                                       float CSI_data[], int CSI_size[2],
                                       float Mod_CSI_data[],
                                       int Mod_CSI_size[2],
                                       float HR_diff_orig_data[],
                                       int HR_diff_orig_size[2]);

static void b_minus(emxArray_real32_T *in1, const emxArray_real32_T *in2);

static int binary_expand_op(const emxArray_real32_T *in1,
                            const emxArray_real32_T *in2,
                            const gc_classreg_learning_classif_Co *in3,
                            float in4, float *out2, float *out3);

static int binary_expand_op_1(const emxArray_real32_T *in1,
                              const emxArray_real32_T *in2,
                              const gc_classreg_learning_classif_Co *in3,
                              float in4, float *out2, float *out3);

static int binary_expand_op_2(const emxArray_real32_T *in1,
                              const emxArray_real32_T *in2,
                              const gc_classreg_learning_classif_Co *in3,
                              float in4, float *out2, float *out3);

static int binary_expand_op_3(const emxArray_real32_T *in1,
                              const emxArray_real32_T *in2,
                              const fc_classreg_learning_classif_Co *in3,
                              float in4, float *out2, float *out3);

static int binary_expand_op_4(const emxArray_real32_T *in1,
                              const emxArray_real32_T *in2,
                              const fc_classreg_learning_classif_Co *in3,
                              float in4, float *out2, float *out3);

static void binary_expand_op_5(float in1_data[], int in2,
                               const float in3_data[], int in4, int in6,
                               int in7, int in8);

static int calculate_idxs_from_mask(const signed char mask[17], int *idx2,
                                    int *idx3, int *idx4, int *idx5, int *idx6,
                                    int *idx7, int *idx8, int *idx9, int *idx10,
                                    int *idx11, int *idx12, int *idx13,
                                    int *idx14, int *idx15, int *idx16,
                                    int *idx17, int *idx);

static void closing(const emxArray_real32_T *inputECG,
                    emxArray_real32_T *outputECG);

static void denoise_rwd(const emxArray_real32_T *ECG,
                        emxArray_real32_T *filteredECG);

static void dilation_s1(const emxArray_real32_T *inputECG,
                        emxArray_real32_T *outputECG);

static void dilation_s2(const emxArray_real32_T *inputECG,
                        emxArray_real32_T *outputECG);

static void erosion_s1(const emxArray_real32_T *inputECG,
                       emxArray_real32_T *outputECG);

static void erosion_s2(const emxArray_real32_T *inputECG,
                       emxArray_real32_T *outputECG);

static float features_Freq_calculator(const float tHRV_data[],
                                      const int tHRV_size[2], float HRV_data[],
                                      const int HRV_size[2], int idx5, int idx6,
                                      int idx7, int idx8, float Tot_pow_data[],
                                      int Tot_pow_size[2], float *nHF,
                                      float *LF_HF);

static float features_time_calculator(const float RR_Interv_data[],
                                      const int RR_Interv_size[2], int idx1,
                                      int idx2, int idx3, int idx4,
                                      float *Std_RR, float *RMSSD,
                                      float *pNN50);

static float my_Extract_features_Jep_orig(
    const emxArray_real32_T *ECG_Sig, const emxArray_real32_T *Spo2_sig,
    const signed char feature_selector_struct[17], emxArray_real32_T *Features);

static float my_slope(const float tHRV_data[], const int tHRV_size[2],
                      const float RR_Interv_filtr_data[],
                      const int RR_Interv_filtr_size[2]);

static void opening(const emxArray_real32_T *inputECG,
                    emxArray_real32_T *outputECG);

static void pan_tompkin_algorithm_segmented(emxArray_real32_T *sig_short,
                                            emxArray_real32_T *qrs_amp_raw,
                                            emxArray_real32_T *Rloc);

static int test_classifier_s1(const emxArray_real32_T *features,
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure);

static int test_classifier_s2(const emxArray_real32_T *features,
                              const boolean_T model_IsCached[15],
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure);

static int test_classifier_s3(const emxArray_real32_T *features,
                              const boolean_T model_IsCached[15],
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure);

static int test_classifier_s4(const emxArray_real32_T *features,
                              const boolean_T model_IsCached[15],
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure);

static int test_classifier_s5(const emxArray_real32_T *features,
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure);

/* Function Definitions */
/*
 * Arguments    : const float RR_Interv_data[]
 *                const int RR_Interv_size[2]
 * Return Type  : float
 */
static float Feature1(const float RR_Interv_data[], const int RR_Interv_size[2])
{
  return d_mean(RR_Interv_data, RR_Interv_size);
}

/*
 * Arguments    : const float CSI_filt_data[]
 *                float Slope
 * Return Type  : float
 */
static float Feature10(const float CSI_filt_data[], float Slope)
{
  return CSI_filt_data[0] * Slope;
}

/*
 * Arguments    : const float CSI_data[]
 * Return Type  : float
 */
static float Feature14(const float CSI_data[])
{
  return CSI_data[0];
}

/*
 * Arguments    : const emxArray_real32_T *Spo2_sig
 *                const emxArray_real32_T *Rlocs
 *                float i
 * Return Type  : float
 */
static float Feature16(const emxArray_real32_T *Spo2_sig,
                       const emxArray_real32_T *Rlocs, float i)
{
  emxArray_real32_T *b_Spo2_sig;
  emxArray_real32_T *r;
  const float *Rlocs_data;
  const float *Spo2_sig_data;
  float f;
  float f1;
  float output;
  float *b_Spo2_sig_data;
  int b_i;
  int i1;
  int loop_ub;
  Rlocs_data = Rlocs->data;
  Spo2_sig_data = Spo2_sig->data;
  f = Rlocs_data[(int)((i - 51.0F) + 1.0F) - 1];
  f1 = Rlocs_data[(int)i - 1];
  if (f > f1) {
    b_i = 0;
    i1 = 0;
  } else {
    b_i = (int)f - 1;
    i1 = (int)f1;
  }
  emxInit_real32_T(&b_Spo2_sig, 1);
  loop_ub = i1 - b_i;
  i1 = b_Spo2_sig->size[0];
  b_Spo2_sig->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(b_Spo2_sig, i1);
  b_Spo2_sig_data = b_Spo2_sig->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_Spo2_sig_data[i1] = Spo2_sig_data[b_i + i1];
  }
  emxInit_real32_T(&r, 1);
  e_abs(b_Spo2_sig, r);
  nonzeros(r, b_Spo2_sig);
  emxFree_real32_T(&r);
  output = mean(b_Spo2_sig);
  emxFree_real32_T(&b_Spo2_sig);
  return output;
}

/*
 * Arguments    : const emxArray_real32_T *Spo2_sig
 *                const emxArray_real32_T *Rlocs
 *                float i
 * Return Type  : float
 */
static float Feature17(const emxArray_real32_T *Spo2_sig,
                       const emxArray_real32_T *Rlocs, float i)
{
  emxArray_real32_T *b_Spo2_sig;
  emxArray_real32_T *r;
  const float *Rlocs_data;
  const float *Spo2_sig_data;
  float f;
  float f1;
  float output;
  float *b_Spo2_sig_data;
  int b_i;
  int i1;
  int loop_ub;
  Rlocs_data = Rlocs->data;
  Spo2_sig_data = Spo2_sig->data;
  f = Rlocs_data[(int)((i - 51.0F) + 1.0F) - 1];
  f1 = Rlocs_data[(int)i - 1];
  if (f > f1) {
    b_i = 0;
    i1 = 0;
  } else {
    b_i = (int)f - 1;
    i1 = (int)f1;
  }
  emxInit_real32_T(&b_Spo2_sig, 1);
  loop_ub = i1 - b_i;
  i1 = b_Spo2_sig->size[0];
  b_Spo2_sig->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(b_Spo2_sig, i1);
  b_Spo2_sig_data = b_Spo2_sig->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_Spo2_sig_data[i1] = Spo2_sig_data[b_i + i1];
  }
  emxInit_real32_T(&r, 1);
  e_abs(b_Spo2_sig, r);
  nonzeros(r, b_Spo2_sig);
  emxFree_real32_T(&r);
  output = c_std(b_Spo2_sig);
  emxFree_real32_T(&b_Spo2_sig);
  return output;
}

/*
 * Arguments    : const float RR_Interv_data[]
 *                const int RR_Interv_size[2]
 * Return Type  : float
 */
static float Feature2(const float RR_Interv_data[], const int RR_Interv_size[2])
{
  return b_std(RR_Interv_data, RR_Interv_size);
}

/*
 * Arguments    : const float RR_Interv_data[]
 *                const int RR_Interv_size[2]
 * Return Type  : float
 */
static float Feature3(const float RR_Interv_data[], const int RR_Interv_size[2])
{
  emxArray_real32_T b_RR_Interv_data;
  emxArray_real32_T *r;
  float tmp_data[399];
  float RMSSD;
  int tmp_size[2];
  b_RR_Interv_data.data = (float *)&RR_Interv_data[0];
  b_RR_Interv_data.size = (int *)&RR_Interv_size[0];
  b_RR_Interv_data.allocatedSize = -1;
  b_RR_Interv_data.numDimensions = 2;
  b_RR_Interv_data.canFreeData = false;
  emxInit_real32_T(&r, 2);
  c_diff(&b_RR_Interv_data, r);
  c_power((float *)r->data, r->size, tmp_data, tmp_size);
  emxFree_real32_T(&r);
  RMSSD = d_mean(tmp_data, tmp_size);
  c_sqrt(&RMSSD);
  return RMSSD;
}

/*
 * Arguments    : const float RR_Interv_data[]
 *                const int RR_Interv_size[2]
 * Return Type  : float
 */
static float Feature4(const float RR_Interv_data[], const int RR_Interv_size[2])
{
  emxArray_real32_T b_RR_Interv_data;
  emxArray_real32_T c_RR_Interv_data;
  emxArray_real32_T *r;
  float pNN50;
  float *r1;
  int b_tmp_data[399];
  int tmp_size[2];
  int i;
  int loop_ub;
  boolean_T tmp_data[399];
  b_RR_Interv_data.data = (float *)&RR_Interv_data[0];
  b_RR_Interv_data.size = (int *)&RR_Interv_size[0];
  b_RR_Interv_data.allocatedSize = -1;
  b_RR_Interv_data.numDimensions = 2;
  b_RR_Interv_data.canFreeData = false;
  emxInit_real32_T(&r, 2);
  c_diff(&b_RR_Interv_data, r);
  r1 = r->data;
  tmp_size[0] = 1;
  tmp_size[1] = r->size[1];
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    tmp_data[i] = (r1[i] > 0.05F);
  }
  int b_tmp_size[2];
  d_eml_find(tmp_data, tmp_size, b_tmp_data, b_tmp_size);
  c_RR_Interv_data.data = (float *)&RR_Interv_data[0];
  c_RR_Interv_data.size = (int *)&RR_Interv_size[0];
  c_RR_Interv_data.allocatedSize = -1;
  c_RR_Interv_data.numDimensions = 2;
  c_RR_Interv_data.canFreeData = false;
  c_diff(&c_RR_Interv_data, r);
  pNN50 = (float)((double)b_tmp_size[1] / (double)r->size[1]);
  emxFree_real32_T(&r);
  return pNN50;
}

/*
 * Arguments    : const emxArray_real32_T *pxx
 *                const emxArray_real32_T *f
 *                float Tot_pow_data[]
 *                int Tot_pow_size[2]
 * Return Type  : void
 */
static void Feature5(const emxArray_real32_T *pxx, const emxArray_real32_T *f,
                     float Tot_pow_data[], int Tot_pow_size[2])
{
  bandpower(pxx, f, Tot_pow_data, Tot_pow_size);
}

/*
 * Arguments    : const emxArray_real32_T *pxx
 *                const emxArray_real32_T *f
 *                const float freq_range[2]
 *                const float Tot_pow_data[]
 *                const int Tot_pow_size[2]
 *                float *Freq_betw_04_15
 * Return Type  : float
 */
static float Feature6(const emxArray_real32_T *pxx, const emxArray_real32_T *f,
                      const float freq_range[2], const float Tot_pow_data[],
                      const int Tot_pow_size[2], float *Freq_betw_04_15)
{
  float nLF;
  int Freq_betw_04_15_size[2];
  int b_Tot_pow_size[2];
  boolean_T b_Tot_pow_data;
  b_bandpower(pxx, f, freq_range, (float *)Freq_betw_04_15,
              Freq_betw_04_15_size);
  b_Tot_pow_size[0] = 1;
  b_Tot_pow_size[1] = Tot_pow_size[1];
  if (Tot_pow_size[1] - 1 >= 0) {
    b_Tot_pow_data = (Tot_pow_data[0] != 0.0F);
  }
  if (ifWhileCond((boolean_T *)&b_Tot_pow_data, b_Tot_pow_size)) {
    nLF = b_mrdiv(*Freq_betw_04_15, Tot_pow_data);
  } else {
    nLF = rtNaNF;
  }
  return nLF;
}

/*
 * Arguments    : const emxArray_real32_T *pxx
 *                const emxArray_real32_T *f
 *                const float Tot_pow_data[]
 *                const int Tot_pow_size[2]
 *                float *Freq_betw_15_40
 * Return Type  : float
 */
static float Feature7(const emxArray_real32_T *pxx, const emxArray_real32_T *f,
                      const float Tot_pow_data[], const int Tot_pow_size[2],
                      float *Freq_betw_15_40)
{
  const float *f_data;
  float b_f;
  float nHF;
  int b_Tot_pow_size[2];
  f_data = f->data;
  b_f = f_data[f->size[0] - 1];
  if (b_f <= 0.4F) {
    boolean_T b_Tot_pow_data;
    *Freq_betw_15_40 = 0.0F;
    b_Tot_pow_size[0] = 1;
    b_Tot_pow_size[1] = Tot_pow_size[1];
    if (Tot_pow_size[1] - 1 >= 0) {
      b_Tot_pow_data = (Tot_pow_data[0] == 0.0F);
    }
    if (ifWhileCond((boolean_T *)&b_Tot_pow_data, b_Tot_pow_size)) {
      nHF = rtNaNF;
    } else {
      nHF = c_mrdiv(Tot_pow_data);
    }
  } else {
    float fv[2];
    int Freq_betw_15_40_size[2];
    boolean_T b_Tot_pow_data;
    /*          Freq_betw_15_40 = bandpower(pxx, f, freq_range, 'psd'); */
    fv[0] = 0.15F;
    fv[1] = minimum2(0.4F, b_f);
    c_bandpower(pxx, f, fv, (float *)Freq_betw_15_40, Freq_betw_15_40_size);
    b_Tot_pow_size[0] = 1;
    b_Tot_pow_size[1] = Tot_pow_size[1];
    if (Tot_pow_size[1] - 1 >= 0) {
      b_Tot_pow_data = (Tot_pow_data[0] == 0.0F);
    }
    if (ifWhileCond((boolean_T *)&b_Tot_pow_data, b_Tot_pow_size)) {
      nHF = rtNaNF;
    } else {
      nHF = b_mrdiv(*Freq_betw_15_40, Tot_pow_data);
    }
  }
  /*      Freq_betw_15_40 = bandpower(pxx, f, freq_range, type); */
  /*      nHF = Freq_betw_15_40/Tot_pow; */
  return nHF;
}

/*
 * Arguments    : float Freq_betw_04_15
 *                float Freq_betw_15_40
 * Return Type  : float
 */
static float Feature8(float Freq_betw_04_15, float Freq_betw_15_40)
{
  return Freq_betw_04_15 / Freq_betw_15_40;
}

/*
 * Arguments    : const float RR_Interv_filtr[400]
 *                const float RR_Interv[400]
 *                float i
 *                const emxArray_real32_T *tHRV
 *                int idx9
 *                int idx10
 *                int idx11
 *                int idx12
 *                int idx13
 *                int idx14
 *                int idx15
 *                float CSI_filt_data[]
 *                int CSI_filt_size[2]
 *                float Mod_CSI_filt_data[]
 *                int Mod_CSI_filt_size[2]
 *                float CSI_data[]
 *                int CSI_size[2]
 *                float Mod_CSI_data[]
 *                int Mod_CSI_size[2]
 *                float HR_diff_orig_data[]
 *                int HR_diff_orig_size[2]
 * Return Type  : float
 */
static float Lorenz_features(
    const float RR_Interv_filtr[400], const float RR_Interv[400], float i,
    const emxArray_real32_T *tHRV, int idx9, int idx10, int idx11, int idx12,
    int idx13, int idx14, int idx15, float CSI_filt_data[],
    int CSI_filt_size[2], float Mod_CSI_filt_data[], int Mod_CSI_filt_size[2],
    float CSI_data[], int CSI_size[2], float Mod_CSI_data[],
    int Mod_CSI_size[2], float HR_diff_orig_data[], int HR_diff_orig_size[2])
{
  const float *tHRV_data;
  float Slope;
  int RR_Interv_size[2];
  int tHRV_size[2];
  int b_i;
  int i1;
  tHRV_data = tHRV->data;
  /*  function [CSI_filt,Mod_CSI_filt, CSI, Mod_CSI, HR_diff_orig, Slope] =
   * Lorenz_features(RR_Interv_filtr, i, x0, Nbr_RR, tHRV,
   * feature_selector_struct, Features, idx_time, idx_freq, idx_diff, idx9,
   * idx10, idx11, idx12, idx13, idx14, idx15) */
  CSI_filt_size[0] = 1;
  CSI_filt_size[1] = 1;
  CSI_filt_data[0] = rtNaNF;
  Mod_CSI_filt_size[0] = 1;
  Mod_CSI_filt_size[1] = 1;
  Mod_CSI_filt_data[0] = rtNaNF;
  if ((idx10 != -1) || (idx11 != -1)) {
    Lorenz_plot_f10f11(RR_Interv_filtr, i, CSI_filt_data, CSI_filt_size,
                       Mod_CSI_filt_data, Mod_CSI_filt_size);
  }
  /*          [CSI,     Mod_CSI,     ~,HR_diff_orig] =
   * Lorenz_plot(RR_Interv(i-x0+1:i),      (Nbr_RR)); */
  CSI_size[0] = 1;
  CSI_size[1] = 1;
  CSI_data[0] = rtNaNF;
  Mod_CSI_size[0] = 1;
  Mod_CSI_size[1] = 1;
  Mod_CSI_data[0] = rtNaNF;
  HR_diff_orig_size[0] = 1;
  HR_diff_orig_size[1] = 1;
  HR_diff_orig_data[0] = rtNaNF;
  Slope = rtNaNF;
  if ((idx9 != -1) || (idx10 != -1) || (idx11 != -1) || (idx12 != -1) ||
      (idx13 != -1) || (idx14 != -1) || (idx15 != -1)) {
    float RR_Interv_data[400];
    float b_tHRV_data[400];
    int i2;
    int loop_ub;
    Lorenz_plot_f9f12f13f14f15(RR_Interv, i, CSI_data, CSI_size, Mod_CSI_data,
                               Mod_CSI_size, HR_diff_orig_data,
                               HR_diff_orig_size);
    if ((i - 51.0F) + 1.0F > i) {
      b_i = 0;
      i1 = 0;
      i2 = 0;
    } else {
      b_i = (int)((i - 51.0F) + 1.0F) - 1;
      i1 = (int)i;
      i2 = (int)((i - 51.0F) + 1.0F) - 1;
    }
    tHRV_size[0] = 1;
    loop_ub = i1 - b_i;
    tHRV_size[1] = loop_ub;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_tHRV_data[i1] = tHRV_data[b_i + i1];
    }
    RR_Interv_size[0] = 1;
    RR_Interv_size[1] = loop_ub;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      RR_Interv_data[b_i] = RR_Interv[i2 + b_i];
    }
    Slope =
        g_abs(my_slope(b_tHRV_data, tHRV_size, RR_Interv_data, RR_Interv_size));
    /*      if feature_selector_struct.mask(4)  */
    /*          if idx10 ~= -1 */
    /*              Features(i-x0+1,idx10) = Feature10(CSI_filt, Slope); %f10 */
    /*          end */
    /*          if idx11 ~= -1 */
    /*              Features(i-x0+1,idx11) = Feature11(Mod_CSI_filt,Slope); %f11
     */
    /*          end */
    /*          if idx12 ~= -1 */
    /*              Features(i-x0+1,idx12) = Feature12(CSI,Slope); %f12 */
    /*          end */
    /*          if idx13 ~= -1 */
    /*              Features(i-x0+1,idx13) = Feature13(Mod_CSI,Slope); %f13 */
    /*          end */
    /*          if idx14 ~= -1 */
    /*              Features(i-x0+1,idx14) = Feature14(CSI); %f14 */
    /*          end */
    /*          if idx15 ~= -1 */
    /*              Features(i-x0+1,idx15) = Feature15(Mod_CSI); %f15 */
    /*          end */
    /*   */
    /*      %     end */
    /*          if idx9 ~= -1 */
    /*              Features(i-x0+1,idx9) = Feature9(HR_diff_orig); %f9 */
    /*          end */
  }
  return Slope;
}

/*
 * Arguments    : const float R_R_interval_data[]
 *                const int R_R_interval_size[2]
 *                float CSI_data[]
 *                int CSI_size[2]
 *                float Mod_CSI_data[]
 *                int Mod_CSI_size[2]
 *                float CVI_data[]
 *                int CVI_size[2]
 *                float HR_diff_data[]
 *                int HR_diff_size[2]
 * Return Type  : void
 */
static void Lorenz_plot(const float R_R_interval_data[],
                        const int R_R_interval_size[2], float CSI_data[],
                        int CSI_size[2], float Mod_CSI_data[],
                        int Mod_CSI_size[2], float CVI_data[], int CVI_size[2],
                        float HR_diff_data[], int HR_diff_size[2])
{
  float Long_L_data[8];
  float Trav_L_data[8];
  float sd1_data[8];
  float sd2_data[8];
  float Strt;
  int tmp_size[2];
  int b_i;
  int i;
  int i3;
  int i5;
  Strt = roundf(b_floor((float)R_R_interval_size[1] / 50.0F));
  if (Strt < 2.14748365E+9F) {
    if (Strt >= -2.14748365E+9F) {
      i = (int)Strt;
    } else {
      i = MIN_int32_T;
    }
  } else if (Strt >= 2.14748365E+9F) {
    i = MAX_int32_T;
  } else {
    i = 0;
  }
  CSI_size[0] = 1;
  CSI_size[1] = i;
  CVI_size[0] = 1;
  CVI_size[1] = i;
  Mod_CSI_size[0] = 1;
  Mod_CSI_size[1] = i;
  HR_diff_size[0] = 1;
  HR_diff_size[1] = i;
  if (i - 1 >= 0) {
    memset(&sd1_data[0], 0, (unsigned int)i * sizeof(float));
    memset(&sd2_data[0], 0, (unsigned int)i * sizeof(float));
    memset(&Long_L_data[0], 0, (unsigned int)i * sizeof(float));
    memset(&Trav_L_data[0], 0, (unsigned int)i * sizeof(float));
    memset(&CSI_data[0], 0, (unsigned int)i * sizeof(float));
    memset(&CVI_data[0], 0, (unsigned int)i * sizeof(float));
    memset(&Mod_CSI_data[0], 0, (unsigned int)i * sizeof(float));
    memset(&HR_diff_data[0], 0, (unsigned int)i * sizeof(float));
  }
  if (R_R_interval_size[1] > 1) {
    i = (int)(float)i;
    for (b_i = 0; b_i < i; b_i++) {
      float tmp_data[400];
      float End;
      int i1;
      int i2;
      int i4;
      int loop_ub;
      int loop_ub_tmp_tmp_tmp;
      Strt = (((float)b_i + 1.0F) - 1.0F) * 50.0F + 1.0F;
      End = ((float)b_i + 1.0F) * 50.0F;
      if (Strt > End) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (int)Strt - 1;
        i2 = (int)End;
      }
      loop_ub_tmp_tmp_tmp = i2 - i1;
      if (loop_ub_tmp_tmp_tmp - 1 < 1) {
        loop_ub = 0;
      } else {
        loop_ub = loop_ub_tmp_tmp_tmp - 1;
      }
      if (loop_ub_tmp_tmp_tmp < 2) {
        i2 = 0;
        i3 = 0;
      } else {
        i2 = 1;
        i3 = loop_ub_tmp_tmp_tmp;
      }
      /*         %% Get the sd1 */
      /*          sd1 = [sd1,1000*(std((sqrt(2)/2)*R_pks_diff))]; */
      i4 = i3 - i2;
      if (loop_ub == i4) {
        tmp_size[0] = 1;
        tmp_size[1] = loop_ub;
        for (i5 = 0; i5 < loop_ub; i5++) {
          tmp_data[i5] = 0.707106769F * (R_R_interval_data[i1 + i5] -
                                         R_R_interval_data[(i1 + i2) + i5]);
        }
        sd1_data[(int)((float)b_i + 1.0F) - 1] =
            1000.0F * b_std(tmp_data, tmp_size);
      } else {
        binary_expand_op_7(sd1_data, b_i, R_R_interval_data, i1, loop_ub - 1,
                           i2, i3 - 1);
      }
      /*         %% Calculate the transverse length (T) as four times  the  Sd1
       */
      /*          Trav_L = [Trav_L,4*sd1(i)]; */
      Trav_L_data[(int)((float)b_i + 1.0F) - 1] =
          4.0F * sd1_data[(int)((float)b_i + 1.0F) - 1];
      /*         %% Get the sd2 */
      /*          sd2 = [sd2,1000*(std((sqrt(2)/2)*R_pks_add))]; */
      if (loop_ub == i4) {
        tmp_size[0] = 1;
        tmp_size[1] = loop_ub;
        for (i3 = 0; i3 < loop_ub; i3++) {
          tmp_data[i3] = 0.707106769F * (R_R_interval_data[i1 + i3] +
                                         R_R_interval_data[(i1 + i2) + i3]);
        }
        sd2_data[(int)((float)b_i + 1.0F) - 1] =
            1000.0F * b_std(tmp_data, tmp_size);
      } else {
        binary_expand_op_6(sd2_data, b_i, R_R_interval_data, i1, loop_ub - 1,
                           i2, i3 - 1);
      }
      /*         %% Calculate the longitudinal length (L) as four times  the Sd2
       */
      /*          Long_L = [Long_L,4*sd2(i)]; */
      Long_L_data[(int)((float)b_i + 1.0F) - 1] =
          4.0F * sd2_data[(int)((float)b_i + 1.0F) - 1];
      /*         %% Calculate the Cardiac  Sympathetic  Index (CSI) */
      /*          CSI = [CSI,Long_L(i)/Trav_L(i)]; */
      Strt = Long_L_data[(int)((float)b_i + 1.0F) - 1];
      End = Trav_L_data[(int)((float)b_i + 1.0F) - 1];
      CSI_data[(int)((float)b_i + 1.0F) - 1] = Strt / End;
      /*         %% Calculate the modified CSI: This one emphasize the
       * longitudinal parameter */
      /*          Mod_CSI = [Mod_CSI,(Long_L(i).^2)/Trav_L(i)]; */
      Mod_CSI_data[(int)((float)b_i + 1.0F) - 1] = Strt * Strt / End;
      /*         %% Calculate the Cardiac Vagal Index (CVI) */
      /*          CVI = [CVI,log10(Long_L(i)*Trav_L(i))]; */
      CVI_data[(int)((float)b_i + 1.0F) - 1] = Strt * End;
      b_log10(&CVI_data[(int)((float)b_i + 1.0F) - 1]);
      /*  Heart rate differential method */
      /*          HR_diff =
       * [HR_diff,sum(0.5.*(RR_inter_Wind(3:end)-RR_inter_Wind(1:end-2)))]; */
      if (loop_ub_tmp_tmp_tmp < 3) {
        i2 = 0;
        i3 = 0;
      } else {
        i2 = 2;
        i3 = loop_ub_tmp_tmp_tmp;
      }
      if (loop_ub_tmp_tmp_tmp - 2 < 1) {
        i4 = 0;
      } else {
        i4 = loop_ub_tmp_tmp_tmp - 2;
      }
      loop_ub = i3 - i2;
      if (loop_ub == i4) {
        tmp_size[0] = 1;
        tmp_size[1] = loop_ub;
        for (i3 = 0; i3 < loop_ub; i3++) {
          tmp_data[i3] = 0.5F * (R_R_interval_data[(i1 + i2) + i3] -
                                 R_R_interval_data[i1 + i3]);
        }
        HR_diff_data[(int)((float)b_i + 1.0F) - 1] = b_sum(tmp_data, tmp_size);
      } else {
        binary_expand_op_5(HR_diff_data, b_i, R_R_interval_data, i1, i2, i3 - 1,
                           i4 - 1);
      }
    }
  }
}

/*
 * Arguments    : const float RR_Interv_filtr[400]
 *                float i
 *                float CSI_filt_data[]
 *                int CSI_filt_size[2]
 *                float Mod_CSI_filt_data[]
 *                int Mod_CSI_filt_size[2]
 * Return Type  : void
 */
static void Lorenz_plot_f10f11(const float RR_Interv_filtr[400], float i,
                               float CSI_filt_data[], int CSI_filt_size[2],
                               float Mod_CSI_filt_data[],
                               int Mod_CSI_filt_size[2])
{
  float RR_Interv_filtr_data[400];
  float a__3_data[8];
  float a__4_data[8];
  int RR_Interv_filtr_size[2];
  int b_i;
  int i1;
  int loop_ub;
  if ((i - 51.0F) + 1.0F > i) {
    b_i = 0;
    i1 = 0;
  } else {
    b_i = (int)((i - 51.0F) + 1.0F) - 1;
    i1 = (int)i;
  }
  RR_Interv_filtr_size[0] = 1;
  loop_ub = i1 - b_i;
  RR_Interv_filtr_size[1] = loop_ub;
  for (i1 = 0; i1 < loop_ub; i1++) {
    RR_Interv_filtr_data[i1] = RR_Interv_filtr[b_i + i1];
  }
  int a__3_size[2];
  int a__4_size[2];
  Lorenz_plot(RR_Interv_filtr_data, RR_Interv_filtr_size, CSI_filt_data,
              CSI_filt_size, Mod_CSI_filt_data, Mod_CSI_filt_size, a__3_data,
              a__3_size, a__4_data, a__4_size);
}

/*
 * [CSI_filt,Mod_CSI_filt,~,  ~] =
 * Lorenz_plot(RR_Interv_filtr(i-x0+1:i),(Nbr_RR));
 *
 * Arguments    : const float RR_Interv[400]
 *                float i
 *                float CSI_data[]
 *                int CSI_size[2]
 *                float Mod_CSI_data[]
 *                int Mod_CSI_size[2]
 *                float HR_diff_orig_data[]
 *                int HR_diff_orig_size[2]
 * Return Type  : void
 */
static void Lorenz_plot_f9f12f13f14f15(const float RR_Interv[400], float i,
                                       float CSI_data[], int CSI_size[2],
                                       float Mod_CSI_data[],
                                       int Mod_CSI_size[2],
                                       float HR_diff_orig_data[],
                                       int HR_diff_orig_size[2])
{
  float RR_Interv_data[400];
  float a__5_data[8];
  int RR_Interv_size[2];
  int b_i;
  int i1;
  int loop_ub;
  if ((i - 51.0F) + 1.0F > i) {
    b_i = 0;
    i1 = 0;
  } else {
    b_i = (int)((i - 51.0F) + 1.0F) - 1;
    i1 = (int)i;
  }
  RR_Interv_size[0] = 1;
  loop_ub = i1 - b_i;
  RR_Interv_size[1] = loop_ub;
  for (i1 = 0; i1 < loop_ub; i1++) {
    RR_Interv_data[i1] = RR_Interv[b_i + i1];
  }
  int a__5_size[2];
  Lorenz_plot(RR_Interv_data, RR_Interv_size, CSI_data, CSI_size, Mod_CSI_data,
              Mod_CSI_size, a__5_data, a__5_size, HR_diff_orig_data,
              HR_diff_orig_size);
  /*       Slope=abs(my_slope(tHRV(i-x0+1:i),RR_Interv_filtr(i-x0+1:i))); */
}

/*
 * Arguments    : emxArray_real32_T *in1
 *                const emxArray_real32_T *in2
 * Return Type  : void
 */
static void b_minus(emxArray_real32_T *in1, const emxArray_real32_T *in2)
{
  emxArray_real32_T *b_in2;
  const float *in2_data;
  float *b_in2_data;
  float *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in2, 1);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] - in1_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = b_in2->size[0];
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in2->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in2_data[i];
  }
  emxFree_real32_T(&b_in2);
}

/*
 * Arguments    : const emxArray_real32_T *in1
 *                const emxArray_real32_T *in2
 *                const gc_classreg_learning_classif_Co *in3
 *                float in4
 *                float *out2
 *                float *out3
 * Return Type  : int
 */
static int binary_expand_op(const emxArray_real32_T *in1,
                            const emxArray_real32_T *in2,
                            const gc_classreg_learning_classif_Co *in3,
                            float in4, float *out2, float *out3)
{
  emxArray_real32_T *b_in1;
  const float *in1_data;
  const float *in2_data;
  float *b_in1_data;
  int aux_0_1;
  int i;
  int i1;
  int loop_ub;
  int out1;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 13;
  emxEnsureCapacity_real32_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  aux_0_1 = 0;
  for (i = 0; i < 13; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] /
          in2_data[i1 * stride_1_0 + in2->size[0] * i];
    }
    aux_0_1 += stride_0_1;
  }
  out1 = test_classifier_s4(b_in1, in3->IsCached, in3->Prior, in4, out2, out3);
  emxFree_real32_T(&b_in1);
  return out1;
}

/*
 * Arguments    : const emxArray_real32_T *in1
 *                const emxArray_real32_T *in2
 *                const gc_classreg_learning_classif_Co *in3
 *                float in4
 *                float *out2
 *                float *out3
 * Return Type  : int
 */
static int binary_expand_op_1(const emxArray_real32_T *in1,
                              const emxArray_real32_T *in2,
                              const gc_classreg_learning_classif_Co *in3,
                              float in4, float *out2, float *out3)
{
  emxArray_real32_T *b_in1;
  const float *in1_data;
  const float *in2_data;
  float *b_in1_data;
  int aux_0_1;
  int i;
  int i1;
  int loop_ub;
  int out1;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 12;
  emxEnsureCapacity_real32_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  aux_0_1 = 0;
  for (i = 0; i < 12; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] /
          in2_data[i1 * stride_1_0 + in2->size[0] * i];
    }
    aux_0_1 += stride_0_1;
  }
  out1 = test_classifier_s3(b_in1, in3->IsCached, in3->Prior, in4, out2, out3);
  emxFree_real32_T(&b_in1);
  return out1;
}

/*
 * Arguments    : const emxArray_real32_T *in1
 *                const emxArray_real32_T *in2
 *                const gc_classreg_learning_classif_Co *in3
 *                float in4
 *                float *out2
 *                float *out3
 * Return Type  : int
 */
static int binary_expand_op_2(const emxArray_real32_T *in1,
                              const emxArray_real32_T *in2,
                              const gc_classreg_learning_classif_Co *in3,
                              float in4, float *out2, float *out3)
{
  emxArray_real32_T *b_in1;
  const float *in1_data;
  const float *in2_data;
  float *b_in1_data;
  int aux_0_1;
  int i;
  int i1;
  int loop_ub;
  int out1;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 11;
  emxEnsureCapacity_real32_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  aux_0_1 = 0;
  for (i = 0; i < 11; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] /
          in2_data[i1 * stride_1_0 + in2->size[0] * i];
    }
    aux_0_1 += stride_0_1;
  }
  out1 = test_classifier_s2(b_in1, in3->IsCached, in3->Prior, in4, out2, out3);
  emxFree_real32_T(&b_in1);
  return out1;
}

/*
 * Arguments    : const emxArray_real32_T *in1
 *                const emxArray_real32_T *in2
 *                const fc_classreg_learning_classif_Co *in3
 *                float in4
 *                float *out2
 *                float *out3
 * Return Type  : int
 */
static int binary_expand_op_3(const emxArray_real32_T *in1,
                              const emxArray_real32_T *in2,
                              const fc_classreg_learning_classif_Co *in3,
                              float in4, float *out2, float *out3)
{
  emxArray_real32_T *b_in1;
  const float *in1_data;
  const float *in2_data;
  float *b_in1_data;
  int aux_0_1;
  int i;
  int i1;
  int loop_ub;
  int out1;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 4;
  emxEnsureCapacity_real32_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  aux_0_1 = 0;
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] /
          in2_data[i1 * stride_1_0 + in2->size[0] * i];
    }
    aux_0_1 += stride_0_1;
  }
  out1 = test_classifier_s1(b_in1, in3->Prior, in4, out2, out3);
  emxFree_real32_T(&b_in1);
  return out1;
}

/*
 * Arguments    : const emxArray_real32_T *in1
 *                const emxArray_real32_T *in2
 *                const fc_classreg_learning_classif_Co *in3
 *                float in4
 *                float *out2
 *                float *out3
 * Return Type  : int
 */
static int binary_expand_op_4(const emxArray_real32_T *in1,
                              const emxArray_real32_T *in2,
                              const fc_classreg_learning_classif_Co *in3,
                              float in4, float *out2, float *out3)
{
  emxArray_real32_T *b_in1;
  const float *in1_data;
  const float *in2_data;
  float *b_in1_data;
  int aux_0_1;
  int i;
  int i1;
  int loop_ub;
  int out1;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 17;
  emxEnsureCapacity_real32_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  aux_0_1 = 0;
  for (i = 0; i < 17; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] /
          in2_data[i1 * stride_1_0 + in2->size[0] * i];
    }
    aux_0_1 += stride_0_1;
  }
  out1 = test_classifier_s5(b_in1, in3->Prior, in4, out2, out3);
  emxFree_real32_T(&b_in1);
  return out1;
}

/*
 * Arguments    : float in1_data[]
 *                int in2
 *                const float in3_data[]
 *                int in4
 *                int in6
 *                int in7
 *                int in8
 * Return Type  : void
 */
static void binary_expand_op_5(float in1_data[], int in2,
                               const float in3_data[], int in4, int in6,
                               int in7, int in8)
{
  float tmp_data[400];
  int tmp_size[2];
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  tmp_size[0] = 1;
  i = (in7 - in6) + 1;
  if (in8 + 1 == 1) {
    loop_ub = i;
  } else {
    loop_ub = in8 + 1;
  }
  tmp_size[1] = loop_ub;
  stride_0_1 = (i != 1);
  stride_1_1 = (in8 + 1 != 1);
  for (i = 0; i < loop_ub; i++) {
    tmp_data[i] = 0.5F * (in3_data[(in4 + in6) + i * stride_0_1] -
                          in3_data[in4 + i * stride_1_1]);
  }
  in1_data[(int)((float)in2 + 1.0F) - 1] = b_sum(tmp_data, tmp_size);
}

/*
 * Arguments    : const signed char mask[17]
 *                int *idx2
 *                int *idx3
 *                int *idx4
 *                int *idx5
 *                int *idx6
 *                int *idx7
 *                int *idx8
 *                int *idx9
 *                int *idx10
 *                int *idx11
 *                int *idx12
 *                int *idx13
 *                int *idx14
 *                int *idx15
 *                int *idx16
 *                int *idx17
 *                int *idx
 * Return Type  : int
 */
static int calculate_idxs_from_mask(const signed char mask[17], int *idx2,
                                    int *idx3, int *idx4, int *idx5, int *idx6,
                                    int *idx7, int *idx8, int *idx9, int *idx10,
                                    int *idx11, int *idx12, int *idx13,
                                    int *idx14, int *idx15, int *idx16,
                                    int *idx17, int *idx)
{
  int i;
  int idx1;
  *idx = 0;
  idx1 = -1;
  *idx2 = -1;
  *idx3 = -1;
  *idx4 = -1;
  *idx5 = -1;
  *idx6 = -1;
  *idx7 = -1;
  *idx8 = -1;
  *idx9 = -1;
  *idx10 = -1;
  *idx11 = -1;
  *idx12 = -1;
  *idx13 = -1;
  *idx14 = -1;
  *idx15 = -1;
  *idx16 = -1;
  *idx17 = -1;
  for (i = 0; i < 17; i++) {
    if (mask[i] == 1) {
      (*idx)++;
      switch (i + 1) {
      case 1:
        idx1 = *idx;
        break;
      case 2:
        *idx2 = *idx;
        break;
      case 3:
        *idx3 = *idx;
        break;
      case 4:
        *idx4 = *idx;
        break;
      case 5:
        *idx5 = *idx;
        break;
      case 6:
        *idx6 = *idx;
        break;
      case 7:
        *idx7 = *idx;
        break;
      case 8:
        *idx8 = *idx;
        break;
      case 9:
        *idx9 = *idx;
        break;
      case 10:
        *idx10 = *idx;
        break;
      case 11:
        *idx11 = *idx;
        break;
      case 12:
        *idx12 = *idx;
        break;
      case 13:
        *idx13 = *idx;
        break;
      case 14:
        *idx14 = *idx;
        break;
      case 15:
        *idx15 = *idx;
        break;
      case 16:
        *idx16 = *idx;
        break;
      default:
        *idx17 = *idx;
        break;
      }
    } else {
      switch (i + 1) {
      case 1:
        idx1 = -1;
        break;
      case 2:
        *idx2 = -1;
        break;
      case 3:
        *idx3 = -1;
        break;
      case 4:
        *idx4 = -1;
        break;
      case 5:
        *idx5 = -1;
        break;
      case 6:
        *idx6 = -1;
        break;
      case 7:
        *idx7 = -1;
        break;
      case 8:
        *idx8 = -1;
        break;
      case 9:
        *idx9 = -1;
        break;
      case 10:
        *idx10 = -1;
        break;
      case 11:
        *idx11 = -1;
        break;
      case 12:
        *idx12 = -1;
        break;
      case 13:
        *idx13 = -1;
        break;
      case 14:
        *idx14 = -1;
        break;
      case 15:
        *idx15 = -1;
        break;
      case 16:
        *idx16 = -1;
        break;
      default:
        *idx17 = -1;
        break;
      }
    }
  }
  return idx1;
}

/*
 * Arguments    : const emxArray_real32_T *inputECG
 *                emxArray_real32_T *outputECG
 * Return Type  : void
 */
static void closing(const emxArray_real32_T *inputECG,
                    emxArray_real32_T *outputECG)
{
  emxArray_real32_T *r;
  emxInit_real32_T(&r, 1);
  dilation_s2(inputECG, r);
  erosion_s2(r, outputECG);
  emxFree_real32_T(&r);
}

/*
 * tamaÃ±o de la ventana del filtro de mediana de la BWcancell (sg)
 *
 * Arguments    : const emxArray_real32_T *ECG
 *                emxArray_real32_T *filteredECG
 * Return Type  : void
 */
static void denoise_rwd(const emxArray_real32_T *ECG,
                        emxArray_real32_T *filteredECG)
{
  emxArray_real32_T *r;
  const float *ECG_data;
  float *filteredECG_data;
  int i;
  int i1;
  int loop_ub;
  ECG_data = ECG->data;
  /* denoise_RWD(ECG,fs,BWremoval,BWwindow,HFNremoval,LF,HF), where: */
  /*    ECG = input ECG signal at 500Hz */
  /*    fs = output sampling frequency */
  /*    BWremoval = baseline wander removal (1: enabled, 0: disabled) */
  /*    BWwindow = size of the structuring element for baseline wander removal
   */
  /*    - usually fs/5. */
  /*    HFNremoval = high-frequency noise removal (1: enabled, 0: disabled) */
  /*    LF = lower cutoff frequency of the band-pass filter */
  /*    HF = upper cutoff frequency of the band-pass filter */
  /*     */
  /* This function processes the input ECG signal, applying a morphological */
  /* filter to remove baseline wander and a band-pass filter to remove high */
  /* frequency noise */
  /* Orden del filtro paso bajo */
  /*  Eliminamos la linea de base */
  emxInit_real32_T(&r, 1);
  opening(ECG, r);
  closing(r, filteredECG);
  emxFree_real32_T(&r);
  if (ECG->size[0] == filteredECG->size[0]) {
    i = filteredECG->size[0];
    filteredECG->size[0] = ECG->size[0];
    emxEnsureCapacity_real32_T(filteredECG, i);
    filteredECG_data = filteredECG->data;
    loop_ub = ECG->size[0];
    for (i = 0; i < loop_ub; i++) {
      filteredECG_data[i] = ECG_data[i] - filteredECG_data[i];
    }
  } else {
    b_minus(filteredECG, ECG);
    filteredECG_data = filteredECG->data;
  }
  for (i = 0; i < 130; i++) {
    filteredECG_data[i] = 0.0F;
  }
  if ((float)filteredECG->size[0] - 130.0F > filteredECG->size[0]) {
    i = 0;
    i1 = 0;
  } else {
    i = (int)((float)filteredECG->size[0] - 130.0F) - 1;
    i1 = (int)(float)filteredECG->size[0];
  }
  loop_ub = i1 - i;
  for (i1 = 0; i1 < loop_ub; i1++) {
    filteredECG_data[i + i1] = 0.0F;
  }
  /*  Filter */
  /* FPB orden 32 y fc = 25 Hz para eliminar el ruido de alta frec. */
  /* La frecuencia de corte del filtro hay que pasarsela normalizada. */
  /* Toma valores entre 0 y 1 donde 1 corresponde a Fnyquist = fs/2. */
  /* aux = filtfilt(B,1,aux); removed for C coder */
}

/*
 * Arguments    : const emxArray_real32_T *inputECG
 *                emxArray_real32_T *outputECG
 * Return Type  : void
 */
static void dilation_s1(const emxArray_real32_T *inputECG,
                        emxArray_real32_T *outputECG)
{
  emxArray_real32_T *b_inputECG;
  const float *inputECG_data;
  float *b_inputECG_data;
  float *outputECG_data;
  int b_i;
  int i;
  int i2;
  int loop_ub;
  inputECG_data = inputECG->data;
  i = outputECG->size[0];
  outputECG->size[0] = inputECG->size[0];
  emxEnsureCapacity_real32_T(outputECG, i);
  outputECG_data = outputECG->data;
  loop_ub = inputECG->size[0];
  for (i = 0; i < loop_ub; i++) {
    outputECG_data[i] = 0.0F;
  }
  i = (int)(((float)inputECG->size[0] - 26.0F) - 26.0F);
  emxInit_real32_T(&b_inputECG, 1);
  for (b_i = 0; b_i < i; b_i++) {
    int i1;
    if (((float)b_i + 27.0F) - 26.0F > ((float)b_i + 27.0F) + 26.0F) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = (int)(((float)b_i + 27.0F) - 26.0F) - 1;
      i2 = (int)(((float)b_i + 27.0F) + 26.0F);
    }
    loop_ub = i2 - i1;
    i2 = b_inputECG->size[0];
    b_inputECG->size[0] = loop_ub;
    emxEnsureCapacity_real32_T(b_inputECG, i2);
    b_inputECG_data = b_inputECG->data;
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_inputECG_data[i2] = inputECG_data[i1 + i2];
    }
    outputECG_data[(int)((float)b_i + 27.0F) - 1] = maximum(b_inputECG);
  }
  emxFree_real32_T(&b_inputECG);
}

/*
 * Arguments    : const emxArray_real32_T *inputECG
 *                emxArray_real32_T *outputECG
 * Return Type  : void
 */
static void dilation_s2(const emxArray_real32_T *inputECG,
                        emxArray_real32_T *outputECG)
{
  emxArray_real32_T *b_inputECG;
  const float *inputECG_data;
  float *b_inputECG_data;
  float *outputECG_data;
  int b_i;
  int i;
  int i2;
  int loop_ub;
  inputECG_data = inputECG->data;
  i = outputECG->size[0];
  outputECG->size[0] = inputECG->size[0];
  emxEnsureCapacity_real32_T(outputECG, i);
  outputECG_data = outputECG->data;
  loop_ub = inputECG->size[0];
  for (i = 0; i < loop_ub; i++) {
    outputECG_data[i] = 0.0F;
  }
  i = (int)(((float)inputECG->size[0] - 39.0F) - 39.0F);
  emxInit_real32_T(&b_inputECG, 1);
  for (b_i = 0; b_i < i; b_i++) {
    int i1;
    if (((float)b_i + 40.0F) - 39.0F > ((float)b_i + 40.0F) + 39.0F) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = (int)(((float)b_i + 40.0F) - 39.0F) - 1;
      i2 = (int)(((float)b_i + 40.0F) + 39.0F);
    }
    loop_ub = i2 - i1;
    i2 = b_inputECG->size[0];
    b_inputECG->size[0] = loop_ub;
    emxEnsureCapacity_real32_T(b_inputECG, i2);
    b_inputECG_data = b_inputECG->data;
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_inputECG_data[i2] = inputECG_data[i1 + i2];
    }
    outputECG_data[(int)((float)b_i + 40.0F) - 1] = maximum(b_inputECG);
  }
  emxFree_real32_T(&b_inputECG);
}

/*
 * Arguments    : const emxArray_real32_T *inputECG
 *                emxArray_real32_T *outputECG
 * Return Type  : void
 */
static void erosion_s1(const emxArray_real32_T *inputECG,
                       emxArray_real32_T *outputECG)
{
  emxArray_real32_T *b_inputECG;
  const float *inputECG_data;
  float *b_inputECG_data;
  float *outputECG_data;
  int b_i;
  int i;
  int i2;
  int loop_ub;
  inputECG_data = inputECG->data;
  i = outputECG->size[0];
  outputECG->size[0] = inputECG->size[0];
  emxEnsureCapacity_real32_T(outputECG, i);
  outputECG_data = outputECG->data;
  loop_ub = inputECG->size[0];
  for (i = 0; i < loop_ub; i++) {
    outputECG_data[i] = 0.0F;
  }
  i = (int)(((float)inputECG->size[0] - 26.0F) - 26.0F);
  emxInit_real32_T(&b_inputECG, 1);
  for (b_i = 0; b_i < i; b_i++) {
    int i1;
    if (((float)b_i + 27.0F) - 26.0F > ((float)b_i + 27.0F) + 26.0F) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = (int)(((float)b_i + 27.0F) - 26.0F) - 1;
      i2 = (int)(((float)b_i + 27.0F) + 26.0F);
    }
    loop_ub = i2 - i1;
    i2 = b_inputECG->size[0];
    b_inputECG->size[0] = loop_ub;
    emxEnsureCapacity_real32_T(b_inputECG, i2);
    b_inputECG_data = b_inputECG->data;
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_inputECG_data[i2] = inputECG_data[i1 + i2];
    }
    outputECG_data[(int)((float)b_i + 27.0F) - 1] = minimum(b_inputECG);
  }
  emxFree_real32_T(&b_inputECG);
}

/*
 * Arguments    : const emxArray_real32_T *inputECG
 *                emxArray_real32_T *outputECG
 * Return Type  : void
 */
static void erosion_s2(const emxArray_real32_T *inputECG,
                       emxArray_real32_T *outputECG)
{
  emxArray_real32_T *b_inputECG;
  const float *inputECG_data;
  float *b_inputECG_data;
  float *outputECG_data;
  int b_i;
  int i;
  int i2;
  int loop_ub;
  inputECG_data = inputECG->data;
  i = outputECG->size[0];
  outputECG->size[0] = inputECG->size[0];
  emxEnsureCapacity_real32_T(outputECG, i);
  outputECG_data = outputECG->data;
  loop_ub = inputECG->size[0];
  for (i = 0; i < loop_ub; i++) {
    outputECG_data[i] = 0.0F;
  }
  i = (int)(((float)inputECG->size[0] - 39.0F) - 39.0F);
  emxInit_real32_T(&b_inputECG, 1);
  for (b_i = 0; b_i < i; b_i++) {
    int i1;
    if (((float)b_i + 40.0F) - 39.0F > ((float)b_i + 40.0F) + 39.0F) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = (int)(((float)b_i + 40.0F) - 39.0F) - 1;
      i2 = (int)(((float)b_i + 40.0F) + 39.0F);
    }
    loop_ub = i2 - i1;
    i2 = b_inputECG->size[0];
    b_inputECG->size[0] = loop_ub;
    emxEnsureCapacity_real32_T(b_inputECG, i2);
    b_inputECG_data = b_inputECG->data;
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_inputECG_data[i2] = inputECG_data[i1 + i2];
    }
    outputECG_data[(int)((float)b_i + 40.0F) - 1] = minimum(b_inputECG);
  }
  emxFree_real32_T(&b_inputECG);
}

/*
 * Arguments    : const float tHRV_data[]
 *                const int tHRV_size[2]
 *                float HRV_data[]
 *                const int HRV_size[2]
 *                int idx5
 *                int idx6
 *                int idx7
 *                int idx8
 *                float Tot_pow_data[]
 *                int Tot_pow_size[2]
 *                float *nHF
 *                float *LF_HF
 * Return Type  : float
 */
static float features_Freq_calculator(const float tHRV_data[],
                                      const int tHRV_size[2], float HRV_data[],
                                      const int HRV_size[2], int idx5, int idx6,
                                      int idx7, int idx8, float Tot_pow_data[],
                                      int Tot_pow_size[2], float *nHF,
                                      float *LF_HF)
{
  emxArray_real32_T *f_tmp;
  emxArray_real32_T *pxx_tmp;
  float Freq_betw_04_15;
  float Freq_betw_15_40;
  float nLF;
  float *f_tmp_data;
  int i;
  boolean_T tmp_data[400];
  Tot_pow_size[0] = 1;
  Tot_pow_size[1] = 1;
  Tot_pow_data[0] = 0.0F;
  nLF = 0.0F;
  *nHF = 0.0F;
  *LF_HF = 0.0F;
  if (HRV_size[1] > 1) {
    int tmp_size[2];
    int end;
    d_isinf(HRV_data, HRV_size, tmp_data, tmp_size);
    Freq_betw_04_15 = b_minimum(HRV_data, HRV_size);
    end = tmp_size[1] - 1;
    for (i = 0; i <= end; i++) {
      if (tmp_data[i]) {
        HRV_data[i] = Freq_betw_04_15;
      }
    }
    emxInit_real32_T(&pxx_tmp, 2);
    emxInit_real32_T(&f_tmp, 2);
    plomb(HRV_data, HRV_size, tHRV_data, tHRV_size, pxx_tmp, f_tmp);
    f_tmp_data = f_tmp->data;
    /* Tot_pow */
    /*      Tot_pow = bandpower(pxx, f, 'psd'); */
    if (idx5 != -1) {
      Feature5(pxx_tmp, f_tmp, Tot_pow_data, Tot_pow_size);
    } else {
      Tot_pow_size[0] = 1;
      Tot_pow_size[1] = 1;
      Tot_pow_data[0] = rtNaNF;
    }
    /* VLF */
    /* if f(1)>=0.04 */
    /*     Freq_less_04=0; */
    /* else */
    /*     Freq_less_04 = bandpower(pxx, f, [f(1) , 0.04], 'psd'); */
    /* end */
    /* nVLF  = Freq_less_04/Tot_pow; */
    /* LF */
    if ((idx6 != -1) || (idx7 != -1)) {
      /*      Freq_betw_04_15 = bandpower(pxx, f, [max(0.04,f(1))
       * min(0.15,f(end))], 'psd'); */
      /*      nLF = Freq_betw_04_15/Tot_pow; */
      if (idx6 != -1) {
        float fv[2];
        fv[0] = maximum2(0.04F, f_tmp_data[0]);
        fv[1] = minimum2(0.15F, f_tmp_data[f_tmp->size[0] - 1]);
        nLF = Feature6(pxx_tmp, f_tmp, fv, Tot_pow_data, Tot_pow_size,
                       &Freq_betw_04_15);
      } else {
        nLF = rtNaNF;
        Freq_betw_04_15 = 0.0F;
      }
      /* HF */
      if (idx7 != -1) {
        *nHF = Feature7(pxx_tmp, f_tmp, Tot_pow_data, Tot_pow_size,
                        &Freq_betw_15_40);
      } else {
        *nHF = rtNaNF;
        Freq_betw_15_40 = 0.0F;
      }
      /*      if f(end)<=0.4 */
      /*          Freq_betw_15_40=0; */
      /*          nHF = Freq_betw_15_40/Tot_pow; */
      /*      else */
      /*          freq_range = [ 0.15 min(0.4, f(end))]; */
      /*  %         Freq_betw_15_40 = bandpower(pxx, f, freq_range, 'psd'); */
      /*          [nHF, Freq_betw_15_40] = Feature7(pxx, f, freq_range, 'psd',
       * Tot_pow); */
      /*      end */
      /*      nHF = Freq_betw_15_40/Tot_pow; */
      /*      nHF = Feature7(Freq_betw_15_40,Tot_pow); */
      /* LF_HF */
      /*      LF_HF=Freq_betw_04_15/Freq_betw_15_40; */
      if (idx8 != -1) {
        *LF_HF = Feature8(Freq_betw_04_15, Freq_betw_15_40);
      } else {
        *LF_HF = rtNaNF;
      }
    } else {
      nLF = rtNaNF;
      *nHF = rtNaNF;
      *LF_HF = rtNaNF;
    }
    emxFree_real32_T(&f_tmp);
    emxFree_real32_T(&pxx_tmp);
  }
  return nLF;
}

/*
 * Mean_RR=mean(RR_Interv);
 *
 * Arguments    : const float RR_Interv_data[]
 *                const int RR_Interv_size[2]
 *                int idx1
 *                int idx2
 *                int idx3
 *                int idx4
 *                float *Std_RR
 *                float *RMSSD
 *                float *pNN50
 * Return Type  : float
 */
static float features_time_calculator(const float RR_Interv_data[],
                                      const int RR_Interv_size[2], int idx1,
                                      int idx2, int idx3, int idx4,
                                      float *Std_RR, float *RMSSD, float *pNN50)
{
  float Mean_RR;
  if (idx1 != -1) {
    Mean_RR = Feature1(RR_Interv_data, RR_Interv_size);
  } else {
    Mean_RR = rtNaNF;
  }
  /*  Std_RR=std(RR_Interv); */
  if (idx2 != -1) {
    *Std_RR = Feature2(RR_Interv_data, RR_Interv_size);
  } else {
    *Std_RR = rtNaNF;
  }
  /*  RMSSD=sqrt(mean(diff(RR_Interv).^2)); */
  if (idx3 != -1) {
    *RMSSD = Feature3(RR_Interv_data, RR_Interv_size);
  } else {
    *RMSSD = rtNaNF;
  }
  /*  pNN50=length(find(diff(RR_Interv) > 0.05))./length(diff(RR_Interv)); */
  if (idx4 != -1) {
    *pNN50 = Feature4(RR_Interv_data, RR_Interv_size);
  } else {
    *pNN50 = rtNaNF;
  }
  return Mean_RR;
}

/*
 * Feature selector mask is used to select which feature extract, it has the
 *  following format:
 *  idx 1 : extract_HRV_features_time
 *  idx 2 : extract_HRV_features_freq
 *  idx 3 : extract_HR_dif
 *  idx 4 : extract_Lorenz
 *  idx 5 : extract_Mean_SPO2
 *  idx 6 : extract_STD_SPO2
 *
 * Arguments    : const emxArray_real32_T *ECG_Sig
 *                const emxArray_real32_T *Spo2_sig
 *                const signed char feature_selector_struct[17]
 *                emxArray_real32_T *Features
 * Return Type  : float
 */
static float my_Extract_features_Jep_orig(
    const emxArray_real32_T *ECG_Sig, const emxArray_real32_T *Spo2_sig,
    const signed char feature_selector_struct[17], emxArray_real32_T *Features)
{
  emxArray_real32_T *Rlocs;
  emxArray_real32_T *b_Features;
  emxArray_real32_T *feature;
  emxArray_real32_T *locs;
  emxArray_real32_T *r;
  emxArray_real32_T *tHRV;
  double dv[6];
  float HRV[400];
  float HRV_data[400];
  float RR_Interv[400];
  float RR_Interv_filtr[400];
  float b_locs_data[400];
  float CSI_filt_tmp_data[8];
  float CSI_tmp_data[8];
  float HR_diff_orig_tmp_data[8];
  float Mod_CSI_filt_tmp_data[8];
  float Mod_CSI_tmp_data[8];
  float c[6];
  float HF_tmp;
  float LF_HF_tmp;
  float LF_tmp;
  float Slope_tmp;
  float denoise_start_time;
  float *Features_data;
  float *Rlocs_data;
  float *b_Features_data;
  float *locs_data;
  int HRV_size[2];
  int locs_size[2];
  int b_i;
  int i;
  int i1;
  int i2;
  int idx10_tmp;
  int idx11_tmp;
  int idx12_tmp;
  int idx13_tmp;
  int idx14_tmp;
  int idx15_tmp;
  int idx16_tmp;
  int idx17_tmp;
  int idx1_tmp;
  int idx2_tmp;
  int idx3_tmp;
  int idx4_tmp;
  int idx5_tmp;
  int idx6_tmp;
  int idx7_tmp;
  int idx8_tmp;
  int idx9_tmp;
  int loop_ub;
  int n_feat_tmp;
  Features_data = Features->data;
  for (i = 0; i < 6; i++) {
    c[i] = (float)dv[i];
  }
  denoise_start_time = c[4] * 60.0F + c[5];
  emxInit_real32_T(&r, 1);
  denoise_rwd(ECG_Sig, r);
  emxInit_real32_T(&tHRV, 2);
  emxInit_real32_T(&feature, 2);
  pan_tompkin_algorithm_segmented(r, tHRV, feature);
  emxFree_real32_T(&r);
  for (i = 0; i < 6; i++) {
    c[i] = (float)dv[i];
  }
  emxInit_real32_T(&Rlocs, 2);
  unique_vector(feature, Rlocs);
  Rlocs_data = Rlocs->data;
  emxInit_real32_T(&locs, 2);
  i = locs->size[0] * locs->size[1];
  locs->size[0] = 1;
  locs->size[1] = Rlocs->size[1];
  emxEnsureCapacity_real32_T(locs, i);
  locs_data = locs->data;
  loop_ub = Rlocs->size[1];
  for (i = 0; i < loop_ub; i++) {
    locs_data[i] = Rlocs_data[i] / 256.0F;
  }
  for (i = 0; i < 400; i++) {
    RR_Interv[i] = rtNaNF;
  }
  c_diff(locs, tHRV);
  Rlocs_data = tHRV->data;
  loop_ub = tHRV->size[1];
  for (i = 0; i < loop_ub; i++) {
    RR_Interv[i] = Rlocs_data[i];
  }
  /* RR_Interv_filtr_2=medfilt1(RR_Interv); %changed to movmedian to for C
   * generation */
  movmedian(RR_Interv, RR_Interv_filtr);
  if (locs->size[1] < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = locs->size[1];
  }
  i2 = tHRV->size[0] * tHRV->size[1];
  tHRV->size[0] = 1;
  loop_ub = i1 - i;
  tHRV->size[1] = loop_ub;
  emxEnsureCapacity_real32_T(tHRV, i2);
  Rlocs_data = tHRV->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    Rlocs_data[i1] = locs_data[i + i1];
  }
  for (i1 = 0; i1 < 400; i1++) {
    HRV[i1] = 1.0F / RR_Interv[i1];
  }
  /*  Features = NaN(400, 17); */
  /*  feature_idx = 0; */
  /*  feature_size = 0; */
  /*  idx_features = 0; */
  idx1_tmp = calculate_idxs_from_mask(
      feature_selector_struct, &idx2_tmp, &idx3_tmp, &idx4_tmp, &idx5_tmp,
      &idx6_tmp, &idx7_tmp, &idx8_tmp, &idx9_tmp, &idx10_tmp, &idx11_tmp,
      &idx12_tmp, &idx13_tmp, &idx14_tmp, &idx15_tmp, &idx16_tmp, &idx17_tmp,
      &n_feat_tmp);
  Features->size[0] = 0;
  Features->size[1] = 0;
  b_i = 0;
  emxInit_real32_T(&b_Features, 2);
  while ((b_i < 350) && (!c_isnan(RR_Interv[b_i + 50]))) {
    int CSI_filt_tmp_size[2];
    int input_sizes_idx_0;
    int sizes_idx_0_tmp;
    signed char sizes_idx_0;
    boolean_T b;
    boolean_T empty_non_axis_sizes;
    i1 = feature->size[0] * feature->size[1];
    feature->size[0] = 1;
    loop_ub = (int)(float)n_feat_tmp;
    feature->size[1] = (int)(float)n_feat_tmp;
    emxEnsureCapacity_real32_T(feature, i1);
    Rlocs_data = feature->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      Rlocs_data[i1] = rtNaNF;
    }
    /* Lorenz features */
    if ((idx9_tmp != -1) || (idx10_tmp != -1) || (idx11_tmp != -1) ||
        (idx12_tmp != -1) || (idx13_tmp != -1) || (idx14_tmp != -1) ||
        (idx15_tmp != -1)) {
      int CSI_tmp_size[2];
      int HR_diff_orig_tmp_size[2];
      int Mod_CSI_filt_tmp_size[2];
      int Mod_CSI_tmp_size[2];
      Slope_tmp = Lorenz_features(
          RR_Interv_filtr, RR_Interv, (float)b_i + 51.0F, tHRV, idx9_tmp,
          idx10_tmp, idx11_tmp, idx12_tmp, idx13_tmp, idx14_tmp, idx15_tmp,
          CSI_filt_tmp_data, CSI_filt_tmp_size, Mod_CSI_filt_tmp_data,
          Mod_CSI_filt_tmp_size, CSI_tmp_data, CSI_tmp_size, Mod_CSI_tmp_data,
          Mod_CSI_tmp_size, HR_diff_orig_tmp_data, HR_diff_orig_tmp_size);
      if (idx10_tmp != -1) {
        Rlocs_data[idx10_tmp - 1] = Feature10(CSI_filt_tmp_data, Slope_tmp);
        /* f10 */
      }
      if (idx11_tmp != -1) {
        Rlocs_data[idx11_tmp - 1] = Feature10(Mod_CSI_filt_tmp_data, Slope_tmp);
        /* f11 */
      }
      if (idx12_tmp != -1) {
        Rlocs_data[idx12_tmp - 1] = Feature10(CSI_tmp_data, Slope_tmp);
        /* f12 */
      }
      if (idx13_tmp != -1) {
        Rlocs_data[idx13_tmp - 1] = Feature10(Mod_CSI_tmp_data, Slope_tmp);
        /* f13 */
      }
      if (idx14_tmp != -1) {
        Rlocs_data[idx14_tmp - 1] = Feature14(CSI_tmp_data);
        /* f14 */
      }
      if (idx15_tmp != -1) {
        Rlocs_data[idx15_tmp - 1] = Feature14(Mod_CSI_tmp_data);
        /* f15 */
      }
      /*               */
      /*          end */
      if (idx9_tmp != -1) {
        /*              HR_diff = [HR_diff;HR_diff_orig]; */
        /*              Features(i-x0+1,9-idx_time-idx_freq) = HR_diff_orig(1);
         * %f9 */
        Rlocs_data[idx9_tmp - 1] = Feature14(HR_diff_orig_tmp_data);
        /* f9 */
      }
    }
    /* HRV features (time and freq) */
    /*      if feature_selector_struct.mask(2) */
    if ((idx5_tmp != -1) || (idx6_tmp != -1) || (idx7_tmp != -1) ||
        (idx8_tmp != -1)) {
      locs_size[0] = 1;
      locs_size[1] = 51;
      for (i1 = 0; i1 < 51; i1++) {
        b_locs_data[i1] = locs_data[(i + b_i) + i1];
      }
      HRV_size[0] = 1;
      HRV_size[1] = 51;
      memcpy(&HRV_data[0], &HRV[b_i], 51U * sizeof(float));
      LF_tmp = features_Freq_calculator(b_locs_data, locs_size, HRV_data,
                                        HRV_size, idx5_tmp, idx6_tmp, idx7_tmp,
                                        idx8_tmp, (float *)&Slope_tmp,
                                        CSI_filt_tmp_size, &HF_tmp, &LF_HF_tmp);
      if (idx5_tmp != -1) {
        Rlocs_data[idx5_tmp - 1] = Slope_tmp;
        /* f5 */
      }
      if (idx6_tmp != -1) {
        Rlocs_data[idx6_tmp - 1] = LF_tmp;
        /* f6   */
      }
      if (idx7_tmp != -1) {
        Rlocs_data[idx7_tmp - 1] = HF_tmp;
        /* f7   */
      }
      if (idx8_tmp != -1) {
        Rlocs_data[idx8_tmp - 1] = LF_HF_tmp;
        /* f8   */
      }
    }
    if ((idx1_tmp != -1) || (idx2_tmp != -1) || (idx3_tmp != -1) ||
        (idx4_tmp != -1)) {
      locs_size[0] = 1;
      locs_size[1] = 51;
      memcpy(&b_locs_data[0], &RR_Interv_filtr[b_i], 51U * sizeof(float));
      Slope_tmp = features_time_calculator(b_locs_data, locs_size, idx1_tmp,
                                           idx2_tmp, idx3_tmp, idx4_tmp,
                                           &LF_tmp, &HF_tmp, &LF_HF_tmp);
      if (idx1_tmp != -1) {
        Rlocs_data[idx1_tmp - 1] = Slope_tmp;
        /* f1 */
      }
      if (idx2_tmp != -1) {
        Rlocs_data[idx2_tmp - 1] = LF_tmp;
        /* f1 */
      }
      if (idx3_tmp != -1) {
        Rlocs_data[idx3_tmp - 1] = HF_tmp;
        /* f3 */
      }
      if (idx4_tmp != -1) {
        Rlocs_data[idx4_tmp - 1] = LF_HF_tmp;
        /* f4 */
      }
    }
    if (idx16_tmp != -1) {
      Rlocs_data[idx16_tmp - 1] =
          Feature16(Spo2_sig, Rlocs, (float)b_i + 51.0F);
    }
    /*      if feature_selector_struct.mask(6) */
    if (idx17_tmp != -1) {
      Rlocs_data[idx17_tmp - 1] =
          Feature17(Spo2_sig, Rlocs, (float)b_i + 51.0F);
    }
    /*  switch n_feat */
    /*      case 2 */
    /*          % extract_feature = extract_feature(:, 5); */
    /*          norm_coef1 = [0.0239    0.0377]; */
    /*          extract_feature = feature./norm_coef1; */
    /*          classifier = loadLearnerForCoder("../c_model/full_model1.mat");
     */
    /*          [predict_res, conf_res] = predict(classifier, extract_feature);
     */
    /*      case 3 */
    /*          norm_coef2 = [0.8192    0.0239    0.0377]; */
    /*          extract_feature = feature./norm_coef2; */
    /*          classifier = loadLearnerForCoder("../c_model/full_model2.mat");
     */
    /*          [predict_res, conf_res] = predict(classifier, extract_feature);
     */
    /*      case 5 */
    /*          norm_coef3 = [0.8192    0.0376    0.0239    0.0377   92.4333];
     */
    /*          extract_feature = feature./norm_coef3; */
    /*          classifier = loadLearnerForCoder("../c_model/full_model3.mat");
     */
    /*          [predict_res, conf_res] = predict(classifier, extract_feature);
     */
    /*      case 13 */
    /*          norm_coef4 = [0.8192    0.0376    0.0239    0.0377   -0.0023
     * 0.0049    1.6571    0.0027    0.8521    2.1909  496.8759   92.4333
     * 0.5755]; */
    /*          extract_feature = feature./norm_coef4; */
    /*          classifier = loadLearnerForCoder("../c_model/full_model4.mat");
     */
    /*          [predict_res, conf_res] = predict(classifier, extract_feature);
     */
    /*      case 17 */
    /*          norm_coef5 = [0.8192    0.0376    0.0239    0.0377    0.0223
     * 0.3428    0.3357    2.8675   -0.0023    0.0049    1.6571    0.0027 0.8521
     * 2.1909  496.8759   92.4333    0.5755]; */
    /*          extract_feature = feature./norm_coef5; */
    /*          classifier = loadLearnerForCoder("../c_model/full_model5.mat");
     */
    /*          [predict_res, conf_res] = predict(classifier, extract_feature);
     */
    /*      otherwise */
    /*          predict_res = NaN; */
    /*          conf_res = NaN; */
    /*   */
    /*  end */
    b = ((Features->size[0] != 0) && (Features->size[1] != 0));
    if (b) {
      loop_ub = Features->size[1];
    } else if (feature->size[1] != 0) {
      loop_ub = feature->size[1];
    } else {
      loop_ub = Features->size[1];
    }
    empty_non_axis_sizes = (loop_ub == 0);
    if (empty_non_axis_sizes || b) {
      input_sizes_idx_0 = Features->size[0];
    } else {
      input_sizes_idx_0 = 0;
    }
    if (empty_non_axis_sizes || (feature->size[1] != 0)) {
      sizes_idx_0 = 1;
    } else {
      sizes_idx_0 = 0;
    }
    sizes_idx_0_tmp = sizes_idx_0;
    i1 = b_Features->size[0] * b_Features->size[1];
    b_Features->size[0] = input_sizes_idx_0 + sizes_idx_0;
    b_Features->size[1] = loop_ub;
    emxEnsureCapacity_real32_T(b_Features, i1);
    b_Features_data = b_Features->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < input_sizes_idx_0; i2++) {
        b_Features_data[i2 + b_Features->size[0] * i1] =
            Features_data[i2 + input_sizes_idx_0 * i1];
      }
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < sizes_idx_0_tmp; i2++) {
        b_Features_data[input_sizes_idx_0 + b_Features->size[0] * i1] =
            Rlocs_data[sizes_idx_0 * i1];
      }
    }
    i1 = Features->size[0] * Features->size[1];
    Features->size[0] = b_Features->size[0];
    Features->size[1] = b_Features->size[1];
    emxEnsureCapacity_real32_T(Features, i1);
    Features_data = Features->data;
    loop_ub = b_Features->size[0] * b_Features->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      Features_data[i1] = b_Features_data[i1];
    }
    b_i++;
  }
  emxFree_real32_T(&b_Features);
  emxFree_real32_T(&feature);
  emxFree_real32_T(&tHRV);
  emxFree_real32_T(&locs);
  emxFree_real32_T(&Rlocs);
  /*  Features_out = Features(1:stop-x0,:); */
  /*  Features_out = Features(Nbr_RR+1:size(Rlocs,2)-1,:); */
  return (c[4] * 60.0F + c[5]) - denoise_start_time;
}

/*
 * Arguments    : const float tHRV_data[]
 *                const int tHRV_size[2]
 *                const float RR_Interv_filtr_data[]
 *                const int RR_Interv_filtr_size[2]
 * Return Type  : float
 */
static float my_slope(const float tHRV_data[], const int tHRV_size[2],
                      const float RR_Interv_filtr_data[],
                      const int RR_Interv_filtr_size[2])
{
  float x_tmp_data[400];
  float Slope;
  float mean_X;
  float mean_y;
  int b_x_tmp_size[2];
  int c_x_tmp_size[2];
  int x_tmp_size[2];
  int i;
  int loop_ub;
  mean_X = d_mean(tHRV_data, tHRV_size);
  mean_y = d_mean(RR_Interv_filtr_data, RR_Interv_filtr_size);
  x_tmp_size[0] = 1;
  x_tmp_size[1] = tHRV_size[1];
  loop_ub = tHRV_size[1];
  for (i = 0; i < loop_ub; i++) {
    x_tmp_data[i] = tHRV_data[i] - mean_X;
  }
  if (tHRV_size[1] == RR_Interv_filtr_size[1]) {
    float b_x_tmp_data[400];
    float c_x_tmp_data[400];
    b_x_tmp_size[0] = 1;
    b_x_tmp_size[1] = tHRV_size[1];
    loop_ub = tHRV_size[1];
    c_x_tmp_size[0] = 1;
    c_x_tmp_size[1] = tHRV_size[1];
    for (i = 0; i < loop_ub; i++) {
      mean_X = x_tmp_data[i];
      b_x_tmp_data[i] = mean_X * (RR_Interv_filtr_data[i] - mean_y);
      c_x_tmp_data[i] = mean_X * mean_X;
    }
    Slope =
        b_sum(b_x_tmp_data, b_x_tmp_size) / b_sum(c_x_tmp_data, c_x_tmp_size);
  } else {
    Slope = binary_expand_op_8(x_tmp_data, x_tmp_size, RR_Interv_filtr_data,
                               RR_Interv_filtr_size, mean_y);
  }
  return Slope;
}

/*
 * Arguments    : const emxArray_real32_T *inputECG
 *                emxArray_real32_T *outputECG
 * Return Type  : void
 */
static void opening(const emxArray_real32_T *inputECG,
                    emxArray_real32_T *outputECG)
{
  emxArray_real32_T *r;
  emxInit_real32_T(&r, 1);
  erosion_s1(inputECG, r);
  dilation_s1(r, outputECG);
  emxFree_real32_T(&r);
}

/*
 * FRAN: I changed the threshold calculation with respect to the previous
 * impementation. Before, the thresholds were calculated at the beginning and
 * updated for every new peak. This caused problems when the signal was very
 * noisy at some point, since the thresholds took ages to come back to a
 * value where the peaks following the noise could be detected. Now the
 * thresholds are calculated using 2 seconds of the signal every time a peak
 * is detected
 *
 * Arguments    : emxArray_real32_T *sig_short
 *                emxArray_real32_T *qrs_amp_raw
 *                emxArray_real32_T *Rloc
 * Return Type  : void
 */
static void pan_tompkin_algorithm_segmented(emxArray_real32_T *sig_short,
                                            emxArray_real32_T *qrs_amp_raw,
                                            emxArray_real32_T *Rloc)
{
  emxArray_boolean_T *b_qrs_i_raw;
  emxArray_real32_T *b_ecg_hpf;
  emxArray_real32_T *b_ecg_lpf;
  emxArray_real32_T *ecg_hpf;
  emxArray_real32_T *ecg_lpf;
  emxArray_real32_T *locs;
  emxArray_real32_T *pks;
  emxArray_real32_T *qrs_i_raw;
  emxArray_real32_T *qrs_i_vec;
  emxArray_real32_T *r;
  emxArray_real_T *locs_tmp;
  double *locs_tmp_data;
  float comp;
  float m_selected_RR;
  float mean_RR;
  float x_i;
  float x_i_t;
  float y_i;
  float *Rloc_data;
  float *b_ecg_hpf_data;
  float *ecg_hpf_data;
  float *ecg_lpf_data;
  float *locs_data;
  float *pks_data;
  float *qrs_amp_raw_data;
  float *qrs_i_raw_data;
  float *qrs_i_vec_data;
  float *sig_short_data;
  int b_i;
  int diffRR_counter;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int qY;
  int qrs_c_couter;
  int qrs_i_idx;
  int ser_back;
  boolean_T *b_qrs_i_raw_data;
  sig_short_data = sig_short->data;
  comp = mean(sig_short);
  loop_ub = sig_short->size[0];
  for (i = 0; i < loop_ub; i++) {
    sig_short_data[i] -= comp;
  }
  /*  Initialize */
  /*  qrs_c =[]; %amplitude of R */
  qrs_c_couter = -1;
  /*  qrs_i =[]; %index */
  /*  qrs_i = zeros(1, length(pks)); */
  /*  qrs_i_couter = 0; */
  /*  becomes one when a T wave is detected */
  m_selected_RR = 0.0F;
  mean_RR = 0.0F;
  /*  qrs_i_raw =[]; */
  /*  qrs_amp_raw=[]; */
  ser_back = 0;
  y_i = 0.0F;
  x_i = 0.0F;
  /*  Filtering - High Pass Filter & Low pass filter */
  /*  displayMessage('Filtering...'); */
  /*  Low Pass Filter  H(z) = ((1 - z^(-6))^2)/(1 - z^(-1))^2 */
  /*  sig_short -> the one from ecgprocessing */
  /* try to find an automatic was for this */
  /*  [~, w_lpf] = freqz(b_lpf, a_lpf, 2000); */
  /*  f_lpf = fs*w_lpf/(2*pi); */
  emxInit_real32_T(&ecg_lpf, 1);
  filter(sig_short, ecg_lpf);
  ecg_lpf_data = ecg_lpf->data;
  emxInit_real32_T(&r, 1);
  e_abs(ecg_lpf, r);
  x_i_t = maximum(r);
  loop_ub = ecg_lpf->size[0];
  for (i = 0; i < loop_ub; i++) {
    ecg_lpf_data[i] /= x_i_t;
  }
  /*  High Pass filter H(z) = (-1 + 32z^(-16)- 32z^(-17) + z^(-32))/(32 -
   * 32z^(-1)) */
  emxInit_real32_T(&ecg_hpf, 1);
  b_filter(ecg_lpf, ecg_hpf);
  ecg_hpf_data = ecg_hpf->data;
  e_abs(ecg_hpf, r);
  x_i_t = maximum(r);
  loop_ub = ecg_hpf->size[0];
  for (i = 0; i < loop_ub; i++) {
    ecg_hpf_data[i] /= x_i_t;
  }
  /*  [h_hpf, w_hpf] = freqz(b_hpf, a_hpf, 2000); */
  /*  f_hpf = fs*w_hpf/(2*pi); */
  /*  derivative filter H(z) = 0.1(2 + z^(-1) - z^(-3) - 2z^(-4)) */
  c_filter(ecg_hpf, ecg_lpf);
  ecg_lpf_data = ecg_lpf->data;
  x_i_t = maximum(ecg_lpf);
  loop_ub = ecg_lpf->size[0];
  for (i = 0; i < loop_ub; i++) {
    ecg_lpf_data[i] /= x_i_t;
  }
  /*  Squaring nonlinearly enhance the dominant peaks */
  /*  Moving average Y(nt) = (1/N)[x(nT-(N - 1)T)+ x(nT - (N - 2)T)+...+x(nT)]
   */
  /*  Namely in the paper we have a sampling frequency of 200Hz for which we */
  /*  have a moving window having 30 samples i.e. 150ms... So, 200:150 = 250:x
   */
  /*  -> we are getting a new length of our window which is equal to 187.5 ms */
  /*  200 elementi */
  /*  b_test = ones(1,200)/round(length_maw*fs); */
  power(ecg_lpf, r);
  d_filter(r, ecg_lpf);
  ecg_lpf_data = ecg_lpf->data;
  /*  ecg_m_test = filter(b_test, 1, ecg_s); */
  /*  for i=1:length(ecg_m) */
  /*     if ecg_m(i)~=ecg_m_test(i)  */
  /*          ecg_m(i) */
  /*          ecg_m_test(i)  */
  /*     end */
  /*  end */
  /*  Finding potential R peaks - no RR waves can occur in less than 200 msec
   * distance */
  /* displayMessage('Finding candidates...'); */
  emxInit_real32_T(&pks, 1);
  emxInit_real_T(&locs_tmp, 1);
  findpeaks(ecg_lpf, pks, locs_tmp);
  locs_tmp_data = locs_tmp->data;
  pks_data = pks->data;
  emxInit_real32_T(&locs, 1);
  i = locs->size[0];
  locs->size[0] = locs_tmp->size[0];
  emxEnsureCapacity_real32_T(locs, i);
  locs_data = locs->data;
  loop_ub = locs_tmp->size[0];
  for (i = 0; i < loop_ub; i++) {
    locs_data[i] = (float)locs_tmp_data[i];
  }
  emxFree_real_T(&locs_tmp);
  emxInit_real32_T(&qrs_i_vec, 2);
  i = qrs_i_vec->size[0] * qrs_i_vec->size[1];
  qrs_i_vec->size[0] = 1;
  qrs_i_vec->size[1] = pks->size[0];
  emxEnsureCapacity_real32_T(qrs_i_vec, i);
  qrs_i_vec_data = qrs_i_vec->data;
  loop_ub = pks->size[0];
  emxInit_real32_T(&qrs_i_raw, 2);
  i = qrs_i_raw->size[0] * qrs_i_raw->size[1];
  qrs_i_raw->size[0] = 1;
  qrs_i_raw->size[1] = pks->size[0];
  emxEnsureCapacity_real32_T(qrs_i_raw, i);
  qrs_i_raw_data = qrs_i_raw->data;
  i = qrs_amp_raw->size[0] * qrs_amp_raw->size[1];
  qrs_amp_raw->size[0] = 1;
  qrs_amp_raw->size[1] = pks->size[0];
  emxEnsureCapacity_real32_T(qrs_amp_raw, i);
  qrs_amp_raw_data = qrs_amp_raw->data;
  for (i = 0; i < loop_ub; i++) {
    qrs_i_vec_data[i] = 0.0F;
    qrs_i_raw_data[i] = 0.0F;
    qrs_amp_raw_data[i] = 0.0F;
  }
  /*  initialize the training phase (2 seconds of the signal) to determine the
   * THR_SIG and THR_NOISE */
  /*  0.25 of the max amplitude */
  /*  0.5 of the mean signal is considered to be noise */
  /*  Initialize bandpath filter threshold(2 seconds of the bandpass signal) */
  /*  0.25 of the max amplitude */
  /*  */
  /*  Signal level in Bandpassed filter */
  /*  Noise level in Bandpassed filter */
  /*  Thresholding and online desicion rule */
  /* displayMessage('Detecting R peaks...'); */
  while ((float)ecg_lpf->size[0] - locs_data[locs->size[0] - 1] < 512.0F) {
    nullAssignment(locs, locs->size[0]);
    locs_data = locs->data;
    nullAssignment(pks, pks->size[0]);
    pks_data = pks->data;
  }
  i = pks->size[0];
  emxInit_real32_T(&b_ecg_hpf, 1);
  emxInit_real32_T(&b_ecg_lpf, 1);
  for (b_i = 0; b_i < i; b_i++) {
    float varargin_1[513];
    float THR_SIG;
    float THR_SIG1;
    float y;
    comp = locs_data[b_i];
    for (i1 = 0; i1 < 513; i1++) {
      varargin_1[i1] = ecg_lpf_data[(int)(comp + (float)i1) - 1];
    }
    THR_SIG = b_maximum(varargin_1) / 3.0F;
    /*  0.25 of the max amplitude */
    qrs_i_idx = (int)locs_data[b_i];
    x_i_t = b_mean(&ecg_lpf_data[qrs_i_idx - 1]);
    /*  0.5 of the mean signal is considered to be noise */
    /*     %% Initialize bandpath filter threshold(2 seconds of the bandpass
     * signal) */
    for (i1 = 0; i1 < 513; i1++) {
      varargin_1[i1] = ecg_hpf_data[(int)(comp + (float)i1) - 1];
    }
    THR_SIG1 = b_maximum(varargin_1) / 3.0F;
    /*  0.25 of the max amplitude */
    y = b_mean(&ecg_hpf_data[qrs_i_idx - 1]);
    /*  */
    /*  Signal level in Bandpassed filter */
    /*  Noise level in Bandpassed filter */
    /*     %% locate the corresponding peak in the filtered signal - the output
     * of the HPF ecg_hpf */
    if ((locs_data[b_i] - c_round(38.4F) >= 1.0F) &&
        ((double)locs_data[b_i] <= ecg_hpf->size[0])) {
      if (locs_data[b_i] - 38.0F > locs_data[b_i]) {
        i1 = 0;
        qrs_i_idx = 0;
      } else {
        i1 = (int)(locs_data[b_i] - 38.0F) - 1;
      }
      loop_ub = qrs_i_idx - i1;
      i2 = b_ecg_hpf->size[0];
      b_ecg_hpf->size[0] = loop_ub;
      emxEnsureCapacity_real32_T(b_ecg_hpf, i2);
      b_ecg_hpf_data = b_ecg_hpf->data;
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_ecg_hpf_data[i2] = ecg_hpf_data[i1 + i2];
      }
      y_i = c_maximum(b_ecg_hpf, &diffRR_counter);
      x_i = (float)diffRR_counter;
    } else if (b_i + 1 == 1) {
      qrs_i_idx = (int)locs_data[0];
      i1 = b_ecg_hpf->size[0];
      b_ecg_hpf->size[0] = (int)locs_data[0];
      emxEnsureCapacity_real32_T(b_ecg_hpf, i1);
      b_ecg_hpf_data = b_ecg_hpf->data;
      for (i1 = 0; i1 < qrs_i_idx; i1++) {
        b_ecg_hpf_data[i1] = ecg_hpf_data[i1];
      }
      y_i = c_maximum(b_ecg_hpf, &diffRR_counter);
      x_i = (float)diffRR_counter;
      ser_back = 1;
    } else if ((double)locs_data[b_i] >= ecg_hpf->size[0]) {
      if (locs_data[b_i] - 38.0F > ecg_hpf->size[0]) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (int)(locs_data[b_i] - 38.0F) - 1;
        i2 = (int)(float)ecg_hpf->size[0];
      }
      loop_ub = i2 - i1;
      i2 = b_ecg_hpf->size[0];
      b_ecg_hpf->size[0] = loop_ub;
      emxEnsureCapacity_real32_T(b_ecg_hpf, i2);
      b_ecg_hpf_data = b_ecg_hpf->data;
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_ecg_hpf_data[i2] = ecg_hpf_data[i1 + i2];
      }
      y_i = c_maximum(b_ecg_hpf, &diffRR_counter);
      x_i = (float)diffRR_counter;
    }
    /* update the heart_rate (Two heart rate means one the most recent and the
     * other selected) */
    /*      if length(qrs_c) >= 9 */
    if (qrs_c_couter + 1 >= 9) {
      float diffRR_buffer[9];
      /*          diffRR = diff(qrs_i(end-8:end)); */
      diffRR_counter = 1;
      for (i1 = 0; i1 < 9; i1++) {
        diffRR_buffer[i1] = 0.0F;
      }
      qrs_i_idx = 8;
      while (diffRR_counter <= 9) {
        boolean_T b;
        b = ((qrs_c_couter + 1 >= 0) &&
             (qrs_i_idx < qrs_c_couter - 2147483646));
        if (b) {
          qY = MAX_int32_T;
        } else if ((qrs_c_couter + 1 < 0) &&
                   (qrs_i_idx > qrs_c_couter - MAX_int32_T)) {
          qY = MIN_int32_T;
        } else {
          qY = (qrs_c_couter - qrs_i_idx) + 1;
        }
        if (qrs_i_vec_data[qY - 1] != 0.0F) {
          if (b) {
            qY = MAX_int32_T;
          } else if ((qrs_c_couter + 1 < 0) &&
                     (qrs_i_idx > qrs_c_couter - MAX_int32_T)) {
            qY = MIN_int32_T;
          } else {
            qY = (qrs_c_couter - qrs_i_idx) + 1;
          }
          diffRR_buffer[diffRR_counter - 1] = qrs_i_vec_data[qY - 1];
          diffRR_counter++;
          if (qrs_i_idx < -2147483647) {
            qrs_i_idx = MIN_int32_T;
          } else {
            qrs_i_idx--;
          }
        }
        /*              qrs_i_idx = qrs_i_idx - 1; */
      }
      float fv[8];
      /*          if any(diffRR ~= diff(diffRR_buffer)) */
      /*              any(diffRR ~= diff(diffRR_buffer)) */
      /*          end */
      /* calculate RR interval */
      diff(diffRR_buffer, fv);
      mean_RR = c_mean(fv);
      /*  calculate the mean of 8 previous R waves interval */
      /*          comp = qrs_i(end)-qrs_i(end-1); %latest RR */
      comp = qrs_i_vec_data[qrs_c_couter] - qrs_i_vec_data[qrs_c_couter - 1];
      /* latest RR */
      /*          if comp ~= comp2 */
      /*             comp  */
      /*             comp2 */
      /*          end */
      if ((comp <= 0.92F * mean_RR) || (comp >= 1.16F * mean_RR)) {
        /*  lower down thresholds to detect better in MVI */
        THR_SIG *= 0.5F;
        /*  lower down thresholds to detect better in Bandpass filtered */
        THR_SIG1 *= 0.5F;
        /* THR_NOISE1 = 0.5*(THR_SIG1); */
      } else {
        m_selected_RR = mean_RR;
        /* the latest regular beats mean */
      }
    }
    /* calculate the mean of the last 8 R waves to make sure that QRS is not */
    /*  missing(If no R detected , trigger a search back) 1.66*mean */
    if (m_selected_RR != 0.0F) {
      comp = m_selected_RR;
      /* if the regular RR availabe use it */
    } else if (mean_RR != 0.0F) {
      comp = mean_RR;
    } else {
      comp = 0.0F;
    }
    if ((comp != 0.0F) && (locs_data[b_i] - qrs_i_vec_data[qrs_c_couter] >=
                           c_round(1.66F * comp))) {
      float locs_temp;
      /*          if (locs(i) - qrs_i(end)) >= round(1.66*test_m)% it shows a
       * QRS is missed */
      /*  it shows a QRS is missed */
      /*              if (locs(i) - qrs_i(end)) ~= (locs(i) -
       * qrs_i_vec(qrs_c_couter)) */
      /*                  (locs(i) - qrs_i(end)) - (locs(i) -
       * qrs_i_vec(qrs_c_couter)) */
      /*              end */
      /*              [pks_temp, locs_temp] = max(ecg_m(qrs_i(end)+
       * round(0.200*fs):locs(i)-round(0.200*fs))); % search back and locate the
       * max in this interval */
      if (qrs_i_vec_data[qrs_c_couter] + 51.0F > locs_data[b_i] - 51.0F) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (int)(qrs_i_vec_data[qrs_c_couter] + 51.0F) - 1;
        i2 = (int)(locs_data[b_i] - 51.0F);
      }
      loop_ub = i2 - i1;
      i2 = b_ecg_lpf->size[0];
      b_ecg_lpf->size[0] = loop_ub;
      emxEnsureCapacity_real32_T(b_ecg_lpf, i2);
      Rloc_data = b_ecg_lpf->data;
      for (i2 = 0; i2 < loop_ub; i2++) {
        Rloc_data[i2] = ecg_lpf_data[i1 + i2];
      }
      comp = c_maximum(b_ecg_lpf, &diffRR_counter);
      /*  search back and locate the max in this interval */
      /*              locs_temp = qrs_i(end)+ round(0.200*fs) + locs_temp -1;
       * %location */
      locs_temp =
          ((qrs_i_vec_data[qrs_c_couter] + 51.0F) + (float)diffRR_counter) -
          1.0F;
      /* location */
      if (comp > bitsra(x_i_t)) {
        /*                  qrs_c = [qrs_c pks_temp]; */
        if (qrs_c_couter + 1 > 2147483646) {
          qY = MAX_int32_T;
        } else {
          qY = qrs_c_couter + 2;
        }
        qrs_c_couter = qY - 1;
        /*                  qrs_i = [qrs_i locs_temp]; */
        /*  debug Yuxuan: */
        /*  qrs_c_couter = min(qrs_c_couter, size(qrs_i_vec,2)); */
        qrs_i_vec_data[qY - 1] = locs_temp;
        /*                  if qrs_i ~= qrs_i_vec(qrs_c_couter) */
        /*                      qrs_i */
        /*                      qrs_i_vec(qrs_c_couter) */
        /*                  end */
        /*  find the location in filtered sig */
        if ((double)locs_temp <= ecg_hpf->size[0]) {
          if (locs_temp - 38.0F > locs_temp) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = (int)(locs_temp - 38.0F) - 1;
            i2 = (int)locs_temp;
          }
          loop_ub = i2 - i1;
          i2 = b_ecg_hpf->size[0];
          b_ecg_hpf->size[0] = loop_ub;
          emxEnsureCapacity_real32_T(b_ecg_hpf, i2);
          b_ecg_hpf_data = b_ecg_hpf->data;
          for (i2 = 0; i2 < loop_ub; i2++) {
            b_ecg_hpf_data[i2] = ecg_hpf_data[i1 + i2];
          }
          comp = c_maximum(b_ecg_hpf, &diffRR_counter);
          x_i_t = (float)diffRR_counter;
        } else {
          if (locs_temp - 38.0F > ecg_hpf->size[0]) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = (int)(locs_temp - 38.0F) - 1;
            i2 = (int)(float)ecg_hpf->size[0];
          }
          loop_ub = i2 - i1;
          i2 = b_ecg_hpf->size[0];
          b_ecg_hpf->size[0] = loop_ub;
          emxEnsureCapacity_real32_T(b_ecg_hpf, i2);
          b_ecg_hpf_data = b_ecg_hpf->data;
          for (i2 = 0; i2 < loop_ub; i2++) {
            b_ecg_hpf_data[i2] = ecg_hpf_data[i1 + i2];
          }
          comp = c_maximum(b_ecg_hpf, &diffRR_counter);
          x_i_t = (float)diffRR_counter;
        }
        /*  take care of bandpass signal threshold */
        if (comp > bitsra(y)) {
          /*                      qrs_i_raw = [qrs_i_raw
           * locs_temp-round(length_maw*fs)+ (x_i_t - 1)];% save index of
           * bandpass */
          qrs_i_raw_data[qY - 1] = (locs_temp - 38.0F) + (x_i_t - 1.0F);
          /*  save index of bandpass */
          /*                      qrs_amp_raw =[qrs_amp_raw y_i_t]; %save
           * amplitude of bandpass */
          qrs_amp_raw_data[qY - 1] = comp;
          /* save amplitude of bandpass */
          /* when found with the second thres */
        }
        /* when found with the second threshold */
      }
    }
    /* find noise and QRS peaks */
    if (pks_data[b_i] >= THR_SIG) {
      boolean_T guard1;
      /*  if a QRS candidate occurs within 360ms of the previous QRS */
      /*  ,the algorithm determines if its T wave or QRS */
      /*          if length(qrs_c) >= 3 */
      guard1 = false;
      if ((qrs_c_couter + 1 >= 3) &&
          (locs_data[b_i] - qrs_i_vec_data[qrs_c_couter] <= c_round(92.16F))) {
        /*              if (locs(i)-qrs_i(end)) <= round(0.36*fs) */
        /*                 locs(i)-qrs_i(end) */
        /*              end */
        /*                  locs(i)-qrs_i_vec(qrs_c_couter) */
        if (locs_data[b_i] - 19.0F > locs_data[b_i]) {
          i1 = 0;
          i2 = 0;
        } else {
          i1 = (int)(locs_data[b_i] - 19.0F) - 1;
          i2 = (int)locs_data[b_i];
        }
        /* mean slope of the waveform at that position */
        /*                  Slope2 =
         * mean(diff(ecg_m(qrs_i(end)-round(0.075*fs):qrs_i(end)))); %mean slope
         * of previous R wave */
        if (qrs_i_vec_data[qrs_c_couter] - 19.0F >
            qrs_i_vec_data[qrs_c_couter]) {
          qrs_i_idx = 0;
          diffRR_counter = 0;
        } else {
          qrs_i_idx = (int)(qrs_i_vec_data[qrs_c_couter] - 19.0F) - 1;
          diffRR_counter = (int)qrs_i_vec_data[qrs_c_couter];
        }
        /* mean slope of previous R wave */
        /*                  if Slope2 ~= Slope2_b */
        /*                      Slope2 - Slope2_b  */
        /*                  end */
        loop_ub = i2 - i1;
        i2 = b_ecg_lpf->size[0];
        b_ecg_lpf->size[0] = loop_ub;
        emxEnsureCapacity_real32_T(b_ecg_lpf, i2);
        Rloc_data = b_ecg_lpf->data;
        for (i2 = 0; i2 < loop_ub; i2++) {
          Rloc_data[i2] = ecg_lpf_data[i1 + i2];
        }
        b_diff(b_ecg_lpf, b_ecg_hpf);
        loop_ub = diffRR_counter - qrs_i_idx;
        i1 = b_ecg_lpf->size[0];
        b_ecg_lpf->size[0] = loop_ub;
        emxEnsureCapacity_real32_T(b_ecg_lpf, i1);
        Rloc_data = b_ecg_lpf->data;
        for (i1 = 0; i1 < loop_ub; i1++) {
          Rloc_data[i1] = ecg_lpf_data[qrs_i_idx + i1];
        }
        b_diff(b_ecg_lpf, r);
        if (!(g_abs(mean(b_ecg_hpf)) <= g_abs(0.5F * mean(r)))) {
          guard1 = true;
        } else {
          /*  slope less then 0.5 of previous R */
          /*  T wave identification */
          /*  adjust noise level in both filtered and */
          /*  MVI */
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        /*  skip is 1 when a T wave is detected */
        /*              qrs_c = [qrs_c pks(i)]; */
        if (qrs_c_couter + 1 > 2147483646) {
          qY = MAX_int32_T;
        } else {
          qY = qrs_c_couter + 2;
        }
        qrs_c_couter = qY - 1;
        /*              qrs_i = [qrs_i locs(i)]; */
        /*  debug Yuxuan: */
        /*  qrs_c_couter = min(qrs_c_couter, size(qrs_i_vec,2)); */
        qrs_i_vec_data[qY - 1] = locs_data[b_i];
        /*  bandpass filter check threshold */
        if (y_i >= THR_SIG1) {
          if (ser_back != 0) {
            /*                      qrs_i_raw = [qrs_i_raw x_i];  % save index
             * of bandpass */
            qrs_i_raw_data[qY - 1] = x_i;
          } else {
            /*                      qrs_i_raw = [qrs_i_raw
             * locs(i)-round(length_maw*fs)+ (x_i - 1)];% save index of bandpass
             */
            qrs_i_raw_data[qY - 1] = (locs_data[b_i] - 38.0F) + (x_i - 1.0F);
          }
          /*                  qrs_amp_raw =[qrs_amp_raw y_i];% save amplitude of
           * bandpass */
          qrs_amp_raw_data[qY - 1] = y_i;
          /*  adjust threshold for bandpass filtered sig */
        }
        /*  adjust Signal level */
      }
    }
    /* adjust the threshold with SNR */
    /*  adjust the threshold with SNR for bandpassed signal */
    /* reset parameters */
    ser_back = 0;
    /* reset bandpass param */
  }
  emxFree_real32_T(&r);
  emxFree_real32_T(&b_ecg_lpf);
  emxFree_real32_T(&qrs_i_vec);
  emxFree_real32_T(&locs);
  emxFree_real32_T(&pks);
  emxFree_real32_T(&ecg_hpf);
  emxFree_real32_T(&ecg_lpf);
  i = qrs_i_raw->size[0] * qrs_i_raw->size[1];
  qrs_i_raw->size[0] = 1;
  emxEnsureCapacity_real32_T(qrs_i_raw, i);
  qrs_i_raw_data = qrs_i_raw->data;
  loop_ub = qrs_i_raw->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    qrs_i_raw_data[i] -= 21.0F;
  }
  /*  Removing outliers  */
  /*  Rloc = []; */
  /*  Rloc_fixedSize = NaN(200,1); */
  emxInit_boolean_T(&b_qrs_i_raw, 1);
  i = b_qrs_i_raw->size[0];
  b_qrs_i_raw->size[0] = qrs_i_raw->size[1];
  emxEnsureCapacity_boolean_T(b_qrs_i_raw, i);
  b_qrs_i_raw_data = b_qrs_i_raw->data;
  loop_ub = qrs_i_raw->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_qrs_i_raw_data[i] = (qrs_i_raw_data[i] >= 1.0F);
  }
  qrs_i_idx = e_combineVectorElements(b_qrs_i_raw);
  emxFree_boolean_T(&b_qrs_i_raw);
  i = Rloc->size[0] * Rloc->size[1];
  Rloc->size[0] = 1;
  Rloc->size[1] = qrs_i_idx;
  emxEnsureCapacity_real32_T(Rloc, i);
  Rloc_data = Rloc->data;
  for (i = 0; i < qrs_i_idx; i++) {
    Rloc_data[i] = 0.0F;
  }
  qrs_i_idx = 1;
  i = qrs_i_raw->size[1];
  for (qY = 0; qY < i; qY++) {
    comp = qrs_i_raw_data[qY];
    if (comp - 20.0F >= 1.0F) {
      if (comp - 20.0F > comp + 20.0F) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (int)(comp - 20.0F) - 1;
        i2 = (int)(comp + 20.0F);
      }
      loop_ub = i2 - i1;
      i2 = b_ecg_hpf->size[0];
      b_ecg_hpf->size[0] = loop_ub;
      emxEnsureCapacity_real32_T(b_ecg_hpf, i2);
      b_ecg_hpf_data = b_ecg_hpf->data;
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_ecg_hpf_data[i2] = sig_short_data[i1 + i2];
      }
      c_maximum(b_ecg_hpf, &diffRR_counter);
      /*          Rloc = [Rloc (ind_R_1 - num - 1 + ind)]; */
      Rloc_data[qrs_i_idx - 1] =
          ((qrs_i_raw_data[qY] - 20.0F) - 1.0F) + (float)diffRR_counter;
      if (qrs_i_idx > 2147483646) {
        qrs_i_idx = MAX_int32_T;
      } else {
        qrs_i_idx++;
      }
    }
  }
  emxFree_real32_T(&b_ecg_hpf);
  emxFree_real32_T(&qrs_i_raw);
}

/*
 * Arguments    : const emxArray_real32_T *features
 *                const float model_Prior[2]
 *                float thrshd
 *                float *score_seizure
 *                float *score_no_seizure
 * Return Type  : int
 */
static int test_classifier_s1(const emxArray_real32_T *features,
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure)
{
  emxArray_real32_T *predicted_cls_tmp;
  emxArray_real32_T *score_movsum;
  emxArray_real32_T *scores_cls_tmp;
  float cont_pos;
  float f;
  float f1;
  float *predicted_cls_tmp_data;
  float *score_movsum_data;
  int i;
  int i1;
  int i2;
  int ind;
  int output;
  boolean_T exitg1;
  emxInit_real32_T(&predicted_cls_tmp, 1);
  emxInit_real32_T(&scores_cls_tmp, 2);
  f_CompactClassificationEnsemble(model_Prior, features, predicted_cls_tmp,
                                  scores_cls_tmp);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  cont_pos = 0.0F;
  ind = 0;
  exitg1 = false;
  while ((!exitg1) && (ind <= predicted_cls_tmp->size[0] - 1)) {
    if (predicted_cls_tmp_data[ind] == 1.0F) {
      cont_pos++;
      if (cont_pos >= thrshd) {
        exitg1 = true;
      } else {
        ind++;
      }
    } else {
      cont_pos = 0.0F;
      ind++;
    }
  }
  /*  ---- compute according to the thrshd  */
  /*  scores_positive_window = [];  */
  /*  scores_negative_window = []; */
  /*  for j=1:length(predicted_cls)-thrshd+1 */
  /*      % scores that it is a seizure */
  /*      scores_positive_window = [scores_positive_window  */
  /*          sum(scores_cls(j:j+thrshd-1,2))/thrshd];  */
  /*      % scores that it is not a seizure */
  /*      scores_negative_window = [scores_negative_window  */
  /*          sum(scores_cls(j:j+thrshd-1,1))/thrshd];  */
  /*  end */
  /*  % True positive % Confidence that it is a seizure */
  /*  score_seizure = mean(scores_positive_window);  */
  /*  % False negative % Confidence that it is not a seizure */
  /*  score_no_seizure = mean(scores_negative_window);  */
  emxInit_real32_T(&score_movsum, 2);
  movsum(scores_cls_tmp, thrshd, score_movsum);
  emxFree_real32_T(&scores_cls_tmp);
  ind = score_movsum->size[0] << 1;
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  for (i = 0; i < ind; i++) {
    score_movsum_data[i] /= thrshd;
  }
  f = bitsra(thrshd);
  f1 = ((float)score_movsum->size[0] - f) + 1.0F;
  if (f + 1.0F > f1) {
    i = -1;
    i1 = -1;
  } else {
    i = (int)(f + 1.0F) - 2;
    i1 = (int)f1 - 1;
  }
  ind = i1 - i;
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < ind; i2++) {
      score_movsum_data[i2 + ind * i1] =
          score_movsum_data[((i + i2) + score_movsum->size[0] * i1) + 1];
    }
  }
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[0] = ind;
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i + score_movsum->size[0]];
  }
  *score_seizure = mean(predicted_cls_tmp);
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i];
  }
  emxFree_real32_T(&score_movsum);
  *score_no_seizure = mean(predicted_cls_tmp);
  emxFree_real32_T(&predicted_cls_tmp);
  /*  determine the result */
  /*  If there are no indexes of seizure in the segment then it is not a sizure,
   */
  /*  otherwise the predicted class for the segment is seizure */
  output = 0;
  if (cont_pos == thrshd) {
    /* the predicted class for the segment is seizure */
    output = 1;
  }
  return output;
}

/*
 * Arguments    : const emxArray_real32_T *features
 *                const boolean_T model_IsCached[15]
 *                const float model_Prior[2]
 *                float thrshd
 *                float *score_seizure
 *                float *score_no_seizure
 * Return Type  : int
 */
static int test_classifier_s2(const emxArray_real32_T *features,
                              const boolean_T model_IsCached[15],
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure)
{
  emxArray_real32_T *predicted_cls_tmp;
  emxArray_real32_T *score_movsum;
  emxArray_real32_T *scores_cls_tmp;
  float cont_pos;
  float f;
  float f1;
  float *predicted_cls_tmp_data;
  float *score_movsum_data;
  int i;
  int i1;
  int i2;
  int ind;
  int output;
  boolean_T exitg1;
  emxInit_real32_T(&predicted_cls_tmp, 1);
  emxInit_real32_T(&scores_cls_tmp, 2);
  g_CompactClassificationEnsemble(model_IsCached, model_Prior, features,
                                  predicted_cls_tmp, scores_cls_tmp);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  cont_pos = 0.0F;
  ind = 0;
  exitg1 = false;
  while ((!exitg1) && (ind <= predicted_cls_tmp->size[0] - 1)) {
    if (predicted_cls_tmp_data[ind] == 1.0F) {
      cont_pos++;
      if (cont_pos >= thrshd) {
        exitg1 = true;
      } else {
        ind++;
      }
    } else {
      cont_pos = 0.0F;
      ind++;
    }
  }
  /*  ---- compute according to the thrshd  */
  /*  scores_positive_window = [];  */
  /*  scores_negative_window = []; */
  /*  for j=1:length(predicted_cls)-thrshd+1 */
  /*      % scores that it is a seizure */
  /*      scores_positive_window = [scores_positive_window  */
  /*          sum(scores_cls(j:j+thrshd-1,2))/thrshd];  */
  /*      % scores that it is not a seizure */
  /*      scores_negative_window = [scores_negative_window  */
  /*          sum(scores_cls(j:j+thrshd-1,1))/thrshd];  */
  /*  end */
  /*  % True positive % Confidence that it is a seizure */
  /*  score_seizure = mean(scores_positive_window);  */
  /*  % False negative % Confidence that it is not a seizure */
  /*  score_no_seizure = mean(scores_negative_window);  */
  emxInit_real32_T(&score_movsum, 2);
  movsum(scores_cls_tmp, thrshd, score_movsum);
  emxFree_real32_T(&scores_cls_tmp);
  ind = score_movsum->size[0] << 1;
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  for (i = 0; i < ind; i++) {
    score_movsum_data[i] /= thrshd;
  }
  f = bitsra(thrshd);
  f1 = ((float)score_movsum->size[0] - f) + 1.0F;
  if (f + 1.0F > f1) {
    i = -1;
    i1 = -1;
  } else {
    i = (int)(f + 1.0F) - 2;
    i1 = (int)f1 - 1;
  }
  ind = i1 - i;
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < ind; i2++) {
      score_movsum_data[i2 + ind * i1] =
          score_movsum_data[((i + i2) + score_movsum->size[0] * i1) + 1];
    }
  }
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[0] = ind;
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i + score_movsum->size[0]];
  }
  *score_seizure = mean(predicted_cls_tmp);
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i];
  }
  emxFree_real32_T(&score_movsum);
  *score_no_seizure = mean(predicted_cls_tmp);
  emxFree_real32_T(&predicted_cls_tmp);
  /*  determine the result */
  /*  If there are no indexes of seizure in the segment then it is not a sizure,
   */
  /*  otherwise the predicted class for the segment is seizure */
  output = 0;
  if (cont_pos == thrshd) {
    /* the predicted class for the segment is seizure */
    output = 1;
  }
  return output;
}

/*
 * Arguments    : const emxArray_real32_T *features
 *                const boolean_T model_IsCached[15]
 *                const float model_Prior[2]
 *                float thrshd
 *                float *score_seizure
 *                float *score_no_seizure
 * Return Type  : int
 */
static int test_classifier_s3(const emxArray_real32_T *features,
                              const boolean_T model_IsCached[15],
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure)
{
  emxArray_real32_T *predicted_cls_tmp;
  emxArray_real32_T *score_movsum;
  emxArray_real32_T *scores_cls_tmp;
  float cont_pos;
  float f;
  float f1;
  float *predicted_cls_tmp_data;
  float *score_movsum_data;
  int i;
  int i1;
  int i2;
  int ind;
  int output;
  boolean_T exitg1;
  emxInit_real32_T(&predicted_cls_tmp, 1);
  emxInit_real32_T(&scores_cls_tmp, 2);
  h_CompactClassificationEnsemble(model_IsCached, model_Prior, features,
                                  predicted_cls_tmp, scores_cls_tmp);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  cont_pos = 0.0F;
  ind = 0;
  exitg1 = false;
  while ((!exitg1) && (ind <= predicted_cls_tmp->size[0] - 1)) {
    if (predicted_cls_tmp_data[ind] == 1.0F) {
      cont_pos++;
      if (cont_pos >= thrshd) {
        exitg1 = true;
      } else {
        ind++;
      }
    } else {
      cont_pos = 0.0F;
      ind++;
    }
  }
  /*  ---- compute according to the thrshd  */
  /*  scores_positive_window = [];  */
  /*  scores_negative_window = []; */
  /*  for j=1:length(predicted_cls)-thrshd+1 */
  /*      % scores that it is a seizure */
  /*      scores_positive_window = [scores_positive_window  */
  /*          sum(scores_cls(j:j+thrshd-1,2))/thrshd];  */
  /*      % scores that it is not a seizure */
  /*      scores_negative_window = [scores_negative_window  */
  /*          sum(scores_cls(j:j+thrshd-1,1))/thrshd];  */
  /*  end */
  /*  % True positive % Confidence that it is a seizure */
  /*  score_seizure = mean(scores_positive_window);  */
  /*  % False negative % Confidence that it is not a seizure */
  /*  score_no_seizure = mean(scores_negative_window);  */
  emxInit_real32_T(&score_movsum, 2);
  movsum(scores_cls_tmp, thrshd, score_movsum);
  emxFree_real32_T(&scores_cls_tmp);
  ind = score_movsum->size[0] << 1;
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  for (i = 0; i < ind; i++) {
    score_movsum_data[i] /= thrshd;
  }
  f = bitsra(thrshd);
  f1 = ((float)score_movsum->size[0] - f) + 1.0F;
  if (f + 1.0F > f1) {
    i = -1;
    i1 = -1;
  } else {
    i = (int)(f + 1.0F) - 2;
    i1 = (int)f1 - 1;
  }
  ind = i1 - i;
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < ind; i2++) {
      score_movsum_data[i2 + ind * i1] =
          score_movsum_data[((i + i2) + score_movsum->size[0] * i1) + 1];
    }
  }
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[0] = ind;
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i + score_movsum->size[0]];
  }
  *score_seizure = mean(predicted_cls_tmp);
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i];
  }
  emxFree_real32_T(&score_movsum);
  *score_no_seizure = mean(predicted_cls_tmp);
  emxFree_real32_T(&predicted_cls_tmp);
  /*  determine the result */
  /*  If there are no indexes of seizure in the segment then it is not a sizure,
   */
  /*  otherwise the predicted class for the segment is seizure */
  output = 0;
  if (cont_pos == thrshd) {
    /* the predicted class for the segment is seizure */
    output = 1;
  }
  return output;
}

/*
 * Arguments    : const emxArray_real32_T *features
 *                const boolean_T model_IsCached[15]
 *                const float model_Prior[2]
 *                float thrshd
 *                float *score_seizure
 *                float *score_no_seizure
 * Return Type  : int
 */
static int test_classifier_s4(const emxArray_real32_T *features,
                              const boolean_T model_IsCached[15],
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure)
{
  emxArray_real32_T *predicted_cls_tmp;
  emxArray_real32_T *score_movsum;
  emxArray_real32_T *scores_cls_tmp;
  float cont_pos;
  float f;
  float f1;
  float *predicted_cls_tmp_data;
  float *score_movsum_data;
  int i;
  int i1;
  int i2;
  int ind;
  int output;
  boolean_T exitg1;
  emxInit_real32_T(&predicted_cls_tmp, 1);
  emxInit_real32_T(&scores_cls_tmp, 2);
  i_CompactClassificationEnsemble(model_IsCached, model_Prior, features,
                                  predicted_cls_tmp, scores_cls_tmp);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  cont_pos = 0.0F;
  ind = 0;
  exitg1 = false;
  while ((!exitg1) && (ind <= predicted_cls_tmp->size[0] - 1)) {
    if (predicted_cls_tmp_data[ind] == 1.0F) {
      cont_pos++;
      if (cont_pos >= thrshd) {
        exitg1 = true;
      } else {
        ind++;
      }
    } else {
      cont_pos = 0.0F;
      ind++;
    }
  }
  /*  ---- compute according to the thrshd  */
  /*  scores_positive_window = [];  */
  /*  scores_negative_window = []; */
  /*  for j=1:length(predicted_cls)-thrshd+1 */
  /*      % scores that it is a seizure */
  /*      scores_positive_window = [scores_positive_window  */
  /*          sum(scores_cls(j:j+thrshd-1,2))/thrshd];  */
  /*      % scores that it is not a seizure */
  /*      scores_negative_window = [scores_negative_window  */
  /*          sum(scores_cls(j:j+thrshd-1,1))/thrshd];  */
  /*  end */
  /*  % True positive % Confidence that it is a seizure */
  /*  score_seizure = mean(scores_positive_window);  */
  /*  % False negative % Confidence that it is not a seizure */
  /*  score_no_seizure = mean(scores_negative_window);  */
  emxInit_real32_T(&score_movsum, 2);
  movsum(scores_cls_tmp, thrshd, score_movsum);
  emxFree_real32_T(&scores_cls_tmp);
  ind = score_movsum->size[0] << 1;
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  for (i = 0; i < ind; i++) {
    score_movsum_data[i] /= thrshd;
  }
  f = bitsra(thrshd);
  f1 = ((float)score_movsum->size[0] - f) + 1.0F;
  if (f + 1.0F > f1) {
    i = -1;
    i1 = -1;
  } else {
    i = (int)(f + 1.0F) - 2;
    i1 = (int)f1 - 1;
  }
  ind = i1 - i;
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < ind; i2++) {
      score_movsum_data[i2 + ind * i1] =
          score_movsum_data[((i + i2) + score_movsum->size[0] * i1) + 1];
    }
  }
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[0] = ind;
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i + score_movsum->size[0]];
  }
  *score_seizure = mean(predicted_cls_tmp);
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i];
  }
  emxFree_real32_T(&score_movsum);
  *score_no_seizure = mean(predicted_cls_tmp);
  emxFree_real32_T(&predicted_cls_tmp);
  /*  determine the result */
  /*  If there are no indexes of seizure in the segment then it is not a sizure,
   */
  /*  otherwise the predicted class for the segment is seizure */
  output = 0;
  if (cont_pos == thrshd) {
    /* the predicted class for the segment is seizure */
    output = 1;
  }
  return output;
}

/*
 * Arguments    : const emxArray_real32_T *features
 *                const float model_Prior[2]
 *                float thrshd
 *                float *score_seizure
 *                float *score_no_seizure
 * Return Type  : int
 */
static int test_classifier_s5(const emxArray_real32_T *features,
                              const float model_Prior[2], float thrshd,
                              float *score_seizure, float *score_no_seizure)
{
  emxArray_real32_T *predicted_cls_tmp;
  emxArray_real32_T *score_movsum;
  emxArray_real32_T *scores_cls_tmp;
  float cont_pos;
  float f;
  float f1;
  float *predicted_cls_tmp_data;
  float *score_movsum_data;
  int i;
  int i1;
  int i2;
  int ind;
  int output;
  boolean_T exitg1;
  emxInit_real32_T(&predicted_cls_tmp, 1);
  emxInit_real32_T(&scores_cls_tmp, 2);
  j_CompactClassificationEnsemble(model_Prior, features, predicted_cls_tmp,
                                  scores_cls_tmp);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  cont_pos = 0.0F;
  ind = 0;
  exitg1 = false;
  while ((!exitg1) && (ind <= predicted_cls_tmp->size[0] - 1)) {
    if (predicted_cls_tmp_data[ind] == 1.0F) {
      cont_pos++;
      if (cont_pos >= thrshd) {
        exitg1 = true;
      } else {
        ind++;
      }
    } else {
      cont_pos = 0.0F;
      ind++;
    }
  }
  /*  ---- compute according to the thrshd  */
  /*  scores_positive_window = [];  */
  /*  scores_negative_window = []; */
  /*  for j=1:length(predicted_cls)-thrshd+1 */
  /*      % scores that it is a seizure */
  /*      scores_positive_window = [scores_positive_window  */
  /*          sum(scores_cls(j:j+thrshd-1,2))/thrshd];  */
  /*      % scores that it is not a seizure */
  /*      scores_negative_window = [scores_negative_window  */
  /*          sum(scores_cls(j:j+thrshd-1,1))/thrshd];  */
  /*  end */
  /*  % True positive % Confidence that it is a seizure */
  /*  score_seizure = mean(scores_positive_window);  */
  /*  % False negative % Confidence that it is not a seizure */
  /*  score_no_seizure = mean(scores_negative_window);  */
  emxInit_real32_T(&score_movsum, 2);
  movsum(scores_cls_tmp, thrshd, score_movsum);
  emxFree_real32_T(&scores_cls_tmp);
  ind = score_movsum->size[0] << 1;
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  for (i = 0; i < ind; i++) {
    score_movsum_data[i] /= thrshd;
  }
  f = bitsra(thrshd);
  f1 = ((float)score_movsum->size[0] - f) + 1.0F;
  if (f + 1.0F > f1) {
    i = -1;
    i1 = -1;
  } else {
    i = (int)(f + 1.0F) - 2;
    i1 = (int)f1 - 1;
  }
  ind = i1 - i;
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < ind; i2++) {
      score_movsum_data[i2 + ind * i1] =
          score_movsum_data[((i + i2) + score_movsum->size[0] * i1) + 1];
    }
  }
  i = score_movsum->size[0] * score_movsum->size[1];
  score_movsum->size[0] = ind;
  score_movsum->size[1] = 2;
  emxEnsureCapacity_real32_T(score_movsum, i);
  score_movsum_data = score_movsum->data;
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i + score_movsum->size[0]];
  }
  *score_seizure = mean(predicted_cls_tmp);
  i = predicted_cls_tmp->size[0];
  predicted_cls_tmp->size[0] = ind;
  emxEnsureCapacity_real32_T(predicted_cls_tmp, i);
  predicted_cls_tmp_data = predicted_cls_tmp->data;
  for (i = 0; i < ind; i++) {
    predicted_cls_tmp_data[i] = score_movsum_data[i];
  }
  emxFree_real32_T(&score_movsum);
  *score_no_seizure = mean(predicted_cls_tmp);
  emxFree_real32_T(&predicted_cls_tmp);
  /*  determine the result */
  /*  If there are no indexes of seizure in the segment then it is not a sizure,
   */
  /*  otherwise the predicted class for the segment is seizure */
  output = 0;
  if (cont_pos == thrshd) {
    /* the predicted class for the segment is seizure */
    output = 1;
  }
  return output;
}

/*
 * Arguments    : const emxArray_real32_T *ECG_sig
 *                const emxArray_real32_T *Spo2_sig
 *                float conf_th
 *                float thrshd
 *                const signed char masks[85]
 *                float *final_result
 *                float *ind
 *                float *runtime
 *                float *saveup_time
 *                float mask_runtime[5]
 * Return Type  : void
 */
void INCLASS_iterative_test_single(const emxArray_real32_T *ECG_sig,
                                   const emxArray_real32_T *Spo2_sig,
                                   float conf_th, float thrshd,
                                   const signed char masks[85],
                                   float *final_result, float *ind)
{
  emxArray_real32_T *b_extract_feature_tmp;
  emxArray_real32_T *c_extract_feature_tmp;
  emxArray_real32_T *d_extract_feature_tmp;
  emxArray_real32_T *e_extract_feature_tmp;
  emxArray_real32_T *extract_feature_tmp;
  emxArray_real32_T *f_extract_feature_tmp;
  emxArray_real32_T *r;
  emxArray_real32_T *r1;
  emxArray_real32_T *r2;
  emxArray_real32_T *r3;
  emxArray_real32_T *r4;
  fc_classreg_learning_classif_Co e_expl_temp;
  fc_classreg_learning_classif_Co expl_temp;
  gc_classreg_learning_classif_Co b_expl_temp;
  gc_classreg_learning_classif_Co c_expl_temp;
  gc_classreg_learning_classif_Co d_expl_temp;
  double dv[6];
  float c[6];
  float pred_mask[5];
  float conf_gray;
  float conf_seiz;
  float iterative_start_time;
  float *b_extract_feature_tmp_data;
  float *extract_feature_tmp_data;
  float *r5;
  int b_ind;
  int i;
  boolean_T exitg1;
  boolean_T first_time;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /*                                                                           %
   */
  /*           Generated by MATLAB 23.2 and Fixed-Point Designer 23.2          %
   */
  /*                                                                           %
   */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  c_CompactClassificationEnsemble(&expl_temp);
  d_CompactClassificationEnsemble(&b_expl_temp);
  d_CompactClassificationEnsemble(&c_expl_temp);
  d_CompactClassificationEnsemble(&d_expl_temp);
  e_CompactClassificationEnsemble(&e_expl_temp);
  *final_result = rtNaNF;
  for (i = 0; i < 5; i++) {
    pred_mask[i] = rtNaNF;
  }
  /*  start_time_update = []; */
  /*  end_time_update = []; */
  first_time = true;

  for (i = 0; i < 6; i++) {
    c[i] = (float)dv[i];
  }
  iterative_start_time = c[4] * 60.0F + c[5];
  *ind = 1.0F;
  b_ind = 0;
  emxInit_real32_T(&extract_feature_tmp, 2);
  emxInit_real32_T(&r, 2);
  emxInit_real32_T(&r1, 2);
  emxInit_real32_T(&r2, 2);
  emxInit_real32_T(&r3, 2);
  emxInit_real32_T(&r4, 2);
  emxInit_real32_T(&b_extract_feature_tmp, 2);
  emxInit_real32_T(&c_extract_feature_tmp, 2);
  emxInit_real32_T(&d_extract_feature_tmp, 2);
  emxInit_real32_T(&e_extract_feature_tmp, 2);
  emxInit_real32_T(&f_extract_feature_tmp, 2);
  exitg1 = false;
  while ((!exitg1) && (b_ind < 5)) {
    float mask_start_time;
    signed char b_masks[17];
    *ind = (float)b_ind + 1.0F;
    for (i = 0; i < 6; i++) {
      c[i] = (float)dv[i];
    }
    mask_start_time = c[4] * 60.0F + c[5];
    for (i = 0; i < 17; i++) {
      b_masks[i] = masks[b_ind + 5 * i];
    }
    if (sum(b_masks) == 0.0) {
      b_ind++;
    } else {
      float savetime_one_tmp;
      int predict_res;
      /*  ------------------ compute mask ------------------ */
      /*  mask = masks(ind,:); */
      /*  n_features = sum(mask); */
      for (i = 0; i < 17; i++) {
        b_masks[i] = masks[b_ind + 5 * i];
      }
      savetime_one_tmp = my_Extract_features_Jep_orig(
          ECG_sig, Spo2_sig, b_masks, extract_feature_tmp);
      extract_feature_tmp_data = extract_feature_tmp->data;
      /*  [extract_feature, savetime_one] = ... */
      /*          my_Extract_features_Jep_orig_single_mex(ECG_sig, ... */
      /*              Spo2_sig, single(Nbr_RR), ... */
      /*              int8(mask), first_time, Fs);   */
      first_time = !first_time;

      /*  ----------- test with training models ------------ */
      switch (b_ind + 1) {
      case 1:
        repmat(extract_feature_tmp->size[0], r1);
        r5 = r1->data;
        if ((extract_feature_tmp->size[0] == r1->size[0]) &&
            (extract_feature_tmp->size[1] == 4)) {
          i = c_extract_feature_tmp->size[0] * c_extract_feature_tmp->size[1];
          c_extract_feature_tmp->size[0] = extract_feature_tmp->size[0];
          c_extract_feature_tmp->size[1] = 4;
          emxEnsureCapacity_real32_T(c_extract_feature_tmp, i);
          b_extract_feature_tmp_data = c_extract_feature_tmp->data;
          predict_res = extract_feature_tmp->size[0] * 4;
          for (i = 0; i < predict_res; i++) {
            b_extract_feature_tmp_data[i] = extract_feature_tmp_data[i] / r5[i];
          }
          predict_res =
              test_classifier_s1(c_extract_feature_tmp, expl_temp.Prior, thrshd,
                                 &conf_seiz, &conf_gray);
        } else {
          predict_res = binary_expand_op_3(extract_feature_tmp, r1, &expl_temp,
                                           thrshd, &conf_seiz, &conf_gray);
        }
        break;
      case 2:
        f_repmat(extract_feature_tmp->size[0], r2);
        r5 = r2->data;
        if ((extract_feature_tmp->size[0] == r2->size[0]) &&
            (extract_feature_tmp->size[1] == 11)) {
          i = d_extract_feature_tmp->size[0] * d_extract_feature_tmp->size[1];
          d_extract_feature_tmp->size[0] = extract_feature_tmp->size[0];
          d_extract_feature_tmp->size[1] = 11;
          emxEnsureCapacity_real32_T(d_extract_feature_tmp, i);
          b_extract_feature_tmp_data = d_extract_feature_tmp->data;
          predict_res = extract_feature_tmp->size[0] * 11;
          for (i = 0; i < predict_res; i++) {
            b_extract_feature_tmp_data[i] = extract_feature_tmp_data[i] / r5[i];
          }
          predict_res = test_classifier_s2(
              d_extract_feature_tmp, b_expl_temp.IsCached, b_expl_temp.Prior,
              thrshd, &conf_seiz, &conf_gray);
        } else {
          predict_res =
              binary_expand_op_2(extract_feature_tmp, r2, &b_expl_temp, thrshd,
                                 &conf_seiz, &conf_gray);
        }
        break;
      case 3:
        g_repmat(extract_feature_tmp->size[0], r3);
        r5 = r3->data;
        if ((extract_feature_tmp->size[0] == r3->size[0]) &&
            (extract_feature_tmp->size[1] == 12)) {
          i = e_extract_feature_tmp->size[0] * e_extract_feature_tmp->size[1];
          e_extract_feature_tmp->size[0] = extract_feature_tmp->size[0];
          e_extract_feature_tmp->size[1] = 12;
          emxEnsureCapacity_real32_T(e_extract_feature_tmp, i);
          b_extract_feature_tmp_data = e_extract_feature_tmp->data;
          predict_res = extract_feature_tmp->size[0] * 12;
          for (i = 0; i < predict_res; i++) {
            b_extract_feature_tmp_data[i] = extract_feature_tmp_data[i] / r5[i];
          }
          predict_res = test_classifier_s3(
              e_extract_feature_tmp, c_expl_temp.IsCached, c_expl_temp.Prior,
              thrshd, &conf_seiz, &conf_gray);
        } else {
          predict_res =
              binary_expand_op_1(extract_feature_tmp, r3, &c_expl_temp, thrshd,
                                 &conf_seiz, &conf_gray);
        }
        /*  fid = fopen('extract_feature.txt', 'w'); */
        /*  for i = 1:size(extract_feature,1) */
        /*      for j = 1:size(extract_feature,2) */
        /*          fprintf(fid, '%.16f', extract_feature(i,j)); */
        /*          if j < size(extract_feature,2) */
        /*              fprintf(fid, '\t'); % Tab delimiter */
        /*          else */
        /*              fprintf(fid, '\n'); % New line for the end of the row */
        /*          end */
        /*      end */
        /*  end */
        /*  fclose(fid); */
        break;
      case 4:
        h_repmat(extract_feature_tmp->size[0], r4);
        r5 = r4->data;
        if ((extract_feature_tmp->size[0] == r4->size[0]) &&
            (extract_feature_tmp->size[1] == 13)) {
          i = f_extract_feature_tmp->size[0] * f_extract_feature_tmp->size[1];
          f_extract_feature_tmp->size[0] = extract_feature_tmp->size[0];
          f_extract_feature_tmp->size[1] = 13;
          emxEnsureCapacity_real32_T(f_extract_feature_tmp, i);
          b_extract_feature_tmp_data = f_extract_feature_tmp->data;
          predict_res = extract_feature_tmp->size[0] * 13;
          for (i = 0; i < predict_res; i++) {
            b_extract_feature_tmp_data[i] = extract_feature_tmp_data[i] / r5[i];
          }
          predict_res = test_classifier_s4(
              f_extract_feature_tmp, d_expl_temp.IsCached, d_expl_temp.Prior,
              thrshd, &conf_seiz, &conf_gray);
        } else {
          predict_res = binary_expand_op(extract_feature_tmp, r4, &d_expl_temp,
                                         thrshd, &conf_seiz, &conf_gray);
        }
        break;
      default:
        i_repmat(extract_feature_tmp->size[0], r);
        r5 = r->data;
        if ((extract_feature_tmp->size[0] == r->size[0]) &&
            (extract_feature_tmp->size[1] == 17)) {
          i = b_extract_feature_tmp->size[0] * b_extract_feature_tmp->size[1];
          b_extract_feature_tmp->size[0] = extract_feature_tmp->size[0];
          b_extract_feature_tmp->size[1] = 17;
          emxEnsureCapacity_real32_T(b_extract_feature_tmp, i);
          b_extract_feature_tmp_data = b_extract_feature_tmp->data;
          predict_res = extract_feature_tmp->size[0] * 17;
          for (i = 0; i < predict_res; i++) {
            b_extract_feature_tmp_data[i] = extract_feature_tmp_data[i] / r5[i];
          }
          predict_res =
              test_classifier_s5(b_extract_feature_tmp, e_expl_temp.Prior,
                                 thrshd, &conf_seiz, &conf_gray);
        } else {
          predict_res = binary_expand_op_4(extract_feature_tmp, r, &e_expl_temp,
                                           thrshd, &conf_seiz, &conf_gray);
        }
        break;
      }
      /*  Open file for writing */
      for (i = 0; i < 6; i++) {
        c[i] = (float)dv[i];
      }

      first_time = false;
      *final_result = (float)predict_res;
      pred_mask[b_ind] = (float)predict_res;
      /*  if the test result matches the threshold, clear cache and break */
      if (((predict_res == 1) && (conf_seiz >= conf_th)) ||
          ((predict_res == 0) && (conf_gray >= conf_th))) {
        exitg1 = true;
      } else {
        if (b_ind + 1 == 5) {
          *final_result = pred_mask[4];
        }
        b_ind++;
      }
    }
  }
  emxFree_real32_T(&f_extract_feature_tmp);
  emxFree_real32_T(&e_extract_feature_tmp);
  emxFree_real32_T(&d_extract_feature_tmp);
  emxFree_real32_T(&c_extract_feature_tmp);
  emxFree_real32_T(&b_extract_feature_tmp);
  emxFree_real32_T(&r4);
  emxFree_real32_T(&r3);
  emxFree_real32_T(&r2);
  emxFree_real32_T(&r1);
  emxFree_real32_T(&r);
  emxFree_real32_T(&extract_feature_tmp);
  for (i = 0; i < 6; i++) {
    c[i] = (float)dv[i];
  }
  /*  fprintf("total runtime: %f\n", iterative_end_time - iterative_start_time)
   */
  /*  fprintf("saveup runtime: %f\n", saveup_time) */
}

/*
 * File trailer for INCLASS_iterative_test_single.c
 *
 * [EOF]
 */
