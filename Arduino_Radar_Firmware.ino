/* MH17 RADAR: Arduino UNO + HC-SR04 + SG90 servo
   HC-SR04: VCC->5V, GND->GND, TRIG->D9, ECHO->D10
   SG90 signal->D6; servo needs suitable 5V supply and shared GND.
   Serial output at 9600 baud: angle,distance_cm
*/
#include <Servo.h>
const byte TRIG_PIN=9, ECHO_PIN=10, SERVO_PIN=6;
const int MIN_ANGLE=15, MAX_ANGLE=165, STEP_ANGLE=3;
Servo scanServo;
float readDistanceCm(){digitalWrite(TRIG_PIN,LOW);delayMicroseconds(3);digitalWrite(TRIG_PIN,HIGH);delayMicroseconds(10);digitalWrite(TRIG_PIN,LOW);unsigned long duration=pulseIn(ECHO_PIN,HIGH,25000UL);if(duration==0)return -1.0;return duration*0.0343f/2.0f;}
void scanAt(int angle){scanServo.write(angle);delay(35);float cm=readDistanceCm();Serial.print(angle);Serial.print(',');if(cm<0||cm>400)Serial.println(-1);else Serial.println(cm,1);delay(20);}
void setup(){pinMode(TRIG_PIN,OUTPUT);pinMode(ECHO_PIN,INPUT);digitalWrite(TRIG_PIN,LOW);scanServo.attach(SERVO_PIN);Serial.begin(9600);scanServo.write(90);delay(500);}
void loop(){for(int a=MIN_ANGLE;a<=MAX_ANGLE;a+=STEP_ANGLE)scanAt(a);for(int a=MAX_ANGLE;a>=MIN_ANGLE;a-=STEP_ANGLE)scanAt(a);}
