int redLED = 9;
int greenLED = 10;
int blueLED = 11;
int tempA = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {

for (int r = 0; r<256; r++) {
  analogWrite(redLED, r);
  Serial.print(r);
  delay(15);
  for(int g = 0; g<256; g++) {
    analogWrite(greenLED, g);
    Serial.print(g);
    delay(15);
    for(int b = 0 ; b<256; b++) {
      analogWrite(blueLED, b);
      Serial.println(b);
      delay(15);
    }
    
  }
}
}