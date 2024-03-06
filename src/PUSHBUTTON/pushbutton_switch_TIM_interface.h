/**
 * @file pushbutton_switch_TIM_interface.h
 * @author niwciu (niwciu@gmail.com)
 * @brief 
 * @version 0.0.1
 * @date 2024-03-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _PUSHBUTTON_SWITCH_TIM_INTERFACE_H_
#define _PUSHBUTTON_SWITCH_TIM_INTERFACE_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
typedef void (*SysTick_callback_t)(void);

void subscribe_SysTick_callback(SysTick_callback_t SysTick_callback);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _PUSHBUTTON_SWITCH_TIM_INTERFACE_H_ */