/**
 * @file key_switch_interface.h
 * @author niwciu (niwciu@gmail.com)
 * @brief
 * @version 0.0.1
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _PUSHBUTTON_SWITCH_INTERFACE_H_
#define _PUSHBUTTON_SWITCH_INTERFACE_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/**
 * @brief Enumeration representing the possible states of a pushbutton.
 */
typedef enum
{
    UP,      /**< Button in the UP state. */
    PUSHED,  /**< Button in the PUSHED state. */
    UNKNOWN  /**< Unknown state of the button. */
} button_state_t;

/**
 * @brief Pointer to a function type for initializing a pushbutton.
 */
typedef void (*pushbutton_init_func_p)(void);

/**
 * @brief Pointer to a function type for getting the state of a pushbutton.
 *
 * This function should return one of the values from the #button_state_t enumeration.
 */
typedef button_state_t (*get_pushbutton_state_func_p)(void);

/**
 * @brief Structure defining the interface for a pushbutton driver.
 *
 * This structure contains function pointers for initializing a pushbutton and
 * retrieving its state.
 */
typedef const struct
{
    pushbutton_init_func_p GPIO_init;          /**< Function pointer for pushbutton initialization. */
    get_pushbutton_state_func_p get_button_state; /**< Function pointer for getting the pushbutton state. */
} pushbutton_driver_interface_t;

/** @brief External instance of the pushbutton driver interface for PUSHBUTTON_1. */
extern pushbutton_driver_interface_t PUSHBUTTON_1_GPIO_interface_struct;

/** @brief External instance of the pushbutton driver interface for PUSHBUTTON_2. */
extern pushbutton_driver_interface_t PUSHBUTTON_2_GPIO_interface_struct;

    /**
     * @brief Gets the GPIO interface for pushbutton 1.
     *
     * This function returns a pointer to the GPIO interface structure
     * specific to pushbutton 1.
     *
     * @return Pointer to the pushbutton 1 GPIO interface.
     */
    const pushbutton_driver_interface_t *pushbutton_1_GPIO_interface_get(void);

    /**
     * @brief Gets the GPIO interface for pushbutton 2.
     *
     * This function returns a pointer to the GPIO interface structure
     * specific to pushbutton 2.
     *
     * @return Pointer to the pushbutton 2 GPIO interface.
     */
    const pushbutton_driver_interface_t *pushbutton_2_GPIO_interface_get(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _PUSHBUTTON_SWITCH_INTERFACE_H_ */