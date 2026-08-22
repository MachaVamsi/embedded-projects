#include "stm32g0xx.h"
#include "FreeRTOS.h"
#include "task.h"

uint32_t SystemCoreClock = 16000000U;
volatile uint32_t b = 0;
volatile uint32_t a = 0;
/*
                 FreeRTOS
                   │
          ┌────────┴────────┐
          │                 │
        TaskA             TaskB
          │                 │
      every 1 sec        every 2 sec
          │                 │
        counter A        counter B

        We want to understand:

		task creation
		task priority
		scheduler
		vTaskDelay()
		periodic execution
		task state transitions
		what the debugger shows when tasks sleep/wake

		Time       TaskA       TaskB
		--------------------------------
		0 sec       A++         B++
		1 sec       A++         -
		2 sec       A++         B++
		3 sec       A++         -
		4 sec       A++         B++
 */



void TaskA(void *argument)
{
    while (1)
    {
        a++;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void TaskB(void *argument)
{
    while (1)
    {
        b++;
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

int main(void){
	xTaskCreate(TaskA, "TaskA", 128, NULL, 1, NULL);
	xTaskCreate(TaskB, "TaskB", 128, NULL, 2, NULL);
	vTaskStartScheduler();
	for(;;);
}
