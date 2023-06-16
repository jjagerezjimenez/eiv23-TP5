#ifndef UART_H
#define UART_H

/**
 * @brief Esta libreria controla el periferico USART 1 en:
 * Modo asincrònico Full Duplex
 * Pines A09 (Tx) y A10(Rx)
 * Baudrate = 9600
 * 
 */


void UART_enable(void);

/**
 * @brief Lee el caracter recibido
 * 
 * @return char 
 */
char UART_read(void);
/**
 * @brief Envía un caracter por el puerto
 * 
 * @param caracter 
 */
void UART_write(char caracter);

















#endif
