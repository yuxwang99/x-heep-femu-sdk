/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Yuxuan_iterative_test_single_mex.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "_coder_Yuxuan_iterative_test_single_mex.h"
#include "_coder_Yuxuan_iterative_test_single_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&Yuxuan_iterative_test_single_atexit);
  /* Module initialization. */
  Yuxuan_iterative_test_single_initialize();
  /* Dispatch the entry-point. */
  unsafe_Yuxuan_iterative_test_single_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  Yuxuan_iterative_test_single_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[4]
 *                int32_T nrhs
 *                const mxArray *prhs[5]
 * Return Type  : void
 */
void unsafe_Yuxuan_iterative_test_single_mexFunction(int32_T nlhs,
                                                     mxArray *plhs[4],
                                                     int32_T nrhs,
                                                     const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[5];
  const mxArray *outputs[4];
  int32_T i;
  int32_T i1;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        28, "Yuxuan_iterative_test_single");
  }
  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 28,
                        "Yuxuan_iterative_test_single");
  }
  /* Call the function. */
  for (i = 0; i < 5; i++) {
    b_prhs[i] = prhs[i];
  }
  d_Yuxuan_iterative_test_single_(b_prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i1 = 1;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0], &outputs[0]);
}

/*
 * File trailer for _coder_Yuxuan_iterative_test_single_mex.c
 *
 * [EOF]
 */
