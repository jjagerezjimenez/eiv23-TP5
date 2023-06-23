#include "numeros.h"


static bool charToInt(char c,int * num){
    if (c <= '9' && c >= '0') {
        *num = (int)c - 48;
    }else{
        return 0;
    }
    return 1;
}

bool agregarDig(Numero * numero,char c){
    int num;
    if (numero->index + 1 == 10  || !charToInt(c,&num)){
        return 0;}
    numero->numero += num * numero->index;
    numero->index = numero->index * 10;
    return 1;
}

int getNumero(Numero * numero){
    int resultado = numero->numero;
    numero->index = 1;
    numero->numero  = 0;
    return resultado;
}


uint8_t toChar(int numero, char * char_n,uint8_t size ){
    int max=0;
    for(uint8_t i = 0 ; i<=10 ; i++){
        if (numero == 0) {
            max = i;
            break;}
        char_n[i] = (char) (numero % 10 + 48);
        numero = numero/10;
    }
    //cambiar orden??

    for (uint8_t i = max+1; i<size; i++){
        char_n[i] = 'x';
    }
    
    return max;
}
