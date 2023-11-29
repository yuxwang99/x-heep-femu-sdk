/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * profile_Yuxuan_iteration_types.h
 *
 * Code generation for function 'profile_Yuxuan_iteration'
 *
 */

#ifndef PROFILE_YUXUAN_ITERATION_TYPES_H
#define PROFILE_YUXUAN_ITERATION_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_rtString
#define typedef_rtString

typedef struct {
  char Value[41];
} rtString;

#endif                                 /*typedef_rtString*/

#ifndef typedef_b_rtString
#define typedef_b_rtString

typedef struct {
  char Value[42];
} b_rtString;

#endif                                 /*typedef_b_rtString*/

#ifndef typedef_c_rtString
#define typedef_c_rtString

typedef struct {
  char Value[43];
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

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_cell_wrap_66
#define typedef_cell_wrap_66

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_66;

#endif                                 /*typedef_cell_wrap_66*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_int16_T
#define struct_emxArray_int16_T

struct emxArray_int16_T
{
  short *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int16_T*/

#ifndef typedef_emxArray_int16_T
#define typedef_emxArray_int16_T

typedef struct emxArray_int16_T emxArray_int16_T;

#endif                                 /*typedef_emxArray_int16_T*/

#ifndef struct_emxArray_uint16_T
#define struct_emxArray_uint16_T

struct emxArray_uint16_T
{
  unsigned short *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint16_T*/

#ifndef typedef_emxArray_uint16_T
#define typedef_emxArray_uint16_T

typedef struct emxArray_uint16_T emxArray_uint16_T;

#endif                                 /*typedef_emxArray_uint16_T*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct {
  creal_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/
#endif

/* End of code generation (profile_Yuxuan_iteration_types.h) */
