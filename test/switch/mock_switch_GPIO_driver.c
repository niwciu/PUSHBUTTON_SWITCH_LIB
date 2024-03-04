/**
 * @brief
 *
 */
#include "switch_GPIO_interface.h"
#include <stddef.h>
#include "mock_switch_GPIO_driver.h"

SWITCH_input_state_t mock_SWITCH_1_STATE = UNKNOWN;

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
SWITCH_driver_interface_t *switch_2_GPIO_interface_get(void)
{
    return &SWITCH_2_GPIO_interface_struct;
}

static void switch_1_gpio_init(void)
{
    mock_SWITCH_1_STATE = RELEASED;
}


static PB_input_state_t get_switch_1_state(void)
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