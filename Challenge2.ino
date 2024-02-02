// include library and set up servo
#include <Servo.h>
Servo myservo1;
Servo myservo2;
void setup() {
// attaching servos and button to digital pins
myservo1.attach(11);
myservo2.attach(12);
pinMode(7, INPUT);
Serial.begin(9600); 
}

void loop() {
  // when button is pressed, make robot go
int switchStatus = digitalRead(7);
Serial.println(switchStatus);
if(switchStatus == 1)  {
  delay(1000);
// figure 8, Challenge 2
turnright();
delay(6850); 
turnleft();
delay(6850);
// stop the robot from moving
myservo1.detach();
myservo2.detach();
}
// do nothing if button is not pressed
if(switchStatus == 0) {
  
}
}
// right turn mid speed
void turnright() {
  myservo1.writeMicroseconds(1200);
  myservo2.writeMicroseconds(1950);
}
// left turn
void turnleft() {
  myservo1.writeMicroseconds(1020);
  myservo2.writeMicroseconds(1775);
}
