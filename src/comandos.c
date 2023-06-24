#include "comandos.h"
#include <ctype.h>
#include <stdint.h>
#include "buffer.h"
#include "numeros.h"

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
    Command const comando = ((palabra->max >= palabra->min) && (tabla_cmd[palabra->min][palabra->n] == '\0' )) ? palabra->min : DESCO;
    return comando;
}

bool esTerminador(char c){
    return (c == ' ' || c == '\r' || c == '\n');
}

/// @brief 
/// @param cmd 
/// @param c 
/// @return 
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
            cmd->cmd = DESCO;
            palabraCLR(&palabra);
            getNumero(&numero);
        }
    }else{
        switch (estado) {
        case INICIO:
            palabraCLR(&palabra);
            getNumero(&numero);
            if (isalpha(c)){
                estado = buscaCMD;
                agregarLetra(&palabra,c);
            }
        break;case buscaCMD:
            if (c == ' '){
                estado = getCMD(&palabra) != DESCO ? buscaNUM : INICIO;
            }else if(isalnum(c) || c== '?') {
                agregarLetra(&palabra,c);          
            }else{
            estado = INICIO;
            }
        break;case buscaNUM:
            if (c != ' '){
                if (isdigit(c)) {
                    agregarDig(&numero,c);
                }else{
                    estado = INICIO;
                }
            }
        break;
        }
    }
    return 0;
}










