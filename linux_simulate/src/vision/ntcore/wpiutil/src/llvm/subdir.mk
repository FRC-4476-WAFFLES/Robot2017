################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/vision/ntcore/wpiutil/src/llvm/ConvertUTF.cpp \
../src/vision/ntcore/wpiutil/src/llvm/ConvertUTFWrapper.cpp \
../src/vision/ntcore/wpiutil/src/llvm/ErrorHandling.cpp \
../src/vision/ntcore/wpiutil/src/llvm/Hashing.cpp \
../src/vision/ntcore/wpiutil/src/llvm/SmallPtrSet.cpp \
../src/vision/ntcore/wpiutil/src/llvm/SmallVector.cpp \
../src/vision/ntcore/wpiutil/src/llvm/StringExtras.cpp \
../src/vision/ntcore/wpiutil/src/llvm/StringMap.cpp \
../src/vision/ntcore/wpiutil/src/llvm/StringRef.cpp \
../src/vision/ntcore/wpiutil/src/llvm/raw_os_ostream.cpp \
../src/vision/ntcore/wpiutil/src/llvm/raw_ostream.cpp 

OBJS += \
./src/vision/ntcore/wpiutil/src/llvm/ConvertUTF.o \
./src/vision/ntcore/wpiutil/src/llvm/ConvertUTFWrapper.o \
./src/vision/ntcore/wpiutil/src/llvm/ErrorHandling.o \
./src/vision/ntcore/wpiutil/src/llvm/Hashing.o \
./src/vision/ntcore/wpiutil/src/llvm/SmallPtrSet.o \
./src/vision/ntcore/wpiutil/src/llvm/SmallVector.o \
./src/vision/ntcore/wpiutil/src/llvm/StringExtras.o \
./src/vision/ntcore/wpiutil/src/llvm/StringMap.o \
./src/vision/ntcore/wpiutil/src/llvm/StringRef.o \
./src/vision/ntcore/wpiutil/src/llvm/raw_os_ostream.o \
./src/vision/ntcore/wpiutil/src/llvm/raw_ostream.o 

CPP_DEPS += \
./src/vision/ntcore/wpiutil/src/llvm/ConvertUTF.d \
./src/vision/ntcore/wpiutil/src/llvm/ConvertUTFWrapper.d \
./src/vision/ntcore/wpiutil/src/llvm/ErrorHandling.d \
./src/vision/ntcore/wpiutil/src/llvm/Hashing.d \
./src/vision/ntcore/wpiutil/src/llvm/SmallPtrSet.d \
./src/vision/ntcore/wpiutil/src/llvm/SmallVector.d \
./src/vision/ntcore/wpiutil/src/llvm/StringExtras.d \
./src/vision/ntcore/wpiutil/src/llvm/StringMap.d \
./src/vision/ntcore/wpiutil/src/llvm/StringRef.d \
./src/vision/ntcore/wpiutil/src/llvm/raw_os_ostream.d \
./src/vision/ntcore/wpiutil/src/llvm/raw_ostream.d 


# Each subdirectory must supply rules for building sources it contributes
src/vision/ntcore/wpiutil/src/llvm/%.o: ../src/vision/ntcore/wpiutil/src/llvm/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


