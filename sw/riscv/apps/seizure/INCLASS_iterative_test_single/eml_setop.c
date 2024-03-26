/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_setop.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "eml_setop.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "relop.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static int skip_to_last_equal_value(int *k, const emxArray_int32_T *x);

/* Function Definitions */
/*
 * Arguments    : int *k
 *                const emxArray_int32_T *x
 * Return Type  : int
 */
static int skip_to_last_equal_value(int *k, const emxArray_int32_T *x)
{
  const int *x_data;
  int xk;
  x_data = x->data;
  xk = x_data[*k - 1];
  while ((*k < x->size[0]) && (x_data[*k] == xk)) {
    (*k)++;
  }
  return xk;
}

/*
 * Arguments    : const emxArray_int32_T *a
 *                const emxArray_int32_T *b
 *                emxArray_int32_T *c
 *                emxArray_int32_T *ia
 *                emxArray_int32_T *ib
 * Return Type  : void
 */
void do_vectors(const emxArray_int32_T *a, const emxArray_int32_T *b,
                emxArray_int32_T *c, emxArray_int32_T *ia, emxArray_int32_T *ib)
{
  int ak;
  int b_a;
  int b_iblast;
  int bk;
  int iafirst;
  int ialast;
  int ibfirst;
  int iblast;
  int na;
  int nb;
  int nc;
  int ncmax;
  int nia;
  int nib;
  int *c_data;
  int *ia_data;
  int *ib_data;
  na = a->size[0];
  nb = b->size[0];
  ncmax = a->size[0] + b->size[0];
  b_a = c->size[0];
  c->size[0] = ncmax;
  emxEnsureCapacity_int32_T(c, b_a);
  c_data = c->data;
  b_a = ia->size[0];
  ia->size[0] = a->size[0];
  emxEnsureCapacity_int32_T(ia, b_a);
  ia_data = ia->data;
  b_a = ib->size[0];
  ib->size[0] = b->size[0];
  emxEnsureCapacity_int32_T(ib, b_a);
  ib_data = ib->data;
  nc = -1;
  nia = -1;
  nib = 0;
  iafirst = 1;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= na) && (iblast <= nb)) {
    b_a = ialast;
    ak = skip_to_last_equal_value(&b_a, a);
    ialast = b_a;
    b_iblast = iblast;
    bk = skip_to_last_equal_value(&b_iblast, b);
    iblast = b_iblast;
    if (ak == bk) {
      nc++;
      c_data[nc] = ak;
      nia++;
      ia_data[nia] = iafirst;
      ialast = b_a + 1;
      iafirst = b_a + 1;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (relop(ak, bk)) {
      nc++;
      nia++;
      c_data[nc] = ak;
      ia_data[nia] = iafirst;
      ialast = b_a + 1;
      iafirst = b_a + 1;
    } else {
      nc++;
      nib++;
      c_data[nc] = bk;
      ib_data[nib - 1] = ibfirst + 1;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    }
  }
  while (ialast <= na) {
    b_a = ialast;
    ak = skip_to_last_equal_value(&b_a, a);
    nc++;
    nia++;
    c_data[nc] = ak;
    ia_data[nia] = iafirst;
    ialast = b_a + 1;
    iafirst = b_a + 1;
  }
  while (iblast <= nb) {
    b_a = iblast;
    bk = skip_to_last_equal_value(&b_a, b);
    nc++;
    nib++;
    c_data[nc] = bk;
    ib_data[nib - 1] = ibfirst + 1;
    iblast = b_a + 1;
    ibfirst = b_a;
  }
  if (a->size[0] > 0) {
    b_a = ia->size[0];
    if (nia + 1 < 1) {
      ia->size[0] = 0;
    } else {
      ia->size[0] = nia + 1;
    }
    emxEnsureCapacity_int32_T(ia, b_a);
  }
  if (b->size[0] > 0) {
    b_a = ib->size[0];
    if (nib < 1) {
      ib->size[0] = 0;
    } else {
      ib->size[0] = nib;
    }
    emxEnsureCapacity_int32_T(ib, b_a);
  }
  if (ncmax > 0) {
    b_a = c->size[0];
    if (nc + 1 < 1) {
      c->size[0] = 0;
    } else {
      c->size[0] = nc + 1;
    }
    emxEnsureCapacity_int32_T(c, b_a);
  }
}

/*
 * File trailer for eml_setop.c
 *
 * [EOF]
 */
