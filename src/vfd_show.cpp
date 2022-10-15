#include <vfd_show.h>

VFD_Display VFD;

void VFDShowTask(void *ptParam)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xFrequency = 1000 / portTICK_PERIOD_MS;
    VFD.VFD_Init();
    while (1)
    {
        VFD.VFD_Show_str(0,timeClient.isTimeSet() != true ? "UPDATE.." : timeClient.getFormattedTime());

        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}
