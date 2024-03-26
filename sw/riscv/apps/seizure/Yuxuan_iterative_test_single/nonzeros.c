/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: nonzeros.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "nonzeros.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "nnz.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *s
 *                emxArray_real32_T *v
 * Return Type  : void
 */
void nonzeros(const emxArray_real32_T *s, emxArray_real32_T *v)
{
  const float *s_data;
  float *v_data;
  int i;
  int k;
  int n;
  s_data = s->data;
  n = s->size[0];
  i = v->size[0];
  v->size[0] = intnnz(s);
  emxEnsureCapacity_real32_T(v, i);
  v_data = v->data;
  i = -1;
  for (k = 0; k < n; k++) {
    if (s_data[k] != 0.0F) {
      i++;
      v_data[i] = s_data[k];
    }
  }
}

/*
 * File trailer for nonzeros.c
 *
 * [EOF]
 */
