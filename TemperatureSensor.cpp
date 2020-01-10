#include "TemperatureSensor.h"

const int TemperatureError = -1000;

// Name: TemperatureSetup
// Parameters: int SensorPin - the pin the sensor is attached to
// Returns: True if the setup succeeds, false if it fails
bool TemperatureSetup(int SensorPin)
{
  Serial.println("Temperature sensor setup not yet implemented.");

  return false;
}

// Name: TemperatureLoop
// Parameters: int SensorPin - the pin the sensor is attached to
// Returns: The current temperature, in degrees Celsius, or int.min if it has not been setup yet
int TemperatureLoop(int SensorPin)
{
  int lm35Pin = A0;
    int analogValue;
    float temperature;

    analogValue = analogRead(lm35Pin);

    temperature = float(analogValue) / 1023;
    temperature = temperature * 500;

    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.println("C");

    return temperature;
}
