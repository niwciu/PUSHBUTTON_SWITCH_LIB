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

    enum button_state_e
    {
        UP,
        PUSHED,
        UNKNOWN
    };

    typedef void (*pushbutton_init_func_p)(void);
    typedef enum button_state_e (*get_pushbutton_state_func_p)(void);

    typedef const struct
    {
        pushbutton_init_func_p GPIO_init;
        get_pushbutton_state_func_p get_button_state;
    } pushbutton_driver_interface_t;

    extern pushbutton_driver_interface_t PUSHBUTTON_1_GPIO_interface_struct;
    extern pushbutton_driver_interface_t PUSHBUTTON_2_GPIO_interface_struct;

    const pushbutton_driver_interface_t* pushbutton_1_GPIO_interface_get(void);
    const pushbutton_driver_interface_t* pushbutton_2_GPIO_interface_get(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _PUSHBUTTON_SWITCH_INTERFACE_H_ */