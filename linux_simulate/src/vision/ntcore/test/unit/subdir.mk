################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/vision/ntcore/test/unit/NetworkTableTest.cpp \
../src/vision/ntcore/test/unit/StorageTest.cpp \
../src/vision/ntcore/test/unit/ValueTest.cpp \
../src/vision/ntcore/test/unit/WireDecoderTest.cpp \
../src/vision/ntcore/test/unit/WireEncoderTest.cpp \
../src/vision/ntcore/test/unit/main.cpp 

OBJS += \
./src/vision/ntcore/test/unit/NetworkTableTest.o \
./src/vision/ntcore/test/unit/StorageTest.o \
./src/vision/ntcore/test/unit/ValueTest.o \
./src/vision/ntcore/test/unit/WireDecoderTest.o \
./src/vision/ntcore/test/unit/WireEncoderTest.o \
./src/vision/ntcore/test/unit/main.o 

CPP_DEPS += \
./src/vision/ntcore/test/unit/NetworkTableTest.d \
./src/vision/ntcore/test/unit/StorageTest.d \
./src/vision/ntcore/test/unit/ValueTest.d \
./src/vision/ntcore/test/unit/WireDecoderTest.d \
./src/vision/ntcore/test/unit/WireEncoderTest.d \
./src/vision/ntcore/test/unit/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/vision/ntcore/test/unit/%.o: ../src/vision/ntcore/test/unit/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


