// Physical device information for board and sensor
#define DEVICE_ID "Soil Moisturize Detector"

#define TEMPERATURE_ALERT 30

// Interval time(ms) for sending message to IoT Hub
#define INTERVAL 2000

// If don't have a physical DHT sensor, can send simulated data to IoT hub
#define SIMULATED_DATA false

// EEPROM address configuration
#define EEPROM_SIZE 512

// SSID and SSID password's length should < 32 bytes
// http://serverfault.com/a/45509
#define SSID_LEN 32
#define PASS_LEN 32
#define CONNECTION_STRING_LEN 256

#define MESSAGE_MAX_LEN 256

/**
 * WiFi setup
 */
#define IOT_CONFIG_WIFI_SSID            "iPhone"
#define IOT_CONFIG_WIFI_PASSWORD        "h1psnw3a71mrj"

/**
 * Find under Microsoft Azure IoT Suite -> DEVICES -> <your device> -> Device Details and Authentication Keys
 * String containing Hostname, Device Id & Device Key in the format:
 *  "HostName=<host_name>;DeviceId=<device_id>;SharedAccessKey=<device_key>"    
 */
#define IOT_CONFIG_CONNECTION_STRING    "HostName=garage01.azure-devices.net;DeviceId=test1;SharedAccessKey=bKxntD4XuKAdV/tGw81Fw+O0FO+1gdaXa+jPv7nDHnM="
