/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VVI.h
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

#ifndef RTW_HEADER_VVI_h_
#define RTW_HEADER_VVI_h_
#ifndef VVI_COMMON_INCLUDES_
#define VVI_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* VVI_COMMON_INCLUDES_ */

#include "VVI_types.h"
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
  real_T PACING_REF_PWM_D5;            /* '<Root>/VVI' */
  real_T FRONTEND_CTRL_D13;            /* '<Root>/VVI' */
  real_T VENT_CMP_REF_PWM_D3;          /* '<Root>/VVI' */
} B_VVI_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_VVI_T obj;   /* '<Root>/Digital Read' */
  freedomk64f_DigitalWrite_VVI_T obj_i;/* '<Root>/Digital Write8' */
  freedomk64f_DigitalWrite_VVI_T obj_ib;/* '<Root>/Digital Write7' */
  freedomk64f_DigitalWrite_VVI_T obj_l;/* '<Root>/Digital Write6' */
  freedomk64f_DigitalWrite_VVI_T obj_b;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_VVI_T obj_j;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_VVI_T obj_h;/* '<Root>/Digital Write3' */
  freedomk64f_DigitalWrite_VVI_T obj_h5;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_VVI_T obj_g;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_VVI_T obj_p;/* '<Root>/Digital Write' */
  freedomk64f_PWMOutput_VVI_T obj_n;   /* '<Root>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/VVI' */
  uint8_T is_active_c1_VVI;            /* '<Root>/VVI' */
  uint8_T is_c1_VVI;                   /* '<Root>/VVI' */
} DW_VVI_T;

/* Parameters (default storage) */
struct P_VVI_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T PWM1_Value;                   /* Expression: 80
                                        * Referenced by: '<Root>/PWM1'
                                        */
  real_T msecs_Value;                  /* Expression: 60000
                                        * Referenced by: '<Root>/msecs'
                                        */
  real_T BPM_Value;                    /* Expression: 60
                                        * Referenced by: '<Root>/BPM'
                                        */
  real_T PulseWidth_msecs_Value;       /* Expression: 400
                                        * Referenced by: '<Root>/PulseWidth_msecs'
                                        */
  real_T PWM_Value;                    /* Expression: 100
                                        * Referenced by: '<Root>/PWM'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_VVI_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_VVI_T VVI_P;

/* Block signals (default storage) */
extern B_VVI_T VVI_B;

/* Block states (default storage) */
extern DW_VVI_T VVI_DW;

/* Model entry point functions */
extern void VVI_initialize(void);
extern void VVI_step(void);
extern void VVI_terminate(void);

/* Real-time Model object */
extern RT_MODEL_VVI_T *const VVI_M;
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
 * '<Root>' : 'VVI'
 * '<S1>'   : 'VVI/VVI'
 */
#endif                                 /* RTW_HEADER_VVI_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
