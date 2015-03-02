/*
  Mole.h - Library for mole game.
  Created by brionescl, July 23, 2012.
  Released into the public domain.
*/

#ifndef Mole_h
  #define Mole_h
  #include "Arduino.h"
  #define MAXLEDS 2
  #define MAXBUTTONS 2
  class Mole {
      public:
           Mole();
           void setLed(int pin);
           void setLedError(int pin);
           void setButton(int pin);
           void switchLed(int ledId, bool state);
           void switchLedError(bool state);
           void calculateRandomLed();
           void captureButtonPress();
           int timeLapse;
           int maxTimeLapse;
           int buttonPress;
           int randomLed;
      private:
           int _ledId;
           int _buttonId;
           int _leds[MAXLEDS];
           int _buttons[MAXBUTTONS];
           int _pinLedError;
  };
#endif
