//  __ __  __   __  __   __   __
// |_ (__ |__) (__)  _) /__  /__
// |__ __)|    (__) /__ \__) \__)
//
// (C) Copyright 2020 Adam K Dean

#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "libs/SBUS.h"
#include "wifi.h"
#include "main.h"

// a SBUS object, which is on hardware serial port 1
SBUS rx(Serial);

// channel, fail safe, and lost frames data
float channels[16];
bool failSafe;
bool lostFrame;

//
// Initial entry point
//
void setup()
{
  Serial.begin(100000);
  pinMode(LED_BUILTIN, OUTPUT);

  // begin the SBUS communication
  rx.begin();
}

//
// Main loop function
//
void loop()
{
  // char msg[64];
  // float a0 = analogRead(A0);
  // sprintf(msg, "A0: %f", a0);
  // Serial.println(msg);

  // if (Serial.available() > 0)
  // {
  //   blink(10, 50, 50);
  // }
  // else
  // {
  //   blink(1, 50, 950);
  // }

  if (rx.readCal(&channels[0], &failSafe, &lostFrame))
  {
    // Serial.println(channels[0]);
    blink(10, 50, 50);
  }
  else
  {
    blink(1, 50, 950);
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
