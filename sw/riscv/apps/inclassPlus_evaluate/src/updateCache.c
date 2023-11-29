/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateCache.c
 *
 * Code generation for function 'updateCache'
 *
 */

/* Include files */
#include "updateCache.h"
#include "profile_Yuxuan_iteration_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void updateCache(const double learnerscore_data[], const int learnerscore_size[2],
                 double cachedScore_data[], const int cachedScore_size[2],
                 double cachedWeights_data[], boolean_T *cached, const char
                 combinerName[15], const boolean_T obsIndices_data[], const int
                 obsIndices_size[1], double score_data[], int score_size[2])
{
  static double b_cachedScore_data[800];
  static double b_cachedWeights_data[400];
  static short b_tmp_data[400];
  static short c_tmp_data[400];
  static short tmp_data[400];
  static const char b_cv[15] = { 'w', 'e', 'i', 'g', 'h', 't', 'e', 'd', 'a',
    'v', 'e', 'r', 'a', 'g', 'e' };

  double x_tmp;
  int exitg1;
  int i;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  boolean_T x[2];
  boolean_T b_bool;
  boolean_T exitg2;
  score_size[0] = cachedScore_size[0];
  score_size[1] = 2;
  loop_ub = cachedScore_size[0] * cachedScore_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&score_data[0], &cachedScore_data[0], loop_ub * sizeof(double));
  }

  if (!*cached) {
    *cached = true;
    loop_ub = obsIndices_size[0] - 1;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (obsIndices_data[i]) {
        tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    loop_ub = obsIndices_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (obsIndices_data[i]) {
        trueCount++;
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      b_cachedScore_data[partialTrueCount] =
        cachedScore_data[b_tmp_data[partialTrueCount] - 1] +
        learnerscore_data[tmp_data[partialTrueCount] - 1];
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      b_cachedScore_data[partialTrueCount + trueCount] = cachedScore_data
        [(b_tmp_data[partialTrueCount] + cachedScore_size[0]) - 1] +
        learnerscore_data[(tmp_data[partialTrueCount] + learnerscore_size[0]) -
        1];
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      cachedScore_data[b_tmp_data[partialTrueCount] - 1] =
        b_cachedScore_data[partialTrueCount];
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      cachedScore_data[(b_tmp_data[partialTrueCount] + cachedScore_size[0]) - 1]
        = b_cachedScore_data[partialTrueCount + trueCount];
    }

    loop_ub = obsIndices_size[0] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (obsIndices_data[i]) {
        trueCount++;
        c_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      b_cachedWeights_data[partialTrueCount] =
        cachedWeights_data[c_tmp_data[partialTrueCount] - 1] + 1.0;
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      cachedWeights_data[c_tmp_data[partialTrueCount] - 1] =
        b_cachedWeights_data[partialTrueCount];
    }

    b_bool = false;
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 15) {
        if (cv[(unsigned char)combinerName[loop_ub]] != cv[(int)b_cv[loop_ub]])
        {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (b_bool) {
      partialTrueCount = cachedScore_size[0];
      for (i = 0; i < partialTrueCount; i++) {
        if (cachedWeights_data[i] == 0.0) {
          x[0] = (cachedScore_data[i] == 0.0);
          x_tmp = cachedScore_data[i + cachedScore_size[0]];
          x[1] = (x_tmp == 0.0);
          b_bool = true;
          loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (loop_ub < 2)) {
            if (!x[loop_ub]) {
              b_bool = false;
              exitg2 = true;
            } else {
              loop_ub++;
            }
          }

          if (b_bool) {
            score_data[i] = rtNaN;
            score_data[i + score_size[0]] = rtNaN;
          } else {
            x[0] = (cachedScore_data[i] < 0.0);
            x[1] = (x_tmp < 0.0);
            b_bool = true;
            loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (loop_ub < 2)) {
              if (!x[loop_ub]) {
                b_bool = false;
                exitg2 = true;
              } else {
                loop_ub++;
              }
            }

            if (b_bool) {
              score_data[i] = rtMinusInf;
              score_data[i + score_size[0]] = rtMinusInf;
            } else {
              score_data[i] = rtInf;
              score_data[i + score_size[0]] = rtInf;
            }
          }
        } else {
          score_data[i] = cachedScore_data[i] / cachedWeights_data[i];
          score_data[i + score_size[0]] = cachedScore_data[i + cachedScore_size
            [0]] / cachedWeights_data[i];
        }
      }
    } else {
      partialTrueCount = cachedScore_size[0];
      for (i = 0; i < partialTrueCount; i++) {
        score_data[i] = cachedScore_data[i];
        score_data[i + score_size[0]] = cachedScore_data[i + cachedScore_size[0]];
      }
    }
  }
}

/* End of code generation (updateCache.c) */
