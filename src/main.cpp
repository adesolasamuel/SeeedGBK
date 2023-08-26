#include "seeedGBK_LED.h"

seeedGBK::LED redled(13);
seeedGBK::LED blueled(14);

void setup() {

}

void loop() {
  redled.Blink(2);
  blueled.Blink(0.5);
  blueled.PWM(100);
}
