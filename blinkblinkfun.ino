void setup() {
pinMode(4, OUTPUT);
pinMode(6, OUTPUT);
for(int i = 0;i < 6; i++) {
digitalWrite(4, HIGH);
digitalWrite(6, HIGH);
delay(150);
delay(200);
digitalWrite(4, LOW);
delay(150);
digitalWrite(6, HIGH);
delay(150);
digitalWrite(6, LOW);
delay(200);
}
}

void loop() {
}
