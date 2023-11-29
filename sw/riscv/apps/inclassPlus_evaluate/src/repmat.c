/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_repmat(const double a[3], double varargin_1, double b_data[], int b_size
              [2])
{
  int ibmat;
  int itilerow;
  int jcol;
  int ntilerows;
  b_size[0] = (short)(int)varargin_1;
  b_size[1] = 3;
  ntilerows = (int)varargin_1;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b_data[ibmat + itilerow] = a[jcol];
    }
  }
}

void c_repmat(const double a[5], double varargin_1, double b_data[], int b_size
              [2])
{
  int ibmat;
  int itilerow;
  int jcol;
  int ntilerows;
  b_size[0] = (short)(int)varargin_1;
  b_size[1] = 5;
  ntilerows = (int)varargin_1;
  for (jcol = 0; jcol < 5; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b_data[ibmat + itilerow] = a[jcol];
    }
  }
}

void d_repmat(const double a[13], double varargin_1, double b_data[], int
              b_size[2])
{
  int ibmat;
  int itilerow;
  int jcol;
  int ntilerows;
  b_size[0] = (short)(int)varargin_1;
  b_size[1] = 13;
  ntilerows = (int)varargin_1;
  for (jcol = 0; jcol < 13; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b_data[ibmat + itilerow] = a[jcol];
    }
  }
}

void e_repmat(const double a[17], double varargin_1, double b_data[], int
              b_size[2])
{
  int ibmat;
  int itilerow;
  int jcol;
  int ntilerows;
  b_size[0] = (short)(int)varargin_1;
  b_size[1] = 17;
  ntilerows = (int)varargin_1;
  for (jcol = 0; jcol < 17; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b_data[ibmat + itilerow] = a[jcol];
    }
  }
}

void repmat(const double a[2], double varargin_1, double b_data[], int b_size[2])
{
  int itilerow;
  int ntilerows;
  b_size[0] = (short)(int)varargin_1;
  b_size[1] = 2;
  ntilerows = (int)varargin_1;
  for (itilerow = 0; itilerow < ntilerows; itilerow++) {
    b_data[itilerow] = a[0];
  }

  for (itilerow = 0; itilerow < ntilerows; itilerow++) {
    b_data[(int)varargin_1 + itilerow] = a[1];
  }
}

/* End of code generation (repmat.c) */
