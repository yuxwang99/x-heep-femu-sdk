/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: unique.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "unique.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "isinf.h"
#include "isnan.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"

/* Function Declarations */
static int b_count_nonfinites(const emxArray_real_T *b, int nb, int *nFinite,
                              int *nPInf, int *nNaN);

static int count_nonfinites(const emxArray_real32_T *b, int nb, int *nFinite,
                            int *nPInf, int *nNaN);

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *b
 *                int nb
 *                int *nFinite
 *                int *nPInf
 *                int *nNaN
 * Return Type  : int
 */
static int b_count_nonfinites(const emxArray_real_T *b, int nb, int *nFinite,
                              int *nPInf, int *nNaN)
{
  const double *b_data;
  int nMInf;
  b_data = b->data;
  nMInf = 0;
  *nFinite = nb;
  while ((*nFinite >= 1) && b_isnan(b_data[*nFinite - 1])) {
    (*nFinite)--;
  }
  *nNaN = nb - *nFinite;
  while ((*nFinite >= 1) && c_isinf(b_data[*nFinite - 1])) {
    (*nFinite)--;
  }
  *nPInf = (nb - *nFinite) - *nNaN;
  return nMInf;
}

/*
 * Arguments    : const emxArray_real32_T *b
 *                int nb
 *                int *nFinite
 *                int *nPInf
 *                int *nNaN
 * Return Type  : int
 */
static int count_nonfinites(const emxArray_real32_T *b, int nb, int *nFinite,
                            int *nPInf, int *nNaN)
{
  const float *b_data;
  int k;
  int nMInf;
  boolean_T exitg1;
  b_data = b->data;
  k = 0;
  while ((k + 1 <= nb) && b_isinf(b_data[k]) && (b_data[k] < 0.0F)) {
    k++;
  }
  nMInf = k;
  k = nb;
  while ((k >= 1) && c_isnan(b_data[k - 1])) {
    k--;
  }
  *nNaN = nb - k;
  exitg1 = false;
  while ((!exitg1) && (k >= 1)) {
    float f;
    f = b_data[k - 1];
    if (b_isinf(f) && (f > 0.0F)) {
      k--;
    } else {
      exitg1 = true;
    }
  }
  *nPInf = (nb - k) - *nNaN;
  *nFinite = k - nMInf;
  return nMInf;
}

/*
 * Arguments    : const emxArray_real_T *a
 *                emxArray_real_T *b
 * Return Type  : void
 */
void b_unique_vector(const emxArray_real_T *a, emxArray_real_T *b)
{
  emxArray_int32_T *idx;
  const double *a_data;
  double *b_data;
  int k;
  int nMInf;
  int nNaN;
  int na;
  int nb;
  int *idx_data;
  a_data = a->data;
  na = a->size[0];
  emxInit_int32_T(&idx, 1);
  b_sortIdx(a, idx);
  idx_data = idx->data;
  k = b->size[0];
  b->size[0] = a->size[0];
  emxEnsureCapacity_real_T(b, k);
  b_data = b->data;
  for (k = 0; k < na; k++) {
    b_data[k] = a_data[idx_data[k] - 1];
  }
  emxFree_int32_T(&idx);
  nMInf = b_count_nonfinites(b, a->size[0], &na, &k, &nNaN);
  nb = -1;
  if (nMInf > 0) {
    nb = 0;
  }
  na += nMInf;
  while (nMInf + 1 <= na) {
    double x;
    x = b_data[nMInf];
    do {
      nMInf++;
    } while (!((nMInf + 1 > na) || (b_data[nMInf] != x)));
    nb++;
    b_data[nb] = x;
  }
  if (k > 0) {
    nb++;
    b_data[nb] = b_data[na];
  }
  nMInf = na + k;
  for (na = 0; na < nNaN; na++) {
    b_data[(nb + na) + 1] = b_data[nMInf + na];
  }
  if (nNaN - 1 >= 0) {
    nb += nNaN;
  }
  k = b->size[0];
  if (nb + 1 < 1) {
    b->size[0] = 0;
  } else {
    b->size[0] = nb + 1;
  }
  emxEnsureCapacity_real_T(b, k);
}

/*
 * Arguments    : const emxArray_real32_T *a
 *                emxArray_real32_T *b
 *                emxArray_int32_T *ndx
 * Return Type  : void
 */
void c_unique_vector(const emxArray_real32_T *a, emxArray_real32_T *b,
                     emxArray_int32_T *ndx)
{
  emxArray_int32_T *idx;
  const float *a_data;
  float *b_data;
  int k0;
  int nInf;
  int nMInf;
  int nNaN;
  int na;
  int nb;
  int *idx_data;
  int *ndx_data;
  a_data = a->data;
  na = a->size[0];
  emxInit_int32_T(&idx, 1);
  c_sortIdx(a, idx);
  idx_data = idx->data;
  k0 = b->size[0];
  b->size[0] = a->size[0];
  emxEnsureCapacity_real32_T(b, k0);
  b_data = b->data;
  for (k0 = 0; k0 < na; k0++) {
    b_data[k0] = a_data[idx_data[k0] - 1];
  }
  nMInf = count_nonfinites(b, a->size[0], &na, &nInf, &nNaN);
  nb = -1;
  if (nMInf > 0) {
    nb = 0;
  }
  na += nMInf;
  while (nMInf + 1 <= na) {
    float x;
    x = b_data[nMInf];
    k0 = nMInf;
    do {
      nMInf++;
    } while (!((nMInf + 1 > na) || (b_data[nMInf] != x)));
    nb++;
    b_data[nb] = x;
    idx_data[nb] = idx_data[k0];
  }
  if (nInf > 0) {
    nb++;
    b_data[nb] = b_data[na];
    idx_data[nb] = idx_data[na];
  }
  nMInf = (na + nInf) - 1;
  for (nInf = 0; nInf < nNaN; nInf++) {
    na = (nMInf + nInf) + 1;
    k0 = (nb + nInf) + 1;
    b_data[k0] = b_data[na];
    idx_data[k0] = idx_data[na];
  }
  if (nNaN - 1 >= 0) {
    nb += nNaN;
  }
  k0 = b->size[0];
  if (nb + 1 < 1) {
    b->size[0] = 0;
  } else {
    b->size[0] = nb + 1;
  }
  emxEnsureCapacity_real32_T(b, k0);
  k0 = ndx->size[0];
  ndx->size[0] = nb + 1;
  emxEnsureCapacity_int32_T(ndx, k0);
  ndx_data = ndx->data;
  for (k0 = 0; k0 <= nb; k0++) {
    ndx_data[k0] = idx_data[k0];
  }
  emxFree_int32_T(&idx);
}

/*
 * Arguments    : const emxArray_real32_T *a
 *                emxArray_real32_T *b
 * Return Type  : void
 */
void unique_vector(const emxArray_real32_T *a, emxArray_real32_T *b)
{
  emxArray_int32_T *idx;
  const float *a_data;
  float *b_data;
  int k;
  int nMInf;
  int nNaN;
  int na;
  int nb;
  int *idx_data;
  a_data = a->data;
  na = a->size[1];
  emxInit_int32_T(&idx, 2);
  sortIdx(a, idx);
  idx_data = idx->data;
  k = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = a->size[1];
  emxEnsureCapacity_real32_T(b, k);
  b_data = b->data;
  for (k = 0; k < na; k++) {
    b_data[k] = a_data[idx_data[k] - 1];
  }
  emxFree_int32_T(&idx);
  nMInf = count_nonfinites(b, a->size[1], &na, &k, &nNaN);
  nb = -1;
  if (nMInf > 0) {
    nb = 0;
  }
  na += nMInf;
  while (nMInf + 1 <= na) {
    float x;
    x = b_data[nMInf];
    do {
      nMInf++;
    } while (!((nMInf + 1 > na) || (b_data[nMInf] != x)));
    nb++;
    b_data[nb] = x;
  }
  if (k > 0) {
    nb++;
    b_data[nb] = b_data[na];
  }
  nMInf = na + k;
  for (na = 0; na < nNaN; na++) {
    b_data[(nb + na) + 1] = b_data[nMInf + na];
  }
  if (nNaN - 1 >= 0) {
    nb += nNaN;
  }
  k = b->size[0] * b->size[1];
  if (nb + 1 < 1) {
    b->size[1] = 0;
  } else {
    b->size[1] = nb + 1;
  }
  emxEnsureCapacity_real32_T(b, k);
}

/*
 * File trailer for unique.c
 *
 * [EOF]
 */
