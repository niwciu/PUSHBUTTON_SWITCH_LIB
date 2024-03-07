/**
 * @file switch.h
 * @author niwciu (niwciu@gmail.com)
 * @brief Header file for a switch control module.
 * @version 0.0.1
 * @date 2024-03-04
 *
 * This file contains the declarations for a switch control module,
 * defining structures, enumerations, and function prototypes related
 * to the management of switch states and callbacks.
 *
 * @copyright Copyright (c) 2024
 */

#ifndef _SWITCH_H_
#define _SWITCH_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/**
 * @brief Number of debounce repetitions for the switch.
 */
#define SWITCH_DEBOUNCE_REPETITIONS 100U

#include "switch_GPIO_interface.h"

    /**
     * @brief Type definition for the switch counter.
     */
    typedef uint16_t SWITCH_counter_t;

    /**
     * @brief Enumeration representing different states of the switch state machine.
     */
    typedef enum
    {
        SW_INIT,        /**< Initialization state. */
        SW_OFF,         /**< Switch is in the OFF state. */
        SW_SWITCHED_ON, /**< Switch is in the switched-on state. */
        SW_ON,          /**< Switch is in the ON state. */
        SW_SWITCHED_OFF /**< Switch is in the switched-off state. */
    } SWITCH_state_macine_t;

    /**
     * @brief Callback function type for switch events.
     */
    typedef void (*SWITCH_callback_t)(void);

    /**
     * @brief Structure representing the switch control module.
     */
    typedef struct
    {
        SWITCH_driver_interface_t *GPIO_interface;  /**< GPIO interface for the switch. */
        SWITCH_input_state_t input_state;           /**< Current input state of the switch. */
        SWITCH_counter_t debounce_counter;          /**< Counter for switch debounce logic. */
        SWITCH_callback_t switch_ON_callback;       /**< Callback function for switch ON event. */
        SWITCH_callback_t switch_OFF_callback;      /**< Callback function for switch OFF event. */
        SWITCH_state_macine_t switch_state_machine; /**< Current state of the switch state machine. */
    } SWITCH_TypDef;

    /**
     * @brief Callback function type for obtaining the GPIO driver interface address.
     */
    typedef const SWITCH_driver_interface_t *(*SWITCH_GPIO_interface_get_callback)(void);

    void init_switch(SWITCH_TypDef *SWITCH,
                     const SWITCH_callback_t switch_ON_callback,
                     const SWITCH_callback_t switch_OFF_callback,
                     const SWITCH_GPIO_interface_get_callback SWITCH_get_driver_interface_adr_callback);

    void check_switch(SWITCH_TypDef *SWITCH);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SWITCH_H_ */
