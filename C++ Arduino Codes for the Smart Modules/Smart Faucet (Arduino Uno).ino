// Ultrasonic sensor pins
#define echoPin 4
#define trigPin 5

long duration;
int distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  // Output pin controlling the faucet (relay or valve)
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);

  delay(2000); // Startup delay
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert time to distance (cm)
  distance = duration * 0.034 / 2;

  // If hand is within 20 cm → turn water on
  if (distance <= 20) {
    digitalWrite(3, HIGH);
    delay(2000); // Keep water running for 2 seconds
  }

  // Turn water off
  digitalWrite(3, LOW);
}
