################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c \
../Src/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.c 

OBJS += \
./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/port.o \
./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.o 

C_DEPS += \
./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/port.d \
./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.d 


# Each subdirectory must supply rules for building sources it contributes
Src/FreeRTOS/Source/portable/GCC/ARM_CM0/%.o Src/FreeRTOS/Source/portable/GCC/ARM_CM0/%.su Src/FreeRTOS/Source/portable/GCC/ARM_CM0/%.cyclo: ../Src/FreeRTOS/Source/portable/GCC/ARM_CM0/%.c Src/FreeRTOS/Source/portable/GCC/ARM_CM0/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DNUCLEO_G070RB -DSTM32G070RBTx -DSTM32 -DSTM32G0 -DSTM32G70xx -DSTM32G070xx -c -I../Inc -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/Drivers" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/Drivers/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/Drivers/Device/ST/STM32G0xx/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/FreeRTOS" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/FreeRTOS/Source/include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/FreeRTOS/Source/Config" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/FreeRTOS/Source/portable/GCC/ARM_CM0" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM0

clean-Src-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM0:
	-$(RM) ./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/port.cyclo ./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/port.d ./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/port.o ./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/port.su ./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.cyclo ./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.d ./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.o ./Src/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.su

.PHONY: clean-Src-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM0

