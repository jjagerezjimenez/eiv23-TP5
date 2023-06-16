#include <UART.h>
#include "BluePillHal.h"

int main (void){
    UART_enable();
    BP_Pin_mode(C13,OUT_2MHz);
    while (1){
        //const char a = UART_read();
        // if (a == 'a') BP_Pin_set(C13,1);
        // if (a == 's') BP_Pin_set(C13,0);

        UART_write(UART_read());
    }

    return 0;
}