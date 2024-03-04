#include "unity/fixture/unity_fixture.h"
#include "mock_switch_GPIO_driver.h"
#include "switch.h"


typedef uint16_t debounce_repetition_t;

SWITCH_TypDef SW_1;


static void check_switch_X_times(SWITCH_TypDef *SWITCH, debounce_repetition_t repetition);

TEST_GROUP(Switch);

TEST_SETUP(Switch)
{
    init_switch(&SW_1,switch_1_GPIO_interface_get);
    /* Init before every test */
}

TEST_TEAR_DOWN(Switch)
{
    /* Cleanup after every test */
}

TEST(Switch, WhenSwitchInitThenInputSwitchStateEqualToSwitchOFF)
{
    
    TEST_ASSERT_EQUAL(SWITCH_INPUT_OFF,mock_SWITCH_1_STATE);
}
TEST(Switch, GivenSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimeThenTestTimerEqual1)
{
    //Given
    register_switch_ON_callback(&SW_1,inc_test_timer);
    mock_SWITCH_1_STATE=SWITCH_INPUT_ON;
    check_switch(&SW_1);
    check_switch_X_times(&SW_1,SWITCH_DEBOUNCE_REPETITIONS);
    check_switch(&SW_1);
    TEST_ASSERT_EQUAL(1,TEST_TIMER);
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
    while(repetition)
    {
        repetition--;
        check_switch(SWITCH);
    }
}