#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <LittleFS.h>
#include <Wire.h>
#include <pins_arduino.h>

#include "sensor.h"

SensorManager sensorManager;

void initFS() {
  if (!LittleFS.begin()) {
    Serial.println("An error occured while mounting LittleFS");
    return;
  }

  Serial.println("LittleFS mounted successfully");
}

Adafruit_BME280 bme;

JsonDocument readings;

void setup() {
  Serial.begin(115200); // TODO: figure out why this is in here

  if (!sensorManager.begin()) {
    Serial.println("BME280 initialization failed");
    return;
  }

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
