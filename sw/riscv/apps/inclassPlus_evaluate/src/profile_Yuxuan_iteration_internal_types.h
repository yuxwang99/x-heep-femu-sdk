/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * profile_Yuxuan_iteration_internal_types.h
 *
 * Code generation for function 'profile_Yuxuan_iteration'
 *
 */

#ifndef PROFILE_YUXUAN_ITERATION_INTERNAL_TYPES_H
#define PROFILE_YUXUAN_ITERATION_INTERNAL_TYPES_H

/* Include files */
#include "profile_Yuxuan_iteration_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef enum_c_classreg_learning_coderutils_
#define enum_c_classreg_learning_coderutils_

enum c_classreg_learning_coderutils_
{
  Logit = 0,                           /* Default value */
  Doublelogit,
  Invlogit,
  Ismax,
  Sign,
  Symmetric,
  Symmetricismax,
  Symmetriclogit,
  Identity
};

#endif                                 /*enum_c_classreg_learning_coderutils_*/

#ifndef typedef_c_classreg_learning_coderutils_
#define typedef_c_classreg_learning_coderutils_

typedef enum c_classreg_learning_coderutils_ c_classreg_learning_coderutils_;

#endif                                 /*typedef_c_classreg_learning_coderutils_*/

#ifndef typedef_coder_internal_SortedBuffer
#define typedef_coder_internal_SortedBuffer

typedef struct {
  double buf[3];
  int nbuf;
  boolean_T includenans;
  int nnans;
} coder_internal_SortedBuffer;

#endif                                 /*typedef_coder_internal_SortedBuffer*/

#ifndef typedef_c_classreg_learning_classif_Com
#define typedef_c_classreg_learning_classif_Com

typedef struct {
  boolean_T IsCached[30];
  double LearnerWeights[30];
  double ClassNames[2];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  double Prior[2];
  boolean_T ClassLogicalIndices[2];
  double Cost[4];
} c_classreg_learning_classif_Com;

#endif                                 /*typedef_c_classreg_learning_classif_Com*/
#endif

/* End of code generation (profile_Yuxuan_iteration_internal_types.h) */
