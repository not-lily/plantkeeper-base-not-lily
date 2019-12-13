//TODO:
//add strobe when triggered bc of light values too high/low
//add light that turns on (w delay) when light is too high/low
//optional speaker w pitches.h

#include <LiquidCrystal.h>
#include "TemperatureSensor.h"
#include "LightSensor.h"
#include "arduino.h"
#include "BlinkLight.h"
#include "AlarmLight.h"

int lcdRSPin = 12;
int lcdEPin = 11;
int lcdD4Pin = 5;
int lcdD5Pin = 4;
int lcdD6Pin = 3;
int lcdD7Pin = 2;

LiquidCrystal lcd(lcdRSPin, lcdEPin, 
                   lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

const int PinTemperature = A0;
const int PinO2Sensor = 3;
const int PinCO2Sensor = 4;
const int PinpHSensor = 5;
const int PinAirMoisture = 6;
const int PinSoilMoisture = 7;
const int PinLightSensor = 8;
const int PinDoorSensor = 9;
const int PinRainGauge = 10;

const int PinOutputTooHot = 12;
const int PinOutputTooCold = 13;

const int HotTemperatureThreshold = 30;
const int ColdTemperatureThreshold = 15;

const int LightBrightnessThreshold = 800;
const int LightDarknessThreshold = 400;

const int ledPinB = 13;
const int ledPinA = 8;

const unsigned long MillisPerLoop = 100;
unsigned long TimeMillis = 0;

void setup()
{
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("show temp");
  lcd.setCursor(0, 1);
  lcd.print("show light");
  
  Serial.begin(115200);
  Serial.println("Beginning setup of PlantKeeper.");

  pinMode(PinOutputTooHot, OUTPUT);
  pinMode(PinOutputTooCold, OUTPUT);

  TemperatureSetup(PinTemperature);
  LightSetup(PinLightSensor);
  BlinkSetup(ledPinB);
  AlarmSetup(ledPinA);
}

void loop()
{
  unsigned long CurrentMillis = millis();
  
  unsigned long ElapsedTimeMillis = CurrentMillis - TimeMillis;

  if (ElapsedTimeMillis < MillisPerLoop)
    return;

  Serial.println("Running loop of PlantKeeper.");
  
  int temperature = TemperatureLoop(PinTemperature);
  int light = LightLoop(PinLightSensor);
  int strobe = BlinkLoop(ledPinB);
  int alarm = AlarmLoop(ledPinA);

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

    digitalWrite(alarm 1);
    digitalWrite(strobe, 1);
  }

  if (light > LightBrightnessThreshold)
  {
    Serial.println("Danger! Too bright.");

    //digitalWrite(PinOutputDanger, 1);
  }
}
