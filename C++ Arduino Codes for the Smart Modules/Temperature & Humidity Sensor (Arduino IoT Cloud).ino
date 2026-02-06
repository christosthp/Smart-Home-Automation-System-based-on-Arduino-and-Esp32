// Cloud variables:
// CloudTemperatureSensor temperature;
// CloudRelativeHumidity humidity;

#include "DHT.h"

#define DHTPIN 0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
}

void loop() {
  readDHTSensor();
}

// Reads humidity & temperature and updates cloud variables
void readDHTSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  temperature = t;
  humidity = h;
}
