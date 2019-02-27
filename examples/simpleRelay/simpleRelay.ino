//Simple code to swap between states on a latching relay

//Relay library
#include <LatchRelay.h>

//Pins controlling the relay
#define on_pin 2
#define off_pin 3

//Relay object
LatchRelay relay = LatchRelay(on_pin, off_pin);

//Variable to track relay state (not always needed, but used here)
bool relayState;

void setup() {
  //initiate relay in the "off" state
  relay.init(0);
}

void loop() {
  //poll current relay state
  relayState = relay.getState();
  //set relay to opposite state
  relay.setState(!relayState);
  //wait one second
  delay(1000);
}