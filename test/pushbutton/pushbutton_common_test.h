typedef PB_driver_interface_t *(*pushbutton_UP_GPIO_interface_get_ptr)(void);
extern pushbutton_UP_GPIO_interface_get_ptr pb_1_GPIO_interface_get;
extern pushbutton_UP_GPIO_interface_get_ptr pb_2_GPIO_interface_get;

typedef uint16_t debounce_repetition_delay_t;

void generate_pushbutton_deb_rep_timer_delay(debounce_repetition_delay_t delay, PUSHBUTTON_TypDef *BUTTON);
void generete_pin_bouncing_on_release(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE);
void generate_pin_bounce_on_release(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE);
void generete_pin_bouncing_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE);
void generate_pin_bounce_on_push(PUSHBUTTON_TypDef *BUTTON, PB_input_state_t *mock_PUSHBUTTON_STATE);
void ckeck_button_state_5_times(PUSHBUTTON_TypDef *BUTTON);