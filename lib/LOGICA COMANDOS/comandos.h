
#ifndef COMANDOS_H
#define COMANDOS_H
#include <stdint.h>
#include "buffer.h"
#include "UART.h"
#define N_COMANDOS 4
#define CMD_SIZE 5
#define MAX_N_PARAMETROS 4


typedef enum Command{
    ANG,
    ANGq, //ANG?
    IDq, //ID?
    NONE, 
    DESCO=255
}Command;

typedef struct CMD{
    Command cmd;
    uint8_t var[MAX_N_PARAMETROS];
}CMD;

void getCommand(CMD * cmd);



//Hacer una tabla con los valores por letra de antemano?



#endif