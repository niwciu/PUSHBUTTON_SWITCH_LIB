#include "unity/fixture/unity_fixture.h"
#include "pushbutton.h"
#include "mock_pushbutton_GPIO_driver.h"
#include "pushbutton_common_test.h"

typedef enum
{
    OK = 0,
    DEB_REP_TIM_ERROR = 0x1U,
    STATE_MACHINE_ERROR = 0x2U,
    INPUT_STATE_ERROR = 0x4u,
    REPETITION_STATUS_FLAG_ERROR = 0x8U,
    PUSH_CALLBACK_ERROR = 0x10U,
    RELEASE_CALLBACK_ERROR = 0x20U,

} PB_init_status_t;

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
    PB_init_status_t PB_init_status = OK;

    if ((PUSHBUTTON_1.deb_rep_timer) != 0)
        PB_init_status |= DEB_REP_TIM_ERROR;
    if ((PUSHBUTTON_1.pushbutton_state_machine) != BUTTON_RELEASED)
        PB_init_status |= STATE_MACHINE_ERROR;
    if ((PUSHBUTTON_1.input_state) != UNKNOWN)
        PB_init_status |= INPUT_STATE_ERROR;
    if ((PUSHBUTTON_1.REPETITION_STATUS_FLAG) != REPETITION_INACTIVE)
        PB_init_status |= REPETITION_STATUS_FLAG_ERROR;
    if ((PUSHBUTTON_1.push_callback) != NULL)
        PB_init_status |= PUSH_CALLBACK_ERROR;
    if ((PUSHBUTTON_1.release_callback) != NULL)
        PB_init_status |= RELEASE_CALLBACK_ERROR;
    TEST_ASSERT_EQUAL(OK, PB_init_status);
}

    // PUSHBUTTON_1.GPIO_interface = PB_get_driver_interface_adr_callback();

    // PUSHBUTTON_1.GPIO_interface->GPIO_init();
    // PUSHBUTTON_1.repetition = PB_repetition_mode;
    // PUSHBUTTON_1.trigger_mode = PB_triger_mode;

    // init other parameters of the structure to default init value
    
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
