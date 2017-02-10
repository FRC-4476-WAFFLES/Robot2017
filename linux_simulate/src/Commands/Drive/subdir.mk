################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Drive/DriveAuto.cpp \
../src/Commands/Drive/DriveAutoRelative.cpp \
../src/Commands/Drive/DriveHalf.cpp \
../src/Commands/Drive/DriveHalfRelative.cpp \
../src/Commands/Drive/DriveOperator.cpp 

OBJS += \
./src/Commands/Drive/DriveAuto.o \
./src/Commands/Drive/DriveAutoRelative.o \
./src/Commands/Drive/DriveHalf.o \
./src/Commands/Drive/DriveHalfRelative.o \
./src/Commands/Drive/DriveOperator.o 

CPP_DEPS += \
./src/Commands/Drive/DriveAuto.d \
./src/Commands/Drive/DriveAutoRelative.d \
./src/Commands/Drive/DriveHalf.d \
./src/Commands/Drive/DriveHalfRelative.d \
./src/Commands/Drive/DriveOperator.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Drive/%.o: ../src/Commands/Drive/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


