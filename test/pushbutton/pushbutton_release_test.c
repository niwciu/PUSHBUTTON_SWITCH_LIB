#include "unity/fixture/unity_fixture.h"
#include "pushbutton_switch.h"
#include "mock_pushbutton_GPIO_driver.h"

#define DEBOUNCE_TIME_TO_STABLE_STATE (PUSHBUTTON_DEBOUNCE_TIME-1)

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_1. */
static PUSHBUTTON_TypDef PUSHBUTTON_1;

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_2. */
static PUSHBUTTON_TypDef PUSHBUTTON_2;

typedef uint16_t debounce_repetition_delay_t;
TEST_GROUP(pushbutton_release);

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_delay_t delay, PUSHBUTTON_TypDef *BUTTON);
static void generete_pin_bouncing_on_release(PUSHBUTTON_TypDef *BUTTON,PB_input_state_t *mock_PUSHBUTTON_STATE);
static void generate_pin_bounce_on_release(PUSHBUTTON_TypDef *BUTTON,PB_input_state_t *mock_PUSHBUTTON_STATE);

TEST_SETUP(pushbutton_release)
{
    /* Init before every test */
    init_pushbutton(&PUSHBUTTON_1,REPETITION_OFF, TRIGER_ON_RELEASE,pushbutton_1_GPIO_interface_get);
    init_pushbutton(&PUSHBUTTON_2,REPETITION_OFF, TRIGER_ON_RELEASE, pushbutton_2_GPIO_interface_get);
    TEST_TIMER=0;
}

TEST_TEAR_DOWN(pushbutton_release)
{
    /* Cleanup after every test */
}


TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStateIsStableForDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_button_release_callback(&PUSHBUTTON_1,inc_test_timer);
    check_button_release(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    check_button_release(&PUSHBUTTON_1);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,&PUSHBUTTON_1);
    check_button_release(&PUSHBUTTON_1);
    check_button_release(&PUSHBUTTON_1);
    check_button_release(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStateIsStableForLessThanDebounceTimeThenTestTimerEqual0)
{
    //Given
    register_button_release_callback(&PUSHBUTTON_1,inc_test_timer);
    check_button_release(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    check_button_release(&PUSHBUTTON_1);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE-1,&PUSHBUTTON_1);
    check_button_release(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(0,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndReleaseAndPinBouncingThenTestTimerEqual0)
{
    //Given
    register_button_release_callback(&PUSHBUTTON_1,inc_test_timer);
    check_button_release(&PUSHBUTTON_1);
    //When
    mock_PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    check_button_release(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(0,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStayReleasedForPushButtonDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_button_release_callback(&PUSHBUTTON_1,inc_test_timer);
    check_button_release(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    check_button_release(&PUSHBUTTON_1);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,&PUSHBUTTON_1);
    check_button_release(&PUSHBUTTON_1);
    //Then
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
}

TEST(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStayReleasedForlongerThanPushButtonDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_button_release_callback(&PUSHBUTTON_1,inc_test_timer);
    check_button_release(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=PUSHED;
    check_button_release(&PUSHBUTTON_1);
    mock_PUSHBUTTON_1_STATE=RELEASED;
    check_button_release(&PUSHBUTTON_1);
    generete_pin_bouncing_on_release(&PUSHBUTTON_1,&mock_PUSHBUTTON_1_STATE);
    check_button_release(&PUSHBUTTON_1);
    //When
    generate_pushbutton_deb_rep_timer_delay(DEBOUNCE_TIME_TO_STABLE_STATE,&PUSHBUTTON_1);
    check_button_release(&PUSHBUTTON_1);
    generate_pushbutton_deb_rep_timer_delay((DEBOUNCE_TIME_TO_STABLE_STATE*100),&PUSHBUTTON_1);
    check_button_release(&PUSHBUTTON_1);
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

static void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_delay_t delay,PUSHBUTTON_TypDef *BUTTON)
{
    for(debounce_repetition_delay_t i=delay; i>0;i--)
    {
        dec_pushbutton_deb_rep_timer(BUTTON);
    }
}
static void generete_pin_bouncing_on_release(PUSHBUTTON_TypDef *BUTTON,PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pin_bounce_on_release(BUTTON,mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON,mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON,mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON,mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON,mock_PUSHBUTTON_STATE);
}

static void generate_pin_bounce_on_release(PUSHBUTTON_TypDef *BUTTON,PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pushbutton_deb_rep_timer_delay(5,BUTTON);
    check_button_release(BUTTON);
    *mock_PUSHBUTTON_STATE=PUSHED;
    check_button_release(BUTTON);
    generate_pushbutton_deb_rep_timer_delay(10,BUTTON);
    check_button_release(BUTTON);
    *mock_PUSHBUTTON_STATE=RELEASED;
    check_button_release(BUTTON);
}