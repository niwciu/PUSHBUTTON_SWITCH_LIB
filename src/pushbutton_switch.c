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

// typedef key_long_push_timer_t uint16_t;
// typedef key_short_up_timer_t uint16_t;
typedef uint8_t input_state_t;

// typedef void (*key_execute_callback_t) (void);


typedef uint16_t pushbutton_repetition_timer_t;

typedef struct
{
    pushbutton_driver_interface_t *GPIO_interface; // ten wskaźnik trzeba załadować w czasie inicjalizacji adresem
                                                   // właściwego interfejsu dla tego klaiwsza
    input_debounce_timer_t debounce_timer;
    pushbutton_repetition_timer_t repetition_timer;
    pushbutton_callback_t push_callback;
    pushbutton_callback_t up_callback;
    //
} pushbutton_t;

pushbutton_t PUSHBUTTON_1;
pushbutton_t PUSHBUTTON_2;

/**
 * @brief  Function that initialize hardwer se they can work as inputs
 */
void init_pushbuttons(void)
{
    PUSHBUTTON_1.GPIO_interface = pushbutton_1_GPIO_interface_get();
    PUSHBUTTON_2.GPIO_interface = pushbutton_2_GPIO_interface_get();

    PUSHBUTTON_1.GPIO_interface->GPIO_init();
    PUSHBUTTON_2.GPIO_interface->GPIO_init();

    PUSHBUTTON_1.debounce_timer=PUSHBUTTON_DEBOUNCE_TIME;
    PUSHBUTTON_2.debounce_timer=PUSHBUTTON_DEBOUNCE_TIME;
}

void check_button_push(enum pushbutton_e button_name)
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
        break;
    }
    if (BUTTON != NULL)
    {
        enum button_state_e BUTTON_input_state = BUTTON->GPIO_interface->get_button_state();

        if (BUTTON_input_state == PUSHED)
        {
            if ((BUTTON->debounce_timer) == 1)
            {
                // wykonaj funkcje
                BUTTON->push_callback();
                // jeśli repetycja to załaduj na nowo debounce timer
                // jeśli brak repetycji to ustaw Timer na 0
                BUTTON->debounce_timer = 0;
            }
            else
            {
            }
        }
        else
        {
            BUTTON->debounce_timer = PUSHBUTTON_DEBOUNCE_TIME;
        }
    }
}

void register_button_push_callback(enum pushbutton_e button_name, pushbutton_callback_t callback_on_push)
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
        break;
    }
    if (BUTTON != NULL)
        BUTTON->push_callback = callback_on_push;
}

void dec_debounce_timer(enum pushbutton_e button_name)
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
        break;
    }
    if (BUTTON != NULL)
        if (BUTTON->debounce_timer)
            BUTTON->debounce_timer--;
    printf("%i",BUTTON->debounce_timer);
}
