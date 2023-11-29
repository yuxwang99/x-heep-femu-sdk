/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * profile_Yuxuan_iteration_emxutil.h
 *
 * Code generation for function 'profile_Yuxuan_iteration_emxutil'
 *
 */

#ifndef PROFILE_YUXUAN_ITERATION_EMXUTIL_H
#define PROFILE_YUXUAN_ITERATION_EMXUTIL_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int
    oldNumel);
  extern void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel);
  extern void emxEnsureCapacity_int16_T(emxArray_int16_T *emxArray, int oldNumel);
  extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
  extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
  extern void emxEnsureCapacity_uint16_T(emxArray_uint16_T *emxArray, int
    oldNumel);
  extern void emxFreeMatrix_cell_wrap_66(cell_wrap_66 pMatrix[2]);
  extern void emxFreeStruct_cell_wrap_66(cell_wrap_66 *pStruct);
  extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
  extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);
  extern void emxFree_int16_T(emxArray_int16_T **pEmxArray);
  extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
  extern void emxFree_real_T(emxArray_real_T **pEmxArray);
  extern void emxFree_uint16_T(emxArray_uint16_T **pEmxArray);
  extern void emxInitMatrix_cell_wrap_66(cell_wrap_66 pMatrix[2]);
  extern void emxInitStruct_cell_wrap_66(cell_wrap_66 *pStruct);
  extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int
    numDimensions);
  extern void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions);
  extern void emxInit_int16_T(emxArray_int16_T **pEmxArray, int numDimensions);
  extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
  extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
  extern void emxInit_uint16_T(emxArray_uint16_T **pEmxArray, int numDimensions);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (profile_Yuxuan_iteration_emxutil.h) */
