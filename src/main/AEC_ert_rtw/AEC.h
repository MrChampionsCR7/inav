/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AEC.h
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

#ifndef RTW_HEADER_AEC_h_
#define RTW_HEADER_AEC_h_
#include <string.h>
#ifndef AEC_COMMON_INCLUDES_
# define AEC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* AEC_COMMON_INCLUDES_ */

#include "AEC_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T AltitudeDiscreteController; /* '<Root>/Altitude Discrete Controller' */
} B_AEC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T AltitudeDiscreteController_DSTA[2];
                                     /* '<Root>/Altitude Discrete Controller' */
  real_T Integrator_DSTATE;            /* '<S34>/Integrator' */
  real_T Filter_DSTATE;                /* '<S29>/Filter' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
} DW_AEC_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Plant_CSTATE[2];              /* '<Root>/Plant' */
} X_AEC_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Plant_CSTATE[2];              /* '<Root>/Plant' */
} XDot_AEC_T;

/* State disabled  */
typedef struct {
  boolean_T Plant_CSTATE[2];           /* '<Root>/Plant' */
} XDis_AEC_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T AltCmd;                       /* '<Root>/AltCmd' */
  real_T Theta;                        /* '<Root>/Theta' */
} ExtU_AEC_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ElevCmd;                      /* '<Root>/ElevCmd' */
  real_T AltError;                     /* '<Root>/AltError' */
} ExtY_AEC_T;

/* Real-time Model Data Structure */
struct tag_RTM_AEC_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_AEC_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_AEC_T AEC_B;

/* Continuous states (default storage) */
extern X_AEC_T AEC_X;

/* Block states (default storage) */
extern DW_AEC_T AEC_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_AEC_T AEC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_AEC_T AEC_Y;

/* Model entry point functions */
extern void AEC_initialize(void);
extern void AEC_step(void);
extern void AEC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AEC_T *const AEC_M;

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
 * '<Root>' : 'AEC'
 * '<S1>'   : 'AEC/Difference Filter'
 * '<S2>'   : 'AEC/PID Controller'
 * '<S3>'   : 'AEC/PID Controller/Anti-windup'
 * '<S4>'   : 'AEC/PID Controller/D Gain'
 * '<S5>'   : 'AEC/PID Controller/Filter'
 * '<S6>'   : 'AEC/PID Controller/Filter ICs'
 * '<S7>'   : 'AEC/PID Controller/I Gain'
 * '<S8>'   : 'AEC/PID Controller/Ideal P Gain'
 * '<S9>'   : 'AEC/PID Controller/Ideal P Gain Fdbk'
 * '<S10>'  : 'AEC/PID Controller/Integrator'
 * '<S11>'  : 'AEC/PID Controller/Integrator ICs'
 * '<S12>'  : 'AEC/PID Controller/N Copy'
 * '<S13>'  : 'AEC/PID Controller/N Gain'
 * '<S14>'  : 'AEC/PID Controller/P Copy'
 * '<S15>'  : 'AEC/PID Controller/Parallel P Gain'
 * '<S16>'  : 'AEC/PID Controller/Reset Signal'
 * '<S17>'  : 'AEC/PID Controller/Saturation'
 * '<S18>'  : 'AEC/PID Controller/Saturation Fdbk'
 * '<S19>'  : 'AEC/PID Controller/Sum'
 * '<S20>'  : 'AEC/PID Controller/Sum Fdbk'
 * '<S21>'  : 'AEC/PID Controller/Tracking Mode'
 * '<S22>'  : 'AEC/PID Controller/Tracking Mode Sum'
 * '<S23>'  : 'AEC/PID Controller/Tsamp - Integral'
 * '<S24>'  : 'AEC/PID Controller/Tsamp - Ngain'
 * '<S25>'  : 'AEC/PID Controller/postSat Signal'
 * '<S26>'  : 'AEC/PID Controller/preSat Signal'
 * '<S27>'  : 'AEC/PID Controller/Anti-windup/Passthrough'
 * '<S28>'  : 'AEC/PID Controller/D Gain/Internal Parameters'
 * '<S29>'  : 'AEC/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S30>'  : 'AEC/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S31>'  : 'AEC/PID Controller/I Gain/Internal Parameters'
 * '<S32>'  : 'AEC/PID Controller/Ideal P Gain/Passthrough'
 * '<S33>'  : 'AEC/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S34>'  : 'AEC/PID Controller/Integrator/Discrete'
 * '<S35>'  : 'AEC/PID Controller/Integrator ICs/Internal IC'
 * '<S36>'  : 'AEC/PID Controller/N Copy/Disabled'
 * '<S37>'  : 'AEC/PID Controller/N Gain/Internal Parameters'
 * '<S38>'  : 'AEC/PID Controller/P Copy/Disabled'
 * '<S39>'  : 'AEC/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S40>'  : 'AEC/PID Controller/Reset Signal/Disabled'
 * '<S41>'  : 'AEC/PID Controller/Saturation/Passthrough'
 * '<S42>'  : 'AEC/PID Controller/Saturation Fdbk/Disabled'
 * '<S43>'  : 'AEC/PID Controller/Sum/Sum_PID'
 * '<S44>'  : 'AEC/PID Controller/Sum Fdbk/Disabled'
 * '<S45>'  : 'AEC/PID Controller/Tracking Mode/Disabled'
 * '<S46>'  : 'AEC/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S47>'  : 'AEC/PID Controller/Tsamp - Integral/Passthrough'
 * '<S48>'  : 'AEC/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S49>'  : 'AEC/PID Controller/postSat Signal/Forward_Path'
 * '<S50>'  : 'AEC/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_AEC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
