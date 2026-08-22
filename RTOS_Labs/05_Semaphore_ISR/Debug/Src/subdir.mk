################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/05_Semaphore_ISR.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart.c 

OBJS += \
./Src/05_Semaphore_ISR.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart.o 

C_DEPS += \
./Src/05_Semaphore_ISR.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DNUCLEO_G070RB -DSTM32G070RBTx -DSTM32 -DSTM32G0 -DSTM32G70xx -DSTM32G070xx -c -I../Inc -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/Drivers" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/Drivers/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/Drivers/Device/ST/STM32G0xx/Include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/FreeRTOS" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/FreeRTOS/Source/include" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/FreeRTOS/Source/Config" -I"C:/Users/vamsi/Documents/GitHub/embedded-projects/RTOS_Labs/05_Semaphore_ISR/FreeRTOS/Source/portable/GCC/ARM_CM0" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/05_Semaphore_ISR.cyclo ./Src/05_Semaphore_ISR.d ./Src/05_Semaphore_ISR.o ./Src/05_Semaphore_ISR.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

