/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AEC.c
 *
 * Code generated for Simulink model 'AEC'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed May 27 17:40:37 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AEC.h"
#include "AEC_private.h"

/* Block signals (default storage) */
B_AEC_T AEC_B;

/* Continuous states */
X_AEC_T AEC_X;

/* Block states (default storage) */
DW_AEC_T AEC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_AEC_T AEC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_AEC_T AEC_Y;

/* Real-time model */
RT_MODEL_AEC_T AEC_M_;
RT_MODEL_AEC_T *const AEC_M = &AEC_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  AEC_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  AEC_step();
  AEC_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  AEC_step();
  AEC_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void AEC_step(void)
{
  /* local block i/o variables */
  real_T rtb_FilterCoefficient;
  real_T rtb_Sum;
  real_T rtb_IntegralGain;
  real_T Subtract1;
  if (rtmIsMajorTimeStep(AEC_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&AEC_M->solverInfo,((AEC_M->Timing.clockTick0+1)*
      AEC_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(AEC_M)) {
    AEC_M->Timing.t[0] = rtsiGetT(&AEC_M->solverInfo);
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Inport: '<Root>/AltCmd'
   *  TransferFcn: '<Root>/Plant'
   */
  AEC_B.Subtract = AEC_U.AltCmd - (0.0 * AEC_X.Plant_CSTATE[0] + -400000.0 *
    AEC_X.Plant_CSTATE[1]);
  if (rtmIsMajorTimeStep(AEC_M)) {
    /* DiscreteZeroPole: '<Root>/Altitude Discrete Controller' */
    {
      AEC_B.AltitudeDiscreteController = (-0.0018202327040000006)*
        AEC_DW.AltitudeDiscreteController_DSTA[0]
        + (0.0018978263120453566)*AEC_DW.AltitudeDiscreteController_DSTA[1];
      AEC_B.AltitudeDiscreteController += 0.033728*AEC_B.Subtract;
    }
  }

  /* Sum: '<Root>/Subtract1' incorporates:
   *  Inport: '<Root>/Theta'
   */
  Subtract1 = AEC_B.AltitudeDiscreteController - AEC_U.Theta;
  if (rtmIsMajorTimeStep(AEC_M)) {
    /* Gain: '<S37>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S29>/Filter'
     *  Gain: '<S28>/Derivative Gain'
     *  Sum: '<S29>/SumD'
     */
    rtb_FilterCoefficient = (2.0 * Subtract1 - AEC_DW.Filter_DSTATE) * 100.0;

    /* Sum: '<S43>/Sum' incorporates:
     *  DiscreteIntegrator: '<S34>/Integrator'
     *  Gain: '<S39>/Proportional Gain'
     */
    rtb_Sum = (-300.0 * Subtract1 + AEC_DW.Integrator_DSTATE) +
      rtb_FilterCoefficient;

    /* Sum: '<S1>/Diff' incorporates:
     *  UnitDelay: '<S1>/UD'
     *
     * Block description for '<S1>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S1>/UD':
     *
     *  Store in Global RAM
     */
    AEC_Y.ElevCmd = rtb_Sum - AEC_DW.UD_DSTATE;

    /* Saturate: '<Root>/Saturation' */
    if (AEC_Y.ElevCmd > 0.35) {
      /* Sum: '<S1>/Diff' incorporates:
       *  Outport: '<Root>/ElevCmd'
       *
       * Block description for '<S1>/Diff':
       *
       *  Add in CPU
       */
      AEC_Y.ElevCmd = 0.35;
    } else {
      if (AEC_Y.ElevCmd < -0.35) {
        /* Sum: '<S1>/Diff' incorporates:
         *  Outport: '<Root>/ElevCmd'
         *
         * Block description for '<S1>/Diff':
         *
         *  Add in CPU
         */
        AEC_Y.ElevCmd = -0.35;
      }
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Gain: '<S31>/Integral Gain' */
    rtb_IntegralGain = -15000.0 * Subtract1;
  }

  /* Outport: '<Root>/AltError' */
  AEC_Y.AltError = AEC_B.Subtract;
  if (rtmIsMajorTimeStep(AEC_M)) {
    if (rtmIsMajorTimeStep(AEC_M)) {
      /* Update for DiscreteZeroPole: '<Root>/Altitude Discrete Controller' */
      {
        real_T xnew[2];
        xnew[0] = (1.920841)*AEC_DW.AltitudeDiscreteController_DSTA[0]
          + (-0.95960460607481457)*AEC_DW.AltitudeDiscreteController_DSTA[1];
        xnew[0] += 1.0*AEC_B.Subtract;
        xnew[1] = (0.95960460607481457)*AEC_DW.AltitudeDiscreteController_DSTA[0];
        (void) memcpy(&AEC_DW.AltitudeDiscreteController_DSTA[0], xnew,
                      sizeof(real_T)*2);
      }

      /* Update for DiscreteIntegrator: '<S34>/Integrator' */
      AEC_DW.Integrator_DSTATE += 0.001 * rtb_IntegralGain;

      /* Update for DiscreteIntegrator: '<S29>/Filter' */
      AEC_DW.Filter_DSTATE += 0.001 * rtb_FilterCoefficient;

      /* Update for UnitDelay: '<S1>/UD'
       *
       * Block description for '<S1>/UD':
       *
       *  Store in Global RAM
       */
      AEC_DW.UD_DSTATE = rtb_Sum;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(AEC_M)) {
    rt_ertODEUpdateContinuousStates(&AEC_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++AEC_M->Timing.clockTick0;
    AEC_M->Timing.t[0] = rtsiGetSolverStopTime(&AEC_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      AEC_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void AEC_derivatives(void)
{
  XDot_AEC_T *_rtXdot;
  _rtXdot = ((XDot_AEC_T *) AEC_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Plant' incorporates:
   *  Outport: '<Root>/ElevCmd'
   */
  _rtXdot->Plant_CSTATE[0] = 0.0;
  _rtXdot->Plant_CSTATE[0] += -1200.0 * AEC_X.Plant_CSTATE[0];
  _rtXdot->Plant_CSTATE[1] = 0.0;
  _rtXdot->Plant_CSTATE[0] += -2400.0 * AEC_X.Plant_CSTATE[1];
  _rtXdot->Plant_CSTATE[1] += AEC_X.Plant_CSTATE[0];
  _rtXdot->Plant_CSTATE[0] += AEC_Y.ElevCmd;
}

/* Model initialize function */
void AEC_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&AEC_M->solverInfo, &AEC_M->Timing.simTimeStep);
    rtsiSetTPtr(&AEC_M->solverInfo, &rtmGetTPtr(AEC_M));
    rtsiSetStepSizePtr(&AEC_M->solverInfo, &AEC_M->Timing.stepSize0);
    rtsiSetdXPtr(&AEC_M->solverInfo, &AEC_M->derivs);
    rtsiSetContStatesPtr(&AEC_M->solverInfo, (real_T **) &AEC_M->contStates);
    rtsiSetNumContStatesPtr(&AEC_M->solverInfo, &AEC_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&AEC_M->solverInfo,
      &AEC_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&AEC_M->solverInfo,
      &AEC_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&AEC_M->solverInfo,
      &AEC_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&AEC_M->solverInfo, (&rtmGetErrorStatus(AEC_M)));
    rtsiSetRTModelPtr(&AEC_M->solverInfo, AEC_M);
  }

  rtsiSetSimTimeStep(&AEC_M->solverInfo, MAJOR_TIME_STEP);
  AEC_M->intgData.y = AEC_M->odeY;
  AEC_M->intgData.f[0] = AEC_M->odeF[0];
  AEC_M->intgData.f[1] = AEC_M->odeF[1];
  AEC_M->intgData.f[2] = AEC_M->odeF[2];
  AEC_M->contStates = ((X_AEC_T *) &AEC_X);
  rtsiSetSolverData(&AEC_M->solverInfo, (void *)&AEC_M->intgData);
  rtsiSetSolverName(&AEC_M->solverInfo,"ode3");
  rtmSetTPtr(AEC_M, &AEC_M->Timing.tArray[0]);
  AEC_M->Timing.stepSize0 = 0.001;

  /* InitializeConditions for TransferFcn: '<Root>/Plant' */
  AEC_X.Plant_CSTATE[0] = 0.0;
  AEC_X.Plant_CSTATE[1] = 0.0;
}

/* Model terminate function */
void AEC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
