#include "FreeRTOS.h"
#include "task.h"
uint32_t SystemCoreClock = 16000000U;
volatile uint32_t sharedCounter = 0;

void TaskA(void *argument)
{
    while (1)
    {
        sharedCounter++;

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void TaskB(void *argument)
{
    while (1)
    {
        sharedCounter++;

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int main(void)
{
    xTaskCreate(
        TaskA,
        "TaskA",
        128,
        NULL,
        1,
        NULL
    );

    xTaskCreate(
        TaskB,
        "TaskB",
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
