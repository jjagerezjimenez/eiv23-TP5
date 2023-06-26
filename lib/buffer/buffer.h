#ifndef BUFFER_H
#define BUFFER_H
#include <stdint.h>
#include <stdbool.h>
#define BUFFER_MAX 64

typedef struct Buffer{
    char  chars[BUFFER_MAX];
    uint8_t i_save;
    uint8_t i_use;
}Buffer;

bool buffer_escribir(Buffer * self, char caracter);
bool buffer_leer(Buffer * self, char * caracter_p);
void buffer_clr(Buffer * self);
#endif