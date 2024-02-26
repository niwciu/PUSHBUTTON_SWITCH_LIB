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
#ifndef _KEY_SWITCH_INTERFACE_H_
#define _KEY_SWITCH_INTERFACE_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    enum PIN_state_e
    {
        HIGH,
        LOW,
        UNKNOWN
    };

    typedef void (*key_init_func_p)(void);
    typedef enum PIN_state_e (*get_pin_state_func_p)(void);

    typedef const struct
    {
        key_init_func_p GPIO_init;
        get_pin_state_func_p get_pin_state;
    } key_driver_interface_t;

    extern key_driver_interface_t KEY_1_GPIO_interface_struct;
    extern key_driver_interface_t KEY_2_GPIO_interface_struct;
    // key_driver_interface_t KEY_3_GPIO_interface;

    const key_driver_interface_t* KEY_1_GPIO_interface_get(void);
    const key_driver_interface_t* KEY_2_GPIO_interface_get(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _KEY_SWITCH_INTERFACE_H_ */