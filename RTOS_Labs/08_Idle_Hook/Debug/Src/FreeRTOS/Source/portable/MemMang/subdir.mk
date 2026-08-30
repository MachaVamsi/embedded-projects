################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/FreeRTOS/Source/portable/MemMang/heap_2.c 

OBJS += \
./Src/FreeRTOS/Source/portable/MemMang/heap_2.o 

C_DEPS += \
./Src/FreeRTOS/Source/portable/MemMang/heap_2.d 


# Each subdirectory must supply rules for building sources it contributes
Src/FreeRTOS/Source/portable/MemMang/%.o Src/FreeRTOS/Source/portable/MemMang/%.su Src/FreeRTOS/Source/portable/MemMang/%.cyclo: ../Src/FreeRTOS/Source/portable/MemMang/%.c Src/FreeRTOS/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DNUCLEO_G070RB -DSTM32G070RBTx -DSTM32 -DSTM32G0 -DSTM32G70xx -DSTM32G070xx -c -I../Inc -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/Drivers" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/Drivers/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/Drivers/Device/ST/STM32G0xx/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/FreeRTOS" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/FreeRTOS/Source/include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/FreeRTOS/Source/Config" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/08_Idle_Hook/FreeRTOS/Source/portable/GCC/ARM_CM0" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

clean-Src-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./Src/FreeRTOS/Source/portable/MemMang/heap_2.cyclo ./Src/FreeRTOS/Source/portable/MemMang/heap_2.d ./Src/FreeRTOS/Source/portable/MemMang/heap_2.o ./Src/FreeRTOS/Source/portable/MemMang/heap_2.su

.PHONY: clean-Src-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

