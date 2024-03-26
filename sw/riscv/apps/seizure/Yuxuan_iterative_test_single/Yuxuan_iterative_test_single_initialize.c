/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Yuxuan_iterative_test_single_initialize.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Feb-2024 11:53:30
 */

/* Include Files */
#include "Yuxuan_iterative_test_single_initialize.h"
#include "Yuxuan_iterative_test_single_data.h"
#include "Yuxuan_iterative_test_single_emxutil.h"
#include "Yuxuan_iterative_test_single_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void b_cast(emxArray_real32_T *r1);

static void cast(emxArray_real32_T *r1);

/* Function Definitions */
/*
 * Arguments    : emxArray_real32_T *r1
 * Return Type  : void
 */
static void b_cast(emxArray_real32_T *r1)
{
  static const float fv[100] = {
      0.901826203F,  0.35824585F,  0.127993599F, 0.348552018F, 0.0963434353F,
      0.343221188F,  0.256764829F, 0.210638747F, 0.765745223F, 0.190940022F,
      0.340506256F,  0.693788528F, 0.57683897F,  0.807470441F, 0.264634371F,
      0.825589955F,  0.329675019F, 0.36898756F,  0.759825468F, 0.490284175F,
      0.179882273F,  0.71540159F,  0.44626224F,  0.645450473F, 0.0714796782F,
      0.0431367382F, 0.882398307F, 0.531388521F, 0.560939074F, 0.683444738F,
      0.0736938044F, 0.495733082F, 0.521365762F, 0.427817F,    0.31222254F,
      0.455536157F,  0.200194731F, 0.38184303F,  0.201323032F, 0.641565F,
      0.605798304F,  0.828842163F, 0.398951948F, 0.449168563F, 0.514198422F,
      0.856458306F,  0.548687816F, 0.826257646F, 0.31969291F,  0.155560225F,
      0.527034044F,  0.365174025F, 0.391346514F, 0.906670332F, 0.425019562F,
      0.863656461F,  0.835501671F, 0.924453855F, 0.542594254F, 0.579363942F,
      0.529048562F,  0.767397285F, 0.7031762F,   0.145455495F, 0.119992658F,
      0.0802338272F, 0.706579149F, 0.319562614F, 0.177692845F, 0.73009938F,
      0.924224198F,  0.343861848F, 0.596090734F, 0.342989385F, 0.365064383F,
      0.54016304F,   0.211789727F, 0.640800059F, 0.167445704F, 0.342500091F,
      0.460211486F,  0.648965836F, 0.290225267F, 0.533908784F, 0.0259183403F,
      0.848293424F,  0.497417361F, 0.56057483F,  0.179936886F, 0.888290942F,
      0.572372F,     0.788647175F, 0.743683279F, 0.341924638F, 0.839467049F,
      0.0308961403F, 0.385621101F, 0.949395299F, 0.784808755F, 0.454923302F};
  float *r;
  int i;
  i = r1->size[0];
  r1->size[0] = 100;
  emxEnsureCapacity_real32_T(r1, i);
  r = r1->data;
  for (i = 0; i < 100; i++) {
    r[i] = fv[i];
  }
}

/*
 * Arguments    : emxArray_real32_T *r1
 * Return Type  : void
 */
static void cast(emxArray_real32_T *r1)
{
  static const float fv[100] = {
      0.422702581F,   0.257683814F,  0.53830421F,  0.422298729F,  0.313929737F,
      0.373742F,      0.347843558F,  0.822564244F, 0.951315343F,  0.306135684F,
      0.13716951F,    0.0575958118F, 0.78930074F,  0.211261943F,  0.376817614F,
      0.00466148183F, 0.446127F,     0.576168239F, 0.867396F,     0.850189865F,
      0.0396470204F,  0.317350864F,  0.989316165F, 0.776601434F,  0.291221917F,
      0.148812145F,   0.976204F,     0.43472755F,  0.804218411F,  0.857985914F,
      0.0336524621F,  0.661969841F,  0.858278155F, 0.749644F,     0.84542954F,
      0.687049806F,   0.554581583F,  0.932820737F, 0.527436435F,  0.384827763F,
      0.28856355F,    0.138581097F,  0.182898372F, 0.756557763F,  0.989027798F,
      0.56401664F,    0.131968841F,  0.505111873F, 0.909785926F,  0.710488915F,
      0.582567096F,   0.600768328F,  0.785169184F, 0.105300315F,  0.99300617F,
      0.731571496F,   0.141658366F,  0.285030633F, 0.20034951F,   0.43981111F,
      0.293522149F,   0.487906396F,  0.919723392F, 0.38706556F,   0.38247171F,
      0.756464422F,   0.108809032F,  0.434180945F, 0.519480586F,  0.197970837F,
      0.624752283F,   0.247602746F,  0.526309907F, 0.0418236852F, 0.645959556F,
      0.509058774F,   0.539788187F,  0.483471185F, 0.953983188F,  0.931712687F,
      0.249638721F,   0.138999209F,  0.197716191F, 0.98951894F,   0.977858F,
      0.913039923F,   0.4621557F,    0.137387887F, 0.835910738F,  0.101873577F,
      0.570340931F,   0.38604486F,   0.355082184F, 0.623844385F,  0.26377219F,
      0.8960976F,     0.75970608F,   0.712929249F, 0.668311954F,  0.25908187F};
  float *r;
  int i;
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = 100;
  emxEnsureCapacity_real32_T(r1, i);
  r = r1->data;
  for (i = 0; i < 100; i++) {
    r[i] = fv[i];
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Yuxuan_iterative_test_single_initialize(void)
{
  emxInit_real32_T(&Rlocs_g, 2);
  emxInit_real32_T(&ECG_segment_g, 1);
  cast(Rlocs_g);
  b_cast(ECG_segment_g);
  ctrl_vec_g[0] = 1.0F;
  ctrl_vec_g[1] = 1.0F;
  isInitialized_Yuxuan_iterative_test_single = true;
}

/*
 * File trailer for Yuxuan_iterative_test_single_initialize.c
 *
 * [EOF]
 */
