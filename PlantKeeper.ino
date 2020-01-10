//TODO:
//light thresholds
//figure out why temp sensor is a mistkerl

//include necessary libraries, c++, and .h files
#include <LiquidCrystal.h>
#include "TemperatureSensor.h"
#include "LightSensor.h"
#include "BlinkLight.h"
#include "AlarmLight.h"

//declare the LCD pins
int lcdRSPin = 12;
int lcdEPin = 11;
int lcdD4Pin = 5;
int lcdD5Pin = 4;
int lcdD6Pin = 3;
int lcdD7Pin = 2;

LiquidCrystal lcd(lcdRSPin, lcdEPin, 
                   lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

//hardware pin definitions
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

const int ledPinB = 13;
const int ledPinA = 8;

//global variables
const unsigned long MillisPerLoop = 100;
unsigned long TimeMillis = 0;

const int HotTemperatureThreshold = 30;
const int ColdTemperatureThreshold = 15;

const int LightBrightnessThreshold = 800;
const int LightDarknessThreshold = 400;

void setup()
{
  //set up LCD
  lcd.begin(16, 2);

  //lcd.setCursor(0, 0);
  //lcd.print("show temp");
  //lcd.setCursor(0, 1);
  //lcd.print("show light");

  //set up serial monitor
  Serial.begin(115200);
  Serial.println("Beginning setup of PlantKeeper.");

  //set up actuator pins
  pinMode(PinOutputTooHot, OUTPUT);
  pinMode(PinOutputTooCold, OUTPUT);

  //include setups for c++ files
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

  //declare variables
  int temperature = TemperatureLoop(PinTemperature);
  int light = LightLoop(PinLightSensor);
  int strobe = BlinkLoop(ledPinB);
  int alarm = AlarmLoop(ledPinA);

  //this is what shows up on the LCD
  lcd.setCursor(0, 0);
  lcd.print("TEMP C:");
  lcd.setCursor(12, 0);
  lcd.print(temperature);
  lcd.setCursor(0, 1);
  lcd.print("LIGHT:");
  lcd.setCursor(12, 1);
  lcd.print(light);

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

    digitalWrite(alarm, 1);
    digitalWrite(strobe, 1);
  }

  if (light > LightBrightnessThreshold)
  {
    Serial.println("Danger! Too bright.");

    //digitalWrite(PinOutputDanger, 1);
  }
}
