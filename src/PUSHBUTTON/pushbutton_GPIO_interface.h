/**
 * @file pushbutton_GPIO_interface.h
 * @brief Defines the interface for pushbutton drivers, including an enumeration for button states and function pointers for initialization and state retrieval.
 * @author niwciu (niwciu@gmail.com)
 * @version 0.0.1
 * @date 2024-02-26
 * @copyright Copyright (c) 2024
 */
#ifndef _PUSHBUTTON_INTERFACE_H_
#define _PUSHBUTTON_INTERFACE_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#include <stdint.h>
    /**
     * @brief Enumeration representing the possible states of a pushbutton.
     */
    typedef enum
    {
        RELEASED, /**< Button in the RELEASED state. */
        PUSHED,   /**< Button in the PUSHED state. */
        UNKNOWN   /**< Unknown state of the button. */
    } PB_input_state_t;

    /**
     * @brief Pointer to a function type for initializing a pushbutton.
     */
    typedef void (*pushbutton_init_func_p)(void);

    /**
     * @brief Pointer to a function type for initializing a pushbutton.
     */
    typedef void (*pushbutton_init_func_p)(void);

    /**
     * @brief Pointer to a function type for getting the state of a pushbutton.
     *
     * This function should return one of the values from the #PB_input_state_t enumeration.
     */
    typedef PB_input_state_t (*get_pushbutton_state_func_p)(void);

    /**
     * @brief Structure defining the interface for a pushbutton driver.
     *
     * This structure contains function pointers for initializing a pushbutton and
     * retrieving its state.
     */
    typedef const struct
    {
        pushbutton_init_func_p GPIO_init;                   /**< Function pointer for pushbutton initialization. */
        get_pushbutton_state_func_p get_button_input_state; /**< Function pointer for getting the pushbutton state. */
    } PB_driver_interface_t;

    /**
     * @brief Gets the GPIO interface for pushbutton 1.
     *
     * This function returns a pointer to the GPIO driver interface structure
     * specific to pushbutton 1 on GPIO drier layer.
     *
     * @return Pointer to the pushbutton 1 GPIO interface.
     */
    const PB_driver_interface_t *pushbutton_1_GPIO_interface_get(void);

    /**
     * @brief Gets the GPIO interface for pushbutton 2.
     *
     * This function returns a pointer to the GPIO driver interface structure
     * specific to pushbutton 2 on GPIO drier layer.
     *
     * @return Pointer to the pushbutton 2 GPIO interface.
     */
    const PB_driver_interface_t *pushbutton_2_GPIO_interface_get(void);

    // Additional interfaces for more pushbuttons can be added if needed.
    // const PB_driver_interface_t *pushbutton_3_GPIO_interface_get(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _PUSHBUTTON_INTERFACE_H_ */