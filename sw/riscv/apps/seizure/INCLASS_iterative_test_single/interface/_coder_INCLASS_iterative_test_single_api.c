/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_INCLASS_iterative_test_single_api.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "_coder_INCLASS_iterative_test_single_api.h"
#include "_coder_INCLASS_iterative_test_single_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131643U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "INCLASS_iterative_test_single",                      /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y);

static const mxArray *b_emlrt_marshallOut(const real32_T u[5]);

static real32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier);

static real32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId);

static int8_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[85];

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, emxArray_real32_T *y);

static const mxArray *emlrt_marshallOut(const real32_T u);

static void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray,
                                       int32_T oldNumel);

static void emxFree_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray);

static void emxInit_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray);

static int8_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[85];

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real32_T *ret);

static real32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId);

static int8_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[85];

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u[5]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real32_T u[5])
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
 * Return Type  : real32_T
 */
static real32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real32_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T
 */
static real32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId)
{
  real32_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : int8_T (*)[85]
 */
static int8_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[85]
{
  emlrtMsgIdentifier thisId;
  int8_T(*y)[85];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const real32_T u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real32_T u)
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
 * Return Type  : void
 */
static void emxInit_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray)
{
  emxArray_real32_T *emxArray;
  *pEmxArray =
      (emxArray_real32_T *)emlrtMallocEmxArray(sizeof(emxArray_real32_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_real32_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : int8_T (*)[85]
 */
static int8_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[85]
{
  int8_T(*y)[85];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real32_T *ret
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
static real32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
static int8_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
 * Arguments    : void
 * Return Type  : void
 */
void INCLASS_iterative_test_single_atexit(void)
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
  INCLASS_iterative_test_single_xil_terminate();
  INCLASS_iterative_test_single_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void INCLASS_iterative_test_single_initialize(void)
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
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void INCLASS_iterative_test_single_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                int32_T nlhs
 *                const mxArray *plhs[5]
 * Return Type  : void
 */
void c_INCLASS_iterative_test_single(const mxArray *const prhs[5], int32_T nlhs,
                                     const mxArray *plhs[5])
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
  real32_T saveup_time;
  real32_T thrshd;
  int8_T(*masks)[85];
  st.tls = emlrtRootTLSGlobal;
  mask_runtime = (real32_T(*)[5])mxMalloc(sizeof(real32_T[5]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emxInit_real32_T(&st, &ECG_sig);
  ECG_sig->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "ECG_sig", ECG_sig);
  emxInit_real32_T(&st, &Spo2_sig);
  Spo2_sig->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Spo2_sig", Spo2_sig);
  conf_th = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "conf_th");
  thrshd = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "thrshd");
  masks = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "masks");
  /* Invoke the target function */
  INCLASS_iterative_test_single(ECG_sig, Spo2_sig, conf_th, thrshd, *masks,
                                &final_result, &ind, &runtime, &saveup_time,
                                *mask_runtime);
  emxFree_real32_T(&st, &Spo2_sig);
  emxFree_real32_T(&st, &ECG_sig);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(final_result);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(ind);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(runtime);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(saveup_time);
  }
  if (nlhs > 4) {
    plhs[4] = b_emlrt_marshallOut(*mask_runtime);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * File trailer for _coder_INCLASS_iterative_test_single_api.c
 *
 * [EOF]
 */
