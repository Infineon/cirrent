# Cirrent Agent Library

### Overview
The Cirrent Agent (CA) is an embedded code library that manages the Wi-Fi connection process. The CA provides all of the functionality required for a product to connect to a ZipKey or a private Wi-Fi network.

### Features
The Cirrent Agent library for MBED OS supports two types of onboarding:
- **Zipkey Onboarding** : When the ZipKey-enabled device is first powered up, the CA scans for nearby Wi-FI networks. If it sees a ZipKey network, it will automatically associate to that network, and upload its status to the Cirrent cloud. It will send requests to the Cirrent cloud, looking for any actions that it should perform. The actions that the CA can perform include:
    * Join private network
    * Delete private network
    * Identify action
    * Reset
- **SoftAP Onboarding** : SoftAP is a temporary Wi-Fi network that is brought up by the CA. The mobile app connects to the SoftAP Wi-Fi network and sends private Wi-Fi network credentials to the device. Then the device joins the private Wi-Fi network and the SoftAP network is brought down.

### Supported Platforms
* [PSoC6 WiFi-BT Prototyping Kit (CY8CPROTO-062-4343W)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wi-fi-bt-prototyping-kit-cy8cproto-062-4343w)
* [PSoC6 WiFi-BT Pioneer Kit (CY8CKIT-062-WiFi-BT)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wifi-bt-pioneer-kit-cy8ckit-062-wifi-bt)

### Dependencies
* [ARM mbed-os version 5.15 and above](https://os.mbed.com/mbed-os/releases)
* [Cypress HTTP Server Library](https://github.com/cypresssemiconductorco/http-server)
* [Cypress Connectivity Utilities Library](https://github.com/cypresssemiconductorco/connectivity-utilities)
* [HTTP Client Library](https://os.mbed.com/teams/sandbox/code/mbed-http/)

### Additional Information
* [Cirrent RELEASE.md](./RELEASE.md)
* [Cirrent library version](./version.txt)
* [Cirrent API Reference Guide](https://cypresssemiconductorco.github.io/cirrent/docs/api_reference_manual/html/index.html)
* More information about the CA can be found in the [Knowledge Center](https://support.cirrent.com/hc/en-us/categories/201995283-Wireless-Connection-Manager-CA-)
