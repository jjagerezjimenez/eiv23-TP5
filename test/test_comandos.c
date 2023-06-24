#include <unity.h>
#include "comandos.h"
#include "numeros.h"

CMD cmd;

void setUp(void){
}
void tearDown(void){

}
void test_Comando_invalido (void){
    TEST_ASSERT_FALSE(getCommand(&cmd,'a'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'b'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'c'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'a'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'s'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'\n'));

}
void test_IDq (void){
    TEST_ASSERT_FALSE(getCommand(&cmd,'a'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'b'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'\n')); 
    TEST_ASSERT_FALSE(getCommand(&cmd,'i'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'d'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'?'));
    TEST_ASSERT_TRUE(getCommand(&cmd,'\n'));
    TEST_ASSERT_EQUAL(IDq , cmd.cmd);
    TEST_ASSERT_EQUAL(cmd.var, 0);
}
void test_ID_incompleto (void){
    TEST_ASSERT_FALSE(getCommand(&cmd,'a'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'b'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'\n')); 
    TEST_ASSERT_FALSE(getCommand(&cmd,'i'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'d'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'\n'));
    TEST_ASSERT_EQUAL(DESCO, cmd.cmd);
    TEST_ASSERT_EQUAL(cmd.var, 0);
}

void test_ANG_q (void){
    TEST_ASSERT_FALSE(getCommand(&cmd,'a'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'\n'));   
    TEST_ASSERT_FALSE(getCommand(&cmd,'a'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'n'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'g'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'?'));
    TEST_ASSERT_TRUE(getCommand(&cmd,'\n'));
    TEST_ASSERT_EQUAL(ANGq, cmd.cmd);
    TEST_ASSERT_EQUAL(cmd.var, 0);
}
void test_ANG(void){
    TEST_ASSERT_FALSE(getCommand(&cmd,'\n')); 
    TEST_ASSERT_FALSE(getCommand(&cmd,'a'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'n'));
    TEST_ASSERT_FALSE(getCommand(&cmd,'g'));
    TEST_ASSERT_TRUE(getCommand(&cmd,'\n'));
    TEST_ASSERT_EQUAL(ANG,cmd.cmd);
    TEST_ASSERT_EQUAL(cmd.var, 0);
}