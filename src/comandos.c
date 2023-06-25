#include "comandos.h"
#include <ctype.h>
#include <stdint.h>
#include "buffer.h"
#include "numeros.h"

static char const * const tabla_cmd[N_COMANDOS] = {
    "ang\n1",
    "ang?",
    "apagar",
    "id?",
    "reset"
};


typedef enum Estado {
    INICIO,
    buscaCMD,
    buscaNUM,
    blank,
    ERROR
}Estado;

typedef struct  Palabra
{
   int min;
   int max;
   int n;
}Palabra;



static void agregarLetra(Palabra * palabra, char c){   
    if (palabra->max < palabra->min) {
        return; //Si no hubo ninguna coincidencia la ultima vez, no hace nada.
    }
    if (isalpha(c)){
        c = tolower(c);
    }
    for (int i = palabra->min; i<= palabra->max; i++){ //  Busco la primera coincidencia.
        char caracter_tabla =  tabla_cmd[i][palabra->n];
        if (c == caracter_tabla){
            palabra->min = i;
            break;
        }
    }

    for (int i = palabra->min; i<=  palabra->max; i++){// Busco la primera diferencia.
        char caracter_tabla =  tabla_cmd[i][palabra->n];
        if (c != caracter_tabla) {
            palabra->max = i - 1;
            break;
        }
    }
    palabra->n++; 
}
static void palabraCLR(Palabra * palabra){
    palabra->max = N_COMANDOS - 1;
    palabra->min = 0;
    palabra->n = 0;
}
static Command getCMD(Palabra * palabra){
    Command const comando = ((palabra->max >= palabra->min) && ((tabla_cmd[palabra->min][palabra->n] == '\0' ) 
                                                            ||  (tabla_cmd[palabra->min][palabra->n] == '\n' )))

     ? palabra->min : DESCO;
    return comando;
}
static uint8_t cmd_c_parametro(Palabra * palabra){
    uint8_t cantidadParametros = 0;
    if (tabla_cmd[palabra->min][palabra->n ] == '\n'){
        cantidadParametros = (tabla_cmd[palabra->min][palabra->n + 1] - '0'); 
    }else{
        cantidadParametros = 0;
    }
    return cantidadParametros;
}
static bool esTerminador(char c){
    return (c == '\r' || c == '\n');
}

static void procesar_cmd(CMD * cmd){
    
 /*       switch (cmd->cmd)
    {        case ANG:
            UART_write_string("Angulo fijado en: ");
            UART_write_numero(cmd->parametro);
            UART_write('\n');           
        break;case ANGq:
            UART_write_string("Angulo fijado en: ");
            //UART_write_numero(getAngle(servo)); 
            UART_write('\n');           
        break;case IDq:
            UART_write_string("Controlador Servomotor v0.1\n");
        break;case DESCO:
            UART_write_string("Syntax ERROR!\n");
        break;default:
        break;
    }*/
}
bool getCommand(CMD * cmd, char c){
    static Estado estado = INICIO;
    static Palabra  palabra = {.max = N_COMANDOS - 1 , .min = 0, .n = 0 };
    static Numero numero;
    static uint8_t parametroRecibido = 0 ;
    bool encontrado = 0;
    if (esTerminador(c)){
        ///Comprueba si detectó un parametro valido///
        encontrado = 1;
        if(DESCO != getCMD(&palabra)){
            if((cmd_c_parametro(&palabra) == parametroRecibido)) {
                cmd->code = OK;
            }
            cmd->code = (cmd_c_parametro(&palabra) > parametroRecibido) ? FaltanParametros : SobranParametros;            
        }else{
            cmd->code = SyntaxError;
        }
        ///Actualiza cmd///
        cmd->cmd = getCMD(&palabra);
        for (int i = 0;i<= parametroRecibido; i++) cmd->parametro[i] = getNumero(&numero);
        ///Cond. Iniciales///
        estado = buscaCMD;
        parametroRecibido = 0;
        palabraCLR(&palabra);
        procesar_cmd(cmd);
    }else{
        switch (estado) {
        case ERROR:
        break;case INICIO: //Para que los espacios en blanco no afecten, y diferenciar de esperar un parametro
            if (isalpha(c)){
                estado = buscaCMD;
                agregarLetra(&palabra,c);
            }else if (isblank(c)){
                estado = buscaCMD;
            }else{
                estado = ERROR;
            }
        break;case buscaCMD:
            if (c == ' '){
                estado = blank;
            }else if(isalnum(c) || c== '?') {
                agregarLetra(&palabra,c);          
            }else{
            estado = ERROR;
            }
        break;case buscaNUM:
            if (isblank(c)){
                estado = blank;
            }else if(!agregarDig(&numero,c)) {
                estado = ERROR;
            }
        break;case blank: 
            if (agregarDig(&numero,c)){
                estado = buscaNUM;
                parametroRecibido++;
            }else if (!isblank(c)){
                estado = ERROR;
            }
        break;
        }
    }
    return encontrado;
}











