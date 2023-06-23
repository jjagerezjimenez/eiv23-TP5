
#ifndef COMANDOS_H
#define COMANDOS_H
#include <stdint.h>
#include "buffer.h"
#define N_COMANDOS 3
#define CMD_SIZE 4
#define MAX_N_PARAMETROS 4

char const tabla_cmd[N_COMANDOS][CMD_SIZE] = {
    {'A','N','G',' '},  //ANG
    {'A','N','G','?'},  //ANG?
    {'I','D','?',' '}   //ID?
};

typedef enum Command{
    ANG,
    ANGq, //ANG?
    IDq, //ID?
    ERROR=255
}Command;

typedef struct CMD{
    Command cmd;
    uint8_t var[MAX_N_PARAMETROS];
}CMD;


void getCommand(Buffer * buffer, CMD * cmd){
int min =0, max = MAX_N_PARAMETROS, n=0;
do{
    char const c = getchar(buffer);
    for (int i = min; i<max; i++){
        if (c== tabla_cmd[i][n]){
            min = i;
            break;}
    }
    for (int i = min; i<=max; i++){
    if (c != tabla_cmd[i][n]) {
        max = i - 1;
        break;}
    }
    n++;
    if (max < min) break;
}while (c != ' ')
if (max == min) cmd->cmd = max;
else cmd->cmd = ERROR; 
}

static int agregarDig(uint8_t * digitos){
    static uint8_t cantidad = 0;
}

void getParameter(Buffer * buffer, CMD * cmd){
    do{
        agregarDig(parametro);
    }while (Esunnumero(c))
    return getInt(parametro);
}



//Hacer una tabla con los valores por letra de antemano?



#endif