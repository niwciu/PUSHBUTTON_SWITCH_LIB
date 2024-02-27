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
extern enum button_state_e PUSHBUTTON_1_STATE;
extern enum button_state_e PUSHBUTTON_2_STATE;
extern uint8_t TEST_TIMER;

void inc_test_timer(void);
