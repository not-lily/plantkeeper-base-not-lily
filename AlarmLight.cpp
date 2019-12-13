#include "AlarmLight.h"

const int ledPinA = 8;

bool AlarmSetup(int ledPinA)
{
  pinMode(ledPinA, OUTPUT);
}

int AlarmLoop(int ledPinA)
{
  digitalWrite(ledPinA, HIGH);
  delay(10000);
  digitalWrite(ledPinA, LOW);
}

