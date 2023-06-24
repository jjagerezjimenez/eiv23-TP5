#include <stm32f1xx.h>
#include "UART.h"
#include "stdbool.h"
#include "BluePillHal.h"
#include "buffer.h"
#include "comandos.h"

#define BAUDRATE 9600
 //Y con 4?
//contar las veces que se lleno el Buffer
//veces que se vació?

Buffer buffer_tx = {
    .i_save = 0,
    .i_use = 0,
};

Buffer buffer_rx = {
    .i_save = 0,
    .i_use = 0
};

CMD cmd;
int X;
char numerox[4];


void USART1_IRQHandler(void){

    if (USART1->SR & USART_SR_TXE) { // Interrupción por registro TX vacío
        char   leido;
        const bool HabiaParaLeer = buffer_leer(&buffer_tx, &leido);
        if (HabiaParaLeer){
            USART1->DR = leido;
        }else{
           USART1->CR1 &= ~USART_CR1_TXEIE;
        }
    }
    if (USART1->SR & USART_SR_RXNE){// Interrupcion por registro RX con caràcter
        const char c = USART1->DR;
        UART_write(c);
        bool IdentificoUnComando = getCommand(&cmd,c);
        if (IdentificoUnComando){
            UART_write('\n');
            switch (cmd.cmd)
            {
                case ANG:
                    UART_write('A');
                break;case ANGq:
                    UART_write('B');
                break;case IDq:
                    UART_write('C');
                break;case DESCO:
                    UART_write('X');
                break;default:
                break;
            }
        }
    }
    
}

void UART_init(void){
    BP_Pin_mode(A9,AO_PP);
    BP_Pin_mode(A10,IN_PULL_UP);
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    USART1->CR1 = USART_CR1_UE;
    USART1->CR2 = 0;
    USART1->CR3 = 0;
    SystemCoreClockUpdate();
    USART1->BRR = SystemCoreClock / (BAUDRATE);  
    __NVIC_EnableIRQ(USART1_IRQn);
    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
   
    
}

bool UART_read(char * c){
    return buffer_leer(&buffer_rx,c);
}
bool UART_write(char caracter){
    bool PudoEscribir = buffer_escribir(&buffer_tx,caracter);
    if (PudoEscribir) {USART1->CR1 |= USART_CR1_TXEIE;} //activa interrupciones si pudo escribir
    return PudoEscribir;
}


