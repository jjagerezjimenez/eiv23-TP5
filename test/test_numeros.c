#include <unity.h>
#include "numeros.h"

Numero numero;
void setUp(){

}
void tearDown(){
    getNumero(&numero);
}

void numero_12 (void){
    agregarDig(&numero,'1');
    agregarDig(&numero,'2');
    TEST_ASSERT_EQUAL(12,getNumero(&numero));
}

void numero_0 (void){
    agregarDig(&numero,'0');
    agregarDig(&numero,'0');
    TEST_ASSERT_EQUAL(12,getNumero(&numero));
}
void numero_235453 (void){
    agregarDig(&numero,'2');
    agregarDig(&numero,'3');
    agregarDig(&numero,'5');
    agregarDig(&numero,'4');
    agregarDig(&numero,'5');
    agregarDig(&numero,'3');
    TEST_ASSERT_EQUAL(235453,getNumero(&numero));
}