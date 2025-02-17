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

#include "keypad.h"
#include "keypad_TIM_interface.h"
#include "pushbutton.h"
#include "LED_GPIO_driver.h"

/** @brief Structure representing PUSHBUTTON_1 pushbutton. */
PUSHBUTTON_TypDef PUSHBUTTON_1;

/** @brief Pointer to the PUSHBUTTON_1 pushbutton structure. */
PUSHBUTTON_TypDef *ENT_ESC = &PUSHBUTTON_1;

static void update_button_timers(void);

/**
 * @brief Initializes the keyboard pushbutton components.
 * @details This function initializes the necessary pushbuttons, sets their configurations,
 * and registers corresponding callback functions. It also subscribes to the SysTick timer
 * for periodic updates of pushbuttonbutton timers.
 */
void init_keypad(void)
{
    // Key ENT_ESC Initialization
    init_pushbutton(ENT_ESC, REPETITION_ON, TRIGGER_ON_SHORT_PUSH_AND_LONG_PUSH, pushbutton_1_GPIO_interface_get);
    register_button_short_push_long_push_callbacks(ENT_ESC, LED_on, LED_toggle);

    // KEY_2 Initialization
    // ...
    // KEY_3 Initialization
    // ...

    subscribe_keypad_timers_update_callback(update_button_timers);
}

/**
 * @brief Checks the state of pushbuttons in the keyboard.
 * @details This function checks the state of the pushbuttons in the keyboard,
 * processes any events, and updates the button timers.
 */
void check_keypad(void)
{
    check_pushbutton(ENT_ESC);
    //check_pushbutton(&KEY_2);
    //check_pushbutton(&KEY_3);
}

/**
 * @brief Updates the timers for pushbuttons in the keyboard.
 * @details This function is called periodically by the SysTick timer to update
 * the debounce and repetition timers for the pushbuttons in the keyboard.
 */
static void update_button_timers(void)
{
    dec_pushbutton_deb_rep_timer(ENT_ESC);
    // dec_pushbutton_deb_rep_timer(&KEY_2);
    // dec_pushbutton_deb_rep_timer(&KEY_3);
}

