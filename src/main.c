#include <UART.h>
#include "BluePillHal.h"

int main (void){
    UART_init();
    BP_Pin_mode(C13,OUT_2MHz);
    while (1){
    UART_read();
        for(int i=0;i<500;i++){
            while ( ! (UART_write('X')) ); //suma int y char no es error?   
        }
            UART_write('\n');
    }

    return 0;
}