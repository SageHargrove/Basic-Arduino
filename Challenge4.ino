// including libraries and servo set up
#include <Servo.h>
Servo leftservo;
Servo rightservo;
void setup() {
// attaching servos to digital pins and button
leftservo.attach(11);
rightservo.attach(12);
pinMode(7, INPUT);
Serial.begin(9600);
}

void loop() {
  int button = digitalRead(7);
  if (button == 1) {
    //Challenge 4
delay(750);
forward();
delay(1300);
sharpleft();
delay(230);
forward();
delay(1800);
sharpleft();
delay(230);
forward();
delay(2000);
sharpleft();
delay(260);
forward();
delay(1000);
slowright();
delay(900);
forward();
delay(2500);
sharpright();
delay(230);
forward();
delay(850);
still();
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
// sharp right turn
void sharpright() {
  leftservo.writeMicroseconds(2000);
  rightservo.writeMicroseconds(2000);
}
// sharp left turn
void sharpleft() {
  leftservo.writeMicroseconds(1000);
  rightservo.writeMicroseconds(1000);
}
// slow right turn
void slowright() {
  leftservo.writeMicroseconds(1700);
  rightservo.writeMicroseconds(1700);
}
void still() {
  leftservo.writeMicroseconds(1500);
  rightservo.writeMicroseconds(1500);
}