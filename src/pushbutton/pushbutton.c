/**
 * @file pushbutton.c
 * @author niwciu (niwciu@gmail.com)
 * @brief This file contains the implementation of a pushbutton switch interface with debouncing and repetition
 * functionality.
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "pushbutton.h"
#include <stddef.h>
// #include <stdio.h>  // to tylko do printfa

static void update_pushbutton_input_state(PUSHBUTTON_TypDef *BUTTON);
static void update_button_deb_rep_counter(PUSHBUTTON_TypDef *BUTTON);
static void debounce_pushbutton_push_state(PUSHBUTTON_TypDef *BUTTON);
static void debounce_pushbutton_release_state(PUSHBUTTON_TypDef *BUTTON);
static void debounce_pushbutton_short_push_long_push_state(PUSHBUTTON_TypDef *BUTTON);

static void handle_push_debouncing(PUSHBUTTON_TypDef *BUTTON);
static void handle_long_push_no_repetition_phase(PUSHBUTTON_TypDef *BUTTON);
static void handle_long_push_phase(PUSHBUTTON_TypDef *BUTTON);
static void handle_short_push_phase(PUSHBUTTON_TypDef *BUTTON);
static void handle_short_push_phase_pin_pushed(PUSHBUTTON_TypDef *BUTTON);
static void handle_short_push_phase_pin_released(PUSHBUTTON_TypDef *BUTTON);

static void execute_push_callback(PUSHBUTTON_TypDef *BUTTON);
static void execute_release_callback(PUSHBUTTON_TypDef *BUTTON);

static void update_pushbutton_input_state(PUSHBUTTON_TypDef *BUTTON)
{
    BUTTON->input_state = BUTTON->GPIO_interface->get_button_input_state();
}

static void update_button_deb_rep_counter(PUSHBUTTON_TypDef *BUTTON)
{

    if ((BUTTON->repetition) == REPETITION_ON)
    {
        if ((BUTTON->REPETITION_STATUS_FLAG) == REPETITION_INACTIVE)
        {
            BUTTON->deb_rep_timer = PUSHBUTTON_FIRST_REPETITION_TIME;
            BUTTON->REPETITION_STATUS_FLAG = REPETITION_ACTIVE;
        }
        else
        {
            BUTTON->deb_rep_timer = PUSHBUTTON_CONTINUOUS_REPETITION_TIME;
        }
    }
    else
    {
        BUTTON->deb_rep_timer = 0;
    }
}

static void debounce_pushbutton_push_state(PUSHBUTTON_TypDef *BUTTON)
{
    if ((BUTTON->input_state) == PUSHED)
    {
        if ((BUTTON->deb_rep_timer) == 1)
        {
            execute_push_callback(BUTTON);
            update_button_deb_rep_counter(BUTTON);
        }
        else
        {
            // Empty else statement for case when deb_rep_timer is different then 1
        }
    }
    else
    {
        BUTTON->deb_rep_timer = PUSHBUTTON_DEBOUNCE_TIME;
        BUTTON->REPETITION_STATUS_FLAG = REPETITION_INACTIVE;
    }
}

static void debounce_pushbutton_release_state(PUSHBUTTON_TypDef *BUTTON)
{
    if ((BUTTON->input_state) == PUSHED)
    {
        BUTTON->deb_rep_timer = PUSHBUTTON_DEBOUNCE_TIME;
    }
    else
    {
        if ((BUTTON->deb_rep_timer) == 1)
        {
            execute_release_callback(BUTTON);
            BUTTON->deb_rep_timer = 0;
        }
        else
        {
            // Empty else statement for case when deb_rep_timer is different then 1
        }
    }
}

void debounce_pushbutton_short_push_long_push_state(PUSHBUTTON_TypDef *BUTTON)
{
    switch (BUTTON->pushbutton_state_machine)
    {
    case BUTTON_RELEASED:
        if ((BUTTON->input_state) == PUSHED)
        {
            BUTTON->pushbutton_state_machine = PUSH_DEBOUNCING;
            BUTTON->deb_rep_timer = PUSHBUTTON_DEBOUNCE_TIME;
        }
        break;
    case PUSH_DEBOUNCING:
        handle_push_debouncing(BUTTON);
        break;
    case SHORT_PUSH_PHASE:
        handle_short_push_phase(BUTTON);
        break;
    case LONG_PUSH_PHASE:
        handle_long_push_phase(BUTTON);
        break;
    case LONG_PUSH_NO_REPETITION_PHASE:
        handle_long_push_no_repetition_phase(BUTTON);
        break;
    }
}
static void handle_push_debouncing(PUSHBUTTON_TypDef *BUTTON)
{
    if ((BUTTON->input_state) == PUSHED)
    {
        if ((BUTTON->deb_rep_timer) == 0)
        {
            BUTTON->pushbutton_state_machine = SHORT_PUSH_PHASE;
            BUTTON->deb_rep_timer = PUSHBUTTON_SHORT_PUSH_TIME_MAX;
        }
    }
    else
    {
        BUTTON->pushbutton_state_machine = BUTTON_RELEASED;
    }
}
static void handle_long_push_no_repetition_phase(PUSHBUTTON_TypDef *BUTTON)
{
    if ((BUTTON->input_state) == RELEASED)
    {
        BUTTON->pushbutton_state_machine = BUTTON_RELEASED;
    }
    else
    {
        BUTTON->pushbutton_state_machine = LONG_PUSH_NO_REPETITION_PHASE;
    }
}

static void handle_long_push_phase(PUSHBUTTON_TypDef *BUTTON)
{
    if ((BUTTON->input_state) == PUSHED)
    {
        if ((BUTTON->deb_rep_timer) == 0)
        {
            execute_push_callback(BUTTON);
            BUTTON->deb_rep_timer = PUSHBUTTON_CONTINUOUS_REPETITION_TIME;
        }
    }
    else
    {
        BUTTON->deb_rep_timer = PUSHBUTTON_DEBOUNCE_TIME;
        BUTTON->pushbutton_state_machine = BUTTON_RELEASED;
    }
}

static void handle_short_push_phase(PUSHBUTTON_TypDef *BUTTON)
{
    if ((BUTTON->input_state) == PUSHED)
    {
        handle_short_push_phase_pin_pushed(BUTTON);
    }
    else
    {
        handle_short_push_phase_pin_released(BUTTON);
    }
}

static void handle_short_push_phase_pin_pushed(PUSHBUTTON_TypDef *BUTTON)
{
    if ((BUTTON->deb_rep_timer) == 0)
    {
        execute_push_callback(BUTTON);

        if (BUTTON->repetition == REPETITION_ON)
        {
            BUTTON->pushbutton_state_machine = LONG_PUSH_PHASE;
            BUTTON->deb_rep_timer = PUSHBUTTON_FIRST_REPETITION_TIME;
        }
        else
        {
            BUTTON->pushbutton_state_machine = LONG_PUSH_NO_REPETITION_PHASE;
        }
    }
}

static void handle_short_push_phase_pin_released(PUSHBUTTON_TypDef *BUTTON)
{
    execute_release_callback(BUTTON);
    BUTTON->deb_rep_timer = PUSHBUTTON_DEBOUNCE_TIME;
    BUTTON->pushbutton_state_machine = BUTTON_RELEASED;
}

static void execute_push_callback(PUSHBUTTON_TypDef *BUTTON)
{
    if (BUTTON->push_callback != NULL)
    {
        BUTTON->push_callback(); // push callback to instancja gdzie trzeba zaerejsrować long push
    }
}

static void execute_release_callback(PUSHBUTTON_TypDef *BUTTON)
{
    if (BUTTON->release_callback != NULL)
    {
        BUTTON->release_callback(); // push callback to instancja gdzie trzeba zaerejsrować long push
    }
}
/**
 * @brief Initializes pushbuttons.
 *
 * This function initializes pushbuttons by obtaining GPIO interfaces,
 * calling their initialization functions, and setting up the necessary configurations.
 *
 * The initialization includes:
 * - Retrieving GPIO interfaces for PUSHBUTTON.
 * - Calling the initialization function for each pushbutton through the obtained GPIO interfaces.
 * - Setting the initial state of the state machines for PUSHBUTTON to BUTTON_RELEASED.
 *
 * @param BUTTON Pointer to the pushbutton structure to initialize.
 * @param PB_repetition_mode The repetition mode for the pushbutton ::PB_repetition_t.
 * @param PB_triger_mode The trigger mode for the pushbutton events ::PB_trigger_mode_t.
 * @param PB_get_driver_interface_adr_callback Callback function to obtain GPIO interface address.
 *
 *
 */
void init_pushbutton(PUSHBUTTON_TypDef *BUTTON,
                     const PB_repetition_t PB_repetition_mode,
                     const PB_trigger_mode_t PB_triger_mode,
                     const PB_GPIO_interface_get_callback PB_get_driver_interface_adr_callback)
{
    BUTTON->GPIO_interface = PB_get_driver_interface_adr_callback();

    BUTTON->GPIO_interface->GPIO_init();
    BUTTON->repetition = PB_repetition_mode;
    BUTTON->trigger_mode = PB_triger_mode;

    // init other parameters of the structure to default init value
    BUTTON->deb_rep_timer = 0;
    BUTTON->pushbutton_state_machine = BUTTON_RELEASED;
    BUTTON->input_state = UNKNOWN;
    BUTTON->REPETITION_STATUS_FLAG = REPETITION_INACTIVE;
    BUTTON->push_callback = NULL;
    BUTTON->release_callback = NULL;
}

/**
 * @brief Checks the state of a pushbutton and performs debouncing based on the trigger mode.
 *
 * This function updates the input state of the specified pushbutton, then determines the trigger mode
 * and invokes the corresponding debouncing function. The debouncing process ensures reliable detection
 * of pushbutton events, such as push, release, short push, or long push, based on the configured trigger mode.
 *
 * @param BUTTON The pushbutton structure to check and debounce.
 *
 * @note Before calling this function, ensure that the pushbutton has been properly initialized using the
 * @ref init_pushbutton function.
 *
 * @see init_pushbutton, update_pushbutton_input_state, debounce_pushbutton_push_state,
 * debounce_pushbutton_release_state, debounce_pushbutton_short_push_long_push_state
 */
void check_pushbutton(PUSHBUTTON_TypDef *BUTTON)
{
    update_pushbutton_input_state(BUTTON);
    switch (BUTTON->trigger_mode)
    {
    case TRIGGER_ON_PUSH:
        debounce_pushbutton_push_state(BUTTON);
        break;
    case TRIGGER_ON_RELEASE:
        debounce_pushbutton_release_state(BUTTON);
        break;
    default:
        debounce_pushbutton_short_push_long_push_state(BUTTON);
        break;
    }
}

/**
 * @brief Registers a callback function to be called on pushbutton press.
 *
 * This function associates a callback function with the specified pushbutton,
 * to be executed when the pushbutton is pressed. The callback is triggered
 * by changes in the pushbutton state from released to pressed.
 *
 * @param button_name The name of the pushbutton to register the callback for. Use values from #pushbutton_name_t
 * enumeration.
 * @param callback_on_push The callback function to be executed on push.
 *
 * @note If the pushbutton is not registered, this function has no effect.
 *
 * @warning Avoid lengthy operations or blocking code in the callback function, as it may impact the responsiveness
 * of the system.
 */
void register_button_push_callback(PUSHBUTTON_TypDef *BUTTON, PB_callback_t callback_on_push)
{
    BUTTON->push_callback = callback_on_push;
}

/**
 * @brief Registers a callback function to be called on pushbutton release.
 *
 * This function associates a callback function with the specified pushbutton,
 * to be executed when the pushbutton is released. The callback is triggered by
 * changes in the pushbutton state from pressed to released.
 *
 * @param button_name The name of the pushbutton to register the release callback for. Use values from
 * #pushbutton_name_t enumeration.
 * @param callback_on_button_release The callback function to be executed on pushbutton release.
 *
 * @note If the pushbutton is not registered, this function has no effect.
 *
 * @warning Avoid lengthy operations or blocking code in the release callback function, as it may impact the
 * responsiveness of the system.
 */
void register_button_release_callback(PUSHBUTTON_TypDef *BUTTON, PB_callback_t callback_on_button_release)
{
    BUTTON->release_callback = callback_on_button_release;
}

/**
 * @brief Registers callback functions for short push and long push events on a pushbutton.
 *
 * This function associates callback functions with the specified pushbutton,
 * to be executed when short push and long push events occur. The short push callback
 * is triggered when the pushbutton is released quickly, and the long push callback is
 * triggered when the pushbutton is held down for an extended period.
 *
 * @param button_name The name of the pushbutton to register the callbacks for. Use values from #pushbutton_name_t
 * enumeration.
 * @param callback_on_short_push The callback function to be executed on a short push event.
 * @param callback_on_long_push The callback function to be executed on a long push event.
 *
 * @note If the pushbutton is not registered, this function has no effect.
 *
 * @warning Avoid lengthy operations or blocking code in the callback functions, as it may impact the
 * responsiveness of the system.
 */
void register_button_short_push_long_push_callbacks(PUSHBUTTON_TypDef *BUTTON, PB_callback_t callback_on_short_push, PB_callback_t callback_on_long_push)
{
    BUTTON->release_callback = callback_on_short_push;
    BUTTON->push_callback = callback_on_long_push;
}

/**
 * @brief Enables pushbutton repetition.
 *
 * This function enables pushbutton repetition for the specified pushbutton.
 *
 * @param button_name The name of the pushbutton to enable repetition for. Use values from #pushbutton_name_t
 * enumeration.
 *
 * @note If the pushbutton is not registered, this function has no effect.
 */
void enable_pusbutton_repetition(PUSHBUTTON_TypDef *BUTTON)
{
    BUTTON->repetition = REPETITION_ON;
}

/**
 * @brief Disables pushbutton repetition.
 *
 * This function disables pushbutton repetition for the specified pushbutton.
 *
 * @param button_name The name of the pushbutton to disable repetition for. Use values from #pushbutton_name_t
 * enumeration.
 *
 * @note If the pushbutton is not registered, this function has no effect.
 */
void disable_pusbutton_repetition(PUSHBUTTON_TypDef *BUTTON)
{
    BUTTON->repetition = REPETITION_OFF;
}

/**
 * @brief Decrements the debounce and repetition timer of a pushbutton.
 *
 * This function decrements the debounce and repetition timer of the specified pushbutton
 * if the pushbutton is valid and the timer is non-zero. This is typically used in the
 * context of pushbutton debouncing and repetition control.
 *
 * @param button_name The name of the pushbutton to decrement the timer for. Use values from #pushbutton_name_t
 * enumeration.
 *
 * @note Make sure to register the pushbutton with the system before using this function.
 * The pushbutton state will be updated based on the specified repetition type.
 * If the pushbutton is not registered or the timer is already at zero, this function has no effect.
 * It is the responsibility of the caller to manage the timing of this function appropriately.
 */
void dec_pushbutton_deb_rep_timer(PUSHBUTTON_TypDef *BUTTON)
{
    BUTTON->deb_rep_timer--;
}
