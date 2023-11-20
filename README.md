Arduino MQTT LED Control

This repository contains Arduino code for a simple Internet of Things (IoT) project that enables remote control of an LED using the MQTT (Message Queuing Telemetry Transport) protocol. The project is designed for an Arduino Uno connected to the Internet via an ESP8266 or ESP32 module.

## Project Overview
- Hardware components: Arduino Uno, LED, 220-ohm resistor, and ESP8266/ESP32 for Internet connectivity.
- MQTT protocol used for communication and control.
- LED controlled remotely through MQTT messages.

## How It Works
1. The Arduino Uno subscribes to the MQTT topic "casa/arduino/led."
2. MQTT messages with the payload "1" turn on the LED; "0" turns it off.
3. LED state changes are controlled remotely through MQTT.

## Getting Started
- Clone this repository to your local machine.
- Open the Arduino IDE and install the necessary libraries (PubSubClient).
- Configure the Wi-Fi credentials, MQTT server details, and MQTT topic in the code.
- Upload the code to your Arduino Uno with an ESP8266/ESP32 module.

Feel free to explore and modify the code for your specific IoT projects.

1. **Wi-Fi Configuration:**
   - Set your Wi-Fi network SSID and password in the code.

2. **MQTT Server Configuration:**
   - Update the MQTT server details (server address, port, username, and password).

3. **MQTT Topic:**
   - Customize the MQTT topic as needed. The default is "casa/arduino/led."

4. **Arduino IDE:**
   - Open the Arduino IDE and install the PubSubClient library.

5. **Upload:**
   - Connect your Arduino Uno with the ESP8266/ESP32 module.
   - Upload the code to the Arduino.

6. **Monitor:**
   - Open the serial monitor to view debug messages and MQTT activity.

Feel free to adapt the code for your specific IoT projects and configurations.


