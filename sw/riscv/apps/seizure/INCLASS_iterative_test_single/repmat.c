/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "repmat.h"
#include "INCLASS_iterative_test_single_emxutil.h"
#include "INCLASS_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : float a
 *                int varargin_1
 *                emxArray_real32_T *b
 * Return Type  : void
 */
void b_repmat(float a, int varargin_1, emxArray_real32_T *b)
{
  float *b_data;
  int i;
  i = b->size[0];
  b->size[0] = varargin_1;
  emxEnsureCapacity_real32_T(b, i);
  b_data = b->data;
  for (i = 0; i < varargin_1; i++) {
    b_data[i] = a;
  }
}

/*
 * Arguments    : float a
 *                double varargin_1
 *                emxArray_real32_T *b
 * Return Type  : void
 */
void c_repmat(float a, double varargin_1, emxArray_real32_T *b)
{
  float *b_data;
  int i;
  int loop_ub_tmp;
  loop_ub_tmp = (int)varargin_1;
  i = b->size[0];
  b->size[0] = (int)varargin_1;
  emxEnsureCapacity_real32_T(b, i);
  b_data = b->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    b_data[i] = a;
  }
}

/*
 * Arguments    : const emxArray_boolean_T *a
 *                emxArray_boolean_T *b
 * Return Type  : void
 */
void d_repmat(const emxArray_boolean_T *a, emxArray_boolean_T *b)
{
  int jtilecol;
  int k;
  int nrows;
  boolean_T *b_data;
  nrows = b->size[0] * b->size[1];
  b->size[0] = a->size[0];
  b->size[1] = 2;
  emxEnsureCapacity_boolean_T(b, nrows);
  b_data = b->data;
  nrows = a->size[0];
  for (jtilecol = 0; jtilecol < 2; jtilecol++) {
    int ibtile;
    ibtile = jtilecol * nrows;
    for (k = 0; k < nrows; k++) {
      b_data[ibtile + k] = true;
    }
  }
}

/*
 * Arguments    : int varargin_1
 *                emxArray_real32_T *b
 * Return Type  : void
 */
void e_repmat(int varargin_1, emxArray_real32_T *b)
{
  float *b_data;
  int i;
  i = b->size[0];
  b->size[0] = varargin_1;
  emxEnsureCapacity_real32_T(b, i);
  b_data = b->data;
  for (i = 0; i < varargin_1; i++) {
    b_data[i] = 0.0F;
  }
}

/*
 * Arguments    : double varargin_1
 *                emxArray_real32_T *b
 * Return Type  : void
 */
void f_repmat(double varargin_1, emxArray_real32_T *b)
{
  static const float fv[11] = {0.8192F,  0.0376F, 0.0239F,    0.0377F,
                               -0.0023F, 0.0049F, 1.6571F,    0.0027F,
                               0.8521F,  2.1909F, 496.875885F};
  float *b_data;
  int i;
  int ibmat;
  int itilerow;
  int jcol;
  i = (int)varargin_1;
  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1;
  b->size[1] = 11;
  emxEnsureCapacity_real32_T(b, ibmat);
  b_data = b->data;
  for (jcol = 0; jcol < 11; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < i; itilerow++) {
      b_data[ibmat + itilerow] = fv[jcol];
    }
  }
}

/*
 * Arguments    : double varargin_1
 *                emxArray_real32_T *b
 * Return Type  : void
 */
void g_repmat(double varargin_1, emxArray_real32_T *b)
{
  static const float fv[12] = {0.8192F,  0.0376F, 0.0239F,     0.0377F,
                               -0.0023F, 0.0049F, 1.6571F,     0.0027F,
                               0.8521F,  2.1909F, 496.875885F, 92.4333F};
  float *b_data;
  int i;
  int ibmat;
  int itilerow;
  int jcol;
  i = (int)varargin_1;
  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1;
  b->size[1] = 12;
  emxEnsureCapacity_real32_T(b, ibmat);
  b_data = b->data;
  for (jcol = 0; jcol < 12; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < i; itilerow++) {
      b_data[ibmat + itilerow] = fv[jcol];
    }
  }
}

/*
 * Arguments    : double varargin_1
 *                emxArray_real32_T *b
 * Return Type  : void
 */
void h_repmat(double varargin_1, emxArray_real32_T *b)
{
  static const float fv[13] = {
      0.8192F, 0.0376F, 0.0239F, 0.0377F,     -0.0023F, 0.0049F, 1.6571F,
      0.0027F, 0.8521F, 2.1909F, 496.875885F, 92.4333F, 0.5755F};
  float *b_data;
  int i;
  int ibmat;
  int itilerow;
  int jcol;
  i = (int)varargin_1;
  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1;
  b->size[1] = 13;
  emxEnsureCapacity_real32_T(b, ibmat);
  b_data = b->data;
  for (jcol = 0; jcol < 13; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < i; itilerow++) {
      b_data[ibmat + itilerow] = fv[jcol];
    }
  }
}

/*
 * Arguments    : double varargin_1
 *                emxArray_real32_T *b
 * Return Type  : void
 */
void i_repmat(double varargin_1, emxArray_real32_T *b)
{
  static const float fv[17] = {
      0.8192F, 0.0376F, 0.0239F,     0.0377F,  0.0223F, 0.3428F,
      0.3357F, 2.8675F, -0.0023F,    0.0049F,  1.6571F, 0.0027F,
      0.8521F, 2.1909F, 496.875885F, 92.4333F, 0.5755F};
  float *b_data;
  int i;
  int ibmat;
  int itilerow;
  int jcol;
  i = (int)varargin_1;
  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1;
  b->size[1] = 17;
  emxEnsureCapacity_real32_T(b, ibmat);
  b_data = b->data;
  for (jcol = 0; jcol < 17; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < i; itilerow++) {
      b_data[ibmat + itilerow] = fv[jcol];
    }
  }
}

/*
 * Arguments    : double varargin_1
 *                emxArray_real32_T *b
 * Return Type  : void
 */
void repmat(double varargin_1, emxArray_real32_T *b)
{
  static const float fv[4] = {0.8192F, 0.0376F, 0.0239F, 0.0377F};
  float *b_data;
  int i;
  int ibmat;
  int itilerow;
  int jcol;
  i = (int)varargin_1;
  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1;
  b->size[1] = 4;
  emxEnsureCapacity_real32_T(b, ibmat);
  b_data = b->data;
  for (jcol = 0; jcol < 4; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < i; itilerow++) {
      b_data[ibmat + itilerow] = fv[jcol];
    }
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
