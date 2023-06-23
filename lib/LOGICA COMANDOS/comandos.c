#include "comandos.h"

char const tabla_cmd[N_COMANDOS][CMD_SIZE] = {
    {'A','N','G',' ',' '},  //ANG
    {'A','N','G','?',' '},  //ANG?
    {'I','D','?',' ',' '},   //ID?
    {'N','O','N','E',' '}, 
};

void getCommand(CMD * cmd){
int min =0, max = MAX_N_PARAMETROS, n=0;
char c;
do{
    UART_read(&c); //como volver si no habia caracter?
    for (int i = min; i<=max; i++){
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
    if (max < min) {UART_write ('F'); break;}
}while (c != ' ');
if (max == min) cmd->cmd = max;
else cmd->cmd = DESCO; 
}

/*
static int agregarDig(uint8_t * digitos){
    static uint8_t cantidad = 0;
}

void getParameter(Buffer * buffer, CMD * cmd){
    do{
        agregarDig(parametro);
    }while (Esunnumero(c))
    return getInt(parametro);
}
*/