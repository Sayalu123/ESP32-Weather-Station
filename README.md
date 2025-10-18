# 🌦️ ESP32 Smart Weather Station (Wokwi Simulation)

This is a virtual IoT project built using **ESP32**, **DHT22**, **OLED display**, and **RGB LED** —  
simulated entirely in [Wokwi](https://wokwi.com/).

## 🔧 Features
- Displays real-time **temperature** and **humidity** on OLED.
- RGB LED indicates current **weather condition** based on temperature and humidity:

  | LED Colour  | Meaning                 |
  |-------------|-------------------------|
  | 🔴 Red     | Hot & Dry                |
  | 🟢 Green   | Pleasant                 |
  | 🔵 Blue    | Rainy / Humid            |
  | ⚪ White   | Cool & Moist             |
  | ⚫ OFF     | Unstable / Sensor Error  |
  -----------------------------------------

- Works **100% virtually** — no physical components required.

## 💻 How to Run
1. Go to [https://wokwi.com](https://wokwi.com).
2. Create a new project → select **ESP32**.
3. Copy and paste the code from `wifi-scan/wifi-scan.ino`.
4. Add the libraries listed in `libraries.txt`.
5. Click **Start Simulation** to view live readings on the OLED display.


## 🧠 Logic
- The ESP32 reads data from the DHT22 sensor.  
- Depending on both **temperature** and **humidity**, the RGB LED changes colour to indicate weather comfort levels.  
- OLED displays both readings every few seconds.


👩‍💻 **Developed by:** Sayali Mangale
💡 **Simulated on:** Wokwi IoT Platform  
✨ **Languages Used:** C++ / Arduino Framework
