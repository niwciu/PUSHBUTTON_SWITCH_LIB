#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

// #include "tested_module.h"
typedef uint16_t debounce_repetition_timer_t;
TEST_GROUP(pushbutton);

static void debounce_timer_delay(debounce_repetition_timer_t delay, enum pushbutton_e button_name);

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
    check_button_push(BUTTON_1,REPETITION_OFF);
    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    dec_debounce_timer(BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}


TEST(pushbutton, GivenKey2InitAndIncTimerFunctionRegisteredWhenKey2PushAndPinStateIsStableForDebounceTimeThenChangeIncTestTimer)
{
    register_button_push_callback(BUTTON_2,inc_test_timer);
    check_button_push(BUTTON_2,REPETITION_OFF);
    PUSHBUTTON_2_STATE=PUSHED;
    check_button_push(BUTTON_2,REPETITION_OFF);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_2);
    check_button_push(BUTTON_2,REPETITION_OFF);
    dec_debounce_timer(BUTTON_2);
    check_button_push(BUTTON_2,REPETITION_OFF);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton,GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndSignalisBouncingWhenSignalIsStableExactlyDefinedTimeThenTestTimerIsIncOnlyOnce)
{
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(5,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(120,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(150,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(35,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton,GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndSignalisBouncingWhenSignalIsStableLongerThenDefinedTimeThenTestTimerIsIncOnlyOnce)
{
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(5,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(120,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(150,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(35,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}
TEST(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndSignalisBouncingWhenSignalIsStableLessByOneThenDefinedTimeThenTestTimerIsNotInc)
{
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(5,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(120,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(150,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(35,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_OFF);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-2,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    check_button_push(BUTTON_1,REPETITION_OFF);
    TEST_ASSERT_EQUAL(0,TEST_TIMER);
}

TEST(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedAndFirstRepetitionDelayPassThenTestTimerValueIs2)
{
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(5,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(120,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(150,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(35,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME-1,BUTTON_1);
    
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    TEST_ASSERT_EQUAL(2,TEST_TIMER);
}

TEST(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForTimeLessThenFirstRepetitionTimeThenTestTimerValueIs1)
{

    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(5,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(120,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(150,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(35,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME-2,BUTTON_1);
    
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForTimeLongerThenFirstRepetitionDelayButShorterThenSecondRepetitionShouldAccourThenTestTimerValueIs2)
{

    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(5,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(120,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(150,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(35,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME-1,BUTTON_1);
    
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay((PUSHBUTTON_CONTINUES_REPETITION_TIME/2),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    TEST_ASSERT_EQUAL(2,TEST_TIMER);
}

TEST(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeEqualToReachDoubleRepetitionThenTestTimerValueIs3)
{

    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(5,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(120,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(150,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(35,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME-1,BUTTON_1);
    
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay((PUSHBUTTON_CONTINUES_REPETITION_TIME-1),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    TEST_ASSERT_EQUAL(3,TEST_TIMER);
}

TEST(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLessToReachDoubleRepetitionThenTestTimerValueIs2)
{

    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(5,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(120,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(150,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(35,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME-1,BUTTON_1);
    
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay((PUSHBUTTON_CONTINUES_REPETITION_TIME-2),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    TEST_ASSERT_EQUAL(2,TEST_TIMER);
}

TEST(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLongerToReachDoubleRepetitionThenTestTimerValueIs3)
{
    register_button_push_callback(BUTTON_1,inc_test_timer);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(5,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(120,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(150,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=UP;
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(35,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    PUSHBUTTON_1_STATE=PUSHED;
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_DEBOUNCE_TIME-1,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);

    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(PUSHBUTTON_FIRST_REPETITION_TIME-1,BUTTON_1);
    
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay((PUSHBUTTON_CONTINUES_REPETITION_TIME-1),BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    debounce_timer_delay(1,BUTTON_1);
    check_button_push(BUTTON_1,REPETITION_ON);
    check_button_push(BUTTON_1,REPETITION_ON);
    TEST_ASSERT_EQUAL(3,TEST_TIMER);
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

// TEST(pushbutton, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

static void debounce_timer_delay(debounce_repetition_timer_t delay,enum pushbutton_e button_name)
{
    for(debounce_repetition_timer_t i=delay; i>0;i--)
    {
        dec_debounce_timer(button_name);
    }
}