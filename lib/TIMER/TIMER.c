#include <stm32f1xx.h>
#include "BluePillHal.h"
#include <string.h>

#define PERIODO_PWM 20000  // Período del PWM en microsegundos
#define ANCHO_PULSO_MIN 1000  // Ancho de pulso mínimo en microsegundos
#define ANCHO_PULSO_MAX 2000  // Ancho de pulso máximo en microsegundos

#define MAX_LONG_COMANDO 10

//esto puede estar sujeto a cambios, no se como unir bien el resto del programa con el timer, pero esto es un intento
volatile uint32_t comando_listo = 0; // Indicador de comando listo
volatile char comando_recibido[MAX_LONG_COMANDO]; // Almacenamiento del comando recibido

//void TIM3_IRQHandler(void);       //ver comenarios en la funcion

void TIM3_init(void) {
    // Habilitar el reloj para TIM3 
    //Veificar que timer usar*********
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    // Configurar el Timer en modo PWM
    TIM3->CR1 = 0;  // Limpiar el registro de control
    TIM3->CR2 = 0;  // Limpiar el registro de control 2
    TIM3->CCMR1 = TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;  // Modo PWM1 en canal 1
    TIM3->CCER = TIM_CCER_CC1E;  // Habilitar la salida del canal 1

    //SystemCoreClockUpdate();      //ver esto, creo que no hace falta porque tengo entendido que sirve si se actualiza la frecuencia del reloj del micro, y creo que eso no pasa aqui

    TIM3->PSC = (SystemCoreClock / 1000000) - 1;  // Configurar el preescaler para una frecuencia de 1MHz
    TIM3->ARR = PERIODO_PWM - 1;  // Configurar el período del PWM

    // Configurar el pin de salida del PWM (PA6)
    GPIOA->CRL &= ~(GPIO_CRL_CNF6 | GPIO_CRL_MODE6);  // Limpiar los bits de configuración del pin
    GPIOA->CRL |= GPIO_CRL_CNF6_1 | GPIO_CRL_MODE6_1;  // Modo de salida alternativa push-pull

    // Habilitar la interrupción del timer
    TIM3->DIER |= TIM_DIER_UIE;

    // Configurar el NVIC para la interrupción del TIM3
    //NVIC_SetPriority(TIM3_IRQn, 0);  // Establecer la prioridad de la interrupción
    //NVIC_EnableIRQ(TIM3_IRQn);

    // Iniciar el Timer
    TIM3->CR1 |= TIM_CR1_CEN;
/*
    // Configurar el pin de salida del PWM (PA6) //NO funciona asi 
    BP_Pin_mode(A6, AO_PP);

    // Habilitar la interrupción del timer
    TIM3->DIER |= TIM_DIER_UIE;

    // Configurar el NVIC para la interrupción del TIM3
    NVIC_EnableIRQ(TIM3_IRQn);

    // Iniciar el Timer
    TIM3->CR1 |= TIM_CR1_CEN;
*/
}

void set_servo_angle(uint32_t angle) {
    // Calcular el ancho de pulso correspondiente al ángulo
    uint32_t ancho_pulso = ANCHO_PULSO_MIN + ((ANCHO_PULSO_MAX - ANCHO_PULSO_MIN) * angle) / 180;

    // Configurar el valor del registro de comparación del canal 1 para establecer el ancho de pulso
    TIM3->CCR1 = ancho_pulso;
}

/* //hay que ver como implementamos las interrupciones aqui asi usamos esta funcion 
void TIM3_IRQHandler(void) {            // Limpiar la bandera de interrupción?? ver bien esto
    TIM3->SR &= ~TIM_SR_UIF;
}
*/

int get_servo_angle(void){
  return TIM3->CCR1 * 180;
}
/*
int main(void) {
    // Inicializar el Timer 3
    TIM3_init();

    while (1) {
        if (comando_listo) {    // hay algun comando?

            uint32_t angle = atoi(comando_recibido + 4);    // extrae el ángulo del comando recibido (por ejemplo, "ang 60")
            set_servo_angle(angle);     //mueve el servo el angulo envido
            comando_listo = 0;                 // reinicia el flag de comando listo para recibir nuevos comandos
        }
    }
}*/

// ver esto, es una implementación de la función de recepción de comandos
/*void recibir_comando(char* comando) {

    if (strncmp(comando, "ang ", 4) == 0 && strlen(comando) <= MAX_LONG_COMANDO) {          // verifica si el comando es válido y tiene el formato adecuado

        strncpy(comando_recibido, comando, MAX_LONG_COMANDO);           // copia el comando recibido a la variable global
        comando_recibido[MAX_LONG_COMANDO - 1] = '\0';       // asegura terminación nula

        comando_listo = 1;              //indicador de comando listo
    }
}*/



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