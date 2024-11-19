################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/clock72.cpp \
../Core/Src/config.cpp \
../Core/Src/control.cpp \
../Core/Src/font.cpp \
../Core/Src/i2c.cpp \
../Core/Src/ip.cpp \
../Core/Src/main.cpp \
../Core/Src/motor.cpp \
../Core/Src/oled.cpp \
../Core/Src/op.cpp \
../Core/Src/timer3.cpp \
../Core/Src/uart.cpp 

C_SRCS += \
../Core/Src/croutine.c \
../Core/Src/event_groups.c \
../Core/Src/heap_2.c \
../Core/Src/list.c \
../Core/Src/port.c \
../Core/Src/queue.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/tasks.c \
../Core/Src/timers.c 

C_DEPS += \
./Core/Src/croutine.d \
./Core/Src/event_groups.d \
./Core/Src/heap_2.d \
./Core/Src/list.d \
./Core/Src/port.d \
./Core/Src/queue.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/tasks.d \
./Core/Src/timers.d 

OBJS += \
./Core/Src/clock72.o \
./Core/Src/config.o \
./Core/Src/control.o \
./Core/Src/croutine.o \
./Core/Src/event_groups.o \
./Core/Src/font.o \
./Core/Src/heap_2.o \
./Core/Src/i2c.o \
./Core/Src/ip.o \
./Core/Src/list.o \
./Core/Src/main.o \
./Core/Src/motor.o \
./Core/Src/oled.o \
./Core/Src/op.o \
./Core/Src/port.o \
./Core/Src/queue.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/tasks.o \
./Core/Src/timer3.o \
./Core/Src/timers.o \
./Core/Src/uart.o 

CPP_DEPS += \
./Core/Src/clock72.d \
./Core/Src/config.d \
./Core/Src/control.d \
./Core/Src/font.d \
./Core/Src/i2c.d \
./Core/Src/ip.d \
./Core/Src/main.d \
./Core/Src/motor.d \
./Core/Src/oled.d \
./Core/Src/op.d \
./Core/Src/timer3.d \
./Core/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/clock72.cyclo ./Core/Src/clock72.d ./Core/Src/clock72.o ./Core/Src/clock72.su ./Core/Src/config.cyclo ./Core/Src/config.d ./Core/Src/config.o ./Core/Src/config.su ./Core/Src/control.cyclo ./Core/Src/control.d ./Core/Src/control.o ./Core/Src/control.su ./Core/Src/croutine.cyclo ./Core/Src/croutine.d ./Core/Src/croutine.o ./Core/Src/croutine.su ./Core/Src/event_groups.cyclo ./Core/Src/event_groups.d ./Core/Src/event_groups.o ./Core/Src/event_groups.su ./Core/Src/font.cyclo ./Core/Src/font.d ./Core/Src/font.o ./Core/Src/font.su ./Core/Src/heap_2.cyclo ./Core/Src/heap_2.d ./Core/Src/heap_2.o ./Core/Src/heap_2.su ./Core/Src/i2c.cyclo ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/ip.cyclo ./Core/Src/ip.d ./Core/Src/ip.o ./Core/Src/ip.su ./Core/Src/list.cyclo ./Core/Src/list.d ./Core/Src/list.o ./Core/Src/list.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/motor.cyclo ./Core/Src/motor.d ./Core/Src/motor.o ./Core/Src/motor.su ./Core/Src/oled.cyclo ./Core/Src/oled.d ./Core/Src/oled.o ./Core/Src/oled.su ./Core/Src/op.cyclo ./Core/Src/op.d ./Core/Src/op.o ./Core/Src/op.su ./Core/Src/port.cyclo ./Core/Src/port.d ./Core/Src/port.o ./Core/Src/port.su ./Core/Src/queue.cyclo ./Core/Src/queue.d ./Core/Src/queue.o ./Core/Src/queue.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/tasks.cyclo ./Core/Src/tasks.d ./Core/Src/tasks.o ./Core/Src/tasks.su ./Core/Src/timer3.cyclo ./Core/Src/timer3.d ./Core/Src/timer3.o ./Core/Src/timer3.su ./Core/Src/timers.cyclo ./Core/Src/timers.d ./Core/Src/timers.o ./Core/Src/timers.su ./Core/Src/uart.cyclo ./Core/Src/uart.d ./Core/Src/uart.o ./Core/Src/uart.su

.PHONY: clean-Core-2f-Src

