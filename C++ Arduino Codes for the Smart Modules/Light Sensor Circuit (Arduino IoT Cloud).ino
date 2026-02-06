// float outside_light;

#define LdrPin 2
int ldrStatus = 0;

void setup() {
}

void loop() {
  ldrStatus = analogRead(LdrPin);
  outside_light = ldrStatus; // Send value to cloud
  delay(100);
}
