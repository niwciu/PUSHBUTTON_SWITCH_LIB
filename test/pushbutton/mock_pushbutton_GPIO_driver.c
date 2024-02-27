/**
 * @brief 
 * 
 */
#include "pushbutton_switch_interface.h"
#include <stddef.h>
#include "mock_pushbutton_GPIO_driver.h"

button_state_t PUSHBUTTON_1_STATE=UNKNOWN;
button_state_t PUSHBUTTON_2_STATE=UNKNOWN;

uint8_t TEST_TIMER=0;

static void pushbutton_1_gpio_init(void);
static void pushbutton_2_gpio_init(void);
static button_state_t get_pushbutton_1_state(void);
static button_state_t get_pushbutton_2_state(void);


pushbutton_driver_interface_t PUSHBUTTON_1_GPIO_interface_struct={
    pushbutton_1_gpio_init,
    get_pushbutton_1_state,
};

pushbutton_driver_interface_t PUSHBUTTON_2_GPIO_interface_struct={
    pushbutton_2_gpio_init,
    get_pushbutton_2_state,
};


const pushbutton_driver_interface_t* pushbutton_1_GPIO_interface_get(void)
{
    return &PUSHBUTTON_1_GPIO_interface_struct;
}
const pushbutton_driver_interface_t* pushbutton_2_GPIO_interface_get(void){
    return &PUSHBUTTON_2_GPIO_interface_struct;
}

static void pushbutton_1_gpio_init(void)
{
    PUSHBUTTON_1_STATE=UP;
}

static void pushbutton_2_gpio_init(void)
{
    PUSHBUTTON_2_STATE=UP;
}

static button_state_t get_pushbutton_1_state(void)
{
    return PUSHBUTTON_1_STATE;
}

static button_state_t get_pushbutton_2_state(void)
{
    return PUSHBUTTON_2_STATE;
}

void inc_test_timer(void)
{
    TEST_TIMER++;
}