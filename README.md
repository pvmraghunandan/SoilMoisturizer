Steps 
1 Go to preferences 
 http://arduino.esp8266.com/stable/package_esp8266com_index.json.
  Go to board manager and install 8266 version 2.5.2
2  install driver –  for uploading file change board to node mcu 0.9
2 proceed to portal.azure.com and create a hub.
Click on Create a Source > Internet of Things > IoT Hub
3 install all this library 
•	AzureIoTHub
•	AzureIoTUtility
•	AzureIoTProtocol_MQTT
•	ArduinoJson 5.0.8
Code changes
1 change in config.h
Change username 
Ssid and password and iot config connection string 
2 change in Arduino.h file 
Comment 
//#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
3  change in wificlientsecure.h file 
#define USING_AXTLS
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include "WiFiClientSecureAxTLS.h"
using namespace axTLS;
take this code out and comment the rest code below in file 



2 Azure IoT Hub
Now, it is time to register our IoT device, NodeMCUv2. To do so;
•	Open your Azure Hub.
•	Click on IoT Devices under Device Manager.
•	Add a new device
•	Give it a name, check the box and save.
3 Registering the Device
Click on the created device and open it.
Get Devices Key and update config files 
4 download code open it and Update your SSID Name, Password and Primary Key under your credentials.ino file from lines 28, 30, 32. Upload the code and open your serial monitor.
5 downgrade arduinojson to version 5.13.5
6 make changes in wificlientsecure.h file
7 arduino.h line no 135 
Comment //#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))



