/*
 * gpio.C
 *  Created on: Aug 22, 2026
 *      Author: vamsi
 */
#include "stm32g0xx.h"
#include <stdint.h>
#include "FreeRTOS.h"
#include "semphr.h"

extern SemaphoreHandle_t mySemaphore; //declaration


void gpio_init(){
	// 1. Enable GPIOC and SYSCFG Clocks
	RCC->IOPENR |= (1<<2); // enable GPIOC clock
//	RCC->APBENR2 |= RCC_APBENR2_SYSCFGEN; // enable the SYSCFG clock line
	// 2. Configure GPIOC Pin 13 as Input
	GPIOC->MODER &= ~(3 << 26);   // Clear bits 4 and 5 (Sets PC13 to Input Mode)

	// Step 1: Clear bits 15:8 to erase previous settings for Line 13
	EXTI->EXTICR[3] &= ~(0xFF << 8);
	// Step 2: Write 0x02 (Port C) into bits 15:8
	EXTI->EXTICR[3] |= (0x02 << 8);

	EXTI->FTSR1 |= (1 << 13); // Enable falling edge trigger for line 13
	EXTI->IMR1 |=(1<<13);
	NVIC_EnableIRQ(EXTI4_15_IRQn);

}


void EXTI4_15_IRQHandler(void) {
	if (EXTI->FPR1 & (1 << 13)){
	EXTI->FPR1 |= (1 << 13);
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR(mySemaphore,&xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}
}
