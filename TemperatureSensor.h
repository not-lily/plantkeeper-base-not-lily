#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <arduino.h>

bool TemperatureSetup(int SensorPin);
int TemperatureLoop(int SensorPin);

#endif // TEMPERATURE_SENSOR_H
