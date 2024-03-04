/**
 * @file switch.h
 * @author niwciu (niwciu@gmail.com)
 * @brief
 * @version 0.0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _SWITCH_H_
#define _SWITCH_H_
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#define SWITCH_DEBOUNCE_REPETITIONS 100U

#include "switch_GPIO_interface.h"
    typedef uint16_t SWITCH_counter_t;

    typedef enum
    {
        SW_INIT,
        SW_OFF,
        SW_SWITCHED_ON,
        SW_ON,
        SW_SWITCHED_OFF
    } SWITCH_state_macine_t;
    /**
     * @brief
     *
     */
    typedef void (*SWITCH_callback_t)(void);

    /**
     * @brief
     *
     *
     */
    typedef struct
    {
        SWITCH_driver_interface_t *GPIO_interface; /**< GPIO interface for the pushbutton. */
        SWITCH_input_state_t input_state;          /**<  */
        SWITCH_counter_t debounce_counter;              /**<  */
        SWITCH_callback_t switch_ON_callback;      /**<  */
        SWITCH_callback_t switch_OFF_callback;     /**<  */
        SWITCH_state_macine_t switch_state_machine;

    } SWITCH_TypDef;

    typedef const SWITCH_driver_interface_t *(*SWITCH_GPIO_interface_get_callback)(void);

    void init_switch(SWITCH_TypDef *SWITCH, SWITCH_GPIO_interface_get_callback SWITCH_get_driver_interface_adr_callback);

    void check_switch(SWITCH_TypDef *SWITCH);

    void register_switch_ON_callback(SWITCH_TypDef *SWITCH, SWITCH_callback_t switch_ON_callback);
    void register_switch_OFF_callback(SWITCH_TypDef *SWITCH, SWITCH_callback_t switch_OFF_callback);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _SWITCH_H_ */