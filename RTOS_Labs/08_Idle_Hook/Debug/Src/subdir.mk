################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/08_Idle_Hook.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart.c 

OBJS += \
./Src/08_Idle_Hook.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart.o 

C_DEPS += \
./Src/08_Idle_Hook.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DNUCLEO_G070RB -DSTM32G070RBTx -DSTM32 -DSTM32G0 -DSTM32G70xx -DSTM32G070xx -c -I../Inc -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/Drivers" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/Drivers/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/Drivers/Device/ST/STM32G0xx/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/FreeRTOS" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/FreeRTOS/Source/include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/FreeRTOS/Source/Config" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/FreeRTOS/Source/portable/GCC/ARM_CM0" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/08_Idle_Hook.cyclo ./Src/08_Idle_Hook.d ./Src/08_Idle_Hook.o ./Src/08_Idle_Hook.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

