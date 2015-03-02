/*
  Mole.cpp - Library for mole game.
  Created by brionescl, July 23, 2012.
  Released into the public domain.
 */

 #include "Arduino.h"
 #include "Mole.h"

 Mole::Mole() {
      _ledId = 0;
      _buttonId = 0;
      randomLed = -1;
      timeLapse = 0;
      maxTimeLapse = 1000; // 1 second
      buttonPress = -1;
      randomSeed(analogRead(0));
 }
 void Mole::setLed(int pin) {
      if (_ledId < MAXLEDS) {
           _leds[_ledId++] = pin;
           pinMode(pin, OUTPUT);
      }
 }
 void Mole::setButton(int pin) {
      if (_buttonId < MAXBUTTONS) {
           _buttons[_buttonId++] = pin;
           pinMode(pin, INPUT);
      }
 }
 void Mole::setLedError(int pin) {
      _pinLedError = pin;
      pinMode(pin, OUTPUT);
 }
 void Mole::switchLed(int ledId, bool state) {
      if (state == true) {
           digitalWrite(_leds[ledId], HIGH);
      } else if (state == false) {
           digitalWrite(_leds[ledId], LOW);
      }
 }
 void Mole::switchLedError(bool state) {
      if (state == true) {
           digitalWrite(_pinLedError, HIGH);
      } else if (state == false) {
           digitalWrite(_pinLedError, LOW);
      }
 }
 void Mole::calculateRandomLed() {
      randomLed = random(0, MAXLEDS);
 }
 void Mole::captureButtonPress() {
      int button = 0;
      for (int buttonId = 0; buttonId < MAXBUTTONS; buttonId++) {
           button = digitalRead(_buttons[buttonId]);
           if (button == HIGH) {
                buttonPress = buttonId;
                break;
           } else {
                buttonPress = -1;
           }
      }
 }
