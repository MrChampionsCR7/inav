/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: IS_data.c
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

#include "IS.h"
#include "IS_private.h"

/* Invariant block signals (default storage) */
const ConstB_IS_T IS_ConstB = {
  { 0.0, 0.0, 16.1809725 },            /* '<S1>/Gain' */
  0.503245                             /* '<S2>/Gain1' */
};

/* Constant parameters (default storage) */
const ConstP_IS_T IS_ConstP = {
  /* Pooled Parameter (Expression: aeroCoeff.alpha_vec)
   * Referenced by:
   *   '<S24>/Prelookup'
   *   '<S25>/Prelookup1'
   */
  { -16.0, -12.0, -8.0, -4.0, -2.0, 0.0, 2.0, 4.0, 8.0, 12.0 },

  /* Expression: aeroCoeff.CD
   * Referenced by: '<S24>/CD'
   */
  { 0.115, 0.079, 0.047, 0.031, 0.027, 0.027, 0.029, 0.034, 0.054, 0.089 },

  /* Expression: aeroCoeff.CL
   * Referenced by: '<S24>/CL'
   */
  { -1.421, -1.092, -0.695, -0.312, -0.132, 0.041, 0.218, 0.402, 0.786, 1.186 },

  /* Expression: aeroCoeff.def_vec
   * Referenced by: '<S25>/Prelookup'
   */
  { -20.0, -10.0, 0.0, 10.0, 20.0 },

  /* Expression: aeroCoeff.CD_el
   * Referenced by: '<S25>/CD_el'
   */
  { 0.0046, 0.0039, 0.0034, 0.0028, 0.0025, 0.0022, 0.0019, 0.0016, 0.001,
    0.0004, 0.0029, 0.0024, 0.002, 0.0016, 0.0014, 0.0012, 0.001, 0.0008, 0.0003,
    -0.0001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0009, -0.0005,
    0.0, 0.0004, 0.0006, 0.0008, 0.001, 0.0012, 0.0016, 0.0021, -0.0008, -0.0001,
    0.0005, 0.0011, 0.0014, 0.0016, 0.0019, 0.0022, 0.0028, 0.0034 },

  /* Expression: aeroCoeff.CL_el
   * Referenced by: '<S25>/CL_el'
   */
  { -0.051, -0.038, 0.0, 0.038, 0.052 },

  /* Expression: vehicle.Thrust*(1+tanh([-3:3]))
   * Referenced by: '<S5>/Thrust'
   */
  { 0.087778122060534258, 0.63851045365425, 4.2317037317851742, 17.75,
    31.268296268214826, 34.861489546345751, 35.412221877939466 },

  /* Expression: (1/6)*(3+([-3:3]))
   * Referenced by: '<S5>/Thrust'
   */
  { 0.0, 0.16666666666666666, 0.33333333333333331, 0.5, 0.66666666666666663,
    0.83333333333333326, 1.0 },

  /* Expression: aeroCoeff.CM
   * Referenced by: '<S24>/CM'
   */
  { 0.0775, 0.0663, 0.053, 0.0337, 0.0217, 0.0073, -0.009, -0.0263, -0.0632,
    -0.1235 },

  /* Expression: aeroCoeff.CM_el
   * Referenced by: '<S25>/CM_el'
   */
  { 0.0842, 0.0601, -0.0001, -0.0601, -0.0843 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
