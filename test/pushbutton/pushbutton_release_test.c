#include "unity/fixture/unity_fixture.h"
#include "pushbutton.h"
#include "mock_pushbutton_GPIO_driver.h"
#include "pushbutton_common_test.h"

#define DEBOUNCE_TIME_TO_STABLE_STATE (PUSHBUTTON_DEBOUNCE_TIME - 1)

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_1. */
static PUSHBUTTON_TypDef PUSHBUTTON_1;

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_2. */
static PUSHBUTTON_TypDef PUSHBUTTON_2;

TEST_GROUP(pushbutton_release);

TEST_SETUP(pushbutton_release)
{
    /* Init before every test */
    init_pushbutton(&PUSHBUTTON_1, REPETITION_OFF, TRIGGER_ON_RELEASE, pb_1_GPIO_interface_get);
    init_pushbutton(&PUSHBUTTON_2, REPETITION_OFF, TRIGGER_ON_RELEASE, pb_2_GPIO_interface_get);
    TEST_TIMER = 0;
}

TEST_TEAR_DOWN(pushbutton_release)
{
    /* Cleanup after every test */
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndReleaseAndBouncingWhenPinStateIsStableForDebounceTimeThenTestTimerEqual1)
{
    // Given
    register_button_release_callback(&PUSHBUTTON_1, inc_test_timer);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = RELEASED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndReleaseAndBouncingWhenPinStateIsStableForLessThanDebounceTimeThenTestTimerEqual0)
{
    // Given
    register_button_release_callback(&PUSHBUTTON_1, inc_test_timer);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = RELEASED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE - 1, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(0, TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndBouncingAndReleaseAndPinBouncingThenTestTimerEqual0)
{
    // Given
    register_button_release_callback(&PUSHBUTTON_1, inc_test_timer);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = RELEASED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(0, TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndReleaseAndBouncingWhenPinStayReleasedForPushButtonDebounceTimeThenTestTimerEqual1)
{
    // Given
    register_button_release_callback(&PUSHBUTTON_1, inc_test_timer);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = RELEASED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndReleaseAndBouncingWhenPinStayReleasedForlongerThanPushButtonDebounceTimeThenTestTimerEqual1)
{
    // Given
    register_button_release_callback(&PUSHBUTTON_1, inc_test_timer);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = PUSHED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_push(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay(PUSHBUTTON_DEBOUNCE_TIME, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE = RELEASED;
    check_pushbutton(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1, &mock_PUSHBUTTON_1_STATE);
    check_pushbutton(&PUSHBUTTON_1);
    // When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE, &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((DEBOUNCE_TIME_TO_STABLE_STATE * 100), &PUSHBUTTON_1);
    check_pushbutton(&PUSHBUTTON_1);
    // Then
    TEST_ASSERT_EQUAL(1, TEST_TIMER);
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
