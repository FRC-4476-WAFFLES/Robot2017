################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/vision/ntcore/gmock/src/gmock-all.cc \
../src/vision/ntcore/gmock/src/gmock-cardinalities.cc \
../src/vision/ntcore/gmock/src/gmock-internal-utils.cc \
../src/vision/ntcore/gmock/src/gmock-matchers.cc \
../src/vision/ntcore/gmock/src/gmock-spec-builders.cc \
../src/vision/ntcore/gmock/src/gmock.cc \
../src/vision/ntcore/gmock/src/gmock_main.cc 

CC_DEPS += \
./src/vision/ntcore/gmock/src/gmock-all.d \
./src/vision/ntcore/gmock/src/gmock-cardinalities.d \
./src/vision/ntcore/gmock/src/gmock-internal-utils.d \
./src/vision/ntcore/gmock/src/gmock-matchers.d \
./src/vision/ntcore/gmock/src/gmock-spec-builders.d \
./src/vision/ntcore/gmock/src/gmock.d \
./src/vision/ntcore/gmock/src/gmock_main.d 

OBJS += \
./src/vision/ntcore/gmock/src/gmock-all.o \
./src/vision/ntcore/gmock/src/gmock-cardinalities.o \
./src/vision/ntcore/gmock/src/gmock-internal-utils.o \
./src/vision/ntcore/gmock/src/gmock-matchers.o \
./src/vision/ntcore/gmock/src/gmock-spec-builders.o \
./src/vision/ntcore/gmock/src/gmock.o \
./src/vision/ntcore/gmock/src/gmock_main.o 


# Each subdirectory must supply rules for building sources it contributes
src/vision/ntcore/gmock/src/%.o: ../src/vision/ntcore/gmock/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


