################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/vision/ntcore/wpiutil/src/support/Base64.cpp \
../src/vision/ntcore/wpiutil/src/support/leb128.cpp \
../src/vision/ntcore/wpiutil/src/support/raw_istream.cpp \
../src/vision/ntcore/wpiutil/src/support/raw_socket_istream.cpp \
../src/vision/ntcore/wpiutil/src/support/raw_socket_ostream.cpp \
../src/vision/ntcore/wpiutil/src/support/timestamp.cpp 

OBJS += \
./src/vision/ntcore/wpiutil/src/support/Base64.o \
./src/vision/ntcore/wpiutil/src/support/leb128.o \
./src/vision/ntcore/wpiutil/src/support/raw_istream.o \
./src/vision/ntcore/wpiutil/src/support/raw_socket_istream.o \
./src/vision/ntcore/wpiutil/src/support/raw_socket_ostream.o \
./src/vision/ntcore/wpiutil/src/support/timestamp.o 

CPP_DEPS += \
./src/vision/ntcore/wpiutil/src/support/Base64.d \
./src/vision/ntcore/wpiutil/src/support/leb128.d \
./src/vision/ntcore/wpiutil/src/support/raw_istream.d \
./src/vision/ntcore/wpiutil/src/support/raw_socket_istream.d \
./src/vision/ntcore/wpiutil/src/support/raw_socket_ostream.d \
./src/vision/ntcore/wpiutil/src/support/timestamp.d 


# Each subdirectory must supply rules for building sources it contributes
src/vision/ntcore/wpiutil/src/support/%.o: ../src/vision/ntcore/wpiutil/src/support/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


