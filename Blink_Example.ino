int x = 13;            // pin on breadboard
int dot = 300;    // equivalent to tiny circles in morse code
int dash = 900;   // equivalent to dashes in morse code
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(x, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
 switchLED(dot);
 switchLED(dot);
 switchLED(dot);
 delay(dash);
 switchLED(dot);
 switchLED(dash);
 delay(dash);
int x = 8;
   switchLED(dash);
 switchLED(dash);
 switchLED(dot);
 delay(dash);
 switchLED(dot);
}

void switchLED(int morse) {
  digitalWrite(x, HIGH);
  delay(morse);
  digitalWrite(x, LOW);
  delay(dot);
}

