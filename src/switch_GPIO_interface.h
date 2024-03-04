/**
 * @file pushbutton_switch_interface.h
 * @brief Defines the interface for pushbutton drivers, including enumeration for button states and function pointers for initialization and state retrieval.
 * @author niwciu (niwciu@gmail.com)
 * @version 0.0.1
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
     * @brief Enumeration representing the possible states of a pushbutton.
     */
    typedef enum
    {
        SWITCH_OFF,   /**< Button in the RELEASED state. */
        SWITCH_ON,     /**< Button in the PUSHED state. */
        SWITCH_UNKNOWN     /**< Unknown state of the button. */
    } SWITCH_input_state_t;


    typedef void (*switch_init_func_p)(void);

  
    typedef SWITCH_input_state_t (*get_switch_state_func_p)(void);

    /**
     * @brief 
     *
     *
     */
    typedef const struct
    {
        switch_init_func_p GPIO_init;          /**< Function pointer for pushbutton initialization. */
        get_switch_state_func_p get_switch_input_state; /**< Function pointer for getting the pushbutton state. */
    } SWITCH_driver_interface_t;


    /**
     * @brief Gets the GPIO interface for pushbutton 1.
     *
     * This function returns a pointer to the GPIO interface structure
     * specific to pushbutton 1.
     *
     * @return Pointer to the pushbutton 1 GPIO interface.
     */
    const SWITCH_driver_interface_t *switch_1_GPIO_interface_get(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _SWITCH_GPIO_INTERFACE_H_ */