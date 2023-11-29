/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationModel.c
 *
 * Code generation for function 'CompactClassificationModel'
 *
 */

/* Include files */
#include "CompactClassificationModel.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void c_CompactClassificationModel_ma(const double obj_ClassNames[2], const
  double obj_Prior[2], const double scores_data[], const int scores_size[2],
  double labels_data[], int labels_size[1])
{
  static double classnum_data[400];
  double d;
  int b_size_idx_0;
  int i1;
  int i2;
  int ix;
  int iy;
  int j;
  int notNaN_size_idx_0;
  boolean_T b_data[800];
  boolean_T notNaN_data[400];
  boolean_T exitg1;
  b_size_idx_0 = scores_size[0];
  i2 = scores_size[0] * scores_size[1];
  for (ix = 0; ix < i2; ix++) {
    b_data[ix] = rtIsNaN(scores_data[ix]);
  }

  notNaN_size_idx_0 = (short)scores_size[0];
  i2 = (short)scores_size[0];
  for (ix = 0; ix < i2; ix++) {
    notNaN_data[ix] = true;
  }

  i2 = scores_size[0];
  iy = -1;
  i1 = 0;
  for (j = 0; j < b_size_idx_0; j++) {
    i1++;
    i2++;
    iy++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && ((b_size_idx_0 > 0) && (ix <= i2))) {
      if (!b_data[ix - 1]) {
        notNaN_data[iy] = false;
        exitg1 = true;
      } else {
        ix += b_size_idx_0;
      }
    }
  }

  for (ix = 0; ix < notNaN_size_idx_0; ix++) {
    notNaN_data[ix] = !notNaN_data[ix];
  }

  if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
        (obj_Prior[1])))) {
    iy = 1;
  } else {
    iy = 0;
  }

  i2 = scores_size[0];
  for (ix = 0; ix < i2; ix++) {
    classnum_data[ix] = rtNaN;
  }

  for (i1 = 0; i1 < notNaN_size_idx_0; i1++) {
    if (notNaN_data[i1]) {
      d = scores_data[i1 + scores_size[0]];
      if ((scores_data[i1] < d) || (rtIsNaN(scores_data[i1]) && (!rtIsNaN(d))))
      {
        i2 = 2;
      } else {
        i2 = 1;
      }

      classnum_data[i1] = i2;
    }
  }

  labels_size[0] = (short)scores_size[0];
  i2 = (short)scores_size[0];
  for (ix = 0; ix < i2; ix++) {
    labels_data[ix] = obj_ClassNames[iy];
  }

  for (i1 = 0; i1 < notNaN_size_idx_0; i1++) {
    if (notNaN_data[i1]) {
      d = classnum_data[i1];
      if (d < 4.294967296E+9) {
        ix = (int)d;
      } else {
        ix = 0;
      }

      labels_data[i1] = obj_ClassNames[ix - 1];
    }
  }
}

void c_CompactClassificationModel_mi(const double obj_ClassNames[2], const
  double obj_Prior[2], const double obj_Cost[4], const double scoresIn_data[],
  const int scoresIn_size[2], double labels_data[], int labels_size[1], double
  classnum_data[], int classnum_size[1], double cost_data[], int cost_size[2])
{
  double b_cost_data_tmp;
  double d;
  int b_i;
  int cost_data_tmp;
  int i;
  int m;
  short outsize_idx_0;
  m = scoresIn_size[0];
  cost_size[0] = scoresIn_size[0];
  cost_size[1] = 2;
  for (i = 0; i < m; i++) {
    cost_data_tmp = scoresIn_size[0] + i;
    b_cost_data_tmp = scoresIn_data[cost_data_tmp];
    cost_data[i] = scoresIn_data[i] * obj_Cost[0] + b_cost_data_tmp * obj_Cost[1];
    cost_data[cost_data_tmp] = scoresIn_data[i] * obj_Cost[2] + b_cost_data_tmp *
      obj_Cost[3];
  }

  if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
        (obj_Prior[1])))) {
    cost_data_tmp = 1;
  } else {
    cost_data_tmp = 0;
  }

  classnum_size[0] = scoresIn_size[0];
  b_i = scoresIn_size[0];
  for (i = 0; i < b_i; i++) {
    b_cost_data_tmp = cost_data[i];
    d = cost_data[i + cost_size[0]];
    if ((b_cost_data_tmp > d) || (rtIsNaN(b_cost_data_tmp) && (!rtIsNaN(d)))) {
      m = 2;
    } else {
      m = 1;
    }

    classnum_data[i] = m;
  }

  outsize_idx_0 = (short)scoresIn_size[0];
  labels_size[0] = outsize_idx_0;
  m = outsize_idx_0;
  for (b_i = 0; b_i < m; b_i++) {
    labels_data[b_i] = obj_ClassNames[cost_data_tmp];
  }

  b_i = scoresIn_size[0];
  for (i = 0; i < b_i; i++) {
    labels_data[i] = obj_ClassNames[(int)classnum_data[i] - 1];
  }
}

/* End of code generation (CompactClassificationModel.c) */
