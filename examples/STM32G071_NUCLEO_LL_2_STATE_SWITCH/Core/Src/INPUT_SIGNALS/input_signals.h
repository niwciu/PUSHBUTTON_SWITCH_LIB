/**
 * @file keyboard.h
 * @brief Declarations for keyboard functionality including pushbuttons and LEDs.
 * @details This file contains the declarations of functions related to the keyboard,
 * including initialization, checking pushbutton states, and updating button timers.
 * @version 0.0.1
 * @date 2024-03-06
 * 
 * @author niwciu
 * @email niwciu@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#ifdef __cplusplus
 extern "C" {
#endif

void init_input_signals(void);
void check_input_signals(void);


#ifdef __cplusplus
}
#endif

#endif /* _KEYBOARD_H_ */