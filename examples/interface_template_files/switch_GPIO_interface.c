#include "switch_GPIO_interface.h"


static void input_1_gpio_init(void);
static SWITCH_input_state_t get_input_1_state(void);
/*************** For more switch signals *************/
// static void input_2_gpio_init(void);
// static SWITCH_input_state_t get_input_2_state(void);
/*****************************************************/


SWITCH_driver_interface_t SWITCH_1_GPIO_interface_struct = {
    input_1_gpio_init,
    get_input_1_state,
};
/*************** For more switch signals *************/
// SWITCH_driver_interface_t SWITCH_2_GPIO_interface_struct = {
//     input_2_gpio_init,
//     get_input_2_state,
// };
/*****************************************************/

static void input_1_gpio_init(void)
{   
}

static SWITCH_input_state_t get_input_1_state(void)
{
    SWITCH_input_state_t test=SWITCH_INPUT_UNKNOWN;
    //check state and retunr proper state according to project assumptions
    return test;
}

/*************** For more switch signals *************/
// static void input_2_gpio_init(void)
// { 
// }

// static SWITCH_input_state_t get_input_2_state(void)
// {
//     SWITCH_input_state_t test=SWITCH_INPUT_UNKNOWN;
//     //check state and retunr proper state according to project assumptions
//     return test;
// }
/*****************************************************/


const SWITCH_driver_interface_t *switch_1_GPIO_interface_get(void)
{
    return &SWITCH_1_GPIO_interface_struct;
}

/*************** For more switch signals *************/
// const SWITCH_driver_interface_t *switch_2_GPIO_interface_get(void)
// {
//     return &SWITCH_2_GPIO_interface_struct;
// }
/*****************************************************/
