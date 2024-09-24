################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include LCD/subdir.mk
-include KEYPAD/subdir.mk
-include GPIO/subdir.mk
-include EXTI/subdir.mk
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
EXTI_DRIVER.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
EXTI_DRIVER.list \

OBJCOPY_HEX += \
EXTI_DRIVER.hex \

OBJCOPY_BIN += \
EXTI_DRIVER.bin \


# All Target
all: EXTI_DRIVER.elf secondary-outputs

# Tool invocations
EXTI_DRIVER.elf: $(OBJS) $(USER_OBJS) D:\Courses\programming\NOW\EmbeddedSystems\Now\DIPLOMAS\KSESDiploma\5.Assignments\Unit\ 7\ (MCU\ Essential\ Prephral)\006.Lecture\ 4\DRIVER\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "EXTI_DRIVER.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Courses\programming\NOW\EmbeddedSystems\Now\DIPLOMAS\KSESDiploma\5.Assignments\Unit 7 (MCU Essential Prephral)\006.Lecture 4\DRIVER\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="EXTI_DRIVER.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

EXTI_DRIVER.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "EXTI_DRIVER.list"
	@echo 'Finished building: $@'
	@echo ' '

EXTI_DRIVER.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "EXTI_DRIVER.hex"
	@echo 'Finished building: $@'
	@echo ' '

EXTI_DRIVER.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "EXTI_DRIVER.bin"
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
