#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <LittleFS.h>
#include <Wire.h>
#include <pins_arduino.h>

void initFS() {
  if (!LittleFS.begin()) {
    Serial.println("An error occured while mounting LittleFS");
    return;
  }

  Serial.println("LittleFS mounted successfully");
}

Adafruit_BME280 bme;

JsonDocument readings;

void initSensor() {
  // WARNING: removed the F() inside println for incompatibility, if issues with
  //  memory it may come from here...
  Serial.println("BME280 Sensor event test");
  unsigned status;

  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor.\n Check wiring or "
                   "try a different address");
    while (1)
      delay(10);
  }
}

String getReadings() {
  String jsonString;

  readings["in_temperature"] = String(bme.readTemperature());
  // readings["in_temperatureD"] = String(senseTemp % 10); // don't see a need
  // for this...
  readings["in_humidity"] = String(bme.readHumidity());
  readings["in_pressure"] = String(bme.readPressure());
  readings["in_altitude"] = String(
      bme.readAltitude(1013.25)); // TODO: make this a const... wtf is this
                                  // anyway? header says float seaLevel... is
                                  // that feet? meters? will have to check docs

  serializeJson(readings, jsonString);
  return jsonString;
}

void setup() {
  Serial.begin(115200); // TODO: figure out why this is in here
  initSensor();
  initFS();
  // initWifi();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10000; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}
