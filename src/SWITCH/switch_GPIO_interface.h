/**
 * @file switch_GPIO_interface.h
 * @brief Defines the interface for two-state switch drivers, including enumeration for switch states and function pointers for initialization and state retrieval.
 * @author niwciu (niwciu@gmail.com)
 * @date 2024-02-26
 * @copyright Copyright (c) 2024
 */
#ifndef _SWITCH_GPIO_INTERFACE_H_
#define _SWITCH_GPIO_INTERFACE_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <stdint.h>

    /**
     * @brief Enumeration representing the possible states of a two-state switch.
     */
    typedef enum
    {
        SWITCH_INPUT_OFF,    /**< Input Pin signal for switch in the OFF state. */
        SWITCH_INPUT_ON,     /**< Input Pin signal for switch in the ON state. */
        SWITCH_INPUT_UNKNOWN /**< Unknown state of the Input Pin signal for switch. */
    } SWITCH_input_state_t;

    /**
     * @brief Function pointer type for two-state switch initialization.
     */
    typedef void (*switch_init_func_p)(void);

    /**
     * @brief Function pointer type for getting the two-state switch state.
     * @return The current state of the two-state switch.
     */
    typedef SWITCH_input_state_t (*get_switch_state_func_p)(void);

    /**
     * @brief Structure defining the interface for two-state switch drivers.
     */
    typedef const struct
    {
        switch_init_func_p GPIO_init;                   /**< Function pointer for two-state switch initialization. */
        get_switch_state_func_p get_switch_input_state; /**< Function pointer for getting the two-state switch state. */
    } SWITCH_driver_interface_t;

    /**
     * @brief Get the GPIO driver interface addres for the two-state switch connected to GPIO.
     * @return A pointer to the two-state switch driver interface.
     */
    const SWITCH_driver_interface_t *switch_1_GPIO_interface_get(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _SWITCH_GPIO_INTERFACE_H_ */