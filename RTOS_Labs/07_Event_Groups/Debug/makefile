################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Src/FreeRTOS/Source/portable/GCC/ARM_CM0/subdir.mk
-include Src/FreeRTOS/Source/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 07_RTOS_Lab_Event_Groups
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
07_RTOS_Lab_Event_Groups.elf \

MAP_FILES += \
07_RTOS_Lab_Event_Groups.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
07_RTOS_Lab_Event_Groups.list \


# All Target
all: main-build

# Main-build Target
main-build: 07_RTOS_Lab_Event_Groups.elf secondary-outputs

# Tool invocations
07_RTOS_Lab_Event_Groups.elf 07_RTOS_Lab_Event_Groups.map: $(OBJS) $(USER_OBJS) C:\Users\vamsi\Documents\GitHub\embedded-projects\RTOS_Labs\07_Event_Groups\STM32G070RBTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "07_RTOS_Lab_Event_Groups.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"C:\Users\vamsi\Documents\GitHub\embedded-projects\RTOS_Labs\07_Event_Groups\STM32G070RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="07_RTOS_Lab_Event_Groups.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

07_RTOS_Lab_Event_Groups.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "07_RTOS_Lab_Event_Groups.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 07_RTOS_Lab_Event_Groups.elf 07_RTOS_Lab_Event_Groups.list 07_RTOS_Lab_Event_Groups.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
