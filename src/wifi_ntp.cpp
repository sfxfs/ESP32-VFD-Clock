#include <wifi_ntp.h>

const char *ssid = "s22u";
const char *password = "13685989425";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com", 28800, 60000);

void WiFiNTPTask(void *ptParam)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xFrequency = 1000 / portTICK_PERIOD_MS;

    Serial.begin(9600);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        vTaskDelay(500 / portTICK_PERIOD_MS);
        Serial.print(".");
    }

    timeClient.begin();

    while (1)
    {
        timeClient.update();
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}
