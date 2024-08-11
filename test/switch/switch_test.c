#include "unity/fixture/unity_fixture.h"
#include "mock_switch_GPIO_driver.h"
#include "switch.h"

typedef uint16_t debounce_repetition_t;

SWITCH_TypDef SW_1;

static void check_switch_X_times(SWITCH_TypDef *SWITCH, debounce_repetition_t repetition);
static void switch_1_pin_bouncing_on_ON(SWITCH_TypDef *SWITCH);
static void switch_1_pin_bouncing_on_OFF(SWITCH_TypDef *SWITCH);

TEST_GROUP(Switch);

TEST_SETUP(Switch)
{
    /* Init before every test */
    TEST_TIMER = 10;
}

TEST_TEAR_DOWN(Switch)
{
    /* Cleanup after every test */
}
TEST(Switch, WhenSwitchInitThenSwitchInputPinSetAsInput)
{

    init_switch(&SW_1, NULL, NULL, switch_1_GPIO_interface_get);

    TEST_ASSERT_EQUAL(PIN_TYPE_INPUT, mock_switch_Pin_type);
}
TEST(Switch, GivenSwitchIsOffWhenSwitchInitThenInputSwitchStateEqualToSwitchOFF)
{
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    init_switch(&SW_1, NULL, NULL, switch_1_GPIO_interface_get);

    TEST_ASSERT_EQUAL(SWITCH_INPUT_OFF, SW_1.input_state);
}
TEST(Switch, GivenSwitchIsOnWhenSwitchInitThenInputSwitchStateEqualToSwitchON)
{
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    init_switch(&SW_1, NULL, NULL, switch_1_GPIO_interface_get);

    TEST_ASSERT_EQUAL(SWITCH_INPUT_ON, SW_1.input_state);
}
TEST(Switch, GivenSwitchIsOffAndTestTimerEqual10AndSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimeThenTestTimerEqual11)
{
    // Given
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    init_switch(&SW_1, inc_test_timer, dec_test_timer, switch_1_GPIO_interface_get);
    check_switch(&SW_1);
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    check_switch(&SW_1);
    switch_1_pin_bouncing_on_ON(&SW_1);
    check_switch(&SW_1);
    check_switch_X_times(&SW_1, SWITCH_DEBOUNCE_REPETITIONS);
    TEST_ASSERT_EQUAL(11, TEST_TIMER);
}
TEST(Switch, GivenSwitchIsOffAndTestTimerEqual10AndSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimeMinus1ThenTestTimerEqual10)
{
    // Given
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    init_switch(&SW_1, inc_test_timer, dec_test_timer, switch_1_GPIO_interface_get);
    check_switch(&SW_1);
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    check_switch(&SW_1);
    switch_1_pin_bouncing_on_ON(&SW_1);
    check_switch(&SW_1);
    check_switch_X_times(&SW_1, SWITCH_DEBOUNCE_REPETITIONS - 1);
    TEST_ASSERT_EQUAL(10, TEST_TIMER);
}

TEST(Switch, GivenSwitchIsOffAndTestTimerEqual10AndSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimePlus1ThenTestTimerEqual11)
{
    // Given
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    init_switch(&SW_1, inc_test_timer, dec_test_timer, switch_1_GPIO_interface_get);
    check_switch(&SW_1);
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    check_switch(&SW_1);
    switch_1_pin_bouncing_on_ON(&SW_1);
    check_switch(&SW_1);
    check_switch_X_times(&SW_1, SWITCH_DEBOUNCE_REPETITIONS + 1);
    TEST_ASSERT_EQUAL(11, TEST_TIMER);
}

TEST(Switch, GivenSwitchIsONAndTestTimerEqual10AndSW1InitAndDecTimerFunctionRegisteredToSwOffAndSW1SwitchedOffAndBouncingWhenSW1StableForDebounceTimeThenTestTimerEqual9)
{
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    init_switch(&SW_1, inc_test_timer, dec_test_timer, switch_1_GPIO_interface_get);
    check_switch(&SW_1);
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    check_switch(&SW_1);
    switch_1_pin_bouncing_on_OFF(&SW_1);
    check_switch(&SW_1);
    check_switch_X_times(&SW_1, SWITCH_DEBOUNCE_REPETITIONS);
    TEST_ASSERT_EQUAL(9, TEST_TIMER);
}
TEST(Switch, GivenSwitchIsONAndTestTimerEqual10AndSW1InitAndDecTimerFunctionRegisteredToSwOffAndSW1SwitchedOffAndBouncingWhenSW1StableForDebounceTimeMinus1ThenTestTimerEqual9)
{
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    init_switch(&SW_1, inc_test_timer, dec_test_timer, switch_1_GPIO_interface_get);
    check_switch(&SW_1);
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    check_switch(&SW_1);
    switch_1_pin_bouncing_on_OFF(&SW_1);
    check_switch(&SW_1);
    check_switch_X_times(&SW_1, SWITCH_DEBOUNCE_REPETITIONS - 1);
    TEST_ASSERT_EQUAL(10, TEST_TIMER);
}

TEST(Switch, GivenSwitchIsONAndTestTimerEqual10AndSW1InitAndDecTimerFunctionRegisteredToSwOffAndSW1SwitchedOffAndBouncingWhenSW1StableForDebounceTimePlus1ThenTestTimerEqual9)
{
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    init_switch(&SW_1, inc_test_timer, dec_test_timer, switch_1_GPIO_interface_get);
    check_switch(&SW_1);
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    check_switch(&SW_1);
    switch_1_pin_bouncing_on_OFF(&SW_1);
    check_switch(&SW_1);
    check_switch_X_times(&SW_1, SWITCH_DEBOUNCE_REPETITIONS + 1);
    TEST_ASSERT_EQUAL(9, TEST_TIMER);
}

// TEST(Switch, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }
// TEST(Switch, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }
// TEST(Switch, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }
// TEST(Switch, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }
// TEST(Switch, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }
// TEST(Switch, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }
// TEST(Switch, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }
// TEST(Switch, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }
static void check_switch_X_times(SWITCH_TypDef *SWITCH, debounce_repetition_t repetition)
{

    while (repetition)
    {
        repetition--;
        check_switch(SWITCH);
    }
}

void switch_1_pin_bouncing_on_ON(SWITCH_TypDef *SWITCH)
{
    check_switch_X_times(SWITCH, 20);
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    check_switch_X_times(SWITCH, 30);
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;

    check_switch_X_times(SWITCH, 20);
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    check_switch_X_times(SWITCH, 30);
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;

    check_switch_X_times(SWITCH, 20);
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
    check_switch_X_times(SWITCH, 30);
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
}

void switch_1_pin_bouncing_on_OFF(SWITCH_TypDef *SWITCH)
{
    check_switch_X_times(SWITCH, 20);
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    check_switch_X_times(SWITCH, 30);
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;

    check_switch_X_times(SWITCH, 20);
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    check_switch_X_times(SWITCH, 30);
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;

    check_switch_X_times(SWITCH, 20);
    mock_SWITCH_1_STATE = SWITCH_INPUT_ON;
    check_switch_X_times(SWITCH, 30);
    mock_SWITCH_1_STATE = SWITCH_INPUT_OFF;
}
