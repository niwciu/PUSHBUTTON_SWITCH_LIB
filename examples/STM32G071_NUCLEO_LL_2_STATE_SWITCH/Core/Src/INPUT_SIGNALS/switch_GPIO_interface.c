#include "switch_GPIO_interface.h"
#include "main.h"

static void input_1_gpio_init(void);
static SWITCH_input_state_t get_input_1_state(void);



SWITCH_driver_interface_t SWITCH_1_GPIO_interface_struct = {
    input_1_gpio_init,
    get_input_1_state,
};

const SWITCH_driver_interface_t *switch_1_GPIO_interface_get(void)
{
    return &SWITCH_1_GPIO_interface_struct;
}


static void input_1_gpio_init(void)
{
    
}

static SWITCH_input_state_t get_input_1_state(void)
{
    SWITCH_input_state_t test=SWITCH_INPUT_UNKNOWN;
    if (LL_GPIO_IsInputPinSet(user_button_GPIO_Port,user_button_Pin))
    {
        test= SWITCH_INPUT_OFF;
    } 
    else 
    {
        test=SWITCH_INPUT_ON;
    }
    return test;
}