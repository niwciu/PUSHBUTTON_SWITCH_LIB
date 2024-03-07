# PUSHBUTTON_SWITCH_LIB - simple cross platform library

The `PUSHBUTTON_SWITCH_LIB` is a simple cross platform library providing interfaces for pushbutton switches and two-state switches (two-state input signals). It includes features such as debouncing, repetition functionality for pushbuttons, and state management for switches.

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
Example of using the library to create a User Interface Keyboard module in the project. The example includes the initialization of one pushbutton keyboard with short-push and long-push with repetition functionality. 
- Short-push triggers the LED ON function, 
- Long-push triggers the LED TOGGLE function.
#### Requirements for compiling and running the example:
1. CMake installed
2. Make or Ninja installed
3. ARM GNU Toolchain (gcc-arm-none-eabi) installed
4. STM32_Programmer_CLI installed
5. ST-link (placed on Nucleo Board) installed
#### Hardware requirements, configuration, and connections:
1. STM32G071 Nucleo-64<br>
  <img src="https://www.st.com/bin/ecommerce/api/image.PF265386.en.feature-description-include-personalized-no-cpn-medium.jpg"   width="400"><br> https://www.st.com/en/evaluation-tools/nucleo-g071rb.html <br> 
#### How to build and run the example:
1. Open the location you want to clone the repository to in your terminal
2. Clone the repository to your preferred localization
    ```bash
    git clone https://github.com/niwciu/PUSHBUTTON_SWITCH_LIB.git
    ```
3. Enter to  PUSHBUTTON_SWITCH_LIB/examples/STM32G071_NUCLEO_LL_1_KEY_UI
    ```bash
    cd ./PUSHBUTTON_SWITCH_LIB/examples/STM32G071_NUCLEO_LL_1_KEY_UI
    ```
4. For Make type:
    ```bash
    cmake -S ./ -B Debug -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
    ```
    ```bash
    cd Debug
    ```
    ```bash 
    make all
    ```
    ```bash 
    make flash
    ```
5. For Ninja type:
    ```bash 
    cmake -S ./ -B Debug -G"Ninja" -DCMAKE_BUILD_TYPE=Debug
    ```
    ```bash
    cd Debug
    ```
    ```bash
    ninja
    ```
    ```bash 
    ninja flash
    ```
6. In some cases Nucleo board requires plugging out and in a USB port to run the program.
### STM32G071_NUCLEO_LL_2_STATE_SWITCH
Example of using the library to create an input signals module in the project. The example includes the initialization of one two-state switch that calls functions when transitioning to ON and OFF states. 
- ON state triggers the LED ON function, 
- OFF state triggers the LED OFF function.
#### Requirements for compiling and running the example:
1. CMake installed
2. Make or Ninja installed
3. ARM GNU Toolchain (gcc-arm-none-eabi) installed
4. STM32_Programmer_CLI installed
5. ST-link (placed on Nucleo Board) installed
#### Hardware requirements, configuration, and connections:
1. STM32G071 Nucleo-64<br>
  <img src="https://www.st.com/bin/ecommerce/api/image.PF265386.en.feature-description-include-personalized-no-cpn-medium.jpg"   width="400"><br> https://www.st.com/en/evaluation-tools/nucleo-g071rb.html <br> 
#### How to build and run the example
1. Open the location you want to clone the repository to in your terminal
2. Clone the repository to your preferred localization
    ```bash
    git clone https://github.com/niwciu/PUSHBUTTON_SWITCH_LIB.git
    ``` 
3. Enter to  PUSHBUTTON_SWITCH_LIB/examples/STM32G071_NUCLEO_LL_2_STATE_SWITCH/
    ```bash
    cd ./PUSHBUTTON_SWITCH_LIB/examples/STM32G071_NUCLEO_LL_2_STATE_SWITCH
    ``` 
4. For Make type:
    ```bash
    cmake -S ./ -B Debug -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
    ```
    ```bash
    cd Debug
    ```
    ```bash 
    make all
    ```
    ```bash 
    make flash
    ``` 
5. For Ninja type:
    ```bash 
    cmake -S ./ -B Debug -G"Ninja" -DCMAKE_BUILD_TYPE=Debug
    ```
    ```bash
    cd Debug
    ```
    ```bash
    ninja
    ```
    ```bash 
    ninja flash
    ```
6. In some cases Nucleo board requires plugging out and in a USB port to run the program.