/*
 * Copyright (C) 2019, Cirrent Inc
 *
 * All use of this software must be covered by a license agreement as described in
 * Cirrent Terms of Services (https://www.cirrent.com/terms-of-service/)
 *
 * DISCLAIMER. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OR CONDITION,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. LICENSORS HEREBY DISCLAIM
 * ALL LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE.
 */

/**
 * @file
 * Defines Cirrent Agent basic APIs
 */

/**
 * @mainpage Overview
 *
 * The Cirrent library provides Cirrent Agent (CA) that enables onboarding of an IoT
 * device onto a Wi-Fi network and diagnosing connectivity issues through Cirrent's
 * IoT Network Intelligence (INI).
 *
 * The Cirrent Agent provides the following functionality:
 * - ZipKey Network
 *   CA enables the device to connect to a ZipKey router's public Wi-Fi network.
 * - Private Wi-Fi Network
 *   CA enables the device to connect to a private Wi-Fi network using credentials
 *   retrieved through one of the onboarding processes.
 * - Cirrent Cloud integration
 *   A device running the Cirrent Agent automatically sends updates regarding the
 *   connection status to the Cirrent Cloud. This allows the monitoring of the device and
 *   capturing important data that can be used for diagnosing any connectivity issue
 *   through Cirrent's IoT Network Intelligence (INI).
 * - Configuration Update
 *   CA updates its configuration by adding newly known or available networks from the
 *   Cirrent Cloud.
 *
 * Types of onboarding processes:
 * - ZipKey onboarding
 *   The device looks for a nearby ZipKey network (with a known SSID and password which is
 *   pre-configured in the device). It connects to the cloud via the ZipKey network and
 *   uploads its status which includes scan result of other nearby networks. User can
 *   select the private network and provide the passkey using a device emulator on the
 *   Cirrent Cloud. Once the device receives the SSID and passkey of the private network,
 *   it disconnects from the ZipKey network and connects to the private network.
 * - SoftAP onboarding
 *   The device initiates SoftAP and starts an HTTP server over it. The ZipKey Dev tool
 *   phone app is used to connect to the device's SoftAP and send the private network
 *   credentials. Once the credentials are received and device joins the private network,
 *   SoftAP is brought down, along with the server.
 *
 *   For more information see
 *   <a href="https://support.cirrent.com/hc/en-us/articles/360000352866-SoftAP-considerations">this</a>.
 * - BLE onboarding
 *   Similar to SoftAP onboarding, the device receives the private network credentials over a BLE link.
 * .
 *
 * For more information on Cirrent Agent and how it works, check the articles
 * <a href="https://support.cirrent.com/hc/en-us/categories/201995283-Cirrent-Agent-CA-">here</a>.
 * \defgroup cirrent_api Cirrent API
 * \defgroup cirrent_data_struct Cirrent Data Structures
 */

#ifndef CIRRENT_H
#define CIRRENT_H

#include "cirrent_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * @addtogroup cirrent_data_struct
 *
 * Definition of data structures, enumerations required by Cirrent Agent
 *
 *  @{
 */

typedef enum ca_result_t
{
    CA_RESULT_SUCCESS                = 0,  /**< Operation success               */
    CA_RESULT_TIMEOUT                = 1,  /**< Timeout                         */
    CA_RESULT_ERROR                  = 2,  /**< Failed to perform operation     */
    CA_RESULT_INVALID_ARG            = 3,  /**< Invalid arguments               */
    CA_RESULT_UNINITIALIZED          = 4,  /**< Not initialized                 */
    CA_RESULT_NOT_READY              = 5,  /**< Not ready for access            */
    CA_RESULT_UNSUPPORTED            = 6,  /**< Unsupported operation           */
    CA_RESULT_ALREADY_INITIALIZED    = 7,  /**< Module has already been inited  */
    CA_RESULT_ALREADY_STARTED        = 8   /**< Module has already been started */
} CA_RESULT_T;
/**
 * @}
 */
 /**
  *
  * @addtogroup cirrent_api
  *
  * The API provided by Cirrent Agent Library for onboarding.
  *
  *  @{
  */
/**
 * Starts Cirrent Agent
 *
 * @param[in] init_config   : CA configuration parameter of type @ref CA_INIT_CONFIG_T
 *
 * @return @ref CA_RESULT_T      : CA_RESULT_SUCCESS - on success, error result type otherwise
 */
CA_RESULT_T ca_start(const CA_INIT_CONFIG_T *init_config);

/**
 * Stops Cirrent Agent
 *
 * @return @ref CA_RESULT_T      : CA_RESULT_SUCCESS - on success, error result type otherwise
 */
CA_RESULT_T ca_stop(void);

/**
 * Checks whether Cirrent Agent is running or not
 *
 * @return bool             : true if Cirrent Agent is running, false otherwise
 */
bool ca_is_running(void);
/**
 * @}
 */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CIRRENT_H */
