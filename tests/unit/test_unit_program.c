#include <unity.h>
#include <logic.h>

void test_logic_add(void)
{
    TEST_ASSERT_EQUAL(5, add(2,3));
    TEST_ASSERT_NOT_EQUAL(5, add(2,2));
}

void test_logic_subtract(void)
{
    TEST_ASSERT_EQUAL(5, subtract(10,5));
    TEST_ASSERT_NOT_EQUAL(4, subtract(10,5));
}

void test_logic_multiply(void)
{
    TEST_ASSERT_EQUAL(10, multiply(2,5));
    TEST_ASSERT_NOT_EQUAL(5, multiply(2,2));
}

void test_logic_divide(void)
{
    TEST_ASSERT_EQUAL(5.0, divide(10,2));
    TEST_ASSERT_EQUAL(-1.0, divide(10,0));
}
/**
* Funcion que se llama antes de ejecutar cualquier test, que me permite inicializar 
* alguna variable.
*/
void setUp(void)
{
}

/**
* Funcion que se llama despues de cada test. 
*/
void tearDown(void)
{
}
/**
* A la funcion RUN_TEST se le pasa como parametro un puntero a una funcion
*/
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_logic_add);
    RUN_TEST(test_logic_subtract);
    RUN_TEST(test_logic_multiply);
    RUN_TEST(test_logic_divide);
    return UNITY_END();
}