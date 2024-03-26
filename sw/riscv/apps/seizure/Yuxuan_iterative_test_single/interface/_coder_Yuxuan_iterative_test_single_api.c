/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Yuxuan_iterative_test_single_api.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "_coder_Yuxuan_iterative_test_single_api.h"
#include "_coder_Yuxuan_iterative_test_single_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

static real32_T ctrl_vec_g[2];

static uint32_T ctrl_vec_g_guard;

static emxArray_real32_T *ECG_segment_g;

static uint32_T ECG_segment_g_guard;

static emxArray_real32_T *Rlocs_g;

static uint32_T Rlocs_g_guard;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131643U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "Yuxuan_iterative_test_single",                       /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[2]);

static const mxArray *b_emlrt_marshallOut(const emxArray_real32_T *u);

static void c_Yuxuan_iterative_test_single_(void);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real32_T *y);

static const mxArray *c_emlrt_marshallOut(const emxArray_real32_T *u);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y);

static const mxArray *d_emlrt_marshallOut(const real32_T u);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real32_T *y);

static const mxArray *e_emlrt_marshallOut(const real32_T u[5]);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, real32_T y[2]);

static const mxArray *emlrt_marshallOut(const real32_T u[2]);

static void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray,
                                       int32_T oldNumel);

static void emxFree_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray);

static void emxInit_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray,
                             int32_T numDimensions, boolean_T doPush);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real32_T *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y);

static real32_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier);

static real32_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId);

static int8_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[85];

static int8_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[85];

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real32_T ret[2]);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real32_T *ret);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real32_T *ret);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real32_T *ret);

static real32_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId);

static int8_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[85];

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[2]
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[2])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emxArray_real32_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const emxArray_real32_T *u)
{
  const mxArray *m;
  const mxArray *y;
  int32_T b_i;
  int32_T i;
  const real32_T *u_data;
  real32_T *pData;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, &u->size[0], mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  i = 0;
  for (b_i = 0; b_i < u->size[0]; b_i++) {
    pData[i] = u_data[b_i];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void c_Yuxuan_iterative_test_single_(void)
{
  Rlocs_g_guard = 0U;
  ECG_segment_g_guard = 0U;
  ctrl_vec_g_guard = 0U;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emxArray_real32_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const emxArray_real32_T *u)
{
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  const real32_T *u_data;
  real32_T *pData;
  u_data = u->data;
  y = NULL;
  iv[0] = 1;
  iv[1] = u->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  i = 0;
  for (b_i = 0; b_i < u->size[1]; b_i++) {
    pData[i] = u_data[b_i];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y)
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const real32_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
  *(real32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const real32_T u[5]
 * Return Type  : const mxArray *
 */
static const mxArray *e_emlrt_marshallOut(const real32_T u[5])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {1, 5};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                real32_T y[2]
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, real32_T y[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const real32_T u[2]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real32_T u[2])
{
  static const int32_T iv[2] = {1, 2};
  const mxArray *m;
  const mxArray *y;
  real32_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  pData[0] = u[0];
  pData[1] = u[1];
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : emxArray_real32_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray,
                                       int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(real32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real32_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real32_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T *)NULL) {
    if (((*pEmxArray)->data != (real32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real32_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real32_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray,
                             int32_T numDimensions, boolean_T doPush)
{
  emxArray_real32_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_real32_T *)emlrtMallocEmxArray(sizeof(emxArray_real32_T));
  if (doPush) {
    emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                        (void *)&emxFree_real32_T, NULL, NULL,
                                        NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size =
      (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y)
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y)
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real32_T
 */
static real32_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real32_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T
 */
static real32_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId)
{
  real32_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : int8_T (*)[85]
 */
static int8_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[85]
{
  emlrtMsgIdentifier thisId;
  int8_T(*y)[85];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : int8_T (*)[85]
 */
static int8_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[85]
{
  int8_T(*y)[85];
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[2]
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real32_T ret[2])
{
  static const int32_T dims[2] = {1, 2};
  real32_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                          (const void *)&dims[0]);
  r = (real32_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real32_T *ret
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real32_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  real32_T *ret_data;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                            (const void *)&dims, &b, &i);
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real32_T(ret, i1);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real32_T *ret
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real32_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  real32_T *ret_data;
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real32_T(ret, i);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real32_T *ret
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real32_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                            (const void *)&dims, &b, &i);
  ret->allocatedSize = i;
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real32_T(ret, i1);
  ret->data = (real32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T
 */
static real32_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real32_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 0U,
                          (const void *)&dims);
  ret = *(real32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : int8_T (*)[85]
 */
static int8_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[85]
{
  static const int32_T dims[2] = {5, 17};
  int32_T iv[2];
  int8_T(*ret)[85];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "int8", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (int8_T(*)[85])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 * Return Type  : void
 */
void MEXGlobalSyncInFunction(const emlrtStack *sp)
{
  const mxArray *tmp;
  /* Marshall in global variables */
  tmp = emlrtGetGlobalVariable("ctrl_vec_g");
  if (tmp != NULL) {
    emlrt_marshallIn(sp, tmp, "ctrl_vec_g", ctrl_vec_g);
    ctrl_vec_g_guard = 1U;
  }
  tmp = emlrtGetGlobalVariable("ECG_segment_g");
  if (tmp != NULL) {
    c_emlrt_marshallIn(sp, tmp, "ECG_segment_g", ECG_segment_g);
    ECG_segment_g_guard = 1U;
  }
  tmp = emlrtGetGlobalVariable("Rlocs_g");
  if (tmp != NULL) {
    e_emlrt_marshallIn(sp, tmp, "Rlocs_g", Rlocs_g);
    Rlocs_g_guard = 1U;
  }
}

/*
 * Arguments    : boolean_T skipDirtyCheck
 * Return Type  : void
 */
void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  /* Marshall out global variables */
  if (skipDirtyCheck || (ctrl_vec_g_guard != 0U)) {
    emlrtPutGlobalVariable("ctrl_vec_g", emlrt_marshallOut(ctrl_vec_g));
  }
  if (skipDirtyCheck || (ECG_segment_g_guard != 0U)) {
    emlrtPutGlobalVariable("ECG_segment_g", b_emlrt_marshallOut(ECG_segment_g));
  }
  if (skipDirtyCheck || (Rlocs_g_guard != 0U)) {
    emlrtPutGlobalVariable("Rlocs_g", c_emlrt_marshallOut(Rlocs_g));
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Yuxuan_iterative_test_single_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  Yuxuan_iterative_test_single_xil_terminate();
  Yuxuan_iterative_test_single_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Yuxuan_iterative_test_single_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 2U, "ForceOff");
  emlrtEnterRtStackR2012b(&st);
  emxInit_real32_T(&st, &Rlocs_g, 2, false);
  emxInit_real32_T(&st, &ECG_segment_g, 1, false);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    c_Yuxuan_iterative_test_single_();
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Yuxuan_iterative_test_single_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emxFree_real32_T(&st, &ECG_segment_g);
  emxFree_real32_T(&st, &Rlocs_g);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void d_Yuxuan_iterative_test_single_(const mxArray *const prhs[5], int32_T nlhs,
                                     const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real32_T *ECG_sig;
  emxArray_real32_T *Spo2_sig;
  real32_T(*mask_runtime)[5];
  real32_T conf_th;
  real32_T final_result;
  real32_T ind;
  real32_T runtime;
  real32_T thrshd;
  int8_T(*masks)[85];
  st.tls = emlrtRootTLSGlobal;
  mask_runtime = (real32_T(*)[5])mxMalloc(sizeof(real32_T[5]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emxInit_real32_T(&st, &ECG_sig, 1, true);
  ECG_sig->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "ECG_sig", ECG_sig);
  emxInit_real32_T(&st, &Spo2_sig, 1, true);
  Spo2_sig->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Spo2_sig", Spo2_sig);
  conf_th = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "conf_th");
  thrshd = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "thrshd");
  masks = k_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "masks");
  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);
  /* Invoke the target function */
  Yuxuan_iterative_test_single(ECG_sig, Spo2_sig, conf_th, thrshd, *masks,
                               &final_result, &ind, &runtime, *mask_runtime);
  emxFree_real32_T(&st, &Spo2_sig);
  emxFree_real32_T(&st, &ECG_sig);
  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);
  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(final_result);
  if (nlhs > 1) {
    plhs[1] = d_emlrt_marshallOut(ind);
  }
  if (nlhs > 2) {
    plhs[2] = d_emlrt_marshallOut(runtime);
  }
  if (nlhs > 3) {
    plhs[3] = e_emlrt_marshallOut(*mask_runtime);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * File trailer for _coder_Yuxuan_iterative_test_single_api.c
 *
 * [EOF]
 */
