################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/vision/ntcore/gmock/gtest/src/gtest-all.cc \
../src/vision/ntcore/gmock/gtest/src/gtest-death-test.cc \
../src/vision/ntcore/gmock/gtest/src/gtest-filepath.cc \
../src/vision/ntcore/gmock/gtest/src/gtest-port.cc \
../src/vision/ntcore/gmock/gtest/src/gtest-printers.cc \
../src/vision/ntcore/gmock/gtest/src/gtest-test-part.cc \
../src/vision/ntcore/gmock/gtest/src/gtest-typed-test.cc \
../src/vision/ntcore/gmock/gtest/src/gtest.cc \
../src/vision/ntcore/gmock/gtest/src/gtest_main.cc 

CC_DEPS += \
./src/vision/ntcore/gmock/gtest/src/gtest-all.d \
./src/vision/ntcore/gmock/gtest/src/gtest-death-test.d \
./src/vision/ntcore/gmock/gtest/src/gtest-filepath.d \
./src/vision/ntcore/gmock/gtest/src/gtest-port.d \
./src/vision/ntcore/gmock/gtest/src/gtest-printers.d \
./src/vision/ntcore/gmock/gtest/src/gtest-test-part.d \
./src/vision/ntcore/gmock/gtest/src/gtest-typed-test.d \
./src/vision/ntcore/gmock/gtest/src/gtest.d \
./src/vision/ntcore/gmock/gtest/src/gtest_main.d 

OBJS += \
./src/vision/ntcore/gmock/gtest/src/gtest-all.o \
./src/vision/ntcore/gmock/gtest/src/gtest-death-test.o \
./src/vision/ntcore/gmock/gtest/src/gtest-filepath.o \
./src/vision/ntcore/gmock/gtest/src/gtest-port.o \
./src/vision/ntcore/gmock/gtest/src/gtest-printers.o \
./src/vision/ntcore/gmock/gtest/src/gtest-test-part.o \
./src/vision/ntcore/gmock/gtest/src/gtest-typed-test.o \
./src/vision/ntcore/gmock/gtest/src/gtest.o \
./src/vision/ntcore/gmock/gtest/src/gtest_main.o 


# Each subdirectory must supply rules for building sources it contributes
src/vision/ntcore/gmock/gtest/src/%.o: ../src/vision/ntcore/gmock/gtest/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


