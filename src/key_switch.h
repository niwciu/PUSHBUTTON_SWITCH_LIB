/**
 * @file key_switch.h
 * @author niwciu (niwciu@gmail.com)
 * @brief
 * @version 0.0.1
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _KEY_SWITCH_H_
#define _KEY_SWITCH_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#include "key_switch_interface.h"
#include <stdint.h>

#define KEY_DEBOUNCE_TIME 200

typedef uint8_t input_debounce_timer_t;
typedef uint16_t key_repetition_timer_t;

typedef void (*key_execute_callback_t) (void);
typedef struct
{
    key_driver_interface_t *GPIO_interface; //ten wskaźnik trzeba załadować w czasie inicjalizacji adresem właściwego interfejsu dla tego klaiwsza
    input_debounce_timer_t key_debounce_timer;
    key_repetition_timer_t key_repetition_timer;
    key_execute_callback_t push_callback;
    key_execute_callback_t up_callback;
    //
} key_t;

extern key_t KEY_1;
extern key_t KEY_2;

void init_keys(void);

void check_key_push(key_t *KEY);
void register_key_push_callback(key_t *KEY,key_execute_callback_t callback);
// void check_key_up(key_t *KEY);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _KEY_SWITCH_H_ */