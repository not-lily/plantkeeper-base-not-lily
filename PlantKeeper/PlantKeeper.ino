#include "TemperatureSensor.h"
#include "LightSensor.h"

const int PinTemperature = A0;
const int PinO2Sensor = 3;
const int PinCO2Sensor = 4;
const int PinpHSensor = 5;
const int PinAirMoisture = 6;
const int PinSoilMoisture = 7;
const int PinLightSensor = A8;
const int PinDoorSensor = 9;
const int PinRainGauge = 10;

const int PinOutputTooHot = 12;
const int PinOutputTooCold = 13;

const int HotTemperatureThreshold = 30;
const int ColdTemperatureThreshold = 15;

const int LightBrightnessThreshold = 800;
const int LightDarknessThreshold = 400;

const unsigned long MillisPerLoop = 100;
unsigned long TimeMillis = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("Beginning setup of PlantKeeper.");

  pinMode(PinOutputTooHot, OUTPUT);
  pinMode(PinOutputTooCold, OUTPUT);

  TemperatureSetup(PinTemperature);
  LightSetup(PinLightSensor);
}

// put your main code here, to run repeatedly
void loop()
{
  unsigned long CurrentMillis = millis();
  
  unsigned long ElapsedTimeMillis = CurrentMillis - TimeMillis;

  if (ElapsedTimeMillis < MillisPerLoop)
    return;

  Serial.println("Running loop of PlantKeeper.");


  int temperature = TemperatureLoop(PinTemperature);
  int light = LightLoop(PinLightSensor);
  

  if (temperature >  HotTemperatureThreshold)
  {
    Serial.println("It is too hot!");

    digitalWrite(PinOutputTooHot, 1);
  }

  else
  {
    digitalWrite(PinOutputTooHot, 0);
  }

  if (temperature < ColdTemperatureThreshold)
  {
    Serial.println("It is too cold!");

    digitalWrite(PinOutputTooCold, 1);
  }

  else
  {
    digitalWrite(PinOutputTooCold, 0);
  }

  TimeMillis = CurrentMillis;

  if (light < LightDarknessThreshold)
  {
    Serial.println("Turn on the lights!");

    //digitalWrite(PinOutputDark, 1);
  }

  if (light > LightBrightnessThreshold)
  {
    Serial.println("Danger! Too bright.");

    //digitalWrite(PinOutputDanger, 1);
  }
}

