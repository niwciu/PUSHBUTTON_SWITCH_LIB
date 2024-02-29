#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

#define DEBOUNCE_TIME_TO_STABLE_STATE (PUSHBUTTON_DEBOUNCE_TIME-1)

typedef uint16_t debounce_repetition_timer_t;
TEST_GROUP(pushbutton_release);

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_timer_t delay, pushbutton_name_t button_name);
static void generete_pin_bouncing_on_release(pushbutton_name_t button_name);
static void generate_pin_bounce_on_release(pushbutton_name_t button_name);

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


TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStateIsStableForDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_button_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generete_pin_bouncing_on_release(BUTTON_1);
    check_button_release(BUTTON_1);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_release(BUTTON_1);
    check_button_release(BUTTON_1);
    check_button_release(BUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStateIsStableForLessThanDebounceTimeThenTestTimerEqual0)
{
    //Given
    register_button_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generete_pin_bouncing_on_release(BUTTON_1);
    check_button_release(BUTTON_1);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE-1,BUTTON_1);
    check_button_release(BUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(0,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndReleaseAndPinBouncingThenTestTimerEqual0)
{
    //Given
    register_button_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    //When
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generete_pin_bouncing_on_release(BUTTON_1);
    check_button_release(BUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(0,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStayReleasedForPushButtonDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_button_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generete_pin_bouncing_on_release(BUTTON_1);
    check_button_release(BUTTON_1);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_release(BUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStayReleasedForlongerThanPushButtonDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_button_release_callback(BUTTON_1,inc_test_timer);
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(BUTTON_1);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(BUTTON_1);
    generete_pin_bouncing_on_release(BUTTON_1);
    check_button_release(BUTTON_1);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_release(BUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((DEBOUNCE_TIME_TO_STABLE_STATE*100),BUTTON_1);
    check_button_release(BUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

// ToDo dopisać testy na odporność na tzw push przez zakłócenie. Obecna implementacja raczej nie przejdzie tego testu
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
static void generete_pin_bouncing_on_release(pushbutton_name_t button_name)
{
    generate_pin_bounce_on_release(button_name);
    generate_pin_bounce_on_release(button_name);
    generate_pin_bounce_on_release(button_name);
    generate_pin_bounce_on_release(button_name);
    generate_pin_bounce_on_release(button_name);
}

static void generate_pin_bounce_on_release(pushbutton_name_t button_name)
{
    generate_pushbutton_deb_rep_timer_delay(5,button_name);
    check_button_release(button_name);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(button_name);
    generate_pushbutton_deb_rep_timer_delay(10,button_name);
    check_button_release(button_name);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(button_name);
}