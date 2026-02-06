// int gas_detected;

int Buzzer = 32;
int Gas_analog = 4;
int Gas_digital = 2;

void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);
  pinMode(Gas_digital, INPUT);
}

void loop() {
  int gasAnalog = analogRead(Gas_analog);
  int gasDigital = digitalRead(Gas_digital);

  gas_detected = gasAnalog;

  Serial.print("Gas Sensor: ");
  Serial.print(gasAnalog);
  Serial.print("\tGas Class: ");
  Serial.print(gasDigital);
  Serial.print("\t");

  if (gasAnalog > 1000) {
    Serial.println("Gas Detected!");
    digitalWrite(Buzzer, HIGH);
    delay(1000);
    digitalWrite(Buzzer, LOW);
  } else {
    Serial.println("No Gas");
  }

  delay(100);
}
