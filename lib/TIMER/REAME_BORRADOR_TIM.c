#include <stm32f1xx.h>
#include "BluePillHal.h"

#define PERIODO_PWM 20000  // Período del PWM en microsegundos
#define ANCHO_PULSO_MIN 1000  // Ancho de pulso mínimo en microsegundos
#define ANCHO_PULSO_MAX 2000  // Ancho de pulso máximo en microsegundos

void TIM3_IRQHandler(void);

void TIM3_init(void) {
    // Habilitar el reloj para TIM3 
    //Veificar que timer usar*********
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    // Configurar el Timer en modo PWM
    TIM3->CR1 = 0;  // Limpiar el registro de control
    TIM3->CR2 = 0;  // Limpiar el registro de control 2
    TIM3->CCMR1 = TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;  // Modo PWM1 en canal 1
    TIM3->CCER = TIM_CCER_CC1E;  // Habilitar la salida del canal 1
    SystemCoreClockUpdate();
    TIM3->PSC = (SystemCoreClock / 1000000) - 1;  // Configurar el preescaler para una frecuencia de 1MHz
    TIM3->ARR = PERIODO_PWM - 1;  // Configurar el período del PWM

    // Configurar el pin de salida del PWM (PA6) //NO funciona asi 
    BP_Pin_mode(A6, AO_PP);

    // Habilitar la interrupción del timer
    TIM3->DIER |= TIM_DIER_UIE;

    // Configurar el NVIC para la interrupción del TIM3
    NVIC_EnableIRQ(TIM3_IRQn);

    // Iniciar el Timer
    TIM3->CR1 |= TIM_CR1_CEN;
}

void set_servo_angle(uint8_t angle) {
    // Calcular el ancho de pulso correspondiente al ángulo
    uint32_t ancho_pulso = ANCHO_PULSO_MIN + ((ANCHO_PULSO_MAX - ANCHO_PULSO_MIN) * angle) / 180;

    // Configurar el valor del registro de comparación del canal 1 para establecer el ancho de pulso
    TIM3->CCR1 = ancho_pulso;
}

void TIM3_IRQHandler(void) {
    // Limpiar la bandera de interrupción
    TIM3->SR &= ~TIM_SR_UIF;
}

int main(void) {
    // Inicializar el Timer 3
    TIM3_init();

    // Configurar el ángulo inicial del servo
    uint8_t initial_angle = 90;
    set_servo_angle(initial_angle);

    while (1) {
        // Realizar alguna acción o esperar aquí
    }
}

