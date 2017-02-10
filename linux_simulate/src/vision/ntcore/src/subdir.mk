################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/vision/ntcore/src/Dispatcher.cpp \
../src/vision/ntcore/src/DsClient.cpp \
../src/vision/ntcore/src/Log.cpp \
../src/vision/ntcore/src/Message.cpp \
../src/vision/ntcore/src/NetworkConnection.cpp \
../src/vision/ntcore/src/Notifier.cpp \
../src/vision/ntcore/src/RpcServer.cpp \
../src/vision/ntcore/src/SequenceNumber.cpp \
../src/vision/ntcore/src/Storage.cpp \
../src/vision/ntcore/src/Value.cpp \
../src/vision/ntcore/src/WireDecoder.cpp \
../src/vision/ntcore/src/WireEncoder.cpp \
../src/vision/ntcore/src/ntcore_c.cpp \
../src/vision/ntcore/src/ntcore_cpp.cpp \
../src/vision/ntcore/src/ntcore_test.cpp 

OBJS += \
./src/vision/ntcore/src/Dispatcher.o \
./src/vision/ntcore/src/DsClient.o \
./src/vision/ntcore/src/Log.o \
./src/vision/ntcore/src/Message.o \
./src/vision/ntcore/src/NetworkConnection.o \
./src/vision/ntcore/src/Notifier.o \
./src/vision/ntcore/src/RpcServer.o \
./src/vision/ntcore/src/SequenceNumber.o \
./src/vision/ntcore/src/Storage.o \
./src/vision/ntcore/src/Value.o \
./src/vision/ntcore/src/WireDecoder.o \
./src/vision/ntcore/src/WireEncoder.o \
./src/vision/ntcore/src/ntcore_c.o \
./src/vision/ntcore/src/ntcore_cpp.o \
./src/vision/ntcore/src/ntcore_test.o 

CPP_DEPS += \
./src/vision/ntcore/src/Dispatcher.d \
./src/vision/ntcore/src/DsClient.d \
./src/vision/ntcore/src/Log.d \
./src/vision/ntcore/src/Message.d \
./src/vision/ntcore/src/NetworkConnection.d \
./src/vision/ntcore/src/Notifier.d \
./src/vision/ntcore/src/RpcServer.d \
./src/vision/ntcore/src/SequenceNumber.d \
./src/vision/ntcore/src/Storage.d \
./src/vision/ntcore/src/Value.d \
./src/vision/ntcore/src/WireDecoder.d \
./src/vision/ntcore/src/WireEncoder.d \
./src/vision/ntcore/src/ntcore_c.d \
./src/vision/ntcore/src/ntcore_cpp.d \
./src/vision/ntcore/src/ntcore_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/vision/ntcore/src/%.o: ../src/vision/ntcore/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


