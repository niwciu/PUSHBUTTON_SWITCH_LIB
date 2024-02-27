#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

// #include "tested_module.h"
typedef uint8_t input_debounce_timer_t;
TEST_GROUP(pushbutton);

static void debounce_timer_delay(input_debounce_timer_t delay, enum pushbutton_e button_name);

TEST_SETUP(pushbutton)
{
    /* Init before every test */
    init_pushbuttons();
    TEST_TIMER=0;
}

TEST_TEAR_DOWN(pushbutton)
{
    /* Cleanup after every test */
}

TEST(pushbutton, WhenKey1InitThenKey1PinStateIsHigh)
{

    TEST_ASSERT_EQUAL(UP,PUSHBUTTON_1_STATE);
}

TEST(pushbutton, WhenKey2InitThenKey2PinStateIsHigh)
{

    TEST_ASSERT_EQUAL(UP,PUSHBUTTON_2_STATE);
}

TEST(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndPinStateIsStableForDebounceTimeThenChangeIncTestTimer)
{
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_push(BUTTON_1);
    dec_debounce_timer(BUTTON_1);
    check_button_push(BUTTON_1);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}


TEST(pushbutton, GivenKey2InitAndIncTimerFunctionRegisteredWhenKey2PushAndPinStateIsStableForDebounceTimeThenChangeIncTestTimer)
{
    register_button_push_callback(BUTTON_2,inc_test_timer);
    check_button_push(BUTTON_2);
    PUSHBUTTON_2_STATE=PUSHED;
    check_button_push(BUTTON_2);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_2);
    check_button_push(BUTTON_2);
    dec_debounce_timer(BUTTON_2);
    check_button_push(BUTTON_2);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

// TEST(pushbutton, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

static void debounce_timer_delay(input_debounce_timer_t delay,enum pushbutton_e button_name)
{
    for(input_debounce_timer_t i=delay; i>0;i--)
    {
        dec_debounce_timer(button_name);
    }
}