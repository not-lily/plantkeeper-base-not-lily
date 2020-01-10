#include "LightSensor.h"

const int LightError = -1000;

// Name: LightSetup
// Parameters: int SensorPin - the pin the sensor is attached to
// Returns: True if the setup succeeds, false if it fails
bool LightSetup(int SensorPin)

{
  Serial.println("Light sensor setup not yet implemented.");

  return false;
}

// Name: LightLoop
// Parameters: int SensorPin - the pin the sensor is attached to
// Returns: The current temperature, in degrees Celsius, or int.min if it has not been setup yet
int LightLoop(int SensorPin)
{
const int sensorMin = 0;
const int sensorMax = 800;

int lightValue;

    lightValue = analogRead(SensorPin);

    return lightValue;
}

