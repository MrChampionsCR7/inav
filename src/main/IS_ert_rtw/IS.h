/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: IS.h
 *
 * Code generated for Simulink model 'IS'.
 *
 * Model version                  : 1.165
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jun  1 22:15:03 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IS_h_
#define RTW_HEADER_IS_h_
#include <string.h>
#include <math.h>
#ifndef IS_COMMON_INCLUDES_
# define IS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* IS_COMMON_INCLUDES_ */

#include "IS_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T q;                            /* '<S9>/q' */
  real_T Sum4;                         /* '<Root>/Sum4' */
  real_T Product2;                     /* '<S11>/Product2' */
  real_T Sum1[2];                      /* '<S9>/Sum1' */
  real_T TmpSignalConversionAtPositionIn[2];/* '<S9>/Transform  to Earth Axes' */
} B_IS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T m_bpIndex;                  /* '<S5>/Thrust' */
  int_T Uw_IWORK;                      /* '<S9>/U,w' */
} DW_IS_T;

/* Continuous states (default storage) */
typedef struct {
  real_T theta;                        /* '<S9>/Theta' */
  real_T u[2];                         /* '<S9>/U,w' */
  real_T Xe[2];                        /* '<S9>/Position' */
  real_T q;                            /* '<S9>/q' */
} X_IS_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_IS_T[1];
typedef real_T PeriodicRngX_IS_T[2];

/* State derivatives (default storage) */
typedef struct {
  real_T theta;                        /* '<S9>/Theta' */
  real_T u[2];                         /* '<S9>/U,w' */
  real_T Xe[2];                        /* '<S9>/Position' */
  real_T q;                            /* '<S9>/q' */
} XDot_IS_T;

/* State disabled  */
typedef struct {
  boolean_T theta;                     /* '<S9>/Theta' */
  boolean_T u[2];                      /* '<S9>/U,w' */
  boolean_T Xe[2];                     /* '<S9>/Position' */
  boolean_T q;                         /* '<S9>/q' */
} XDis_IS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain[3];                /* '<S1>/Gain' */
  const real_T Gain1;                  /* '<S2>/Gain1' */
} ConstB_IS_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: aeroCoeff.alpha_vec)
   * Referenced by:
   *   '<S24>/Prelookup'
   *   '<S25>/Prelookup1'
   */
  real_T pooled3[10];

  /* Expression: aeroCoeff.CD
   * Referenced by: '<S24>/CD'
   */
  real_T CD_Table[10];

  /* Expression: aeroCoeff.CL
   * Referenced by: '<S24>/CL'
   */
  real_T CL_Table[10];

  /* Expression: aeroCoeff.def_vec
   * Referenced by: '<S25>/Prelookup'
   */
  real_T Prelookup_BreakpointsData[5];

  /* Expression: aeroCoeff.CD_el
   * Referenced by: '<S25>/CD_el'
   */
  real_T CD_el_Table[50];

  /* Expression: aeroCoeff.CL_el
   * Referenced by: '<S25>/CL_el'
   */
  real_T CL_el_Table[5];

  /* Expression: vehicle.Thrust*(1+tanh([-3:3]))
   * Referenced by: '<S5>/Thrust'
   */
  real_T Thrust_tableData[7];

  /* Expression: (1/6)*(3+([-3:3]))
   * Referenced by: '<S5>/Thrust'
   */
  real_T Thrust_bp01Data[7];

  /* Expression: aeroCoeff.CM
   * Referenced by: '<S24>/CM'
   */
  real_T CM_Table[10];

  /* Expression: aeroCoeff.CM_el
   * Referenced by: '<S25>/CM_el'
   */
  real_T CM_el_Table[5];
} ConstP_IS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ActCmd;                       /* '<Root>/ActCmd' */
  real_T Throttle;                     /* '<Root>/Throttle' */
  real_T VelReel;                      /* '<Root>/VelReel' */
} ExtU_IS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T LonStatesBus[9];              /* '<Root>/LonStatesBus' */
  real_T Airspeed;                     /* '<Root>/Airspeed' */
  real_T Theta[2];                     /* '<Root>/Theta' */
  real_T OutAltitude;                  /* '<Root>/OutAltitude' */
  real_T Beta;                         /* '<Root>/Beta' */
  real_T Alpha;                        /* '<Root>/Alpha' */
} ExtY_IS_T;

/* Real-time Model Data Structure */
struct tag_RTM_IS_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_IS_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[3][6];
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
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_IS_T IS_B;

/* Continuous states (default storage) */
extern X_IS_T IS_X;

/* Block states (default storage) */
extern DW_IS_T IS_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_IS_T IS_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_IS_T IS_Y;
extern const ConstB_IS_T IS_ConstB;    /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_IS_T IS_ConstP;

/* Model entry point functions */
extern void IS_initialize(void);
extern void IS_step(void);
extern void IS_terminate(void);

/* Real-time Model object */
extern RT_MODEL_IS_T *const IS_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/Unit Conversion' : Unused code path elimination
 * Block '<S23>/Airspeed' : Unused code path elimination
 * Block '<S27>/Product' : Unused code path elimination
 * Block '<S27>/Product1' : Unused code path elimination
 * Block '<S27>/Sum' : Unused code path elimination
 * Block '<S31>/Constant' : Unused code path elimination
 * Block '<S31>/Constant1' : Unused code path elimination
 * Block '<S31>/Constant2' : Unused code path elimination
 * Block '<S33>/Reshape1' : Unused code path elimination
 * Block '<S33>/pg,qg,rg' : Unused code path elimination
 * Block '<Root>/Power' : Unused code path elimination
 * Block '<S7>/Product2' : Unused code path elimination
 * Block '<S8>/Gain' : Unused code path elimination
 * Block '<S34>/Airspeed' : Unused code path elimination
 * Block '<S34>/Incidence' : Unused code path elimination
 * Block '<S35>/Product' : Unused code path elimination
 * Block '<S35>/Product1' : Unused code path elimination
 * Block '<S35>/Sum' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S18>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S15>/Unit Conversion' : Eliminated nontunable gain of 1
 * Block '<S19>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S32>/Reshape1' : Reshape block reduction
 * Block '<S33>/Reshape' : Reshape block reduction
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
 * '<Root>' : 'IS'
 * '<S1>'   : 'IS/3DOF EOM'
 * '<S2>'   : 'IS/Aerodynamic Model'
 * '<S3>'   : 'IS/Degrees to Radians'
 * '<S4>'   : 'IS/Environment Model'
 * '<S5>'   : 'IS/Propulsion'
 * '<S6>'   : 'IS/Radians to Degrees'
 * '<S7>'   : 'IS/TetherForce'
 * '<S8>'   : 'IS/Visualization'
 * '<S9>'   : 'IS/3DOF EOM/3DOF (Body Axes)'
 * '<S10>'  : 'IS/3DOF EOM/Rotation Angles to Direction Cosine Matrix'
 * '<S11>'  : 'IS/3DOF EOM/3DOF (Body Axes)/Calculate qdot'
 * '<S12>'  : 'IS/3DOF EOM/3DOF (Body Axes)/Determine Force,  Mass & Inertia'
 * '<S13>'  : 'IS/3DOF EOM/3DOF (Body Axes)/Gravity'
 * '<S14>'  : 'IS/3DOF EOM/3DOF (Body Axes)/Transform  to Earth Axes'
 * '<S15>'  : 'IS/3DOF EOM/3DOF (Body Axes)/Velocity Conversion'
 * '<S16>'  : 'IS/3DOF EOM/3DOF (Body Axes)/Velocity Conversion1'
 * '<S17>'  : 'IS/3DOF EOM/3DOF (Body Axes)/Transform  to Earth Axes/Rotation Angles to Direction Cosine Matrix'
 * '<S18>'  : 'IS/3DOF EOM/3DOF (Body Axes)/Transform  to Earth Axes/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S19>'  : 'IS/3DOF EOM/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S20>'  : 'IS/Aerodynamic Model/Aero Forces and Moments'
 * '<S21>'  : 'IS/Aerodynamic Model/Dynamic Pressure'
 * '<S22>'  : 'IS/Aerodynamic Model/Elevator Forces and Moments'
 * '<S23>'  : 'IS/Aerodynamic Model/Incidence  & Airspeed'
 * '<S24>'  : 'IS/Aerodynamic Model/Lookup Aero Coeffs'
 * '<S25>'  : 'IS/Aerodynamic Model/Lookup Elevator Aero Coeffs'
 * '<S26>'  : 'IS/Aerodynamic Model/Dynamic Pressure/dot'
 * '<S27>'  : 'IS/Aerodynamic Model/Incidence  & Airspeed/dot'
 * '<S28>'  : 'IS/Aerodynamic Model/Lookup Aero Coeffs/Subsystem'
 * '<S29>'  : 'IS/Aerodynamic Model/Lookup Elevator Aero Coeffs/Subsystem'
 * '<S30>'  : 'IS/Aerodynamic Model/Lookup Elevator Aero Coeffs/Subsystem1'
 * '<S31>'  : 'IS/Environment Model/Constant Atmosphere'
 * '<S32>'  : 'IS/Environment Model/Constant Gravity'
 * '<S33>'  : 'IS/Environment Model/Constant Wind'
 * '<S34>'  : 'IS/Visualization/Incidence  & Airspeed'
 * '<S35>'  : 'IS/Visualization/Incidence  & Airspeed/dot'
 */
#endif                                 /* RTW_HEADER_IS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
