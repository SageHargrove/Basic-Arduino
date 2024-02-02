// initializing all variables
int redLED = 9; int blueLED = 11; int fan = 4; int heater = 12  ; // assigning names to digital pins
int tempA; int redIntensity; int blueIntensity; // initializing analog temp and intensity of red and blue LEDs
const int stDev = 4; // standard deviation for determing LCLA and UCLA
float SPC = 26.4 ; float tempC; // this is whatever setpoint value we are given, and initializing celsius temperature
int SPA = 17.454 * SPC + 92.422; int UCLA = SPA + 3*stDev; int LCLA = SPA - 3*stDev; // setpoints and control limits
int fromLOW = LCLA; int fromHIGH = UCLA; int toLOW = 0; int toHIGH = 255; // preparing for map function, from lower to upper to all values of LED

// setting up the functions for digital writing of LEDs and fan/heater
void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(heater, OUTPUT);
  Serial.println();
}
void loop() {
  // constantly getting the analog value and converting it to celsius, and using the map function to determine LED intensities.
  Serial.println();
  tempA = analogRead(5);
  tempC = (.0572 * tempA - 5.2468);
  redIntensity = map(tempA, fromLOW, fromHIGH, toLOW, toHIGH);
  blueIntensity = map(tempA, fromLOW, fromHIGH, toHIGH, toLOW);

  // constantly printing the headers for every variable
  Serial.println("LCLA\tSP\tUCLA\tTempA\tTempC\theater\tfan");
  Serial.print(LCLA); Serial.print("\t"); Serial.print(SPA); Serial.print("\t");
  Serial.print(UCLA); Serial.print("\t"); Serial.print(tempA); Serial.print("\t");
  Serial.print(tempC); Serial.print("\t");

  // constantly writing the intensity of the LED's
  // this will be printed to the serial monitor, organized in a clean manner
  analogWrite(redLED, redIntensity);
  analogWrite(blueLED, blueIntensity);

  // the last parts of what will be printed to the serial monitor, and will also be turning the heater on/off and the fan on/off.
  // this will also max out the red LED's intensity if it is above the UCLA and max out the blue LED's intensity if it is below the UCLA.
  if (tempA < LCLA) heaterOn();
  if (tempA > UCLA) heaterOff();
  if (tempA <= UCLA and tempA >= LCLA) {
    Serial.print("OFF");
  }
  Serial.print("\t");
  if (tempA > UCLA) fanOn();
  if (tempA < SPA) fanOff();
    if (tempA <= UCLA and tempA >= SPA) {
      Serial.print("OFF");
  }
  delay(1000);
  Serial.println("");
  }

// functions for the heater
void heaterOn() {
  Serial.print("ON");
  digitalWrite(heater, HIGH);
  analogWrite(blueLED, 255);
  analogWrite(redLED, 0);
}
void heaterOff() {
  Serial.print("OFF");
  digitalWrite(heater, LOW);
  analogWrite(redLED, 255);
  analogWrite(blueLED, 0);
}
// functions for the fan
void fanOn() {
  Serial.print("ON");
  digitalWrite(fan, HIGH);
}
void fanOff() {
  Serial.print("OFF");
  digitalWrite(fan, LOW);
}

