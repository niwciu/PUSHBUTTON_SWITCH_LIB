#############################################################################################################################
# file:  CMakeLists.txt
# brief: Template "CMakeLists.txt" for building of executables and static libraries.
#
# usage: Edit MCPU-Variable to suit STM32 project requirements.
#        For debug build using Unix Makefiles:
#          cmake -S ./ -B Debug -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
#          make -C Debug all (optional with VERBOSE=1  and -jxx ->xx numnber of cores)
#        For debug build using Ninja:
#          cmake -S ./ -B Debug -G"Ninja" -DCMAKE_BUILD_TYPE=Debug
#          ninja -C Debug (optional with -V  and -jxx ->xx numnber of cores)
# 
#        For release build Unix Makefiles:
#          cmake -S ./ -B Release -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
#          make all -C Release VERBOSE=1 -j12 (optional with VERBOSE=1  and -jxx ->xx numnber of cores)
#        For Release build using Ninja:
#          cmake -S ./ -B Release -G"Ninja" -DCMAKE_BUILD_TYPE=Release
#          ninja -C Release (optional -V  and -jxx ->xx numnber of cores)
#############################################################################################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE config/Toolchain-arm-gcc.cmake)

# Allow assembler
enable_language(ASM)

project(STM32G071RB_SWITCH_HW_TEST)

set(INCLUDE_DIRS
../
./Core
./Core/Inc
./Core/Src/LED
./Core/Src/INPUT_SIGNALS
# Core/Src
# Core/Startup

../../src/switch

./Core/Inc 
./Drivers/STM32G0xx_HAL_Driver/Inc 
./Drivers/CMSIS/Device/ST/STM32G0xx/Include 
./Drivers/CMSIS/Include 

.
)

set(C_SRCS
    Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_exti.c
    Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_gpio.c
    Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_pwr.c
    Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_rcc.c
    Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_utils.c
    
    Core/Src/LED/LED_GPIO_driver.c
    Core/Src/INPUT_SIGNALS/input_signals.c
    Core/Src/INPUT_SIGNALS/switch_GPIO_interface.c
    Core/Src/main.c
    Core/Src/stm32g0xx_it.c
    Core/Src/syscalls.c
    Core/Src/sysmem.c
    Core/Src/system_stm32g0xx.c
    

    ../../src/switch/switch.c
    
	
)

set(ASM_SRCS
    Core/Startup/startup_stm32g071rbtx.s
)

set(GLOBAL_DEFINES
-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
-DSTM32G071xx 
-DUSE_FULL_LL_DRIVER 
-DHSE_VALUE=8000000 
-DHSE_STARTUP_TIMEOUT=100 
-DLSE_STARTUP_TIMEOUT=5000 
-DLSE_VALUE=32768 
-DEXTERNAL_CLOCK_VALUE=48000 
-DHSI_VALUE=16000000 
-DLSI_VALUE=32000 
-DVDD_VALUE=3300 
-DPREFETCH_ENABLE=1 
-DINSTRUCTION_CACHE_ENABLE=1 
-DDATA_CACHE_ENABLE=1
)

set(LINKED_LIBS

)

link_directories(

)

include_directories(${INCLUDE_DIRS})
add_definitions(${GLOBAL_DEFINES})

set(MCPU "-mcpu=cortex-m0plus")
include(    config/compiler_flags.cmake)

# generate elf file
add_arm_executable(${CMAKE_PROJECT_NAME} ${C_SRCS} ${ASM_SRCS})

arm_link_libraries(${CMAKE_PROJECT_NAME} ${LINKED_LIBS})

