################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Sudoku.cpp \
../src/TADcasilla.cpp \
../src/TADjuego.cpp \
../src/TADtablero.cpp \
../src/entorno.cpp \
../src/utilidades.cpp 

OBJS += \
./src/Sudoku.o \
./src/TADcasilla.o \
./src/TADjuego.o \
./src/TADtablero.o \
./src/entorno.o \
./src/utilidades.o 

CPP_DEPS += \
./src/Sudoku.d \
./src/TADcasilla.d \
./src/TADjuego.d \
./src/TADtablero.d \
./src/entorno.d \
./src/utilidades.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


