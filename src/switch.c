/**
 * @file switch.c
 * @author niwciu (niwciu@gmail.com)
 * @brief
 * @version 0.0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "switch.h"
#include <stddef.h>
// #include <stdio.h>
#include <stdbool.h>



    /**
     * @brief
     * @param SWITCH
     * @param SWITCH_get_driver_interface_adr_callback
     */
    void
    init_switch(SWITCH_TypDef *SWITCH, SWITCH_GPIO_interface_get_callback SWITCH_get_driver_interface_adr_callback)
{
    SWITCH->GPIO_interface = SWITCH_get_driver_interface_adr_callback();
    SWITCH->GPIO_interface->GPIO_init();

    // init other parameters of the structure to default init value
    SWITCH->input_state = SWITCH_INPUT_UNKNOWN;
    SWITCH->debounce_counter = 0;
    SWITCH->switch_OFF_callback = NULL;
    SWITCH->switch_ON_callback = NULL;
    SWITCH->switch_state_machine = SW_OFF;

    //ToDo testy na inicjalizacj switcha gdy fizycznie jest w jakims stanie
}

void check_switch(SWITCH_TypDef *SWITCH)
{
    SWITCH->input_state = SWITCH->GPIO_interface->get_switch_input_state();

    switch (SWITCH->switch_state_machine)
    {
    case SW_OFF:
        if((SWITCH->input_state)==SWITCH_INPUT_ON)
        {
            SWITCH->debounce_counter=SWITCH_DEBOUNCE_REPETITIONS;
            SWITCH->switch_state_machine=SW_SWITCHED_ON;
        }
        break;
    case SW_SWITCHED_ON:
        if((SWITCH->input_state)==SWITCH_INPUT_ON)
        {
            SWITCH->debounce_counter--;
            if((SWITCH->debounce_counter)==0)
            {
                SWITCH->switch_state_machine=SW_ON;
                if((SWITCH->switch_ON_callback)!=NULL)
                {
                    SWITCH->switch_ON_callback();
                }
            }
        }
        else
        {
            SWITCH->switch_state_machine=SW_OFF;
        }
        
        break;
    case SW_ON:
        break;
    case SW_SWITCHED_OFF:
        break;
    default:
    // printf("\r\ndefault\r\n");
        if((SWITCH->input_state)==SWITCH_INPUT_ON) SWITCH->switch_state_machine=SW_ON;
        else SWITCH->switch_state_machine=SW_OFF;
        break;
    }
}

/**
 * @brief
 * @param SWITCH
 * @param switch_ON_callback
 */
void register_switch_ON_callback(SWITCH_TypDef *SWITCH, SWITCH_callback_t switch_ON_callback)
{
    SWITCH->switch_ON_callback = switch_ON_callback;
}

