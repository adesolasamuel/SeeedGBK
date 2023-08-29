#include <Arduino.h>

namespace seeedGBK{
    
class LED{

public:

    LED(int pin): pin(pin){
        pinMode(pin, OUTPUT);
    }

    void Blink(float seconds);
    void PWM(int value);
    void on();
    void off();

private:
    int pin;

};



}
