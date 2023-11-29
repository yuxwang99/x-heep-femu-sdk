/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_profile_Yuxuan_iteration_mex.c
 *
 * Code generation for function 'profile_Yuxuan_iteration'
 *
 */

/* Include files */
#include "_coder_profile_Yuxuan_iteration_mex.h"
#include "_coder_profile_Yuxuan_iteration_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&profile_Yuxuan_iteration_atexit);

  /* Module initialization. */
  profile_Yuxuan_iteration_initialize();

  /* Dispatch the entry-point. */
  profile_Yuxuan_iteration_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  profile_Yuxuan_iteration_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

void profile_Yuxuan_iteration_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[17])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 17) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 17, 4,
                        24, "profile_Yuxuan_iteration");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 24,
                        "profile_Yuxuan_iteration");
  }

  /* Call the function. */
  profile_Yuxuan_iteration_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

/* End of code generation (_coder_profile_Yuxuan_iteration_mex.c) */
