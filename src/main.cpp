#include <vfd_show.h>
#include <wifi_ntp.h>

TaskHandle_t VFDShowTaskHandle = NULL;
TaskHandle_t WiFiNTPTaskHandle = NULL;

void setup()
{
  xTaskCreatePinnedToCore(VFDShowTask, "show the time", 1024 * 6, NULL, 1, &VFDShowTaskHandle, 1);
  xTaskCreatePinnedToCore(WiFiNTPTask, "get the time", 1024 * 6, NULL, 1, &WiFiNTPTaskHandle, 1);
  vTaskDelete(NULL);
}

void loop()
{}
