/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.h
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

#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_PushButton_untitl_T obj; /* '<Root>/Push Button' */
  freedomk64f_DigitalWrite_unti_T obj_l;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_unti_T obj_b;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_unti_T obj_g;/* '<Root>/Digital Write' */
  uint8_T is_active_c3_untitled;       /* '<Root>/Chart' */
  uint8_T is_c3_untitled;              /* '<Root>/Chart' */
} DW_untitled_T;

/* Parameters (default storage) */
struct P_untitled_T_ {
  real_T PushButton_SampleTime;        /* Expression: SampleTime1
                                        * Referenced by: '<Root>/Push Button'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_untitled_T untitled_P;

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Chart'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
