

#include "FreeRTOS.h"
#include "task.h"

volatile uint32_t tickCount = 0;
uint32_t SystemCoreClock = 16000000U;

void vApplicationTickHook(void)
{
    tickCount++;
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
