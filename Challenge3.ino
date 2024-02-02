// including libraries and servo set up
#include <Servo.h>
Servo leftservo;
Servo rightservo;
void setup() {
// attaching servos and LEDs to digital pins
leftservo.attach(11);
rightservo.attach(12);
pinMode(7, INPUT);
pinMode(4,OUTPUT);
pinMode(5, OUTPUT);
Serial.begin(9600);
}

void loop() {
// when button is pressed, make robot go (Challenge 1)
digitalWrite(4, LOW);
digitalWrite(5, LOW);
int switchStatus = digitalRead(7);
Serial.println(switchStatus);
if(switchStatus == 1) {
delay(750);
// Challenge 3
// random movement pattern
  forward();
  delay(750);
  spin();
  delay(500);
  turnleft();
  delay(800);
  spin();
  delay(500);
  turnright();
  delay(900);
  still();
// while loop so that the pattern repeats 3 times
int x = 0;
while (x < 3) {
// random LED pattern
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
delay(250);
digitalWrite(5, LOW);
digitalWrite(4, HIGH);
delay(350);
digitalWrite(4, LOW);
delay(150);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
delay(300);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
delay(300);
x = x + 1;
}
}
}
// max speed forward
void forward() {
  leftservo.writeMicroseconds(1000);
  rightservo.writeMicroseconds(2000);
}
// left turn mid speed
void turnleft() {
  leftservo.writeMicroseconds(1900);
  rightservo.writeMicroseconds(1660);
}
// right turn mid speed
void turnright() {
  leftservo.writeMicroseconds(1660);
  rightservo.writeMicroseconds(1900);
}
// spin
void spin() {
  leftservo.writeMicroseconds(1000);
  rightservo.writeMicroseconds(1000);
}
void still() {
  leftservo.writeMicroseconds(1500);
  rightservo.writeMicroseconds(1500);
}