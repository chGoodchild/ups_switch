/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

//  int A0 = 23;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(38400);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  analogReference(EXTERNAL);

  // Configure serial
}

/**
 * Return the battery voltage given the measured voltage 
 * and the resistors in the voltage divider.
 */
float batteryVoltage(float measured, int sR, int bR) {
  return measured * (sR + bR) / sR;
}

/**
 * Return the true voltage of the 5~V source.
 */
float supplyVoltage() {
  float zenerExpected = 3.3;
  float zenerMeasured = analogRead(A1);
//  float ratio = zenerMeasured / zenerExpected;
  return zenerMeasured * zenerExpected;
}


// the loop function runs over and over again forever
void loop() {
  // Resistance of the small resistor
  static int sR = 326;
  // Resistance of the big resistor
  static int bR = 4670;
  // Measured voltage
  static float measured = 0;

  measured = analogRead(A0);
  static float bV = 0;
  bV = batteryVoltage(measured / 1024 * 3.3, sR, bR);
  Serial.println("");
  Serial.print("Measured bV:\t\t");
  Serial.print(bV);

  measured = analogRead(A0);
  static float pV = 0;
  bV = 12.3;
  pV = ((bV - (measured / 1024 * 3.3)) / 14.33) + (bV - (measured / 1024 * 3.3));
  Serial.println("");
  Serial.print("Measured pV:\t\t");
  Serial.print(pV);
  
  if (bV < 11.7) {
    digitalWrite(13, 1);
  }
  if (bV > 13) {
    digitalWrite(13, 0);
  }
//  Serial.print("\treading:\t\t");
//  Serial.print(measured);  
//  Serial.print("\tsV:\t\t");
//  Serial.print(supplyVoltage());  
//  Serial.print("\tBattery voltage:\t\t");
//  Serial.print(bV / 1024 * supplyVoltage());
  // wait for 250 ms
  delay(1000);
}


