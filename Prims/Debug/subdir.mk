################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PrimMST.cpp \
../edgeNode.cpp \
../graphNode.cpp \
../main.cpp 

OBJS += \
./PrimMST.o \
./edgeNode.o \
./graphNode.o \
./main.o 

CPP_DEPS += \
./PrimMST.d \
./edgeNode.d \
./graphNode.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


