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
#include "key_switch.h"

// typedef key_long_push_timer_t uint16_t;
// typedef key_short_up_timer_t uint16_t;
typedef uint8_t input_state_t;

// typedef void (*key_execute_callback_t) (void);

key_t KEY_1;
key_t KEY_2;

/**
 * @brief  Function that initialize hardwer se they can work as inputs
 */
void init_keys(void)
{
    KEY_1.GPIO_interface = KEY_1_GPIO_interface_get();
    KEY_2.GPIO_interface = KEY_2_GPIO_interface_get();

    KEY_1.GPIO_interface->GPIO_init();
    KEY_2.GPIO_interface->GPIO_init();

    // KEY_1.key_debounce_timer=KEY_DEBOUNCE_TIME;
    // KEY_2.key_debounce_timer=KEY_DEBOUNCE_TIME;
}

void check_key_push(key_t *KEY)
{
    enum PIN_state_e KEY_input_state = KEY->GPIO_interface->get_pin_state();

    if(KEY_input_state == LOW )
    {
            if((KEY->key_debounce_timer)==1)
            {
                //wykonaj funkcje
                KEY->push_callback();
                //jeśli repetycja to załaduj na nowo debounce timer 
                //jeśli brak repetycji to ustaw Timer na 0
                KEY->key_debounce_timer=0;
            }
            else
            {

            }
    }
    else 
    {
        KEY->key_debounce_timer=KEY_DEBOUNCE_TIME;
    }
}

void register_key_push_callback(key_t *KEY, key_execute_callback_t callback)
{
    KEY->push_callback=callback;
}
