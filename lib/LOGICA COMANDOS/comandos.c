#include "comandos.h"
#include <ctype.h>

//char const tabla_cmd[N_COMANDOS][CMD_SIZE] = {
//    {'A','N','G',' ',' '},  //ANG
//    {'A','N','G','?',' '},  //ANG?
//    {'I','D','?',' ',' '},   //ID?
//    {'N','O','N','E',' '}, 
//};


static char const * const tabla_cmd[N_COMANDOS] = {
    "ang",
    "ang?",
    "id?"
};

typedef enum Estado {
    INICIO,
    buscaCMD,
    buscaNUM
}Estado;

typedef struct  Palabra
{
   int min;
   int max;
   int n;
}Palabra;



void agregarLetra(Palabra * palabra, char c){   
    if (palabra->max < palabra->min) {
        return; //Guarda por si hubo una diferencia
    }
    if (isalpha(c)){
        c = tolower(c);
    }
    for (int i = palabra->min; i<= palabra->max; i++){ //  Busco la primera coincidencia
    volatile char tabla =  tabla_cmd[i][palabra->n];
        if (c == tabla){
            palabra->min = i;
            break;
        }
    }

    for (int i = palabra->min; i<=  palabra->max; i++){// Busco la primera diferencia
    volatile char tabla =  tabla_cmd[i][palabra->n];

        if (c != tabla) {
            palabra->max = i - 1;
            break;
        }
    }

    palabra->n++;
    
}

void palabraCLR(Palabra * palabra){
    palabra->max = N_COMANDOS - 1;
    palabra->min = 0;

    palabra->n = 0;
}
Command getCMD(Palabra * palabra){
    if ((palabra->max == palabra->min ) && (tabla_cmd[palabra->max][palabra->n + 1] == 0 )){
//Y si era el ùnico pero no se termino de escribir?
        return palabra->max;
    }else{
        return DESCO;
    }
}






bool esTerminador(char c){
    return (c == ' ' || c == '\r' || c == '\n');
}

bool getCommand(CMD * cmd, char c){
    static Estado estado = INICIO;
    static Palabra  palabra = {.max = N_COMANDOS - 1 , .min = 0, .n = 0 };
    static Numero numero;


    if (esTerminador(c)){
        estado = INICIO;
        if(getCMD(&palabra) != DESCO) {
            cmd->cmd = getCMD(&palabra);
            cmd->var = getNumero(&numero);
            palabraCLR(&palabra);
            return 1;
        }else{
            palabraCLR(&palabra);
            getNumero(&numero);
        }

    }else{
        switch (estado) {
            case INICIO:
                UART_write('I');
                palabraCLR(&palabra);
                getNumero(&numero);
                if (isalpha(c)){
                    estado = buscaCMD;
                    agregarLetra(&palabra,c);
                }

            break;case buscaCMD:
                UART_write('K');
                if ( (isalnum (c)) || (c == ' ') || (c == '?' )) 
                
                {
                    agregarLetra(&palabra,c); 
                    estado = buscaCMD;
                    if (c == ' '){
                        if ( getCMD(&palabra) != DESCO){
                            estado = buscaNUM;
                        }else{
                            estado = INICIO;
                        }
                    }         
                }else{
                    estado = INICIO;
                }

            break;case buscaNUM:
                if (isdigit(c)) {
                    agregarDig(&numero,c);
                }else{
                    estado = INICIO;
                }
            break;
        }
    }
    return 0;
}










