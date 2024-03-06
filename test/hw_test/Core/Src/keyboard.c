
#include "main.h"
#include "keyboard.h"
#include "pushbutton.h"

PUSHBUTTON_TypDef KEY_1;

static void LED_toogle (void);
static void LED_off (void);
static void LED_on (void);


static void LED_toogle (void)
{
  if(LL_GPIO_IsOutputPinSet(LED_GPIO_Port,LED_Pin)){
    LL_GPIO_ResetOutputPin(LED_GPIO_Port,LED_Pin);
  }
  else{
    LL_GPIO_SetOutputPin(LED_GPIO_Port,LED_Pin);
  }
}

static void LED_on (void)
{
    LL_GPIO_SetOutputPin(LED_GPIO_Port,LED_Pin); 
}

static void LED_off (void)
{
    LL_GPIO_ResetOutputPin(LED_GPIO_Port,LED_Pin);
}

void init_keyboard(void)
{
   init_pushbutton(&KEY_1,REPETITION_ON,TRIGER_ON_SHORT_PUSH_AND_LONG_PUSH,pushbutton_1_GPIO_interface_get);
   register_button_push_callback(&KEY_1,LED_toogle);
   register_button_release_callback(&KEY_1,LED_off);
   subscribe_SysTick_callback(update_button_timers);
//    LL_GPIO_SetOutputPin(LED_GPIO_Port,LED_Pin);
}
void check_keyboard(void)
{
    check_pushbutton(&KEY_1);
}

void update_button_timers (void)
{
    dec_pushbutton_deb_rep_timer(&KEY_1);
}
