//  __ __  __   __  __   __   __
// |_ (__ |__) (__)  _) /__  /__
// |__ __)|    (__) /__ \__) \__)
//
// (C) Copyright 2020 Adam K Dean

#include <Arduino.h>
#include "main.h"
#include "SBUS.h"

// a SBUS object, which is on hardware
// serial port 1
SBUS rx(Serial1);

// channel, fail safe, and lost frames data
float channels[16];
bool failSafe;
bool lostFrame;

//
// Initial entry point
//
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // begin the SBUS communication
  rx.begin();
}

//
// Main loop function
//
void loop()
{
  blink(1, 250, 250);

  if (rx.readCal(&channels[0], &failSafe, &lostFrame))
  {
    Serial.println(channels[0]);
    blink(1, 500, 500);
  }
}

//
// Blink very fast like something exciting is
// happening and you want everyone to know!
//
void blink(int count, int on, int off)
{
  for (int i = 0; i < count; i++)
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(on);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(off);
  }
}
