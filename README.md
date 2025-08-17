# IOT-automatic-irrigation-system
Abstract 

This project presents an Automated Irrigation System based on IoT and embedded systems to ensure efficient water management for agricultural applications. The system uses soil moisture sensors to monitor soil conditions and automatically controls the water pump when irrigation is necessary. The integration of an LCD display provides real-time status updates to the user. The project is built around a microcontroller that processes sensor data and automates the irrigation process based on threshold values. This not only conserves water but also minimizes human intervention, making it highly suitable for small-scale and remote agricultural settings. 

 The system architecture consists of: 

    Arduino Nano as the control unit. 
    DHT11 sensor to monitor temperature and humidity. 
    Soil moisture sensor to determine if the soil is dry or wet.
    Rain sensor to detect rainfall and override irrigation. 
    Relay module to control the DC pump.
    DC Pump to deliver water. 
    16x2 LCD display to provide real-time information to the user. 

All components are connected such that the Arduino reads input from the sensors and triggers the pump when required. 


Hardware Integration 

The Arduino receives analog and digital input from the sensors. The soil moisture sensor provides analog values (0–1023), while the rain sensor and DHT11 provide digital signals. 

    Soil Moisture Sensor: Connected to A2 (analog pin) on Arduino Nano. 
    Rain Sensor: Connected to A1 (digital pin). 
    DHT11: Connected to digital pin D2. 
    Relay Module: Connected to A0 (to control the pump). 
    LCD: Uses pins D4 to D9. 

The Arduino executes the logic every 2 seconds using millis() to update the LCD and check environmental conditions. 
