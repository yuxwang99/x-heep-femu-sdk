/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: movSumProdOrMean.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "movSumProdOrMean.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "applyVectorFunction.h"
#include "combineVectorElements.h"
#include "repmat.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void movSumProdOrMean_anonFcn1(int nx, int kleft, int kright,
                                      const emxArray_real32_T *x,
                                      emxArray_real32_T *varargout_1);

static float processWindow(int i, const emxArray_real32_T *x, int kleft,
                           int kright);

static void vmovfun(const emxArray_real32_T *x, int nx, int kleft, int kright,
                    emxArray_real32_T *y);

/* Function Definitions */
/*
 * Arguments    : int nx
 *                int kleft
 *                int kright
 *                const emxArray_real32_T *x
 *                emxArray_real32_T *varargout_1
 * Return Type  : void
 */
static void movSumProdOrMean_anonFcn1(int nx, int kleft, int kright,
                                      const emxArray_real32_T *x,
                                      emxArray_real32_T *varargout_1)
{
  vmovfun(x, nx, kleft, kright, varargout_1);
}

/*
 * Arguments    : int i
 *                const emxArray_real32_T *x
 *                int kleft
 *                int kright
 * Return Type  : float
 */
static float processWindow(int i, const emxArray_real32_T *x, int kleft,
                           int kright)
{
  int iLeft;
  int ipnf;
  if (i <= kleft) {
    iLeft = 1;
  } else {
    iLeft = i - kleft;
  }
  ipnf = i + kright;
  if (ipnf > x->size[0]) {
    ipnf = x->size[0];
  }
  return i_combineVectorElements(x, (ipnf - iLeft) + 1, iLeft);
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                int nx
 *                int kleft
 *                int kright
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void vmovfun(const emxArray_real32_T *x, int nx, int kleft, int kright,
                    emxArray_real32_T *y)
{
  float *y_data;
  int i;
  int loop_ub;
  i = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real32_T(y, i);
  y_data = y->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = 0.0F;
  }
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    y_data[loop_ub] = processWindow(loop_ub + 1, x, kleft, kright);
  }
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                int kleft
 *                int kright
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void movSumProdOrMean(const emxArray_real32_T *x, int kleft, int kright,
                      emxArray_real32_T *y)
{
  emxArray_real32_T *xv;
  emxArray_real32_T *yv;
  const float *x_data;
  float *xv_data;
  float *y_data;
  int k;
  int nx;
  int p;
  int workspace_ixfirst_tmp;
  x_data = x->data;
  workspace_ixfirst_tmp = y->size[0] * y->size[1];
  y->size[0] = x->size[0];
  y->size[1] = 2;
  emxEnsureCapacity_real32_T(y, workspace_ixfirst_tmp);
  y_data = y->data;
  nx = x->size[0] << 1;
  for (workspace_ixfirst_tmp = 0; workspace_ixfirst_tmp < nx;
       workspace_ixfirst_tmp++) {
    y_data[workspace_ixfirst_tmp] = 0.0F;
  }
  nx = x->size[0];
  emxInit_real32_T(&xv, 1);
  emxInit_real32_T(&yv, 1);
  for (p = 0; p < 2; p++) {
    int len;
    workspace_ixfirst_tmp = p * nx + 1;
    e_repmat(nx, xv);
    xv_data = xv->data;
    for (k = 0; k < nx; k++) {
      xv_data[k] =
          x_data[b_looper1D_anonFcn1(workspace_ixfirst_tmp, k + 1) - 1];
    }
    movSumProdOrMean_anonFcn1(x->size[0], kleft, kright, xv, yv);
    xv_data = yv->data;
    len = yv->size[0];
    for (k = 0; k < len; k++) {
      y_data[b_looper1D_anonFcn1(workspace_ixfirst_tmp, k + 1) - 1] =
          xv_data[k];
    }
  }
  emxFree_real32_T(&yv);
  emxFree_real32_T(&xv);
}

/*
 * File trailer for movSumProdOrMean.c
 *
 * [EOF]
 */
