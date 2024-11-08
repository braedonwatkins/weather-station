#include <Arduino.h>
#include <Wire.h>
#include <pins_arduino.h>

#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

void setup() { pinMode(LED_BUILTIN, OUTPUT); }

void loop() {
  for (int i = 0; i < 10000; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}
