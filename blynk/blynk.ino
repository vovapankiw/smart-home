// secrets.h must come FIRST: Blynk needs the TEMPLATE_ID defines
// before BlynkSimpleEsp32.h is included
#include "secrets.h"

#define BLYNK_PRINT Serial   // Blynk connection logs in Serial Monitor

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

const int steamPin = 34;                  // Steam sensor analog output (S/AO) -> GPIO 34
const unsigned long SEND_INTERVAL = 600000UL;  // 10 minutes in ms

BlynkTimer timer;

// Read the steam sensor and send the value to Blynk
void sendSensorData() {
  int rawValue = analogRead(steamPin);           // 0..4095
  int steamPercent = map(rawValue, 0, 4095, 0, 100);

  Serial.print("Raw ADC: ");
  Serial.print(rawValue);
  Serial.print(" | Steam: ");
  Serial.print(steamPercent);
  Serial.println("%");

  Blynk.virtualWrite(V1, steamPercent);
}

// Runs every time the board (re)connects to Blynk:
// send a reading right away so the dashboard isn't empty for 10 minutes
BLYNK_CONNECTED() {
  sendSensorData();
}

void setup() {
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);

  // Send data every 10 minutes (30,000 msg/month limit -> ~4,320 used)
  timer.setInterval(SEND_INTERVAL, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}