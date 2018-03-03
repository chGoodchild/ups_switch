void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  digitalWrite(13, 0);
  digitalWrite(2, 0);
  delay(1000);
  digitalWrite(13, 1);
  digitalWrite(2, 1);
}
