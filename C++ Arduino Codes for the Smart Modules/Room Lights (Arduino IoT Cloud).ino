// CloudSwitch light_switch;

void setup() {
  light_switch = 0;
}

void loop() {
}

void onLightSwitchChange() {
  if (light_switch == 1) {
    digitalWrite(0, HIGH); // Turn lights ON
  } else {
    digitalWrite(0, LOW);  // Turn lights OFF
  }
}
