#include "BlinkLight.h"

const int ledPinB = 13;

// Name: BlinkSetup
// Parameters: int ledPinB - the pin the sensor is attached to
// Returns: True if the setup succeeds, false if it fails
bool BlinkSetup(int ledPinB)
{
  pinMode(ledPinB, OUTPUT);
}

// Name: BlinkLoop
// Parameters: int ledPinB - the pin the sensor is attached to
// Returns: The current temperature, in degrees Celsius, or int.min if it has not been setup yet
int BlinkLoop(int ledPinB)
{
  digitalWrite(ledPinB, HIGH);
  delay(680);
  digitalWrite(ledPinB, LOW);
  delay(680);
}

