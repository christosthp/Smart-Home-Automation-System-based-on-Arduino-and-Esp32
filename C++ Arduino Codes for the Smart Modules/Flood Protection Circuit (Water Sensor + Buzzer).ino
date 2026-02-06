// int water_level;

#define THRESHOLD 1000
#define POWER_PIN 17
#define SIGNAL_PIN 36

int value = 0;
int Buzzer = 32;

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, LOW);
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);
  delay(10);

  value = analogRead(SIGNAL_PIN);
  water_level = value;

  if (water_level > THRESHOLD) {
    digitalWrite(Buzzer, HIGH);
    delay(1000);
    digitalWrite(Buzzer, LOW);
  }

  digitalWrite(POWER_PIN, LOW);

  Serial.print("Water sensor value: ");
  Serial.println(value);
  delay(1000);
}
