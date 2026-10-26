MH17 RADAR — REAL SENSOR STARTER PACKAGE

FILES
- index.html: radar display; receives live serial readings, no fake targets.
- Arduino_Radar_Firmware.ino: Arduino UNO firmware for HC-SR04 + SG90 servo.
- start_local_server.py: optional local static web server for testing.
- install_and_push_termux.sh: one-time helper to copy files into ~/MH17-RADAR and push them to GitHub from Termux.

UPLOAD WEBSITE FILES FROM TERMUX
1. Download and extract this ZIP on your phone.
2. In Termux, run the extracted install_and_push_termux.sh script (see steps from ChatGPT). It copies the new website and support files to ~/MH17-RADAR and pushes them to GitHub.

HARDWARE WIRING (UNO + HC-SR04 + SG90)
HC-SR04: VCC -> 5V, GND -> GND, TRIG -> D9, ECHO -> D10.
SG90 servo: signal -> D6. Use an appropriate 5V supply if needed and connect grounds together.

LAPTOP SETUP
1. Install/open Arduino IDE on the laptop.
2. Open Arduino_Radar_Firmware.ino, select Arduino Uno and the correct port, then Upload.
3. Open the published HTTPS MH17 RADAR website in desktop Chrome or Edge.
4. Click Connect Arduino and select the Arduino serial port.
5. Keep the tab open; after unplug/restart, reconnect using the button.

IMPORTANT
- Web Serial requires a supported desktop browser such as Chrome/Edge and user permission to select the serial port. A website cannot silently auto-connect to USB.
- HC-SR04 is an ultrasonic proximity scanner, not true long-range radar. Typical practical range is up to about 4 m in suitable conditions.
- This firmware is for UNO + HC-SR04 + SG90. If your actual sensor/firmware differs, wiring and serial format need adapting.
