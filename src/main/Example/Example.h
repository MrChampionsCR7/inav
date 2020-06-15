/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Example.h
 *
 * Code generated for Simulink model 'Example'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Apr 21 21:42:43 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Example_h_
#define RTW_HEADER_Example_h_
#ifndef Example_COMMON_INCLUDES_
# define Example_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Example_COMMON_INCLUDES_ */

#include "Example_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T coolant_temp;                /* '<Root>/coolant_temp' */
} ExtU_Example_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T Temperature;                 /* '<Root>/Temperature' */
  boolean_T error;                     /* '<Root>/error' */
} ExtY_Example_T;

/* Real-time Model Data Structure */
struct tag_RTM_Example_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_Example_T Example_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Example_T Example_Y;

/* Model entry point functions */
extern void Example_initialize(void);
extern void Example_step(void);
extern void Example_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Example_T *const Example_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Example'
 * '<S1>'   : 'Example/OutOfRange'
 * '<S2>'   : 'Example/ScaleAndOffset'
 */
#endif                                 /* RTW_HEADER_Example_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
