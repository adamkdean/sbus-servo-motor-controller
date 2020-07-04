//  __ __  __   __  __   __   __
// |_ (__ |__) (__)  _) /__  /__
// |__ __)|    (__) /__ \__) \__)
//
// (C) Copyright 2020 Adam K Dean

#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "libs/SBUS.h"
#include "secrets.h"
#include "main.h"

// a SBUS object, which is on hardware serial port 1
SBUS rx(Serial);

// channel, fail safe, and lost frames data
float channels[16];
bool failSafe;
bool lostFrame;

// metrics data
char payload[1024];
char dataUrl[128];
char dataToken[40];

//
// Initial entry point
//
void setup()
{
  sprintf(dataUrl, "%s/rxchannels", DATA_URL);
  sprintf(dataToken, "Bearer %s", DATA_BEARER_TOKEN);

  Serial.begin(100000);
  pinMode(LED_BUILTIN, OUTPUT);
  connect_to_wifi();
  rx.begin();
}

//
// Main loop function
//
void loop()
{
  if (rx.readCal(&channels[0], &failSafe, &lostFrame))
  {
    sprintf(payload,
            "{\"ch0\":%f,\"ch1\":%f,\"ch2\":%f,\"ch3\":%f"
            ",\"ch4\":%f,\"ch5\":%f,\"ch6\":%f,\"ch7\":%f"
            ",\"ch8\":%f,\"ch9\":%f,\"ch10\":%f,\"ch11\":%f"
            ",\"ch12\":%f,\"ch13\":%f,\"ch14\":%f,\"ch15\":%f}",
            channels[0], channels[1], channels[2], channels[3],
            channels[4], channels[5], channels[6], channels[7],
            channels[8], channels[9], channels[10], channels[11],
            channels[12], channels[13], channels[14], channels[15]);

    HTTPClient http;
    http.begin(dataUrl);
    http.addHeader("Authorization", dataToken);
    http.addHeader("Content-Type", "application/json");

    digitalWrite(LED_BUILTIN, LOW);
    http.POST(payload);
    digitalWrite(LED_BUILTIN, HIGH);

    blink(1, 50, 450);
    blink(1, 50, 450);
  }
  else
  {
    blink(10, 50, 50);
  }
}

//
// Connect to WiFi while blinking.
//
void connect_to_wifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    blink(5, 50, 50);
    delay(500);
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
