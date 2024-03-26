/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: days2ymd.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:08:49
 */

/* Include Files */
#include "days2ymd.h"
#include "INCLASS_iterative_test_single_rtwutil.h"
#include "floor.h"
#include "idivide.h"
#include "rem.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double days
 *                double *m
 *                double *d
 * Return Type  : double
 */
double days2ymd(double days, double *m, double *d)
{
  double dg;
  double y;
  if (((days + 719529.0) - 61.0 >= 0.0) &&
      ((days + 719529.0) - 61.0 <= 2.147483647E+9)) {
    long i1;
    long i2;
    int b_qY;
    int i;
    int ia_quot;
    int ic_quot;
    int ig_rem;
    int qY;
    dg = rt_roundd_snf((days + 719529.0) - 61.0);
    if (dg < 2.147483648E+9) {
      if (dg >= -2.147483648E+9) {
        i = (int)dg;
      } else {
        i = MIN_int32_T;
      }
    } else if (dg >= 2.147483648E+9) {
      i = MAX_int32_T;
    } else {
      i = 0;
    }
    ig_rem = b_rem(i);
    ic_quot = idivide(ig_rem, 36524.0);
    qY = d_rem(ig_rem);
    if (ic_quot > 3) {
      ic_quot = 3;
      if (ig_rem < -2147374076) {
        qY = MIN_int32_T;
      } else {
        qY = ig_rem - 109572;
      }
    }
    ig_rem = f_rem(qY);
    ia_quot = idivide(ig_rem, 365.0);
    b_qY = h_rem(ig_rem);
    if (ia_quot > 3) {
      ia_quot = 3;
      if (ig_rem < -2147482553) {
        b_qY = MIN_int32_T;
      } else {
        b_qY = ig_rem - 1095;
      }
    }
    i1 = idivide(i, 146097.0) * 400L;
    if (i1 > 2147483647L) {
      i1 = 2147483647L;
    } else if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
    i2 = ic_quot * 100L;
    if (i2 > 2147483647L) {
      i2 = 2147483647L;
    } else if (i2 < -2147483648L) {
      i2 = -2147483648L;
    }
    if (((int)i1 < 0) && ((int)i2 < MIN_int32_T - (int)i1)) {
      ic_quot = MIN_int32_T;
    } else if (((int)i1 > 0) && ((int)i2 > MAX_int32_T - (int)i1)) {
      ic_quot = MAX_int32_T;
    } else {
      ic_quot = (int)i1 + (int)i2;
    }
    i = idivide(qY, 1461.0);
    if (i > 536870911) {
      ig_rem = MAX_int32_T;
    } else if (i <= -536870912) {
      ig_rem = MIN_int32_T;
    } else {
      ig_rem = i << 2;
    }
    if ((ic_quot < 0) && (ig_rem < MIN_int32_T - ic_quot)) {
      qY = MIN_int32_T;
    } else if ((ic_quot > 0) && (ig_rem > MAX_int32_T - ic_quot)) {
      qY = MAX_int32_T;
    } else {
      qY = ic_quot + ig_rem;
    }
    if ((qY < 0) && (ia_quot < MIN_int32_T - qY)) {
      qY = MIN_int32_T;
    } else if ((qY > 0) && (ia_quot > MAX_int32_T - qY)) {
      qY = MAX_int32_T;
    } else {
      qY += ia_quot;
    }
    y = qY;
    i1 = b_qY * 5L;
    if (i1 > 2147483647L) {
      i1 = 2147483647L;
    } else if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
    if ((int)i1 > 2147483339) {
      qY = MAX_int32_T;
    } else {
      qY = (int)i1 + 308;
    }
    ig_rem = idivide(qY, 153.0);
    if (ig_rem < -2147483646) {
      qY = MIN_int32_T;
    } else {
      qY = ig_rem - 2;
    }
    dg = qY;
    if (qY > 2147483643) {
      qY = MAX_int32_T;
    } else {
      qY += 4;
    }
    i1 = qY * 153L;
    if (i1 > 2147483647L) {
      i1 = 2147483647L;
    } else if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
    ig_rem = idivide((int)i1, 5.0);
    if ((b_qY >= 0) && (ig_rem < b_qY - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((b_qY < 0) && (ig_rem > b_qY - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = b_qY - ig_rem;
    }
    if (qY > 2147483525) {
      qY = MAX_int32_T;
    } else {
      qY += 122;
    }
    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }
    *d = qY;
  } else {
    double a;
    double b;
    double c;
    double da;
    double g;
    g = c_floor(((days + 719529.0) - 61.0) / 146097.0);
    dg = ((days + 719529.0) - 61.0) - g * 146097.0;
    c = c_floor(dg / 36524.0);
    if (c > 3.0) {
      c = 3.0;
    }
    dg -= c * 36524.0;
    b = c_floor(dg / 1461.0);
    dg -= b * 1461.0;
    a = c_floor(dg / 365.0);
    if (a > 3.0) {
      a = 3.0;
    }
    da = dg - a * 365.0;
    y = ((g * 400.0 + c * 100.0) + b * 4.0) + a;
    dg = c_floor((da * 5.0 + 308.0) / 153.0) - 2.0;
    *d = ((da - c_floor((dg + 4.0) * 153.0 / 5.0)) + 122.0) + 1.0;
  }
  if (dg > 9.0) {
    y++;
    *m = (dg + 2.0) - 11.0;
  } else {
    *m = (dg + 2.0) + 1.0;
  }
  return y;
}

/*
 * File trailer for days2ymd.c
 *
 * [EOF]
 */
