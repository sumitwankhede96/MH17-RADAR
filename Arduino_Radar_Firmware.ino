#include <Servo.h>

Servo radarServo;
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int SERVO_PIN = 6;

long measureDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 25000UL);
  if (duration == 0) return -1;
  return (long)(duration * 0.0343 / 2.0);
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  radarServo.attach(SERVO_PIN);
  radarServo.write(90);
  delay(500);
}

void scanAt(int angle) {
  radarServo.write(angle);
  delay(35);
  long cm = measureDistanceCm();
  Serial.print(angle);
  Serial.print(',');
  Serial.println(cm);
}

void loop() {
  for (int angle = 0; angle <= 180; angle += 3) scanAt(angle);
  for (int angle = 180; angle >= 0; angle -= 3) scanAt(angle);
}
