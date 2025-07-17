
# ESP32 Blink LED Project

This is a beginner-friendly project to blink an LED on the ESP32 development board. It demonstrates basic GPIO control using Arduino IDE.

---

## Features

- Blinks an LED connected to the ESP32 at a fixed interval.
- Uses GPIO 2 by default (built-in LED on many ESP32 boards).
- Simple code suitable for beginners learning ESP32 programming.

---

## Hardware Required

- ESP32 development board (e.g., ESP32 DevKit v1)
- LED connected to GPIO 2 (or use built-in LED)
- USB cable for programming and power

---

## Setup Instructions

1. **Connect the LED (optional)**  
   If your board doesn’t have a built-in LED on GPIO 2, connect an external LED to GPIO 2 with a 220Ω resistor to GND.

2. **Upload the Code**  
   Open the Arduino IDE, paste the blink code, and upload it to your ESP32.

3. **Observe the LED**  
   The LED will blink ON and OFF at a set interval (e.g., 1 second).

---

## Example Blink Code

```cpp
const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);  // Turn LED ON
  delay(1000);                 // Wait 1 second
  digitalWrite(ledPin, LOW);   // Turn LED OFF
  delay(1000);                 // Wait 1 second
}
````

---

## Troubleshooting

* **LED not blinking:** Check wiring and make sure you use the correct GPIO pin.
* **Upload errors:** Verify board and port selection in Arduino IDE.

---

## License

This project is open-source and free to use.

---

## Author

Ganesh Kumar Pun

---

