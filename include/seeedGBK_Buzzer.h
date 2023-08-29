#include <Arduino.h>

namespace seeedGBK{
    
class Buzzer{

public:

    Buzzer(int pin): pin(pin){
        pinMode(pin, OUTPUT);
    }

    void Beep(float seconds);
    void on(int freq = 1000);
    void off();

    void playDo1(int seconds);
    void playRe(int seconds);
    void playMi(int seconds);
    void playFa(int seconds);
    void playSo(int seconds);
    void playLa(int seconds);
    void playSi(int seconds);
    void playDo2(int seconds);
 

private:
    int pin;

};


}
