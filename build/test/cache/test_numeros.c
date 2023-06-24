#include "src/numeros.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


Numero numero;

void setUp(){



}

void tearDown(){

    getNumero(&numero);

}



void numero_12 (void){

    agregarDig(&numero,'1');

    agregarDig(&numero,'2');

    UnityAssertEqualNumber((UNITY_INT)((12)), (UNITY_INT)((getNumero(&numero))), (

   ((void *)0)

   ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);

}



void numero_0 (void){

    agregarDig(&numero,'0');

    agregarDig(&numero,'0');

    UnityAssertEqualNumber((UNITY_INT)((12)), (UNITY_INT)((getNumero(&numero))), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

}

void numero_235453 (void){

    agregarDig(&numero,'2');

    agregarDig(&numero,'3');

    agregarDig(&numero,'5');

    agregarDig(&numero,'4');

    agregarDig(&numero,'5');

    agregarDig(&numero,'3');

    UnityAssertEqualNumber((UNITY_INT)((235453)), (UNITY_INT)((getNumero(&numero))), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}
