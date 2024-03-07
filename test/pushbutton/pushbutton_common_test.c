#include "pushbutton.h"
#include "pushbutton_TIM_interface.h"
#include "pushbutton_common_test.h"

void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_delay_t delay, PUSHBUTTON_TypDef *BUTTON)
{
    for (debounce_repetition_delay_t i = delay; i > 0; i--)
    {
        dec_pushbutton_deb_rep_timer(BUTTON);
    }
}
void generete_pin_bouncing_on_release(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pin_bounce_on_release(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_release(BUTTON, mock_PUSHBUTTON_STATE);
}

void generate_pin_bounce_on_release(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pushbutton_deb_rep_timer_delay(5, BUTTON);
    check_pushbutton(BUTTON);
    *mock_PUSHBUTTON_STATE = PUSHED;
    check_pushbutton(BUTTON);
    generate_pushbutton_deb_rep_timer_delay(10, BUTTON);
    check_pushbutton(BUTTON);
    *mock_PUSHBUTTON_STATE = RELEASED;
    check_pushbutton(BUTTON);
}

void generete_pin_bouncing_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
    generate_pin_bounce_on_push(BUTTON, mock_PUSHBUTTON_STATE);
}

void generate_pin_bounce_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE)
{
    generate_pushbutton_deb_rep_timer_delay(5, BUTTON);
    check_pushbutton(BUTTON);
    *mock_PUSHBUTTON_STATE = RELEASED;
    check_pushbutton(BUTTON);
    generate_pushbutton_deb_rep_timer_delay(10, BUTTON);
    check_pushbutton(BUTTON);
    *mock_PUSHBUTTON_STATE = PUSHED;
    check_pushbutton(BUTTON);
}

void ckeck_button_state_5_times(PUSHBUTTON_TypDef *BUTTON)
{
    check_pushbutton(BUTTON);
    check_pushbutton(BUTTON);
    check_pushbutton(BUTTON);
    check_pushbutton(BUTTON);
}