#include "unity/fixture/unity_fixture.h"

// #include "tested_module.h"

TEST_GROUP(key);

TEST_SETUP(key)
{
    /* Init before every test */
}

TEST_TEAR_DOWN(key)
{
    /* Cleanup after every test */
}

TEST(key, FirstTest)
{
    TEST_FAIL_MESSAGE("Implement your test!");
}
