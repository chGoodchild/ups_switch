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
  pinMode(A1, INPUT);
  //pinMode(A1, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

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
  float zenerExpected = 3.3;
  float zenerMeasured = analogRead(A1);
//  float ratio = zenerMeasured / zenerExpected;
  return zenerMeasured * zenerExpected;
}
*/

// the loop function runs over and over again forever
void loop() {
  // Measured voltage
  static float measured = 0;

  measured = analogRead(A1);
  // static float initial = (measured / 1024 * 5);
  // static float initial = measured;
  static float initial = 512;

  /*
  static int pmsR = 1000;
  static int pmbR = 150;
  */

  static float voltageDifference = 0;
  voltageDifference = ((measured - initial) / 1024 * 5) * 1000;
  Serial.println("");
  Serial.print("Initial measurement:\t");
  Serial.print(initial);
  Serial.print("\tDifference:\t");
  Serial.print(voltageDifference);
  Serial.print("\tAmps:\t");
  static float current = 0;
  current = voltageDifference / 33;
  static float averageCurrent = current;
  averageCurrent = (0.9 * averageCurrent + 0.1 * current);
  Serial.print(current);
  Serial.print("\tAverage current:\t");
  Serial.print(averageCurrent);
}
