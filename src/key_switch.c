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

typedef void *key_press_callback_func_p(void);
typedef void *key_up_callback_func_p(void);

key_t KEY_1;
key_t KEY_2;

void key_init(key_t *key)
{
    // get GPIO_driver_interface_addres
    if(key==&KEY_1)
    {
        key->GPIO_interface=KEY_1_GPIO_interface_get();
    }
    else if (key==&KEY_2)
    {
        key->GPIO_interface=KEY_2_GPIO_interface_get();
    }
    
    key->GPIO_interface->GPIO_init();
    // 
}

