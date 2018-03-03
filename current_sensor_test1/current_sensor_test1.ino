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


// the loop function runs over and over again forever
void loop() {
  // Measured voltage
  static float measured0 = 0;
  static float measured1 = 0;
  static float measured2 = 0;
  static float middle1 = analogRead(A0);
  static float middle2 = analogRead(A1);
  static float middle3 = analogRead(A2);

  measured0 = (19 * measured0 + analogRead(A0))/20;
  measured1 = (19 * measured1 + analogRead(A1))/20;
  measured2 = (19 * measured2 + analogRead(A2))/20;
  /*
  Serial.print("A0:\t");
  Serial.print(middle1);
  Serial.print("\tA1:\t");
  Serial.print(middle2);
  Serial.print("\tA2:\t");
  Serial.println(middle3);
  */
  Serial.print("A0:\t");
  Serial.print(((middle1 - measured0) / 1023 * 5) * 1000 / 33);
  Serial.print("\tA1:\t");
  Serial.print(((middle2 - measured1) / 1023 * 5) * 1000 / 33);
  Serial.print("\tA2:\t");
  Serial.println(((middle3 - measured2) / 1023 * 5) * 1000 / 33);
  
}
