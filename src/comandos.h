
#ifndef COMANDOS_H
#define COMANDOS_H
#define N_COMANDOS 3
#define CMD_SIZE 5
#define MAX_N_PARAMETROS 1
#include <stdbool.h>


typedef enum Command{
    ANG,
    ANGq, //ANG?
    IDq, //ID?
    NONE, 
    DESCO=255
}Command;

typedef struct CMD{
    Command cmd;
    int var;
}CMD;

/// @brief 
/// @param cmd 
/// @param c 
/// @return 
bool getCommand(CMD * cmd, char c);



//Hacer una tabla con los valores por letra de antemano?



#endif