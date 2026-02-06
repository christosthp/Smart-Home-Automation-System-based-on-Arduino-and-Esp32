// CloudSwitch outside_door;

void setup() {
  outside_door = 0; // Door initially closed
}

void loop() {
}

// Triggered when the cloud variable changes
void onOutsideDoorChange() {
  if (outside_door == 1) {
    digitalWrite(0, HIGH); // Unlock / open
    delay(5000);
    digitalWrite(0, LOW);  // Lock / close
    outside_door = 0;
  } else {
    digitalWrite(0, LOW);
  }
}
