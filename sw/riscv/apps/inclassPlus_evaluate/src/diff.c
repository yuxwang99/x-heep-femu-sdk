/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "diff.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  double d;
  double tmp1;
  double work_data_idx_0;
  int dimSize;
  int ixLead;
  int iyLead;
  int m;
  dimSize = x->size[0];
  if (x->size[0] == 0) {
    y->size[0] = 0;
  } else {
    ixLead = x->size[0] - 1;
    if (ixLead >= 1) {
      ixLead = 1;
    }

    if (ixLead < 1) {
      y->size[0] = 0;
    } else {
      ixLead = y->size[0];
      y->size[0] = x->size[0] - 1;
      emxEnsureCapacity_real_T(y, ixLead);
      if (x->size[0] - 1 != 0) {
        ixLead = 1;
        iyLead = 0;
        work_data_idx_0 = x->data[0];
        for (m = 2; m <= dimSize; m++) {
          tmp1 = x->data[ixLead];
          d = tmp1;
          tmp1 -= work_data_idx_0;
          work_data_idx_0 = d;
          ixLead++;
          y->data[iyLead] = tmp1;
          iyLead++;
        }
      }
    }
  }
}

void c_diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  double d;
  double tmp1;
  double work_data_idx_0;
  int dimSize;
  int ixLead;
  int iyLead;
  int m;
  dimSize = x->size[1];
  if (x->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    ixLead = x->size[1] - 1;
    if (ixLead >= 1) {
      ixLead = 1;
    }

    if (ixLead < 1) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else {
      ixLead = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = x->size[1] - 1;
      emxEnsureCapacity_real_T(y, ixLead);
      if (x->size[1] - 1 != 0) {
        ixLead = 1;
        iyLead = 0;
        work_data_idx_0 = x->data[0];
        for (m = 2; m <= dimSize; m++) {
          tmp1 = x->data[ixLead];
          d = tmp1;
          tmp1 -= work_data_idx_0;
          work_data_idx_0 = d;
          ixLead++;
          y->data[iyLead] = tmp1;
          iyLead++;
        }
      }
    }
  }
}

void diff(const double x[9], double y[8])
{
  double tmp2;
  double work;
  int ixLead;
  int iyLead;
  int m;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 8; m++) {
    tmp2 = work;
    work = x[ixLead];
    y[iyLead] = x[ixLead] - tmp2;
    ixLead++;
    iyLead++;
  }
}

/* End of code generation (diff.c) */
