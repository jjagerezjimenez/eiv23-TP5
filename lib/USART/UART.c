#include <stm32f1xx.h>
#include "UART.h"
#include "stdbool.h"
#include "BluePillHal.h"

#define BAUDRATE 9600
#define BUFFER_MAX 64

typedef struct Buffer{
    char * chars;
    uint8_t i_save;
    uint8_t i_use;
    uint8_t size;
}Buffer;

Buffer buffer_tx = {
    .i_save = 0,
    .i_use = 0,
    .size = 64
};

void bufferInit(Buffer * self){
    self-> chars = calloc(self -> size , sizeof( char ));
}


bool BufferLleno(Buffer * self){
    return (self->i_save + 1) == self->i_use;
}

bool BufferVacio(Buffer * self){
    return self->i_use == self->i_save;
}

static uint8_t siguienteModular(uint8_t valor,uint8_t modulo){
    if (!modulo) return 0;
    if (valor >= (modulo - 1)) {
        valor = 0;
    }else{
        valor = valor + 1;
    }
    return valor;
}

bool buffer_escribir(Buffer * self, char caracter){
    if (BufferLleno (self)) return 0;
    self->chars[self->i_save] = caracter;
    // Asignar nuevo valor
    self->i_save = siguienteModular(self->i_save,self->size);
    return true;
}


bool buffer_leer(Buffer * self, char * caracter_p){
    if (BufferVacio(self)) return 0;

    *caracter_p = self->chars[self->i_use];
    self->i_use = siguienteModular(self->i_use,self->size);
    return 1;
}


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
    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
    bufferInit(&buffer_tx);
    
}
char UART_read(void){
    while (!(USART1->SR & USART_SR_RXNE));
    const char a = USART1->DR;
    return a;
}
bool UART_write(char caracter){
    bool PudoEscribir = buffer_escribir(&buffer_tx,caracter);
    if (PudoEscribir) {USART1->CR1 |= USART_CR1_TXEIE;}
    return PudoEscribir;
}


