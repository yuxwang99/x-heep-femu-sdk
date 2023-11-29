/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ismember.c
 *
 * Code generation for function 'ismember'
 *
 */

/* Include files */
#include "ismember.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void local_ismember(const double a[2], const double s[2], boolean_T tf[2], int
                    loc[2])
{
  double absx;
  int exponent;
  int i;
  boolean_T exitg1;
  tf[0] = false;
  loc[0] = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    absx = fabs(s[i] / 2.0);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = ldexp(1.0, exponent - 53);
      }
    } else {
      absx = rtNaN;
    }

    if ((fabs(s[i] - a[0]) < absx) || (rtIsInf(a[0]) && rtIsInf(s[i]) && ((a[0] >
           0.0) == (s[i] > 0.0)))) {
      tf[0] = true;
      loc[0] = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }

  tf[1] = false;
  loc[1] = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    absx = fabs(s[i] / 2.0);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = ldexp(1.0, exponent - 53);
      }
    } else {
      absx = rtNaN;
    }

    if ((fabs(s[i] - a[1]) < absx) || (rtIsInf(a[1]) && rtIsInf(s[i]) && ((a[1] >
           0.0) == (s[i] > 0.0)))) {
      tf[1] = true;
      loc[1] = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }
}

/* End of code generation (ismember.c) */
