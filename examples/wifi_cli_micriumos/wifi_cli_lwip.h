/***************************************************************************//**
 * @file
 * @brief lwIP related-function prototypes
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
#ifndef WIFI_CLI_LWIP_H
#define WIFI_CLI_LWIP_H

#include "sl_wfx_cmd_api.h"
#include "sl_status.h"
#include "wifi_cli_params.h"
#include "lwip/stats.h"
#include "lwip/tcpip.h"
#include "lwip/raw.h"
#include "lwip/icmp.h"
#include "lwip/inet.h"
#include "lwip/inet_chksum.h"
#include "lwip/ip.h"
#include "lwiperf.h"

#define IPERF_DEFAULT_DURATION_SEC          10
#define IPERF_DEFAULT_PORT                  5001

#define IPERF_CLIENT_MODE                   0
#define IPERF_SERVER_MODE                   1

#define PING_DEFAULT_REQ_NB                 3
#define PING_DEFAULT_INTERVAL_SEC           1
#define PING_DEFAULT_RCV_TMO_SEC            1
#define PING_DEFAULT_DATA_SIZE              32

#ifndef PING_ID
#define PING_ID                             0xAFAF      /*!< LSB = MSB */
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************//**
 * @brief: Set station link status to up.
 *****************************************************************************/
sl_status_t set_sta_link_up(void);

/**************************************************************************//**
 * @brief: Set station link status to down.
 *****************************************************************************/
sl_status_t set_sta_link_down(void);

/**************************************************************************//**
 * @brief: Set AP link status to up.
 *****************************************************************************/
sl_status_t set_ap_link_up(void);

/**************************************************************************//**
 * @brief: Set AP link status to down.
 *****************************************************************************/
sl_status_t set_ap_link_down(void);

/**************************************************************************//**
 * @brief: Implementation of ping command.
 *
 * @param[in]
 *         + req_num: Number of request messages (ICMP)
 *         + ip_str: Remote IP's address
 *
 * @param[out]  None
 *
 * @return
 *        SL_STATUS_OK if success
 *        SL_STATUS_FAIL if error
 *****************************************************************************/
sl_status_t ping_cmd(uint32_t req_num, char *ip_str);

/**************************************************************************//**
 * @brief: Start iperf server mode.
 *****************************************************************************/
void iperf_server(void);

/**************************************************************************//**
 * @brief: Start iperf client mode.
 *
 * @param[in]
 *         + ip_str: IP address string of remote iperf server
 *         + duration: duration in seconds
 *         + remote_port: Port of remote iperf server
 *         + is_foreground_mode: enable/disable foreground mode
 *
 * @param[out] None
 *
 * @return     None
 *****************************************************************************/
void iperf_client(char *ip_str,
                  uint32_t duration,
                  uint32_t remote_port,
                  bool is_foreground_mode);

/**************************************************************************//**
 * @brief: Stop iperf server mode.
 *****************************************************************************/
void stop_iperf_server(void);

/**************************************************************************//**
 * @brief: Stop iperf client mode.
 *****************************************************************************/
void stop_iperf_client(void);

/**************************************************************************//**
 * @brief: Start lwip-related tasks.
 *****************************************************************************/
void lwip_init_start(void);

#ifdef __cplusplus
}
#endif

#endif /* WIFI_CLI_LWIP_H_ */
