#include "seeedGBK_LED.h"

namespace seeedGBK{

void LED::Blink(float seconds){
        digitalWrite(pin, HIGH);
        delay(seconds*1000);
        digitalWrite(pin, LOW);
        delay(seconds*1000);
}

void LED::on(){
    digitalWrite(pin, HIGH);
}

void LED::off(){
    digitalWrite(pin, LOW);
}

void LED::PWM(int value){
    if (value < 0){value = 0;}
    if (value > 255){value = 255;}
    analogWrite(pin, value);
}
}