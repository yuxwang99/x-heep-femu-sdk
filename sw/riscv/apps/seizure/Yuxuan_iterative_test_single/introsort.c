/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: introsort.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "introsort.h"
#include "Yuxuan_iterative_test_single_internal_types.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "nextpow2.h"
#include "rt_nonfinite.h"
#include "sortpartition.h"
#include "stack.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_int32_T *x
 *                int xend
 * Return Type  : void
 */
void introsort(emxArray_int32_T *x, int xend)
{
  struct_T st_d_data[120];
  struct_T frame;
  int st_n;
  if (xend > 1) {
    if (xend <= 32) {
      insertionsort(x, 1, xend);
    } else {
      int MAXDEPTH;
      MAXDEPTH = (nextpow2(xend) - 1) << 1;
      frame.xstart = 1;
      frame.xend = xend;
      frame.depth = 0;
      stack_stack(frame, MAXDEPTH << 1, st_d_data, &st_n);
      st_d_data[st_n] = frame;
      st_n++;
      while (st_n > 0) {
        frame = st_d_data[st_n - 1];
        st_n--;
        if ((frame.xend - frame.xstart) + 1 <= 32) {
          insertionsort(x, frame.xstart, frame.xend);
        } else if (frame.depth == MAXDEPTH) {
          b_heapsort(x, frame.xstart, frame.xend);
        } else {
          int st_d_size;
          st_d_size = sortpartition(x, frame.xstart, frame.xend);
          if (st_d_size + 1 < frame.xend) {
            st_d_data[st_n].xstart = st_d_size + 1;
            st_d_data[st_n].xend = frame.xend;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
          if (frame.xstart < st_d_size) {
            st_d_data[st_n].xstart = frame.xstart;
            st_d_data[st_n].xend = st_d_size;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
        }
      }
    }
  }
}

/*
 * File trailer for introsort.c
 *
 * [EOF]
 */
