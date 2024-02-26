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

typedef uint8_t input_debounce_timer_t;
typedef uint16_t key_repetition_timer_t;
typedef struct
{
    key_driver_interface_t *GPIO_interface; //ten wskaźnik trzeba załadować w czasie inicjalizacji adresem właściwego interfejsu dla tego klaiwsza
    input_debounce_timer_t key_debounce_timer;
    key_repetition_timer_t key_repetition_timer;
    //
} key_t;

extern key_t KEY_1;
extern key_t KEY_2;

void key_init(key_t *key);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _KEY_SWITCH_H_ */