################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Misc/WaitTime.cpp \
../src/Commands/Misc/WaitTrigger.cpp 

OBJS += \
./src/Commands/Misc/WaitTime.o \
./src/Commands/Misc/WaitTrigger.o 

CPP_DEPS += \
./src/Commands/Misc/WaitTime.d \
./src/Commands/Misc/WaitTrigger.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Misc/%.o: ../src/Commands/Misc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


