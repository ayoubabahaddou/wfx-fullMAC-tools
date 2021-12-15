/***************************************************************************//**
 * @file
 * @brief wifi cli app on micrium os
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include "wifi_cli_app.h"

/*******************************************************************************
 ******************   Wi-Fi CLI Start App Task Configuration   *****************
 ******************************************************************************/
#define WFX_CLI_START_APP_TASK_PRIO             31u
#define WFX_CLI_START_APP_TASK_STACK_SIZE       256u

/* Wifi CLI start app task's stack */
static CPU_STK wfx_cli_start_app_task_stack[WFX_CLI_START_APP_TASK_STACK_SIZE];
/* Wifi CLI start app task's TCB (task control block) */
static OS_TCB wfx_cli_start_app_task_tcb;

/**************************************************************************//**
 * @brief: Wifi CLI start app task implementation.
 *****************************************************************************/
static void wfx_cli_start_app_task(void *p_arg) {
  PP_UNUSED_PARAM(p_arg);
  RTOS_ERR err;

  /* Wait until finishing wfx_driver initialization */
  OSSemPend(&wfx_init_sem,
            0,
            OS_OPT_PEND_BLOCKING,
            NULL,
            &err);

  /* Display Wi-Fi CLI application name */
  printf("Wi-Fi CLI Application Example\r\n");

  /* Start wifi events task handling indication message from wf200 */
  app_wifi_events_start();

  /* Start CLI's commands registration task */
  wifi_cli_commands_init();

  /* Start registering global wifi get/set parameters */
  wifi_cli_params_init();

  /* Start lwIP stack & related tasks */
  lwip_init_start();

  /* Delete this init task */
  OSTaskDel(NULL, &err);
}

/**************************************************************************//**
 * @brief: Initialize the Wi-Fi CLI app.
 *****************************************************************************/
void cli_app_init(void)
{
  RTOS_ERR err;

  /* CLI start app task */
  OSTaskCreate(&wfx_cli_start_app_task_tcb,
               "Wifi CLI app init",
               wfx_cli_start_app_task,
               DEF_NULL,
               WFX_CLI_START_APP_TASK_PRIO,
               &wfx_cli_start_app_task_stack[0],
               (WFX_CLI_START_APP_TASK_STACK_SIZE / 10u),
               WFX_CLI_START_APP_TASK_STACK_SIZE,
               0u,
               0u,
               DEF_NULL,
               (OS_OPT_TASK_STK_CLR),
               &err);

  /* Check err code */
  APP_RTOS_ASSERT_DBG((RTOS_ERR_CODE_GET(err) == RTOS_ERR_NONE), 1);
}
