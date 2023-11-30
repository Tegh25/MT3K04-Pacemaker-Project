/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VVI.c
 *
 * Code generated for Simulink model 'VVI'.
 *
 * Model version                  : 8.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Oct 15 22:22:39 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VVI.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<Root>/VVI' */
#define VVI_IN_Charging_and_Sensing    ((uint8_T)1U)
#define VVI_IN_Pacing                  ((uint8_T)2U)

/* Block signals (default storage) */
B_VVI_T VVI_B;

/* Block states (default storage) */
DW_VVI_T VVI_DW;

/* Real-time model */
static RT_MODEL_VVI_T VVI_M_;
RT_MODEL_VVI_T *const VVI_M = &VVI_M_;

/* Model step function */
void VVI_step(void)
{
  int32_T rtb_LED_BLUE;
  int32_T rtb_LED_RED;
  int32_T rtb_PACE_CHARGE_CTRL_D2;
  int32_T rtb_PACE_GND_CTRL_D10;
  int32_T rtb_VENT_GND_CTRL_D12;
  int32_T rtb_VENT_PACE_CTRL_D9;
  boolean_T rtb_DigitalRead_0;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (VVI_DW.obj.SampleTime != VVI_P.DigitalRead_SampleTime) {
    VVI_DW.obj.SampleTime = VVI_P.DigitalRead_SampleTime;
  }

  rtb_DigitalRead_0 = MW_digitalIO_read(VVI_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/VVI' incorporates:
   *  Constant: '<Root>/BPM'
   *  Constant: '<Root>/PWM'
   *  Constant: '<Root>/PWM1'
   *  Constant: '<Root>/PulseWidth_msecs'
   *  Constant: '<Root>/msecs'
   *  MATLABSystem: '<Root>/Digital Read'
   *  Product: '<Root>/Divide'
   */
  if (VVI_DW.temporalCounter_i1 < MAX_uint32_T) {
    VVI_DW.temporalCounter_i1++;
  }

  if (VVI_DW.is_active_c1_VVI == 0U) {
    VVI_DW.is_active_c1_VVI = 1U;
    VVI_DW.temporalCounter_i1 = 0U;
    VVI_DW.is_c1_VVI = VVI_IN_Charging_and_Sensing;
    VVI_B.PACING_REF_PWM_D5 = VVI_P.PWM_Value;
    rtb_PACE_CHARGE_CTRL_D2 = 1;
    rtb_VENT_PACE_CTRL_D9 = 0;
    rtb_VENT_GND_CTRL_D12 = 1;
    rtb_PACE_GND_CTRL_D10 = 0;
    rtb_LED_RED = 0;
    rtb_LED_BLUE = 1;
    VVI_B.FRONTEND_CTRL_D13 = 1.0;
    VVI_B.VENT_CMP_REF_PWM_D3 = VVI_P.PWM1_Value;
  } else if (VVI_DW.is_c1_VVI == VVI_IN_Charging_and_Sensing) {
    rtb_PACE_CHARGE_CTRL_D2 = 1;
    rtb_VENT_PACE_CTRL_D9 = 0;
    rtb_VENT_GND_CTRL_D12 = 1;
    rtb_PACE_GND_CTRL_D10 = 0;
    rtb_LED_RED = 0;
    rtb_LED_BLUE = 1;
    VVI_B.FRONTEND_CTRL_D13 = 1.0;
    if (rtb_DigitalRead_0) {
      VVI_DW.temporalCounter_i1 = 0U;
      VVI_B.PACING_REF_PWM_D5 = VVI_P.PWM_Value;
      VVI_B.VENT_CMP_REF_PWM_D3 = VVI_P.PWM1_Value;
    } else if (VVI_DW.temporalCounter_i1 >= (uint32_T)ceil(VVI_P.msecs_Value /
                VVI_P.BPM_Value - VVI_P.PulseWidth_msecs_Value)) {
      VVI_DW.temporalCounter_i1 = 0U;
      VVI_DW.is_c1_VVI = VVI_IN_Pacing;
      VVI_B.PACING_REF_PWM_D5 = VVI_P.PWM_Value;
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
    if (VVI_DW.temporalCounter_i1 >= (uint32_T)ceil(VVI_P.PulseWidth_msecs_Value))
    {
      VVI_DW.temporalCounter_i1 = 0U;
      VVI_DW.is_c1_VVI = VVI_IN_Charging_and_Sensing;
      VVI_B.PACING_REF_PWM_D5 = VVI_P.PWM_Value;
      rtb_PACE_CHARGE_CTRL_D2 = 1;
      rtb_VENT_PACE_CTRL_D9 = 0;
      rtb_VENT_GND_CTRL_D12 = 1;
      rtb_PACE_GND_CTRL_D10 = 0;
      rtb_LED_RED = 0;
      rtb_LED_BLUE = 1;
      VVI_B.FRONTEND_CTRL_D13 = 1.0;
      VVI_B.VENT_CMP_REF_PWM_D3 = VVI_P.PWM1_Value;
    }
  }

  /* End of Chart: '<Root>/VVI' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(VVI_DW.obj_p.MW_DIGITALIO_HANDLE, rtb_PACE_CHARGE_CTRL_D2
                     != 0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(VVI_DW.obj_g.MW_DIGITALIO_HANDLE, rtb_PACE_GND_CTRL_D10 !=
                     0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(VVI_DW.obj_h5.MW_DIGITALIO_HANDLE, VVI_B.PACING_REF_PWM_D5
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(VVI_DW.obj_h.MW_DIGITALIO_HANDLE, rtb_VENT_GND_CTRL_D12 !=
                     0);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(VVI_DW.obj_j.MW_DIGITALIO_HANDLE, rtb_VENT_PACE_CTRL_D9 !=
                     0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(VVI_DW.obj_b.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(VVI_DW.obj_l.MW_DIGITALIO_HANDLE, rtb_LED_RED != 0);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(VVI_DW.obj_ib.MW_DIGITALIO_HANDLE, rtb_LED_BLUE != 0);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(VVI_DW.obj_i.MW_DIGITALIO_HANDLE, VVI_B.FRONTEND_CTRL_D13
                     != 0.0);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(VVI_DW.obj_n.MW_PWM_HANDLE, VVI_B.VENT_CMP_REF_PWM_D3);
}

/* Model initialize function */
void VVI_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Read' */
  VVI_DW.obj.matlabCodegenIsDeleted = false;
  VVI_DW.obj.SampleTime = VVI_P.DigitalRead_SampleTime;
  VVI_DW.obj.isInitialized = 1;
  VVI_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
  VVI_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write' */
  VVI_DW.obj_p.matlabCodegenIsDeleted = false;
  VVI_DW.obj_p.isInitialized = 1;
  VVI_DW.obj_p.MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
  VVI_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write1' */
  VVI_DW.obj_g.matlabCodegenIsDeleted = false;
  VVI_DW.obj_g.isInitialized = 1;
  VVI_DW.obj_g.MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
  VVI_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write2' */
  VVI_DW.obj_h5.matlabCodegenIsDeleted = false;
  VVI_DW.obj_h5.isInitialized = 1;
  VVI_DW.obj_h5.MW_DIGITALIO_HANDLE = MW_digitalIO_open(5U, 1);
  VVI_DW.obj_h5.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write3' */
  VVI_DW.obj_h.matlabCodegenIsDeleted = false;
  VVI_DW.obj_h.isInitialized = 1;
  VVI_DW.obj_h.MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
  VVI_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write4' */
  VVI_DW.obj_j.matlabCodegenIsDeleted = false;
  VVI_DW.obj_j.isInitialized = 1;
  VVI_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
  VVI_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write5' */
  VVI_DW.obj_b.matlabCodegenIsDeleted = false;
  VVI_DW.obj_b.isInitialized = 1;
  VVI_DW.obj_b.MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
  VVI_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write6' */
  VVI_DW.obj_l.matlabCodegenIsDeleted = false;
  VVI_DW.obj_l.isInitialized = 1;
  VVI_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
  VVI_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write7' */
  VVI_DW.obj_ib.matlabCodegenIsDeleted = false;
  VVI_DW.obj_ib.isInitialized = 1;
  VVI_DW.obj_ib.MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
  VVI_DW.obj_ib.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write8' */
  VVI_DW.obj_i.matlabCodegenIsDeleted = false;
  VVI_DW.obj_i.isInitialized = 1;
  VVI_DW.obj_i.MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
  VVI_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM Output' */
  VVI_DW.obj_n.matlabCodegenIsDeleted = false;
  VVI_DW.obj_n.isInitialized = 1;
  VVI_DW.obj_n.MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
  MW_PWM_Start(VVI_DW.obj_n.MW_PWM_HANDLE);
  VVI_DW.obj_n.isSetupComplete = true;
}

/* Model terminate function */
void VVI_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!VVI_DW.obj.matlabCodegenIsDeleted) {
    VVI_DW.obj.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj.isInitialized == 1) && VVI_DW.obj.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!VVI_DW.obj_p.matlabCodegenIsDeleted) {
    VVI_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_p.isInitialized == 1) && VVI_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!VVI_DW.obj_g.matlabCodegenIsDeleted) {
    VVI_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_g.isInitialized == 1) && VVI_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!VVI_DW.obj_h5.matlabCodegenIsDeleted) {
    VVI_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_h5.isInitialized == 1) && VVI_DW.obj_h5.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_h5.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!VVI_DW.obj_h.matlabCodegenIsDeleted) {
    VVI_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_h.isInitialized == 1) && VVI_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!VVI_DW.obj_j.matlabCodegenIsDeleted) {
    VVI_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_j.isInitialized == 1) && VVI_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!VVI_DW.obj_b.matlabCodegenIsDeleted) {
    VVI_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_b.isInitialized == 1) && VVI_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  if (!VVI_DW.obj_l.matlabCodegenIsDeleted) {
    VVI_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_l.isInitialized == 1) && VVI_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!VVI_DW.obj_ib.matlabCodegenIsDeleted) {
    VVI_DW.obj_ib.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_ib.isInitialized == 1) && VVI_DW.obj_ib.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_ib.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  if (!VVI_DW.obj_i.matlabCodegenIsDeleted) {
    VVI_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_i.isInitialized == 1) && VVI_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write8' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!VVI_DW.obj_n.matlabCodegenIsDeleted) {
    VVI_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_n.isInitialized == 1) && VVI_DW.obj_n.isSetupComplete) {
      MW_PWM_Stop(VVI_DW.obj_n.MW_PWM_HANDLE);
      MW_PWM_Close(VVI_DW.obj_n.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
