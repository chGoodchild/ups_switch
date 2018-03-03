
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
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(A0, INPUT);
  //pinMode(A1, INPUT);
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
/*
 float supplyVoltage() {
  float zenerExpected = Vref;
  float zenerMeasured = analogRead(A1);
//  float ratio = zenerMeasured / zenerExpected;
  return zenerMeasured * zenerExpected;
}
*/

// the loop function runs over and over again forever
void loop() {
  // Resistance of the small resistor
  // static int bsR = 326;
  static int bsR = 317;
  // Resistance of the big resistor
  // static int bbR = 4670;
  static int bbR = 4590;
  // Measured voltage
  static float measured = 0;
  static float Vref = 3.6;
  /*
  static int pmsR = 1000;
  static int pmbR = 150;
  */

  measured = analogRead(A0);
  static float bV = 0;
  bV = batteryVoltage(measured / 1024 * Vref, bsR, bbR);
  Serial.println("");
  Serial.print("Measured bV:\t");
  Serial.print(bV);
  //Serial.print("\t Measured voltage:\t");
  //Serial.print(measured / 1024 * Vref);

  /*
  measured = analogRead(A1);
  static float pV = 0;
  //bV = 12.3;
  //pV = (((measured) - 26.6) / (165 / 1165)) - bV;
  pV = (measured / 1024 * Vref);// - Vref) * (pmsR + pmbR) / pmbR + Vref;
  Serial.print("\tMeasured pV:\t\t\t");
  Serial.print(pV);
  pV = ((measured / 1024 * Vref) - Vref) * (pmsR + pmbR) / pmbR;// + Vref;
  Serial.print("\tVoltage at Vp-:\t\t\t");
  Serial.print(pV);
  */
  
  if (bV < 23.4) {
    digitalWrite(13, 1);
    Serial.print("\t\tMains:\t1");
  }
  if (bV > 26) {
    digitalWrite(13, 0);
    Serial.print("\t\tMains:\t0");
  }
//  Serial.print("\treading:\t\t");
//  Serial.print(measured);  
//  Serial.print("\tsV:\t\t");
//  Serial.print(supplyVoltage());  
//  Serial.print("\tBattery voltage:\t\t");
//  Serial.print(bV / 1024 * supplyVoltage());
  // wait for 250 ms
  
//  delay(1000);
}
