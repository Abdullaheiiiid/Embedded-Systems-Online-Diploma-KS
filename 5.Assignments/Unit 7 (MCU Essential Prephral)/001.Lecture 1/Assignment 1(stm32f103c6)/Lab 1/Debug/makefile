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
lab.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lab.list \

OBJCOPY_HEX += \
lab.hex \

OBJCOPY_BIN += \
lab.bin \


# All Target
all: lab.elf secondary-outputs

# Tool invocations
lab.elf: $(OBJS) $(USER_OBJS) D:\Courses\programming\NOW\EmbeddedSystems\Now\DIPLOMAS\KSESDiploma\5.Assignments\Unit\ 7\ (MCU\ Essential\ Prephral)\Lecture\ 1\Assignment\ 1(stm32f103c6)\Lab\ 1\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "lab.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Courses\programming\NOW\EmbeddedSystems\Now\DIPLOMAS\KSESDiploma\5.Assignments\Unit 7 (MCU Essential Prephral)\Lecture 1\Assignment 1(stm32f103c6)\Lab 1\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lab.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lab.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lab.list"
	@echo 'Finished building: $@'
	@echo ' '

lab.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "lab.hex"
	@echo 'Finished building: $@'
	@echo ' '

lab.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lab.bin"
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
