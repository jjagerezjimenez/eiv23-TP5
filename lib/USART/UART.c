#include <stm32f1xx.h>
#include "UART.h"
#include "stdbool.h"
#include "BluePillHal.h"

#define BAUDRATE 9600

void USART1_IRQHandler(void){

}

void UART_enable(void){
    BP_Pin_mode(A9,AO_PP);
    BP_Pin_mode(A10,IN_PULL_UP);
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    USART1->CR1 = USART_CR1_UE;
    USART1->CR2 = 0;
    USART1->CR3 = 0;
    SystemCoreClockUpdate();
    USART1->BRR = SystemCoreClock / (BAUDRATE);  
    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
}

char UART_read(void){
    while (!(USART1->SR & USART_SR_RXNE));
    const char a = USART1->DR;
    return a;
}

void UART_write(char caracter){
    while (!(USART1->SR & USART_SR_TXE));
    USART1->DR = caracter;
    return;
}


