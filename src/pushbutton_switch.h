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
#ifndef _PUSHBUTTON_SWITCH_H_
#define _PUSHBUTTON_SWITCH_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#include "pushbutton_switch_interface.h"
#include <stdint.h>

#define PUSHBUTTON_DEBOUNCE_TIME 200U
#define PUSHBUTTON_FIRST_REPETITION_TIME 1000U

typedef void (*pushbutton_callback_t)(void);

enum pushbutton_e{
    BUTTON_1,
    BUTTON_2,
};
enum pushbutton_repetition_e{
    REPETITION_ON,
    REPETITION_OFF,
};


void init_pushbuttons(void);

void check_button_push(enum pushbutton_e button_name,enum pushbutton_repetition_e repetition);
void register_button_push_callback(enum pushbutton_e button_name,pushbutton_callback_t callback_on_push);
void dec_debounce_timer(enum pushbutton_e button_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _PUSHBUTTON_SWITCH_H_ */