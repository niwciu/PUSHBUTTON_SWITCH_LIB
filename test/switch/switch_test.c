#include "unity/fixture/unity_fixture.h"
#include "mock_switch_GPIO_driver.h"
#include "switch_GPIO_interface.h"
// #include "switch_GPIO_interface.h"

// #include "tested_module.h"

TEST_GROUP(Switch);

TEST_SETUP(Switch)
{
    /* Init before every test */
}

TEST_TEAR_DOWN(Switch)
{
    /* Cleanup after every test */
}

TEST(Switch, WhenSwitchInitThenInputSwitchStateEqualToSwitchOFF)
{
    TEST_ASSERT_EQUAL(SWITCH_OFF,mock_SWITCH_1_STATE);
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
// TEST(Switch, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }