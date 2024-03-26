/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: findNode.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "findNode.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "isnan.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1658]
 *                const float cutVar[829]
 *                const float cutPoint[829]
 *                const boolean_T nanCutPoints[829]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void ab_findNode(const emxArray_real32_T *X, const float kids[1658],
                 const float cutVar[829], const float cutPoint[829],
                 const boolean_T nanCutPoints[829], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1186]
 *                const float cutVar[593]
 *                const float cutPoint[593]
 *                const boolean_T nanCutPoints[593]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void ac_findNode(const emxArray_real32_T *X, const float kids[1186],
                 const float cutVar[593], const float cutPoint[593],
                 const boolean_T nanCutPoints[593], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2838]
 *                const float cutVar[1419]
 *                const float cutPoint[1419]
 *                const boolean_T nanCutPoints[1419]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void b_findNode(const emxArray_real32_T *X, const float kids[2838],
                const float cutVar[1419], const float cutPoint[1419],
                const boolean_T nanCutPoints[1419], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1302]
 *                const float cutVar[651]
 *                const float cutPoint[651]
 *                const boolean_T nanCutPoints[651]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void bb_findNode(const emxArray_real32_T *X, const float kids[1302],
                 const float cutVar[651], const float cutPoint[651],
                 const boolean_T nanCutPoints[651], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[926]
 *                const float cutVar[463]
 *                const float cutPoint[463]
 *                const boolean_T nanCutPoints[463]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void bc_findNode(const emxArray_real32_T *X, const float kids[926],
                 const float cutVar[463], const float cutPoint[463],
                 const boolean_T nanCutPoints[463], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2866]
 *                const float cutVar[1433]
 *                const float cutPoint[1433]
 *                const boolean_T nanCutPoints[1433]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void c_findNode(const emxArray_real32_T *X, const float kids[2866],
                const float cutVar[1433], const float cutPoint[1433],
                const boolean_T nanCutPoints[1433], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1102]
 *                const float cutVar[551]
 *                const float cutPoint[551]
 *                const boolean_T nanCutPoints[551]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void cb_findNode(const emxArray_real32_T *X, const float kids[1102],
                 const float cutVar[551], const float cutPoint[551],
                 const boolean_T nanCutPoints[551], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1162]
 *                const float cutVar[581]
 *                const float cutPoint[581]
 *                const boolean_T nanCutPoints[581]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void cc_findNode(const emxArray_real32_T *X, const float kids[1162],
                 const float cutVar[581], const float cutPoint[581],
                 const boolean_T nanCutPoints[581], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2990]
 *                const float cutVar[1495]
 *                const float cutPoint[1495]
 *                const boolean_T nanCutPoints[1495]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void d_findNode(const emxArray_real32_T *X, const float kids[2990],
                const float cutVar[1495], const float cutPoint[1495],
                const boolean_T nanCutPoints[1495], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1334]
 *                const float cutVar[667]
 *                const float cutPoint[667]
 *                const boolean_T nanCutPoints[667]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void db_findNode(const emxArray_real32_T *X, const float kids[1334],
                 const float cutVar[667], const float cutPoint[667],
                 const boolean_T nanCutPoints[667], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[3106]
 *                const float cutVar[1553]
 *                const float cutPoint[1553]
 *                const boolean_T nanCutPoints[1553]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void e_findNode(const emxArray_real32_T *X, const float kids[3106],
                const float cutVar[1553], const float cutPoint[1553],
                const boolean_T nanCutPoints[1553], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1214]
 *                const float cutVar[607]
 *                const float cutPoint[607]
 *                const boolean_T nanCutPoints[607]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void eb_findNode(const emxArray_real32_T *X, const float kids[1214],
                 const float cutVar[607], const float cutPoint[607],
                 const boolean_T nanCutPoints[607], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2766]
 *                const float cutVar[1383]
 *                const float cutPoint[1383]
 *                const boolean_T nanCutPoints[1383]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void f_findNode(const emxArray_real32_T *X, const float kids[2766],
                const float cutVar[1383], const float cutPoint[1383],
                const boolean_T nanCutPoints[1383], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1246]
 *                const float cutVar[623]
 *                const float cutPoint[623]
 *                const boolean_T nanCutPoints[623]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void fb_findNode(const emxArray_real32_T *X, const float kids[1246],
                 const float cutVar[623], const float cutPoint[623],
                 const boolean_T nanCutPoints[623], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[3162]
 *                const float cutVar[1581]
 *                const float cutPoint[1581]
 *                const boolean_T nanCutPoints[1581]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void findNode(const emxArray_real32_T *X, const float kids[3162],
              const float cutVar[1581], const float cutPoint[1581],
              const boolean_T nanCutPoints[1581], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2646]
 *                const float cutVar[1323]
 *                const float cutPoint[1323]
 *                const boolean_T nanCutPoints[1323]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void g_findNode(const emxArray_real32_T *X, const float kids[2646],
                const float cutVar[1323], const float cutPoint[1323],
                const boolean_T nanCutPoints[1323], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1078]
 *                const float cutVar[539]
 *                const float cutPoint[539]
 *                const boolean_T nanCutPoints[539]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void gb_findNode(const emxArray_real32_T *X, const float kids[1078],
                 const float cutVar[539], const float cutPoint[539],
                 const boolean_T nanCutPoints[539], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2726]
 *                const float cutVar[1363]
 *                const float cutPoint[1363]
 *                const boolean_T nanCutPoints[1363]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void h_findNode(const emxArray_real32_T *X, const float kids[2726],
                const float cutVar[1363], const float cutPoint[1363],
                const boolean_T nanCutPoints[1363], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1042]
 *                const float cutVar[521]
 *                const float cutPoint[521]
 *                const boolean_T nanCutPoints[521]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void hb_findNode(const emxArray_real32_T *X, const float kids[1042],
                 const float cutVar[521], const float cutPoint[521],
                 const boolean_T nanCutPoints[521], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2530]
 *                const float cutVar[1265]
 *                const float cutPoint[1265]
 *                const boolean_T nanCutPoints[1265]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void i_findNode(const emxArray_real32_T *X, const float kids[2530],
                const float cutVar[1265], const float cutPoint[1265],
                const boolean_T nanCutPoints[1265], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1054]
 *                const float cutVar[527]
 *                const float cutPoint[527]
 *                const boolean_T nanCutPoints[527]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void ib_findNode(const emxArray_real32_T *X, const float kids[1054],
                 const float cutVar[527], const float cutPoint[527],
                 const boolean_T nanCutPoints[527], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2698]
 *                const float cutVar[1349]
 *                const float cutPoint[1349]
 *                const boolean_T nanCutPoints[1349]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void j_findNode(const emxArray_real32_T *X, const float kids[2698],
                const float cutVar[1349], const float cutPoint[1349],
                const boolean_T nanCutPoints[1349], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1086]
 *                const float cutVar[543]
 *                const float cutPoint[543]
 *                const boolean_T nanCutPoints[543]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void jb_findNode(const emxArray_real32_T *X, const float kids[1086],
                 const float cutVar[543], const float cutPoint[543],
                 const boolean_T nanCutPoints[543], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2558]
 *                const float cutVar[1279]
 *                const float cutPoint[1279]
 *                const boolean_T nanCutPoints[1279]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void k_findNode(const emxArray_real32_T *X, const float kids[2558],
                const float cutVar[1279], const float cutPoint[1279],
                const boolean_T nanCutPoints[1279], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[934]
 *                const float cutVar[467]
 *                const float cutPoint[467]
 *                const boolean_T nanCutPoints[467]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void kb_findNode(const emxArray_real32_T *X, const float kids[934],
                 const float cutVar[467], const float cutPoint[467],
                 const boolean_T nanCutPoints[467], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[3222]
 *                const float cutVar[1611]
 *                const float cutPoint[1611]
 *                const boolean_T nanCutPoints[1611]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void l_findNode(const emxArray_real32_T *X, const float kids[3222],
                const float cutVar[1611], const float cutPoint[1611],
                const boolean_T nanCutPoints[1611], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1222]
 *                const float cutVar[611]
 *                const float cutPoint[611]
 *                const boolean_T nanCutPoints[611]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void lb_findNode(const emxArray_real32_T *X, const float kids[1222],
                 const float cutVar[611], const float cutPoint[611],
                 const boolean_T nanCutPoints[611], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2874]
 *                const float cutVar[1437]
 *                const float cutPoint[1437]
 *                const boolean_T nanCutPoints[1437]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void m_findNode(const emxArray_real32_T *X, const float kids[2874],
                const float cutVar[1437], const float cutPoint[1437],
                const boolean_T nanCutPoints[1437], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[914]
 *                const float cutVar[457]
 *                const float cutPoint[457]
 *                const boolean_T nanCutPoints[457]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void mb_findNode(const emxArray_real32_T *X, const float kids[914],
                 const float cutVar[457], const float cutPoint[457],
                 const boolean_T nanCutPoints[457], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2738]
 *                const float cutVar[1369]
 *                const float cutPoint[1369]
 *                const boolean_T nanCutPoints[1369]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void n_findNode(const emxArray_real32_T *X, const float kids[2738],
                const float cutVar[1369], const float cutPoint[1369],
                const boolean_T nanCutPoints[1369], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[902]
 *                const float cutVar[451]
 *                const float cutPoint[451]
 *                const boolean_T nanCutPoints[451]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void nb_findNode(const emxArray_real32_T *X, const float kids[902],
                 const float cutVar[451], const float cutPoint[451],
                 const boolean_T nanCutPoints[451], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2734]
 *                const float cutVar[1367]
 *                const float cutPoint[1367]
 *                const boolean_T nanCutPoints[1367]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void o_findNode(const emxArray_real32_T *X, const float kids[2734],
                const float cutVar[1367], const float cutPoint[1367],
                const boolean_T nanCutPoints[1367], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[850]
 *                const float cutVar[425]
 *                const float cutPoint[425]
 *                const boolean_T nanCutPoints[425]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void ob_findNode(const emxArray_real32_T *X, const float kids[850],
                 const float cutVar[425], const float cutPoint[425],
                 const boolean_T nanCutPoints[425], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2958]
 *                const float cutVar[1479]
 *                const float cutPoint[1479]
 *                const boolean_T nanCutPoints[1479]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void p_findNode(const emxArray_real32_T *X, const float kids[2958],
                const float cutVar[1479], const float cutPoint[1479],
                const boolean_T nanCutPoints[1479], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[686]
 *                const float cutVar[343]
 *                const float cutPoint[343]
 *                const boolean_T nanCutPoints[343]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void pb_findNode(const emxArray_real32_T *X, const float kids[686],
                 const float cutVar[343], const float cutPoint[343],
                 const boolean_T nanCutPoints[343], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2938]
 *                const float cutVar[1469]
 *                const float cutPoint[1469]
 *                const boolean_T nanCutPoints[1469]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void q_findNode(const emxArray_real32_T *X, const float kids[2938],
                const float cutVar[1469], const float cutPoint[1469],
                const boolean_T nanCutPoints[1469], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1074]
 *                const float cutVar[537]
 *                const float cutPoint[537]
 *                const boolean_T nanCutPoints[537]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void qb_findNode(const emxArray_real32_T *X, const float kids[1074],
                 const float cutVar[537], const float cutPoint[537],
                 const boolean_T nanCutPoints[537], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[3326]
 *                const float cutVar[1663]
 *                const float cutPoint[1663]
 *                const boolean_T nanCutPoints[1663]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void r_findNode(const emxArray_real32_T *X, const float kids[3326],
                const float cutVar[1663], const float cutPoint[1663],
                const boolean_T nanCutPoints[1663], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1058]
 *                const float cutVar[529]
 *                const float cutPoint[529]
 *                const boolean_T nanCutPoints[529]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void rb_findNode(const emxArray_real32_T *X, const float kids[1058],
                 const float cutVar[529], const float cutPoint[529],
                 const boolean_T nanCutPoints[529], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2822]
 *                const float cutVar[1411]
 *                const float cutPoint[1411]
 *                const boolean_T nanCutPoints[1411]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void s_findNode(const emxArray_real32_T *X, const float kids[2822],
                const float cutVar[1411], const float cutPoint[1411],
                const boolean_T nanCutPoints[1411], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[854]
 *                const float cutVar[427]
 *                const float cutPoint[427]
 *                const boolean_T nanCutPoints[427]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void sb_findNode(const emxArray_real32_T *X, const float kids[854],
                 const float cutVar[427], const float cutPoint[427],
                 const boolean_T nanCutPoints[427], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[2634]
 *                const float cutVar[1317]
 *                const float cutPoint[1317]
 *                const boolean_T nanCutPoints[1317]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void t_findNode(const emxArray_real32_T *X, const float kids[2634],
                const float cutVar[1317], const float cutPoint[1317],
                const boolean_T nanCutPoints[1317], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[894]
 *                const float cutVar[447]
 *                const float cutPoint[447]
 *                const boolean_T nanCutPoints[447]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void tb_findNode(const emxArray_real32_T *X, const float kids[894],
                 const float cutVar[447], const float cutPoint[447],
                 const boolean_T nanCutPoints[447], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1418]
 *                const float cutVar[709]
 *                const float cutPoint[709]
 *                const boolean_T nanCutPoints[709]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void u_findNode(const emxArray_real32_T *X, const float kids[1418],
                const float cutVar[709], const float cutPoint[709],
                const boolean_T nanCutPoints[709], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1126]
 *                const float cutVar[563]
 *                const float cutPoint[563]
 *                const boolean_T nanCutPoints[563]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void ub_findNode(const emxArray_real32_T *X, const float kids[1126],
                 const float cutVar[563], const float cutPoint[563],
                 const boolean_T nanCutPoints[563], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1566]
 *                const float cutVar[783]
 *                const float cutPoint[783]
 *                const boolean_T nanCutPoints[783]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void v_findNode(const emxArray_real32_T *X, const float kids[1566],
                const float cutVar[783], const float cutPoint[783],
                const boolean_T nanCutPoints[783], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[938]
 *                const float cutVar[469]
 *                const float cutPoint[469]
 *                const boolean_T nanCutPoints[469]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void vb_findNode(const emxArray_real32_T *X, const float kids[938],
                 const float cutVar[469], const float cutPoint[469],
                 const boolean_T nanCutPoints[469], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1298]
 *                const float cutVar[649]
 *                const float cutPoint[649]
 *                const boolean_T nanCutPoints[649]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void w_findNode(const emxArray_real32_T *X, const float kids[1298],
                const float cutVar[649], const float cutPoint[649],
                const boolean_T nanCutPoints[649], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[942]
 *                const float cutVar[471]
 *                const float cutPoint[471]
 *                const boolean_T nanCutPoints[471]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void wb_findNode(const emxArray_real32_T *X, const float kids[942],
                 const float cutVar[471], const float cutPoint[471],
                 const boolean_T nanCutPoints[471], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1530]
 *                const float cutVar[765]
 *                const float cutPoint[765]
 *                const boolean_T nanCutPoints[765]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void x_findNode(const emxArray_real32_T *X, const float kids[1530],
                const float cutVar[765], const float cutPoint[765],
                const boolean_T nanCutPoints[765], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1110]
 *                const float cutVar[555]
 *                const float cutPoint[555]
 *                const boolean_T nanCutPoints[555]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void xb_findNode(const emxArray_real32_T *X, const float kids[1110],
                 const float cutVar[555], const float cutPoint[555],
                 const boolean_T nanCutPoints[555], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[1398]
 *                const float cutVar[699]
 *                const float cutPoint[699]
 *                const boolean_T nanCutPoints[699]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void y_findNode(const emxArray_real32_T *X, const float kids[1398],
                const float cutVar[699], const float cutPoint[699],
                const boolean_T nanCutPoints[699], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * Arguments    : const emxArray_real32_T *X
 *                const float kids[846]
 *                const float cutVar[423]
 *                const float cutPoint[423]
 *                const boolean_T nanCutPoints[423]
 *                emxArray_real_T *node
 * Return Type  : void
 */
void yb_findNode(const emxArray_real32_T *X, const float kids[846],
                 const float cutVar[423], const float cutPoint[423],
                 const boolean_T nanCutPoints[423], emxArray_real_T *node)
{
  double *node_data;
  const float *X_data;
  int m;
  int n;
  int numberOfObservations;
  X_data = X->data;
  numberOfObservations = X->size[0];
  m = node->size[0];
  node->size[0] = X->size[0];
  emxEnsureCapacity_real_T(node, m);
  node_data = node->data;
  for (n = 0; n < numberOfObservations; n++) {
    boolean_T exitg1;
    m = 0;
    exitg1 = false;
    while (!(exitg1 || (cutVar[m] == 0.0F))) {
      float f;
      f = X_data[n + X->size[0] * ((int)cutVar[m] - 1)];
      if (c_isnan(f) || nanCutPoints[m]) {
        exitg1 = true;
      } else if (f < cutPoint[m]) {
        m = (int)kids[m << 1] - 1;
      } else {
        m = (int)kids[(m << 1) + 1] - 1;
      }
    }
    node_data[n] = m + 1;
  }
}

/*
 * File trailer for findNode.c
 *
 * [EOF]
 */
