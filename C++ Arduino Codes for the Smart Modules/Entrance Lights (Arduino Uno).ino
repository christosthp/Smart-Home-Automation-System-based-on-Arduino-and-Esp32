int relayPin = 3;          // Relay controlling the lights
int sensorPin = 2;         // PIR motion sensor
int pirState = LOW;
int val = 0;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  val = digitalRead(sensorPin);

  if (val == HIGH) {
    digitalWrite(relayPin, HIGH); // Lights ON
    delay(1000);
    pirState = HIGH;
  } else {
    digitalWrite(relayPin, LOW);  // Lights OFF
    delay(1000);
    pirState = LOW;
  }
}
