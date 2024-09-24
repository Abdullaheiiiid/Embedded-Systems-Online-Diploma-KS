################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD/LCD.c 

OBJS += \
./LCD/LCD.o 

C_DEPS += \
./LCD/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
LCD/LCD.o: ../LCD/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/005.Section 3/Code/STM32F103C6" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/005.Section 3/Code/GPIO" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/005.Section 3/Code/Standard Library" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/005.Section 3/Code/LCD" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/005.Section 3/Code/KEYPAD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

