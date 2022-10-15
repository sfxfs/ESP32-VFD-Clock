#ifndef WIFI_NTP_H
#define WIFI_NTP_H

#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>

extern NTPClient timeClient;

void WiFiNTPTask(void *ptParam);

#endif
