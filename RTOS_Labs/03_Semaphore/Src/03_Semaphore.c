/*
 * TaskA
  │
  │ gives semaphore
  ↓
Semaphore
  │
  │ wakes TaskB
  ↓
TaskB
 */



#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
uint32_t SystemCoreClock = 16000000U;
volatile uint32_t eventCount = 0;

SemaphoreHandle_t mySemaphore;


void TaskA(void *argument){
    while (1){
        vTaskDelay(pdMS_TO_TICKS(1000));
        xSemaphoreGive(mySemaphore);
    }
}


void TaskB(void *argument){
    while (1){
        xSemaphoreTake(mySemaphore, portMAX_DELAY);
        eventCount++;
    }
}


int main(void)
{
    mySemaphore = xSemaphoreCreateBinary();
    if (mySemaphore == NULL)
    {
        while (1);
    }


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
