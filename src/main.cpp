#include <vfd_show.h>
#include <wifi_ntp.h>

void setup()
{
  xTaskCreatePinnedToCore(VFDShowTask, "show the time", 1024 * 6, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(WiFiNTPTask, "get the time", 1024 * 6, NULL, 1, NULL, 1);
  vTaskDelete(NULL);
}

void loop()
{}
