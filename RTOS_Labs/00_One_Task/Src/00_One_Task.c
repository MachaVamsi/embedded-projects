#include "stm32g0xx.h"
#include "FreeRTOS.h"
#include "task.h"

uint32_t SystemCoreClock = 16000000U;
volatile uint32_t b = 0;
volatile uint32_t a = 0;
/*
 * Lab 0 — Debugging familiarity ✅
 *
 * Case 1
	TaskA = priority 1
	TaskB = priority 1
	Both READY
			↓
	Time slicing
			↓
	TaskA ↔ TaskB

   Case 2
	TaskA = priority 2
	TaskB = priority 1
	Both READY
			↓
	Highest-priority READY task = TaskA
			↓
	TaskA keeps running
	TaskB remains READY

You have now learned experimentally:

How to identify the task currently executing.
How to use Resume/Pause.
How a breakpoint inside a task behaves.
RUNNING vs BLOCKED.
How vTaskDelay() changes task behavior.
How to use variables (a, b) as evidence that a task executed.
Why "the debugger shows TaskB" does not mean TaskA isn't running.
 */



void TaskA(void *argument)
{
    while (1)
    {
        a++;
//        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void TaskB(void *argument)
{
    while (1)
    {
        b++;
//        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

int main(void){

//	xTaskCreate(TaskA, "TaskA", 128, NULL, 1, NULL);
//	xTaskCreate(TaskB, "TaskB", 128, NULL, 1, NULL); // both gets executed due to RTOS time slicing

	xTaskCreate(TaskA, "TaskA", 128, NULL, 1, NULL); // in this scenario taskA never executes due to less priority
	xTaskCreate(TaskB, "TaskB", 128, NULL, 2, NULL);
	vTaskStartScheduler();
	for(;;);
}
