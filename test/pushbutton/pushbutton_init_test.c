#include "unity/fixture/unity_fixture.h"
#include "pushbutton.h"
#include "mock_pushbutton_GPIO_driver.h"
#include "pushbutton_common_test.h"

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_1. */
static PUSHBUTTON_TypDef PUSHBUTTON_1;

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_2. */
static PUSHBUTTON_TypDef PUSHBUTTON_2;

TEST_GROUP(pushbutton_init);

TEST_SETUP(pushbutton_init)
{
    /* Init before every test */
    init_pushbutton(&PUSHBUTTON_1, REPETITION_OFF, TRIGGER_ON_PUSH, pb_1_GPIO_interface_get);
    init_pushbutton(&PUSHBUTTON_2, REPETITION_OFF, TRIGGER_ON_PUSH, pb_2_GPIO_interface_get);
    TEST_TIMER = 0;
}

TEST_TEAR_DOWN(pushbutton_init)
{
    /* Cleanup after every test */
}

TEST(pushbutton_init, WhenKey1InitThenKey1PinStateIsReleased)
{

    TEST_ASSERT_EQUAL(RELEASED, mock_PUSHBUTTON_1_STATE);
}

TEST(pushbutton_init, WhenKey2InitThenKey2PinStateIsReleased)
{

    TEST_ASSERT_EQUAL(RELEASED, mock_PUSHBUTTON_2_STATE);
}

TEST(pushbutton_init, GivenSystemResetWhenKey1InitThendefaultValuesOfStructureAreCorrect)
{
    TEST_FAIL_MESSAGE("Implement your test!");
}

// TEST(pushbutton_init, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }

// TEST(pushbutton_init, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }

// TEST(pushbutton_init, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }

// TEST(pushbutton_init, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }

// TEST(pushbutton_init, )
// {
//     TEST_FAIL_MESSAGE("Implement your test!");
// }
