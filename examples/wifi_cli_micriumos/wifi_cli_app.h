/***************************************************************************//**
 * @file
 * @brief Wi-Fi CLI application initialization on micrium os
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
#ifndef WIFI_CLI_APP_H
#define WIFI_CLI_APP_H

#include <string.h>
#include <stdio.h>
#include "os.h"
#include "wifi_cli_cmd_registration.h"
#include "wifi_cli_lwip.h"
#include "wifi_cli_params.h"
#include "sl_wfx_host.h"
#include "app_wifi_events.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @brief: Initialize the Wi-Fi CLI app.
 ******************************************************************************/
 void cli_app_init(void);

#ifdef __cplusplus
}
#endif

#endif  /* WIFI_CLI_APP_H */
