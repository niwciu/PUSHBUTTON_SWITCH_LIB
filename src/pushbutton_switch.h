/**
 * @file pushbutton_switch.h
 * @author niwciu (niwciu@gmail.com)
 * @brief Library providing an interface for pushbutton switches with debouncing and repetition functionality.
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

/** @brief Time duration for pushbutton debounce in milliseconds. */
#define PUSHBUTTON_DEBOUNCE_TIME 200U

/** @brief Time duration for the first repetition of a pushbutton press in milliseconds. */
#define PUSHBUTTON_FIRST_REPETITION_TIME 1000U

/** @brief Time duration for continuous repetition of a pushbutton press in milliseconds. */
#define PUSHBUTTON_CONTINUES_REPETITION_TIME 500U

/** @brief Time duration for splitting short push and long push in milliseconds. */
#define PUSHBUTTON_SHORT_PUSH_TIME_MAX 1000U


/**
 * @brief Callback function pointer type for pushbutton events.
 *
 * This type defines the function signature for callback functions to be associated
 * with pushbutton events.
 */
typedef void (*pushbutton_callback_t)(void);
/**
 * @brief Enumeration of pushbutton names.
 *
 * This enumeration defines the possible names of pushbuttons.
 */
typedef enum {
    BUTTON_1,   /**< Represents the first pushbutton. */
    BUTTON_2,   /**< Represents the second pushbutton. */
}pushbutton_name_t;

void init_pushbuttons(void);

void check_button_push(pushbutton_name_t button_name);
void check_button_release(pushbutton_name_t button_name);
void check_button_short_push_long_push(pushbutton_name_t button_name);

void register_button_push_callback(pushbutton_name_t button_name,pushbutton_callback_t callback_on_push);
void register_button_release_callback(pushbutton_name_t button_name,pushbutton_callback_t callback_on_button_release);
void register_button_short_push_long_push_callbacks(pushbutton_name_t button_name,pushbutton_callback_t callback_on_short_push,pushbutton_callback_t callback_on_long_push);

void enable_pusbutton_repetition(pushbutton_name_t button_name);
void disable_pusbutton_repetition(pushbutton_name_t button_name);

void dec_pushbutton_deb_rep_timer(pushbutton_name_t button_name);


/**
 * ToDo funkcja do ustawiania parametru repetycji tak by oddzielić sprawdzanie stanu klaisza od ustawienia tego czy ma być repetycja czy nie  
 * 
 */

/*
 * functionality to be implemented in the future for singals
 * 
 */


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _PUSHBUTTON_SWITCH_H_ */