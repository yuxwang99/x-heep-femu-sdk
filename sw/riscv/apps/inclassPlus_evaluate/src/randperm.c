/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randperm.c
 *
 * Code generation for function 'randperm'
 *
 */

/* Include files */
#include "randperm.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void randperm(double p[153])
{
  static double hashTbl[153];
  static double link[153];
  double loc[153];
  double j;
  double newEntry;
  double r;
  double selectedLoc;
  int m;
  short val[153];
  memset(&hashTbl[0], 0, 153U * sizeof(double));
  memset(&link[0], 0, 153U * sizeof(double));
  memset(&val[0], 0, 153U * sizeof(short));
  memset(&loc[0], 0, 153U * sizeof(double));
  newEntry = 1.0;
  for (m = 0; m < 153; m++) {
    selectedLoc = b_rand() * ((30720.0 - ((double)m + 1.0)) + 1.0);
    selectedLoc = floor(selectedLoc);
    if (rtIsNaN(selectedLoc) || rtIsInf(selectedLoc)) {
      r = rtNaN;
    } else if (selectedLoc == 0.0) {
      r = 0.0;
    } else {
      r = fmod(selectedLoc, 153.0);
      if (r == 0.0) {
        r = 0.0;
      }
    }

    j = hashTbl[(int)(r + 1.0) - 1];
    while ((j > 0.0) && (loc[(int)j - 1] != selectedLoc)) {
      j = link[(int)j - 1];
    }

    if (j > 0.0) {
      p[m] = (double)val[(int)j - 1] + 1.0;
    } else {
      p[m] = selectedLoc + 1.0;
      j = newEntry;
      newEntry++;
      loc[(int)j - 1] = selectedLoc;
      link[(int)j - 1] = hashTbl[(int)(r + 1.0) - 1];
      hashTbl[(int)(r + 1.0) - 1] = j;
    }

    if (m + 1 < 153) {
      selectedLoc = hashTbl[(int)fmod(30720.0 - ((double)m + 1.0), 153.0)];
      while ((selectedLoc > 0.0) && (loc[(int)selectedLoc - 1] != 30720.0 -
              ((double)m + 1.0))) {
        selectedLoc = link[(int)selectedLoc - 1];
      }

      if (selectedLoc > 0.0) {
        val[(int)j - 1] = val[(int)selectedLoc - 1];
      } else {
        val[(int)j - 1] = (short)(30719 - m);
      }
    }
  }
}

/* End of code generation (randperm.c) */
