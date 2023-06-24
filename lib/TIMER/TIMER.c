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
    // Limpiar la bandera de interrupción ??
    TIM3->SR &= ~TIM_SR_UIF;
}

int main(void) {
    // Inicializar el Timer 3
    TIM3_init();

    // Configurar el ángulo inicial del servo
    uint8_t initial_angle = 90;
    set_servo_angle(initial_angle);


/*
  BP_inicio(); ¿debo iniciar yo la placa blue pill? consultar eso y donde agrego el timer ahora

  BP_Pin_mode(SERVO_PIN, OUT_2MHz); //pin para el servo como salida

  configure_timer();        //conf el tempo


  USART1_init(9600);            //para iniciar la comunicacion serial, ver el tema d elos 9600 baudios
*/

    while (true) {
        // Realizar alguna acción o esperar aquí
    uint8_t angle = recibir_angulo_desde_pc();

    set_servo_angle(angle);     // para establecer el ángulo del servomotor

    esperar_tiempo(1000); // Esperar 1 segundo (ver bien esto)

    /*
     
        if (USART1_available()) {       // ¿se ha recibido un dato por comunicación SERIAL? (ver bien esto)
      
      uint8_t angle = (uint8_t)USART1_read();   //leo angulo

      set_servo_angle(angle);   //lo cargo en el servo
    */

    }
}




/*

#include <stm32f1xx.h>
#include "BluePillHal.h"

#define SERVO_PIN A0
#define SERVO_MIN_ANGLE 0
#define SERVO_MAX_ANGLE 180
#define SERVO_MIN_PULSE_WIDTH 500  // Tiempo mínimo de pulso en microsegundos (0 grados)
#define SERVO_MAX_PULSE_WIDTH 2500 // Tiempo máximo de pulso en microsegundos (180 grados)

// Variables globales
volatile uint32_t servo_pulse_width = 0;

void set_servo_pulse_width(uint32_t pulse_width) {
  servo_pulse_width = pulse_width;
}

void configure_timer(void) {
  // Habilitar el reloj para TIMER3
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

  // Configurar el prescaler y el contador del temporizador
  TIM3->PSC = 72 - 1;  // Prescaler = 72 (72MHz / 72 = 1MHz)
  TIM3->ARR = 20000;   // Auto-reload = 20000 (1MHz / 20000 = 50Hz)

  // Configurar el canal 1 del temporizador como salida PWM
  TIM3->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1; // Modo PWM1
  TIM3->CCMR1 |= TIM_CCMR1_OC1PE;                    // Habilitar preload
  TIM3->CCER |= TIM_CCER_CC1E;                        // Habilitar la salida del canal 1

  // Configurar el canal 1 del temporizador para generar interrupciones cuando alcanza el valor del CCR1
  TIM3->DIER |= TIM_DIER_CC1IE;

  // Habilitar la interrupción del temporizador
  NVIC_EnableIRQ(TIM3_IRQn);

  // Iniciar el temporizador
  TIM3->CR1 |= TIM_CR1_CEN;
}

void set_servo_angle(uint8_t angle) {
  if (angle < SERVO_MIN_ANGLE) {
    angle = SERVO_MIN_ANGLE;
  } else if (angle > SERVO_MAX_ANGLE) {
    angle = SERVO_MAX_ANGLE;
  }

  uint32_t pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  set_servo_pulse_width(pulse_width);
}

void TIM3_IRQHandler(void) {
  if (TIM3->SR & TIM_SR_CC1IF) {
    // Limpiar la bandera de interrupción del canal 1
    TIM3->SR &= ~TIM_SR_CC1IF;

    // Actualizar el valor del CCR1 para el próximo pulso
    TIM3->CCR1 = servo_pulse_width;
  }
}

int main(void) {
 
???
???
???

while (true)

?????????
?????????
??????

*/