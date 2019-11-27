#include "LightSensor.h"

const int LightError = -1000;

// Function declarations

// Name: LightSetup
// Parameters: int SensorPin - the pin the sensor is attached to
// Returns: True if the setup succeeds, false if it fails
bool LightSetup(int SensorPin)

{
  Serial.println("Light sensor setup not yet implemented");

  return false;
}

int LightLoop(int SensorPin)
{
const int sensorMin = 0;
// sensor maximum, discovered through experiment
const int sensorMax = 800;

int photocellPin = A5;
  int analogValue;
  int range;

    analogValue = analogRead(photocellPin);
    range = map(analogValue, sensorMin, sensorMax, 0, 3);

    switch (range) 
    {
        // your hand is on the sensor
        case 0:
            Serial.print("Light: ");
            Serial.println("dark");
            break;
        // your hand is close to the sensor
        case 1:
            Serial.print("Light: ");
            Serial.println("dim");
            break;
        // your hand is a few inches from the sensor
        case 2: 
            Serial.print("Light: ");
            Serial.println("medium");
            break;
        // your hand is nowhere near the sensor
        case 3:
            Serial.print("Light: ");
            Serial.println("bright");
            break;
    }
}
