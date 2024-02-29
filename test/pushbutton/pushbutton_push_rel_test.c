#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

// #include "tested_module.h"

// #define TIME_TO_EXECUTE_FIRST_REPETITION (PUSHBUTTON_FIRST_REPETITION_TIME-1)
// #define TIME_TO_EXECUTE_N_REPETITION (PUSHBUTTON_CONTINUES_REPETITION_TIME-1)
typedef uint16_t debounce_repetition_timer_t;
TEST_GROUP(pushbutton_push_rel);

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_timer_t delay, pushbutton_name_t button_name);
static void generete_pin_bouncing_on_push(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);
static void generate_pin_bounce_on_push(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);
static void generete_pin_bouncing_on_release(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);
static void generate_pin_bounce_on_release(pushbutton_name_t button_name, pushbutton_repetition_t repetition_switch);
static button_state_t* get_pusbutton_state_adr(pushbutton_name_t button_name);
static void ckeck_button_state_5_times(pushbutton_name_t button_name, pushbutton_repetition_t long_push_repetition);

TEST_SETUP(pushbutton_push_rel)
{
    /* Init before every test */
    //Given ...
    init_pushbuttons();
    TEST_TIMER=10;
    register_button_push_callback(BUTTON_1,dec_test_timer);
    register_button_release_callback(BUTTON_1,inc_test_timer);
}

TEST_TEAR_DOWN(pushbutton_push_rel)
{
    /* Cleanup after every test */
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeMaxPushTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual11)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual11)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSBUTTON_SHORT_PUSH_TIME_MAX-1,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual11)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSBUTTON_SHORT_PUSH_TIME_MAX-1,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);

    TEST_ASSERT_EQUAL(11,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeLessThanMaxPushTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual11)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay((PUSBUTTON_SHORT_PUSH_TIME_MAX-10),BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeLessThanMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual11)
{    
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay((PUSBUTTON_SHORT_PUSH_TIME_MAX-10),BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeLessThanMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual11)
{    
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay((PUSBUTTON_SHORT_PUSH_TIME_MAX-10),BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);

    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}


TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushBecomeStableWhenPushbuttonReleasedAndBouncingThenTestTimerEqual11)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushBecomeStableWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual11)
{    
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushBecomeStableWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual11)
{    
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndNotStableWhenPushbuttonReleasedAndBouncingThenTestTimerEqual10)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(10,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndNotStableWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual10)
{    
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //Then
    TEST_ASSERT_EQUAL(10,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndNotStableWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual10)
{    
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(10,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndShortenThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSBUTTON_SHORT_PUSH_TIME_MAX,BUTTON_1); // PUSBUTTON_SHORT_PUSH_TIME_MAX - from this delay it push starting to be long push
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(9,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSBUTTON_SHORT_PUSH_TIME_MAX,BUTTON_1); // PUSBUTTON_SHORT_PUSH_TIME_MAX - from this delay it push starting to be long push
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,BUTTON_1); // PUSBUTTON_SHORT_PUSH_TIME_MAX - from this delay it push starting to be long push
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(9,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanTwiceFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSBUTTON_SHORT_PUSH_TIME_MAX,BUTTON_1); 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,BUTTON_1); 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,BUTTON_1); 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_OFF);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(9,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitrAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndShortenThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_ON);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(PUSBUTTON_SHORT_PUSH_TIME_MAX,BUTTON_1); 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_ON);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    TEST_ASSERT_EQUAL(9,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitrAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual8)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_ON);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(PUSBUTTON_SHORT_PUSH_TIME_MAX,BUTTON_1); 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,BUTTON_1); 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_ON);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    TEST_ASSERT_EQUAL(8,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitrAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanTwiceFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual7)
{
    //... Given 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generete_pin_bouncing_on_push(BUTTON_1,REPETITION_ON);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(PUSBUTTON_SHORT_PUSH_TIME_MAX,BUTTON_1); 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,BUTTON_1); 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_CONTINUES_REPETITION_TIME,BUTTON_1); 
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    //When
    PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    generete_pin_bouncing_on_release(BUTTON_1,REPETITION_ON);
    ckeck_button_state_5_times(BUTTON_1,REPETITION_ON);
    TEST_ASSERT_EQUAL(7,TEST_TIMER);
}
//co jak po pushu i execucie z pusha w czasie debouncu wejdzie znowu do pusha







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
    ckeck_button_state_5_times(button_name,repetition_switch);
    *PUSHBUTTON_STATE=RELEASED;
    ckeck_button_state_5_times(button_name,repetition_switch);
    generate_pushbutton_deb_rep_timer_delay(10,button_name);
    ckeck_button_state_5_times(button_name,repetition_switch);
    *PUSHBUTTON_STATE=PUSHED;
    ckeck_button_state_5_times(button_name,repetition_switch);
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
    ckeck_button_state_5_times(button_name,repetition_switch);
    *PUSHBUTTON_STATE=PUSHED;
    ckeck_button_state_5_times(button_name,repetition_switch);
    generate_pushbutton_deb_rep_timer_delay(10,button_name);
    ckeck_button_state_5_times(button_name,repetition_switch);
    *PUSHBUTTON_STATE=RELEASED;
    ckeck_button_state_5_times(button_name,repetition_switch);
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

static void ckeck_button_state_5_times(pushbutton_name_t button_name, pushbutton_repetition_t long_push_repetition)
{
    check_button_short_push_long_push(button_name,long_push_repetition);
    check_button_short_push_long_push(button_name,long_push_repetition);
    check_button_short_push_long_push(button_name,long_push_repetition);
    check_button_short_push_long_push(button_name,long_push_repetition);
}
