/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Lorenz_plot.c
 *
 * Code generation for function 'Lorenz_plot'
 *
 */

/* Include files */
#include "Lorenz_plot.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_rtwutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include "vvarstd.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void Lorenz_plot(const double R_R_interval_data[], const int R_R_interval_size[2],
                 int Wind_Siz, emxArray_real_T *CSI, emxArray_real_T *Mod_CSI,
                 emxArray_real_T *CVI, emxArray_real_T *HR_diff)
{
  static double x_data[400];
  emxArray_real_T b_x_data;
  emxArray_real_T c_x_data;
  emxArray_real_T *Trav_L;
  double d;
  double y;
  long i1;
  int R_R_interval[1];
  int b_i;
  int b_loop_ub;
  int i;
  int i2;
  int i3;
  int loop_ub;
  int qY;
  y = rt_roundd_snf((double)R_R_interval_size[1] / (double)Wind_Siz);
  if (y < 2.147483648E+9) {
    if (y >= -2.147483648E+9) {
      loop_ub = (int)y;
    } else {
      loop_ub = MIN_int32_T;
    }
  } else if (y >= 2.147483648E+9) {
    loop_ub = MAX_int32_T;
  } else {
    loop_ub = 0;
  }

  i = CSI->size[0] * CSI->size[1];
  CSI->size[0] = 1;
  CSI->size[1] = loop_ub;
  emxEnsureCapacity_real_T(CSI, i);
  for (i = 0; i < loop_ub; i++) {
    CSI->data[i] = 0.0;
  }

  i = CVI->size[0] * CVI->size[1];
  CVI->size[0] = 1;
  CVI->size[1] = loop_ub;
  emxEnsureCapacity_real_T(CVI, i);
  for (i = 0; i < loop_ub; i++) {
    CVI->data[i] = 0.0;
  }

  i = Mod_CSI->size[0] * Mod_CSI->size[1];
  Mod_CSI->size[0] = 1;
  Mod_CSI->size[1] = loop_ub;
  emxEnsureCapacity_real_T(Mod_CSI, i);
  for (i = 0; i < loop_ub; i++) {
    Mod_CSI->data[i] = 0.0;
  }

  i = HR_diff->size[0] * HR_diff->size[1];
  HR_diff->size[0] = 1;
  HR_diff->size[1] = loop_ub;
  emxEnsureCapacity_real_T(HR_diff, i);
  for (i = 0; i < loop_ub; i++) {
    HR_diff->data[i] = 0.0;
  }

  if (R_R_interval_size[1] > 1) {
    emxInit_real_T(&Trav_L, 2);
    i = Trav_L->size[0] * Trav_L->size[1];
    Trav_L->size[0] = 1;
    Trav_L->size[1] = loop_ub;
    emxEnsureCapacity_real_T(Trav_L, i);
    i = CSI->size[0] * CSI->size[1];
    CSI->size[0] = 1;
    CSI->size[1] = loop_ub;
    emxEnsureCapacity_real_T(CSI, i);
    i = Mod_CSI->size[0] * Mod_CSI->size[1];
    Mod_CSI->size[0] = 1;
    Mod_CSI->size[1] = loop_ub;
    emxEnsureCapacity_real_T(Mod_CSI, i);
    i = CVI->size[0] * CVI->size[1];
    CVI->size[0] = 1;
    CVI->size[1] = loop_ub;
    emxEnsureCapacity_real_T(CVI, i);
    i = HR_diff->size[0] * HR_diff->size[1];
    HR_diff->size[0] = 1;
    HR_diff->size[1] = loop_ub;
    emxEnsureCapacity_real_T(HR_diff, i);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i1 = (long)b_i * Wind_Siz;
      if (i1 > 2147483647L) {
        i1 = 2147483647L;
      } else {
        if (i1 < -2147483648L) {
          i1 = -2147483648L;
        }
      }

      if ((int)i1 > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = (int)i1 + 1;
      }

      i1 = (long)(b_i + 1) * Wind_Siz;
      if (i1 > 2147483647L) {
        i1 = 2147483647L;
      } else {
        if (i1 < -2147483648L) {
          i1 = -2147483648L;
        }
      }

      if (qY > (int)i1) {
        i = -1;
        qY = -1;
      } else {
        i = qY - 2;
        qY = (int)i1 - 1;
      }

      i2 = (short)(qY - i);
      if (1 > i2 - 1) {
        b_loop_ub = 0;
      } else {
        b_loop_ub = (short)(qY - i) - 1;
      }

      qY = (2 <= i2);

      /*         %% Get the sd1 */
      /*          sd1 = [sd1,1000*(std((sqrt(2)/2)*R_pks_diff))]; */
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        x_data[i3] = 0.70710678118654757 * (R_R_interval_data[(i + i3) + 1] -
          R_R_interval_data[((i + qY) + i3) + 1]);
      }

      R_R_interval[0] = b_loop_ub;

      /*         %% Calculate the transverse length (T) as four times  the  Sd1 */
      /*          Trav_L = [Trav_L,4*sd1(i)]; */
      b_x_data.data = &x_data[0];
      b_x_data.size = &R_R_interval[0];
      b_x_data.allocatedSize = 400;
      b_x_data.numDimensions = 1;
      b_x_data.canFreeData = false;
      Trav_L->data[b_i] = 4.0 * (1000.0 * vvarstd(&b_x_data, b_loop_ub));

      /*         %% Get the sd2 */
      /*          sd2 = [sd2,1000*(std((sqrt(2)/2)*R_pks_add))]; */
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        x_data[i3] = 0.70710678118654757 * (R_R_interval_data[(i + i3) + 1] +
          R_R_interval_data[((i + qY) + i3) + 1]);
      }

      R_R_interval[0] = b_loop_ub;

      /*         %% Calculate the longitudinal length (L) as four times  the  Sd2 */
      /*          Long_L = [Long_L,4*sd2(i)]; */
      c_x_data.data = &x_data[0];
      c_x_data.size = &R_R_interval[0];
      c_x_data.allocatedSize = 400;
      c_x_data.numDimensions = 1;
      c_x_data.canFreeData = false;
      y = 4.0 * (1000.0 * vvarstd(&c_x_data, b_loop_ub));

      /*         %% Calculate the Cardiac  Sympathetic  Index (CSI) */
      /*          CSI = [CSI,Long_L(i)/Trav_L(i)]; */
      d = Trav_L->data[b_i];
      CSI->data[b_i] = y / d;

      /*         %% Calculate the modified CSI: This one emphasize the longitudinal parameter */
      /*          Mod_CSI = [Mod_CSI,(Long_L(i).^2)/Trav_L(i)]; */
      Mod_CSI->data[b_i] = y * y / d;

      /*         %% Calculate the Cardiac Vagal Index (CVI) */
      /*          CVI = [CVI,log10(Long_L(i)*Trav_L(i))]; */
      CVI->data[b_i] = log10(y * d);

      /*  Heart rate differential method */
      /*          HR_diff = [HR_diff,sum(0.5.*(RR_inter_Wind(3:end)-RR_inter_Wind(1:end-2)))]; */
      if (3 > i2) {
        qY = 0;
        i2 = 0;
      } else {
        qY = 2;
      }

      b_loop_ub = i2 - qY;
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        x_data[i2] = 0.5 * (R_R_interval_data[((i + qY) + i2) + 1] -
                            R_R_interval_data[(i + i2) + 1]);
      }

      if (b_loop_ub == 0) {
        y = 0.0;
      } else {
        y = x_data[0];
        for (qY = 2; qY <= b_loop_ub; qY++) {
          y += x_data[qY - 1];
        }
      }

      HR_diff->data[b_i] = y;
    }

    emxFree_real_T(&Trav_L);
  }
}

/* End of code generation (Lorenz_plot.c) */
