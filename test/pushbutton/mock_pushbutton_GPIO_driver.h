/**
 * @file mock_key_GPIO_driver.h
 * @author niwciu (niwciu@gmail.com)
 * @brief 
 * @version 0.0.1
 * @date 2024-02-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdint.h>
extern PB_input_state_t mock_PUSHBUTTON_1_STATE;
extern PB_input_state_t mock_PUSHBUTTON_2_STATE;
extern uint8_t TEST_TIMER;

void inc_test_timer(void);
void dec_test_timer(void);
