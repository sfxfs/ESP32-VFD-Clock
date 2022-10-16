#include <vfd_show.h>
#include <wifi_ntp.h>

TaskHandle_t VFDShowTaskHandle = NULL;
TaskHandle_t WiFiNTPTaskHandle = NULL;

void setup()
{
  Serial.begin(9600);
  xTaskCreatePinnedToCore(VFDShowTask, "show the time", 1024 * 6, NULL, 1, &VFDShowTaskHandle, 1);
  xTaskCreatePinnedToCore(WiFiNTPTask, "get the time", 1024 * 6, NULL, 1, &WiFiNTPTaskHandle, 1);
  Serial.printf("VFD set to: %d\n", 2 * (1024 * 6 - uxTaskGetStackHighWaterMark(VFDShowTaskHandle)));
  Serial.printf("WiFi set to: %d", 2 * (1024 * 6 - uxTaskGetStackHighWaterMark(WiFiNTPTaskHandle)));
  vTaskDelete(NULL);
}

void loop()
{}
