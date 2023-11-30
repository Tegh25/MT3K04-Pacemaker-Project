/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VOO.c
 *
 * Code generated for Simulink model 'VOO'.
 *
 * Model version                  : 8.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Oct 15 20:08:29 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VOO.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<Root>/VOO' */
#define VOO_IN_Charging                ((uint8_T)1U)
#define VOO_IN_Pacing                  ((uint8_T)2U)

/* Block signals (default storage) */
B_VOO_T VOO_B;

/* Block states (default storage) */
DW_VOO_T VOO_DW;

/* Real-time model */
static RT_MODEL_VOO_T VOO_M_;
RT_MODEL_VOO_T *const VOO_M = &VOO_M_;

/* Model step function */
void VOO_step(void)
{
  int32_T rtb_LED_BLUE;
  int32_T rtb_LED_RED;
  int32_T rtb_PACE_CHARGE_CTRL_D2;
  int32_T rtb_PACE_GND_CTRL_D10;
  int32_T rtb_VENT_GND_CTRL_D12;
  int32_T rtb_VENT_PACE_CTRL_D9;

  /* Chart: '<Root>/VOO' incorporates:
   *  Constant: '<Root>/BPM'
   *  Constant: '<Root>/PWM'
   *  Constant: '<Root>/Pulse_Width'
   *  Constant: '<Root>/msecs'
   *  Product: '<Root>/Divide'
   */
  if (VOO_DW.temporalCounter_i1 < MAX_uint32_T) {
    VOO_DW.temporalCounter_i1++;
  }

  if (VOO_DW.is_active_c1_VOO == 0U) {
    VOO_DW.is_active_c1_VOO = 1U;
    VOO_DW.temporalCounter_i1 = 0U;
    VOO_DW.is_c1_VOO = VOO_IN_Charging;
    VOO_B.PACING_REF_PWM_D5 = VOO_P.PWM_Value;
    rtb_PACE_CHARGE_CTRL_D2 = 1;
    rtb_VENT_PACE_CTRL_D9 = 0;
    rtb_VENT_GND_CTRL_D12 = 1;
    rtb_PACE_GND_CTRL_D10 = 0;
    rtb_LED_RED = 0;
    rtb_LED_BLUE = 1;
  } else if (VOO_DW.is_c1_VOO == VOO_IN_Charging) {
    rtb_PACE_CHARGE_CTRL_D2 = 1;
    rtb_VENT_PACE_CTRL_D9 = 0;
    rtb_VENT_GND_CTRL_D12 = 1;
    rtb_PACE_GND_CTRL_D10 = 0;
    rtb_LED_RED = 0;
    rtb_LED_BLUE = 1;
    if (VOO_DW.temporalCounter_i1 >= (uint32_T)ceil(VOO_P.msecs_Value /
         VOO_P.BPM_Value - VOO_P.Pulse_Width_Value)) {
      VOO_DW.temporalCounter_i1 = 0U;
      VOO_DW.is_c1_VOO = VOO_IN_Pacing;
      VOO_B.PACING_REF_PWM_D5 = VOO_P.PWM_Value;
      rtb_PACE_CHARGE_CTRL_D2 = 0;
      rtb_VENT_PACE_CTRL_D9 = 1;
      rtb_VENT_GND_CTRL_D12 = 0;
      rtb_PACE_GND_CTRL_D10 = 1;
      rtb_LED_RED = 1;
      rtb_LED_BLUE = 0;
    }
  } else {
    /* case IN_Pacing: */
    rtb_PACE_CHARGE_CTRL_D2 = 0;
    rtb_VENT_PACE_CTRL_D9 = 1;
    rtb_VENT_GND_CTRL_D12 = 0;
    rtb_PACE_GND_CTRL_D10 = 1;
    rtb_LED_RED = 1;
    rtb_LED_BLUE = 0;
    if (VOO_DW.temporalCounter_i1 >= (uint32_T)ceil(VOO_P.Pulse_Width_Value)) {
      VOO_DW.temporalCounter_i1 = 0U;
      VOO_DW.is_c1_VOO = VOO_IN_Charging;
      VOO_B.PACING_REF_PWM_D5 = VOO_P.PWM_Value;
      rtb_PACE_CHARGE_CTRL_D2 = 1;
      rtb_VENT_PACE_CTRL_D9 = 0;
      rtb_VENT_GND_CTRL_D12 = 1;
      rtb_PACE_GND_CTRL_D10 = 0;
      rtb_LED_RED = 0;
      rtb_LED_BLUE = 1;
    }
  }

  /* End of Chart: '<Root>/VOO' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(VOO_DW.obj_h.MW_DIGITALIO_HANDLE, rtb_PACE_CHARGE_CTRL_D2
                     != 0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(VOO_DW.obj_j.MW_DIGITALIO_HANDLE, rtb_PACE_GND_CTRL_D10 !=
                     0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(VOO_DW.obj_b.MW_DIGITALIO_HANDLE, VOO_B.PACING_REF_PWM_D5
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(VOO_DW.obj_l.MW_DIGITALIO_HANDLE, rtb_VENT_GND_CTRL_D12 !=
                     0);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(VOO_DW.obj_ib.MW_DIGITALIO_HANDLE, rtb_VENT_PACE_CTRL_D9 !=
                     0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(VOO_DW.obj_i.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(VOO_DW.obj_n.MW_DIGITALIO_HANDLE, rtb_LED_RED != 0);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(VOO_DW.obj.MW_DIGITALIO_HANDLE, rtb_LED_BLUE != 0);
}

/* Model initialize function */
void VOO_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Write' */
  VOO_DW.obj_h.matlabCodegenIsDeleted = false;
  VOO_DW.obj_h.isInitialized = 1;
  VOO_DW.obj_h.MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
  VOO_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write1' */
  VOO_DW.obj_j.matlabCodegenIsDeleted = false;
  VOO_DW.obj_j.isInitialized = 1;
  VOO_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
  VOO_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write2' */
  VOO_DW.obj_b.matlabCodegenIsDeleted = false;
  VOO_DW.obj_b.isInitialized = 1;
  VOO_DW.obj_b.MW_DIGITALIO_HANDLE = MW_digitalIO_open(5U, 1);
  VOO_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write3' */
  VOO_DW.obj_l.matlabCodegenIsDeleted = false;
  VOO_DW.obj_l.isInitialized = 1;
  VOO_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
  VOO_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write4' */
  VOO_DW.obj_ib.matlabCodegenIsDeleted = false;
  VOO_DW.obj_ib.isInitialized = 1;
  VOO_DW.obj_ib.MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
  VOO_DW.obj_ib.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write5' */
  VOO_DW.obj_i.matlabCodegenIsDeleted = false;
  VOO_DW.obj_i.isInitialized = 1;
  VOO_DW.obj_i.MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
  VOO_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write6' */
  VOO_DW.obj_n.matlabCodegenIsDeleted = false;
  VOO_DW.obj_n.isInitialized = 1;
  VOO_DW.obj_n.MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
  VOO_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write7' */
  VOO_DW.obj.matlabCodegenIsDeleted = false;
  VOO_DW.obj.isInitialized = 1;
  VOO_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
  VOO_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void VOO_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!VOO_DW.obj_h.matlabCodegenIsDeleted) {
    VOO_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_h.isInitialized == 1) && VOO_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!VOO_DW.obj_j.matlabCodegenIsDeleted) {
    VOO_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_j.isInitialized == 1) && VOO_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!VOO_DW.obj_b.matlabCodegenIsDeleted) {
    VOO_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_b.isInitialized == 1) && VOO_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!VOO_DW.obj_l.matlabCodegenIsDeleted) {
    VOO_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_l.isInitialized == 1) && VOO_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!VOO_DW.obj_ib.matlabCodegenIsDeleted) {
    VOO_DW.obj_ib.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_ib.isInitialized == 1) && VOO_DW.obj_ib.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_ib.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!VOO_DW.obj_i.matlabCodegenIsDeleted) {
    VOO_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_i.isInitialized == 1) && VOO_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  if (!VOO_DW.obj_n.matlabCodegenIsDeleted) {
    VOO_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_n.isInitialized == 1) && VOO_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!VOO_DW.obj.matlabCodegenIsDeleted) {
    VOO_DW.obj.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj.isInitialized == 1) && VOO_DW.obj.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
