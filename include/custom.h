#include <Arduino.h>

class LED{

public:

    void Blink(int pin, float seconds);

};

void LED::Blink(int pin, float seconds){
        digitalWrite(pin, HIGH);
        delay(seconds*1000);
        digitalWrite(pin, LOW);
        delay(seconds*1000);
}