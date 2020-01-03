# PDM Data Generation Tool

### Overview
In order to get the Cirrent Agent to work, it needs to keep some data in the non-volatile memory. The PDM(Persistent Data Manager) data generation tool is used to generate that data in the form of a header file. The file contains the following information
1) **Credentials** : Account-Id, Device-Id and Secret of the registered device.
2) **Certificate** : The certificates required to perform HTTPS requests to the Cirrent Cloud.
3) **ZipKey Profiles** : The SSID and Password of ZipKey profiles fetched from Cirrent Cloud.

### Steps to generate the config file
**NOTE** : The tool can only be run on a Windows machine.
1) Register your device with Cirrent at https://support.cirrent.com/hc/en-us/articles/115000119646 and get the **Account Id**, **Device Id** and **Secret**.
2) Run the following command in the command prompt.
    ```
    pdm_generate.sh ACCOUNT_ID DEVICE_ID SECRET
    ```
3) The ca_config_data.h will be generated.
