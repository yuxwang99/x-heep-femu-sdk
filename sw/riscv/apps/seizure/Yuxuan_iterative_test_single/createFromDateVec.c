/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: createFromDateVec.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "createFromDateVec.h"
#include "floor.h"
#include "isfinite.h"
#include "plus.h"
#include "rt_nonfinite.h"
#include "times.h"

/* Function Declarations */
static double b_divmod(double a, double *n_rem);

static creal_T createFromDateVecUTC(const double fieldValues[7]);

static double ymd2days(double y, double mo, double d);

/* Function Definitions */
/*
 * Arguments    : double a
 *                double *n_rem
 * Return Type  : double
 */
static double b_divmod(double a, double *n_rem)
{
  double n;
  n = c_floor(a / 12.0);
  *n_rem = a - n * 12.0;
  return n;
}

/*
 * Arguments    : const double fieldValues[7]
 * Return Type  : creal_T
 */
static creal_T createFromDateVecUTC(const double fieldValues[7])
{
  creal_T t;
  double check;
  double fracSecs;
  double second;
  second = fieldValues[5];
  fracSecs = fieldValues[6];
  check = (((((fieldValues[0] + fieldValues[1]) + fieldValues[2]) +
             fieldValues[3]) +
            fieldValues[4]) +
           fieldValues[5]) +
          fieldValues[6];
  if (c_isfinite(check)) {
    creal_T dc;
    if ((fieldValues[6] < 0.0) || (fieldValues[6] >= 1000.0)) {
      fracSecs = c_floor(fieldValues[6] / 1000.0);
      second = fieldValues[5] + fracSecs;
      fracSecs = fieldValues[6] - fracSecs * 1000.0;
    }
    dc.re = ymd2days(fieldValues[0], fieldValues[1], fieldValues[2]);
    dc.im = 0.0;
    t = plus(plus(plus(times(dc),
                       (60.0 * fieldValues[3] + fieldValues[4]) * 60000.0),
                  second * 1000.0),
             fracSecs);
  } else {
    t.re = check;
    t.im = 0.0;
  }
  return t;
}

/*
 * Arguments    : double y
 *                double mo
 *                double d
 * Return Type  : double
 */
static double ymd2days(double y, double mo, double d)
{
  double b_mo;
  if ((mo < 1.0) || (mo > 12.0)) {
    double k;
    k = b_divmod(mo - 1.0, &b_mo);
    y += k;
    mo = b_mo + 1.0;
  }
  if (mo < 3.0) {
    y--;
    mo += 9.0;
  } else {
    mo -= 3.0;
  }
  return ((((((365.0 * y + c_floor(y / 4.0)) - c_floor(y / 100.0)) +
             c_floor(y / 400.0)) +
            c_floor((153.0 * mo + 2.0) / 5.0)) +
           d) +
          60.0) -
         719529.0;
}

/*
 * Arguments    : const double inData[7]
 * Return Type  : creal_T
 */
creal_T createFromDateVec(const double inData[7])
{
  return createFromDateVecUTC(inData);
}

/*
 * File trailer for createFromDateVec.c
 *
 * [EOF]
 */
