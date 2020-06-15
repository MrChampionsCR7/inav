/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Example.c
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

#include "Example.h"
#include "Example_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_Example_T Example_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Example_T Example_Y;

/* Real-time model */
RT_MODEL_Example_T Example_M_;
RT_MODEL_Example_T *const Example_M = &Example_M_;

/* Model step function */
void Example_step(void)
{
  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<Root>/Offset'
   *  Inport: '<Root>/coolant_temp'
   */
  Example_Y.Temperature = (int16_T)(Example_U.coolant_temp - 4);

  /* RelationalOperator: '<S1>/Relational Operator' incorporates:
   *  Constant: '<S1>/MaxTemp'
   */
  Example_Y.error = (Example_Y.Temperature > 210);

  /* Switch: '<S1>/Switch' */
  if (Example_Y.error) {
    /* Outport: '<Root>/Temperature' incorporates:
     *  Constant: '<S1>/DefaultTemp'
     */
    Example_Y.Temperature = 20;
  }

  /* End of Switch: '<S1>/Switch' */
}

/* Model initialize function */
void Example_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Example_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
