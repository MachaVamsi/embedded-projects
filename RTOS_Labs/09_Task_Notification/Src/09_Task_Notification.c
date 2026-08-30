#include "FreeRTOS.h"
#include "task.h"

volatile uint32_t producerCount = 0;
volatile uint32_t consumerCount = 0;
uint32_t SystemCoreClock = 16000000U;
TaskHandle_t consumerTaskHandle;

/* Consumer Task */
void ConsumerTask(void *argument)
{
    while (1)
    {
        /*
         * Wait for a notification.
         * Task becomes BLOCKED here until Producer
         * sends a notification.
         */
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        consumerCount++;
    }
}


/* Producer Task */
void ProducerTask(void *argument)
{
    while (1)
    {
        producerCount++;
        /*
         * Send notification to Consumer Task.
         */
        xTaskNotifyGive(consumerTaskHandle);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


int main(void)
{
    /*
     * Create Consumer first so that
     * consumerTaskHandle gets its value.
     */
    xTaskCreate(ConsumerTask,"Consumer", 128, NULL, 1, &consumerTaskHandle);
    /*
     * Create Producer.
     */
    xTaskCreate(ProducerTask,"Producer",128,NULL,2,NULL);
    vTaskStartScheduler();
    while (1);
}
