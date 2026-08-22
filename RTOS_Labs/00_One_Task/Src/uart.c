/*
 * uart.c
 *
 *  Created on: Aug 10, 2026
 *      Author: vamsi
 */

#include <stdio.h>
#include "stm32g0xx.h"

void uart_enable_clock(){
	RCC->APBENR1 |= (1<<17) ; //enable the UART2 clock
	RCC->IOPENR |= (1<<0) ; // enable clock for GPIOA
}

void gpio_uart_config() {

    // Set PA2, PA3 to Alternate mode
    GPIOA->MODER &= ~((3 << 4) | (3 << 6));
    GPIOA->MODER |=  (2 << 4) | (2 << 6);

    // Set AF1 (USART2)
    GPIOA->AFR[0] &= ~((0xF << 8) | (0xF << 12));
    GPIOA->AFR[0] |=  (1 << 8) | (1 << 12);

    USART2->BRR = 0x682;   // approx value
    USART2->CR1 |= (1 << 3);  // TE (Transmit enable)
    USART2->CR1 |= (1 << 2);  // RE (Receive enable)
    USART2->CR1 |= (1 << 0);  // UE (USART enable)
}


void uart_send_char(char c)
{
    while (!(USART2->ISR & (1 << 7)));  // wait TXE
    USART2->TDR = c;
}


int _write(int file, char *data, int len) {

	int i=0;
	while(i++<len){
	uart_send_char(*data++);
	}
    return len;
}


void usart2_init() {
	uart_enable_clock();          // your RCC
	gpio_uart_config();   // MODER + AFR
	printf("testing UART \n");
}
