/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AAI.h
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

#ifndef RTW_HEADER_AAI_h_
#define RTW_HEADER_AAI_h_
#ifndef AAI_COMMON_INCLUDES_
#define AAI_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* AAI_COMMON_INCLUDES_ */

#include "AAI_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PACING_REF_PWM_D5;            /* '<Root>/AAI' */
  real_T FRONTEND_CTRL_D13;            /* '<Root>/AAI' */
  real_T ATR_CMP_REF_PWM_D6;           /* '<Root>/AAI' */
} B_AAI_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_AAI_T obj;   /* '<Root>/Digital Read' */
  freedomk64f_DigitalWrite_AAI_T obj_l;/* '<Root>/Digital Write9' */
  freedomk64f_DigitalWrite_AAI_T obj_n;/* '<Root>/Digital Write8' */
  freedomk64f_DigitalWrite_AAI_T obj_i;/* '<Root>/Digital Write7' */
  freedomk64f_DigitalWrite_AAI_T obj_m;/* '<Root>/Digital Write6' */
  freedomk64f_DigitalWrite_AAI_T obj_j;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_AAI_T obj_n2;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_AAI_T obj_ix;/* '<Root>/Digital Write3' */
  freedomk64f_DigitalWrite_AAI_T obj_e;/* '<Root>/Digital Write10' */
  freedomk64f_DigitalWrite_AAI_T obj_ib;/* '<Root>/Digital Write1' */
  freedomk64f_PWMOutput_AAI_T obj_b;   /* '<Root>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/AAI' */
  uint8_T is_active_c1_AAI;            /* '<Root>/AAI' */
  uint8_T is_c1_AAI;                   /* '<Root>/AAI' */
} DW_AAI_T;

/* Parameters (default storage) */
struct P_AAI_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T PWM_Value;                    /* Expression: 80
                                        * Referenced by: '<Root>/PWM'
                                        */
  real_T msecs_Value;                  /* Expression: 60000
                                        * Referenced by: '<Root>/msecs'
                                        */
  real_T BPM_Value;                    /* Expression: 60
                                        * Referenced by: '<Root>/BPM'
                                        */
  real_T PWM1_Value;                   /* Expression: 100
                                        * Referenced by: '<Root>/PWM1'
                                        */
  real_T PulseWidth_msecs_Value;       /* Expression: 400
                                        * Referenced by: '<Root>/PulseWidth_msecs'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_AAI_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_AAI_T AAI_P;

/* Block signals (default storage) */
extern B_AAI_T AAI_B;

/* Block states (default storage) */
extern DW_AAI_T AAI_DW;

/* Model entry point functions */
extern void AAI_initialize(void);
extern void AAI_step(void);
extern void AAI_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AAI_T *const AAI_M;
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
 * '<Root>' : 'AAI'
 * '<S1>'   : 'AAI/AAI'
 */
#endif                                 /* RTW_HEADER_AAI_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
