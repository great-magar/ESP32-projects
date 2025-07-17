
# ESP32 LED Control with AJAX

This project allows you to control an LED connected to an ESP32 board using a web page accessed from any device on the same Wi-Fi network. The web interface uses AJAX to switch the LED ON and OFF without reloading the page, providing a smooth and responsive user experience.

---

## Features

- Connects ESP32 to your Wi-Fi network.
- Hosts a web server on port 80.
- Provides a web page with ON/OFF buttons to control the LED.
- Uses AJAX to update LED status instantly without page refresh.
- Mobile-friendly interface.

---

## Hardware Required

- ESP32 development board (e.g., ESP32 DevKit v1)
- LED connected to GPIO 2 (or use built-in LED if available)
- USB cable to connect ESP32 to your computer

---

## Setup Instructions

1. **Connect your LED**  
   Connect the positive leg (anode) of the LED to GPIO 2 on ESP32 and the negative leg (cathode) to GND via a suitable resistor (220Ω recommended).

2. **Update Wi-Fi Credentials**  
   Open the Arduino IDE and replace the following lines with your Wi-Fi SSID and password:
   ```cpp
   const char* ssid = "YOUR_WIFI_SSID";
   const char* password = "YOUR_WIFI_PASSWORD";
````

3. **Upload the Code**
   Upload the provided Arduino sketch to your ESP32 board.

4. **Find ESP32 IP Address**
   Open the Serial Monitor (baud rate 115200) after upload completes and wait for the message:

   ```
   WiFi connected.
   IP Address: 192.168.x.x
   ```

   Note the IP address.

5. **Control the LED**
   On any device connected to the same Wi-Fi, open a web browser and enter the ESP32 IP address (e.g., `http://192.168.x.x`).
   Use the **Turn ON** and **Turn OFF** buttons to control the LED. The status updates instantly.

---

## Troubleshooting

* **LED does not respond:** Check your wiring and make sure the LED is connected to GPIO 2.
* **ESP32 does not connect to Wi-Fi:** Verify SSID and password, and ensure you are connecting to a 2.4GHz Wi-Fi network.
* **No IP address shown:** Make sure Serial Monitor baud rate is set to 115200.
* **Page does not load:** Ensure your controlling device is on the same Wi-Fi network as the ESP32.

---

## License

This project is open-source and free to use.

---

## Author

Ganesh Kumar Pun

---

