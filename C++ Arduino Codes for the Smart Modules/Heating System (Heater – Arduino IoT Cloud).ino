// CloudSwitch heater;

void setup() {
  heater = 0;
}

void loop() {
}

void onHeaterChange() {
  if (heater == 1) {
    digitalWrite(0, HIGH); // Heater ON
  } else {
    digitalWrite(0, LOW);  // Heater OFF
  }
}
