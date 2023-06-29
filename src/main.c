#include <UART.h>
#include <TIMER.h>
#include "BluePillHal.h"
#include <stm32f1xx.h>


int main (void){
    UART_init();
    TIM3_init();
    __WFI();
    return;
}

