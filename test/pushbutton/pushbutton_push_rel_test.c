#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

// #include "tested_module.h"
/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_1. */
static PUSHBUTTON_TypDef PUSHBUTTON_1;


typedef uint16_t debounce_repetition_delay_t;
TEST_GROUP(pushbutton_push_rel);

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_delay_t delay, PUSHBUTTON_TypDef *BUTTON);
static void generete_pin_bouncing_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE);
static void generate_pin_bounce_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE);
static void generete_pin_bouncing_on_release(PUSHBUTTON_TypDef *BUTTON,PB_input_state_t *mock_PUSHBUTTON_STATE);
static void generate_pin_bounce_on_release(PUSHBUTTON_TypDef *BUTTON,PB_input_state_t *mock_PUSHBUTTON_STATE);
static void ckeck_button_state_5_times(PUSHBUTTON_TypDef *BUTTON);

TEST_SETUP(pushbutton_push_rel)
{
    /* Init before every test */
    //Given ...
    init_pushbutton(&PUSHBUTTON_1,REPETITION_OFF,TRIGER_ON_SHORT_PUSH_AND_LONG_PUSH,pushbutton_1_GPIO_interface_get);
    TEST_TIMER=10;
    register_button_push_callback(&PUSHBUTTON_1,dec_test_timer);
    register_button_release_callback(&PUSHBUTTON_1,inc_test_timer);
}

TEST_TEAR_DOWN(pushbutton_push_rel)
{
    /* Cleanup after every test */
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeMaxPushTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual11)
{
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual11)
{
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_SHORT_PUSH_TIME_MAX-1,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual11)
{
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_SHORT_PUSH_TIME_MAX-1,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);

    TEST_ASSERT_EQUAL(11,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeLessThanMaxPushTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual11)
{
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((PUSHBUTTON_SHORT_PUSH_TIME_MAX-10),&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeLessThanMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual11)
{    
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((PUSHBUTTON_SHORT_PUSH_TIME_MAX-10),&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeLessThanMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual11)
{    
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((PUSHBUTTON_SHORT_PUSH_TIME_MAX-10),&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);

    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}


TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushBecomeStableWhenPushbuttonReleasedAndBouncingThenTestTimerEqual11)
{
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushBecomeStableWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual11)
{    
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushBecomeStableWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual11)
{    
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    TEST_ASSERT_EQUAL(11,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndNotStableWhenPushbuttonReleasedAndBouncingThenTestTimerEqual10)
{
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(10,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndNotStableWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual10)
{    
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(10,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndNotStableWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual10)
{    
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    TEST_ASSERT_EQUAL(10,TEST_TIMER);

}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndShortenThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9)
{
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_SHORT_PUSH_TIME_MAX,&PUSHBUTTON_1); // PUSHBUTTON_SHORT_PUSH_TIME_MAX - from this delay it push starting to be long push
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    TEST_ASSERT_EQUAL(9,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9)
{
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_SHORT_PUSH_TIME_MAX,&PUSHBUTTON_1); // PUSHBUTTON_SHORT_PUSH_TIME_MAX - from this delay it push starting to be long push
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,&PUSHBUTTON_1); // PUSHBUTTON_SHORT_PUSH_TIME_MAX - from this delay it push starting to be long push
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    TEST_ASSERT_EQUAL(9,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanTwiceFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9)
{
    //... Given 
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_SHORT_PUSH_TIME_MAX,&PUSHBUTTON_1); 
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,&PUSHBUTTON_1); 
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,&PUSHBUTTON_1); 
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    TEST_ASSERT_EQUAL(9,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitrAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndShortenThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9)
{
    //... Given 
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_SHORT_PUSH_TIME_MAX,&PUSHBUTTON_1); 
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    TEST_ASSERT_EQUAL(9,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitrAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual8)
{
    //... Given 
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_SHORT_PUSH_TIME_MAX,&PUSHBUTTON_1); 
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,&PUSHBUTTON_1); 
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    TEST_ASSERT_EQUAL(8,TEST_TIMER);
}

TEST(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitrAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanTwiceFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual7)
{
    //... Given 
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,&PUSHBUTTON_1);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_SHORT_PUSH_TIME_MAX,&PUSHBUTTON_1); 
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME,&PUSHBUTTON_1); 
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_CONTINUOUS_REPETITION_TIME,&PUSHBUTTON_1); 
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=RELEASED;
    ckeck_button_state_5_times(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    ckeck_button_state_5_times(&PUSHBUTTON_1);
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

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_delay_t delay,PUSHBUTTON_TypDef *BUTTON)
{
    for(debounce_repetition_delay_t i=delay; i>0;i--)
    {
        dec_pushbutton_deb_rep_timer(BUTTON);
    }
}
static void generete_pin_bouncing_on_push(PUSHBUTTON_TypDef *BUTTON,PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pin_bounce_on_push(BUTTON,mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON,mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON,mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON,mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON,mock_PUSHBUTTON_STATE);
}
static void generate_pin_bounce_on_push(PUSHBUTTON_TypDef *BUTTON,PB_input_state_t *mock_PUSHBUTTON_STATE)
{

    generate_pushbutton_deb_rep_timer_delay(5,BUTTON);
    ckeck_button_state_5_times(BUTTON);
    *mock_PUSHBUTTON_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON);
    generate_pushbutton_deb_rep_timer_delay(10,BUTTON);
    ckeck_button_state_5_times(BUTTON);
    *mock_PUSHBUTTON_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON);
}

static void generete_pin_bouncing_on_release(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pin_bounce_on_release(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON, mock_PUSHBUTTON_STATE);
}

static void generate_pin_bounce_on_release(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE)
{

    generate_pushbutton_deb_rep_timer_delay(5,BUTTON);
    ckeck_button_state_5_times(BUTTON);
    *mock_PUSHBUTTON_STATE=PUSHED;
    ckeck_button_state_5_times(BUTTON);
    generate_pushbutton_deb_rep_timer_delay(10,BUTTON);
    ckeck_button_state_5_times(BUTTON);
    *mock_PUSHBUTTON_STATE=RELEASED;
    ckeck_button_state_5_times(BUTTON);
}

static void ckeck_button_state_5_times(PUSHBUTTON_TypDef *BUTTON)
{
    check_button_short_push_long_push(BUTTON);
    check_button_short_push_long_push(BUTTON);
    check_button_short_push_long_push(BUTTON);
    check_button_short_push_long_push(BUTTON);
}
