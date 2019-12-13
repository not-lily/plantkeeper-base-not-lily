#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <arduino.h>

bool LightSetup(int SensorPin);
int LightLoop(int SensorPin);

#endif // LIGHT_SENSOR_H
