/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: movfunDispatch.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "movfunDispatch.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "floor.h"
#include "indexIntRelop.h"
#include "movSumProdOrMean.h"
#include "movsortfun.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void b_dispatch(const emxArray_real32_T *x, float k,
                       emxArray_real32_T *y);

static void dispatch(const float x[400], float y[400]);

static int toKleftKrightIndexInt(float k, int xlen, int *kright);

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 *                float k
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void b_dispatch(const emxArray_real32_T *x, float k,
                       emxArray_real32_T *y)
{
  int kleft;
  int kright;
  kleft = toKleftKrightIndexInt(k, x->size[0], &kright);
  movSumProdOrMean(x, kleft, kright, y);
}

/*
 * Arguments    : const float x[400]
 *                float y[400]
 * Return Type  : void
 */
static void dispatch(const float x[400], float y[400])
{
  movsortfun(x, y);
}

/*
 * Arguments    : float k
 *                int xlen
 *                int *kright
 * Return Type  : int
 */
static int toKleftKrightIndexInt(float k, int xlen, int *kright)
{
  int kleft;
  if (idx_le_flt(k)) {
    kleft = xlen;
    *kright = xlen;
  } else {
    kleft = (int)b_floor(k / 2.0F);
    *kright = kleft;
    if (idx_eq_flt(kleft << 1, k)) {
      *kright = kleft - 1;
    }
    if (kleft > xlen) {
      kleft = xlen;
    }
    if (*kright > xlen) {
      *kright = xlen;
    }
  }
  return kleft;
}

/*
 * Arguments    : const emxArray_real32_T *x
 *                float k
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void b_movfunDispatch(const emxArray_real32_T *x, float k, emxArray_real32_T *y)
{
  b_dispatch(x, k, y);
}

/*
 * Arguments    : const float x[400]
 *                float y[400]
 * Return Type  : void
 */
void movfunDispatch(const float x[400], float y[400])
{
  dispatch(x, y);
}

/*
 * File trailer for movfunDispatch.c
 *
 * [EOF]
 */
