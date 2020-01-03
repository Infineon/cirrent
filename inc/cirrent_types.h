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
 * Defines Cirrent Agent configuration parameters
 */

#ifndef CIRRENT_TYPES_H
#define CIRRENT_TYPES_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 *                      Macros
 ******************************************************/
#define SOFTAP_IP_MAX_LEN       16
#define SOFTAP_SSID_MAX_LEN     33

/******************************************************
 *                    Structures
 ******************************************************/
 /**
  *
  * @addtogroup cirrent_data_struct
  *
  * Definition of data structures, enumerations required by Cirrent Agent
  *
  *  @{
  */
/**
 * Cirrent Agent configuration parameters.
 *
 * This structure defines configuration parameters that must be set and passed to
 * @ref ca_start()
*/
typedef struct ca_init_config_t
{
    /**
     * Defines whether a device supports user binding.
     *
     * If the device is bound to a user account, it will not be added to the list of
     * nearby discoverable devices. It is never discoverable unless the user takes some
     * explicit action (in the app or on the device) to reset the device into onboarding
     * mode.
     *
     * For more information, see the article on
     * <a href="https://support.cirrent.com/hc/en-us/articles/115004510783-User-binding-and-discoverability">User-binding and discoverability</a>
     */
    bool user_binding_enabled;

    /**
     * Defines whether a device has a button which could be used by device users to enable the onboarding mode.
     *
     * For more information, see the article on
     * <a href="https://support.cirrent.com/hc/en-us/articles/115000102206-App-Design-Considerations">App Design Considerations</a>
     */
    bool onboarding_button_exists;

    /**
     * Enables or disables CA console logs.
     */
    bool log_print_enabled;

    /**
     * Contains the start address of device's flash memory where CA stores the configuration data.
     */
    uint32_t ca_fl_start;

    /**
     * Contains the size of the flash section on the device that is reserved for configuration data.
     */
    uint32_t ca_fl_size;

    /**
     * SoftAP configuration parameters.
     *
     * Defines the configuration parameters for SoftAP onboarding.
    */
    struct ca_softap_config_t
    {
        /**
         * Determines whether SoftAP onboarding is enabled or disabled.
         *
         * If the flag is not set, CA will not bring up the SoftAP network and will only
         * use ZipKey onboarding.
         */
        bool softap_enabled;

        /**
         * Defines the SSID of the SoftAP.
         */
        char ssid[SOFTAP_SSID_MAX_LEN];

        /**
         * Defines the SoftAP IP address.
         *
         * The DHCP and HTTP server will be started on this IP address.
         */
        char server_ip[SOFTAP_IP_MAX_LEN];

        /**
         * Defines the port where HTTP server should be started.
         */
        unsigned char server_port;
    } softap_config;

    /**
     * Time profile configuration parameters.
     *
     * This structure defines configuration parameters for various timer values used by
     * Cirrent Agent. All values are in seconds (s).
    */
    struct ca_time_profile_config_t
    {
        /**
         * Delay between scans when in disconnected state.
         */
        int disconnected_wifi_rescan_delay_timeout;

        /**
         * Timeout for dhcp request retry when in associated state.
         */
        int associated_dhcp_request_retry_timeout;

        /**
        * Timeout used while checking whether connection is established successfully.
        */
        int associated_check_connection_timeout;

        /**
         * Timeout for retrying connection check.
         */
        int check_connection_retry_timeout;

        /**
         * Timeout for JOINING status reporting to Cirrent Cloud after receiving private
         * network credentials when in connected state.
         */
        int connected_joining_status_timeout;

        /**
         * Duration between HTTP GET /action requests to Cirrent Cloud in slow interaction
         * mode, when in connected state.
         *
         * Slow cloud interaction mode follows fast interaction mode. Timeout of fast cloud
         * interaction mode depends on the type of connected network (ZipKey or private).
         */
        int connected_get_action_slow;

        /**
         * Delay before starting SoftAP for shared radio mode when there is no saved
         * private network credentials.
         *
         * Cirrent Agent will double this value when private network credentials are
         * present but the network is not in range.
         */
        int softap_start_delay;

    } time_profile_config;

} CA_INIT_CONFIG_T;
/**
 * @}
 */
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // CIRRENT_TYPES_H
