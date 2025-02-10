/**
 * @file LED_GPIO_driver.c
 * @brief GPIO driver layer for executing operations on LED.
 * @details This file contains the implementation of functions to control the state of an LED using GPIO.
 * @version 0.0.1
 * @date 2024-03-06
 * 
 * @author niwciu
 * @email niwciu@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */

#include "LED_GPIO_driver.h"
#include "main.h"

/**
 * @brief Toggles the state of the LED.
 * @details If the LED is currently on, it will be turned off, and vice versa.
 */
void LED_toggle(void)
{
    if(LL_GPIO_IsOutputPinSet(LED_GPIO_Port, LED_Pin))
    {
        LL_GPIO_ResetOutputPin(LED_GPIO_Port, LED_Pin);
    }
    else
    {
        LL_GPIO_SetOutputPin(LED_GPIO_Port, LED_Pin);
    }
}

/**
 * @brief Turns on the LED.
 * @details Sets the output pin of the LED GPIO port to logic high, turning on the LED.
 */
void LED_on(void)
{
    LL_GPIO_SetOutputPin(LED_GPIO_Port, LED_Pin);
}

/**
 * @brief Turns off the LED.
 * @details Resets the output pin of the LED GPIO port to logic low, turning off the LED.
 */
void LED_off(void)
{
    LL_GPIO_ResetOutputPin(LED_GPIO_Port, LED_Pin);
}