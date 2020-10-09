################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Sources/UTN_Array.c \
../src/Sources/UTN_Employees.c \
../src/Sources/UTN_Inputs.c \
../src/Sources/UTN_Menu.c \
../src/Sources/UTN_Validations.c \
../src/Sources/main.c 

OBJS += \
./src/Sources/UTN_Array.o \
./src/Sources/UTN_Employees.o \
./src/Sources/UTN_Inputs.o \
./src/Sources/UTN_Menu.o \
./src/Sources/UTN_Validations.o \
./src/Sources/main.o 

C_DEPS += \
./src/Sources/UTN_Array.d \
./src/Sources/UTN_Employees.d \
./src/Sources/UTN_Inputs.d \
./src/Sources/UTN_Menu.d \
./src/Sources/UTN_Validations.d \
./src/Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/Sources/%.o: ../src/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


