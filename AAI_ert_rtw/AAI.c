/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AAI.c
 *
 * Code generated for Simulink model 'AAI'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Oct 15 22:13:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AAI.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<Root>/AAI' */
#define AAI_IN_Charging_and_Sensing    ((uint8_T)1U)
#define AAI_IN_Pacing                  ((uint8_T)2U)

/* Block signals (default storage) */
B_AAI_T AAI_B;

/* Block states (default storage) */
DW_AAI_T AAI_DW;

/* Real-time model */
static RT_MODEL_AAI_T AAI_M_;
RT_MODEL_AAI_T *const AAI_M = &AAI_M_;

/* Model step function */
void AAI_step(void)
{
  int32_T rtb_ATR_GND_CTRL_D11;
  int32_T rtb_ATR_PACE_CTRL_D8;
  int32_T rtb_PACE_CHARGE_CTRL_D2;
  int32_T rtb_PACE_GND_CTRL_D10;
  boolean_T rtb_DigitalRead_0;
  boolean_T rtb_LED_STATE_GREEN;
  boolean_T rtb_LED_STATE_RED;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (AAI_DW.obj.SampleTime != AAI_P.DigitalRead_SampleTime) {
    AAI_DW.obj.SampleTime = AAI_P.DigitalRead_SampleTime;
  }

  rtb_DigitalRead_0 = MW_digitalIO_read(AAI_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/AAI' incorporates:
   *  Constant: '<Root>/BPM'
   *  Constant: '<Root>/PWM'
   *  Constant: '<Root>/PWM1'
   *  Constant: '<Root>/PulseWidth_msecs'
   *  Constant: '<Root>/msecs'
   *  MATLABSystem: '<Root>/Digital Read'
   *  Product: '<Root>/Divide'
   */
  if (AAI_DW.temporalCounter_i1 < MAX_uint32_T) {
    AAI_DW.temporalCounter_i1++;
  }

  if (AAI_DW.is_active_c1_AAI == 0U) {
    AAI_DW.is_active_c1_AAI = 1U;
    AAI_DW.temporalCounter_i1 = 0U;
    AAI_DW.is_c1_AAI = AAI_IN_Charging_and_Sensing;
    AAI_B.PACING_REF_PWM_D5 = AAI_P.PWM1_Value;
    rtb_PACE_CHARGE_CTRL_D2 = 1;
    rtb_ATR_PACE_CTRL_D8 = 0;
    rtb_ATR_GND_CTRL_D11 = 1;
    rtb_PACE_GND_CTRL_D10 = 0;
    rtb_LED_STATE_RED = true;
    rtb_LED_STATE_GREEN = false;
    AAI_B.FRONTEND_CTRL_D13 = 1.0;
    AAI_B.ATR_CMP_REF_PWM_D6 = AAI_P.PWM_Value;
  } else if (AAI_DW.is_c1_AAI == AAI_IN_Charging_and_Sensing) {
    rtb_PACE_CHARGE_CTRL_D2 = 1;
    rtb_ATR_PACE_CTRL_D8 = 0;
    rtb_ATR_GND_CTRL_D11 = 1;
    rtb_PACE_GND_CTRL_D10 = 0;
    rtb_LED_STATE_RED = true;
    rtb_LED_STATE_GREEN = false;
    AAI_B.FRONTEND_CTRL_D13 = 1.0;
    if (rtb_DigitalRead_0) {
      AAI_DW.temporalCounter_i1 = 0U;
      AAI_B.PACING_REF_PWM_D5 = AAI_P.PWM1_Value;
      AAI_B.ATR_CMP_REF_PWM_D6 = AAI_P.PWM_Value;
    } else if (AAI_DW.temporalCounter_i1 >= (uint32_T)ceil(AAI_P.msecs_Value /
                AAI_P.BPM_Value - AAI_P.PulseWidth_msecs_Value)) {
      AAI_DW.temporalCounter_i1 = 0U;
      AAI_DW.is_c1_AAI = AAI_IN_Pacing;
      AAI_B.PACING_REF_PWM_D5 = AAI_P.PWM1_Value;
      rtb_PACE_CHARGE_CTRL_D2 = 0;
      rtb_ATR_PACE_CTRL_D8 = 1;
      rtb_ATR_GND_CTRL_D11 = 0;
      rtb_PACE_GND_CTRL_D10 = 1;
      rtb_LED_STATE_RED = false;
      rtb_LED_STATE_GREEN = true;
    }
  } else {
    /* case IN_Pacing: */
    rtb_PACE_CHARGE_CTRL_D2 = 0;
    rtb_ATR_PACE_CTRL_D8 = 1;
    rtb_ATR_GND_CTRL_D11 = 0;
    rtb_PACE_GND_CTRL_D10 = 1;
    rtb_LED_STATE_RED = false;
    rtb_LED_STATE_GREEN = true;
    if (AAI_DW.temporalCounter_i1 >= (uint32_T)ceil(AAI_P.PulseWidth_msecs_Value))
    {
      AAI_DW.temporalCounter_i1 = 0U;
      AAI_DW.is_c1_AAI = AAI_IN_Charging_and_Sensing;
      AAI_B.PACING_REF_PWM_D5 = AAI_P.PWM1_Value;
      rtb_PACE_CHARGE_CTRL_D2 = 1;
      rtb_ATR_PACE_CTRL_D8 = 0;
      rtb_ATR_GND_CTRL_D11 = 1;
      rtb_PACE_GND_CTRL_D10 = 0;
      rtb_LED_STATE_RED = true;
      rtb_LED_STATE_GREEN = false;
      AAI_B.FRONTEND_CTRL_D13 = 1.0;
      AAI_B.ATR_CMP_REF_PWM_D6 = AAI_P.PWM_Value;
    }
  }

  /* End of Chart: '<Root>/AAI' */

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(AAI_DW.obj_ib.MW_DIGITALIO_HANDLE, rtb_PACE_GND_CTRL_D10 !=
                     0);

  /* MATLABSystem: '<Root>/Digital Write10' */
  MW_digitalIO_write(AAI_DW.obj_e.MW_DIGITALIO_HANDLE, AAI_B.FRONTEND_CTRL_D13
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(AAI_DW.obj_ix.MW_DIGITALIO_HANDLE, rtb_PACE_CHARGE_CTRL_D2
                     != 0);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(AAI_DW.obj_n2.MW_DIGITALIO_HANDLE, rtb_ATR_PACE_CTRL_D8 !=
                     0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(AAI_DW.obj_j.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(AAI_DW.obj_m.MW_DIGITALIO_HANDLE, AAI_B.PACING_REF_PWM_D5
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(AAI_DW.obj_i.MW_DIGITALIO_HANDLE, rtb_ATR_GND_CTRL_D11 != 0);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(AAI_DW.obj_n.MW_DIGITALIO_HANDLE, rtb_LED_STATE_RED);

  /* MATLABSystem: '<Root>/Digital Write9' */
  MW_digitalIO_write(AAI_DW.obj_l.MW_DIGITALIO_HANDLE, rtb_LED_STATE_GREEN);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(AAI_DW.obj_b.MW_PWM_HANDLE, AAI_B.ATR_CMP_REF_PWM_D6);
}

/* Model initialize function */
void AAI_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Read' */
  AAI_DW.obj.matlabCodegenIsDeleted = false;
  AAI_DW.obj.SampleTime = AAI_P.DigitalRead_SampleTime;
  AAI_DW.obj.isInitialized = 1;
  AAI_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
  AAI_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write1' */
  AAI_DW.obj_ib.matlabCodegenIsDeleted = false;
  AAI_DW.obj_ib.isInitialized = 1;
  AAI_DW.obj_ib.MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
  AAI_DW.obj_ib.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write10' */
  AAI_DW.obj_e.matlabCodegenIsDeleted = false;
  AAI_DW.obj_e.isInitialized = 1;
  AAI_DW.obj_e.MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
  AAI_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write3' */
  AAI_DW.obj_ix.matlabCodegenIsDeleted = false;
  AAI_DW.obj_ix.isInitialized = 1;
  AAI_DW.obj_ix.MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
  AAI_DW.obj_ix.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write4' */
  AAI_DW.obj_n2.matlabCodegenIsDeleted = false;
  AAI_DW.obj_n2.isInitialized = 1;
  AAI_DW.obj_n2.MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
  AAI_DW.obj_n2.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write5' */
  AAI_DW.obj_j.matlabCodegenIsDeleted = false;
  AAI_DW.obj_j.isInitialized = 1;
  AAI_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
  AAI_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write6' */
  AAI_DW.obj_m.matlabCodegenIsDeleted = false;
  AAI_DW.obj_m.isInitialized = 1;
  AAI_DW.obj_m.MW_DIGITALIO_HANDLE = MW_digitalIO_open(5U, 1);
  AAI_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write7' */
  AAI_DW.obj_i.matlabCodegenIsDeleted = false;
  AAI_DW.obj_i.isInitialized = 1;
  AAI_DW.obj_i.MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
  AAI_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write8' */
  AAI_DW.obj_n.matlabCodegenIsDeleted = false;
  AAI_DW.obj_n.isInitialized = 1;
  AAI_DW.obj_n.MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
  AAI_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write9' */
  AAI_DW.obj_l.matlabCodegenIsDeleted = false;
  AAI_DW.obj_l.isInitialized = 1;
  AAI_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
  AAI_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM Output' */
  AAI_DW.obj_b.matlabCodegenIsDeleted = false;
  AAI_DW.obj_b.isInitialized = 1;
  AAI_DW.obj_b.MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
  MW_PWM_Start(AAI_DW.obj_b.MW_PWM_HANDLE);
  AAI_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void AAI_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!AAI_DW.obj.matlabCodegenIsDeleted) {
    AAI_DW.obj.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj.isInitialized == 1) && AAI_DW.obj.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!AAI_DW.obj_ib.matlabCodegenIsDeleted) {
    AAI_DW.obj_ib.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_ib.isInitialized == 1) && AAI_DW.obj_ib.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_ib.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write10' */
  if (!AAI_DW.obj_e.matlabCodegenIsDeleted) {
    AAI_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_e.isInitialized == 1) && AAI_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write10' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!AAI_DW.obj_ix.matlabCodegenIsDeleted) {
    AAI_DW.obj_ix.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_ix.isInitialized == 1) && AAI_DW.obj_ix.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_ix.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!AAI_DW.obj_n2.matlabCodegenIsDeleted) {
    AAI_DW.obj_n2.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_n2.isInitialized == 1) && AAI_DW.obj_n2.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_n2.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!AAI_DW.obj_j.matlabCodegenIsDeleted) {
    AAI_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_j.isInitialized == 1) && AAI_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  if (!AAI_DW.obj_m.matlabCodegenIsDeleted) {
    AAI_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_m.isInitialized == 1) && AAI_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!AAI_DW.obj_i.matlabCodegenIsDeleted) {
    AAI_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_i.isInitialized == 1) && AAI_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  if (!AAI_DW.obj_n.matlabCodegenIsDeleted) {
    AAI_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_n.isInitialized == 1) && AAI_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write9' */
  if (!AAI_DW.obj_l.matlabCodegenIsDeleted) {
    AAI_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_l.isInitialized == 1) && AAI_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write9' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!AAI_DW.obj_b.matlabCodegenIsDeleted) {
    AAI_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_b.isInitialized == 1) && AAI_DW.obj_b.isSetupComplete) {
      MW_PWM_Stop(AAI_DW.obj_b.MW_PWM_HANDLE);
      MW_PWM_Close(AAI_DW.obj_b.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
