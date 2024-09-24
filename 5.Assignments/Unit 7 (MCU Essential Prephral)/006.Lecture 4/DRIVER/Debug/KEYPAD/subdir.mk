################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KEYPAD/KEYPAD.c 

OBJS += \
./KEYPAD/KEYPAD.o 

C_DEPS += \
./KEYPAD/KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
KEYPAD/KEYPAD.o: ../KEYPAD/KEYPAD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/006.Lecture 4/DRIVER/Standard Library" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/006.Lecture 4/DRIVER/STM32F103C6" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/006.Lecture 4/DRIVER/LCD" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/006.Lecture 4/DRIVER/KEYPAD" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/006.Lecture 4/DRIVER/GPIO" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/006.Lecture 4/DRIVER/EXTI" -I"D:/Courses/programming/NOW/EmbeddedSystems/Now/DIPLOMAS/KSESDiploma/5.Assignments/Unit 7 (MCU Essential Prephral)/006.Lecture 4/DRIVER/EXTI" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"KEYPAD/KEYPAD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

