/*
 *
 * in 08_Idle_Hook\FreeRTOS\Source\Config\FreeRTOSConfig.h
 * chnage #define configUSE_IDLE_HOOK  from 0 to 1
 */



#include "FreeRTOS.h"
#include "task.h"

volatile uint32_t idleCount = 0;
uint32_t SystemCoreClock = 16000000U;

void vApplicationIdleHook(void)
{
    idleCount++;
}


void MyTask(void *argument)
{
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


int main(void)
{
    xTaskCreate(
        MyTask,
        "MyTask",
        128,
        NULL,
        1,
        NULL
    );

    vTaskStartScheduler();

    while (1)
    {
    }
}
