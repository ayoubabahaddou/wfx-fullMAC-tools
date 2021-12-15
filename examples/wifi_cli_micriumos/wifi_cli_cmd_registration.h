/***************************************************************************//**
 * @file
 * @brief Wi-Fi CLI's commands registration function prototypes
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
#ifndef WIFI_CLI_CMD_REGISTRATION_H
#define WIFI_CLI_CMD_REGISTRATION_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @brief Create the task for registering CLI commands
 ******************************************************************************/
void wifi_cli_commands_init(void);

#ifdef __cplusplus
}
#endif

#endif /* WIFI_CLI_CMD_REGISTRATION_H */
