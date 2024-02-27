#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

// #include "tested_module.h"

TEST_GROUP(pushbutton);

TEST_SETUP(pushbutton)
{
    /* Init before every test */
    init_pushbuttons();
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
    TEST_TIMER=0;
    register_button_push_callback(BUTTON_1,inc_test_timer);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1);
    for(input_debounce_timer_t i=PUSHBUTTON_DEBOUNCE_TIME; i>2;i--)
    {
        dec_debounce_timer(BUTTON_1);
    }
    check_button_push(BUTTON_1);
    dec_debounce_timer(BUTTON_1);
    check_button_push(BUTTON_1);
    check_button_push(BUTTON_1);
    check_button_push(BUTTON_1);
    check_button_push(BUTTON_1);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

// check previous state on init
// check 

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

// TEST(pushbutton, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }
