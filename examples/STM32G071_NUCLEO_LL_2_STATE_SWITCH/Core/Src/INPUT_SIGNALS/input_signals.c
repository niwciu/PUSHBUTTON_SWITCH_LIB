/**
 * @file keyboard.c
 * @brief Implementation of keyboard functionality including pushbuttons and LEDs.
 * @details This file contains the implementation of functions related to the keyboard,
 * including initialization, checking pushbutton states, and updating button timers.
 * @version 0.0.1
 * @date 2024-03-06
 * 
 * @author niwciu
 * @email niwciu@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */

#include "input_signals.h"
#include "switch.h"
#include "LED_GPIO_driver.h"

/** @brief Structure representing INPUT_1 pushbutton. */
SWITCH_TypDef INPUT_1;

/** @brief Pointer to the INPUT_1 pushbutton structure. */
SWITCH_TypDef *Hmin = &INPUT_1;

/**
 * @brief Initializes the keyboard pushbutton components.
 * @details This function initializes the necessary pushbuttons, sets their configurations,
 * and registers corresponding callback functions. It also subscribes to the SysTick timer
 * for periodic updates of pushbuttonbutton timers.
 */
void init_input_signals(void)
{
    // Hmin two state input signal (switch) initialization
    init_switch(Hmin,LED_on,LED_off,switch_1_GPIO_interface_get);
    // INPUT_2 Initialization
    // INPUT_3 Initialization
}

/**
 * @brief Checks the state of pushbuttons in the keyboard.
 * @details This function checks the state of the pushbuttons in the keyboard,
 * processes any events, and updates the button timers.
 */
void check_input_signals(void)
{
    check_switch(Hmin);
    //check_switch(&INPUT_2);
    //check_switch(&INPUT_3);
}
