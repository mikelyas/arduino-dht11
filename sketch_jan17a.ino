#include "TinyDHT.h"

DHT dht(8, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  uint8_t humidity    = dht.readHumidity();
  int16_t temperature = dht.readTemperature();

  if (temperature == BAD_TEMP || humidity == BAD_HUM) {
    Serial.println("Failed to read from DHT11");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C | Humidity: ");
    Serial.print(humidity);
    Serial.println("%\t");
  }
  delay(2000);
}
