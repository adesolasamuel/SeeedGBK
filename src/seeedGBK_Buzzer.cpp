#include "seeedGBK_Buzzer.h"

namespace seeedGBK{

void Buzzer::Beep(float seconds){
    this->on(seconds*1000);
    delay(seconds*1000);
    this->off();
    delay(seconds*1000);
}

void Buzzer::on(int freq){
  analogWrite(pin, 128);
  delay(freq);
  analogWrite(pin, 0);
  delay(0);
}

void Buzzer::off(){
    analogWrite(pin, 0);
}

}