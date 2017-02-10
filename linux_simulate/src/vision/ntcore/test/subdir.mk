################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/vision/ntcore/test/client.cpp \
../src/vision/ntcore/test/rpc_local.cpp \
../src/vision/ntcore/test/rpc_speed.cpp \
../src/vision/ntcore/test/server.cpp 

OBJS += \
./src/vision/ntcore/test/client.o \
./src/vision/ntcore/test/rpc_local.o \
./src/vision/ntcore/test/rpc_speed.o \
./src/vision/ntcore/test/server.o 

CPP_DEPS += \
./src/vision/ntcore/test/client.d \
./src/vision/ntcore/test/rpc_local.d \
./src/vision/ntcore/test/rpc_speed.d \
./src/vision/ntcore/test/server.d 


# Each subdirectory must supply rules for building sources it contributes
src/vision/ntcore/test/%.o: ../src/vision/ntcore/test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


