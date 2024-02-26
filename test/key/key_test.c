#include "unity/fixture/unity_fixture.h"
#include "key_switch.h"
#include "mock_key_GPIO_driver.h"

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

TEST(key, WhenKey1InitThenKey1PinStateIsHigh)
{
    key_init(&KEY_1);
    TEST_ASSERT_EQUAL(HIGH,KEY_1_PIN_STATE);
}

TEST(key, WhenKey2InitThenKey2PinStateIsHigh)
{
    key_init(&KEY_2);
    TEST_ASSERT_EQUAL(HIGH,KEY_2_PIN_STATE);
}
