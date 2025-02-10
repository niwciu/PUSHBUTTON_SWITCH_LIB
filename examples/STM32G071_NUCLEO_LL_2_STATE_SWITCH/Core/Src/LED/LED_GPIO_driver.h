/**
 * @file LED_GPIO_driver.h
 * @brief Declarations for controlling LED using GPIO.
 * @details This file contains the declarations of functions related to controlling an LED
 * using GPIO. The functions include toggling, turning off, and turning on the LED.
 * @version 0.0.1
 * @date 2024-03-06
 * 
 * @author [Author Name]
 * @email [Author Email]
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef _LED_GPIO_DRIVER_H_
#define _LED_GPIO_DRIVER_H_

#ifdef __cplusplus
 extern "C" {
#endif

void LED_off (void);
void LED_on (void);

#ifdef __cplusplus
}
#endif

#endif /* _LED_GPIO_DRIVER_H_*/