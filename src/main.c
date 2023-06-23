#include <UART.h>
#include "BluePillHal.h"

int main (void){
    UART_init();
    BP_Pin_mode(C13,OUT_2MHz);

    
    for(;;);

    return 0;
}

