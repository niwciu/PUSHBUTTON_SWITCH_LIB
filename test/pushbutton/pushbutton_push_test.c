#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

#define DEBOUNCE_TIME_TO_STABLE_STATE (PUSHBUTTON_DEBOUNCE_TIME-1)
#define TIME_TO_EXECUTE_FIRST_REPETITION (PUSHBUTTON_FIRST_REPETITION_TIME-1)
#define TIME_TO_EXECUTE_N_REPETITION (PUSHBUTTON_CONTINUES_REPETITION_TIME-1)

typedef uint16_t debounce_repetition_timer_t;
TEST_GROUP(pushbutton_push);

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_timer_t delay, pushbutton_name_t button_name);
static void generete_pin_bouncing_on_push(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);
static void generate_pin_bounce_on_push(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);

TEST_SETUP(pushbutton_push)
{
    /* Init before every test */
    init_pushbuttons();
    TEST_TIMER=0;
}

TEST_TEAR_DOWN(pushbutton_push)
{
    /* Cleanup after every test */
}

TEST(pushbutton_push, WhenKey1InitThenKey1PinStateIsHigh)
{

    TEST_ASSERT_EQUAL(RELEASED,PUSHBUTTON_1_STATE);
}

TEST(pushbutton_push, WhenKey2InitThenKey2PinStateIsHigh)
{

    TEST_ASSERT_EQUAL(RELEASED,PUSHBUTTON_2_STATE);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}


TEST(pushbutton_push, GivenKey2InitAndIncTimerFunctionRegisteredAndKey2PushedAndBouncingWhenPushStableForDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_button_push_callback(BUTTON_2,inc_test_timer);
    check_button_push(BUTTON_2,REPETITION_OFF);
    PUSHBUTTON_2_STATE=PUSHED;
    check_button_push(BUTTON_2,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_2,REPETITION_OFF);
    check_button_push(BUTTON_2,REPETITION_OFF);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_2);
    check_button_push(BUTTON_2,REPETITION_OFF);
    check_button_push(BUTTON_2,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton_push,GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForMoreThanDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay((DEBOUNCE_TIME_TO_STABLE_STATE*100),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}
TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForDebounceTimeMinus1ThenTestTimerEqual0)
{
    //Given
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    //When
    generate_pushbutton_deb_rep_timer_delay((DEBOUNCE_TIME_TO_STABLE_STATE-1),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(0,TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForFirstRepetitionDelayTimeThenTestTimerEqual2)
{
   //Given
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF); 
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    //When
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    //Then
    TEST_ASSERT_EQUAL(2,TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForTimeFirstRepetitionTimeMinus1ThenTestTimerEqual1)
{

    //Given
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF); 
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    //When
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_FIRST_REPETITION-1),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    //Then
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedLongerThanFirstRepetitionTimeButShorterThenSecondRepetitionShouldAccourThenTestTimerValueIs2)
{
    //Given
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF); 
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    //When
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
     generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_N_REPETITION-1),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    //Then
    TEST_ASSERT_EQUAL(2,TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeEqualToReachDoubleRepetitionThenTestTimerValueIs3)
{
    //Given
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF); 
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    //Then
    TEST_ASSERT_EQUAL(3,TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLessToReachTripleRepetitionThenTestTimerValueIs3)
{

    //Given
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF); 
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_N_REPETITION-1),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    //Then
    TEST_ASSERT_EQUAL(3,TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLongerToReachTripleRepetitionThenTestTimerValueIs4)
{
    //Given
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF); 
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_N_REPETITION-1),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    //Then
    TEST_ASSERT_EQUAL(4,TEST_TIMER);
}

// TEST(pushbutton_push, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton_push, )
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
    switch(button_name)
    {
        case BUTTON_1:
            PUSHBUTTON_STATE=&PUSHBUTTON_1_STATE;  
            break;
        case BUTTON_2:
            PUSHBUTTON_STATE=&PUSHBUTTON_2_STATE; 
            break;
    }
    generate_pushbutton_deb_rep_timer_delay(5,button_name);
    check_button_push(button_name,repetition_switch);
    *PUSHBUTTON_STATE=RELEASED;
    check_button_push(button_name,repetition_switch);
    generate_pushbutton_deb_rep_timer_delay(10,button_name);
    check_button_push(button_name,repetition_switch);
    *PUSHBUTTON_STATE=PUSHED;
    check_button_push(button_name,repetition_switch);
}