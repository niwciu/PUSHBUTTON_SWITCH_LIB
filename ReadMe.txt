# PUSHBUTTON_SWITCH_LIB - simple cross platform library

The `PUSHBUTTON_SWITCH_LIB` is a simple cross platform library providing interfaces for pushbutton switches and two-state switches. It includes features such as debouncing, repetition functionality for pushbuttons, and state management for switches.

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

## Examples
### STM32G071_NUCLEO_LL_1_KEY_UI 
Example of usage the library to create Use Interface Keyboard module in the procject. 
Example contain initialization of one pushbutton keybard with short-push and long-push with repetition functinality.
Short-push trigger/call LED ON function.
Long-push trigger/call LED TOOGLE function.
#### Requirements for compiling and running the example:
#### Hardware requirements, configuration, and connections:
#### PUSBUTTON_SWITCH library configuration - pushbutton.h
#### How to build and run the example:

### STM32G071_NUCLEO_LL_2_STATE_SWITCH
Example of usage the library to create input signals module in the procject. 
Example contain initialization of one two state switch that call functions once when goint to ON and OFF state.
ON state trigger/call LED ON function.
OFF state trigger/call LED OFF function.
#### Requirements for compiling and running the example:
#### Hardware requirements, configuration, and connections:
#### PUSBUTTON_SWITCH library configuration - pushbutton.h
#### How to build and run the example: