/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Yuxuan_iterative_test_single_info.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "_coder_Yuxuan_iterative_test_single_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[7] = {
      "789ced96cf6e12411cc7b7a69ac644e5e09f8b311e9a1e34612ab4b53d2295766b4bb0cb"
      "4ab03674d81dba0bb3bb746616b67d02a307bde903f8101e315e7c02"
      "3de8c9938f210506e8261b084d86a5f47bf9ed8fdfce7c7f33cb7c32d28cbc332349d24d"
      "a92de3613bdee8e4914ebc229d95bf3ed389d77c39d75569f6cc385e",
      "ffd0899a6333e4b17662430b7547ea8e65dad066d9e32a9208a20eae21bd55299918654d"
      "0b29fd49fa34b3527da56e725a3a7d4e1a48ab28ae251183f63ac4fd"
      "49773f0e02d63b3b603ffcf2ef87ffbd69f16b8ce8c7e7cf0ff0e3f53d751fa814110a8e"
      "5dcf8536c810a78c3446412c9e821803399ddc4e280aa0442b546115",
      "11a0152c474718240bd4b40f312a94686c79a55072316e579e442dc87ceb3908e8f7d690"
      "ebf1c7defb73adf86eff0f12e9b730f7e991483fae71f97901f30dfb"
      "7fbc1be017f1d5f1f622adcbd94d563faaa8e56a6e559113cb1bbd3e32037c06f52105e4"
      "a2e63f08187f51b825daaf31a25f1838191b0327df0be6e4cfbfdfaf",
      "8bf4e39a544ede09f08bf8ea4f9557cfca356824503e6e33d9d276b6d2aa74c949bfc2ca"
      "2dd17e8d11fdc2c0c9f81470f2a375ef81483fae49e5e4b0f749751d"
      "1d6eb8262ddbf55cde283dd75f56bcdae62527fd0a2bb744fb3546f40b032797a680935f"
      "7efc0322fdb8269593c3de276b95dadad6ee89522cee9e64e2f1ba59",
      "9219932e39e95758b925daaf31a25f1838b93c064efe7e2d9693bfbeddbe2fd28f6b5239"
      "39ec7d52d6d7d6bcb87a1c53d71386914a7947f5cc8be4c5e1e4d780"
      "f1c3eea31a307fc457df9393fbf3cd63886191380e9b07cc7170d1f10065b079b8350c29"
      "25e8103cee3d610489dd3cd1cddf9aa79880a46355a1c63204e9a6c6",
      "1c12b5fad6f1f69ceb5818b00e5ee7ed457977d156732e33318d6609b469c921d6f8387d"
      "deefa90cf0e3f53d397dceefd9da32d0ddb2d6d714c793cfb9ec1b91"
      "7e5cd3e2278acf5b309b75a19e23c534ab2ee557bdc598432e009fff03a05f927c",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 8320U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("Yuxuan_iterative_test_single"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString(
          "/Users/yuxuan/Projects/23Fall/INCLASS/src_paper/extern_new/codegen/"
          "Yuxuan_iterative_test/single/Yuxuan_iterative_test_single.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739308.418599537));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2365128 (R2023b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("RAWdI9shfpQ6rIaxVoCb8B"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_Yuxuan_iterative_test_single_info.c
 *
 * [EOF]
 */
