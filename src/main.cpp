#include "custom.h"

int redled = 13;

LED myLED;

void setup() {
  pinMode(redled, OUTPUT);

}

void loop() {
  myLED.Blink(redled, 0.5);
}
