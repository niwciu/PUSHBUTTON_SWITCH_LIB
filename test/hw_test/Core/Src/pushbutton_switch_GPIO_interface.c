#include "pushbutton_switch_interface.h"
#include "main.h"

static void key_1_gpio_init(void);
static PB_input_state_t get_key_1_state(void);



PB_driver_interface_t KEY_1_GPIO_interface_struct = {
    key_1_gpio_init,
    get_key_1_state,
};

PB_driver_interface_t *key_1_GPIO_interface_get(void)
{
    return &KEY_1_GPIO_interface_struct;
}


static void key_1_gpio_init(void)
{
    
}

static PB_input_state_t get_key_1_state(void)
{
    PB_input_state_t test=UNKNOWN;
    if (LL_GPIO_IsInputPinSet(user_button_GPIO_Port,user_button_Pin)) test= RELEASED;
    else test=PUSHED;
    return test;
}