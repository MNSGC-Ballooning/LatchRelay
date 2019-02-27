#ifndef LatchRelay_h
#define LatchRelay_h

#include <Arduino.h>

class LatchRelay {
  public:
    //Constructor
    LatchRelay(int onPin, int offPin);
    //Call during setup()
    void init(bool startState);
    //Set the relay state using true/false or 1/0
    void setState(bool state);
    //Poll current relay state
    bool getState();
  private:
    //Pins used to control the relay
    int onPin, offPin;
    //Boolean to track relay state
    bool currentState;
};

#endif