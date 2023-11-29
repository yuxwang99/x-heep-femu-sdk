/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_profile_Yuxuan_iteration_api.h
 *
 * Code generation for function 'profile_Yuxuan_iteration'
 *
 */

#ifndef _CODER_PROFILE_YUXUAN_ITERATION_API_H
#define _CODER_PROFILE_YUXUAN_ITERATION_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_rtString
#define typedef_rtString

typedef struct {
  char_T Value[41];
} rtString;

#endif                                 /*typedef_rtString*/

#ifndef typedef_b_rtString
#define typedef_b_rtString

typedef struct {
  char_T Value[42];
} b_rtString;

#endif                                 /*typedef_b_rtString*/

#ifndef typedef_c_rtString
#define typedef_c_rtString

typedef struct {
  char_T Value[43];
} c_rtString;

#endif                                 /*typedef_c_rtString*/

#ifndef typedef_cell_0
#define typedef_cell_0

typedef struct {
  rtString f1;
  b_rtString f2;
  b_rtString f3;
  b_rtString f4;
  b_rtString f5;
  b_rtString f6;
  b_rtString f7;
  b_rtString f8;
  b_rtString f9;
  b_rtString f10;
  b_rtString f11;
  rtString f12;
  b_rtString f13;
  rtString f14;
  rtString f15;
  rtString f16;
  rtString f17;
  rtString f18;
  rtString f19;
  rtString f20;
  b_rtString f21;
  b_rtString f22;
  b_rtString f23;
  b_rtString f24;
  b_rtString f25;
  b_rtString f26;
  b_rtString f27;
  b_rtString f28;
  b_rtString f29;
  b_rtString f30;
  b_rtString f31;
  b_rtString f32;
  b_rtString f33;
  b_rtString f34;
  b_rtString f35;
  b_rtString f36;
  b_rtString f37;
  b_rtString f38;
  rtString f39;
  rtString f40;
  b_rtString f41;
  b_rtString f42;
  b_rtString f43;
  b_rtString f44;
  b_rtString f45;
  b_rtString f46;
  rtString f47;
  rtString f48;
  c_rtString f49;
  c_rtString f50;
  b_rtString f51;
  b_rtString f52;
  rtString f53;
  rtString f54;
  rtString f55;
  b_rtString f56;
  b_rtString f57;
  b_rtString f58;
  b_rtString f59;
  b_rtString f60;
  b_rtString f61;
  b_rtString f62;
  rtString f63;
  b_rtString f64;
  b_rtString f65;
  b_rtString f66;
  b_rtString f67;
  b_rtString f68;
  b_rtString f69;
  rtString f70;
  b_rtString f71;
  b_rtString f72;
  b_rtString f73;
  b_rtString f74;
  rtString f75;
  rtString f76;
  rtString f77;
  rtString f78;
  b_rtString f79;
  b_rtString f80;
  b_rtString f81;
  rtString f82;
  rtString f83;
  rtString f84;
  rtString f85;
  rtString f86;
  rtString f87;
  rtString f88;
  rtString f89;
  rtString f90;
} cell_0;

#endif                                 /*typedef_cell_0*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void profile_Yuxuan_iteration(real_T ECG_Seiz_Window[2764800], real_T
    Spo2_Seiz_Window[2764800], real_T ECG_Gray_Window[2764800], real_T
    Spo2_Gray_Window[2764800], real_T norm_coef1[2], real_T norm_coef2[3],
    real_T norm_coef3[5], real_T norm_coef4[13], real_T norm_coef5[17], real_T
    wind_len, real_T masks[85], real_T profile_times, cell_0 *File_info, real_T
    Fs, real_T Nbr_RR, real_T conf_seiz, boolean_T select_ind[90], real_T
    pred_label_data[], int32_T pred_label_size[2], real_T true_label_data[],
    int32_T true_label_size[2]);
  void profile_Yuxuan_iteration_api(const mxArray * const prhs[17], int32_T nlhs,
    const mxArray *plhs[2]);
  void profile_Yuxuan_iteration_atexit(void);
  void profile_Yuxuan_iteration_initialize(void);
  void profile_Yuxuan_iteration_terminate(void);
  void profile_Yuxuan_iteration_xil_shutdown(void);
  void profile_Yuxuan_iteration_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (_coder_profile_Yuxuan_iteration_api.h) */
