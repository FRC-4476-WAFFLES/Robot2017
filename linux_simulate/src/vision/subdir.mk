################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/vision/main.cpp \
../src/vision/run_result.cpp \
../src/vision/vision.cpp 

OBJS += \
./src/vision/main.o \
./src/vision/run_result.o \
./src/vision/vision.o 

CPP_DEPS += \
./src/vision/main.d \
./src/vision/run_result.d \
./src/vision/vision.d 


# Each subdirectory must supply rules for building sources it contributes
src/vision/%.o: ../src/vision/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


