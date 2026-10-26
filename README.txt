MH17 RADAR V2

FEATURES
- Animated radar screen
- Demo Mode with clearly labelled simulated targets
- Target tracking and active target list
- Optional radar beep
- CSV export of readings
- Arduino USB serial support in desktop Chrome/Edge

ARDUINO UNO + HC-SR04 + SG90 WIRING
HC-SR04 VCC -> 5V
HC-SR04 GND -> GND
HC-SR04 TRIG -> D9
HC-SR04 ECHO -> D10
Servo signal -> D6
Servo power -> suitable 5V supply
Servo GND and Arduino GND must be connected together.

Upload Arduino_Radar_Firmware.ino using Arduino IDE.
Set Serial Monitor to 9600 baud, then close it before connecting from the website.
Open the website on a computer using Chrome or Edge over HTTPS and click Connect Arduino.
The browser will ask you to choose the Arduino serial port.

This is a short-range ultrasonic scanner, not long-range radar.
Demo Mode shows simulated data only.
