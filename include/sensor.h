#pragma once

#include <Adafruit_BME280.h>
#include <ArduinoJson.h>

class SensorManager {
public:
  SensorManager();
  bool begin();
  String getReadings();

private:
  Adafruit_BME280 bme;
  JsonDocument readings;
};
