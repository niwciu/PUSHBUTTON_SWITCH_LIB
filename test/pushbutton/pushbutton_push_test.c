#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

#define DEBOUNCE_TIME_TO_STABLE_STATE (PUSHBUTTON_DEBOUNCE_TIME - 1)
#define TIME_TO_EXECUTE_FIRST_REPETITION (PUSHBUTTON_FIRST_REPETITION_TIME - 1)
#define TIME_TO_EXECUTE_N_REPETITION (PUSHBUTTON_CONTINUOUS_REPETITION_TIME - 1)

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_1. */
static PUSHBUTTON_TypDef PUSHBUTTON_1;

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_2. */
static PUSHBUTTON_TypDef PUSHBUTTON_2;

typedef uint16_t debounce_repetition_delay_t;
TEST_GROUP(pushbutton_push);

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_delay_t delay, PUSHBUTTON_TypDef *BUTTON);
static void generete_pin_bouncing_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE);
static void generate_pin_bounce_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE);

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
    check_button_push(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_button_push(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey2InitAndIncTimerFunctionRegisteredAndKey2PushedAndBouncingWhenPushStableForDebounceTimeThenTestTimerEqual1)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_2, inc_test_timer);
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_2);
    mock_PUSHBUTTON_2_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_2);
    generete_pin_bouncing_on_push(&PUSHBUTTON_2, &mock_PUSHBUTTON_2_STATE);
    check_button_push(&PUSHBUTTON_2);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_2);
    check_button_push(&PUSHBUTTON_2);
    check_button_push(&PUSHBUTTON_2);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForMoreThanDebounceTimeThenTestTimerEqual1)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_button_push(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((DEBOUNCE_TIME_TO_STABLE_STATE * 100), &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}
TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForDebounceTimeMinus1ThenTestTimerEqual0)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    disable_pusbutton_repetition(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_button_push(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay((DEBOUNCE_TIME_TO_STABLE_STATE - 1), &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(0, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForFirstRepetitionDelayTimeThenTestTimerEqual2)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(2, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForTimeFirstRepetitionTimeMinus1ThenTestTimerEqual1)
{

    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_FIRST_REPETITION - 1), &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedLongerThanFirstRepetitionTimeButShorterThenSecondRepetitionShouldAccourThenTestTimerValueIs2)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_N_REPETITION - 1), &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(2, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeEqualToReachDoubleRepetitionThenTestTimerValueIs3)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_button_push(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(3, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLessToReachTripleRepetitionThenTestTimerValueIs3)
{

    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_button_push(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_N_REPETITION - 1), &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(3, TEST_TIMER);
}

TEST(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLongerToReachTripleRepetitionThenTestTimerValueIs4)
{
    // Given
    register_button_push_callback(&PUSHBUTTON_1, inc_test_timer);
    enable_pusbutton_repetition(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_button_push(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_button_push(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_FIRST_REPETITION, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(TIME_TO_EXECUTE_N_REPETITION, &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((TIME_TO_EXECUTE_N_REPETITION - 1), &PUSHBUTTON_1);
    check_button_push(&PUSHBUTTON_1);
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

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_delay_t delay, PUSHBUTTON_TypDef *BUTTON)
{
    for (debounce_repetition_delay_t i = delay; i > 0; i--)
    {
        dec_pushbutton_deb_rep_timer(BUTTON);
    }
}
static void generete_pin_bouncing_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
}

static void generate_pin_bounce_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pushbutton_deb_rep_timer_delay(5, BUTTON);
    check_button_push(BUTTON);
    *mock_PUSHBUTTON_STATE = RELEASED;
    check_button_push(BUTTON);
    generate_pushbutton_deb_rep_timer_delay(10, BUTTON);
    check_button_push(BUTTON);
    *mock_PUSHBUTTON_STATE = PUSHED;
    check_button_push(BUTTON);
}