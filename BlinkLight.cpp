#include "BlinkLight.h"

const int ledPinB = 13;

bool BlinkSetup(int ledPin)
{
  pinMode(ledPinB, OUTPUT);
}

int BlinkLoop(int ledPinB)
{
  digitalWrite(ledPinB, HIGH);
  delay(750);
  digitalWrite(ledPinB, LOW);
  delay(750);
}

