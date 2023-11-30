/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Nov 21 23:32:44 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define untitled_IN_LED_BLUE_STATE     ((uint8_T)1U)
#define untitled_IN_LED_GREEN_STATE    ((uint8_T)2U)
#define untitled_IN_LED_RED_STATE      ((uint8_T)3U)

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  boolean_T rtb_LED_BLUE;
  boolean_T rtb_LED_GREEN;
  boolean_T rtb_LED_RED;
  boolean_T rtb_PushButton_0;

  /* MATLABSystem: '<Root>/Push Button' */
  if (untitled_DW.obj.SampleTime != untitled_P.PushButton_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.PushButton_SampleTime;
  }

  rtb_PushButton_0 = MW_digitalIO_read(untitled_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<Root>/Push Button'
   */
  if (untitled_DW.is_active_c3_untitled == 0U) {
    untitled_DW.is_active_c3_untitled = 1U;
    untitled_DW.is_c3_untitled = untitled_IN_LED_RED_STATE;
    rtb_LED_RED = true;
    rtb_LED_BLUE = false;
    rtb_LED_GREEN = false;
  } else {
    switch (untitled_DW.is_c3_untitled) {
     case untitled_IN_LED_BLUE_STATE:
      rtb_LED_RED = false;
      rtb_LED_BLUE = true;
      rtb_LED_GREEN = false;
      if (rtb_PushButton_0) {
        untitled_DW.is_c3_untitled = untitled_IN_LED_GREEN_STATE;
        rtb_LED_BLUE = false;
        rtb_LED_GREEN = true;
      }
      break;

     case untitled_IN_LED_GREEN_STATE:
      rtb_LED_RED = false;
      rtb_LED_BLUE = false;
      rtb_LED_GREEN = true;
      if (rtb_PushButton_0) {
        untitled_DW.is_c3_untitled = untitled_IN_LED_RED_STATE;
        rtb_LED_RED = true;
        rtb_LED_GREEN = false;
      }
      break;

     default:
      /* case IN_LED_RED_STATE: */
      rtb_LED_RED = true;
      rtb_LED_BLUE = false;
      rtb_LED_GREEN = false;
      if (rtb_PushButton_0) {
        untitled_DW.is_c3_untitled = untitled_IN_LED_BLUE_STATE;
        rtb_LED_RED = false;
        rtb_LED_BLUE = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(untitled_DW.obj_g.MW_DIGITALIO_HANDLE, rtb_LED_RED);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(untitled_DW.obj_b.MW_DIGITALIO_HANDLE, rtb_LED_BLUE);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(untitled_DW.obj_l.MW_DIGITALIO_HANDLE, rtb_LED_GREEN);
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Push Button' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.PushButton_SampleTime;
  untitled_DW.obj.isInitialized = 1;
  untitled_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(45U, 0);
  untitled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write' */
  untitled_DW.obj_g.matlabCodegenIsDeleted = false;
  untitled_DW.obj_g.isInitialized = 1;
  untitled_DW.obj_g.MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
  untitled_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write1' */
  untitled_DW.obj_b.matlabCodegenIsDeleted = false;
  untitled_DW.obj_b.isInitialized = 1;
  untitled_DW.obj_b.MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
  untitled_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write2' */
  untitled_DW.obj_l.matlabCodegenIsDeleted = false;
  untitled_DW.obj_l.isInitialized = 1;
  untitled_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
  untitled_DW.obj_l.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Push Button' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1) && untitled_DW.obj.isSetupComplete)
    {
      MW_digitalIO_close(untitled_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Push Button' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!untitled_DW.obj_g.matlabCodegenIsDeleted) {
    untitled_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_g.isInitialized == 1) &&
        untitled_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!untitled_DW.obj_b.matlabCodegenIsDeleted) {
    untitled_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_b.isInitialized == 1) &&
        untitled_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!untitled_DW.obj_l.matlabCodegenIsDeleted) {
    untitled_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_l.isInitialized == 1) &&
        untitled_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
