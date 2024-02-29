#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

// #include "tested_module.h"
typedef uint16_t debounce_repetition_timer_t;
TEST_GROUP(pushbutton_push_rel);

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_timer_t delay, pushbutton_name_t button_name);
static void generete_pin_bouncing_on_push(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);
static void generate_pin_bounce_on_push(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);
static void generete_pin_bouncing_on_release(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);
static void generate_pin_bounce_on_release(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);
static button_state_t* get_pusbutton_state_adr(pushbutton_name_t button_name);

TEST_SETUP(pushbutton_push_rel)
{
    /* Init before every test */
    //Given ...
    init_pushbuttons();
    TEST_TIMER=10;
    register_button_release_callback(BUTTON_1,dec_test_timer);
    register_button_release_callback(BUTTON_1,inc_test_timer);
}

TEST_TEAR_DOWN(pushbutton_push_rel)
{
    /* Cleanup after every test */
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndStablePushWhenReleasedBeforeMaxPushCallWindowThenTestTimerEqual11)
{
    //... Given 
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSBUTTON_MAX_PUSH_TIME_TO_CALL_PUSH_FUNC,BUTTON_1);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    //When
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    //Then
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(11,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndStablePushWhenReleasedAtMaxPushCallWindowThenTestTimerEqual11)
{
    //... Given 
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay((PUSBUTTON_MAX_PUSH_TIME_TO_CALL_PUSH_FUNC-1),BUTTON_1);
    PUSHBUTTON_1_STATE=RELEASED;
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    //When
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    //Then
    check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(11,TEST_TIMER);
}

// TEST(pushbutton_push, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndStablePushWhenReleasedAfterMaxPushCallWindowThenTestTimerEqual9)
// {
//     //Given
//     register_button_push_callback(BUTTON_1,inc_test_timer);
//     check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
//     PUSHBUTTON_1_STATE=PUSHED;
//     check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
//     generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
//     check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
//     //When
//     generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
//     check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
//     check_button_long_push_short_release(BUTTON_1,REPETITION_OFF);
//     //Then
//     TEST_ASSERT_EQUAL(1,TEST_TIMER);
// }

//test że dwa callbacki zarejestrowane 

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
static void generete_pin_bouncing_on_push(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch)
{
    generate_pin_bounce_on_push(button_name, repetition_switch);
    generate_pin_bounce_on_push(button_name, repetition_switch);
    generate_pin_bounce_on_push(button_name, repetition_switch);
    generate_pin_bounce_on_push(button_name, repetition_switch);
    generate_pin_bounce_on_push(button_name, repetition_switch);
}
static void generate_pin_bounce_on_push(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch)
{
    button_state_t *PUSHBUTTON_STATE;
    PUSHBUTTON_STATE=get_pusbutton_state_adr(button_name);

    generate_pushbutton_deb_rep_timer_delay(5,button_name);
    check_button_long_push_short_release(button_name,repetition_switch);
    *PUSHBUTTON_STATE=RELEASED;
    check_button_long_push_short_release(button_name,repetition_switch);
    generate_pushbutton_deb_rep_timer_delay(10,button_name);
    check_button_long_push_short_release(button_name,repetition_switch);
    *PUSHBUTTON_STATE=PUSHED;
    check_button_long_push_short_release(button_name,repetition_switch);
}

static void generete_pin_bouncing_on_release(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch)
{
    generate_pin_bounce_on_release(button_name, repetition_switch);
    generate_pin_bounce_on_release(button_name, repetition_switch);
    generate_pin_bounce_on_release(button_name, repetition_switch);
    generate_pin_bounce_on_release(button_name, repetition_switch);
    generate_pin_bounce_on_release(button_name, repetition_switch);
}

static void generate_pin_bounce_on_release(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch)
{
    button_state_t *PUSHBUTTON_STATE;
    PUSHBUTTON_STATE=get_pusbutton_state_adr(button_name);

    generate_pushbutton_deb_rep_timer_delay(5,button_name);
    check_button_long_push_short_release(button_name,repetition_switch);
    *PUSHBUTTON_STATE=PUSHED;
    check_button_long_push_short_release(button_name,repetition_switch);
    generate_pushbutton_deb_rep_timer_delay(10,button_name);
    check_button_long_push_short_release(button_name,repetition_switch);
    *PUSHBUTTON_STATE=RELEASED;
    check_button_long_push_short_release(button_name,repetition_switch);
}
static button_state_t* get_pusbutton_state_adr(pushbutton_name_t button_name)
{
    button_state_t *PUSHBUTTON_STATE;
    switch(button_name)
    {
        case BUTTON_1:
            PUSHBUTTON_STATE=&PUSHBUTTON_1_STATE;  
            break;
        case BUTTON_2:
            PUSHBUTTON_STATE=&PUSHBUTTON_2_STATE; 
            break;
    }
    return PUSHBUTTON_STATE;
}
