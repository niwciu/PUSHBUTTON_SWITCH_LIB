/**
 * @brief 
 * 
 */
#include "key_switch_interface.h"
#include <stddef.h>
#include "mock_key_GPIO_driver.h"

enum PIN_state_e KEY_1_PIN_STATE=UNKNOWN;
enum PIN_state_e KEY_2_PIN_STATE=UNKNOWN;

uint8_t TEST_TIMER=0;

static void key_1_gpio_init(void);
static void key_2_gpio_init(void);
static enum PIN_state_e get_key_1_state(void);
static enum PIN_state_e get_key_2_state(void);


key_driver_interface_t KEY_1_GPIO_interface_struct={
    key_1_gpio_init,
    get_key_1_state,
};

key_driver_interface_t KEY_2_GPIO_interface_struct={
    key_2_gpio_init,
    get_key_2_state,
};


const key_driver_interface_t* KEY_1_GPIO_interface_get(void)
{
    return &KEY_1_GPIO_interface_struct;
}
const key_driver_interface_t* KEY_2_GPIO_interface_get(void){
    return &KEY_2_GPIO_interface_struct;
}

static void key_1_gpio_init(void)
{
    KEY_1_PIN_STATE=HIGH;
}

static void key_2_gpio_init(void)
{
    KEY_2_PIN_STATE=HIGH;
}

static enum PIN_state_e get_key_1_state(void)
{
    return KEY_1_PIN_STATE;
}

static enum PIN_state_e get_key_2_state(void)
{
    return KEY_2_PIN_STATE;
}

void inc_test_tmer(void)
{
    TEST_TIMER++;
}