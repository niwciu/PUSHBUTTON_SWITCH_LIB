# PUSHBUTTON_SWITCH_LIB

The `PUSHBUTTON_SWITCH_LIB` is a simple library providing interfaces for pushbutton switches and two-state switches. It includes features such as debouncing, repetition functionality for pushbuttons, and state management for switches.

## Usage

### Pushbutton Module

1. Include the necessary files in your project:
   - `pushbutton.h`
   - `pushbutton.c`
   - `pushbutton_GPIO_interface.h`
   - `pushbutton_TIM_interface.h`

2. Initialize the pushbutton(s) using `init_pushbutton` function. Example:

    ```c
    PUSHBUTTON_TypDef myButton;
    init_pushbutton(&myButton, REPETITION_ON, TRIGGER_ON_PUSH, pushButton_GPIO_interface_get);
    ```

3. Register callbacks for push events:

    ```c
    register_button_push_callback(&myButton, myPushCallback);
    ```

4. Periodically check the pushbutton state using `check_pushbutton`:

    ```c
    check_pushbutton(&myButton);
    ```

### Switch Module

1. Include the necessary files in your project:
   - `switch.h`
   - `switch.c`
   - `switch_GPIO_interface.h`

2. Initialize the switch using `init_switch` function. Example:

    ```c
    SWITCH_TypDef mySwitch;
    init_switch(&mySwitch, switch_ON_callback, switch_OFF_callback, switch_GPIO_interface_get);
    ```

3. Periodically check the switch state using `check_switch`:

    ```c
    check_switch(&mySwitch);
    ```

4. Implement your callback functions for switch events.

## Notes

- Make sure to include the necessary dependencies for GPIO and timer interfaces as per your hardware platform.
- Adjust debounce and repetition settings based on your application requirements.