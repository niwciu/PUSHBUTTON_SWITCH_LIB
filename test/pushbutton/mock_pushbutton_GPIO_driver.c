/**
 * @brief
 *
 */
#include "pushbutton_GPIO_interface.h"
#include <stddef.h>
#include "mock_pushbutton_GPIO_driver.h"

PB_input_state_t mock_PUSHBUTTON_1_STATE = UNKNOWN;
PB_input_state_t mock_PUSHBUTTON_2_STATE = UNKNOWN;

uint8_t TEST_TIMER = 0;

static void pushbutton_1_gpio_init(void);
static void pushbutton_2_gpio_init(void);
static PB_input_state_t get_pushbutton_1_state(void);
static PB_input_state_t get_pushbutton_2_state(void);

PB_driver_interface_t PUSHBUTTON_1_GPIO_interface_struct = {
    pushbutton_1_gpio_init,
    get_pushbutton_1_state,
};

PB_driver_interface_t PUSHBUTTON_2_GPIO_interface_struct = {
    pushbutton_2_gpio_init,
    get_pushbutton_2_state,
};

const PB_driver_interface_t *pushbutton_1_GPIO_interface_get(void)
{
    return &PUSHBUTTON_1_GPIO_interface_struct;
}
const PB_driver_interface_t *pushbutton_2_GPIO_interface_get(void)
{
    return &PUSHBUTTON_2_GPIO_interface_struct;
}

static void pushbutton_1_gpio_init(void)
{
    mock_PUSHBUTTON_1_STATE = RELEASED;
}

static void pushbutton_2_gpio_init(void)
{
    mock_PUSHBUTTON_2_STATE = RELEASED;
}

static PB_input_state_t get_pushbutton_1_state(void)
{
    return mock_PUSHBUTTON_1_STATE;
}

static PB_input_state_t get_pushbutton_2_state(void)
{
    return mock_PUSHBUTTON_2_STATE;
}

void inc_test_timer(void)
{
    TEST_TIMER++;
}
void dec_test_timer(void)
{
    TEST_TIMER--;
}