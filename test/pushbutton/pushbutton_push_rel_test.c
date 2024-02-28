#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

// #include "tested_module.h"
typedef uint16_t debounce_repetition_timer_t;
TEST_GROUP(pushbutton_push_rel);

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_timer_t delay, pushbutton_name_t button_name);

TEST_SETUP(pushbutton_push_rel)
{
    /* Init before every test */
    init_pushbuttons();
    TEST_TIMER=0;
}

TEST_TEAR_DOWN(pushbutton_push_rel)
{
    /* Cleanup after every test */
}

TEST(pushbutton_push_rel, GivenKey1InitAndIncTimerFunctionRegisteredOnButtonReleaseWhenKey1PushAndReleasePinStateIsStableForDebounceTimeThenTestTimerEqual1)
{
    register_button_release_callback(BUTTON_1,inc_test_timer);
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    dec_pushbutton_deb_rep_timer(BUTTON_1);
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }
// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }
// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }
// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }
// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }
// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton_push_rel, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_timer_t delay,pushbutton_name_t button_name)
{
    for(debounce_repetition_timer_t i=delay; i>0;i--)
    {
        dec_pushbutton_deb_rep_timer(button_name);
    }
}