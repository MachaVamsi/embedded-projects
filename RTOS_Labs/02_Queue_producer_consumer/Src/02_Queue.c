/*
                  FreeRTOS Queue
              ┌─────────────────┐
              │                 │
Producer ────>│     Queue       │────> Consumer
 TaskA        │                 │      TaskB
              └─────────────────┘

TaskA
  │
  │ send 10
  │ send 20
  │ send 30
  ↓
Queue

Queue
  │
  │ receive 10
  │ receive 20
  │ receive 30
  ↓
TaskB
 */


#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

uint32_t SystemCoreClock = 16000000U;
volatile uint32_t receivedValue = 0;
uint32_t value=0;
QueueHandle_t myQueue;

void ProducerTask(void * argument){

	while(1){
		value++;
		xQueueSend(myQueue, &value, portMAX_DELAY);
//		vTaskDelay(pdMS_TO_TICKS(100));
	}
}

void ConsumerTask(void *argument)
{
	 uint32_t received;
	while (1){
		xQueueReceive(myQueue, &received, portMAX_DELAY);
		receivedValue = received;
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}


int main(void){
	myQueue = xQueueCreate(5, sizeof(uint32_t));
	if(myQueue == NULL){
		while(1);
	}
	xTaskCreate(ProducerTask, "Producer", 128, NULL, 1, NULL);
	xTaskCreate(ConsumerTask, "Consumer", 128, NULL, 1, NULL);
	vTaskStartScheduler();
	while(1);
}
