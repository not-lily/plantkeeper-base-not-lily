#include "AlarmLight.h"

const int ledPinA = 8;

// Name: AlarmSetup
// Parameters: int ledPinA - the pin the sensor is attached to
// Returns: True if the setup succeeds, false if it fails
bool AlarmSetup(int ledPinA)
{
  pinMode(ledPinA, OUTPUT);
}

// Name: AlarmLoop
// Parameters: int ledPinA - the pin the sensor is attached to
// Returns: The current temperature, in degrees Celsius, or int.min if it has not been setup yet
int AlarmLoop(int ledPinA)
{
  digitalWrite(ledPinA, HIGH);
}

