/**
 * @file mock_switch_GPIO_driver.h
 * @author niwciu (niwciu@gmail.com)
 * @brief 
 * @version 0.0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "switch_GPIO_interface.h"
#include <stdint.h>


extern SWITCH_input_state_t mock_SWITCH_1_STATE;

extern uint8_t TEST_TIMER;

void inc_test_timer(void);
void dec_test_timer(void);
