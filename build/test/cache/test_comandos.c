#include "src/numeros.h"
#include "src/comandos.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


CMD cmd;



void setUp(void){

}

void tearDown(void){



}

void test_Comando_invalido (void){

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(13)));}} while(0);

    do {if (!(getCommand(&cmd,'b'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(14)));}} while(0);

    do {if (!(getCommand(&cmd,'c'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(15)));}} while(0);

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(16)));}} while(0);

    do {if (!(getCommand(&cmd,'s'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(17)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(18)));}} while(0);



}

void test_IDq (void){

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(22)));}} while(0);

    do {if (!(getCommand(&cmd,'b'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(23)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(24)));}} while(0);

    do {if (!(getCommand(&cmd,'i'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(25)));}} while(0);

    do {if (!(getCommand(&cmd,'d'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(26)));}} while(0);

    do {if (!(getCommand(&cmd,'?'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(27)));}} while(0);

    do {if ((getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(28)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((IDq)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((cmd.var)), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}

void test_ID_incompleto (void){

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(33)));}} while(0);

    do {if (!(getCommand(&cmd,'b'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(34)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(35)));}} while(0);

    do {if (!(getCommand(&cmd,'i'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(36)));}} while(0);

    do {if (!(getCommand(&cmd,'d'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(37)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(38)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((DESCO)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((cmd.var)), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

}



void test_ANG_q (void){

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(44)));}} while(0);

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(45)));}} while(0);

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(46)));}} while(0);

    do {if (!(getCommand(&cmd,'n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(47)));}} while(0);

    do {if (!(getCommand(&cmd,'g'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(48)));}} while(0);

    do {if (!(getCommand(&cmd,'?'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(49)));}} while(0);

    do {if ((getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(50)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((ANGq)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((cmd.var)), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

}

void test_ANG(void){

    do {if (!(getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(55)));}} while(0);

    do {if (!(getCommand(&cmd,'a'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(56)));}} while(0);

    do {if (!(getCommand(&cmd,'n'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(57)));}} while(0);

    do {if (!(getCommand(&cmd,'g'))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(58)));}} while(0);

    do {if ((getCommand(&cmd,'\n'))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(59)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((ANG)), (UNITY_INT)((cmd.cmd)), (

   ((void *)0)

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((cmd.var)), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

}
