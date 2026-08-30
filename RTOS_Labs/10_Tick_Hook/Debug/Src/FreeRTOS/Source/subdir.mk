################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/FreeRTOS/Source/list.c \
../Src/FreeRTOS/Source/queue.c \
../Src/FreeRTOS/Source/tasks.c 

OBJS += \
./Src/FreeRTOS/Source/list.o \
./Src/FreeRTOS/Source/queue.o \
./Src/FreeRTOS/Source/tasks.o 

C_DEPS += \
./Src/FreeRTOS/Source/list.d \
./Src/FreeRTOS/Source/queue.d \
./Src/FreeRTOS/Source/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
Src/FreeRTOS/Source/%.o Src/FreeRTOS/Source/%.su Src/FreeRTOS/Source/%.cyclo: ../Src/FreeRTOS/Source/%.c Src/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DNUCLEO_G070RB -DSTM32G070RBTx -DSTM32 -DSTM32G0 -DSTM32G70xx -DSTM32G070xx -c -I../Inc -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/10_Tick_Hook/Drivers" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/10_Tick_Hook/Drivers/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/10_Tick_Hook/Drivers/Device/ST/STM32G0xx/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/10_Tick_Hook/FreeRTOS" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/10_Tick_Hook/FreeRTOS/Source/include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/10_Tick_Hook/FreeRTOS/Source/Config" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/10_Tick_Hook/FreeRTOS/Source/portable/GCC/ARM_CM0" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-FreeRTOS-2f-Source

clean-Src-2f-FreeRTOS-2f-Source:
	-$(RM) ./Src/FreeRTOS/Source/list.cyclo ./Src/FreeRTOS/Source/list.d ./Src/FreeRTOS/Source/list.o ./Src/FreeRTOS/Source/list.su ./Src/FreeRTOS/Source/queue.cyclo ./Src/FreeRTOS/Source/queue.d ./Src/FreeRTOS/Source/queue.o ./Src/FreeRTOS/Source/queue.su ./Src/FreeRTOS/Source/tasks.cyclo ./Src/FreeRTOS/Source/tasks.d ./Src/FreeRTOS/Source/tasks.o ./Src/FreeRTOS/Source/tasks.su

.PHONY: clean-Src-2f-FreeRTOS-2f-Source

