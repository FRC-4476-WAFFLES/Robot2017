################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Auto/AutoDoNothing.cpp \
../src/Commands/Auto/AutoGearDelivery.cpp \
../src/Commands/Auto/AutoRightGearDelivery.cpp 

OBJS += \
./src/Commands/Auto/AutoDoNothing.o \
./src/Commands/Auto/AutoGearDelivery.o \
./src/Commands/Auto/AutoRightGearDelivery.o 

CPP_DEPS += \
./src/Commands/Auto/AutoDoNothing.d \
./src/Commands/Auto/AutoGearDelivery.d \
./src/Commands/Auto/AutoRightGearDelivery.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Auto/%.o: ../src/Commands/Auto/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


