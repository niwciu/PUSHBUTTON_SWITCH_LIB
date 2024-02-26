#include "unity/fixture/unity_fixture.h"
#include "key_switch.h"
#include "mock_key_GPIO_driver.h"

// #include "tested_module.h"

TEST_GROUP(key);

TEST_SETUP(key)
{
    /* Init before every test */
    init_keys();
}

TEST_TEAR_DOWN(key)
{
    /* Cleanup after every test */
}

TEST(key, WhenKey1InitThenKey1PinStateIsHigh)
{

    TEST_ASSERT_EQUAL(HIGH,KEY_1_PIN_STATE);
}

TEST(key, WhenKey2InitThenKey2PinStateIsHigh)
{

    TEST_ASSERT_EQUAL(HIGH,KEY_2_PIN_STATE);
}

TEST(key, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndPinStateIsStableForDebounceTimeThenChangeIncTestTimer)
{
    TEST_TIMER=0;
    register_key_push_callback(&KEY_1,inc_test_tmer);
    KEY_1_PIN_STATE=LOW;
    check_key_push(&KEY_1);
    KEY_1.key_debounce_timer=2;
    check_key_push(&KEY_1);
    KEY_1.key_debounce_timer=1;
    check_key_push(&KEY_1);
    check_key_push(&KEY_1);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

// TEST(key, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndIncTestTimerexecutedWhenPinStateHighandcheckKeyPushThenkeyDebounceTimerEqualKeyDebounceTime)
// {
//     TEST_TIMER=0;
//     register_key_push_callback(&KEY_1,inc_test_tmer);
//     KEY_1_PIN_STATE=LOW;
//     check_key_push(&KEY_1);
//     KEY_1.key_debounce_timer=2;
//     check_key_push(&KEY_1);
//     KEY_1.key_debounce_timer=1;
//     check_key_push(&KEY_1);
//     check_key_push(&KEY_1);
//     KEY_1_PIN_STATE=HIGH;
//     check_key_push(&KEY_1);
//     TEST_ASSERT_EQUAL(KEY_DEBOUNCE_TIME,KEY_1.key_debounce_timer);
// }
// check previous state on init
// check 

// TEST(key, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(key, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(key, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(key, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(key, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }
