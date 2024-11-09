#include "sensor.h"
#include "config.h"

SensorManager::SensorManager() {}

bool SensorManager::begin() {
  Serial.println("Initializing BME280");
  return bme.begin(BME280_ADDRESS);
}

String SensorManager::getReadings() {
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
