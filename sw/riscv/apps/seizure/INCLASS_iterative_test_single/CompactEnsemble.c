/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactEnsemble.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "CompactEnsemble.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_internal_types.h"
#include "INCLASS_iterative_test_single_types.h"
#include "aggregatePredict.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : gc_classreg_learning_classif_Co *obj
 * Return Type  : void
 */
void CompactEnsemble_CompactEnsemble(gc_classreg_learning_classif_Co *obj)
{
  int i;
  for (i = 0; i < 15; i++) {
    obj->IsCached[i] = false;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void CompactEnsemble_ensemblePredict(const emxArray_real32_T *X,
                                     emxArray_real32_T *score)
{
  emxArray_boolean_T *r;
  int i;
  int loop_ub;
  boolean_T bv[5];
  boolean_T *r1;
  for (i = 0; i < 5; i++) {
    bv[i] = true;
  }
  emxInit_boolean_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = X->size[0];
  r->size[1] = 5;
  emxEnsureCapacity_boolean_T(r, i);
  r1 = r->data;
  loop_ub = X->size[0] * 5;
  for (i = 0; i < loop_ub; i++) {
    r1[i] = true;
  }
  aggregatePredict(X, score, bv, r);
  emxFree_boolean_T(&r);
}

/*
 * Arguments    : const boolean_T obj_IsCached[15]
 *                const emxArray_real32_T *X
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void b_CompactEnsemble_ensemblePredi(const boolean_T obj_IsCached[15],
                                     const emxArray_real32_T *X,
                                     emxArray_real32_T *score)
{
  emxArray_boolean_T *r;
  int i;
  int loop_ub;
  boolean_T bv[15];
  boolean_T *r1;
  for (i = 0; i < 15; i++) {
    bv[i] = true;
  }
  emxInit_boolean_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = X->size[0];
  r->size[1] = 15;
  emxEnsureCapacity_boolean_T(r, i);
  r1 = r->data;
  loop_ub = X->size[0] * 15;
  for (i = 0; i < loop_ub; i++) {
    r1[i] = true;
  }
  b_aggregatePredict(X, score, obj_IsCached, bv, r);
  emxFree_boolean_T(&r);
}

/*
 * Arguments    : const boolean_T obj_IsCached[15]
 *                const emxArray_real32_T *X
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void c_CompactEnsemble_ensemblePredi(const boolean_T obj_IsCached[15],
                                     const emxArray_real32_T *X,
                                     emxArray_real32_T *score)
{
  emxArray_boolean_T *r;
  int i;
  int loop_ub;
  boolean_T bv[15];
  boolean_T *r1;
  for (i = 0; i < 15; i++) {
    bv[i] = true;
  }
  emxInit_boolean_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = X->size[0];
  r->size[1] = 15;
  emxEnsureCapacity_boolean_T(r, i);
  r1 = r->data;
  loop_ub = X->size[0] * 15;
  for (i = 0; i < loop_ub; i++) {
    r1[i] = true;
  }
  c_aggregatePredict(X, score, obj_IsCached, bv, r);
  emxFree_boolean_T(&r);
}

/*
 * Arguments    : const boolean_T obj_IsCached[15]
 *                const emxArray_real32_T *X
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void d_CompactEnsemble_ensemblePredi(const boolean_T obj_IsCached[15],
                                     const emxArray_real32_T *X,
                                     emxArray_real32_T *score)
{
  emxArray_boolean_T *r;
  int i;
  int loop_ub;
  boolean_T bv[15];
  boolean_T *r1;
  for (i = 0; i < 15; i++) {
    bv[i] = true;
  }
  emxInit_boolean_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = X->size[0];
  r->size[1] = 15;
  emxEnsureCapacity_boolean_T(r, i);
  r1 = r->data;
  loop_ub = X->size[0] * 15;
  for (i = 0; i < loop_ub; i++) {
    r1[i] = true;
  }
  d_aggregatePredict(X, score, obj_IsCached, bv, r);
  emxFree_boolean_T(&r);
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                emxArray_real32_T *score
 * Return Type  : void
 */
void e_CompactEnsemble_ensemblePredi(const emxArray_real32_T *X,
                                     emxArray_real32_T *score)
{
  emxArray_boolean_T *r;
  int i;
  int loop_ub;
  boolean_T bv[10];
  boolean_T *r1;
  for (i = 0; i < 10; i++) {
    bv[i] = true;
  }
  emxInit_boolean_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = X->size[0];
  r->size[1] = 10;
  emxEnsureCapacity_boolean_T(r, i);
  r1 = r->data;
  loop_ub = X->size[0] * 10;
  for (i = 0; i < loop_ub; i++) {
    r1[i] = true;
  }
  e_aggregatePredict(X, score, bv, r);
  emxFree_boolean_T(&r);
}

/*
 * File trailer for CompactEnsemble.c
 *
 * [EOF]
 */
