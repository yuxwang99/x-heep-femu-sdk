/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_profile_Yuxuan_iteration_api.c
 *
 * Code generation for function 'profile_Yuxuan_iteration'
 *
 */

/* Include files */
#include "_coder_profile_Yuxuan_iteration_api.h"
#include "_coder_profile_Yuxuan_iteration_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131595U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "profile_Yuxuan_iteration",          /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static boolean_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[90];
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2764800];
static real_T (*bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2764800];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef1, const char_T *identifier))[2];
static real_T (*cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static real_T (*db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef2, const char_T *identifier))[3];
static real_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *ECG_Seiz_Window, const char_T *identifier))[2764800];
static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T (*fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[13];
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef3, const char_T *identifier))[5];
static real_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[17];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[5];
static real_T hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef4, const char_T *identifier))[13];
static real_T (*ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[85];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[13];
static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[41]);
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef5, const char_T *identifier))[17];
static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[42]);
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[17];
static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[43]);
static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *wind_len,
  const char_T *identifier);
static boolean_T (*mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[90];
static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *masks,
  const char_T *identifier))[85];
static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[85];
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *File_info,
  const char_T *identifier, cell_0 *y);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_0 *y);
static rtString s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[41]);
static b_rtString u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[42]);
static c_rtString w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[43]);
static boolean_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *select_ind, const char_T *identifier))[90];

/* Function Definitions */
static boolean_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[90]
{
  boolean_T (*y)[90];
  y = mb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2764800]
{
  real_T (*y)[2764800];
  y = bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2764800]
{
  static const int32_T dims[2] = { 30720, 90 };

  real_T (*ret)[2764800];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[2764800])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef1, const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(norm_coef1), &thisId);
  emlrtDestroyArray(&norm_coef1);
  return y;
}

static real_T (*cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2] = { 1, 2 };

  real_T (*ret)[2];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2]
{
  real_T (*y)[2];
  y = cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims[2] = { 1, 3 };

  real_T (*ret)[3];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef2, const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(norm_coef2), &thisId);
  emlrtDestroyArray(&norm_coef2);
  return y;
}

static real_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5]
{
  static const int32_T dims[2] = { 1, 5 };

  real_T (*ret)[5];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[5])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *ECG_Seiz_Window, const char_T *identifier))[2764800]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[2764800];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(ECG_Seiz_Window), &thisId);
  emlrtDestroyArray(&ECG_Seiz_Window);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  static const int32_T iv[2] = { 0, 0 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, u_size, 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = db_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[13]
{
  static const int32_T dims[2] = { 1, 13 };

  real_T (*ret)[13];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[13])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef3, const char_T *identifier))[5]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[5];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(norm_coef3), &thisId);
  emlrtDestroyArray(&norm_coef3);
  return y;
}
  static real_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[17]
{
  static const int32_T dims[2] = { 1, 17 };

  real_T (*ret)[17];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[17])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[5]
{
  real_T (*y)[5];
  y = eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef4, const char_T *identifier))[13]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[13];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(norm_coef4), &thisId);
  emlrtDestroyArray(&norm_coef4);
  return y;
}
  static real_T (*ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[85]
{
  static const int32_T dims[2] = { 5, 17 };

  real_T (*ret)[85];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[85])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[13]
{
  real_T (*y)[13];
  y = fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, char_T ret[41])
{
  static const int32_T dims[2] = { 1, 41 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 41);
  emlrtDestroyArray(&src);
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *norm_coef5, const char_T *identifier))[17]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[17];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(norm_coef5), &thisId);
  emlrtDestroyArray(&norm_coef5);
  return y;
}
  static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, char_T ret[42])
{
  static const int32_T dims[2] = { 1, 42 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 42);
  emlrtDestroyArray(&src);
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[17]
{
  real_T (*y)[17];
  y = gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, char_T ret[43])
{
  static const int32_T dims[2] = { 1, 43 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 43);
  emlrtDestroyArray(&src);
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *wind_len,
  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = n_emlrt_marshallIn(sp, emlrtAlias(wind_len), &thisId);
  emlrtDestroyArray(&wind_len);
  return y;
}

static boolean_T (*mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[90]
{
  static const int32_T dims[1] = { 90 };

  boolean_T (*ret)[90];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 1U, dims);
  ret = (boolean_T (*)[90])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *masks,
  const char_T *identifier))[85]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[85];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = p_emlrt_marshallIn(sp, emlrtAlias(masks), &thisId);
  emlrtDestroyArray(&masks);
  return y;
}
  static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[85]
{
  real_T (*y)[85];
  y = ib_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *File_info,
  const char_T *identifier, cell_0 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  r_emlrt_marshallIn(sp, emlrtAlias(File_info), &thisId, y);
  emlrtDestroyArray(&File_info);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_0 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 90;
  bv[1] = false;
  emlrtCheckCell(sp, parentId, u, 2U, iv, bv);
  thisId.fIdentifier = "1";
  y->f1 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)),
    &thisId);
  thisId.fIdentifier = "2";
  y->f2 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 1)),
    &thisId);
  thisId.fIdentifier = "3";
  y->f3 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 2)),
    &thisId);
  thisId.fIdentifier = "4";
  y->f4 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 3)),
    &thisId);
  thisId.fIdentifier = "5";
  y->f5 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 4)),
    &thisId);
  thisId.fIdentifier = "6";
  y->f6 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 5)),
    &thisId);
  thisId.fIdentifier = "7";
  y->f7 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 6)),
    &thisId);
  thisId.fIdentifier = "8";
  y->f8 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 7)),
    &thisId);
  thisId.fIdentifier = "9";
  y->f9 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 8)),
    &thisId);
  thisId.fIdentifier = "10";
  y->f10 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 9)),
    &thisId);
  thisId.fIdentifier = "11";
  y->f11 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 10)),
    &thisId);
  thisId.fIdentifier = "12";
  y->f12 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 11)),
    &thisId);
  thisId.fIdentifier = "13";
  y->f13 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 12)),
    &thisId);
  thisId.fIdentifier = "14";
  y->f14 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 13)),
    &thisId);
  thisId.fIdentifier = "15";
  y->f15 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 14)),
    &thisId);
  thisId.fIdentifier = "16";
  y->f16 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 15)),
    &thisId);
  thisId.fIdentifier = "17";
  y->f17 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 16)),
    &thisId);
  thisId.fIdentifier = "18";
  y->f18 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 17)),
    &thisId);
  thisId.fIdentifier = "19";
  y->f19 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 18)),
    &thisId);
  thisId.fIdentifier = "20";
  y->f20 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 19)),
    &thisId);
  thisId.fIdentifier = "21";
  y->f21 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 20)),
    &thisId);
  thisId.fIdentifier = "22";
  y->f22 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 21)),
    &thisId);
  thisId.fIdentifier = "23";
  y->f23 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 22)),
    &thisId);
  thisId.fIdentifier = "24";
  y->f24 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 23)),
    &thisId);
  thisId.fIdentifier = "25";
  y->f25 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 24)),
    &thisId);
  thisId.fIdentifier = "26";
  y->f26 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 25)),
    &thisId);
  thisId.fIdentifier = "27";
  y->f27 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 26)),
    &thisId);
  thisId.fIdentifier = "28";
  y->f28 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 27)),
    &thisId);
  thisId.fIdentifier = "29";
  y->f29 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 28)),
    &thisId);
  thisId.fIdentifier = "30";
  y->f30 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 29)),
    &thisId);
  thisId.fIdentifier = "31";
  y->f31 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 30)),
    &thisId);
  thisId.fIdentifier = "32";
  y->f32 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 31)),
    &thisId);
  thisId.fIdentifier = "33";
  y->f33 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 32)),
    &thisId);
  thisId.fIdentifier = "34";
  y->f34 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 33)),
    &thisId);
  thisId.fIdentifier = "35";
  y->f35 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 34)),
    &thisId);
  thisId.fIdentifier = "36";
  y->f36 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 35)),
    &thisId);
  thisId.fIdentifier = "37";
  y->f37 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 36)),
    &thisId);
  thisId.fIdentifier = "38";
  y->f38 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 37)),
    &thisId);
  thisId.fIdentifier = "39";
  y->f39 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 38)),
    &thisId);
  thisId.fIdentifier = "40";
  y->f40 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 39)),
    &thisId);
  thisId.fIdentifier = "41";
  y->f41 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 40)),
    &thisId);
  thisId.fIdentifier = "42";
  y->f42 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 41)),
    &thisId);
  thisId.fIdentifier = "43";
  y->f43 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 42)),
    &thisId);
  thisId.fIdentifier = "44";
  y->f44 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 43)),
    &thisId);
  thisId.fIdentifier = "45";
  y->f45 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 44)),
    &thisId);
  thisId.fIdentifier = "46";
  y->f46 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 45)),
    &thisId);
  thisId.fIdentifier = "47";
  y->f47 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 46)),
    &thisId);
  thisId.fIdentifier = "48";
  y->f48 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 47)),
    &thisId);
  thisId.fIdentifier = "49";
  y->f49 = w_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 48)),
    &thisId);
  thisId.fIdentifier = "50";
  y->f50 = w_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 49)),
    &thisId);
  thisId.fIdentifier = "51";
  y->f51 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 50)),
    &thisId);
  thisId.fIdentifier = "52";
  y->f52 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 51)),
    &thisId);
  thisId.fIdentifier = "53";
  y->f53 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 52)),
    &thisId);
  thisId.fIdentifier = "54";
  y->f54 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 53)),
    &thisId);
  thisId.fIdentifier = "55";
  y->f55 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 54)),
    &thisId);
  thisId.fIdentifier = "56";
  y->f56 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 55)),
    &thisId);
  thisId.fIdentifier = "57";
  y->f57 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 56)),
    &thisId);
  thisId.fIdentifier = "58";
  y->f58 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 57)),
    &thisId);
  thisId.fIdentifier = "59";
  y->f59 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 58)),
    &thisId);
  thisId.fIdentifier = "60";
  y->f60 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 59)),
    &thisId);
  thisId.fIdentifier = "61";
  y->f61 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 60)),
    &thisId);
  thisId.fIdentifier = "62";
  y->f62 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 61)),
    &thisId);
  thisId.fIdentifier = "63";
  y->f63 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 62)),
    &thisId);
  thisId.fIdentifier = "64";
  y->f64 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 63)),
    &thisId);
  thisId.fIdentifier = "65";
  y->f65 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 64)),
    &thisId);
  thisId.fIdentifier = "66";
  y->f66 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 65)),
    &thisId);
  thisId.fIdentifier = "67";
  y->f67 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 66)),
    &thisId);
  thisId.fIdentifier = "68";
  y->f68 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 67)),
    &thisId);
  thisId.fIdentifier = "69";
  y->f69 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 68)),
    &thisId);
  thisId.fIdentifier = "70";
  y->f70 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 69)),
    &thisId);
  thisId.fIdentifier = "71";
  y->f71 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 70)),
    &thisId);
  thisId.fIdentifier = "72";
  y->f72 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 71)),
    &thisId);
  thisId.fIdentifier = "73";
  y->f73 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 72)),
    &thisId);
  thisId.fIdentifier = "74";
  y->f74 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 73)),
    &thisId);
  thisId.fIdentifier = "75";
  y->f75 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 74)),
    &thisId);
  thisId.fIdentifier = "76";
  y->f76 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 75)),
    &thisId);
  thisId.fIdentifier = "77";
  y->f77 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 76)),
    &thisId);
  thisId.fIdentifier = "78";
  y->f78 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 77)),
    &thisId);
  thisId.fIdentifier = "79";
  y->f79 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 78)),
    &thisId);
  thisId.fIdentifier = "80";
  y->f80 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 79)),
    &thisId);
  thisId.fIdentifier = "81";
  y->f81 = u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 80)),
    &thisId);
  thisId.fIdentifier = "82";
  y->f82 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 81)),
    &thisId);
  thisId.fIdentifier = "83";
  y->f83 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 82)),
    &thisId);
  thisId.fIdentifier = "84";
  y->f84 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 83)),
    &thisId);
  thisId.fIdentifier = "85";
  y->f85 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 84)),
    &thisId);
  thisId.fIdentifier = "86";
  y->f86 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 85)),
    &thisId);
  thisId.fIdentifier = "87";
  y->f87 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 86)),
    &thisId);
  thisId.fIdentifier = "88";
  y->f88 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 87)),
    &thisId);
  thisId.fIdentifier = "89";
  y->f89 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 88)),
    &thisId);
  thisId.fIdentifier = "90";
  y->f90 = s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 89)),
    &thisId);
  emlrtDestroyArray(&u);
}

static rtString s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[1];
  rtString y;
  const char_T *propClasses[1] = { "coder.internal.string" };

  const char_T *propNames[1] = { "Value" };

  propValues[0] = NULL;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(sp, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(sp, u, 0,
    "coder.internal.string"));
  emlrtCheckMcosClass2017a(sp, parentId, u, "coder.internal.string");
  emlrtGetAllProperties(sp, u, 0, 1, propNames, propClasses, propValues);
  thisId.fIdentifier = "Value";
  t_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y.Value);
  emlrtDestroyArrays(1, (const mxArray **)&propValues);
  emlrtDestroyArray(&u);
  return y;
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[41])
{
  jb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static b_rtString u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  b_rtString y;
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[1];
  const char_T *propClasses[1] = { "coder.internal.string" };

  const char_T *propNames[1] = { "Value" };

  propValues[0] = NULL;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(sp, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(sp, u, 0,
    "coder.internal.string"));
  emlrtCheckMcosClass2017a(sp, parentId, u, "coder.internal.string");
  emlrtGetAllProperties(sp, u, 0, 1, propNames, propClasses, propValues);
  thisId.fIdentifier = "Value";
  v_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y.Value);
  emlrtDestroyArrays(1, (const mxArray **)&propValues);
  emlrtDestroyArray(&u);
  return y;
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[42])
{
  kb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static c_rtString w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  c_rtString y;
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[1];
  const char_T *propClasses[1] = { "coder.internal.string" };

  const char_T *propNames[1] = { "Value" };

  propValues[0] = NULL;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(sp, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(sp, u, 0,
    "coder.internal.string"));
  emlrtCheckMcosClass2017a(sp, parentId, u, "coder.internal.string");
  emlrtGetAllProperties(sp, u, 0, 1, propNames, propClasses, propValues);
  thisId.fIdentifier = "Value";
  x_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y.Value);
  emlrtDestroyArrays(1, (const mxArray **)&propValues);
  emlrtDestroyArray(&u);
  return y;
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[43])
{
  lb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *select_ind, const char_T *identifier))[90]
{
  emlrtMsgIdentifier thisId;
  boolean_T (*y)[90];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = ab_emlrt_marshallIn(sp, emlrtAlias(select_ind), &thisId);
  emlrtDestroyArray(&select_ind);
  return y;
}
  void profile_Yuxuan_iteration_api(const mxArray * const prhs[17], int32_T nlhs,
  const mxArray *plhs[2])
{
  cell_0 File_info;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T (*ECG_Gray_Window)[2764800];
  real_T (*ECG_Seiz_Window)[2764800];
  real_T (*Spo2_Gray_Window)[2764800];
  real_T (*Spo2_Seiz_Window)[2764800];
  real_T (*pred_label_data)[900];
  real_T (*true_label_data)[180];
  real_T (*masks)[85];
  real_T (*norm_coef5)[17];
  real_T (*norm_coef4)[13];
  real_T (*norm_coef3)[5];
  real_T (*norm_coef2)[3];
  real_T (*norm_coef1)[2];
  real_T Fs;
  real_T Nbr_RR;
  real_T conf_seiz;
  real_T profile_times;
  real_T wind_len;
  int32_T pred_label_size[2];
  int32_T true_label_size[2];
  boolean_T (*select_ind)[90];
  st.tls = emlrtRootTLSGlobal;
  pred_label_data = (real_T (*)[900])mxMalloc(sizeof(real_T [900]));
  true_label_data = (real_T (*)[180])mxMalloc(sizeof(real_T [180]));

  /* Marshall function inputs */
  ECG_Seiz_Window = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "ECG_Seiz_Window");
  Spo2_Seiz_Window = emlrt_marshallIn(&st, emlrtAlias(prhs[1]),
    "Spo2_Seiz_Window");
  ECG_Gray_Window = emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "ECG_Gray_Window");
  Spo2_Gray_Window = emlrt_marshallIn(&st, emlrtAlias(prhs[3]),
    "Spo2_Gray_Window");
  norm_coef1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "norm_coef1");
  norm_coef2 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "norm_coef2");
  norm_coef3 = g_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "norm_coef3");
  norm_coef4 = i_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "norm_coef4");
  norm_coef5 = k_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "norm_coef5");
  wind_len = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "wind_len");
  masks = o_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "masks");
  profile_times = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "profile_times");
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "File_info", &File_info);
  Fs = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "Fs");
  Nbr_RR = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "Nbr_RR");
  conf_seiz = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "conf_seiz");
  select_ind = y_emlrt_marshallIn(&st, emlrtAlias(prhs[16]), "select_ind");

  /* Invoke the target function */
  profile_Yuxuan_iteration(*ECG_Seiz_Window, *Spo2_Seiz_Window, *ECG_Gray_Window,
    *Spo2_Gray_Window, *norm_coef1, *norm_coef2, *norm_coef3, *norm_coef4,
    *norm_coef5, wind_len, *masks, profile_times, &File_info, Fs, Nbr_RR,
    conf_seiz, *select_ind, *pred_label_data, pred_label_size, *true_label_data,
    true_label_size);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*pred_label_data, pred_label_size);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*true_label_data, true_label_size);
  }
}

void profile_Yuxuan_iteration_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  profile_Yuxuan_iteration_xil_terminate();
  profile_Yuxuan_iteration_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void profile_Yuxuan_iteration_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void profile_Yuxuan_iteration_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_profile_Yuxuan_iteration_api.c) */
