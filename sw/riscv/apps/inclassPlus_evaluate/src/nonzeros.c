/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nonzeros.c
 *
 * Code generation for function 'nonzeros'
 *
 */

/* Include files */
#include "nonzeros.h"
#include "profile_Yuxuan_iteration_emxutil.h"
#include "profile_Yuxuan_iteration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void nonzeros(const emxArray_real_T *s, emxArray_real_T *v)
{
  int b_i;
  int i;
  int k;
  int n;
  n = s->size[0];
  i = 0;
  b_i = s->size[0];
  for (k = 0; k < b_i; k++) {
    if (s->data[k] != 0.0) {
      i++;
    }
  }

  b_i = v->size[0];
  v->size[0] = i;
  emxEnsureCapacity_real_T(v, b_i);
  i = -1;
  for (k = 0; k < n; k++) {
    if (s->data[k] != 0.0) {
      i++;
      v->data[i] = s->data[k];
    }
  }
}

/* End of code generation (nonzeros.c) */
