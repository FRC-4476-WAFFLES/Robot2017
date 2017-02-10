################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/vision/ntcore/native/ntcore/build/libs/ntcore/static/x64/test.cpp 

OBJS += \
./src/vision/ntcore/native/ntcore/build/libs/ntcore/static/x64/test.o 

CPP_DEPS += \
./src/vision/ntcore/native/ntcore/build/libs/ntcore/static/x64/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/vision/ntcore/native/ntcore/build/libs/ntcore/static/x64/%.o: ../src/vision/ntcore/native/ntcore/build/libs/ntcore/static/x64/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


