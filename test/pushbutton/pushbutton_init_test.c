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
    DRIVER_STRUCT_ADR_ERROR = 0x40U,
    REPETIOTION_MODE_ERROR = 0x80u,
    TRIGER_MODE_ERROR = 0x100U,

} PB_init_status_t;

typedef struct
{
    const PB_repetition_t PB_repetition_mode;
    const PB_trigger_mode_t PB_triger_mode;
    const PB_GPIO_interface_get_callback PB_get_driver_interface_adr_callback;
    PB_init_status_t *PB_init_status;
} expected_PB_config_value_t;

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_1. */
static PUSHBUTTON_TypDef PUSHBUTTON_1;

/** @brief Instance of PUSHBUTTON_TypDef representing PUSHBUTTON_2. */
static PUSHBUTTON_TypDef PUSHBUTTON_2;

static void check_PB_struct_default_init_value(const PUSHBUTTON_TypDef *BUTTON, PB_init_status_t *PB_init_status);
static void check_expected_configurable_PB_struct_values(const PUSHBUTTON_TypDef *BUTTON, expected_PB_config_value_t *expected_val);

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
    check_PB_struct_default_init_value(&PUSHBUTTON_1, &PB_init_status);
    TEST_ASSERT_EQUAL(OK, PB_init_status);
}

// PUSHBUTTON_1.GPIO_interface = PB_get_driver_interface_adr_callback();

// init other parameters of the structure to default init value

TEST(pushbutton_init, GivenSystemResetWhenPushbutton1InitWithRepetitionOnAndTrigerOnShortPushLongPushThenPushbuttonStructIsCorrect)
{
    PB_init_status_t PB_init_status = OK;
    // When
    init_pushbutton(&PUSHBUTTON_1, REPETITION_ON, TRIGGER_ON_SHORT_PUSH_AND_LONG_PUSH, pb_1_GPIO_interface_get);
    // Then
    expected_PB_config_value_t PB_expected_config = {
    REPETITION_ON,
    TRIGGER_ON_SHORT_PUSH_AND_LONG_PUSH,
    pb_1_GPIO_interface_get,
    &PB_init_status};
    check_expected_configurable_PB_struct_values(&PUSHBUTTON_1, &PB_expected_config);
    check_PB_struct_default_init_value(&PUSHBUTTON_1, &PB_init_status);

    TEST_ASSERT_EQUAL(OK, PB_init_status);
}

static void check_PB_struct_default_init_value(const PUSHBUTTON_TypDef *BUTTON, PB_init_status_t *PB_init_status)
{
    if ((BUTTON->deb_rep_timer) != 0)
        *PB_init_status |= DEB_REP_TIM_ERROR;
    if ((BUTTON->pushbutton_state_machine) != BUTTON_RELEASED)
        *PB_init_status |= STATE_MACHINE_ERROR;
    if ((BUTTON->input_state) != UNKNOWN)
        *PB_init_status |= INPUT_STATE_ERROR;
    if ((BUTTON->REPETITION_STATUS_FLAG) != REPETITION_INACTIVE)
        *PB_init_status |= REPETITION_STATUS_FLAG_ERROR;
    if ((BUTTON->push_callback) != NULL)
        *PB_init_status |= PUSH_CALLBACK_ERROR;
    if ((BUTTON->release_callback) != NULL)
        *PB_init_status |= RELEASE_CALLBACK_ERROR;
}
static void check_expected_configurable_PB_struct_values(const PUSHBUTTON_TypDef *BUTTON, expected_PB_config_value_t *expected_val)
{
    if ((BUTTON->GPIO_interface) != expected_val->PB_get_driver_interface_adr_callback())
        *(expected_val->PB_init_status) |= DRIVER_STRUCT_ADR_ERROR;
    if ((BUTTON->repetition) != expected_val->PB_repetition_mode)
        *(expected_val->PB_init_status) |= REPETIOTION_MODE_ERROR;
    if ((BUTTON->trigger_mode) != expected_val->PB_triger_mode)
        *(expected_val->PB_init_status) |= TRIGER_MODE_ERROR;
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
