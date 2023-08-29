#include "seeedGBK_BMP280.h"
#include <Wire.h>
#include <ArduinoJson.h>
// http://librarymanager/All#ArduinoJSON

seeedGBK::BMP280 bmp280;
#define INTERVAL 2000
double t0;
uint32_t MSL = 102009; // Mean Sea Level in Pa

void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.println("\n\nBMP280 test");
  if (!bmp280.init()) {
    Serial.println("Device not connected or broken!");
  }
}

void loop() {
  double t1 = millis();
  if (t1 - t0 > INTERVAL) {
    float p1;

    //get and print temperatures
    Serial.print("Temp: ");
    float t = bmp280.getTemperature();
    Serial.print(t);
    Serial.println("C");
    
    //get and print atmospheric pressure data
    Serial.print("MSL: ");
    Serial.print(MSL / 100.0);
    Serial.println(" HPa");
    Serial.print("Pressure: ");
    p1 = bmp280.getPressure();
    Serial.print(p1 / 100.0);
    Serial.println(" HPa");

    //get and print altitude data
    float a = bmp280.calcAltitude(MSL, p1, t);
    Serial.print("Altitude: ");
    Serial.print(a);
    Serial.println(" m");
    Serial.println("\n");
    t0 = millis();
  }
  if (Serial.available()) {
    char mb[255];
    uint8_t ix = 0;
    while (Serial.available()) {
      mb[ix++] = Serial.read();
    }
    mb[ix] = 0;
    Serial.println("Incoming:");
    Serial.println(mb);
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, mb);
    if (!error) {
      float newMSL = doc["MSL"];
      Serial.print("New MSL: "); Serial.println(newMSL);
      if (newMSL > 0.0) {
        MSL = newMSL * 100;
      }
    } else {
      Serial.println("Parse error!");
    }
  }
}