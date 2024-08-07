/**
 * @file pushbutton_TIM_interface.h
 * @author niwciu (niwciu@gmail.com)
 * @brief Defines the interface for integrating pushbutton layer with a timer (TIM) module. It's part of this library but in project this file should come
 * from Timer implementation layer side where "observer" design patter is implemented.
 * @date 2024-03-02
 * @copyright Copyright (c) 2024
 */
#ifndef _PUSHBUTTON_TIM_INTERFACE_H_
#define _PUSHBUTTON_TIM_INTERFACE_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
     * @brief Callback function type for 1 ms timer events.
     *
     * This function type is used for callback functions that are triggered every 1ms by timer events. 
     * 
     *  
     */
    typedef void (*Timer_callback_t)(void);

    /**
     * @brief Subscribes a callback function to timer events fired with 1ms resolution.
     *
     * This function allows subscribing a callback function to timer events for timer-related operations.
     *
     * @param SysTick_callback The callback function to be subscribed.
     */
    void subscribe_timer_callback(Timer_callback_t Timer_callback);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PUSHBUTTON_TIM_INTERFACE_H_ */
