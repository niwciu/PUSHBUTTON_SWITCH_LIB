/**
 * @file key_switch.c
 * @author niwciu (niwciu@gmail.com)
 * @brief
 * @version 0.0.1
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "pushbutton_switch.h"
#include <stddef.h>
#include <stdio.h>

typedef uint8_t input_state_t;
typedef uint16_t debounce_repetition_timer_t;
/**
 * @brief Structure representing a pushbutton.
 *
 * This structure holds information related to a pushbutton, including its GPIO interface,
 * debounce and repetition timer, repetition flag, and callback functions.
 */
typedef struct
{
    pushbutton_driver_interface_t *GPIO_interface; /**< GPIO interface for the pushbutton. */
    debounce_repetition_timer_t deb_rep_timer;     /**< Debounce and repetition timer. */
    uint8_t REPETITION_FLAG;                       /**< Repetition flag indicating the current state. */
    pushbutton_callback_t push_or_release_callback;           /**< Callback function on push action. */
    pushbutton_callback_t up_callback;             /**< Callback function on release action. */
    //
} pushbutton_t;

/** @brief Instance of pushbutton_t representing PUSHBUTTON_1. */
pushbutton_t PUSHBUTTON_1;

/** @brief Instance of pushbutton_t representing PUSHBUTTON_2. */
pushbutton_t PUSHBUTTON_2;

static pushbutton_t *get_pushbutton_struct_adres(pushbutton_name_t button_name);
static void update_button_repetition_counter(pushbutton_t *BUTTON, pushbutton_repetition_t repetition);
static void debounce_pushbutton_state(pushbutton_t *BUTTON, pushbutton_repetition_t repetition);

static pushbutton_t *get_pushbutton_struct_adres(pushbutton_name_t button_name)
{
    pushbutton_t *BUTTON = NULL;
    switch (button_name)
    {
    case BUTTON_1:
        BUTTON = &PUSHBUTTON_1;
        break;
    case BUTTON_2:
        BUTTON = &PUSHBUTTON_2;
        break;
    default:
        // Handle the case when the switch value is not a defined button.
        // Returning NULL as there's no valid button struct to associate with the given name.
        break;
    }
    return BUTTON;
}

static void update_button_repetition_counter(pushbutton_t *BUTTON, pushbutton_repetition_t repetition)
{

    if (repetition == REPETITION_ON)
    {
        if ((BUTTON->REPETITION_FLAG) == 0)
        {
            BUTTON->deb_rep_timer = PUSHBUTTON_FIRST_REPETITION_TIME;
            BUTTON->REPETITION_FLAG = 1;
        }
        else
        {
            BUTTON->deb_rep_timer = PUSHBUTTON_CONTINUES_REPETITION_TIME;
        }
    }
    else
    {
        BUTTON->deb_rep_timer = 0;
    }
}

static void debounce_pushbutton_state(pushbutton_t *BUTTON, pushbutton_repetition_t repetition)
{
    button_state_t pushbutton_input_state = BUTTON->GPIO_interface->get_button_state();
    if (pushbutton_input_state == PUSHED)
    {
        if ((BUTTON->deb_rep_timer) == 1)
        {
            if (BUTTON->push_or_release_callback != NULL)
            {
                BUTTON->push_or_release_callback();
            }
            update_button_repetition_counter(BUTTON, repetition);
        }
        else
        {
            // Empty else statement for case when deb_rep_timer is different then 1
        }
    }
    else
    {
        BUTTON->deb_rep_timer = PUSHBUTTON_DEBOUNCE_TIME;
        BUTTON->REPETITION_FLAG = 0;
    }
}

/**
 * @brief Initializes pushbuttons.
 *
 * This function initializes pushbuttons by obtaining GPIO interfaces,
 * calling their initialization functions, and setting up the necessary configurations.
 */
void init_pushbuttons(void)
{
    PUSHBUTTON_1.GPIO_interface = pushbutton_1_GPIO_interface_get();
    PUSHBUTTON_2.GPIO_interface = pushbutton_2_GPIO_interface_get();
    PUSHBUTTON_1.GPIO_interface->GPIO_init();
    PUSHBUTTON_2.GPIO_interface->GPIO_init();
}

/**
 * @brief Checks the state of a specific pushbutton and performs debounce if needed.
 *
 * This function checks the state of the specified pushbutton, identified by `button_name`,
 * and performs debounce if the pushbutton is valid.
 *
 * @param button_name The name of the pushbutton to check. 
 * @param repetition The type of repetition for the pushbutton.
 */
void check_button_push(pushbutton_name_t button_name,pushbutton_repetition_t repetition)
{
    pushbutton_t *BUTTON = get_pushbutton_struct_adres(button_name);

    if (BUTTON != NULL)
    {
        debounce_pushbutton_state(BUTTON, repetition);
    }
}

/**
 * @brief Registers a callback function to be called on pushbutton press or release.
 *
 * This function associates a callback function with the specified pushbutton,
 * to be executed when the pushbutton is either pressed or released.
 *
 * @param button_name The name of the pushbutton to register the callback for.
 * @param callback_on_push The callback function to be executed on push or release.
 */
void register_button_push_or_release_callback(pushbutton_name_t button_name, pushbutton_callback_t callback_on_push)
{
    pushbutton_t *BUTTON = get_pushbutton_struct_adres(button_name);
    if (BUTTON != NULL)
    {
        BUTTON->push_or_release_callback = callback_on_push;
    }
}

/**
 * @brief Decrements the debounce and repetition timer of a pushbutton.
 *
 * This function decrements the debounce and repetition timer of the specified pushbutton
 * if the pushbutton is valid and the timer is non-zero.
 *
 * @param button_name The name of the pushbutton to decrement the timer for.
 */
void dec_pushbutton_deb_rep_timer(pushbutton_name_t button_name)
{
    pushbutton_t *BUTTON = get_pushbutton_struct_adres(button_name);
    if (BUTTON != NULL)
    {
        if (BUTTON->deb_rep_timer)
        {
            BUTTON->deb_rep_timer--;
        }
    }
}
