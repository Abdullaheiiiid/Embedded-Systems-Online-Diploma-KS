################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
lab2_interrupt_stm32.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lab2_interrupt_stm32.list \

OBJCOPY_HEX += \
lab2_interrupt_stm32.hex \

OBJCOPY_BIN += \
lab2_interrupt_stm32.bin \


# All Target
all: lab2_interrupt_stm32.elf secondary-outputs

# Tool invocations
lab2_interrupt_stm32.elf: $(OBJS) $(USER_OBJS) D:\Courses\programming\NOW\EmbeddedSystems\Now\DIPLOMAS\KSESDiploma\5.Assignments\Unit\ 6\ (Micro-controller\ Architecture)\Lecture\ 4\Lab2\stm\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "lab2_interrupt_stm32.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Courses\programming\NOW\EmbeddedSystems\Now\DIPLOMAS\KSESDiploma\5.Assignments\Unit 6 (Micro-controller Architecture)\Lecture 4\Lab2\stm\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lab2_interrupt_stm32.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lab2_interrupt_stm32.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lab2_interrupt_stm32.list"
	@echo 'Finished building: $@'
	@echo ' '

lab2_interrupt_stm32.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "lab2_interrupt_stm32.hex"
	@echo 'Finished building: $@'
	@echo ' '

lab2_interrupt_stm32.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lab2_interrupt_stm32.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
