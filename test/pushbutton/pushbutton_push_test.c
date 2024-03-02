#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"
#include "pushbutton_common_test.h"

#define DEBOUNCE_TIME_TO_STABLE_STATE (PUSHBUTTON_DEBOUNCE_TIME-1)
#define TIME_TO_EXECUTE_FIRST_REPETITION (PUSHBUTTON_FIRST_REPETITION_TIME -1)
#define TIME_TO_EXECUTE_N_REPETITION (PUSHBUTTON_CONTINUOUS_REPETITION_TIME -1)

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_1. */
static PUSHBUTTON_TypDef PUSHBUTTON_1;

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_2. */
static PUSHBUTTON_TypDef PUSHBUTTON_2;

TEST_GROUP(pushbutton_push);

TEST_SETUP(pushbutton_push)
{
    /* Init before every test */
    init_pushbutton(&PUSHBUTTON_1,REPETITION_OFF,TRIGER_ON_PUSH, pushbutton_1_GPIO_interface_get);
    init_pushbutton(&PUSHBUTTON_2,REPETITION_OFF,TRIGER_ON_PUSH, pushbutton_2_GPIO_interface_get);
    TEST_TIMER = 0;
}

TEST_TEAR_DOWN(pushbutton_push)
{
    /* Cleanup after every test */
}

TEST(pushbutton_push, WhenKey1InitThenKey1PinStateIsHigh)
{

    TEST_ASSERT_EQUAL(RELEASED, mock_PUSHBUTTON_1_STATE);
}

TEST(pushbutton_push, WhenKey2InitThenKey2PinStateIsHigh)
{

    TEST_ASSERT_EQUAL(RELEASED, mock_PUSHBUTTON_2_STATE);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForDebounceTimeThenTestTimerEqual1)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey2InitAndIncTimerFunctionRegisteredAndKey2PushedAndBouncingWhenPushStableForDebounceTimeThenTestTimerEqual1)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_2, inc_test_timer);
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_2);
    mock_PUSHBUTTON_2_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_2);
    generete_pin_bouncing_on_push(&PUSHBUTTON_2, &mock_PUSHBUTTON_2_STATE);
    check_pushbutton(&PUSHBUTTON_2);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_2);
    check_pushbutton(&PUSHBUTTON_2);
    check_pushbutton(&PUSHBUTTON_2);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForMoreThanDebounceTimeThenTestTimerEqual1)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((DEBOUNCE_TIME_TO_STABLE_STATE * 100), &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}
TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForDebounceTimeMinus1ThenTestTimerEqual0)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay((DEBOUNCE_TIME_TO_STABLE_STATE - 1), &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(0, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForFirstRepetitionDelayTimeThenTestTimerEqual2)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(2, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForTimeFirstRepetitionTimeMinus1ThenTestTimerEqual1)
{

    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_FIRST_REPETITION - 1), &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedLongerThanFirstRepetitionTimeButShorterThenSecondRepetitionShouldAccourThenTestTimerValueIs2)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_N_REPETITION - 1), &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(2, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeEqualToReachDoubleRepetitionThenTestTimerValueIs3)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(3, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLessToReachTripleRepetitionThenTestTimerValueIs3)
{

    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_N_REPETITION - 1), &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(3, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLongerToReachTripleRepetitionThenTestTimerValueIs4)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_N_REPETITION - 1), &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(4, TEST_TIMER);
}

// TEST(pushbutton_push, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }

// TEST(pushbutton_push, )
// {

//     TEST_FAIL_MESSAGE("added new test")
// }



