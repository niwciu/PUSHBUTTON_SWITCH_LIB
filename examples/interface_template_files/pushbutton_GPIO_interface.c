#include "pushbutton_GPIO_interface.h"


static void key_1_gpio_init(void);
static PB_input_state_t get_key_1_state(void);
/*************** For more pusbuttons *************/
// static void key_2_gpio_init(void);
// static PB_input_state_t get_key_2_state(void);
/************************************************/

PB_driver_interface_t KEY_1_GPIO_interface_struct = {
    key_1_gpio_init,
    get_key_1_state,
};
/*************** For more pusbuttons *************/
// PB_driver_interface_t KEY_2_GPIO_interface_struct = {
//     key_2_gpio_init,
//     get_key_2_state,
// };
/************************************************/

static void key_1_gpio_init(void)
{
    //init key_1 gpio
}

static PB_input_state_t get_key_1_state(void)
{
    PB_input_state_t PB_state=UNKNOWN;
    //check state and retunr proper state according to project assumptions
    return PB_state;
}
/*************** For more pusbuttons *************/
// static void key_2_gpio_init(void)
// {
//     //init key_2 gpio
// }

// static PB_input_state_t get_key_2_state(void)
// {
//     PB_input_state_t test=UNKNOWN;
//     //check state and retunr proper state according to project assumptions
//     return test;
// }
/************************************************/

PB_driver_interface_t *pushbutton_1_GPIO_interface_get(void)
{
    return &KEY_1_GPIO_interface_struct;
}
/*************** For more pusbuttons *************/
// PB_driver_interface_t *pushbutton_2_GPIO_interface_get(void)
// {
//     return &KEY_2_GPIO_interface_struct;
// }
/************************************************/
