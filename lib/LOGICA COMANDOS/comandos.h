
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
    
    int min =0, max = MAX_N_PARAMETROS;
    char const c = getchar(buffer);
    for (int i = min; i<max; i++){
        if (c== tabla_cmd[i][n]){
            min = i;
            break;}
    }
    for (int i = min; i<max; i++){
    if (c != tabla_cmd[i][n]) {
        max = i;
        break;}
    }
}



#endif