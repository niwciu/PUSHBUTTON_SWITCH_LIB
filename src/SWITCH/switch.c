/**
 * @file switch.c
 * @brief Switch ( Two state input signal) control module implementation.
 * @author niwciu (niwciu@gmail.com)
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 */
#include "switch.h"
#include <stddef.h>
// #include <stdbool.h>

static void handle_DEFAULT_state(SWITCH_TypDef *SWITCH);
static void handle_SW_SWITCHED_OFF_state(SWITCH_TypDef *SWITCH);
static void handle_SW_ON_state(SWITCH_TypDef *SWITCH);
static void handle_SW_SWITCHED_ON_state(SWITCH_TypDef *SWITCH);
static void handle_SW_OFF_state(SWITCH_TypDef *SWITCH);

static void handle_DEFAULT_state(SWITCH_TypDef *SWITCH)
{
    if ((SWITCH->input_state) == SWITCH_INPUT_ON)
        SWITCH->switch_state_machine = SW_ON;
    else
        SWITCH->switch_state_machine = SW_OFF;
}

static void handle_SW_SWITCHED_OFF_state(SWITCH_TypDef *SWITCH)
{
    if ((SWITCH->input_state) == SWITCH_INPUT_OFF)
    {
        SWITCH->debounce_counter--;
        if ((SWITCH->debounce_counter) == 0)
        {
            SWITCH->switch_state_machine = SW_OFF;
            if ((SWITCH->switch_OFF_callback) != NULL)
            {
                SWITCH->switch_OFF_callback();
            }
        }
    }
    else
    {
        SWITCH->switch_state_machine = SW_ON;
    }
}

static void handle_SW_ON_state(SWITCH_TypDef *SWITCH)
{
    if ((SWITCH->input_state) == SWITCH_INPUT_OFF)
    {
        SWITCH->debounce_counter = SWITCH_DEBOUNCE_REPETITIONS;
        SWITCH->switch_state_machine = SW_SWITCHED_OFF;
    }
}

static void handle_SW_SWITCHED_ON_state(SWITCH_TypDef *SWITCH)
{
    if ((SWITCH->input_state) == SWITCH_INPUT_ON)
    {
        SWITCH->debounce_counter--;
        if ((SWITCH->debounce_counter) == 0)
        {
            SWITCH->switch_state_machine = SW_ON;
            if ((SWITCH->switch_ON_callback) != NULL)
            {
                SWITCH->switch_ON_callback();
            }
        }
    }
    else
    {
        SWITCH->switch_state_machine = SW_OFF;
    }
}

static void handle_SW_OFF_state(SWITCH_TypDef *SWITCH)
{
    if ((SWITCH->input_state) == SWITCH_INPUT_ON)
    {
        SWITCH->debounce_counter = SWITCH_DEBOUNCE_REPETITIONS;
        SWITCH->switch_state_machine = SW_SWITCHED_ON;
    }
}

/**
 * @brief Initializes the switch control module.
 * @param SWITCH Pointer to the SWITCH_TypDef structure.
 * @param switch_ON_callback Callback function for switch ON event.
 * @param switch_OFF_callback Callback function for switch OFF event.
 * @param SWITCH_get_driver_interface_adr_callback Callback to get the GPIO driver interface address.
 *
 * This function initializes the switch control module, configuring the GPIO
 * interface and setting up callback functions for switch events.
 */
void init_switch(SWITCH_TypDef *SWITCH,
                 const SWITCH_callback_t switch_ON_callback,
                 const SWITCH_callback_t switch_OFF_callback,
                 const SWITCH_GPIO_interface_get_callback SWITCH_get_driver_interface_adr_callback)
{
    SWITCH->GPIO_interface = SWITCH_get_driver_interface_adr_callback();
    SWITCH->GPIO_interface->GPIO_init();

    // init other parameters of the structure to default init value
    SWITCH->input_state = SWITCH->GPIO_interface->get_switch_input_state();
    SWITCH->debounce_counter = 0;
    SWITCH->switch_OFF_callback = switch_OFF_callback;
    SWITCH->switch_ON_callback = switch_ON_callback;
    SWITCH->switch_state_machine = SW_INIT;
}

/**
 * @brief Checks the current state of the switch and performs corresponding actions.
 * @param SWITCH Pointer to the SWITCH_TypDef structure.
 *
 * This function checks the current state of the switch state machine and invokes
 * the appropriate state-handling function.
 */
void check_switch(SWITCH_TypDef *SWITCH)
{
    SWITCH->input_state = SWITCH->GPIO_interface->get_switch_input_state();
    switch (SWITCH->switch_state_machine)
    {
    case SW_OFF:
        handle_SW_OFF_state(SWITCH);
        break;
    case SW_SWITCHED_ON:
        handle_SW_SWITCHED_ON_state(SWITCH);
        break;
    case SW_ON:
        handle_SW_ON_state(SWITCH);
        break;
    case SW_SWITCHED_OFF:
        handle_SW_SWITCHED_OFF_state(SWITCH);
        break;
    default:
        handle_DEFAULT_state(SWITCH);
        break;
    }
}
