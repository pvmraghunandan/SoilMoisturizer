#include <ArduinoJson.h>
#include <Wire.h>

const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */

void initSensor()
{
    
}


float readSoilMoisture()
{
    float moisture_percentage, moisture_value;

    //moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );
    moisture_value= analogRead(sensor_pin);
    moisture_value= moisture_value/10;
    return moisture_value;
}


bool readMessage(int messageId, char *payload)
{
    

    float temperature = 50.0;
    float moisture_value = readSoilMoisture();
    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
    JsonObject &root = jsonBuffer.createObject();
    root["deviceId"] = DEVICE_ID;
    root["messageId"] = messageId;
    bool temperatureAlert = false;

    
    if (std::isnan(moisture_value))
    {
        root["moisture_value"] = NULL;
    }
    else
    {
        root["moisture_value"] = moisture_value;
    }
    root.printTo(payload, MESSAGE_MAX_LEN);
    return temperatureAlert;
}

void parseTwinMessage(char *message)
{
    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(message);
    if (!root.success())
    {
        Serial.printf("Parse %s failed.\r\n", message);
        return;
    }

    if (root["desired"]["interval"].success())
    {
        interval = root["desired"]["interval"];
    }
    else if (root.containsKey("interval"))
    {
        interval = root["interval"];
    }
}
