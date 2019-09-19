Below are the steps to follow for deploying the code.

- Open Arduino IDE & Go to Preferences Tab & update the "Additional Boards Manager URL" to  http://arduino.esp8266.com/stable/package_esp8266com_index.json.

- Install the USB Driver for uploading file change board to node MCU 0.9
https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers

- Install the below libraries in Arduino Under Tools -> Manage Libraries
1.  AzureIoTHub
1.  AzureIoTUtility
1.  AzureIoTProtocol_MQTT
1.  ArduinoJson 5.0.8

Please note the verson of Arduino JSON and downgrade if higher version is installed.

- Comment the below Line in Arduino.h File under "Local\Arduino15\packages"
//#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))

- Change the code in WifiClientSecure.h file under "Local\Arduino15\packages"

#define USING_AXTLS
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include "WiFiClientSecureAxTLS.h"
using namespace axTLS;

Take the above code out and comment the rest code below in file.

- Create an Iot Hub from Azure Portal & create new device

- Now, it is time to register our IoT device, NodeMCUv2. To do so;
1. Open your Azure Hub.
2. Click on IoT Devices under Device Manager.
3. Add a new device
4. Give it a name, check the box and save.

- Registering the Device in Iot Hub
1. Click on the created device and open it.
2. Get Devices Key and take a note.

- Download Device Explorer & install.
https://aka.ms/aziotdevexp

- Open Config.h in the Synced code from Git Hub & update the below values.
1. SSID Name of Wifi
2. Password of Wifi
3. Device Connection String obtained from above step.

- Now code is ready to be deployed.


- Sample Code

const int sensor_pin = A0; 
void setup() 
{ Serial.begin(9600);
}
 void loop() 
{ float moisture_percentage; 
 moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );
 Serial.print("Soil Moisture(in Percentage) = ");
 Serial.print(moisture_percentage);
 Serial.println("%"); delay(1000);


 }




