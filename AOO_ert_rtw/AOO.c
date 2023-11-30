/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AOO.c
 *
 * Code generated for Simulink model 'AOO'.
 *
 * Model version                  : 8.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Oct 19 15:20:59 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AOO.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<Root>/AOO' */
#define AOO_IN_Chambers_Paced_Charging ((uint8_T)1U)
#define AOO_IN_pacing                  ((uint8_T)2U)

/* Block signals (default storage) */
B_AOO_T AOO_B;

/* Block states (default storage) */
DW_AOO_T AOO_DW;

/* Real-time model */
static RT_MODEL_AOO_T AOO_M_;
RT_MODEL_AOO_T *const AOO_M = &AOO_M_;

/* Model step function */
void AOO_step(void)
{
  int32_T rtb_ATR_GND_CTRL_D11;
  int32_T rtb_ATR_PACE_CTRL_D8;
  int32_T rtb_PACE_CHARGE_CTRL_D2;
  int32_T rtb_PACE_GND_CTRL_D10;
  boolean_T rtb_LED_STATE_GREEN;
  boolean_T rtb_LED_STATE_RED;

  /* Chart: '<Root>/AOO' incorporates:
   *  Constant: '<Root>/BPM'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/PWM'
   *  Constant: '<Root>/msec'
   *  Product: '<Root>/Divide'
   */
  if (AOO_DW.temporalCounter_i1 < MAX_uint32_T) {
    AOO_DW.temporalCounter_i1++;
  }

  if (AOO_DW.is_active_c3_AOO == 0U) {
    AOO_DW.is_active_c3_AOO = 1U;
    AOO_DW.temporalCounter_i1 = 0U;
    AOO_DW.is_c3_AOO = AOO_IN_Chambers_Paced_Charging;
    AOO_B.PACING_REF_PWM_D5 = AOO_P.PWM_Value;
    rtb_PACE_CHARGE_CTRL_D2 = 1;
    rtb_ATR_PACE_CTRL_D8 = 0;
    rtb_ATR_GND_CTRL_D11 = 1;
    rtb_PACE_GND_CTRL_D10 = 0;
    rtb_LED_STATE_RED = true;
    rtb_LED_STATE_GREEN = false;
  } else if (AOO_DW.is_c3_AOO == AOO_IN_Chambers_Paced_Charging) {
    rtb_PACE_CHARGE_CTRL_D2 = 1;
    rtb_ATR_PACE_CTRL_D8 = 0;
    rtb_ATR_GND_CTRL_D11 = 1;
    rtb_PACE_GND_CTRL_D10 = 0;
    rtb_LED_STATE_RED = true;
    rtb_LED_STATE_GREEN = false;
    if (AOO_DW.temporalCounter_i1 >= (uint32_T)ceil(AOO_P.msec_Value /
         AOO_P.BPM_Value - AOO_P.Constant_Value)) {
      AOO_DW.temporalCounter_i1 = 0U;
      AOO_DW.is_c3_AOO = AOO_IN_pacing;
      AOO_B.PACING_REF_PWM_D5 = AOO_P.PWM_Value;
      rtb_PACE_CHARGE_CTRL_D2 = 0;
      rtb_ATR_PACE_CTRL_D8 = 1;
      rtb_ATR_GND_CTRL_D11 = 0;
      rtb_PACE_GND_CTRL_D10 = 1;
      rtb_LED_STATE_RED = false;
      rtb_LED_STATE_GREEN = true;
    }
  } else {
    /* case IN_pacing: */
    rtb_PACE_CHARGE_CTRL_D2 = 0;
    rtb_ATR_PACE_CTRL_D8 = 1;
    rtb_ATR_GND_CTRL_D11 = 0;
    rtb_PACE_GND_CTRL_D10 = 1;
    rtb_LED_STATE_RED = false;
    rtb_LED_STATE_GREEN = true;
    if (AOO_DW.temporalCounter_i1 >= (uint32_T)ceil(AOO_P.Constant_Value)) {
      AOO_DW.temporalCounter_i1 = 0U;
      AOO_DW.is_c3_AOO = AOO_IN_Chambers_Paced_Charging;
      AOO_B.PACING_REF_PWM_D5 = AOO_P.PWM_Value;
      rtb_PACE_CHARGE_CTRL_D2 = 1;
      rtb_ATR_PACE_CTRL_D8 = 0;
      rtb_ATR_GND_CTRL_D11 = 1;
      rtb_PACE_GND_CTRL_D10 = 0;
      rtb_LED_STATE_RED = true;
      rtb_LED_STATE_GREEN = false;
    }
  }

  /* End of Chart: '<Root>/AOO' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(AOO_DW.obj_n2.MW_DIGITALIO_HANDLE, rtb_PACE_GND_CTRL_D10 !=
                     0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(AOO_DW.obj_j.MW_DIGITALIO_HANDLE, rtb_PACE_CHARGE_CTRL_D2
                     != 0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(AOO_DW.obj_m.MW_DIGITALIO_HANDLE, rtb_ATR_PACE_CTRL_D8 != 0);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(AOO_DW.obj_l5.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(AOO_DW.obj_e.MW_DIGITALIO_HANDLE, AOO_B.PACING_REF_PWM_D5
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(AOO_DW.obj_l.MW_DIGITALIO_HANDLE, rtb_ATR_GND_CTRL_D11 != 0);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(AOO_DW.obj_n.MW_DIGITALIO_HANDLE, rtb_LED_STATE_RED);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(AOO_DW.obj.MW_DIGITALIO_HANDLE, rtb_LED_STATE_GREEN);
}

/* Model initialize function */
void AOO_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Write' */
  AOO_DW.obj_n2.matlabCodegenIsDeleted = false;
  AOO_DW.obj_n2.isInitialized = 1;
  AOO_DW.obj_n2.MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
  AOO_DW.obj_n2.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write1' */
  AOO_DW.obj_j.matlabCodegenIsDeleted = false;
  AOO_DW.obj_j.isInitialized = 1;
  AOO_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
  AOO_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write2' */
  AOO_DW.obj_m.matlabCodegenIsDeleted = false;
  AOO_DW.obj_m.isInitialized = 1;
  AOO_DW.obj_m.MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
  AOO_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write3' */
  AOO_DW.obj_l5.matlabCodegenIsDeleted = false;
  AOO_DW.obj_l5.isInitialized = 1;
  AOO_DW.obj_l5.MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
  AOO_DW.obj_l5.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write4' */
  AOO_DW.obj_e.matlabCodegenIsDeleted = false;
  AOO_DW.obj_e.isInitialized = 1;
  AOO_DW.obj_e.MW_DIGITALIO_HANDLE = MW_digitalIO_open(5U, 1);
  AOO_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write5' */
  AOO_DW.obj_l.matlabCodegenIsDeleted = false;
  AOO_DW.obj_l.isInitialized = 1;
  AOO_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
  AOO_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write6' */
  AOO_DW.obj_n.matlabCodegenIsDeleted = false;
  AOO_DW.obj_n.isInitialized = 1;
  AOO_DW.obj_n.MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
  AOO_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write7' */
  AOO_DW.obj.matlabCodegenIsDeleted = false;
  AOO_DW.obj.isInitialized = 1;
  AOO_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
  AOO_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void AOO_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!AOO_DW.obj_n2.matlabCodegenIsDeleted) {
    AOO_DW.obj_n2.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_n2.isInitialized == 1) && AOO_DW.obj_n2.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_n2.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!AOO_DW.obj_j.matlabCodegenIsDeleted) {
    AOO_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_j.isInitialized == 1) && AOO_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!AOO_DW.obj_m.matlabCodegenIsDeleted) {
    AOO_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_m.isInitialized == 1) && AOO_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!AOO_DW.obj_l5.matlabCodegenIsDeleted) {
    AOO_DW.obj_l5.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_l5.isInitialized == 1) && AOO_DW.obj_l5.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_l5.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!AOO_DW.obj_e.matlabCodegenIsDeleted) {
    AOO_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_e.isInitialized == 1) && AOO_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!AOO_DW.obj_l.matlabCodegenIsDeleted) {
    AOO_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_l.isInitialized == 1) && AOO_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  if (!AOO_DW.obj_n.matlabCodegenIsDeleted) {
    AOO_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_n.isInitialized == 1) && AOO_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!AOO_DW.obj.matlabCodegenIsDeleted) {
    AOO_DW.obj.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj.isInitialized == 1) && AOO_DW.obj.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
