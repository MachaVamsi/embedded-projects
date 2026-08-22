#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "gpio.c"

uint32_t SystemCoreClock = 16000000U;
void gpio_init();
void MyTask(void * argument);

SemaphoreHandle_t mySemaphore; //definition
volatile uint32_t eventCount =0;


int main(){
	gpio_init();
	mySemaphore = xSemaphoreCreateBinary();
	if(mySemaphore == NULL){
		while(1);
	}
	xTaskCreate(MyTask, "MyTask", 128, NULL, 1, NULL);
	vTaskStartScheduler();

}

void MyTask(void *argument){
    while (1){
        xSemaphoreTake(mySemaphore, portMAX_DELAY);
        eventCount++;
    }
}
