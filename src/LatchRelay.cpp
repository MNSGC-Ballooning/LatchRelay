#include "LatchRelay.h"

LatchRelay::LatchRelay(int onPin, int offPin):
  onPin(onPin), offPin(offPin) {
}

void LatchRelay::init(bool startState) {
  pinMode(onPin, OUTPUT);
  pinMode(offPin, OUTPUT);
  setState(startState);
}

void LatchRelay::setState(bool state) {
  if (state) {
    digitalWrite(onPin, HIGH);
    delay(10);
    digitalWrite(onPin, LOW);
  }
  else {
    digitalWrite(offPin, HIGH);
    delay(10);
    digitalWrite(offPin, LOW);
  }
  currentState = state;
}

bool LatchRelay::getState() {
  return currentState;
}