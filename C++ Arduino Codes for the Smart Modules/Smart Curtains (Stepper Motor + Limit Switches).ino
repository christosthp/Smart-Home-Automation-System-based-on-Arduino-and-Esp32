// CloudSwitch curtains;

const int stepPin = 2;
const int dirPin = 4;
const int end1_button = 12; // Fully closed limit switch
const int end2_button = 13; // Fully open limit switch

int STATE_1;
int STATE_2;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(end1_button, INPUT);
  pinMode(end2_button, INPUT);
}

void loop() {
}

void onCurtainsChange() {
  // OPEN curtains
  if (curtains == 1) {
    STATE_2 = 0;
    digitalWrite(dirPin, HIGH);

    while (STATE_2 != 1) {
      STATE_2 = digitalRead(end2_button);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
    }
  }

  // CLOSE curtains
  if (curtains == 0) {
    STATE_1 = 0;
    digitalWrite(dirPin, LOW);

    while (STATE_1 != 1) {
      STATE_1 = digitalRead(end1_button);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
    }
  }
}
