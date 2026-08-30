#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/*
 * for this file to work i have renamed timer.d to timers.c
 * in 6_SoftwareTimer\FreeRTOS\Source\Config\FreeRTOSConfig.h
 * chnage #define configUSE_TIMERS  from 0 to 1
 */

uint32_t SystemCoreClock = 16000000U;
volatile uint32_t timerCount=0;
TimerHandle_t myTimer;


void TimerCallback(TimerHandle_t xTimer){
	// xTimer is available, but we don't need it
	timerCount++;
}

int main(void)
{
    myTimer = xTimerCreate("MyTimer", pdMS_TO_TICKS(1000), pdTRUE, NULL, TimerCallback);
    if (myTimer == NULL){
        while (1);
    }
    xTimerStart(myTimer, 0);
    vTaskStartScheduler();
    while (1);
}
