# UART CLI Example

The purpose of this application is to provide a UART Command Line Interface (CLI) to allow interaction with part of the Wi-Fi FMAC driver and the LwIP APIs.

## Requirements

### Hardware Prerequisites

The example requires the hardware components below:

* [**EFM32 Giant Gecko GG11 Starter Kit (SLSTK3701A)**](https://www.silabs.com/products/development-tools/mcu/32-bit/efm32-giant-gecko-gg11-starter-kit) with
  [**WF200 Wi-Fi® Expansion Kit (SLEXP8022A)**](https://www.silabs.com/products/development-tools/wireless/wi-fi/wf200-expansion-kit) or
  [**WFM200S Wi-Fi® Expansion Kit (SLEXP8023A)**](https://www.silabs.com/products/development-tools/wireless/wi-fi/wfm200-expansion-kit)
* [**WGM160P Wi-Fi® Module Starter Kit**](https://www.silabs.com/products/development-tools/wireless/wi-fi/wgm160p-wifi-module-starter-kit)
* A mini USB cable
* A PC is required to configure the board and it can also be used to load a binary file on the board, to compile the Simplicity Studio project or run a serial terminal

### Software Prerequisites

The required software includes:

* The required software includes Simplicity Studio v5 and the Gecko SDK Suite (32-bit MCU SDK v6.0 or newer, Gecko Platform SDK v3.1 or newer, and Micrium OS Kernel SDK v5.10 or newer)
* The example project and the Wi-Fi Full MAC driver (available in the Gecko Platform SDK)
* Optionally: A Serial terminal to communicate with the board. For example, [**Tera Term**](https://osdn.net/projects/ttssh2/releases/) or [**Putty**](https://www.putty.org/)

## Set up your Kit

Please follow the instructions related to the platform suiting your case:

* [**EFM32 Giant Gecko GG11 Starter Kit setup**](https://github.com/SiliconLabs/wfx-fullMAC-tools/blob/master/Examples/SiliconLabs/shared/doc/slstk3701a/slstk3701a-setup.md)
* [**WGM160P Wi-Fi® Module Starter Kit setup**](https://github.com/SiliconLabs/wfx-fullMAC-tools/blob/master/Examples/SiliconLabs/shared/doc/wgm160p/wgm160p-setup.md)

## Install Simplicity Studio 5 and the SDKs

Simplicity Studio 5 is a free software suite needed to start developing your application. To install Simplicity Studio 5, please follow this [**procedure**](https://docs.silabs.com/simplicity-studio-5-users-guide/latest/ss-5-users-guide-getting-started/install-ss-5-and-software)  
by selecting the options **[Install by connecting device(s)]** and **[Auto]**.

## Get the example
Please follow this [**instruction**](https://docs.silabs.com/wifi/wf200/content-source/getting-started/silabs/wifi-commissioning-micriumos/getting-started#get-the-example)
Note that at step 6, the example name is **Platform - Wi-Fi CLI on Micrium OS kernel**

## Start the Example
1. Please follow this [**instruction**](https://docs.silabs.com/wifi/wf200/content-source/getting-started/silabs/wifi-commissioning-micriumos/getting-started#start-the-example)
Note that at step 5, the hex file name is **wifi_cli_micriumos.hex**

2. Reset the board using the **'RESET' button**. You should see the following output.

        FMAC Driver version    3.3.2
        WF200 Firmware version 3.12.2
        WF200 initialization successful
        Wi-Fi CLI Application Example
        
        >


3. The uart_cli project is ready to receive commands. You can start by the 'help' command to list available commands.
	The 'help' list below is provided as an indication. To access an up-to-date list, use the 'help' command on the target.

        help
        lwip                          lwip CLI commands
        reset                         Reset the host CPU
                                      [*] reset
        ping                          Send ICMP ECHO_REQUEST to network hosts
                                      [*] [-n nb] <ip>
        iperf                         Start a TCP iPerf test as a client or a server
                                      [*] iperf <-c ip [-t dur] [-p port] [-k] | -s>
        iperf_server_stop             Stop the running iPerf server
                                      [*] iperf_stop_server
        iperf_client_stop             Stop the running iPerf client
                                      [*] iperf_stop_client
        wifi                          Wifi CLI commands

Additionally, you can display the specific command help by entering:

```
@ [command] help
```
