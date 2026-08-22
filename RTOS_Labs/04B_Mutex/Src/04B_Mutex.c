#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
uint32_t SystemCoreClock = 16000000U;
volatile uint32_t sharedCounter = 0;
SemaphoreHandle_t myMutex;
void TaskA(void *argument)
{
	while (1)
	{
	    xSemaphoreTake(myMutex, portMAX_DELAY);

	    sharedCounter++;

	    xSemaphoreGive(myMutex);

	    vTaskDelay(pdMS_TO_TICKS(10));
	}
}

void TaskB(void *argument)
{
	while (1)
	{
	    xSemaphoreTake(myMutex, portMAX_DELAY);

	    sharedCounter++;

	    xSemaphoreGive(myMutex);

	    vTaskDelay(pdMS_TO_TICKS(10));
	}
}

int main(void)
{


	myMutex = xSemaphoreCreateMutex();

	if (myMutex == NULL)
	{
	    while (1);
	}
    xTaskCreate( TaskA,        "TaskA",        128,        NULL,        1,        NULL    );
    xTaskCreate(        TaskB,        "TaskB",        128,        NULL,        1,        NULL    );
    vTaskStartScheduler();
    while (1)    {
    }
}
