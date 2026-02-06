#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

RFID rfid(10, 9);
unsigned char status;
unsigned char str[MAX_LEN];

// Allowed RFID card IDs
String accessGranted[2] = {"310988016", "19612012715"};
int accessGrantedSize = 2;

Servo lockServo;
int lockPos = 15;     // Locked position
int unlockPos = 75;   // Unlocked position
bool locked = true;

int redLEDPin = 5;
int greenLEDPin = 6;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();

  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);

  // LED startup sequence
  digitalWrite(redLEDPin, HIGH); delay(200);
  digitalWrite(greenLEDPin, HIGH); delay(200);
  digitalWrite(redLEDPin, LOW); delay(200);
  digitalWrite(greenLEDPin, LOW); delay(200);

  lockServo.attach(3);
  lockServo.write(lockPos);

  Serial.println("Place card/tag near reader...");
}

void loop() {
  if (rfid.findCard(PICC_REQIDL, str) == MI_OK) {
    Serial.println("Card found");
    String temp = "";

    if (rfid.anticoll(str) == MI_OK) {
      Serial.print("Card ID: ");

      for (int i = 0; i < 4; i++) {
        temp += (0x0F & (str[i] >> 4));
        temp += (0x0F & str[i]);
      }

      Serial.println(temp);
      checkAccess(temp);
    }
  }

  rfid.halt();
}

void checkAccess(String temp) {
  bool granted = false;

  for (int i = 0; i < accessGrantedSize; i++) {
    if (accessGranted[i] == temp) {
      Serial.println("Access Granted");
      granted = true;

      if (locked) {
        lockServo.write(unlockPos);
        locked = false;
      } else {
        lockServo.write(lockPos);
        locked = true;
      }

      // Green LED blink
      for (int j = 0; j < 2; j++) {
        digitalWrite(greenLEDPin, HIGH); delay(200);
        digitalWrite(greenLEDPin, LOW); delay(200);
      }
    }
  }

  if (!granted) {
    Serial.println("Access Denied");

    // Red LED blink
    for (int j = 0; j < 2; j++) {
      digitalWrite(redLEDPin, HIGH); delay(200);
      digitalWrite(redLEDPin, LOW); delay(200);
    }
  }
}
