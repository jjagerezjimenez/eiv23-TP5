
#ifndef COMANDOS_H
#define COMANDOS_H
#define N_COMANDOS 5
#define MAX_N_PARAMETROS 1
#include <stdbool.h>


typedef enum Command{
    ANG,
    ANGq, //ANG?
    APAGAR, 
    IDq, //ID?
    RESET_CMD,
    DESCO=255
}Command;

typedef enum Codigo{
    OK,
    none,
    SyntaxError,
    FaltanParametros,
    SobranParametros
}Codigo;

typedef struct CMD{
    Command cmd;
    int parametro[9];
    Codigo code;
}CMD;


bool getCommand(CMD * cmd, char c);





#endif