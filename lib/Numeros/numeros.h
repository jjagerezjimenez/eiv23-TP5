#ifndef NUMEROS_H
#define NUMEROS_H
#include <stdint.h>
#include <stdbool.h>

typedef struct Numero {
    int numero;
    uint8_t index;
}Numero;



/**
 * @brief Agrega un digito al numero
 * 
 * @param numero 
 * @param c 
 * @return true Si pudo agregarlo
 * @return false Si no pudo, esto puede ser porque esta lleno el arreglo o porque era invàlido
 */
bool agregarDig(Numero * numero,char c);
/**
 * @brief Devuleve el numero guardado y resetea para guardar un nuevo numero
 * 
 * @param numero 
 * @return int 
 */
int getNumero(Numero * numero);
/**
 * @brief Guarda el nuemro como arreglod e caracteres:
 * Numero = 1234
 * size = 8
 * char_n[size] = [4,3,2,1,x,x,x,x]
 * 
 * Devuleve la posicion de primer elemento 'x'
 * 
 * @param numero 
 * @param char_n 
 * @param size 
 * @return uint8_t 
 */
uint8_t toChar(int numero, char * char_n, uint8_t size );

#endif