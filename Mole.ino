#include <Mole.h>

const bool ON = true;
const bool OFF = false;
Mole mole;

void setup() {
    //Serial.begin(9600);
    // pin LEDs
    mole.setLed(12); // 1 kohms +/-5
    mole.setLed(11); // 1 kohms +/-5
    // LED error
    mole.setLedError(10); // 1 kohms +/-5
    // pin Button
    // 3.3v
    mole.setButton(3); // 10 kohms +/-5
    mole.setButton(2); // 10 kohms +/-5
    mole.calculateRandomLed();
    mole.maxTimeLapse = 2000; // 2 seconds
}

void loop() {
    mole.captureButtonPress();
    if (mole.buttonPress != -1) {
         //Serial.println(mole.buttonPress);
         mole.switchLed(mole.randomLed, OFF);
         if (mole.randomLed == mole.buttonPress) {
              delay(1000);
         } else {
              mole.switchLedError(ON);
              delay(2000);
              mole.switchLedError(OFF);
         }
         mole.timeLapse = 0;
         mole.calculateRandomLed();
    } else {
         //Serial.println("NO PRESS");
    }
    if (mole.timeLapse == mole.maxTimeLapse) {
         mole.timeLapse = 0;
         mole.switchLed(mole.randomLed, OFF);
         mole.switchLedError(ON);
         delay(500);
         mole.switchLedError(OFF);
         mole.calculateRandomLed();
    } else {
         mole.switchLed(mole.randomLed, ON);
         delay(1);
         mole.timeLapse++;
    }
}
