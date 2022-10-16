#include <vfd_show.h>
#include <wifi_ntp.h>

void setup()
{
  xTaskCreatePinnedToCore(VFDShowTask, "show the time", 1024 * 2, nullptr, 1, nullptr, 1);  //该任务实测占用1020字节的ram
  xTaskCreatePinnedToCore(WiFiNTPTask, "get the time", 1024 * 4, nullptr, 1, nullptr, 1);   //占用2018字节的ram
  vTaskDelete(NULL);
}

void loop()
{}
