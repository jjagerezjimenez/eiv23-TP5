#include "comandos.h"

char const tabla_cmd[N_COMANDOS][CMD_SIZE] = {
    {'A','N','G',' ',' '},  //ANG
    {'A','N','G','?',' '},  //ANG?
    {'I','D','?',' ',' '},   //ID?
    {'N','O','N','E',' '}, 
};

void getCommand(CMD * cmd){
    int min =0, max = N_COMANDOS , n=0;
    char c;
    bool par_valido = 1;
    Numero param = {0};
    UART_read(&c);
    while (c!= '\r' && c!= ' '){

        
        for (int i = min; i<=max; i++){ //  Busco la primera coincidencia
            if (c== tabla_cmd[i][n]){
                min = i;
                break;
            }
        }
        for (int i = min; i<=max; i++){// Busco la primera diferencia
            if (c != tabla_cmd[i][n]) {
                max = i - 1;
                break;
            }
        }
        n++;
        if (max < min) {
            UART_write ('F');
            break;
        }
        UART_read(&c); //como volver si no habia caracter?
    }
    if ((tabla_cmd[min][n] == ' ')){ //???
        max=min;          
    }
    if (max == min){
        cmd->cmd = max;
    }else{
        cmd->cmd = DESCO; 
    }
    if (c=='\n'){
        return;
    }
    getNumero(&param);
    do{
        UART_read(&c);
        if (!agregarDig(&param,c)) {
            par_valido=0;
            break;
        }
    }while(c != '\n');
    if(par_valido) {
        cmd->var[0] = getNumero(&param);
    }else{
        cmd->var[0] = 0;
    }
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