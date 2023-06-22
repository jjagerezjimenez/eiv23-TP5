#include "comandos.h"


void command_process(uint8_t * buffer, cmdtable tabla, uint16_t *  cmd, uint8_t * par)
{
    uint16_t cmd;

    do {int min = 0;
        int max = 64;
        int letra = 0;
        char const c = getchar(buffer);
        for (int i=min; i<=max; i++ ){
            if ( tabla_cmd[letra][i] == )

        }
        letra++;

    }while(c!=' ');

    do{

    }while(c=! '\n')

}