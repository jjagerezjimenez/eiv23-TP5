#include "src/numeros.h"
#include "src/comandos.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


CMD cmd;



void setUp(void){

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(8)));}} while(0);

}

void tearDown(void){

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(11)));}} while(0);

}

void test_Comando_invalido (void){

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(14)));}} while(0);

    do {if (!(getCommand(&cmd,'b'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(15)));}} while(0);

    do {if (!(getCommand(&cmd,'c'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(16)));}} while(0);

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(17)));}} while(0);

    do {if (!(getCommand(&cmd,'s'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(18)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(19)));}} while(0);



}

void test_IDq (void){

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(23)));}} while(0);

    do {if (!(getCommand(&cmd,'b'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(24)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(25)));}} while(0);

    do {if (!(getCommand(&cmd,'i'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(26)));}} while(0);

    do {if (!(getCommand(&cmd,'d'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(27)));}} while(0);

    do {if (!(getCommand(&cmd,'?'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(28)));}} while(0);

    do {if ((getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(29)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((IDq)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((cmd.var)), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}

void test_ID_incompleto (void){

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(34)));}} while(0);

    do {if (!(getCommand(&cmd,'b'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(35)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(36)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((DESCO)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);

    do {if (!(getCommand(&cmd,'i'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(38)));}} while(0);

    do {if (!(getCommand(&cmd,'d'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(39)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(40)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((DESCO)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((cmd.var)), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_INT);

}



void test_ANG_q (void){

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(46)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(47)));}} while(0);

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(48)));}} while(0);

    do {if (!(getCommand(&cmd,'n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(49)));}} while(0);

    do {if (!(getCommand(&cmd,'g'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(50)));}} while(0);

    do {if (!(getCommand(&cmd,'?'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(51)));}} while(0);

    do {if ((getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(52)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((ANGq)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((cmd.var)), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

}

void test_ANG(void){

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(57)));}} while(0);

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(58)));}} while(0);

    do {if (!(getCommand(&cmd,'n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(59)));}} while(0);

    do {if (!(getCommand(&cmd,'g'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(60)));}} while(0);

    do {if ((getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(61)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((ANG)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((cmd.var)), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}

void test_ANG_c_numero (void){

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(66)));}} while(0);

    do {if (!(getCommand(&cmd,'n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(67)));}} while(0);

    do {if (!(getCommand(&cmd,'g'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(68)));}} while(0);

    do {if ((getCommand(&cmd,' '))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(69)));}} while(0);

    do {if (!(getCommand(&cmd,'1'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(70)));}} while(0);

    do {if (!(getCommand(&cmd,'2'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(71)));}} while(0);

    do {if (!(getCommand(&cmd,'2'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(72)));}} while(0);

    do {if ((getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(73)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((ANG)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((cmd.var)), (UNITY_INT)((122)), (

   ((void *)0)

   ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT);

}
