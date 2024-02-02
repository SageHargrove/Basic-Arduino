void setup() {
pinMode(7, INPUT);
pinMode(13, OUTPUT);
Serial.begin(9600);
}

void loop() {
  int switchStatus = digitalRead(7);
  Serial.println(switchStatus);
  if (switchStatus == 1) {
    digitalWrite(13, HIGH);
  }
  if (switchStatus ==0) {
    digitalWrite(13, LOW);
  }
}
