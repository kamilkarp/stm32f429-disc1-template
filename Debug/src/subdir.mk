################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LEDS.c \
../src/delay.c \
../src/main.c \
../src/syscalls.c \
../src/system.c \
../src/system_stm32f4xx.c \
../src/usart.c \
../src/usart1.c 

OBJS += \
./src/LEDS.o \
./src/delay.o \
./src/main.o \
./src/syscalls.o \
./src/system.o \
./src/system_stm32f4xx.o \
./src/usart.o \
./src/usart1.o 

C_DEPS += \
./src/LEDS.d \
./src/delay.d \
./src/main.d \
./src/syscalls.d \
./src/system.d \
./src/system_stm32f4xx.d \
./src/usart.d \
./src/usart1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DDEBUG -DSTM32F429_439xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/Kamil/Documents/SWSTM32 WORKSPACE/stm32f429-disc1-template/StdPeriph_Driver/inc" -I"C:/Users/Kamil/Documents/SWSTM32 WORKSPACE/stm32f429-disc1-template/inc" -I"C:/Users/Kamil/Documents/SWSTM32 WORKSPACE/stm32f429-disc1-template/CMSIS/device" -I"C:/Users/Kamil/Documents/SWSTM32 WORKSPACE/stm32f429-disc1-template/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


