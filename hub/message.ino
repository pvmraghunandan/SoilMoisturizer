#include <Adafruit_Sensor.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include <Wire.h>

#if SIMULATED_DATA

void initSensor()
{
    // use SIMULATED_DATA, no sensor need to be inited
}

float readTemperature()
{
    return random(20, 30);
}

float readHumidity()
{
    return random(30, 40);
}

float loop() {
  float moisture_percentage;

  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");

  delay(1000);
  return moisture_percentage;
}   
#else
const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */




static DHT dht(DHT_PIN, DHT_TYPE);
void initSensor()
{
    dht.begin();
}

float readTemperature()
{
    return dht.readTemperature();
}

float readHumidity()
{
  float moisture_percentage;

  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );
    return moisture_percentage;
}

#endif

bool readMessage(int messageId, char *payload)
{
    

    float temperature = 50.0;
    float humidity = readHumidity();
    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
    JsonObject &root = jsonBuffer.createObject();
    root["deviceId"] = DEVICE_ID;
    root["messageId"] = messageId;
    bool temperatureAlert = false;

    // NAN is not the valid json, change it to NULL
    if (std::isnan(temperature))
    {
        root["temperature"] = NULL;
    }
    else
    {
        root["temperature"] = temperature;
        if (temperature > TEMPERATURE_ALERT)
        {
            temperatureAlert = true;
        }
    }

    if (std::isnan(humidity))
    {
        root["humidity"] = NULL;
    }
    else
    {
        root["humidity"] = humidity;
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
