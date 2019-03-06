# LatchRelay

This Arduino library is intended for the EC2-5TNU and similar dual-coil latching relays.
It encapsulates the pulse generation necessary to flip the state of the relay, and allows that state to be polled.

## Use in code
### Object creation
This library defines the class `LatchRelay` to drive the switch.
The constructor has the form
```
LatchRelay(onPin, offPin);
```
where `onPin` and `offPin` are of type `byte` and indicate the pins used to control the relay.
`onPin` is the pin that pulses high to switch the relay on, while `offPin` is the pin to pulse high to switch off.

### Initialization
If `relay` is an object of type `LatchRelay`, then somewhere during setup the `init()` method should be called:
```
relay.init();
```
This declares the pins named in the constructor as outputs, without changing the switch state.
If a default starting state is desired, pass a boolean to the function to force it to start on or off:
```
relay.init(0); //start off
relay.init(1); //start on
```

### Controlling the Relay
The relay is controlled via the `setState()` function, which takes a boolean argument:
```
relay.setState(0); //set to off
relay.setState(1); //set to on
```
Alternatively, use actual `bool` expressions - these are equivalent (though wordier)
```
relay.setState(false); //set to off
relay.setState(true); //set to on
```
Whenever this function is called, the object tracks the relay state, which can be polled:
```
bool relayState = relay.getState();
```
There is no explicit function to toggle the switch state, but this is easy enough by combining the get and set methods:
```
relay.setState(!relay.getState());
```
Note that `getState()` only tracks the value passed to the last call to `setState()` and cannot actually poll the physical state of the switch.
Thus, it is possible (though unlikely) that the switch fails to change but `getState()` would not reflect this.
If this occurs regularly, external verification should be used.
Additionally, if the `init()` function with no paramaters is called, the object has no way of knowing the current switch state,
and `getState()` will default to reporting as off until the state is set for the first time. 

## Naming Convention
Although the library naming convention assumes the user is toggling a switch on and off,
the physical relay actually toggles which of two pins a third pin is connected to.
Thus, the user could route a signal in either of two ways, both of which would be a form of "on".
In this case, 0 and 1 simply represent these two different states of the relay,
with `onPin` and `offPin` being the pins used to set the relay to states 1 and 0, respectively.