/**
 * @brief
 *
 */

#include <stddef.h>
#include "mock_switch_GPIO_driver.h"

SWITCH_input_state_t mock_SWITCH_1_STATE = SWITCH_INPUT_UNKNOWN;
pin_type_t mock_switch_Pin_type = PIN_TYPE_UNKNOWN;

uint8_t TEST_TIMER = 0;

static void switch_1_gpio_init(void);

static SWITCH_input_state_t get_switch_1_state(void);

SWITCH_driver_interface_t SWITCH_1_GPIO_interface_struct = {
    switch_1_gpio_init,
    get_switch_1_state,
};

SWITCH_driver_interface_t *switch_1_GPIO_interface_get(void)
{
    return &SWITCH_1_GPIO_interface_struct;
}

static void switch_1_gpio_init(void)
{
    mock_switch_Pin_type = PIN_TYPE_INPUT;
}

static SWITCH_input_state_t get_switch_1_state(void)
{
    return mock_SWITCH_1_STATE;
}

void inc_test_timer(void)
{
    TEST_TIMER++;
}
void dec_test_timer(void)
{
    TEST_TIMER--;
}