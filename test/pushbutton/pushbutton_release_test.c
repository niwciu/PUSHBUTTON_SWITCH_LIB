#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

// #include "tested_module.h"
typedef uint16_t debounce_repetition_timer_t;
TEST_GROUP(pushbutton_release);

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_timer_t delay, pushbutton_name_t button_name);

TEST_SETUP(pushbutton_release)
{
    /* Init before every test */
    init_pushbuttons();
    TEST_TIMER=0;
}

TEST_TEAR_DOWN(pushbutton_release)
{
    /* Cleanup after every test */
}


TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndUpPinStateIsStableForDebounceTimeThenChangeIncTestTimer)
{
    register_button_push_or_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_release(BUTTON_1);
    dec_pushbutton_deb_rep_timer(BUTTON_1);
    check_button_release(BUTTON_1);
    check_button_release(BUTTON_1);
    check_button_release(BUTTON_1);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndUpPinStateIsStableForLessThanDebounceTimeThenTestTimerEqual0)
{
    register_button_push_or_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_release(BUTTON_1);
    check_button_release(BUTTON_1);

    TEST_ASSERT_EQUAL(0,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndReleaseAndPinBounceInTimeShorterThanDebounceTimeThenTestTimerEqual0)
{
    register_button_push_or_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(10,BUTTON_1);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(1,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(6,BUTTON_1);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(84,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_release(BUTTON_1);

    TEST_ASSERT_EQUAL(0,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndReleaseAndPinBounceAndNextStayReleasedForPushButtonDebounceThenTestTimerEqual1)
{
    register_button_push_or_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(10,BUTTON_1);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(1,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(6,BUTTON_1);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(84,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_release(BUTTON_1);

    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndReleaseAndPinBouncAndNextStayReleasedForlongerPushButtonDebounceThenTestTimerEqual1)
{
    register_button_push_or_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(10,BUTTON_1);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(1,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(6,BUTTON_1);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(84,BUTTON_1);
    check_button_release(BUTTON_1);

    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(100,BUTTON_1);
    check_button_release(BUTTON_1);
    check_button_release(BUTTON_1);
    check_button_release(BUTTON_1);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}
// TEST(pushbutton_release, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton_release, )
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