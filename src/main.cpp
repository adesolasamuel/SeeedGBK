#include "seeedGBK_BMP280.h"
#include <Wire.h>

// http://librarymanager/All#ArduinoJSON

seeedGBK::BMP280 bmp280;
float t0;
const int INTERVAL = 2000;

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
    float MSL = bmp280.getMSL();
    Serial.print(MSL);
    Serial.println("HPa");
    Serial.print("Pressure: ");
    p1 = bmp280.getPressure();
    Serial.print(p1);
    Serial.println(" HPa");

    //get and print altitude data
    float a = bmp280.calcAltitude();
    Serial.print("Altitude: ");
    Serial.print(a);
    Serial.println(" m");
    Serial.println("\n");
    t0 = millis();
  }
  
}