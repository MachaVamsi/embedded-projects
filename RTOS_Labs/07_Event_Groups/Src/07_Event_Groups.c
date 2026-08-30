/*
 *
	   Task A
		  │
		  │ set BIT 0
		  ↓
	Event Group
		  ↑
		  │ set BIT 1
		  │
		Task B
          ↓
      MyTask waits


        Event A only:
		01 → MyTask remains blocked

		Event B only:
		10 → MyTask remains blocked

		Both:
		11 → MyTask wakes
 */

#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

#define EVENT_A    (1U << 0)
#define EVENT_B    (1U << 1)

EventGroupHandle_t myEventGroup;
volatile uint32_t eventCount = 0;
uint32_t SystemCoreClock = 16000000U;

void TaskA(void *argument)
{
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
        xEventGroupSetBits(myEventGroup, EVENT_A);
    }
}


void TaskB(void *argument)
{
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(2000));
        xEventGroupSetBits(myEventGroup, EVENT_B);
    }
}


void MyTask(void *argument)
{
    EventBits_t bits;
    while (1)
    {
        bits = xEventGroupWaitBits(
            myEventGroup,
            EVENT_A | EVENT_B,
            pdTRUE,
            pdTRUE,
            portMAX_DELAY
        );

        if ((bits & (EVENT_A | EVENT_B)) ==
            (EVENT_A | EVENT_B))
        {
            eventCount++;
        }
    }
}


int main(void)
{
    myEventGroup = xEventGroupCreate();
    if (myEventGroup == NULL)    {
        while (1);
    }
    xTaskCreate(TaskA, "TaskA", 128, NULL, 1, NULL);
    xTaskCreate(TaskB, "TaskB", 128, NULL, 1, NULL);
    xTaskCreate(MyTask, "MyTask", 128, NULL, 1, NULL);
    vTaskStartScheduler();
    while (1);
}
