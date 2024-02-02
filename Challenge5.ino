// including library and setting up servos
#include <Servo.h>
Servo leftservo;
Servo rightservo;
void setup() {
  // attaching servos and LED's to their digital pins
leftservo.attach(11);
rightservo.attach(12);
pinMode(3, OUTPUT); // GREEN LED
pinMode(4,OUTPUT); // RED LED
pinMode(5, OUTPUT); // YELLOW LED
Serial.begin(9600);
}
void loop() {
// Challenge 5
// setting up the photoresistor and inputs for troubleshooting
int val = analogRead(2);
Serial.println(val);
delay(100);
// bright light, spin in circles, red LED
if(val > 900) {
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  spin();
}
// shadow, reverse slowly, yellow LED
if(val < 650) {
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  reverse();
}
// ambient light, move forward, green LED
if (val < 900 && val > 650) {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  forward();
}
}
// setting up all the user-defined functions

// medium forward
void forward() {
  leftservo.writeMicroseconds(1100);
  rightservo.writeMicroseconds(1900);
}
// reverse slowly
void reverse() {
  leftservo.writeMicroseconds(1600);
  rightservo.writeMicroseconds(1400);
}
// spin
void spin() {
  leftservo.writeMicroseconds(1000);
  rightservo.writeMicroseconds(1000);
}